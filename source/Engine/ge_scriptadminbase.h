#ifndef GE_SCRIPTADMINBASE_H_INCLUDED
#define GE_SCRIPTADMINBASE_H_INCLUDED

//NOTE: Cross module forwarding, but there seems to be no other way.
struct gSScript;
struct gSScriptDLL;

struct eSScriptBase
{
    GEU32                                    m_u32RegisterCounter;
    bTStringObjMap< eSScriptBase >::bSNode * m_pFunctionMapNode;
    bCString                                 m_strSource;
    gSScriptDLL *                            m_pScriptDLL;
    void *                                   m_funcFunction;  // gFScriptXxx
};
GE_ASSERT_SIZEOF( eSScriptBase, 0x0014 )

class GE_DLLIMPORT eCScriptAdminBase :
    public eCEngineComponentBase
{
public:    virtual      ~eCScriptAdminBase( void );                                        
protected: virtual GEInt CallScript( gSScript *, eCEntity *, eCEntity *, GEInt ) = 0;  
public:
    eCScriptAdminBase & operator = ( eCScriptAdminBase const & );
public:
    eCScriptAdminBase( eCScriptAdminBase const & );
    eCScriptAdminBase( void );
};
GE_ASSERT_SIZEOF( eCScriptAdminBase, 0x0010 )

#endif
