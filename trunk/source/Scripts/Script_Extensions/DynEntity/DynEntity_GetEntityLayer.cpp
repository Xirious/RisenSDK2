#include "DynEntity_GetEntityLayer.h"

bCUnicodeString CON_DynEntity::GetEntityLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gCDynamicLayer * pLayer = GetLayer( pEntity );
    if ( !pLayer )
        return L"$The entity isn't part of any dynamic layer.";

    strResult = pLayer->GetFileBaseName().GetUnicodeText();
    ParamAutoCompletion( &strResult );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}