#ifndef GS_PSNPC_H_INCLUDED
#define GS_PSNPC_H_INCLUDED

class GE_DLLIMPORT PSNpc
{
public:
    class PropertyAnimationBearing
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                   operator bCString const ( void ) const;
        PropertyAnimationBearing & operator =              ( bCString const & );
        PropertyAnimationBearing & operator =              ( PropertyAnimationBearing const & );
    };
    class PropertyAttitudeLock
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator gEAttitude const ( void ) const;
        PropertyAttitudeLock & operator =                ( gEAttitude const & );
        PropertyAttitudeLock & operator =                ( PropertyAttitudeLock const & );
    };
    class PropertyBraveryOverride
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                  operator gEBraveryOverride const ( void ) const;
        PropertyBraveryOverride & operator =                       ( gEBraveryOverride const & );
        PropertyBraveryOverride & operator =                       ( PropertyBraveryOverride const & );
    };
    class PropertyDamageCalculationType
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                        operator gEDamageCalculationType const ( void ) const;
        PropertyDamageCalculationType & operator =                             ( gEDamageCalculationType const & );
        PropertyDamageCalculationType & operator =                             ( PropertyDamageCalculationType const & );
    };
    class PropertyDefeatedByPlayer
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                   operator GEBool const ( void ) const;
        PropertyDefeatedByPlayer & operator =            ( GEBool const & );
        PropertyDefeatedByPlayer & operator =            ( PropertyDefeatedByPlayer const & );
    };
    class PropertyDiscovered
    {
    protected:
        eCEntity * m_pEntity;
    public:
                             operator GEBool const ( void ) const;
        PropertyDiscovered & operator =            ( GEBool const & );
        PropertyDiscovered & operator =            ( PropertyDiscovered const & );
    };
    class PropertyEffectMaterial
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                 operator bCString const ( void ) const;
        PropertyEffectMaterial & operator =              ( bCString const & );
        PropertyEffectMaterial & operator =              ( PropertyEffectMaterial const & );
    };
    class PropertyEffectSpecies
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                operator bCString const ( void ) const;
        PropertyEffectSpecies & operator =              ( bCString const & );
        PropertyEffectSpecies & operator =              ( PropertyEffectSpecies const & );
    };
    class PropertyGender
    {
    protected:
        eCEntity * m_pEntity;
    public:
                         operator gEGender const ( void ) const;
        PropertyGender & operator =              ( gEGender const & );
        PropertyGender & operator =              ( PropertyGender const & );
    };
    class PropertyGroup
    {
    protected:
        eCEntity * m_pEntity;
    public:
                        operator bCString const ( void ) const;
        PropertyGroup & operator =              ( bCString const & );
        PropertyGroup & operator =              ( PropertyGroup const & );
    };
    class PropertyGuardStatus
    {
    protected:
        eCEntity * m_pEntity;
    public:
                              operator gEGuardStatus const ( void ) const;
        PropertyGuardStatus & operator =                   ( gEGuardStatus const & );
        PropertyGuardStatus & operator =                   ( PropertyGuardStatus const & );
    };
    class PropertyGuild
    {
    protected:
        eCEntity * m_pEntity;
    public:
                        operator gEGuild const ( void ) const;
        PropertyGuild & operator =             ( gEGuild const & );
        PropertyGuild & operator =             ( PropertyGuild const & );
    };
    class PropertyLastCommentTimestamp
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                       operator GEFloat const ( void ) const;
        PropertyLastCommentTimestamp & operator =             ( GEFloat const & );
        PropertyLastCommentTimestamp & operator =             ( PropertyLastCommentTimestamp const & );
    };
    class PropertyLastDistToGuardPoint
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                       operator GEFloat const ( void ) const;
        PropertyLastDistToGuardPoint & operator =             ( GEFloat const & );
        PropertyLastDistToGuardPoint & operator =             ( PropertyLastDistToGuardPoint const & );
    };
    class PropertyLastDistToTarget
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                   operator GEFloat const ( void ) const;
        PropertyLastDistToTarget & operator =             ( GEFloat const & );
        PropertyLastDistToTarget & operator =             ( PropertyLastDistToTarget const & );
    };
    class PropertyLastFightAgainstPlayer
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                         operator gEFight const ( void ) const;
        PropertyLastFightAgainstPlayer & operator =             ( gEFight const & );
        PropertyLastFightAgainstPlayer & operator =             ( PropertyLastFightAgainstPlayer const & );
    };
    class PropertyLastFightTimestamp
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                     operator GEFloat const ( void ) const;
        PropertyLastFightTimestamp & operator =             ( GEFloat const & );
        PropertyLastFightTimestamp & operator =             ( PropertyLastFightTimestamp const & );
    };
    class PropertyLastPlayerAR
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator gEReason const ( void ) const;
        PropertyLastPlayerAR & operator =              ( gEReason const & );
        PropertyLastPlayerAR & operator =              ( PropertyLastPlayerAR const & );
    };
    class PropertyLastPlayerComment
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                    operator gEComment const ( void ) const;
        PropertyLastPlayerComment & operator =               ( gEComment const & );
        PropertyLastPlayerComment & operator =               ( PropertyLastPlayerComment const & );
    };
    class PropertyLastPlayerCrime
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                  operator gECrime const ( void ) const;
        PropertyLastPlayerCrime & operator =             ( gECrime const & );
        PropertyLastPlayerCrime & operator =             ( PropertyLastPlayerCrime const & );
    };
    class PropertyLastReason
    {
    protected:
        eCEntity * m_pEntity;
    public:
                             operator gEReason const ( void ) const;
        PropertyLastReason & operator =              ( gEReason const & );
        PropertyLastReason & operator =              ( PropertyLastReason const & );
    };
    class PropertyPlayerWeaponTimestamp
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                        operator GEFloat const ( void ) const;
        PropertyPlayerWeaponTimestamp & operator =             ( GEFloat const & );
        PropertyPlayerWeaponTimestamp & operator =             ( PropertyPlayerWeaponTimestamp const & );
    };
    class PropertyRansacked
    {
    protected:
        eCEntity * m_pEntity;
    public:
                            operator GEBool const ( void ) const;
        PropertyRansacked & operator =            ( GEBool const & );
        PropertyRansacked & operator =            ( PropertyRansacked const & );
    };
    class PropertyReason
    {
    protected:
        eCEntity * m_pEntity;
    public:
                         operator gEReason const ( void ) const;
        PropertyReason & operator =              ( gEReason const & );
        PropertyReason & operator =              ( PropertyReason const & );
    };
    class PropertySpecies
    {
    protected:
        eCEntity * m_pEntity;
    public:
                          operator gESpecies const ( void ) const;
        PropertySpecies & operator =               ( gESpecies const & );
        PropertySpecies & operator =               ( PropertySpecies const & );
    };
    class PropertyVoice
    {
    protected:
        eCEntity * m_pEntity;
    public:
                        operator bCString const ( void ) const;
        PropertyVoice & operator =              ( bCString const & );
        PropertyVoice & operator =              ( PropertyVoice const & );
    };
protected:
    eCEntity * m_pEntity;
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
    template< typename PSNpc_PropertyXxx > PSNpc_PropertyXxx &       Property( void );
    template< typename PSNpc_PropertyXxx > PSNpc_PropertyXxx const & Property( void ) const;
};

template<> PSNpc &       Entity::PropertySet( void );
template<> PSNpc const & Entity::PropertySet( void ) const;
GE_ASSERT_SIZEOF( PSNpc, sizeof(Entity) )

template<> PSNpc::PropertyAttitudeLock &       PSNpc::Property( void );
template<> PSNpc::PropertyAttitudeLock const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyAttitudeLock, sizeof(PSNpc) )
template<> PSNpc::PropertyBraveryOverride &       PSNpc::Property( void );
template<> PSNpc::PropertyBraveryOverride const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyBraveryOverride, sizeof(PSNpc) )
template<> PSNpc::PropertyDamageCalculationType &       PSNpc::Property( void );
template<> PSNpc::PropertyDamageCalculationType const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyDamageCalculationType, sizeof(PSNpc) )
template<> PSNpc::PropertyDefeatedByPlayer &       PSNpc::Property( void );
template<> PSNpc::PropertyDefeatedByPlayer const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyDefeatedByPlayer, sizeof(PSNpc) )
template<> PSNpc::PropertyDiscovered &       PSNpc::Property( void );
template<> PSNpc::PropertyDiscovered const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyDiscovered, sizeof(PSNpc) )
template<> PSNpc::PropertyEffectMaterial &       PSNpc::Property( void );
template<> PSNpc::PropertyEffectMaterial const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyEffectMaterial, sizeof(PSNpc) )
template<> PSNpc::PropertyEffectSpecies &       PSNpc::Property( void );
template<> PSNpc::PropertyEffectSpecies const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyEffectSpecies, sizeof(PSNpc) )
template<> PSNpc::PropertyGender &       PSNpc::Property( void );
template<> PSNpc::PropertyGender const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyGender, sizeof(PSNpc) )
template<> PSNpc::PropertyGroup &       PSNpc::Property( void );
template<> PSNpc::PropertyGroup const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyGroup, sizeof(PSNpc) )
template<> PSNpc::PropertyGuardStatus &       PSNpc::Property( void );
template<> PSNpc::PropertyGuardStatus const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyGuardStatus, sizeof(PSNpc) )
template<> PSNpc::PropertyGuild &       PSNpc::Property( void );
template<> PSNpc::PropertyGuild const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyGuild, sizeof(PSNpc) )
template<> PSNpc::PropertyLastCommentTimestamp &       PSNpc::Property( void );
template<> PSNpc::PropertyLastCommentTimestamp const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastCommentTimestamp, sizeof(PSNpc) )
template<> PSNpc::PropertyLastDistToGuardPoint &       PSNpc::Property( void );
template<> PSNpc::PropertyLastDistToGuardPoint const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastDistToGuardPoint, sizeof(PSNpc) )
template<> PSNpc::PropertyLastDistToTarget &       PSNpc::Property( void );
template<> PSNpc::PropertyLastDistToTarget const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastDistToTarget, sizeof(PSNpc) )
template<> PSNpc::PropertyLastFightAgainstPlayer &       PSNpc::Property( void );
template<> PSNpc::PropertyLastFightAgainstPlayer const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastFightAgainstPlayer, sizeof(PSNpc) )
template<> PSNpc::PropertyLastFightTimestamp &       PSNpc::Property( void );
template<> PSNpc::PropertyLastFightTimestamp const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastFightTimestamp, sizeof(PSNpc) )
template<> PSNpc::PropertyLastPlayerAR &       PSNpc::Property( void );
template<> PSNpc::PropertyLastPlayerAR const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastPlayerAR, sizeof(PSNpc) )
template<> PSNpc::PropertyLastPlayerComment &       PSNpc::Property( void );
template<> PSNpc::PropertyLastPlayerComment const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastPlayerComment, sizeof(PSNpc) )
template<> PSNpc::PropertyLastPlayerCrime &       PSNpc::Property( void );
template<> PSNpc::PropertyLastPlayerCrime const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastPlayerCrime, sizeof(PSNpc) )
template<> PSNpc::PropertyLastReason &       PSNpc::Property( void );
template<> PSNpc::PropertyLastReason const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyLastReason, sizeof(PSNpc) )
template<> PSNpc::PropertyPlayerWeaponTimestamp &       PSNpc::Property( void );
template<> PSNpc::PropertyPlayerWeaponTimestamp const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyPlayerWeaponTimestamp, sizeof(PSNpc) )
template<> PSNpc::PropertyRansacked &       PSNpc::Property( void );
template<> PSNpc::PropertyRansacked const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyRansacked, sizeof(PSNpc) )
template<> PSNpc::PropertyReason &       PSNpc::Property( void );
template<> PSNpc::PropertyReason const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyReason, sizeof(PSNpc) )
template<> PSNpc::PropertySpecies &       PSNpc::Property( void );
template<> PSNpc::PropertySpecies const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertySpecies, sizeof(PSNpc) )
template<> PSNpc::PropertyVoice &       PSNpc::Property( void );
template<> PSNpc::PropertyVoice const & PSNpc::Property( void ) const;
GE_ASSERT_SIZEOF( PSNpc::PropertyVoice, sizeof(PSNpc) )

#include "gs_psnpc.inl"

#endif
