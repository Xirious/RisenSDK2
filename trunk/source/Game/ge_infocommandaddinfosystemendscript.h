#ifndef GE_INFOCOMMANDADDINFOSYSTEMENDSCRIPT_H_INCLUDED
#define GE_INFOCOMMANDADDINFOSYSTEMENDSCRIPT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAddInfoSystemEndScript :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCInfoCommandAddInfoSystemEndScript( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCScriptProxyScript m_Script;
    bCString            m_strSelf;
    bCString            m_strOther;
    GEInt               m_iParam;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                  AccessOther( void );
    GEInt &                     AccessParam( void );
    eCScriptProxyScript &       AccessScript( void );
    bCString &                  AccessSelf( void );
    bCString const &            GetOther( void ) const;
    GEInt const &               GetParam( void ) const;
    eCScriptProxyScript const & GetScript( void ) const;
    bCString const &            GetSelf( void ) const;
    void                        SetOther( bCString const & );
    void                        SetParam( GEInt const & );
    void                        SetScript( eCScriptProxyScript const & );
    void                        SetSelf( bCString const & );
public:
    gCInfoCommandAddInfoSystemEndScript & operator = ( gCInfoCommandAddInfoSystemEndScript const & );
public:
    gCInfoCommandAddInfoSystemEndScript( gCInfoCommandAddInfoSystemEndScript const & );
    gCInfoCommandAddInfoSystemEndScript( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAddInfoSystemEndScript, 0x001C )

#endif
