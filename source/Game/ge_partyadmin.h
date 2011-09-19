#ifndef GE_PARTYADMIN_H_INCLUDED
#define GE_PARTYADMIN_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCPartyAdmin'

class GE_DLLIMPORT gCPartyAdmin :
    public eCEngineComponentBase
{
GE_DECLARE_PROPERTY_OBJECT( gCPartyAdmin, eCEngineComponentBase )
public: virtual GEBool   IsValid( void ) const;
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual         ~gCPartyAdmin( void );
public: virtual bEResult Initialize( void );
public: virtual bEResult PostInitialize( void );
public: virtual bEResult Shutdown( void );
protected:
    bTValArray< gCParty * > m_arrParties;
public:
    bCString  GetNewPartyName( gCParty_PS const * );
    void      Invalidate( void );
    GEBool    IsPartyNameValid( bCString const & );
    gCParty * QueryParty( bCString const &, eCEntityProxy const & );
    gCParty * ReleaseParty( bCString const &, eCEntityProxy const & );
};
GE_ASSERT_SIZEOF( gCPartyAdmin, 0x001C )

#pragma warning( pop )

#endif
