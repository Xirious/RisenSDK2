#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "..\CmdManagement.h"
#include "World_AddLayer.h"
#include "World_AddSector.h"
#include "World_ListLayers.h"
#include "World_ListSectors.h"
#include "World_RemoveLayer.h"
#include "World_RemoveSector.h"
#include "World_Save.h"
#include "World_SaveLayer.h"
#include "World_SaveSector.h"

GEInt GE_STDCALL World( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs );

#endif  // WORLD_H_INCLUDED