#include "World_ListLayers.h"

bCUnicodeString CON_World_Sub::ListLayers( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    gCSector * pSector = gCWorld::GetCurrentWorld()->GetSector( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !pSector )
        return L"$Unknown sector.";

    bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
    bCUnicodeString strResult = bCString::GetFormattedString( "Layers in %s (%i):", pSector->GetFileBaseName().GetText(), arrLayers.GetCount() ).GetUnicodeText();
    for ( GEInt i = 0, ie = arrLayers.GetCount(); i != ie; ++i )
        strResult += ( "\n  " + arrLayers.GetAt( i )->GetFileBaseName() ).GetUnicodeText();

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return strResult;
}