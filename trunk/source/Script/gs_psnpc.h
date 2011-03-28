#ifndef GS_PSNPC_H_INCLUDED
#define GS_PSNPC_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSNpc )
public:
    GS_DECLARE_PROPERTY_TEMPLATE( PSNpc )
    GS_DECLARE_PROPERTY( AnimationBearing,       bCString )
    GS_DECLARE_PROPERTY( AttitudeLock,           gEAttitude )
    GS_DECLARE_PROPERTY( BraveryOverride,        gEBraveryOverride )
    GS_DECLARE_PROPERTY( DamageCalculationType,  gEDamageCalculationType )
    GS_DECLARE_PROPERTY( DefeatedByPlayer,       GEBool )
    GS_DECLARE_PROPERTY( Discovered,             GEBool )
    GS_DECLARE_PROPERTY( EffectMaterial,         bCString )
    GS_DECLARE_PROPERTY( EffectSpecies,          bCString )
    GS_DECLARE_PROPERTY( Gender,                 gEGender )
    GS_DECLARE_PROPERTY( Group,                  bCString )
    GS_DECLARE_PROPERTY( GuardStatus,            gEGuardStatus )
    GS_DECLARE_PROPERTY( Guild,                  gEGuild )
    GS_DECLARE_PROPERTY( LastCommentTimestamp,   GEFloat )
    GS_DECLARE_PROPERTY( LastDistToGuardPoint,   GEFloat )
    GS_DECLARE_PROPERTY( LastDistToTarget,       GEFloat )
    GS_DECLARE_PROPERTY( LastFightAgainstPlayer, gEFight )
    GS_DECLARE_PROPERTY( LastFightTimestamp,     GEFloat )
    GS_DECLARE_PROPERTY( LastPlayerAR,           gEReason )
    GS_DECLARE_PROPERTY( LastPlayerComment,      gEComment )
    GS_DECLARE_PROPERTY( LastPlayerCrime,        gECrime )
    GS_DECLARE_PROPERTY( LastReason,             gEReason )
    GS_DECLARE_PROPERTY( PlayerWeaponTimestamp,  GEFloat )
    GS_DECLARE_PROPERTY( Ransacked,              GEBool )
    GS_DECLARE_PROPERTY( Reason,                 gEReason )
    GS_DECLARE_PROPERTY( Species,                gESpecies )
    GS_DECLARE_PROPERTY( Voice,                  bCString )
public:
    GEBool            BeginStatusEffect( gSNPCStatusEffect & );
    void              ClearMnemonic( void );
    GEBool            EndStatusEffect( gEStatusEffect );
    Entity            GetCurrentAttacker( void ) const;
    bCString          GetCurrentMovementAni( void ) const;
    Entity            GetCurrentTarget( void ) const;
    Entity            GetGuardPoint( void ) const;
    Entity            GetLastAttacker( void ) const;
    gSNPCStatusEffect GetStatusEffect( gEStatusEffect ) const;
    GEU32             GetStatusEffectDuration( gEStatusEffect ) const;
    bCString          GetStatusEffectName( gEStatusEffect ) const;
    GEU32             GetStatusEffectTime( gEStatusEffect ) const;
    GEU32             GetStatusEffectUserData( gEStatusEffect ) const;
    GEBool            HasStatusEffects( gEStatusEffect ) const;
    GEBool            IsBurning( void ) const;
    GEBool            IsFrozen( void ) const;
    GEBool            IsPoisoned( void ) const;
    GEBool            IsValid( void ) const;
    void              SetCurrentAttacker( Entity const & );
    void              SetCurrentTarget( Entity const & );
    GEBool            SetGuardPoint( Entity const & ) const;
    void              SetLastAttacker( Entity const & );
    void              SetStatusEffectDuration( gEStatusEffect, GEU32 );
    void              SetStatusEffectName( gEStatusEffect, bCString );
    void              SetStatusEffectTime( gEStatusEffect, GEU32 );
    void              SetStatusEffectUserData( gEStatusEffect, GEU32 );
public:
    gCNPC_PS const * operator -> ( void ) const;
protected:
               operator gCNPC_PS *       ( void );
               operator gCNPC_PS const * ( void ) const;
    gCNPC_PS * operator ->               ( void );
//FIXME: PSNpc assignment operator shouldn’t be used (only one byte is copied).
//public: PSNpc & operator = ( PSNpc const & );
};

GS_DECLARE_PROPERTYSET_ACCESSOR( PSNpc )

GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, AttitudeLock )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, BraveryOverride )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, DamageCalculationType )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, DefeatedByPlayer )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Discovered )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, EffectMaterial )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, EffectSpecies )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Gender )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Group )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, GuardStatus )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Guild )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastCommentTimestamp )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastDistToGuardPoint )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastDistToTarget )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastFightAgainstPlayer )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastFightTimestamp )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastPlayerAR )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastPlayerComment )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastPlayerCrime )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, LastReason )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, PlayerWeaponTimestamp )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Ransacked )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Reason )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Species )
GS_DECLARE_PROPERTY_ACCESSOR( PSNpc, Voice )

#endif
