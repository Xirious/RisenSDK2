#include "DynEntity_Edit.h"

bCUnicodeString CON_DynEntity::Edit( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gui2.ShowPropertyEditor( Entity( pEntity ), true );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return L"";
}