#ifndef GE_INFOCONDITIONSCRIPT_H_INCLUDED
#define GE_INFOCONDITIONSCRIPT_H_INCLUDED

class GE_DLLIMPORT gCInfoConditionScript :
    public gCInfoCondition
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoConditionScript, gCInfoCondition )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoConditionScript( void );
public: virtual GEBool         IsSatisfied( gCInfo const & );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strScriptName, ScriptName )
    GE_DECLARE_PROPERTY( bCString, m_strSelf,       Self )
    GE_DECLARE_PROPERTY( bCString, m_strOther,      Other )
    GE_DECLARE_PROPERTY( GEInt,    m_iParam,        Param )
    eCEntityProxy                  m_EntityProxy1;
    eCEntityProxy                  m_EntityProxy2;
    eCScriptProxy                  m_ScriptProxy;
public:
    eCEntityProxy & GetEntityProxy1( gCInfo const & );
    eCEntityProxy & GetEntityProxy2( gCInfo const & );
    void            ResetProxies( void );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoConditionScript, 0x0030 )

#endif
