#include "Script_Clock.h"
#include "Script_Clock.rh"
#pragma warning( push, 0 )
#include <commctrl.h>
#pragma warning( pop )
#pragma comment( lib, "comctl32" )
#pragma comment( lib, "user32" )

HMODULE g_hModule = 0;

bCUnicodeString GetResourceString( GEUInt a_uID )
{
    bCUnicodeString strResult;
    GELPUnicodeChar pcResult = 0;
    GEInt iResultLength = ::LoadStringW( g_hModule, a_uID, reinterpret_cast< LPWSTR >( &pcResult ), 0 );
    if( (iResultLength > 0) && pcResult )
    {
        strResult.SetText( pcResult, iResultLength );
        ::LocalFree( reinterpret_cast< HLOCAL >( pcResult ) );
    }
    return strResult;
}

bCUnicodeString GetFormattedResourceString( GEUInt a_uID, ... )
{
    bCUnicodeString strResult;
    bCUnicodeString strFormat = GetResourceString( a_uID );
    if( !strFormat.IsEmpty() )
    {
        LPWSTR pcResult = 0;
        va_list Arguments;
        va_start( Arguments, a_uID );
        if( ::FormatMessageW( FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            strFormat.GetText(), 0, 0, reinterpret_cast< LPWSTR >( &pcResult ), 0, &Arguments ) )
        {
            strResult = pcResult;
            if( pcResult )
                ::LocalFree( reinterpret_cast< HLOCAL >( pcResult ) );
        }
    }
    return strResult;
}

GEInt ApplicationMessageBox( bCUnicodeString const & a_strMessage, bCUnicodeString const & a_strCaption, GEU32 a_u32Type )
{
    HWND hParent = eCApplication::IsInitialised() ? eCApplication::GetInstance().GetHandle() : 0;
    if( !hParent && (0 == (a_u32Type & (
        MB_SYSTEMMODAL |
        MB_NOFOCUS |
        MB_SETFOREGROUND |
        MB_DEFAULT_DESKTOP_ONLY |
        MB_TOPMOST |
        MB_SERVICE_NOTIFICATION))) )
    {
        a_u32Type |= MB_TASKMODAL;
    }
    return ::MessageBoxExW( hParent, a_strMessage, a_strCaption, a_u32Type, 0 );
}

GEInt GE_STDCALL CON_clock( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iIntParameter )
{
    gSConScriptArgs & ConArgs = *reinterpret_cast< gSConScriptArgs * >( a_iIntParameter );
    switch( ConArgs.m_enumEvent )
    {
    case gEConScriptEvent_Help:
        ConArgs.m_strResult = GetResourceString( IDS_SCRIPT_CLOCK_CONHELP );
        return GETrue;
    case gEConScriptEvent_Execute:
        {
            bCDateTime SystemTime;
            SystemTime.Update();
            bCString strSystemTime;
            SystemTime.GetTimeString( strSystemTime );
            bCUnicodeString strUserMsg = GetFormattedResourceString(
                IDS_SCRIPT_CLOCK_SYSTIME,
                strSystemTime.GetText()  // %1!S!
                );
            bCUnicodeString strGameMsg;
            PSClock const & Clock = Entity::GetWorldEntity().GetPropertySet< PSClock >();
            if( Clock.IsValid() )
            {
                GEInt iYear = Clock.GetYear();
                GEInt iMonth = Clock.GetMonth();
                GEInt iDay = Clock.GetDay();
                GEInt iGameDays = iYear * 365 + iDay;
                //NOTE: [NicoDE] This is the reverse of the hard-coded logic
                // how PSClock splits gCClock_PS.m_u32Day into Day and Month.
                switch( iMonth )
                {
                case 12: iGameDays += 334; break;
                case 11: iGameDays += 304; break;
                case 10: iGameDays += 273; break;
                case 9: iGameDays += 243; break;
                case 8: iGameDays += 212; break;
                case 7: iGameDays += 181; break;
                case 6: iGameDays += 151; break;
                case 5: iGameDays += 120; break;
                case 4: iGameDays += 90; break;
                case 3: iGameDays += 59; break;
                case 2: iGameDays += 31; break;
                }
                strGameMsg = GetFormattedResourceString(
                    IDS_SCRIPT_CLOCK_GAMEMSG,
                    iYear,              // %1!i!
                    iMonth,             // %2!i!
                    iDay,               // %3!i!
                    Clock.GetHour(),    // %4!i!
                    Clock.GetMinute(),  // %5!i!
                    iGameDays,          // %6!i!
                    iGameDays + 1       // %7!i!
                    );
            }
            ConArgs.m_strResult = GetFormattedResourceString(
                IDS_SCRIPT_CLOCK_MESSAGE,
                strUserMsg.GetText(),  // %1!s!
                strGameMsg.GetText()   // %2!s!
                );
            if( ConArgs.m_strResult.IsEmpty() )
                ConArgs.m_strResult = GetResourceString( IDS_SCRIPT_CLOCK_DEFAULT );
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
            {
                gELogMessageType enumType = static_cast< gELogMessageType >(
                    GetResourceString( IDS_SCRIPT_CLOCK_LOGTYPE ).GetInteger() );
                if( enumType < gELogMessageType_Grey )
                    enumType = gELogMessageType_Grey;
                if( enumType > gELogMessageType_Lime )
                    enumType = gELogMessageType_Lime;
                GEBool bLarge = GetResourceString( IDS_SCRIPT_CLOCK_LOGSIZE ).GetBool();
                bCUnicodeString strDelimeters( L"\n" );
                bTObjArray< bCUnicodeString > arrLines;
                GEInt iLineCount = static_cast< GEInt >(
                    ConArgs.m_strResult.Split( strDelimeters, &arrLines ) );
                if( iLineCount > 0 )
                {
                    for( GEInt iLine = 0; iLine < iLineCount - 1; ++iLine )
                        gui2.PrintGameLog( arrLines[ iLine ], enumType, bLarge, 0 );
                    gui2.PrintGameLog( arrLines[ iLineCount - 1 ], enumType, bLarge,
                        GetResourceString( IDS_SCRIPT_CLOCK_LOGXEFF ).GetAnsiText().GetBuffer( 0 ) );
                }
            }
            else
            {
                ApplicationMessageBox( ConArgs.m_strResult,
                    GetResourceString( IDS_SCRIPT_CLOCK_CAPTION ),
                    MB_ICONINFORMATION );
            }
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

