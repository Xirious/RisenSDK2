#include "Utils.h"

void DbgOut( GELPCChar a_strFormat, ... )
{
    va_list argp;
    va_start( argp, a_strFormat );

    GEChar Buffer[ 255 ];
    vsprintf_s( Buffer, 255, a_strFormat, argp );
    OutputDebugString( Buffer );

    va_end( argp );
}

bCString GetRisenPath( void )
{
    eCVirtualFileSystem & VirtualFileSystem = eCVirtualFileSystem::GetInstance();
    return VirtualFileSystem.GetPhysicalRootPath();
}

GEBool ToFile( bCMemoryStream & a_MemStream, GELPCChar a_strFileName )
{
    FILE * pFile;
    if ( fopen_s( &pFile, a_strFileName, "wb" ) )
    {
        return false;
    }

    GEI64 Offset = a_MemStream.GetPosition();
    a_MemStream.Seek( 0, bEStreamSeekMode_Begin );

    fwrite( a_MemStream.GetBuffer( 0 ), sizeof( GEU8 ), static_cast< GEU32 >( a_MemStream.GetSize() ), pFile );
    fclose( pFile );

    a_MemStream.Seek( Offset, bEStreamSeekMode_Begin );
    return true;
}

bCUnicodeString GetClipboardText( void )
{
    bCUnicodeString Result;
    if ( !IsClipboardFormatAvailable( CF_TEXT ) )
        return Result;
    if ( !OpenClipboard( 0 ) ) 
        return Result;
    HGLOBAL hglb = GetClipboardData( CF_TEXT );
    if ( hglb == NULL ) 
        return Result;
    LPTSTR lptstr = reinterpret_cast< LPTSTR >( GlobalLock( hglb ) ); 
    if ( lptstr != NULL )
        Result = lptstr;
    GlobalUnlock( hglb ); 
    CloseClipboard();
    return Result;
}

void SetClipboardText( bCUnicodeString a_strText )
{
    if ( !OpenClipboard( 0 ) ) 
        return;
    EmptyClipboard();
    GEInt iSize = ( a_strText.GetLength() + 1 );
    HGLOBAL hglb = GlobalAlloc( GMEM_MOVEABLE, iSize * sizeof( TCHAR ) );
    LPTSTR lptstr = reinterpret_cast< LPTSTR >( GlobalLock( hglb ) );
    memcpy( lptstr, a_strText.GetAnsiText().GetText(), ( iSize * sizeof( TCHAR ) ) );
    GlobalUnlock( hglb ); 
    SetClipboardData( CF_TEXT, hglb ); 
    CloseClipboard();
    return;
}

eCDynamicEntity * GetDynamicEntity( bCUnicodeString a_strGuid, bCUnicodeString & Result )
{
    bCString GuidString = a_strGuid.GetAnsiText();

    bCGuid TargetGuid( GuidString );
    if ( !TargetGuid.IsValid() )
    {
        Result = L"Invalid GUID specified.";
        return 0;
    }

    bCPropertyID TargetPropId( TargetGuid );
    if ( !TargetPropId.IsValid() )
    {
        Result = L"Retrieved invalid PropertyID from GUID.";
        return 0;
    }

    eCEntityProxy pTargetEntityProxy;
    pTargetEntityProxy.SetEntity( TargetPropId );
    if ( !pTargetEntityProxy.IsEntityIDValid() )
    {
        Result = L"Retrieved invalid entity proxy from GUID.";
        return 0;
    }

    eCDynamicEntity * pTargetEntity = pTargetEntityProxy.GetDynamicEntity();
    if ( !pTargetEntity )
    {
        Result = L"Retrieved invalid dynamic entity from GUID.";
        return 0;
    }
    if ( !pTargetEntity->IsValid() )
    {
        Result = L"Retrieved invalid dynamic entity from GUID.";
        return 0;
    }

    return pTargetEntity;
}

GEBool IsEntityEnabled( const eCEntity * a_pEntity )
{
    const eSEntityFlags & EntityFlags = a_pEntity->GetEntityFlags();
    return ( EntityFlags.m_Enabled != 0 );
}

gCDynamicLayer * GetLayer( bCString a_strName )
{
    const gCWorld * pWorld = gCWorld::GetCurrentWorld();
    for ( GEInt i = 0, ie = pWorld->GetSectorCount(); i != ie; ++i )
    {
        const gCSector * pSector = pWorld->GetSectorAt( i );
        const bTPtrArray< gCDynamicLayer * > & arrPossibleLayers = pSector->GetEntityLayers();
        for ( GEInt i = 0, ie = arrPossibleLayers.GetCount(); i != ie; ++i )
        {
            if ( a_strName.Compare( arrPossibleLayers.GetAt( i )->GetFileBaseName() ) == 0 )
                return arrPossibleLayers.GetAt( i );
        }
    }
    return 0;
}

gCDynamicLayer * GetLayer( eCDynamicEntity * a_pEntity )
{
    gCSector * pSector = gCWorld::GetSectorForEntity( a_pEntity );
    if ( !pSector )
        return 0;

    const bTPtrArray< gCDynamicLayer * > & arrPossibleLayers = pSector->GetEntityLayers();
    for ( GEInt i = 0, ie = arrPossibleLayers.GetCount(); i != ie; ++i )
    {
        arrPossibleLayers[i]->Enable( false );
        if ( !IsEntityEnabled( a_pEntity ) )
        {
            arrPossibleLayers[i]->Enable( true );
            return arrPossibleLayers[i];
        }
        arrPossibleLayers[i]->Enable( true );
    }

    return 0;
}

GEBool GetVectorFromText( bCVector & a_vecTarget, bCString a_strText )
{
    return ( sscanf_s( a_strText.GetText(), "[%f,%f,%f]", &a_vecTarget.AccessX(), &a_vecTarget.AccessY(), &a_vecTarget.AccessZ() ) == 3 );
}

bCUnicodeString ParamAutoCompletion( const bCUnicodeString * a_strResultToRegister )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< bCUnicodeString > arrResults;
    static GEU32 i;

#pragma warning( pop )

    if ( a_strResultToRegister )
    {
        i = 10;
        if ( *a_strResultToRegister == L"" )
            return L"";
        arrResults.Remove( *a_strResultToRegister );
        arrResults.InsertAt( 0, *a_strResultToRegister );
        if ( arrResults.GetCount() == 11 )
            arrResults.RemoveAt( 10 );
        return L"";
    }

    if ( i >= static_cast< GEU32 >( arrResults.GetCount() ) )
    {
        i = 0;
        return GetClipboardText();
    }
    if ( GetClipboardText() == arrResults[ static_cast< GEInt >( i ) ] )
    {
        ++i;
        if ( i >= static_cast< GEU32 >( arrResults.GetCount() ) )
            i = 0;
    }
    return arrResults[ static_cast< GEInt >( i++ ) ];
}

GEBool IsPhysical( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    if ( !File.Exists() )
        return false;
    return File.IsPhysical();
}

bCString GetPhysicalFilePath( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    if ( !File.Exists() )
        return "";
    return File.GetPhysicalFilePath();
}

bCString GetAddrString( const void * a_pAddr )
{
    GEChar Buffer[20];
    sprintf_s( Buffer, 20, "%#.8x", reinterpret_cast< GEU32 >( a_pAddr ) );
    return bCString( Buffer );
}