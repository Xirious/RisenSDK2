gSScriptInitScriptBase::gSScriptInitScriptBase( GELPCChar a_pcName, GELPCChar a_pcSource ) :
    m_strName( a_pcName ), m_strSource( a_pcSource )
{
}

gSScriptInitScriptBase::gSScriptInitScriptBase( void )
{
}

gSScriptInitScriptAIState::gSScriptInitScriptAIState( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState ) :
    gSScriptInitScriptBase( a_pcName, a_pcSource ), m_funcScriptAIState( a_funcScriptAIState )
{
}

gSScriptInitScriptAIState::gSScriptInitScriptAIState( void )
{
}

gSScriptInitScriptAIFunction::gSScriptInitScriptAIFunction( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIFunction a_funcScriptAIFunction ) :
    gSScriptInitScriptBase( a_pcName, a_pcSource ), m_funcScriptAIFunction( a_funcScriptAIFunction )
{
}

gSScriptInitScriptAIFunction::gSScriptInitScriptAIFunction( void )
{
}

gSScriptInitScriptAICallback::gSScriptInitScriptAICallback( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAICallback a_funcScriptAICallback ) :
    gSScriptInitScriptBase( a_pcName, a_pcSource ), m_funcScriptAICallback( a_funcScriptAICallback )
{
}

gSScriptInitScriptAICallback::gSScriptInitScriptAICallback( void )
{
}

gSScriptInitScript::gSScriptInitScript( GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript ) :
    gSScriptInitScriptBase( a_pcName, a_pcSource ), m_funcScript( a_funcScript )
{
}

gSScriptInitScript::gSScriptInitScript( void )
{
}
