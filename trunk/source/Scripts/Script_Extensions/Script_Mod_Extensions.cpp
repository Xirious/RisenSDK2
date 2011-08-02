#include "ColShape/ColShape.h"
#include "DynEntity/DynEntity.h"
#include "Tools/Tools.h"
#include "World/World.h"

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

    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_ColShape", __FILE__, ColShape ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_DynEntity", __FILE__, DynEntity ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_Tools", __FILE__, Tools ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_World", __FILE__, World ) );
    
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