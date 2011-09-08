#include "Script_RQMS.h"
#include "Script_RQMS.rh"
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
    eCApplication::DestroySplashScreen();
    return ::MessageBoxExW( hParent, a_strMessage, a_strCaption, a_u32Type, 0 );
}

void AddScriptPatch( gSScriptInit & a_ScriptInit, GELPCChar a_pcOriginalFileName, GELPCChar a_pcName, gFScript a_funcScript, GELPCChar a_pcSource )
{
    eCScriptFunctionMap & ScriptFunctionMap = eCScriptFunctionMap::GetInstance();
    gSScript * pScript = static_cast< gSScript * >(
        const_cast< eSScriptBase * >( ScriptFunctionMap.GetScript( a_pcName ) ) );
    if( pScript && pScript->m_funcFunction )
    {
        gSScriptDLL * pScriptDLL = pScript->m_pScriptDLL;
        if( !pScriptDLL ||
            !pScriptDLL->m_strFileName.CompareNoCase( a_pcOriginalFileName ) ||
            IDYES == ApplicationMessageBox(
                GetFormattedResourceString( IDS_SCRIPT_RQMS_OVERRIDE_MESSAGE,
                    bCUnicodeString( a_pcName ).GetText(),
                    bCUnicodeString( pScriptDLL->m_strFileName ).GetText() ),
                GetFormattedResourceString( IDS_SCRIPT_RQMS_OVERRIDE_CAPTION ),
                MB_ICONQUESTION | MB_YESNO ) )
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
    AddScriptPatch( s_ScriptInit,
        "Script_Game.dll", "OnQuestChange", OnQuestChange,
        "Script/Story/Quest/OnQuestChange.cpp" );

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

