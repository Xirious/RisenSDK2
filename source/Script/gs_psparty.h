#ifndef GS_PSPARTY_H_INCLUDED
#define GS_PSPARTY_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSParty, gCParty_PS )
public:
    GS_DECLARE_PROPERTY( AutoRejoin,      GEBool )
    GS_DECLARE_PROPERTY( PartyArea,       bCString )
    GS_DECLARE_PROPERTY( PartyMemberType, gEPartyMemberType )
    GS_DECLARE_PROPERTY( Waiting,         GEBool )
public:
    GEBool                   AddToParty( Entity );
    Entity                   GetPartyLeader( void ) const;
    bTValArray< eCEntity * > GetPartyMembers( GEBool ) const;
    bCString                 GetPartyName( void ) const;
    GEBool                   IsMemberOfParty( Entity ) const;
    GEBool                   IsValid( void ) const;
    GEBool                   RemoveFromParty( Entity );
    GEBool                   SetPartyLeader( Entity );
    GEBool                   SetPartyName( bCString );
};

#endif
