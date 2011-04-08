#ifndef GE_INFOCOMMANDRUNAISCRIPT_H_INCLUDED
#define GE_INFOCOMMANDRUNAISCRIPT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunAIScript :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandRunAIScript( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual gEInfoCommand              GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy &            GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy &            GetEntityProxy2( gCRuntimeInfo & );
public: virtual void                       ResetProxies( void );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString      m_strAIScriptName;
    bCString      m_strSelf;
    bCString      m_strOther;
    GEInt         m_iParam;
    eCEntityProxy m_EntityProxy1;
    eCEntityProxy m_EntityProxy2;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessAIScriptName( void );
    bCString &       AccessOther( void );
    GEInt &          AccessParam( void );
    bCString &       AccessSelf( void );
    bCString const & GetAIScriptName( void ) const;
    bCString const & GetOther( void ) const;
    GEInt const &    GetParam( void ) const;
    bCString const & GetSelf( void ) const;
    void             SetAIScriptName( bCString const & );
    void             SetOther( bCString const & );
    void             SetParam( GEInt const & );
    void             SetSelf( bCString const & );
public:
    gCInfoCommandRunAIScript & operator = ( gCInfoCommandRunAIScript const & );
public:
    gCInfoCommandRunAIScript( gCInfoCommandRunAIScript const & );
    gCInfoCommandRunAIScript( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunAIScript, 0x0028 )

#endif
