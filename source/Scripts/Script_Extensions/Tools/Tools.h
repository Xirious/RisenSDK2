#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "..\CmdManagement.h"
#include "Tools_GetClipboardText.h"
#include "Tools_GetPhysicalFilePath.h"
#include "Tools_SetClipboardText.h"

GEInt GE_STDCALL Tools( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs );

#endif  // TOOLS_H_INCLUDED