#ifndef M_CONSOLEVARADMIN_H_INCLUDED
#define M_CONSOLEVARADMIN_H_INCLUDED

#include "SharedBase.h"

class mCConsoleVarAdmin
{
public:
    void     Clear( void );
    GEBool   ExistsVariable( bCString a_strName ) const;
    bCString GetNextVariable( bCString a_strCurrent ) const;
    GEBool   GetVariable( bCString a_strName, bCString & a_strDest ) const;
    bCString GetVariable( bCString const & a_strName ) const;
    void     GetVariableNames( bTObjArray< bCString > & a_arrDest ) const;
    void     GetVariableNames( bCString a_strWildCard, bTObjArray< bCString > & a_arrDest ) const;
    void     Load( void );
    void     RemoveVariable( bCString a_strName );
    void     Save( void );
    void     SetVariable( bCString a_strName, bCString const & a_strText );
public:
    static mCConsoleVarAdmin & GetInstance( void );
private:
    mCConsoleVarAdmin( void );
    mCConsoleVarAdmin( mCConsoleVarAdmin const & );
   ~mCConsoleVarAdmin( void );
private:
    bTStringValMap< bCString > m_mapVars;
};

#endif