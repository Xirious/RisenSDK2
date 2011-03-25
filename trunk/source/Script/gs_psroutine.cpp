#include "../Script.h"

template<> PSRoutine &       Entity::PropertySet( void )       { return *reinterpret_cast< PSRoutine *       >( this ); }
template<> PSRoutine const & Entity::PropertySet( void ) const { return *reinterpret_cast< PSRoutine const * >( this ); }

template<> PSRoutine::PropertyAIDelay &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyAIDelay *       >( this ); }
template<> PSRoutine::PropertyAIDelay const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyAIDelay const * >( this ); }
template<> PSRoutine::PropertyAIMode &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyAIMode *       >( this ); }
template<> PSRoutine::PropertyAIMode const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyAIMode const * >( this ); }
template<> PSRoutine::PropertyActionString &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyActionString *       >( this ); }
template<> PSRoutine::PropertyActionString const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyActionString const * >( this ); }
template<> PSRoutine::PropertyAmbientAction &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyAmbientAction *       >( this ); }
template<> PSRoutine::PropertyAmbientAction const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyAmbientAction const * >( this ); }
template<> PSRoutine::PropertyCommandTime &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyCommandTime *       >( this ); }
template<> PSRoutine::PropertyCommandTime const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyCommandTime const * >( this ); }
template<> PSRoutine::PropertyEndAttackTimestamp &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyEndAttackTimestamp *       >( this ); }
template<> PSRoutine::PropertyEndAttackTimestamp const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyEndAttackTimestamp const * >( this ); }
template<> PSRoutine::PropertyHitDirection &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyHitDirection *       >( this ); }
template<> PSRoutine::PropertyHitDirection const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyHitDirection const * >( this ); }
template<> PSRoutine::PropertyLastAIMode &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyLastAIMode *       >( this ); }
template<> PSRoutine::PropertyLastAIMode const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyLastAIMode const * >( this ); }
template<> PSRoutine::PropertyLockAIInterrupt &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyLockAIInterrupt *       >( this ); }
template<> PSRoutine::PropertyLockAIInterrupt const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyLockAIInterrupt const * >( this ); }
template<> PSRoutine::PropertyLockAIResult &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyLockAIResult *       >( this ); }
template<> PSRoutine::PropertyLockAIResult const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyLockAIResult const * >( this ); }
template<> PSRoutine::PropertyRoutine &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyRoutine *       >( this ); }
template<> PSRoutine::PropertyRoutine const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyRoutine const * >( this ); }
template<> PSRoutine::PropertyRoutineChanged &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyRoutineChanged *       >( this ); }
template<> PSRoutine::PropertyRoutineChanged const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyRoutineChanged const * >( this ); }
template<> PSRoutine::PropertyStatePosition &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyStatePosition *       >( this ); }
template<> PSRoutine::PropertyStatePosition const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyStatePosition const * >( this ); }
template<> PSRoutine::PropertyTaskPosition &       PSRoutine::Property( void )       { return *reinterpret_cast< PSRoutine::PropertyTaskPosition *       >( this ); }
template<> PSRoutine::PropertyTaskPosition const & PSRoutine::Property( void ) const { return *reinterpret_cast< PSRoutine::PropertyTaskPosition const * >( this ); }

