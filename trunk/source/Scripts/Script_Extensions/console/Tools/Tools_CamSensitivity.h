#ifndef TOOLS_CAMSENSITIVITY_H_INCLUDED
#define TOOLS_CAMSENSITIVITY_H_INCLUDED

#include "../m_commandhandler.h"

namespace CON_Tools_Sub
{
    bCUnicodeString FreeCamSensitivity( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
    bCUnicodeString PlayerCamSensitivity( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif