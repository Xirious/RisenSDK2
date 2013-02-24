#include "VarOperation.h"
#include "../../m_hook.h"
#include "../m_consolevaradmin.h"
#include "../m_commandhandler.h"

namespace
{
    struct SConsoleAccessor : public eCConsole2
    {
        static GELPByte GetConsoleInputRetrieveCode( void )
        {
            eCConsoleEdit2 * pConsoleEdit = static_cast< SConsoleAccessor * >( static_cast< GELPVoid >( &eCApplication::GetInstance().GetConsole2() ) )->m_pConsoleEdit;
            GEU32 * pVTable = *reinterpret_cast< GEU32 ** >( pConsoleEdit );
            GELPByte pCode = reinterpret_cast< GELPByte >( pVTable[ 65 ] );
            if ( *pCode++ != 0xE9 )
                return 0;
            pCode += sizeof( GEI32 ) + *reinterpret_cast< GEI32 * >( pCode ) + 0xF;
            if ( *pCode++ != 0xE8 )
                return 0;
            pCode += sizeof( GEI32 ) + *reinterpret_cast< GEI32 * >( pCode );
            return pCode;
        }
    };

    bCString s_strScriptName = "CON_#";

    void RegisterConsoleScript( bCString a_strName )
    {
        eCScriptFunctionMap & ScriptFunctionMap = eCScriptFunctionMap::GetInstance();
        if ( ( s_strScriptName == a_strName ) ||
             ( !ScriptFunctionMap.GetScript( s_strScriptName ) ) )
            return;
        eSScriptBase OldScript = *ScriptFunctionMap.GetScript( s_strScriptName );
        eSScriptBase & Script = *ScriptFunctionMap.RegisterScript( a_strName );
        Script.m_funcFunction = OldScript.m_funcFunction;
        Script.m_pScriptDLL = OldScript.m_pScriptDLL;
        Script.m_strSource = OldScript.m_strSource;
        ScriptFunctionMap.UnRegisterScript( const_cast< eSScriptBase * >( ScriptFunctionMap.GetScript( s_strScriptName ) ) );
        s_strScriptName = a_strName;
    };

    bCUnicodeString * GE_STDCALL OnRetrieveConsoleInput( bCUnicodeString * a_pDest, GEInt a_iParam1, GEInt a_iParam2 )
    {
        ( *mCCallHook::GetOriginalFunctionProxy( &OnRetrieveConsoleInput ) )( a_pDest, a_iParam1, a_iParam2 );
        bCUnicodeString strCommand = *a_pDest;
        for ( int i = 0, ie = strCommand.GetLength(); i != ie; ++i )
            if ( strCommand[ i ] == L' ' )
                strCommand = strCommand.Left( i ), i = ie - 1;
        if ( a_iParam1 == 0 && strCommand.GetLength() && strCommand[ 0 ] == L'#' )
            RegisterConsoleScript( "CON_" + strCommand.GetAnsiText() );
        return a_pDest;
    }

    mCCallHook s_ConsoleInputRetrieveHook( g_CallHookParams( SConsoleAccessor::GetConsoleInputRetrieveCode(), &OnRetrieveConsoleInput, GEFalse, 0 ) );
}

GEInt GE_STDCALL CON_VarOperation( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    SArgs & Args = *reinterpret_cast< SArgs * >( a_iArgs );
    bTObjArray< bCUnicodeString > & arrParams = Args.m_arrParams;
    bCUnicodeString & strLastParam = arrParams.GetCount() ? arrParams[ arrParams.GetCount() - 1 ] : Args.m_strResult;
    mCConsoleVarAdmin & ConsoleVarAdmin = mCConsoleVarAdmin::GetInstance();
    bCString strName = s_strScriptName.Right( s_strScriptName.GetLength() - 5 );
    bCString strText;
    ConsoleVarAdmin.GetVariable( strName, strText );
    switch( Args.m_enuReason )
    {
    case SArgs::EReason_Help:
        Args.m_strResult = L"Console variables can be displayed, set (or modified), executed and used as parameters for all console commands introduced in Script_Extensions.\n" \
                           L"Variable names are prefixed with '#'. Basic wildcards ('*' at begin and/or end of a variable name) are supported for display/set/append/execute operations.\n"
                           L"Setting a variable to '$' removes it. All variables are persistent as they are stored in %localappdata%\\Risen\\ConsoleVariables.ini.\n" \
                           L"There are some special variables: #c (clipboard text) and #r1/#r2/#r3/#r4/#r5 (last five results of certain console commands).\n" \
                           L"Operators:\n" \
                           L"  '=' (set), '+=' (append), '!' (execute)\n" \
                           L"Usage:\n" \
                           L"  #<variable name, may contain wildcards> <operator, only for set/append/execute operations> <parameter(s), only for set/append operations>";
        return 1;
    case SArgs::EReason_AutoComplete:
        if ( arrParams.GetCount() == 1 )
            return strLastParam = arrParams[ 0 ] == L"=" ? L"+=" : ( arrParams[ 0 ] == L"+=" ? L"!" : L"=" ), 1;
        if ( !strLastParam.GetLength() || strLastParam[ 0 ] != L'#' )
            return strLastParam = mCCommandHandler::RegisterOrAutoCompleteParameter(), 1;
        return strLastParam = L"#" + ConsoleVarAdmin.GetNextVariable( strLastParam.Right( strLastParam.GetLength() - 1 ).GetAnsiText() ).GetUnicodeText(), 1;
    case SArgs::EReason_Execute:
        for ( ; arrParams.GetCount() > 2; arrParams.RemoveAt( 2 ) )
            arrParams[ 1 ] += L" " + arrParams[ 2 ];
        if ( !mCCommandHandler::ParseParameters( arrParams, Args.m_strResult ) )
            return 0;
        if ( ( arrParams.GetCount() == 1 && arrParams[ 0 ] != L"!" ) ||
             ( arrParams.GetCount() == 2 && arrParams[ 0 ] != L"=" && arrParams[ 0 ] != L"+=" ) )
            return Args.m_strResult = L"Invalid command usage. Use \"# help\" for more information.", 0;
        if ( strName.GetLength() && ( strName[ 0 ] == '*' || strName[ strName.GetLength() - 1 ] == '*' ) )
        {
            bTObjArray< bCString > arrVariableNames;
            ConsoleVarAdmin.GetVariableNames( strName, arrVariableNames );
            if ( arrVariableNames.GetCount() == 0 )
                return Args.m_strResult = L"No variables found.", 0;
            bCUnicodeString strParams;
            for ( GEInt i = 0, ie = arrParams.GetCount(); i != ie; ++i )
                strParams += L" " + arrParams[ i ];
            bCString const strScriptName = s_strScriptName;
            GEInt iFailedCount = arrVariableNames.GetCount();
            for ( GEInt i = 0, ie = arrVariableNames.GetCount(); i != ie; ++i )
            {
                s_strScriptName = "CON_#" + arrVariableNames[ i ];
                SArgs Args2 = { SArgs::EReason_Execute, bTObjArray< bCUnicodeString >( arrParams ), L"" };
                GEInt iResult = CON_VarOperation( 0, 0, 0, reinterpret_cast< GEInt >( &Args2 ) );
                iFailedCount -= iResult;
                if ( arrParams.GetCount() == 0 )
                    Args.m_strResult += L"    #" + arrVariableNames[ i ].GetUnicodeText() + L" = " + Args2.m_strResult + L"\n";
            }
            s_strScriptName = strScriptName;
            if ( arrParams.GetCount() == 0 )
                Args.m_strResult += bCUnicodeString::GetFormattedString( L"%u variables found.", arrVariableNames.GetCount() );
            else if ( arrParams[ 0 ] == L"!" )
                Args.m_strResult = bCUnicodeString::GetFormattedString( L"%u commands executed, %u failed.", arrVariableNames.GetCount(), iFailedCount );
            else if ( arrParams[ 0 ] == L"=" && arrParams[ 1 ] == L"0" )
                Args.m_strResult = bCUnicodeString::GetFormattedString( L"%u variables removed.", arrVariableNames.GetCount() );
            else if ( arrParams[ 0 ] == L"=" )
                Args.m_strResult = bCUnicodeString::GetFormattedString( L"%u variables set to '%s'.", arrVariableNames.GetCount(), arrParams[ 1 ].GetText() );
            else
                Args.m_strResult = bCUnicodeString::GetFormattedString( L"Appended %u variables '%s'.", arrVariableNames.GetCount(), arrParams[ 1 ].GetText() );
            return 1;
        }
        if ( arrParams.GetCount() == 0 )
            return Args.m_strResult = strText.GetLength() ? strText.GetUnicodeText() : L"Unknown variable.", strText.GetLength() ? 1 : 0;
        else if ( arrParams[ 0 ] == L"!" )
        {
            if ( !strText.GetLength() )
                return Args.m_strResult = L"Unknown variable.", 0;
            bTObjArray< bCUnicodeString > arrParams2;
            strText += " ";
            for ( GEInt i = 0, v = 0, ie = strText.GetLength(); i != ie; ++i )
                if ( strText[ i ] == ' ' )
                    arrParams2.Add( strText.Mid( v, i - v ).GetUnicodeText() ), v = i + 1;
            if ( arrParams2[ 0 ].GetLength() && arrParams2[ 0 ][ 0 ] == L'#' )
            {
                bCString const strScriptName = s_strScriptName;
                s_strScriptName = "CON_" + arrParams2[ 0 ].GetAnsiText();
                arrParams2.RemoveAt( 0 );
                SArgs Args2 = { SArgs::EReason_Execute, arrParams2, L"" };
                GEInt iResult = CON_VarOperation( 0, 0, 0, reinterpret_cast< GEInt >( &Args2 ) );
                s_strScriptName = strScriptName;
                return Args.m_strResult = Args2.m_strResult, iResult;
            }
            else
            {
                eCScriptProxyScript ProxyScript( "CON_" + arrParams2[ 0 ].GetAnsiText() );
                if ( !ProxyScript.IsScriptValid() )
                    return Args.m_strResult = L"Unknown command: \"" + arrParams2[ 0 ] + L"\".", 0;
                arrParams2.RemoveAt( 0 );
                if ( !mCCommandHandler::ParseParameters( arrParams2, Args.m_strResult ) )
                    return 0;
                SArgs Args2 = { SArgs::EReason_Execute, arrParams2, L"" };
                GEInt iResult = ProxyScript( 0, 0, reinterpret_cast< GEInt >( &Args2 ) );
                return Args.m_strResult = Args2.m_strResult, iResult;
            }
        }
        else if ( arrParams[ 0 ] == L"=" || ( arrParams[ 1 ] = strText.GetUnicodeText() + arrParams[ 1 ], arrParams[ 0 ] == L"+=" ) )
        {
            if ( arrParams[ 1 ] == L"$" )
            {
                ConsoleVarAdmin.RemoveVariable( strName );
                return Args.m_strResult = L"Removed #" + strName.GetUnicodeText() + L".", 1; 
            }
            ConsoleVarAdmin.SetVariable( strName, arrParams[ 1 ].GetAnsiText() );
            return Args.m_strResult = arrParams[ 1 ], 1;
        }
        return 0;
    default:
        return 0;
    }
}