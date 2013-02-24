#include "DynEntity_Dump.h"

bCUnicodeString CON_DynEntity_Sub::Dump( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    bCMemoryStream streamOut;
    if ( !pEntity->OnWrite( streamOut ) )
        return ( L"$Failed to dump " + pEntity->GetName().GetUnicodeText() + L"." );

    bCString strOutFilePath = GetRisenAppdataPath() + "\\Dumps";
    CreateDirectoryA( strOutFilePath.GetText(), 0 );
    strOutFilePath += "\\" + pEntity->GetName() + ".bin";

    if ( !ToFile( streamOut, strOutFilePath.GetText() ) )
        return ( L"$Could not write to " + strOutFilePath.GetUnicodeText() + L"." );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return ( "Saved " + pEntity->GetName() + " as " + strOutFilePath + "." ).GetUnicodeText();
}