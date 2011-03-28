#ifndef GS_PSROUTINE_H_INCLUDED
#define GS_PSROUTINE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSRoutine )
public:
    GS_DECLARE_PROPERTY_TEMPLATE( PSRoutine )
    GS_DECLARE_PROPERTY( AIDelay,            GEI32 )
    GS_DECLARE_PROPERTY( AIMode,             gEAIMode )
    GS_DECLARE_PROPERTY( ActionString,       bCString )
    GS_DECLARE_PROPERTY( AmbientAction,      gEAmbientAction )
    GS_DECLARE_PROPERTY( CommandTime,        GEI32 )
    GS_DECLARE_PROPERTY( EndAttackTimestamp, GEFloat )
    GS_DECLARE_PROPERTY( HitDirection,       gEHitDirection )
    GS_DECLARE_PROPERTY( LastAIMode,         gEAIMode )
    GS_DECLARE_PROPERTY( LockAIInterrupt,    GEBool )
    GS_DECLARE_PROPERTY( LockAIResult,       GEBool )
    GS_DECLARE_PROPERTY( Routine,            eCScriptProxyScript )
    GS_DECLARE_PROPERTY( RoutineChanged,     GEBool )
    GS_DECLARE_PROPERTY( StatePosition,      GEI32 )
    GS_DECLARE_PROPERTY( TaskPosition,       GEI32 )
public:
    void       ContinueRoutine( void );
    void       FullStop( void );
    Entity     GetActionTarget( void ) const;
    gEAniState GetAniState( void ) const;
    bCString   GetCurrentRoutineTask( void ) const;
    bCString   GetCurrentState( void ) const;
    bCString   GetCurrentTask( void ) const;
    gEAniState GetFallbackAniState( void ) const;
    bCString   GetLastTask( void ) const;
    bCString   GetLocalCallback( void ) const;
    GEFloat    GetStateTime( void ) const;
    bCString   GetTaskCallback( void ) const;
    GEFloat    GetTaskTime( void ) const;
    GEBool     IsValid( void ) const;
    void       SetActionTarget( Entity & );
    void       SetAniState( gEAniState, gEAniState );
    void       SetLocalCallback( bCString );
    void       SetState( bCString );
    void       SetStateTime( GEFloat );
    void       SetTask( bCString );
    void       SetTaskCallback( bCString );
    void       SetTaskTime( GEFloat );
    void       StartOutput( bCString, gEOutputType );
    void       StopAICombatMove( void );
    void       StopAIGoto( GEBool );
    void       StopAIOutput( void );
    void       StopAIPlayAnimation( void );
    void       StopAIWait( void );
    void       StopOutput( void );
protected:
                         operator gCScriptRoutine_PS *       ( void );
                         operator gCScriptRoutine_PS const * ( void ) const;
    gCScriptRoutine_PS * operator ->                         ( void );
public:
    gCScriptRoutine_PS const * operator -> ( void ) const;
//FIXME: PSRoutine assignment operator shouldn’t be used (only one byte is copied).
//public: PSRoutine & operator = ( PSRoutine const & );
};

GS_DECLARE_PROPERTYSET_ACCESSOR( PSRoutine )

GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, AIDelay )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, AIMode )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, ActionString )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, AmbientAction )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, CommandTime )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, EndAttackTimestamp )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, HitDirection )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, LastAIMode )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, LockAIInterrupt )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, LockAIResult )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, Routine )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, RoutineChanged )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, StatePosition )
GS_DECLARE_PROPERTY_ACCESSOR( PSRoutine, TaskPosition )

#endif
