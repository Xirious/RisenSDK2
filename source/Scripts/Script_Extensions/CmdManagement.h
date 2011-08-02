#ifndef CMD_MANAGEMENT_H_INCLUDED
#define CMD_MANAGEMENT_H_INCLUDED

#include "Utils.h"

struct SArgs
{
    enum EReason
    {
        EReason_Help,
        EReason_AutoComplete,
        EReason_Execute
    }                             m_enuReason;
    bTObjArray< bCUnicodeString > m_arrParams;
    bCUnicodeString               m_strResult;
};

namespace CmdManagement
{
    typedef bCUnicodeString( *SubCmdFuncPtr )( bTObjArray< bCUnicodeString >, gCScriptProcessingUnit * );

    struct SubCmdInfo
    {
        bCUnicodeString strName;
        GEU32           uParamCount;
        SubCmdFuncPtr   pFunction;
        SubCmdFuncPtr   pAutoComplete;
        bCUnicodeString strHelpText;
        __forceinline ~SubCmdInfo( void ) {};  // To avoid C4710.
    };

    template< GEInt x > const bTObjArray< SubCmdInfo > & GetSubCmdInfos( void );

    template< GEInt x >
    bCUnicodeString GetCmdHelpText( bCUnicodeString a_strCmdDescription, bCUnicodeString a_strCmdUsage )
    {
        const bTObjArray< SubCmdInfo > & arrSubCmdInfos = GetSubCmdInfos< x >();
        bCUnicodeString Result = a_strCmdDescription + L"\n";
        Result += L"Usage:\n";
        Result += L"  " + a_strCmdUsage + L"\n";
        Result += L"Commands:\n";
        for ( GEInt i = 0, ie = arrSubCmdInfos.GetCount(); i != ie; ++i )
        {
            Result += L"  " + arrSubCmdInfos[i].strName + L"\n";
        }
        Result += L"Additional help is available for all commands. Use autocompletion (TAB) to skip through them.\n";
        return Result;
    }

    template< GEInt x >
    bCUnicodeString GetSubCmdHelpText( bCUnicodeString a_strName )
    {
        bCUnicodeString Result;
        const SubCmdInfo * SubCommandInfo = GetSubCmdInfo< x >( a_strName );
        if ( SubCommandInfo == 0 )
        {
            Result = L"Unknown command.";
            return Result;
        }
        Result = SubCommandInfo->strHelpText + L"\n";
        if ( ( SubCommandInfo->pAutoComplete == 0 ) && ( SubCommandInfo->uParamCount != 0 ) )
            Result += L"Autocompletion (TAB) inserts successively the last ten reuslts or parameters and the clipboard content as parameter.\n";
        return Result;
    }

    template< GEInt x >
    bCUnicodeString GetAutoCompletedSubCmdName( bCUnicodeString a_strText )
    {
        const bTObjArray< SubCmdInfo > & arrSubCmdInfos = GetSubCmdInfos< x >();
        for ( GEInt i = 0, ie = arrSubCmdInfos.GetCount(); i != ie; ++i )
        {
            if( a_strText.CompareNoCase( arrSubCmdInfos[ i ].strName ) < 0 )
                return arrSubCmdInfos[ i ].strName;
        }
        return arrSubCmdInfos[ 0 ].strName;
    }

    template< GEInt x >
    const SubCmdInfo * GetSubCmdInfo( bCUnicodeString a_strName )
    {
        const bTObjArray< SubCmdInfo > & arrSubCmdInfos = GetSubCmdInfos< x >();
        for ( GEInt i = 0, ie = arrSubCmdInfos.GetCount(); i != ie; ++i )
        {
            if( a_strName.CompareNoCase( arrSubCmdInfos[ i ].strName ) == 0 )
                return &arrSubCmdInfos[ i ];
        }
        return 0;
    }

    template< GEInt x >
    GEInt HandleCmdCall( bCUnicodeString CmdName, GELPCUnicodeChar CmdDescription, GELPCUnicodeChar CmdUsage, gCScriptProcessingUnit * a_pSPU, GEInt a_iArgs )
    {
        SArgs & Args = *reinterpret_cast< SArgs * >( a_iArgs );

        switch( Args.m_enuReason )
        {
        case SArgs::EReason_Help:
            {
                if ( Args.m_arrParams.GetCount() > 1 )
                    Args.m_strResult = GetSubCmdHelpText< x >( Args.m_arrParams[ 0 ] );
                else
                    Args.m_strResult = GetCmdHelpText< x >( CmdDescription, CmdUsage );
                return 1;
            }
        case SArgs::EReason_AutoComplete:
            {
                if ( Args.m_arrParams.GetCount() == 1 )
                {
                    Args.m_arrParams[ 0 ] = GetAutoCompletedSubCmdName< x >( Args.m_arrParams[ 0 ] );
                }
                else
                {
                    GEInt i = ( Args.m_arrParams.GetCount() - 1 );
                    const SubCmdInfo * SubCommandInfo = GetSubCmdInfo< x >( Args.m_arrParams[ 0 ] );
                    if ( !SubCommandInfo )
                        return 0;
                    if ( !SubCommandInfo->pAutoComplete )
                    {

#pragma warning( push )
#pragma warning( disable : 4640 )

                        static bCUnicodeString strLastSubCmdName;

#pragma warning( pop )
                        if ( strLastSubCmdName != Args.m_arrParams[ 0 ] )
                        {
                            bCUnicodeString strDummy = L"";
                            ParamAutoCompletion( &strDummy );
                            strLastSubCmdName = Args.m_arrParams[ 0 ];
                        }
                            
                        Args.m_arrParams.AccessAt( i ) = ParamAutoCompletion();
                    }
                    else
                    {
                        Args.m_arrParams.AccessAt( i ) = ( *SubCommandInfo->pAutoComplete )( Args.m_arrParams, a_pSPU );
                    }
                }
                return 1;
            }
        case SArgs::EReason_Execute:
            {
                if ( Args.m_arrParams.GetCount() == 0 )
                {
                    Args.m_strResult = L"Please specify a command (use \"" + CmdName + L" help\" to get a list of them).";
                    return 0;
                }
                const SubCmdInfo * SubCommandInfo = GetSubCmdInfo< x >( Args.m_arrParams[ 0 ] );
                if ( !SubCommandInfo )
                {
                    Args.m_strResult = L"Unknown command.";
                    return 0;
                }
                if ( ( SubCommandInfo->uParamCount + 1 ) != static_cast< GEU32>( Args.m_arrParams.GetCount() ) )
                {
                    Args.m_strResult = L"Wrong argument count. Use \"" + CmdName + L" " + SubCommandInfo->strName + L" help\" to learn about the command's usage.";
                    return 0;
                }
                Args.m_strResult = ( *SubCommandInfo->pFunction )( Args.m_arrParams, a_pSPU );
                if ( Args.m_strResult.Contains( L"$", 0 ) )
                {
                    Args.m_strResult.Remove( L"$" );
                    return 0;
                }
                return 1;
            }
        default:
            {
                Args.m_strResult = L"Unknown command action.";
                return 0;
            }
        }
    }
}

#endif  // CMD_MANAGEMENT_H_INCLUDED