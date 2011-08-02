#include "World_Save.h"

bCUnicodeString CON_World::Save( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    if ( !pWorld->Save() )
        return ( "$Failed to save " + GetPhysicalFilePath( pWorld->GetFilePath() ) + "." ).GetUnicodeText();

    GEInt iSectorCount = pWorld->GetSectorCount();
    GEInt iLayerCount = 0;
    GEI32 iSkippedFileCount = 0;

    for ( GEInt i = 0; i != iSectorCount; ++i )
    {
        gCSector * pSector = const_cast< gCSector * >( pWorld->GetSectorAt( i ) );
        if ( IsPhysical( pSector->GetFilePath() ) )
        {
            if ( !pSector->Save() )
                return ( "$Failed to save " + GetPhysicalFilePath( pSector->GetFilePath() ) + "." ).GetUnicodeText();
        }
        else
        {
            ++iSkippedFileCount;
        }

        bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
        iLayerCount += arrLayers.GetCount();
        for ( GEInt j = 0, je = arrLayers.GetCount(); j != je; ++j )
        {
            gCDynamicLayer * pLayer = arrLayers.GetAt( j );
            if ( IsPhysical( pLayer->GetFilePath() ) )
            {
                if ( !pLayer->Save() )
                    return ( "$Failed to save " + GetPhysicalFilePath( pLayer->GetFilePath() ) + "." ).GetUnicodeText();
            }
            else
            {
                ++iSkippedFileCount;
            }
        }
    }

    GEChar Buffer1[20];
    GEChar Buffer2[20];
    GEChar Buffer3[20];
    _itoa_s( iSectorCount, Buffer1, 20, 10 );
    _itoa_s( iLayerCount, Buffer2, 20, 10 );
    _itoa_s( iSkippedFileCount, Buffer3, 20, 10 );

    return ( bCString( "The current world, " ) + Buffer1 + " sector(s) and " + Buffer2 + " dynamic layer(s) have been successfully saved. Skipped " + Buffer3 + " non-physical file(s)." ).GetUnicodeText();
}