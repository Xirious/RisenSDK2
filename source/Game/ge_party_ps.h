#ifndef GE_PARTY_PS_H_INCLUDED
#define GE_PARTY_PS_H_INCLUDED

enum gEPartyMemberType
{
    gEPartyMemberType_None,
    gEPartyMemberType_Party,
    gEPartyMemberType_Mob,
    gEPartyMemberType_Slave,
    gEPartyMemberType_Controlled,
    gEPartyMemberType_Summoned,
    gEPartyMemberType_PlayerGuide,
    gEPartyMemberType_ForceDWORD = GE_FORCE_DWORD
};

//NOTE: gCParty is not exported.
class gCParty
{
public: virtual ~gCParty( void );
protected:
    bCString                    m_strName;
    bTObjArray< eCEntityProxy > m_arrMembers;
    GEInt                       m_iLeader;
};
GE_ASSERT_SIZEOF( gCParty, 0x0018 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCParty_PS'

class GE_DLLIMPORT gCParty_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCParty_PS, eCEntityPropertySet )
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
protected: virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       SetEntity( eCEntity * );
public:    virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_ENUMPROP( gEPartyMemberType, m_enumPartyMemberType, PartyMemberType )
    GE_DECLARE_PROPERTY( GEBool,            m_bWaiting,            Waiting )
    GE_DECLARE_PROPERTY( GEBool,            m_bAutoRejoin,         AutoRejoin )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( bCString,          m_strPartyArea,        PartyArea )
    gCParty *                               m_pParty;
public:
    GEBool                              AddToParty( eCEntityProxy const & );
    GEBool                              GetIsLeader( void ) const;
    bTObjArray< eCEntityProxy > const & GetMembers( void ) const;
    eCEntityProxy                       GetPartyLeaderEntity( void ) const;
    bCString                            GetPartyName( void ) const;
    void                                SetIsLeader( GEBool const & );
    void                                SetPartyLeaderEntity( eCEntityProxy const & );
    void                                SetPartyName( bCString const & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCParty_PS, 0x0024 )

#pragma warning( pop )

#endif
