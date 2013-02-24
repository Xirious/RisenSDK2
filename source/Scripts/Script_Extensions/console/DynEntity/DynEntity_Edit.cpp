#include "DynEntity_Edit.h"

bCUnicodeString CON_DynEntity_Sub::Edit( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    gui2.ShowPropertyEditor( Entity( pEntity ), GETrue );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return L"";
}