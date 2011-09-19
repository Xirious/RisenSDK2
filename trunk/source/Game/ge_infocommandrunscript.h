#ifndef GE_INFOCOMMANDRUNSCRIPT_H_INCLUDED
#define GE_INFOCOMMANDRUNSCRIPT_H_INCLUDED

enum gEOtherType
{
    gEOtherType_Entity         = 0x00000000,
    gEOtherType_TemplateEntity = 0x00000001,
    gEOtherType_ForceDWORD     = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable: 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandRunScript'

class GE_DLLIMPORT gCInfoCommandRunScript :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandRunScript, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual bEResult        PostInitializeProperties( void );
public: virtual                ~gCInfoCommandRunScript( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_Script,        Script )
    GE_DECLARE_PROPERTY( bCString,            m_strSelf,       Self )
    GE_DECLARE_PROPERTY( bCString,            m_strOther,      Other )
    GE_DECLARE_ENUMPROP( gEOtherType,         m_enumOtherType, OtherType )
    GE_DECLARE_PROPERTY( GEInt,               m_iParam,        Param )
    eCEntityProxy                             m_EntityProxy1;
    eCEntityProxy                             m_EntityProxy2;
    eCTemplateEntityProxy                     m_TemplateEntityProxy;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunScript, 0x0038 )

#pragma warning( pop )

#endif
