#include "m_consolevaradmin.h"
#include "../m_utils.h"

void mCConsoleVarAdmin::Clear( void )
{
    m_mapVars.Clear();
    m_mapVars.InitHashTable( 211 );
    m_mapVars[ "c" ] = "";
}

GEBool mCConsoleVarAdmin::ExistsVariable( bCString a_strName ) const
{
    a_strName.ToLower();
    return m_mapVars.IsValidKey( a_strName );
}

bCString mCConsoleVarAdmin::GetNextVariable( bCString a_strCurrent ) const
{
    a_strCurrent.ToLower();
    bCString strDummy = "\x7F";
    bCString const * pResult = &strDummy;
    for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
        if ( ( i.GetKey() < *pResult ) && ( i.GetKey() > a_strCurrent ) )
            pResult = &i.GetKey();
    return pResult == &strDummy ? GetNextVariable( "" ) : *pResult;
}

GEBool mCConsoleVarAdmin::GetVariable( bCString a_strName, bCString & a_strDest ) const
{
    a_strName.ToLower();
    if ( a_strName != "c" )
        return m_mapVars.GetAt( a_strName, a_strDest );
    if ( GetClipboardText() == L"" )
        return a_strDest = "<no_clipboard_text_available>", GETrue;
    bCString strClipboardText = GetClipboardText().GetAnsiText() + "\n";
    for ( GELPCChar pcIt = strClipboardText.GetText(), pcEnd = pcIt + strClipboardText.GetLength(); pcIt != pcEnd; ++pcIt )
        if ( ( *pcIt == '\n' ) || ( *pcIt == '\t' ) || ( *pcIt == '\r' ) )
            return a_strDest = strClipboardText.Left( pcIt - strClipboardText.GetText() ), GETrue;
    return GETrue;
}

bCString mCConsoleVarAdmin::GetVariable( bCString const & a_strName ) const
{
    bCString strResult;
    GetVariable( a_strName, strResult );
    return strResult;
}

void mCConsoleVarAdmin::GetVariableNames( bTObjArray< bCString > & a_arrDest ) const
{
    a_arrDest.Clear();
    a_arrDest.Reserve( m_mapVars.GetCount() );
    for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
        a_arrDest.Add( i.GetKey() );
}

namespace
{
    GEInt GE_CCALL CompareStrings( GELPCVoid a_pFirst, GELPCVoid a_pSecond )
    {
        return static_cast< bCString const * >( a_pFirst )->Compare( *static_cast< bCString const * >( a_pSecond ) );
    }
}

void mCConsoleVarAdmin::GetVariableNames( bCString a_strWildCard, bTObjArray< bCString > & a_arrDest ) const
{
    a_arrDest.Clear();
    GEInt iLength = a_strWildCard.GetLength();
    if ( iLength == 0 )
        return;
    a_strWildCard.ToLower();
    if ( a_strWildCard == "*" || a_strWildCard == "**" )
    {
        GetVariableNames( a_arrDest );
    }
    else if ( a_strWildCard[ 0 ] == '*' && a_strWildCard[ iLength - 1 ] == '*' )
    {
        a_strWildCard = a_strWildCard.Mid( 1, iLength -= 2 );
        for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
            if ( i.GetKey().Contains( a_strWildCard.GetText(), 0 ) )
                a_arrDest.Add( i.GetKey() );
    }
    else if ( a_strWildCard[ 0 ] == '*' )
    {
        a_strWildCard = a_strWildCard.Right( --iLength );
        for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
            if ( i.GetKey().Right( iLength ) == a_strWildCard )
                a_arrDest.Add( i.GetKey() );
    }
    else if ( a_strWildCard[ iLength - 1 ] == '*' )
    {
        a_strWildCard = a_strWildCard.Left( --iLength );
        for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
            if ( i.GetKey().Left( iLength ) == a_strWildCard )
                a_arrDest.Add( i.GetKey() );
    }
    else
    {
        if ( ExistsVariable( a_strWildCard ) )
            a_arrDest.Add( a_strWildCard );
    }
    qsort( a_arrDest.AccessArray(), static_cast< size_t >( a_arrDest.GetCount() ), sizeof( a_arrDest[ 0 ] ), CompareStrings );
}

void mCConsoleVarAdmin::Load( void )
{
    bCMemoryStream streamSource;
    if ( !FromFile( streamSource, ( GetRisenAppdataPath() + "\\ConsoleVariables.ini" ).GetText() ) )
        return;
    while ( streamSource.GetPosition() != streamSource.GetSize() )
    {
        bCString strLine;
        streamSource.ReadLine( strLine );
        for ( GEInt i = 0, iLength = strLine.GetLength(); i != iLength; ++i )
            if ( strLine[ i ] == ' ' )
                SetVariable( strLine.Left( i ), strLine.Right( iLength - i - 1 ) ), i = iLength - 1;
    }
}

void mCConsoleVarAdmin::RemoveVariable( bCString a_strName )
{
    a_strName.ToLower();
    if ( a_strName != "c" )
        m_mapVars.RemoveAt( a_strName );
}

void mCConsoleVarAdmin::Save( void )
{
    bCMemoryStream streamDest;
    for ( bTStringValMap< bCString >::bCConstIterator i = m_mapVars.Begin(), ie = m_mapVars.End(); i != ie; ++i )
        streamDest.WriteLine( i.GetKey() + " " + *i );
    ToFile( streamDest, ( GetRisenAppdataPath() + "\\ConsoleVariables.ini" ).GetText() );
}

void mCConsoleVarAdmin::SetVariable( bCString a_strName, bCString const & a_strText )
{
    a_strName.ToLower();
    if ( a_strName == "" )
        return;
    if ( a_strName == "c" )
        SetClipboardText( a_strText.GetUnicodeText() );
    else
        m_mapVars[ a_strName ] = a_strText;
}

mCConsoleVarAdmin & mCConsoleVarAdmin::GetInstance( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )
    static mCConsoleVarAdmin * s_pInstance = new mCConsoleVarAdmin;
#pragma warning( pop )
    return *s_pInstance;
}

mCConsoleVarAdmin::mCConsoleVarAdmin( void )
{
    Clear();
    Load();
}

mCConsoleVarAdmin::~mCConsoleVarAdmin( void )
{
}