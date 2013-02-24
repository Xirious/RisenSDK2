#include "World_ListSectors.h"

bCUnicodeString CON_World_Sub::ListSectors( bTObjArray< bCUnicodeString >, gCScriptProcessingUnit * )
{
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    GEInt const iSectorCount = pWorld->GetSectorCount();

    bCUnicodeString strResult = bCUnicodeString::GetFormattedString( L"Sectors in the current world (%i):", iSectorCount );
    for ( GEInt i = 0; i != iSectorCount; ++i )
        strResult += ( "\n  " + pWorld->GetSectorAt( i )->GetFileBaseName() ).GetUnicodeText();
    return strResult;
}