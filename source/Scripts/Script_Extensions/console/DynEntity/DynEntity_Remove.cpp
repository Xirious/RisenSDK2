#include "DynEntity_Remove.h"

bCUnicodeString CON_DynEntity_Sub::Remove( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    strResult = pEntity->GetName();
    DestroyEntity( pEntity );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return ( L"Removed " + strResult + L"." );
}