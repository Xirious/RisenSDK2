#include "World_AddLayer.h"

bCUnicodeString CON_World_Sub::AddLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString const strSectorName = a_arrParams.GetAt( 1 ).GetAnsiText();
    bCString const strLayerName = a_arrParams.GetAt( 2 ).GetAnsiText();
    gCWorld * pWorld = gCWorld::GetCurrentWorld();

    gCSector * pSector = pWorld->GetSector( strSectorName );
    if ( !pSector )
        return L"$Unknown sector.";
    if ( GetLayer( strLayerName ) )
        return L"$The layer already exists.";
    if ( !IsPhysical( pSector->GetFilePath() ) )
        return ( "$" + pSector->GetFileBaseName() + " is not physical." ).GetUnicodeText();

    gCDynamicLayer * pLayer = pSector->InsertNewDynamicLayer( strLayerName, gEEntityType_Game );
    if ( !pLayer )
        return ( "$Failed to insert a new dynamic layer in " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
    bCString strLayerFilePath = GetPhysicalFilePath( pLayer->GetFilePath() );
    if ( !pLayer->Save() )
        return ( "$" + strLayerFilePath + " could not be saved." ).GetUnicodeText();
    if ( !pSector->Save() )
        return ( "$" + pSector->GetFileBaseName() + " could not be saved." ).GetUnicodeText();

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 2 ) );
    return ( GetPhysicalFilePath( pLayer->GetFilePath() ) + " has been added to " + pSector->GetFileBaseName() + "." ).GetUnicodeText();
}