#include "World_RemoveLayer.h"

bCUnicodeString CON_World_Sub::RemoveLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString strLayerName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCDynamicLayer * pLayer = GetLayer( strLayerName );
    if ( !pLayer )
        return L"$Unknown layer.";

    gCSector * pSector = gCWorld::GetSectorForEntity( dynamic_cast< eCEntity * >( pLayer->GetContext().GetGraph() ) );
    if ( !pSector )
        return L"$Could not find the layer's sector.";
    if ( pSector->RemoveDynamicLayer( pLayer ) != 1 )
        return L"$Failed to remove the layer.";
    if ( !pSector->Save() )
        return ( "$The sector " + pSector->GetFileBaseName() + " could not be saved." ).GetUnicodeText();

    return ( strLayerName + " has been removed from the sector " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
}