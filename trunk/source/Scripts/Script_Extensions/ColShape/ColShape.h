#ifndef COLSHAPE_H_INCLUDED
#define COLSHAPE_H_INCLUDED

#include "..\CmdManagement.h"
#include "ColShape_AddBox.h"
#include "ColShape_AddMesh.h"
#include "ColShape_RemoveShapeAt.h"

GEInt GE_STDCALL ColShape( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs );

#endif  // COLSHAPE_H_INCLUDED