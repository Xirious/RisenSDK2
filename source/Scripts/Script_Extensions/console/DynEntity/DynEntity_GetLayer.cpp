#include "DynEntity_GetLayer.h"

bCUnicodeString CON_DynEntity_Sub::GetLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gCDynamicLayer * pLayer = GetLayer( pEntity );
    if ( !pLayer )
        return L"$The entity is not part of any dynamic layer.";

    strResult = pLayer->GetFileBaseName().GetUnicodeText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &strResult );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return mCCommandHandler::PushResult( strResult );
}