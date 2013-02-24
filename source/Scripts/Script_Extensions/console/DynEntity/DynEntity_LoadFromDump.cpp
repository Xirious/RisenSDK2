#include "DynEntity_LoadFromDump.h"

bCUnicodeString CON_DynEntity_Sub::LoadFromDump( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    bCString strInFilePath = GetRisenAppdataPath() + "\\Dumps\\" + a_arrParams.GetAt( 2 ).GetAnsiText() + ".bin";
    bCMemoryStream InStream;
    if ( !FromFile( InStream, strInFilePath.GetText() ) )
        return ( L"$Could not open the file " + strInFilePath.GetUnicodeText() + L"." );
    InStream.Seek( 0, bEStreamSeekMode_Begin );

    if ( !pEntity->OnRead( InStream ) )
        return ( L"$Failed to load " + pEntity->GetName().GetUnicodeText() + L" from dump." );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 2 ) );
    return L"Ok.";
}