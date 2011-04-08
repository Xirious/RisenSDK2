#ifndef GE_INFOCOMMANDPLAYMUSIC_H_INCLUDED
#define GE_INFOCOMMANDPLAYMUSIC_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandPlayMusic :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandPlayMusic( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strSituation;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessSituation( void );
    bCString const & GetSituation( void ) const;
    void             SetSituation( bCString const & );
public:
    gCInfoCommandPlayMusic & operator = ( gCInfoCommandPlayMusic const & );
public:
    gCInfoCommandPlayMusic( gCInfoCommandPlayMusic const & );
    gCInfoCommandPlayMusic( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandPlayMusic, 0x000C )

#endif
