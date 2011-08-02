#include "World_ListLayers.h"

bCUnicodeString CON_World::ListLayers( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    gCSector * pSector = gCWorld::GetCurrentWorld()->GetSector( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !pSector )
        return L"$Unknown sector.";

    bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
    GEChar Buffer[20];
    _itoa_s( arrLayers.GetCount(), Buffer, 20, 10 );
    bCUnicodeString strResult = ( "Layers in " + pSector->GetFileBaseName() + " (" + Buffer + "):" ).GetUnicodeText();

    for ( GEInt i = 0, ie = arrLayers.GetCount(); i != ie; ++i )
        strResult += ( "\n  " + arrLayers.GetAt( i )->GetFileBaseName() ).GetUnicodeText();

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}