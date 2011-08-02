#include "Tools_SetClipboardText.h"

bCUnicodeString CON_Tools::SetClipboardText( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );
    
    ::SetClipboardText( a_arrParams.AccessAt( 1 ) );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return L"Copied to clipboard.";
}