#include "World_AddSector.h"

bCUnicodeString CON_World_Sub::AddSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString const strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    if ( pWorld->GetSector( strSectorName ) )
        return L"$The sector already exists.";

    eCArchiveFile WorldFile = eCArchiveManager::GetInstance().GetFile( pWorld->GetDataFilePath() );
    if ( !WorldFile.IsPhysical() )
        return L"$The world file ist not physical.";

    gCSector * pSector = pWorld->InsertNewSector( strSectorName, WorldFile.GetPhysicalRootPath() );
    if ( !pSector->Save() )
        return ( "$" + GetPhysicalFilePath( pSector->GetFilePath() ) + " could not be saved." ).GetUnicodeText();
    if ( !pWorld->Save() )
        return L"$" + pWorld->GetFileName().GetUnicodeText() + L" could not be saved.";

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return ( GetPhysicalFilePath( pSector->GetFilePath() ) + " has been added to the current world." ).GetUnicodeText();
}