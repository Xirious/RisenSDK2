#include "World_AddSector.h"

bCUnicodeString CON_World::AddSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCString strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    if ( pWorld->GetSector( strSectorName ) )
        return L"$Sector already existent.";

    eCArchiveFile WorldDataFile = eCArchiveManager::GetInstance().GetFile( pWorld->GetDataFilePath() );
    if ( !WorldDataFile.IsPhysical() )
        return L"$World data file ist not physical";

    gCSector * pSector = pWorld->InsertNewSector( strSectorName, WorldDataFile.GetPhysicalRootPath() );
    if ( !pSector->Save() )
        return ( "$" + GetPhysicalFilePath( pSector->GetFilePath() ) + " could not be saved." ).GetUnicodeText();
    if ( !pWorld->Save() )
        return L"$The current world's data file could not be saved";

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( GetPhysicalFilePath( pSector->GetFilePath() ) + " has been added to the current world." ).GetUnicodeText();
}