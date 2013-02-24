#include "World_SaveSector.h"

bCUnicodeString CON_World_Sub::SaveSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    gCWorld * pWorld = gCWorld::GetCurrentWorld();
    gCSector * pSector = pWorld->GetSector( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !pSector )
        return L"$Unknown sector";

    if ( IsPhysical( pSector->GetFilePath() ) )
        if ( !pSector->Save() )
            return ( "$Failed to save " + GetPhysicalFilePath( pSector->GetFilePath() ) + "." ).GetUnicodeText();
    else
        return ( "$" + pSector->GetFilePath() + " is not physical." ).GetUnicodeText();

    GEInt iSkippedFileCount = 0;
    bTPtrArray< gCDynamicLayer * > const & arrLayers = pSector->GetEntityLayers();
    for ( GEInt i = 0, ie = arrLayers.GetCount(); i != ie; ++i )
    {
        gCDynamicLayer * pLayer = arrLayers.GetAt( i );
        if ( IsPhysical( pLayer->GetFilePath() ) )
            if ( !pLayer->Save() )
                return ( "$Failed to save " + GetPhysicalFilePath( pLayer->GetFilePath() ) + "." ).GetUnicodeText();
        else
            ++iSkippedFileCount;
    }

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return bCUnicodeString::GetFormattedString( L"%s and %i dynamic layer(s) have been successfully saved. Skipped %i non-physical file(s).", pSector->GetFileBaseName().GetUnicodeText().GetText(), ( arrLayers.GetCount() - iSkippedFileCount ), iSkippedFileCount );
}