#include "World_SaveLayer.h"

bCUnicodeString CON_World_Sub::SaveLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    gCDynamicLayer * pLayer = GetLayer( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !pLayer )
        return L"$Dynamic layer not found.";

    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( pLayer->GetFilePath() );
    if ( !File.IsPhysical() )
        return ( "$" + File.GetFileName() + " is not physical." ).GetUnicodeText();

    if ( !pLayer->Save() )
        return ( "$Could not write to " + File.GetPhysicalFilePath() + "." ).GetUnicodeText();

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return ( File.GetPhysicalFilePath() + " has been saved." ).GetUnicodeText();
}