#ifndef GS_PSCHARACTERMOVEMENT_H_INCLUDED
#define GS_PSCHARACTERMOVEMENT_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSCharacterMovement, gCCharacterMovement_PS )
public:
    GS_DECLARE_PROPERTY( CanBePushedWhileIdle, GEBool )
    GS_DECLARE_PROPERTY( DisableRotation,      GEBool )
    GS_DECLARE_PROPERTY( DisableTranslation,   GEBool )
    GS_DECLARE_PROPERTY( ForceGroundAlignment, GEBool )
    GS_DECLARE_PROPERTY( LastFallVelocity,     GEFloat )
    GS_DECLARE_PROPERTY( StepHeight,           GEFloat )
public:
    GEBool             CanJump( void ) const;
    GEBool             CanStandAtPose( bCMatrix const &, GEBool, GEBool ) const;
    void               CreateDependantShapes( void );
    gEClimbMode        DetectClimbMode( gEDirection );
    gEJumpMode         DetectJumpMode( gEDirection );
    void               EnableControlByAnimation( GEBool );
    void               EnableGravitation( GEBool );
    GEBool             FindFloorAtPos( bCVector & ) const;
    bCVector           GetAlignmentLookAt( void ) const;
    GEFloat            GetAlignmentSpeed( void ) const;
    Entity             GetAlignmentTarget( void ) const;
    GEFloat            GetBrakingTime( void ) const;
    GEFloat            GetCeilingY( void ) const;
    GEBool             GetClimbBeginPlayed( void ) const;
    GEBool             GetClimbLoopPlayed( void ) const;
    GEBool             GetDistanceToGround( GEFloat & );
    GEFloat            GetFallDistance( void ) const;
    Entity             GetFloorEntity( void ) const;
    eEShapeMaterial    GetFloorMaterial( void ) const;
    GEFloat            GetFloorY( void ) const;
    Entity             GetGroundBias( void ) const;
    GEBool             GetLastCTRClimbEdgeDetected( void ) const;
    GEFloat            GetLastCTRClimbFlightDuration( void ) const;
    gEClimbMode        GetLastCTRClimbMode( void ) const;
    Entity             GetLastCTRClimbTargetEntity( void ) const;
    GEFloat            GetLastCTRClimbTargetGroundAngle( void ) const;
    bCVector           GetLastCTRClimbTargetNormal( void ) const;
    bCVector           GetLastCTRClimbTargetPoint( void ) const;
    GEFloat            GetLastJTRJumpFlightDuration( void ) const;
    gEJumpMode         GetLastJTRJumpMode( void ) const;
    gECharMovementMode GetLastMovementMode( void ) const;
    GEFloat            GetLevitationUpVeloPercentage( void ) const;
    gECharMovementMode GetMovementMode( void ) const;
    GEFloat            GetNearIdleTime( void ) const;
    GEFloat            GetSlideDistance( void ) const;
    GEBool             GetSlideStartedFrontally( void ) const;
    GEFloat            GetWaterY( void ) const;
    GEBool             HasAdditionalMovementVelo( void ) const;
    GEBool             HasMoved( void ) const;
    GEBool             HasReachedClimbFinalTarget( void ) const;
    GEBool             HasReachedClimbJumpTarget( void ) const;
    GEBool             HasReachedJumpEnd( void ) const;
    GEBool             HasReachedLevitationBounds( void ) const;
    GEBool             IsBraking( void ) const;
    GEBool             IsClimbing( void ) const;
    GEBool             IsControledByAnimation( void ) const;
    GEBool             IsDiving( void ) const;
    GEBool             IsFalling( void ) const;
    GEBool             IsGravitationEnabled( void ) const;
    GEBool             IsInMovingState( void ) const;
    GEBool             IsJumping( void ) const;
    GEBool             IsLevitating( void ) const;
    GEBool             IsRunning( void ) const;
    GEBool             IsSneaking( void ) const;
    GEBool             IsSprinting( void ) const;
    GEBool             IsStanding( void ) const;
    GEBool             IsSwimming( void ) const;
    GEBool             IsValid( void ) const;
    void               LiftUpToMinHeightAndMoveFwd( GEFloat, GEFloat, GEFloat, GEBool );
    void               PlaceOnGround( bCVector const &, GEBool );
    void               PutToGround( void );
    void               ResetFallDistance( void );
    void               ResetSlideDistance( void );
    void               SetAdditionalMovementVelo( bCVector const &, GEFloat, GEFloat, GEFloat );
    void               SetAlignmentLookAt( bCVector const & );
    void               SetAlignmentSpeed( GEFloat );
    void               SetAlignmentTarget( Entity const &, GEFloat );
    void               SetClimbBeginPlayed( GEBool );
    void               SetClimbLoopPlayed( GEBool );
    void               SetForcedAlignmentTarget( Entity const & );
    void               SetGoalPose( bCMatrix const & );
    void               SetGroundBias( Entity const & );
    void               SetGroundBias( GEFloat );
    void               SetMovementGoal( Entity const & );
    void               SetMovementGoal( bCMatrix const & );
    void               SetMovementGoal( bCVector const & );
    void               SetMovementMode( gECharMovementMode );
    void               StopMovement( void ) const;
};

#endif
