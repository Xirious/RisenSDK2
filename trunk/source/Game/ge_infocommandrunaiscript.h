#ifndef GE_INFOCOMMANDRUNAISCRIPT_H_INCLUDED
#define GE_INFOCOMMANDRUNAISCRIPT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunAIScript :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandRunAIScript, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strAIScriptName, AIScriptName )
    GE_DECLARE_PROPERTY( bCString, m_strSelf,         Self )
    GE_DECLARE_PROPERTY( bCString, m_strOther,        Other )
    GE_DECLARE_PROPERTY( GEInt,    m_iParam,          Param )
    eCEntityProxy                  m_EntityProxy1;
    eCEntityProxy                  m_EntityProxy2;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunAIScript, 0x0028 )

#endif
