#include "Script_Clock.h"
#include "Script_Clock.rh"
#pragma warning( push, 0 )
#include <commctrl.h>
#pragma warning( pop )
#pragma comment( lib, "comctl32" )
#pragma comment( lib, "user32" )

HMODULE g_hModule = 0;

bCUnicodeString GetFormattedResourceString( GEUInt a_uID, ... )
{
    bCUnicodeString strResult;
    GELPCUnicodeChar pwFormat = 0;
    GEInt iFormatLength = ::LoadStringW( g_hModule, a_uID, reinterpret_cast< LPWSTR >( &pwFormat ), 0 );
    if( (iFormatLength > 0) && pwFormat )
    {
        bCUnicodeString strFormat( pwFormat, iFormatLength );
        GELPUnicodeChar pwResult = 0;
        va_list Arguments;
        va_start( Arguments, a_uID );
        if( ::FormatMessageW( FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            strFormat.GetText(), 0, 0, reinterpret_cast< LPWSTR >( &pwResult ), 0, &Arguments ) )
        {
            strResult = pwResult;
            if( pwResult )
                ::LocalFree( reinterpret_cast< HLOCAL >( pwResult ) );
        }
    }
    return strResult;
}

GEInt ApplicationMessageBox( bCUnicodeString const & a_strMessage, bCUnicodeString const & a_strCaption, GEU32 a_u32Type )
{
    HWND hParent = eCApplication::IsInitialised() ? eCApplication::GetInstance().GetHandle() : 0;
    return ::MessageBoxExW( hParent, a_strMessage, a_strCaption, a_u32Type, 0 );
}

GEInt GE_STDCALL CON_clock( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iIntParameter )
{
    gSConScriptArgs & ConArgs = *reinterpret_cast< gSConScriptArgs * >( a_iIntParameter );
    switch( ConArgs.m_enumEvent )
    {
    case gEConScriptEvent_Help:
        ConArgs.m_strResult = GetFormattedResourceString( IDS_SCRIPT_CLOCK_CONHELP );
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
            ConArgs.m_strResult = GetFormattedResourceString( IDS_SCRIPT_CLOCK_MESSAGE, strSystemTime.GetUnicodeText(), strGameTime.GetUnicodeText() );
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
                ApplicationMessageBox( ConArgs.m_strResult,
                    GetFormattedResourceString( IDS_SCRIPT_CLOCK_CAPTION ),
                    MB_ICONINFORMATION );
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

BOOL APIENTRY DllMain( HMODULE a_hModule, DWORD a_dwReason, LPVOID )
{
    switch( a_dwReason )
    {
    case DLL_PROCESS_ATTACH:
        g_hModule = a_hModule;
        ::DisableThreadLibraryCalls( a_hModule );
        {
            INITCOMMONCONTROLSEX IccEx = { sizeof(INITCOMMONCONTROLSEX), ICC_WIN95_CLASSES };
            ::InitCommonControlsEx( &IccEx );
        }
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

