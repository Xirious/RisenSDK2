#include "DynEntity_GetEntityName.h"

bCUnicodeString CON_DynEntity::GetEntityName( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    strResult = pEntity->GetName().GetUnicodeText();
    ParamAutoCompletion( &strResult );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}