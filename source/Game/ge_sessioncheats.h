#ifndef GE_SESSIONCHEATS_H_INCLUDED
#define GE_SESSIONCHEATS_H_INCLUDED

class GE_DLLIMPORT gCSessionCheats :
    public bCObjectRefBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCSessionCheats( void );
public: using                bCObjectBase::CopyFrom;
public: virtual void                       CopyFrom( gCSessionCheats const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEBool m_bCheatGodEnabled;
    GEBool m_bCheatInvisibleEnabled;
           GE_PADDING( 2 )
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &       AccessCheatGodEnabled( void );
    GEBool &       AccessCheatInvisibleEnabled( void );
    GEBool const & GetCheatGodEnabled( void ) const;
    GEBool const & GetCheatInvisibleEnabled( void ) const;
    void           Invalidate( void );
    void           Process( void );
    void           SetCheatGodEnabled( GEBool const & );
    void           SetCheatInvisibleEnabled( GEBool const & );
public:
    gCSessionCheats & operator = ( gCSessionCheats const & );
public:
    gCSessionCheats( gCSessionCheats const & );
    gCSessionCheats( void );
};
GE_ASSERT_SIZEOF( gCSessionCheats, 0x000C )

#endif
