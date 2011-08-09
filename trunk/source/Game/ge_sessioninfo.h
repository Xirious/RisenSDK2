#ifndef GE_SESSIONINFO_H_INCLUDED
#define GE_SESSIONINFO_H_INCLUDED

class GE_DLLIMPORT gCSessionInfo :
    public bCObjectRefBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCSessionInfo( void );
public: using                bCObjectBase::CopyFrom;
public: virtual void                       CopyFrom( gCSessionInfo const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString        m_strName;
    GEFloat         m_fNumHoursPlayed;
    GEBool          m_bPlayerHasCheated;
                    GE_PADDING( 3 )
    gCSessionCheats m_Cheats;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &              AccessName( void );
    GEFloat &               AccessNumHoursPlayed( void );
    GEBool &                AccessPlayerHasCheated( void );
    gCSessionCheats &       GetCheats( void );
    gCSessionCheats const & GetCheats( void ) const;
    bCString const &        GetName( void ) const;
    GEFloat const &         GetNumHoursPlayed( void ) const;
    GEBool const &          GetPlayerHasCheated( void ) const;
    void                    Invalidate( void );
    void                    Process( void );
    void                    SetName( bCString const & );
    void                    SetNumHoursPlayed( GEFloat const & );
    void                    SetPlayerHasCheated( GEBool const & );
public:
    gCSessionInfo & operator = ( gCSessionInfo const & );
public:
    gCSessionInfo( gCSessionInfo const & );
    gCSessionInfo( void );
};
GE_ASSERT_SIZEOF( gCSessionInfo, 0x0020 )

#endif
