#ifndef TOOLS_GETCLIPBOARDTEXT_H_INCLUDED
#define TOOLS_GETCLIPBOARDTEXT_H_INCLUDED

#include "..\Utils.h"

namespace CON_Tools
{
    bCUnicodeString GetClipboardText( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif  // TOOLS_GETCLIPBOARDTEXT_H_INCLUDED