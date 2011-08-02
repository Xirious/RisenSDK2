#ifndef DYNENTITY_GETENTITYNAME_H_INCLUDED
#define DYNENTITY_GETENTITYNAME_H_INCLUDED

#include "..\Utils.h"

namespace CON_DynEntity
{
    bCUnicodeString GetEntityName( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU );
}

#endif  // DYNENTITY_GETENTITYNAME_H_INCLUDED