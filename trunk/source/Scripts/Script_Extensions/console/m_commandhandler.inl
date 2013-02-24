template< gFScript x >
void mTCommandHandler< x >::AutoCompleteSubCommandName( bCUnicodeString & a_strName )
{
    bTObjArray< SSubCommandDesc > const & arrSubCommandDescs = GetSubCommandDescs();
    for ( GEInt i = 0, ie = arrSubCommandDescs.GetCount(); i != ie; ++i )
    {
        if ( a_strName.CompareNoCase( arrSubCommandDescs[ i ].m_strName ) < 0 )
        {
            a_strName = arrSubCommandDescs[ i ].m_strName;
            return;
        }
    }
    a_strName = arrSubCommandDescs[ 0 ].m_strName;
}

template< gFScript x >
mCCommandHandler::SSubCommandDesc const * mTCommandHandler< x >::FindSubCommandDesc( bCUnicodeString const & a_strName )
{
    bTObjArray< SSubCommandDesc > const & arrSubCommandDescs = GetSubCommandDescs();
    for ( GEInt i = 0, ie = arrSubCommandDescs.GetCount(); i != ie; ++i )
        if ( a_strName.CompareNoCase( arrSubCommandDescs[ i ].m_strName ) == 0 )
            return &arrSubCommandDescs[ i ];
    return 0;
}

template< gFScript x >
bCUnicodeString mTCommandHandler< x >::GetCommandHelpText( bCUnicodeString const & a_strDescription, bCUnicodeString const & a_strUsage )
{
    bTObjArray< SSubCommandDesc > const & arrSubCommandDescs = GetSubCommandDescs();
    bCUnicodeString strResult = a_strDescription + L"\n";
    strResult += L"Usage:\n";
    strResult += L"  " + a_strUsage + L"\n";
    strResult += L"Commands:\n";
    for ( GEInt i = 0, ie = arrSubCommandDescs.GetCount(); i != ie; ++i )
        strResult += L"  " + arrSubCommandDescs[ i ].m_strName + L"\n";
    strResult += L"Additional help is available for all commands. You can skip through them using autocompletion (TAB).\n";
    return strResult;
}

template< gFScript x >
bCUnicodeString mTCommandHandler< x >::GetSubCommandHelpText( bCUnicodeString const & a_strName )
{
    SSubCommandDesc const * pSubCommandDesc = FindSubCommandDesc( a_strName );
    if ( !pSubCommandDesc )
        return L"Unknown command.";
    bCUnicodeString strResult = pSubCommandDesc->m_strHelpText + L"\n";
    if ( ( pSubCommandDesc->m_pfuncAutoComplete == 0 ) && ( pSubCommandDesc->m_iParameterCountMax != 0 ) )
        strResult += L"Autocompletion (TAB) successively inserts the last ten reuslts or parameters.\n";
    return strResult;
}

template< gFScript x >
GEInt mTCommandHandler< x >::HandleCommandCall( bCUnicodeString const & a_strName, bCUnicodeString const & a_strDescription, bCUnicodeString const & a_strUsage, gCScriptProcessingUnit * a_pSPU, GEInt a_iArgs )
{
    SArgs & Args = *reinterpret_cast< SArgs * >( a_iArgs );
    bTObjArray< bCUnicodeString > & arrParams = Args.m_arrParams;
    SSubCommandDesc const * pSubCommandDesc = arrParams.GetCount() ? FindSubCommandDesc( arrParams[ 0 ] ) : 0;
    switch( Args.m_enuReason )
    {
    case SArgs::EReason_Help:
        if ( arrParams.GetCount() > 1 )
            Args.m_strResult = GetSubCommandHelpText( arrParams[ 0 ] );
        else
            Args.m_strResult = GetCommandHelpText( a_strDescription, a_strUsage );
        return 1;
    case SArgs::EReason_AutoComplete:
        if ( arrParams.GetCount() != 1 )
        {
            if ( !pSubCommandDesc )
                return 0;
            bCUnicodeString & strLastParam = arrParams[ arrParams.GetCount() - 1 ];
            if ( strLastParam.GetLength() && strLastParam[ 0 ] == L'#' )
                strLastParam = L"#" + mCConsoleVarAdmin::GetInstance().GetNextVariable( strLastParam.Right( strLastParam.GetLength() - 1 ).GetAnsiText() ).GetUnicodeText();
            else if ( pSubCommandDesc->m_pfuncAutoComplete )
                strLastParam = ( *pSubCommandDesc->m_pfuncAutoComplete )( arrParams, a_pSPU );
            else
            {
#pragma warning( push )
#pragma warning( disable : 4640 )
                static bCUnicodeString s_strLastSubCmdName;
#pragma warning( pop )
                if ( s_strLastSubCmdName != arrParams[ 0 ] )
                {
                    s_strLastSubCmdName = arrParams[ 0 ];
                    bCUnicodeString strDummy;
                    RegisterOrAutoCompleteParameter( &strDummy );
                }
                strLastParam = RegisterOrAutoCompleteParameter();
            }
        }
        else
            AutoCompleteSubCommandName( arrParams[ 0 ] );
        return 1;
    case SArgs::EReason_Execute:
        if ( !ParseParameters( arrParams, Args.m_strResult ) )
            return 0;
        if ( arrParams.GetCount() == 0 )
            return Args.m_strResult = L"Please specify a command (use \"" + a_strName + L" help\" to get a list of supported commands).", 0;
        if ( !pSubCommandDesc )
            return Args.m_strResult = L"Unknown command.", 0;
        if ( arrParams.GetCount() < pSubCommandDesc->m_iParameterCountMin + 1 || arrParams.GetCount() > pSubCommandDesc->m_iParameterCountMax + 1 )
            return Args.m_strResult = L"Wrong argument count. You can use \"" + a_strName + L" " + pSubCommandDesc->m_strName + L" help\" to learn more about the command's usage.", 0;
        Args.m_strResult = ( *pSubCommandDesc->m_pfuncExecute )( arrParams, a_pSPU );
        if ( Args.m_strResult.Contains( L"$", 0 ) )
            return Args.m_strResult.Remove( L"$" ), 0;
        return 1;
    default:
        return Args.m_strResult = L"Unknown command action.", 0;
    }
}