#include "m_utils.h"
#include "m_hacks.h"
#include <stdio.h>

#pragma comment ( lib, "user32.lib" )

void DbgOut( GELPCChar a_strFormat, ... )
{
    va_list argp;
    va_start( argp, a_strFormat );
    GEChar Buffer[ 255 ];
    vsprintf_s( Buffer, 255, a_strFormat, argp );
    OutputDebugString( Buffer );
    va_end( argp );
}

void DestroyEntity( eCEntity * a_pEntity )
{
    if ( !a_pEntity )
        return;
    a_pEntity->Kill();
    eCSceneAdmin * pSceneAdmin = dynamic_cast< eCSceneAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCSceneAdmin" ) );
    if ( pSceneAdmin )
        pSceneAdmin->GetAccessToEntityAdmin().KillEntities();
}

GEBool FromFile( bCMemoryStream & a_streamDest, GELPCChar a_strFileName )
{
    FILE * pFile;
    if ( fopen_s( &pFile, a_strFileName, "rb" ) )
        return GEFalse;
    fseek( pFile, 0, SEEK_END );
    GEUInt uSize = static_cast< GEUInt >( ftell( pFile ) );
    GEByte * pBuffer = new GEByte [ uSize ];
    fseek( pFile, 0, SEEK_SET );
    fread( pBuffer, sizeof( GEByte ), uSize, pFile );
    fclose( pFile );
    a_streamDest.Clear();
    a_streamDest.Write( pBuffer, uSize );
    a_streamDest.Seek( 0, bEStreamSeekMode_Begin );
    delete [] pBuffer;
    return GETrue;
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
        return CloseClipboard(), Result;
    LPTSTR lptstr = reinterpret_cast< LPTSTR >( GlobalLock( hglb ) ); 
    if ( lptstr != NULL )
        Result = lptstr;
    GlobalUnlock( hglb ); 
    return CloseClipboard(), Result;
}

eCDynamicEntity * GetDynamicEntity( bCUnicodeString a_strGuid, bCUnicodeString & a_strResult )
{
    bCGuid guidTarget( a_strGuid.GetAnsiText() );
    if ( !guidTarget.IsValid() )
        return a_strResult = L"Invalid GUID specified.", 0;
    bCPropertyID TargetPropertyId( guidTarget );
    if ( !TargetPropertyId.IsValid() )
        return a_strResult = L"Retrieved invalid PropertyID from GUID.", 0;
    eCEntityProxy TargetEntityProxy;
    TargetEntityProxy.SetEntity( TargetPropertyId );
    if ( !TargetEntityProxy.IsEntityIDValid() )
        return a_strResult = L"Retrieved invalid entity proxy from GUID.", 0;
    eCDynamicEntity * pTargetEntity = TargetEntityProxy.GetDynamicEntity();
    if ( !pTargetEntity || !pTargetEntity->IsValid() )
        return a_strResult = L"Retrieved invalid dynamic entity from GUID.", 0;
    return pTargetEntity;
}

gCDynamicLayer * GetLayer( bCString a_strName )
{
    gCWorld const * pWorld = gCWorld::GetCurrentWorld();
    for ( GEInt i = 0, ie = pWorld->GetSectorCount(); i != ie; ++i )
    {
        gCSector const * pSector = pWorld->GetSectorAt( i );
        bTPtrArray< gCDynamicLayer * > const & arrPossibleLayers = pSector->GetEntityLayers();
        for ( GEInt i = 0, ie = arrPossibleLayers.GetCount(); i != ie; ++i )
            if ( a_strName.Compare( arrPossibleLayers[ i ]->GetFileBaseName() ) == 0 )
                return arrPossibleLayers[ i ];
    }
    return 0;
}

gCDynamicLayer * GetLayer( eCDynamicEntity * a_pEntity )
{
    if ( !a_pEntity )
        return 0;
    gCSector const * pSector = gCWorld::GetSectorForEntity( a_pEntity );
    if ( !pSector )
        return 0;
    bTPtrArray< gCDynamicLayer * > const & arrPossibleLayers = pSector->GetEntityLayers();
    if ( arrPossibleLayers.GetCount() == 1 )
        return arrPossibleLayers[ 0 ];
    for ( GEInt i = 0, ie = arrPossibleLayers.GetCount(); i != ie; ++i )
        if ( arrPossibleLayers[ i ]->GetContext().GetGraph() == a_pEntity->GetRoot() )
            return arrPossibleLayers[ i ]; 
    return 0;
}

bCString GetPhysicalFilePath( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    if ( !File.Exists() )
        return "";
    return File.GetPhysicalFilePath();
}

bCString GetRisenAppdataPath( void )
{
    GEChar arrBuffer[ 255 ];
    if ( !g_FFGetSpecialDirectory( EFFSpecialFolder_LocalAppData, arrBuffer, sizeof( arrBuffer ) ) )
        return "";
    return bCString( arrBuffer ) + "\\Risen";
}

bCString GetRisenPath( void )
{
    eCVirtualFileSystem & VirtualFileSystem = eCVirtualFileSystem::GetInstance();
    return VirtualFileSystem.GetPhysicalRootPath();
}

GEBool GetVectorFromText( bCVector & a_vecTarget, bCString const & a_strText )
{
    return ( sscanf_s( a_strText.GetText(), "[%f,%f,%f]", &a_vecTarget.AccessX(), &a_vecTarget.AccessY(), &a_vecTarget.AccessZ() ) == 3 );
}

GEBool IsEntityEnabled( const eCEntity * a_pEntity )
{
    return a_pEntity->GetEntityFlags().m_Enabled != 0;
}

GEBool IsPhysical( bCString const & a_strFilePath )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_strFilePath );
    if ( !File.Exists() )
        return GEFalse;
    return File.IsPhysical();
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

GEBool SetEntityLayer( eCDynamicEntity * a_pEntity, gCDynamicLayer * a_pLayer )
{
    if ( !a_pEntity || !a_pLayer )
        return GEFalse;
    eCDynamicEntity * pParent = dynamic_cast< eCDynamicEntity * >( a_pLayer->GetContext().GetGraph() );
    if ( !pParent )
        return GEFalse;
    a_pEntity->AddReference();
    a_pEntity->RemoveFromParent();
    GEBool bResult = pParent->AttachChild( a_pEntity );
    a_pEntity->ReleaseReference();
    a_pEntity->UpdateAll( GETrue );
    return bResult;
}

GEBool ToFile( bCMemoryStream & a_streamSource, GELPCChar a_strFileName )
{
    FILE * pFile;
    if ( fopen_s( &pFile, a_strFileName, "wb" ) )
        return GEFalse;
    GEI64 i64Offset = a_streamSource.GetPosition();
    a_streamSource.Seek( 0, bEStreamSeekMode_Begin );
    fwrite( a_streamSource.GetBuffer( 0 ), sizeof( GEU8 ), static_cast< GEU32 >( a_streamSource.GetSize() ), pFile );
    fclose( pFile );
    a_streamSource.Seek( i64Offset, bEStreamSeekMode_Begin );
    return GETrue;
}