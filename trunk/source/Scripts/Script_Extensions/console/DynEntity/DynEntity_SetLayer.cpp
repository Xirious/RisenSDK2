#include "DynEntity_SetLayer.h"

bCUnicodeString CON_DynEntity_Sub::SetLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gCDynamicLayer * pLayer = GetLayer( a_arrParams.GetAt( 2 ).GetAnsiText() );
    if ( !pLayer )
        return L"$Dynamic layer not found.";
    if ( !SetEntityLayer( pEntity, pLayer ) )
        return L"$Internal error.";

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 2 ) );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return L"'" + pEntity->GetName().GetUnicodeText() + L"' has been attached to the target layer.";
}