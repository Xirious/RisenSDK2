#ifndef TOOLS_GETPHYSICALFILEPATH_H_INCLUDED
#define TOOLS_GETPHYSICALFILEPATH_H_INCLUDED

#include "../m_commandhandler.h"

namespace CON_Tools_Sub
{
    bCUnicodeString GetPhysicalFilePath( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * );
}

#endif