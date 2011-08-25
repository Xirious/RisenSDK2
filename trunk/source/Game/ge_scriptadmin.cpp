#include "../Game.h"

GEInt gSScript::operator () ( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iIntParameter )
{
    if( !this->m_funcFunction )
        return 0;
    return static_cast< gFScript >( this->m_funcFunction )( a_pSPU, a_pSelfEntity, a_pOtherEntity, a_iIntParameter );
}

GEBool gSScriptAICallback::operator () ( gCScriptProcessingUnit * a_pSPU )
{
    if( !this->m_funcFunction )
        return GEFalse;
    return static_cast< gFScriptAICallback >( this->m_funcFunction )( a_pSPU );
}

GEBool gSScriptAIFunction::operator () ( bTObjStack< gScriptRunTimeSingleState > & a_Stack, gCScriptProcessingUnit * a_pSPU )
{
    if( !this->m_funcFunction )
        return GEFalse;
    return static_cast< gFScriptAIFunction >( this->m_funcFunction )( a_Stack, a_pSPU );
}

GEBool gSScriptAIState::operator () ( bTObjStack< gScriptRunTimeSingleState > & a_Stack, gCScriptProcessingUnit * a_pSPU )
{
    if( !this->m_funcFunction )
        return GEFalse;
    return static_cast< gFScriptAIState >( this->m_funcFunction )( a_Stack, a_pSPU );
}

