#include "World_RemoveSector.h"

bCUnicodeString CON_World::RemoveSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCString strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();

    gCSector * pSector = pWorld->GetSector( strSectorName );
    if ( !pSector )
        return L"$Unknown sector.";

    if ( pWorld->RemoveSector( pSector ) != 1 )
        return L"$Failed to remove the sector.";

    if ( !pWorld->Save() )
        return L"$The current world's data file could not be saved";

    return ( strSectorName + " has been removed from the current world." ).GetUnicodeText();
}