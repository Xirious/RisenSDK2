#ifndef GE_CASTINFO_PS_H_INCLUDED
#define GE_CASTINFO_PS_H_INCLUDED

class GE_DLLIMPORT gCCastInfo_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCCastInfo_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCTemplateEntityProxy m_CastItem;
    eCTemplateEntityProxy m_CastAmmo;
    eCTemplateEntityProxy m_CastFail;
    GEBool                m_bConsumeItem;
                          GE_PADDING( 3 )
    GEI32                 m_i32ManaCost;
    bCString              m_strStartTask;
    bCString              m_strFocusMode;
    bCString              m_strCastInfo;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCTemplateEntityProxy &       AccessCastAmmo( void );
    eCTemplateEntityProxy &       AccessCastFail( void );
    bCString &                    AccessCastInfo( void );
    eCTemplateEntityProxy &       AccessCastItem( void );
    GEBool &                      AccessConsumeItem( void );
    bCString &                    AccessFocusMode( void );
    GEI32                         AccessManaCost( void );
    bCString &                    AccessStartTask( void );
    eCTemplateEntityProxy const & GetCastAmmo( void ) const;
    eCTemplateEntityProxy const & GetCastFail( void ) const;
    bCString const &              GetCastInfo( void ) const;
    eCTemplateEntityProxy const & GetCastItem( void ) const;
    GEBool const &                GetConsumeItem( void ) const;
    bCString const &              GetFocusMode( void ) const;
    GEI32 const &                 GetManaCost( void ) const;
    bCString const &              GetStartTask( void ) const;
    void                          SetCastAmmo( eCTemplateEntityProxy const & );
    void                          SetCastFail( eCTemplateEntityProxy const & );
    void                          SetCastInfo( bCString const & );
    void                          SetCastItem( eCTemplateEntityProxy const & );
    void                          SetConsumeItem( GEBool const & );
    void                          SetFocusMode( bCString const & );
    void                          SetManaCost( GEI32 const & );
    void                          SetStartTask( bCString const & );
public:
    gCCastInfo_PS & operator = ( gCCastInfo_PS const & );
public:
    gCCastInfo_PS( gCCastInfo_PS const & );
    gCCastInfo_PS( void );
};
GE_ASSERT_SIZEOF( gCCastInfo_PS, 0x0030 )

#endif
