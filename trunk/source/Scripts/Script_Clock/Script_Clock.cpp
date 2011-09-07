#include "Script.h"

GEInt GE_STDCALL CON_clock( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iIntParameter )
{
    gSConScriptArgs & ConArgs = *reinterpret_cast< gSConScriptArgs * >( a_iIntParameter );
    switch( ConArgs.m_enumEvent )
    {
    case gEConScriptEvent_Help:
        ConArgs.m_strResult = L"Displays the system and game time.";
        return GETrue;
    case gEConScriptEvent_Execute:
        {
            bCDateTime SystemTime;
            SystemTime.Update();
            bCString strSystemTime;
            SystemTime.GetTimeString( strSystemTime );
            bCString strGameTime;
            Entity WorldEntity = Entity::GetWorldEntity();
            if( WorldEntity != None )
            {
                PSClock const & Clock = WorldEntity.GetPropertySet< PSClock >();
                if( Clock.IsValid() )
                    strGameTime.Format( "%02d:%02d", Clock.GetHour(), Clock.GetMinute() );
            }
            ConArgs.m_strResult.Format( L"System: %s, Game: %s", strSystemTime.GetUnicodeText(), strGameTime.GetUnicodeText() );
            return GETrue;
        }
        break;
    default:
    case gEConScriptEvent_Complete:
        return GEFalse;
    }
}
GEInt GE_STDCALL OnDebugClock( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt )
{
    if( gSDebugAction::gEKeyAction_Down == input.GetCurrentDebugEvent().m_enumKeyAction )
    {
        gSConScriptArgs ConArgs;
        ConArgs.m_enumEvent = gEConScriptEvent_Execute;
        if( CON_clock( 0, 0, 0, reinterpret_cast< GEInt >( &ConArgs ) ) )
        {
            if( world.IsGameRunning() && !world.IsPaused() && !gui2.IsLoading() )
                gui2.PrintGameLog( ConArgs.m_strResult, gELogMessageType_Grey, GETrue, 0 );
            else
                g_MessageBox( eCApplication::GetInstance().GetHandle(), ConArgs.m_strResult.GetAnsiText(), "clock", MB_ICONINFORMATION );
        }
        return GETrue;
    }
    return GEFalse;
}

extern "C" __declspec( dllexport )  // "_ScriptInit@0"
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )  // construction of local static object is not thread-safe

    static gSScriptInit s_ScriptInit;

#pragma warning( pop )

    s_ScriptInit.m_arrScriptAIStates.Clear();
    s_ScriptInit.m_arrScriptAIFunctions.Clear();
    s_ScriptInit.m_arrScriptAICallbacks.Clear();
    s_ScriptInit.m_arrScripts.Clear();
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "CON_clock", __FILE__, CON_clock ) );
    s_ScriptInit.m_arrScripts.Add( gSScriptInitScript( "OnDebugClock", __FILE__, OnDebugClock ) );

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
        break;
    }
    return TRUE;
}

