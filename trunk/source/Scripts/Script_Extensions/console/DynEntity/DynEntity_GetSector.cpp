#include "DynEntity_GetSector.h"

bCUnicodeString CON_DynEntity_Sub::GetSector( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gCSector * pSector = gCWorld::GetSectorForEntity( pEntity );
    if ( !pSector )
        return L"$The entity is not part of any sector.";

    strResult = pSector->GetFileBaseName().GetUnicodeText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &strResult );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return mCCommandHandler::PushResult( strResult );
}