#include "console/m_consolevaradmin.h"
#include "console/ColShape/ColShape.h"
#include "console/DynEntity/DynEntity.h"
#include "console/Tools/Tools.h"
#include "console/VarOperation/VarOperation.h"
#include "console/World/World.h"
#include "console/Session/Session.h"
#include "info/OnTradeInfo_CreateTradeItems.h"
#include "info/OnTradeInfo_RemoveTradeItems.h"
#include "info/OnTradeInfo_ClearTradeInventory.h"

namespace
{
    gSScriptInit s_ScriptInit;
}

extern "C" __declspec( dllexport ) gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    if( !s_ScriptInit.m_arrScripts.IsEmpty() )
        return &s_ScriptInit;

    s_ScriptInit.m_arrScriptAIStates.Clear();
    s_ScriptInit.m_arrScriptAIFunctions.Clear();
    s_ScriptInit.m_arrScriptAICallbacks.Clear();
    s_ScriptInit.m_arrScripts.Clear();

    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_ColShape", __FILE__, CON_ColShape ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_DynEntity", __FILE__, CON_DynEntity ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_Tools", __FILE__, CON_Tools ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_#", __FILE__, CON_VarOperation ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_World", __FILE__, CON_World ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_Session", __FILE__, CON_Session ) );

    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "OnTradeInfo_CreateTradeItems", __FILE__, OnTradeInfo_CreateTradeItems ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "OnTradeInfo_RemoveTradeItems", __FILE__, OnTradeInfo_RemoveTradeItems ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "OnTradeInfo_ClearTradeInventory", __FILE__, OnTradeInfo_ClearTradeInventory ) );

    return &s_ScriptInit;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        mCConsoleVarAdmin::GetInstance().Save();
        break;
    }
    return TRUE;
}