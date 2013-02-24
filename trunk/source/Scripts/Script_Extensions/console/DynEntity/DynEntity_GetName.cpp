#include "DynEntity_GetName.h"

bCUnicodeString CON_DynEntity_Sub::GetName( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    strResult = pEntity->GetName().GetUnicodeText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &strResult );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return mCCommandHandler::PushResult( strResult );
}