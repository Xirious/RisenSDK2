#ifndef GE_SCRIPTADMINBASE_H_INCLUDED
#define GE_SCRIPTADMINBASE_H_INCLUDED

struct eSScriptBase
{
    GEU32                                    m_u32RegisterCounter;
    bTStringObjMap< eSScriptBase >::bSNode * m_pFunctionMapNode;
    bCString                                 m_strSource;
    void *                                   m_pScriptDLL;    // gSScriptDLL *
    void *                                   m_funcFunction;  // gFScriptXxx
};
GE_ASSERT_SIZEOF( eSScriptBase, 0x0014 )

class GE_DLLIMPORT eCScriptAdminBase :
    public eCEngineComponentBase
{
protected: virtual GEInt                      CallScript( eSScriptBase *, eCEntity *, eCEntity *, GEInt ) = 0;  
public:    virtual                           ~eCScriptAdminBase( void );                                        
public:
    eCScriptAdminBase & operator = ( eCScriptAdminBase const & );
public:
    eCScriptAdminBase( eCScriptAdminBase const & );
    eCScriptAdminBase( void );
};
GE_ASSERT_SIZEOF( eCScriptAdminBase, 0x0010 )

#endif
