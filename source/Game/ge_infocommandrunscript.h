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
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCInfoCommandRunScript( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy &            GetEntityProxy2( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCScriptProxyScript                m_Script;
    bCString                           m_strSelf;
    bCString                           m_strOther;
    bTPropertyContainer< gEOtherType > m_enumOtherType;
    GEInt                              m_iParam;
    eCEntityProxy                      m_EntityProxy1;
    eCEntityProxy                      m_EntityProxy2;
    eCTemplateEntityProxy              m_TemplateEntityProxy;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                 AccessOther( void );
    bTPropertyContainer< gEOtherType > &       AccessOtherType( void );
    GEInt &                                    AccessParam( void );
    eCScriptProxyScript &                      AccessScript( void );
    bCString &                                 AccessSelf( void );
    bCString const &                           GetOther( void ) const;
    bTPropertyContainer< gEOtherType > const & GetOtherType( void ) const;
    GEInt const &                              GetParam( void ) const;
    eCScriptProxyScript const &                GetScript( void ) const;
    bCString const &                           GetSelf( void ) const;
    void                                       SetOther( bCString const & );
    void                                       SetOtherType( bTPropertyContainer< gEOtherType > const & );
    void                                       SetParam( GEInt const & );
    void                                       SetScript( eCScriptProxyScript const & );
    void                                       SetSelf( bCString const & );
public:
    gCInfoCommandRunScript & operator = ( gCInfoCommandRunScript const & );
public:
    gCInfoCommandRunScript( gCInfoCommandRunScript const & );
    gCInfoCommandRunScript( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunScript, 0x0038 )

#pragma warning( pop )

#endif
