#include "World_RemoveLayer.h"

bCUnicodeString CON_World::RemoveLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCString strLayerName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCDynamicLayer * pLayer = GetLayer( strLayerName );
    if ( !pLayer )
        return L"$Unknown layer.";

    eCDynamicEntity * pTempEntity = pLayer->CreateDynamicEntity();
    if ( !pTempEntity )
        return L"$Failed to create a new entity in the specified layer.";
    gCSector * pSector = gCWorld::GetSectorForEntity( pTempEntity );
    gCWorld::GetCurrentWorld()->DestroyDynamicEntity( pTempEntity );
    if ( !pSector )
        return L"$Could not find the layer's sector.";
    
    if ( pSector->RemoveDynamicLayer( pLayer ) != 1 )
        return L"$Failed to remove the layer.";
    if ( !pSector->Save() )
        return ( "$The sector " + pSector->GetFileBaseName() + " could not be saved." ).GetUnicodeText();

    return ( strLayerName + " has been removed from the sector " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
}