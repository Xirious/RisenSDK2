#include "Script_Mod_Fixes.h"

void AddScriptPatch( gSScriptInit & a_ScriptInit, GELPCChar a_pcOriginalFileName, GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript )
{
    eCScriptFunctionMap & ScriptFunctionMap = eCScriptFunctionMap::GetInstance();
    eSScriptBase * pScript = const_cast< eSScriptBase * >( ScriptFunctionMap.GetScript( a_pcName ) );
    if( pScript && pScript->m_funcFunction )
    {
        gSScriptDLL * pScriptDLL = static_cast< gSScriptDLL * >( pScript->m_pScriptDLL );
        if( !pScriptDLL ||
            !pScriptDLL->m_strFileName.CompareNoCase( a_pcOriginalFileName ) ||
            g_MessageBox( 0, bCString::GetFormattedString(
              "The script \"%s\" is already overridden by the \"%s\"!\n"
              "Do you want to apply the patch anyway?",
              a_pcName, pScriptDLL->m_strFileName ),
              "Script Modification - Fixes", MB_ICONEXCLAMATION | MB_YESNO ) == IDYES )
        {
            pScript->m_funcFunction = 0;
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

    AddScriptPatch( s_ScriptInit, "Script_Game.dll",
        "GiveXP", "Script/Ai/AI_Commands/GiveXP.cpp", GiveXP );
    AddScriptPatch( s_ScriptInit, "Script_Game.dll",
        "OnQuestChange", "Script/Story/Quest/OnQuestChange.cpp", OnQuestChange );
    AddScriptPatch( s_ScriptInit, "Script_Game.dll",
        "OnQuestSuccess_CloseQuestWine", "Script/Story/Quest/Chapter1.cpp", OnQuestSuccess_CloseQuestWine );

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
