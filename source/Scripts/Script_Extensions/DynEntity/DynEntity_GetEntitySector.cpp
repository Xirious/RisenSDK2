#include "DynEntity_GetEntitySector.h"

bCUnicodeString CON_DynEntity::GetEntitySector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gCSector * pSector = gCWorld::GetSectorForEntity( pEntity );
    if ( !pSector )
        return L"$The entity isn't part of any sector.";

    strResult = pSector->GetFileBaseName().GetUnicodeText();
    ParamAutoCompletion( &strResult );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}