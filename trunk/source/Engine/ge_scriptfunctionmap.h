#ifndef GE_SCRIPTFUNCTIONMAP_H_INCLUDED
#define GE_SCRIPTFUNCTIONMAP_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTStringObjMap<T>' needs to have dll-interface to be used by clients of class 'eCScriptFunctionMap'

class GE_DLLIMPORT eCScriptFunctionMap
{
protected:
    bTStringObjMap< eSScriptBase > m_mapAIStates;
    bTStringObjMap< eSScriptBase > m_mapAIFunctions;
    bTStringObjMap< eSScriptBase > m_mapAICallbacks;
    bTStringObjMap< eSScriptBase > m_mapScripts;
public:
    static eCScriptFunctionMap & GE_STDCALL GetInstance( void );
public:
    bCString             FindNextScript( bCString const &, bCString const & );
    eSScriptBase const * GetScript( bCString const & ) const;
    eSScriptBase const * GetScriptAICallback( bCString const & ) const;
    eSScriptBase const * GetScriptAIFunction( bCString const & ) const;
    eSScriptBase const * GetScriptAIState( bCString const & ) const;
    eSScriptBase *       RegisterScript( bCString const & );
    eSScriptBase *       RegisterScriptAICallback( bCString const & );
    eSScriptBase *       RegisterScriptAIFunction( bCString const & );
    eSScriptBase *       RegisterScriptAIState( bCString const & );
    GEBool               UnRegisterScript( eSScriptBase * );
    GEBool               UnRegisterScriptAICallback( eSScriptBase * );
    GEBool               UnRegisterScriptAIFunction( eSScriptBase * );
    GEBool               UnRegisterScriptAIState( eSScriptBase * );
public:
    eCScriptFunctionMap & operator = ( eCScriptFunctionMap const & );
public:
    eCScriptFunctionMap( eCScriptFunctionMap const & );
    eCScriptFunctionMap( void );
   ~eCScriptFunctionMap( void );
};
GE_ASSERT_SIZEOF( eCScriptFunctionMap, 0x0040 )

#pragma warning( pop )

#endif
