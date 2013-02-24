#include "m_commandhandler.h"
#include "m_consolevaradmin.h"

bCUnicodeString mCCommandHandler::RegisterOrAutoCompleteParameter( bCUnicodeString const * a_strParameterToRegister )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< bCUnicodeString > arrResults;
    static GEU32 i = 0;

#pragma warning( pop )

    if ( !a_strParameterToRegister )
        return arrResults.GetCount() ? arrResults[ static_cast< GEInt >( i++ % arrResults.GetCount() ) ] : L"";
    i = 0;
    if ( *a_strParameterToRegister == L"" )
        return L"";
    arrResults.Remove( *a_strParameterToRegister );
    arrResults.InsertAt( 0, *a_strParameterToRegister );
    if ( arrResults.GetCount() == 11 )
        arrResults.RemoveAt( 10 );
    return L""; 
}

GEBool mCCommandHandler::ParseParameters( bTObjArray< bCUnicodeString > & a_arrParams, bCUnicodeString & a_strError )
{
    for ( GEInt i = a_arrParams.GetCount(); i--; )
    {
        if ( !a_arrParams[ i ].GetLength() || a_arrParams[ i ][ 0 ] != L'#' || a_arrParams[ i ].Contains( L' ', 0 ) )
            continue;
        bCString strText;
        if ( !mCConsoleVarAdmin::GetInstance().GetVariable( a_arrParams[ i ].Right( a_arrParams[ i ].GetLength() - 1 ).GetAnsiText(), strText ) )
            return a_strError = L"Unknown variable: " + a_arrParams[ i ], GEFalse;
        a_arrParams[ i ] = strText.GetUnicodeText();
    }
    return GETrue;
}

bCUnicodeString const & mCCommandHandler::PushResult( bCUnicodeString const & a_strResult )
{
    mCConsoleVarAdmin & ConsoleVarAdmin = mCConsoleVarAdmin::GetInstance();
    ConsoleVarAdmin.SetVariable( "r5", ConsoleVarAdmin.GetVariable( "r4" ) );
    ConsoleVarAdmin.SetVariable( "r4", ConsoleVarAdmin.GetVariable( "r3" ) );
    ConsoleVarAdmin.SetVariable( "r3", ConsoleVarAdmin.GetVariable( "r2" ) );
    ConsoleVarAdmin.SetVariable( "r2", ConsoleVarAdmin.GetVariable( "r1" ) );
    ConsoleVarAdmin.SetVariable( "r1", a_strResult.GetAnsiText() );
    return a_strResult;
}