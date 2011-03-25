#ifndef GS_PSROUTINE_H_INCLUDED
#define GS_PSROUTINE_H_INCLUDED

class GE_DLLIMPORT PSRoutine
{
public:
    class PropertyAIDelay
    {
    protected:
        eCEntity * m_pEntity;
    public:
                          operator GEI32 const ( void ) const;
        PropertyAIDelay & operator =           ( GEI32 const & );
        PropertyAIDelay & operator =           ( PropertyAIDelay const & );
    };
    class PropertyAIMode
    {
    protected:
        eCEntity * m_pEntity;
    public:
                         operator gEAIMode const ( void ) const;
        PropertyAIMode & operator =              ( gEAIMode const & );
        PropertyAIMode & operator =              ( PropertyAIMode const & );
    };
    class PropertyActionString
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator bCString const ( void ) const;
        PropertyActionString & operator =              ( bCString const & );
        PropertyActionString & operator =              ( PropertyActionString const & );
    };
    class PropertyAmbientAction
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                operator gEAmbientAction const ( void ) const;
        PropertyAmbientAction & operator =                     ( gEAmbientAction const & );
        PropertyAmbientAction & operator =                     ( PropertyAmbientAction const & );
    };
    class PropertyCommandTime
    {
    protected:
        eCEntity * m_pEntity;
    public:
                              operator GEI32 const ( void ) const;
        PropertyCommandTime & operator =           ( GEI32 const & );
        PropertyCommandTime & operator =           ( PropertyCommandTime const & );
    };
    class PropertyEndAttackTimestamp
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                     operator GEFloat const ( void ) const;
        PropertyEndAttackTimestamp & operator =             ( GEFloat const & );
        PropertyEndAttackTimestamp & operator =             ( PropertyEndAttackTimestamp const & );
    };
    class PropertyHitDirection
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator gEHitDirection const ( void ) const;
        PropertyHitDirection & operator =                    ( gEHitDirection const & );
        PropertyHitDirection & operator =                    ( PropertyHitDirection const & );
    };
    class PropertyLastAIMode
    {
    protected:
        eCEntity * m_pEntity;
    public:
                             operator gEAIMode const ( void ) const;
        PropertyLastAIMode & operator =              ( gEAIMode const & );
        PropertyLastAIMode & operator =              ( PropertyLastAIMode const & );
    };
    class PropertyLockAIInterrupt
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                  operator GEBool const ( void ) const;
        PropertyLockAIInterrupt & operator =            ( GEBool const & );
        PropertyLockAIInterrupt & operator =            ( PropertyLockAIInterrupt const & );
    };
    class PropertyLockAIResult
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator GEBool const ( void ) const;
        PropertyLockAIResult & operator =            ( GEBool const & );
        PropertyLockAIResult & operator =            ( PropertyLockAIResult const & );
    };
    class PropertyRoutine
    {
    protected:
        eCEntity * m_pEntity;
    public:
                          operator eCScriptProxyScript const ( void ) const;
        PropertyRoutine & operator =                         ( eCScriptProxyScript const & );
        PropertyRoutine & operator =                         ( PropertyRoutine const & );
    };
    class PropertyRoutineChanged
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                 operator GEBool const ( void ) const;
        PropertyRoutineChanged & operator =            ( GEBool const & );
        PropertyRoutineChanged & operator =            ( PropertyRoutineChanged const & );
    };
    class PropertyStatePosition
    {
    protected:
        eCEntity * m_pEntity;
    public:
                                operator GEI32 const ( void ) const;
        PropertyStatePosition & operator =           ( GEI32 const & );
        PropertyStatePosition & operator =           ( PropertyStatePosition const & );
    };
    class PropertyTaskPosition
    {
    protected:
        eCEntity * m_pEntity;
    public:
                               operator GEI32 const ( void ) const;
        PropertyTaskPosition & operator =           ( GEI32 const & );
        PropertyTaskPosition & operator =           ( PropertyTaskPosition const & );
    };
protected:
    eCEntity * m_pEntity;

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
public:
    template< typename PSRoutine_PropertyXxx > PSRoutine_PropertyXxx &       Property( void );
    template< typename PSRoutine_PropertyXxx > PSRoutine_PropertyXxx const & Property( void ) const;
};

template<> PSRoutine &       Entity::PropertySet( void );
template<> PSRoutine const & Entity::PropertySet( void ) const;
GE_ASSERT_SIZEOF( PSRoutine, sizeof(Entity) )

template<> PSRoutine::PropertyAIDelay &       PSRoutine::Property( void );
template<> PSRoutine::PropertyAIDelay const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyAIDelay, sizeof(PSRoutine) )
template<> PSRoutine::PropertyAIMode &       PSRoutine::Property( void );
template<> PSRoutine::PropertyAIMode const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyAIMode, sizeof(PSRoutine) )
template<> PSRoutine::PropertyActionString &       PSRoutine::Property( void );
template<> PSRoutine::PropertyActionString const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyActionString, sizeof(PSRoutine) )
template<> PSRoutine::PropertyAmbientAction &       PSRoutine::Property( void );
template<> PSRoutine::PropertyAmbientAction const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyAmbientAction, sizeof(PSRoutine) )
template<> PSRoutine::PropertyCommandTime &       PSRoutine::Property( void );
template<> PSRoutine::PropertyCommandTime const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyCommandTime, sizeof(PSRoutine) )
template<> PSRoutine::PropertyEndAttackTimestamp &       PSRoutine::Property( void );
template<> PSRoutine::PropertyEndAttackTimestamp const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyEndAttackTimestamp, sizeof(PSRoutine) )
template<> PSRoutine::PropertyHitDirection &       PSRoutine::Property( void );
template<> PSRoutine::PropertyHitDirection const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyHitDirection, sizeof(PSRoutine) )
template<> PSRoutine::PropertyLastAIMode &       PSRoutine::Property( void );
template<> PSRoutine::PropertyLastAIMode const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyLastAIMode, sizeof(PSRoutine) )
template<> PSRoutine::PropertyLockAIInterrupt &       PSRoutine::Property( void );
template<> PSRoutine::PropertyLockAIInterrupt const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyLockAIInterrupt, sizeof(PSRoutine) )
template<> PSRoutine::PropertyLockAIResult &       PSRoutine::Property( void );
template<> PSRoutine::PropertyLockAIResult const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyLockAIResult, sizeof(PSRoutine) )
template<> PSRoutine::PropertyRoutine &       PSRoutine::Property( void );
template<> PSRoutine::PropertyRoutine const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyRoutine, sizeof(PSRoutine) )
template<> PSRoutine::PropertyRoutineChanged &       PSRoutine::Property( void );
template<> PSRoutine::PropertyRoutineChanged const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyRoutineChanged, sizeof(PSRoutine) )
template<> PSRoutine::PropertyStatePosition &       PSRoutine::Property( void );
template<> PSRoutine::PropertyStatePosition const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyStatePosition, sizeof(PSRoutine) )
template<> PSRoutine::PropertyTaskPosition &       PSRoutine::Property( void );
template<> PSRoutine::PropertyTaskPosition const & PSRoutine::Property( void ) const;
GE_ASSERT_SIZEOF( PSRoutine::PropertyTaskPosition, sizeof(PSRoutine) )

#endif
