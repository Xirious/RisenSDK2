#include "DynEntity_Remove.h"

bCUnicodeString CON_DynEntity::Remove( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    strResult = pEntity->GetName();
    if ( !gCWorld::GetCurrentWorld()->DestroyDynamicEntity( pEntity ) )
        return ( L"$Failed to destroy " + strResult );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( L"Removed " + strResult + L"." );
}