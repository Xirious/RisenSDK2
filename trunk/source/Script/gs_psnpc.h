#ifndef GS_PSNPC_H_INCLUDED
#define GS_PSNPC_H_INCLUDED

#define PSNpcProperty( N, T )                               \
class Property##N :                                         \
    protected Entity                                        \
{                                                           \
public:                                                     \
                  operator T const ( void ) const;          \
    Property##N & operator =       ( T const & );           \
    Property##N & operator =       ( Property##N const & ); \
}

class GE_DLLIMPORT PSNpc :
    protected Entity
{
public:
    PSNpcProperty( AnimationBearing,       bCString );
    PSNpcProperty( AttitudeLock,           gEAttitude );
    PSNpcProperty( BraveryOverride,        gEBraveryOverride );
    PSNpcProperty( DamageCalculationType,  gEDamageCalculationType );
    PSNpcProperty( DefeatedByPlayer,       GEBool );
    PSNpcProperty( Discovered,             GEBool );
    PSNpcProperty( EffectMaterial,         bCString );
    PSNpcProperty( EffectSpecies,          bCString );
    PSNpcProperty( Gender,                 gEGender );
    PSNpcProperty( Group,                  bCString );
    PSNpcProperty( GuardStatus,            gEGuardStatus );
    PSNpcProperty( Guild,                  gEGuild );
    PSNpcProperty( LastCommentTimestamp,   GEFloat );
    PSNpcProperty( LastDistToGuardPoint,   GEFloat );
    PSNpcProperty( LastDistToTarget,       GEFloat );
    PSNpcProperty( LastFightAgainstPlayer, gEFight );
    PSNpcProperty( LastFightTimestamp,     GEFloat );
    PSNpcProperty( LastPlayerAR,           gEReason );
    PSNpcProperty( LastPlayerComment,      gEComment );
    PSNpcProperty( LastPlayerCrime,        gECrime );
    PSNpcProperty( LastReason,             gEReason );
    PSNpcProperty( PlayerWeaponTimestamp,  GEFloat );
    PSNpcProperty( Ransacked,              GEBool );
    PSNpcProperty( Reason,                 gEReason );
    PSNpcProperty( Species,                gESpecies );
    PSNpcProperty( Voice,                  bCString );
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
public:
    template< typename T >
    T & Property( void );
    template< typename T >
    T const & Property( void ) const;
};
GE_ASSERT_SIZEOF( PSNpc, 0x0004 )

#undef PSNpcProperty

#include "gs_psnpc.inl"

#endif
