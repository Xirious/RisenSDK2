#include "Script/Story/Quest/Chapter1.h"

void AddScript( gSScriptInit & a_ScriptInit, GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript )
{
    eCScriptFunctionMap & ScriptFunctionMap = eCScriptFunctionMap::GetInstance();
    eSScriptBase * pScript = const_cast< eSScriptBase * >( ScriptFunctionMap.GetScript( a_pcName ) );
    if( pScript && pScript->m_funcFunction )
    {
        pScript->m_funcFunction = 0;
        {
            gSScriptDLL * pScriptDLL = static_cast< gSScriptDLL * >( pScript->m_pScriptDLL );
            if( pScriptDLL && pScriptDLL->m_arrScripts.RemoveAt( pScriptDLL->m_arrScripts.IndexOf( pScript ) ) )
                ScriptFunctionMap.UnRegisterScript( pScript );
        }
    }
    a_ScriptInit.m_arrScripts.Add( gSScriptInitScript( a_pcName, a_pcSource, a_funcScript ) );
}

extern "C" __declspec( dllexport ) gSScriptInit const * GE_STDCALL ScriptInit( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static gSScriptInit s_ScriptInit;

#pragma warning( pop )

    s_ScriptInit.m_arrScriptAIStates.Clear();
    s_ScriptInit.m_arrScriptAIFunctions.Clear();
    s_ScriptInit.m_arrScriptAICallbacks.Clear();
    s_ScriptInit.m_arrScripts.Clear();

    AddScript( s_ScriptInit, "OnQuestSuccess_CloseQuestWine", "Script/Story/Quest/Chapter1.cpp", OnQuestSuccess_CloseQuestWine );
    
    return &s_ScriptInit;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER( lpReserved );
    switch( dwReason )
	{
	case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
