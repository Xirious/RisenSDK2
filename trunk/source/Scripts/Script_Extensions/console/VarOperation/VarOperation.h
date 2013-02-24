#ifndef VAROPERATION_H_INCLUDED
#define VAROPERATION_H_INCLUDED

#include "Script.h"

void HookConsoleEditInputParser( void );

GEInt GE_STDCALL CON_VarOperation( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iArgs );

#endif