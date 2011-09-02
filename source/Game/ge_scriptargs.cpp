#include "../Game.h"

//
// gSArgsForScriptBase
//

gSArgsForScriptBase::~gSArgsForScriptBase( void )
{
}

//
// gSAIScriptArgs
//

gSAIScriptArgs::gSAIScriptArgs( eCEntity * a_pSelf, eCEntity * a_pOther ) :
    m_Other( a_pOther ), m_iParameter( 0 ), m_Self( a_pSelf )
{
}

gSAIScriptArgs::gSAIScriptArgs( eCEntity * a_pSelf, eCEntity * a_pOther, GEInt a_iParameter ) :
    m_Other( a_pOther ), m_iParameter( a_iParameter ), m_Self( a_pSelf )
{
}

