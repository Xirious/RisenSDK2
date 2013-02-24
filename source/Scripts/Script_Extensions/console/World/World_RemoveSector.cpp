#include "World_RemoveSector.h"

bCUnicodeString CON_World_Sub::RemoveSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();

    gCSector * pSector = pWorld->GetSector( strSectorName );
    if ( !pSector )
        return L"$Unknown sector.";
    if ( pWorld->RemoveSector( pSector ) != 1 )
        return L"$Failed to remove the sector.";
    if ( !pWorld->Save() )
        return L"$" + pWorld->GetFileName().GetUnicodeText() + L" could not be saved.";
    return ( strSectorName + " has been removed from the current world." ).GetUnicodeText();
}