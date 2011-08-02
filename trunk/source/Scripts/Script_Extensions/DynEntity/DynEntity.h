#ifndef DYNENTITY_H_INCLUDED
#define DYNENTITY_H_INCLUDED

#include "..\CmdManagement.h"
#include "DynEntity_Clone.h"
#include "DynEntity_DocumentPS.h"
#include "DynEntity_Dump.h"
#include "DynEntity_Edit.h"
#include "DynEntity_GetEntityGuid.h"
#include "DynEntity_GetEntityLayer.h"
#include "DynEntity_GetEntityName.h"
#include "DynEntity_GetEntitySector.h"
#include "DynEntity_RecalcExtents.h"
#include "DynEntity_Remove.h"
#include "DynEntity_SetLayer.h"
#include "DynEntity_Show.h"

GEInt GE_STDCALL DynEntity( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs );

#endif  // DYNENTITY_H_INCLUDED