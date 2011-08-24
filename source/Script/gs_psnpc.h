#ifndef GS_PSNPC_H_INCLUDED
#define GS_PSNPC_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSNpc, gCNPC_PS )
public:
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
};

#endif
