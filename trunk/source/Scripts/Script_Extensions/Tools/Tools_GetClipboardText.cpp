#include "Tools_GetClipboardText.h"

bCUnicodeString CON_Tools::GetClipboardText( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );
    UNREFERENCED_PARAMETER( a_arrParams );

    bCUnicodeString strResult = ::GetClipboardText();
    ParamAutoCompletion( &strResult );
    return strResult;
}