#include "World_ListSectors.h"

bCUnicodeString CON_World::ListSectors( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );
    UNREFERENCED_PARAMETER( a_arrParams );

    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    GEInt iSectorCount = pWorld->GetSectorCount();

    GEChar Buffer[20];
    _itoa_s( iSectorCount, Buffer, 20, 10 );
    bCUnicodeString strResult = ( bCString( "Sectors in the current world (" ) + Buffer + "):" ).GetUnicodeText();
    for ( GEInt i = 0; i != iSectorCount; ++i )
        strResult += ( "\n  " + pWorld->GetSectorAt( i )->GetFileBaseName() ).GetUnicodeText();

    return strResult;
}