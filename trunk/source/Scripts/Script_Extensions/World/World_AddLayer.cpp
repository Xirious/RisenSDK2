#include "World_AddLayer.h"

bCUnicodeString CON_World::AddLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCString strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    bCString strLayerName = a_arrParams.GetAt( 2 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();

    gCSector * pSector = pWorld->GetSector( strSectorName );
    if ( !pSector )
        return L"$Unknown sector.";
    if ( GetLayer( strLayerName ) )
        return L"$Layer already existent";
    if ( !IsPhysical( pSector->GetFilePath() ) )
        return ( "$" + pSector->GetFileBaseName() + " is not physical." ).GetUnicodeText();

    gCDynamicLayer * pLayer = pSector->InsertNewDynamicLayer( strLayerName, gEEntityType_Game );
    if ( !pLayer )
        return ( "$Failed to insert a new dynamic layer in " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
    bCString strLayerFilePath = GetPhysicalFilePath( pLayer->GetFilePath() );
    if ( !pLayer->Save() )
        return ( "$" + strLayerFilePath + " could not be saved." ).GetUnicodeText();
    if ( !pSector->Save() )
        return ( "$" + pSector->GetFileBaseName() + " could not be saved." ).GetUnicodeText();

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    ParamAutoCompletion( &a_arrParams.GetAt( 2 ) );
    return ( GetPhysicalFilePath( pLayer->GetFilePath() ) + " has been added to " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
}