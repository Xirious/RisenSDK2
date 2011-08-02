#ifndef TOOLS_GETPHYSICALFILEPATH_H_INCLUDED
#define TOOLS_GETPHYSICALFILEPATH_H_INCLUDED

#include "..\Utils.h"

namespace CON_Tools
{
    bCUnicodeString GetPhysicalFilePath( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif  // TOOLS_GETPHYSICALFILEPATH_H_INCLUDED