#include "../Script.h"

template<> PSNpc &       Entity::PropertySet( void )       { return *reinterpret_cast< PSNpc *       >( this ); }
template<> PSNpc const & Entity::PropertySet( void ) const { return *reinterpret_cast< PSNpc const * >( this ); }

template<> PSNpc::PropertyAttitudeLock &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyAttitudeLock *       >( this ); }
template<> PSNpc::PropertyAttitudeLock const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyAttitudeLock const * >( this ); }
template<> PSNpc::PropertyBraveryOverride &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyBraveryOverride *       >( this ); }
template<> PSNpc::PropertyBraveryOverride const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyBraveryOverride const * >( this ); }
template<> PSNpc::PropertyDamageCalculationType &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyDamageCalculationType *       >( this ); }
template<> PSNpc::PropertyDamageCalculationType const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyDamageCalculationType const * >( this ); }
template<> PSNpc::PropertyDefeatedByPlayer &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyDefeatedByPlayer *       >( this ); }
template<> PSNpc::PropertyDefeatedByPlayer const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyDefeatedByPlayer const * >( this ); }
template<> PSNpc::PropertyDiscovered &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyDiscovered *       >( this ); }
template<> PSNpc::PropertyDiscovered const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyDiscovered const * >( this ); }
template<> PSNpc::PropertyEffectMaterial &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyEffectMaterial *       >( this ); }
template<> PSNpc::PropertyEffectMaterial const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyEffectMaterial const * >( this ); }
template<> PSNpc::PropertyEffectSpecies &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyEffectSpecies *       >( this ); }
template<> PSNpc::PropertyEffectSpecies const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyEffectSpecies const * >( this ); }
template<> PSNpc::PropertyGender &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyGender *       >( this ); }
template<> PSNpc::PropertyGender const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyGender const * >( this ); }
template<> PSNpc::PropertyGroup &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyGroup *       >( this ); }
template<> PSNpc::PropertyGroup const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyGroup const * >( this ); }
template<> PSNpc::PropertyGuardStatus &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyGuardStatus *       >( this ); }
template<> PSNpc::PropertyGuardStatus const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyGuardStatus const * >( this ); }
template<> PSNpc::PropertyGuild &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyGuild *       >( this ); }
template<> PSNpc::PropertyGuild const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyGuild const * >( this ); }
template<> PSNpc::PropertyLastCommentTimestamp &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastCommentTimestamp *       >( this ); }
template<> PSNpc::PropertyLastCommentTimestamp const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastCommentTimestamp const * >( this ); }
template<> PSNpc::PropertyLastDistToGuardPoint &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastDistToGuardPoint *       >( this ); }
template<> PSNpc::PropertyLastDistToGuardPoint const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastDistToGuardPoint const * >( this ); }
template<> PSNpc::PropertyLastDistToTarget &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastDistToTarget *       >( this ); }
template<> PSNpc::PropertyLastDistToTarget const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastDistToTarget const * >( this ); }
template<> PSNpc::PropertyLastFightAgainstPlayer &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastFightAgainstPlayer *       >( this ); }
template<> PSNpc::PropertyLastFightAgainstPlayer const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastFightAgainstPlayer const * >( this ); }
template<> PSNpc::PropertyLastFightTimestamp &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastFightTimestamp *       >( this ); }
template<> PSNpc::PropertyLastFightTimestamp const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastFightTimestamp const * >( this ); }
template<> PSNpc::PropertyLastPlayerAR &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastPlayerAR *       >( this ); }
template<> PSNpc::PropertyLastPlayerAR const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastPlayerAR const * >( this ); }
template<> PSNpc::PropertyLastPlayerComment &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastPlayerComment *       >( this ); }
template<> PSNpc::PropertyLastPlayerComment const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastPlayerComment const * >( this ); }
template<> PSNpc::PropertyLastPlayerCrime &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastPlayerCrime *       >( this ); }
template<> PSNpc::PropertyLastPlayerCrime const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastPlayerCrime const * >( this ); }
template<> PSNpc::PropertyLastReason &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyLastReason *       >( this ); }
template<> PSNpc::PropertyLastReason const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyLastReason const * >( this ); }
template<> PSNpc::PropertyPlayerWeaponTimestamp &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyPlayerWeaponTimestamp *       >( this ); }
template<> PSNpc::PropertyPlayerWeaponTimestamp const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyPlayerWeaponTimestamp const * >( this ); }
template<> PSNpc::PropertyRansacked &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyRansacked *       >( this ); }
template<> PSNpc::PropertyRansacked const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyRansacked const * >( this ); }
template<> PSNpc::PropertyReason &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyReason *       >( this ); }
template<> PSNpc::PropertyReason const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyReason const * >( this ); }
template<> PSNpc::PropertySpecies &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertySpecies *       >( this ); }
template<> PSNpc::PropertySpecies const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertySpecies const * >( this ); }
template<> PSNpc::PropertyVoice &       PSNpc::Property( void )       { return *reinterpret_cast< PSNpc::PropertyVoice * >( this ); }
template<> PSNpc::PropertyVoice const & PSNpc::Property( void ) const { return *reinterpret_cast< PSNpc::PropertyVoice const * >( this ); }
