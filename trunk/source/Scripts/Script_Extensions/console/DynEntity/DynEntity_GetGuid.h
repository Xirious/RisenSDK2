#ifndef DYNENTITY_GETGUID_H_INCLUDED
#define DYNENTITY_GETGUID_H_INCLUDED

#include "../m_commandhandler.h"

namespace CON_DynEntity_Sub
{
    bCUnicodeString GetGuid( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * );
    bCUnicodeString GetGuidAC( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif