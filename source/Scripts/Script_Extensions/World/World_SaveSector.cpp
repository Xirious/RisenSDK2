#include "World_SaveSector.h"

bCUnicodeString CON_World::SaveSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    gCSector * pSector = pWorld->GetSector( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !pSector )
        return L"$Unknown sector";

    GEI32 iSkippedFileCount = 0;
    if ( IsPhysical( pSector->GetFilePath() ) )
    {
        if ( !pSector->Save() )
            return ( "$Failed to save " + GetPhysicalFilePath( pSector->GetFilePath() ) + "." ).GetUnicodeText();
    }
    else
    {
        return ( "$" + pSector->GetFilePath() + " is not physical." ).GetUnicodeText();
    }

    bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
    for ( GEInt i = 0, ie = arrLayers.GetCount(); i != ie; ++i )
    {
        gCDynamicLayer * pLayer = arrLayers.GetAt( i );
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

    GEChar Buffer1[20];
    GEChar Buffer2[20];
    _itoa_s( arrLayers.GetCount(), Buffer1, 20, 10 );
    _itoa_s( iSkippedFileCount, Buffer2, 20, 10 );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( pSector->GetFileBaseName() + " and " + Buffer1 + " dynamic layer(s) have been successfully saved. Skipped " + Buffer2 + " non-physical file(s)." ).GetUnicodeText();
}