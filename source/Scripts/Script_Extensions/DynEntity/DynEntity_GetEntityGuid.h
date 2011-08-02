#ifndef DYNENTITY_GETENTITYGUID_H_INCLUDED
#define DYNENTITY_GETENTITYGUID_H_INCLUDED

#include "..\CmdManagement.h"

namespace CON_DynEntity
{
    bCUnicodeString GetEntityGuid( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
    bCUnicodeString GetEntityGuidAC( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif  // DYNENTITY_GETENTITYGUID_H_INCLUDED