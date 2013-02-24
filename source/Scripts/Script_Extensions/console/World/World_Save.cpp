#include "World_Save.h"

bCUnicodeString CON_World_Sub::Save( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    if ( !pWorld->Save() )
        return ( "$Failed to save " + GetPhysicalFilePath( pWorld->GetFilePath() ) + "." ).GetUnicodeText();

    GEInt iSectorCount = pWorld->GetSectorCount();
    GEInt iLayerCount = 0;
    GEInt iSkippedSectorCount = 0;
    GEInt iSkippedLayerCount = 0;

    for ( GEInt i = 0; i != iSectorCount; ++i )
    {
        gCSector * pSector = pWorld->GetSectorAt( i );
        if ( IsPhysical( pSector->GetFilePath() ) )
            if ( !pSector->Save() )
                return ( "$Failed to save " + GetPhysicalFilePath( pSector->GetFilePath() ) + "." ).GetUnicodeText();
        else
            ++iSkippedSectorCount;

        bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
        iLayerCount += arrLayers.GetCount();
        for ( GEInt j = 0, je = arrLayers.GetCount(); j != je; ++j )
        {
            gCDynamicLayer * pLayer = arrLayers.GetAt( j );
            if ( IsPhysical( pLayer->GetFilePath() ) )
                if ( !pLayer->Save() )
                    return ( "$Failed to save " + GetPhysicalFilePath( pLayer->GetFilePath() ) + "." ).GetUnicodeText();
            else
                ++iSkippedLayerCount;
        }
    }

    return bCString::GetFormattedString( "%s, %i sector(s) and %i dynamic layer(s) have been successfully saved. Skipped %i non-physical layer(s) and %i non-physical sector(s).",
                                         pWorld->GetFileName(),
                                         ( iSectorCount - iSkippedSectorCount ),
                                         ( iLayerCount - iSkippedLayerCount ),
                                         iSkippedLayerCount,
                                         iSkippedSectorCount ).GetUnicodeText();
}