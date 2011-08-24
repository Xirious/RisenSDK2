#ifndef GE_CHARACTERMOVEMENT_PS_H_INCLUDED
#define GE_CHARACTERMOVEMENT_PS_H_INCLUDED

enum gECharMovementMode
{
    //FIXME: gECharMovementMode constants.
    gECharMovementMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEClimbMode
{
    //FIXME: gEClimbMode constants.
    gEClimbMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEDirection
{
    //FIXME: gEDirection constants.
    gEDirection_ForceDWORD = GE_FORCE_DWORD
};

enum gEJumpMode
{
    //FIXME: gEJumpMode constants.
    gEJumpMode_ForceDWORD = GE_FORCE_DWORD
};

struct gSSpatialState
{
    //FIXME: gSSpatialState members.
};

class GE_DLLIMPORT gCCharacterMovement_PS :
    public eCEntityPropertySet
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCCharacterMovement_PS * m_pCharacterMovementPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:
    struct gSClimbTestReport
    {
        //FIXME: gCCharacterMovement_PS::gSClimbTestReport members
    };
    struct gSJumpTestReport
    {
        //FIXME: gCCharacterMovement_PS::gSJumpTestReport members
    };
    class gCMovementWayDescription
    {
        //FIXME: gCCharacterMovement_PS::gCMovementWayDescription members
    };
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
protected: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                           ~gCCharacterMovement_PS( void );
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;
public:    virtual GEBool                     IsEditorRelevant( void ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual void                       OnTouch( eCEntity *, eCContactIterator & );
public:    virtual void                       OnIntersect( eCEntity *, eCContactIterator & );
public:    virtual void                       OnUntouch( eCEntity *, eCContactIterator & );
public:    virtual GEBool                     IsClassProcessible( void ) const;
public:    virtual GEBool                     IsClassProcessingEnabled( void ) const;
public:    virtual void                       EnableClassProcessing( GEBool );
public:    virtual void                       EnterProcessingRange( void );
public:    virtual void                       ExitProcessingRange( void );
protected: virtual void                       OnEnterProcessingRange( void );
protected: virtual void                       OnExitProcessingRange( void );
public:    virtual void                       OnRenderDebug( void );
protected: virtual void                       OnProcess( void );
protected: virtual void                       OnPostRead( void );
protected: virtual void                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected: virtual void                       OnPrefetch( bCVector const & );
public:    virtual GEInt                      OnAction( gSAction const & );
private:
    static bCPropertyObjectTypeBase thisType;
public:
    static GEBool ms_bHeightCorr;
protected:
    char __FIXME[ 0x0554 - sizeof(eCEntityPropertySet) ];
protected:
    void    AddToCurrentVelocity( bCVector const &, GEBool );
    void    CalcAniVelocity( void );
    void    CalcDistToGoal( GEBool );
    void    CalcGroundSlopeTransScale( void );
    void    CalcNewRotationAngleAndVelocity( bCVector const &, bCVector const &, GEFloat, GEFloat &, GEFloat &, GEBool );
    void    CalcNextSteps( void );
    void    CalcQuadrupedDistances( void );
    void    ClearVolatileFrameStates( void );
    void    ContributeFloorActions( void );
    void    ContributeFloorMovements( void );
    GEBool  CorrectGoalMiss( void );
    void    CreateDependantPSets( void );
    void    GameReset( void );
    GEFloat GetPositionXOffsetOfCurrentAni( void );
    GEFloat GetPositionYOffsetOfCurrentAni( void );
    GEFloat GetPositionZOffsetOfCurrentAni( void );
    void    InitFirstPose( void );
    void    Invalidate( void );
    GEBool  NeedsComplexStaticCollisionTests( bTPtrArray< gCCharacterMovement_PS * > * );
    void    OnFloorMaterialChanged( eEShapeMaterial );
    void    OnGoalChanged( GEBool );
    void    OnMovementModeChanged( void );
    void    ProcessAdditionalMovementVelo( void );
    void    ProcessAnimationMovements( void );
    void    ProcessClimbHigh( void );
    void    ProcessClimbStandard( void );
    void    ProcessControledMovements( void );
    void    ProcessControledRotation( void );
    void    ProcessControledRotationLookAt( bCVector & );
    void    ProcessControledRotationToTarget( void );
    void    ProcessControledTranslation( void );
    void    ProcessFreeNavigationJump( void );
    void    ProcessMovementAnimation( void );
    void    ProcessMovements( void );
    void    ProcessPhysicsMovements( void );
    void    ProcessQuadrupedXRotation( bCQuaternion &, GEBool );
    void    SaveFrameStates( void );
    void    SetAniStopTime( GEFloat );
    void    SetCurrentPosition( bCVector const &, GEBool, GEBool );
    void    SetCurrentVelocity( bCVector const & );
    GEBool  SetEffectsByMode( gECharMovementMode );
    GEBool  SetFlagsByMode( gECharMovementMode );
    GEBool  SetShapeByMode( gECharMovementMode );
    GEBool  SetSpeedByMode( gECharMovementMode );
    void    ShowDebug( void );
    GEBool  TestClimbMode( gEClimbMode, GEFloat, gEDirection, GEBool );
    void    ValidateZoneGeometry( void ) const;
public:
    static bCObjectBase *               GE_STDCALL CreateObject( void );
    static bTValArray< eEShapeGroup > * GE_STDCALL GetSweepTestGroups( void );
    static bCPropertyObjectTypeBase &   GE_STDCALL GetThisType( void );
    static GEBool                       GE_STDCALL S_GetHeightCorr( void );
    static void                         GE_STDCALL S_SetHeightCorr( GEBool );
    static void                         GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                      AccessApplyGravity( void );
    GEFloat &                     AccessBackwardSpeedMax( void );
    GEBool &                      AccessCanBePushedWhileIdle( void );
    GEFloat &                     AccessClimbFlightForwardTime( void );
    GEFloat &                     AccessClimbFlightGravity( void );
    GEFloat &                     AccessClimbFrontDepth1( void );
    GEFloat &                     AccessClimbFrontDepth2( void );
    GEFloat &                     AccessClimbFrontDepth3( void );
    GEFloat &                     AccessClimbHeightHigh( void );
    GEFloat &                     AccessClimbHeightLow( void );
    GEFloat &                     AccessClimbHeightMid( void );
    GEFloat &                     AccessClimbHeightMin( void );
    GEFloat &                     AccessClimbTargetGroundAngleMax( void );
    GEBool &                      AccessDisableRotation( void );
    GEBool &                      AccessDisableTranslation( void );
    GEBool &                      AccessDoHeightCorrection( void );
    GEFloat &                     AccessDontStopFallAngleMin( void );
    GEFloat &                     AccessFallDownMinGroundDist( void );
    GEFloat &                     AccessFallSteerScaleFactor( void );
    GEFloat &                     AccessFallVelocity( void );
    GEFloat &                     AccessFallXZDecceleration( void );
    GEFloat &                     AccessFallXZDeccelerationWarmUpTime( void );
    GEFloat &                     AccessFastModifier( void );
    GEBool &                      AccessForceGroundAlignment( void );
    GEFloat &                     AccessForwardSpeedMax( void );
    GEFloat &                     AccessGroundSlopeTransInertia( void );
    GEBool &                      AccessIsQuadruped( void );
    GEFloat &                     AccessJumpFlightGravity( void );
    GEFloat &                     AccessJumpFrontSpeedFactor( void );
    GEFloat &                     AccessJumpHeight( void );
    GEFloat &                     AccessJumpRotationCtrlFactor( void );
    GEFloat &                     AccessJumpTranslationCtrlFactor( void );
    gSClimbTestReport *           AccessLastClimbTestReport( void );
    GEFloat &                     AccessLastFallVelocity( void );
    GEFloat &                     AccessLevitationFallVelo( void );
    GEFloat &                     AccessLevitationMaxUpwardMove( void );
    GEFloat &                     AccessLevitationModifier( void );
    GEFloat &                     AccessLevitationUpVelo( void );
    GEFloat &                     AccessMoveAcceleration( void );
    GEFloat &                     AccessMoveDecceleration( void );
    GEFloat &                     AccessQuadrupedSlopeInertia( void );
    GEFloat &                     AccessSensorAdvanceDuration( void );
    GEBool &                      AccessSensorAffectsDirection( void );
    GEFloat &                     AccessSensorInertia( void );
    GEFloat &                     AccessSensorMinSlideAngle( void );
    bCVector &                    AccessSensorPosition( void );
    GEFloat &                     AccessSlideSpeed( void );
    GEFloat &                     AccessSlowModifier( void );
    GEFloat &                     AccessSneakModifier( void );
    GEFloat &                     AccessSteepGroundAngleMax( void );
    GEFloat &                     AccessSteepGroundAngleMin( void );
    GEFloat &                     AccessStepHeight( void );
    GEFloat &                     AccessStrafeSpeedMax( void );
    GEBool &                      AccessTreatWaterAsSolid( void );
    GEFloat &                     AccessTurnAcceleration( void );
    GEFloat &                     AccessTurnDecceleration( void );
    GEFloat &                     AccessTurnSpeedMax( void );
    GEFloat &                     AccessTurnSpeedModifier( void );
    GEFloat &                     AccessWalkDownSpeedScale( void );
    GEFloat &                     AccessWaterDeathDepth( void );
    GEFloat &                     AccessWaterWadeDepth( void );
    void                          ActivateFreeNavigationJump( bTValArray< bCMotion > const & );
    GEBool                        CanBeHeightCorrected( GEFloat ) const;
    GEBool                        CanFallDown( void ) const;
    GEBool                        CanJump( void ) const;
    GEBool                        CanSensorCorrectDirection( void ) const;
    GEBool                        CanSlide( void ) const;
    GEBool                        CanStandAtGoal( bCMotion const &, GEBool, GEBool, GEBool ) const;
    GEBool                        CanWalkOnFloor( bCVector const & ) const;
    GEBool                        CanWalkToGoal( bCMotion const &, eCGeometryEntity *, gCMovementWayDescription &, GEBool );
    void                          CheckChangedMovementStates( void );
    void                          CheckCharacterGotStuck( void );
    GEBool                        CheckSlideSpace( bCVector const & ) const;
    void                          CreateDependantShapes( void );
    GEBool                        CreateSweepTestCapsule( bCCapsule &, bCVector const &, GEFloat ) const;
    gEClimbMode                   DetectClimbMode( gEDirection );
    gEJumpMode                    DetectJumpMode( gEDirection );
    void                          EnableCombatMovementFromSPU( GEBool, eCEntityProxy const &, bCVector & );
    void                          EnableCombatRotationFromSPU( GEBool, bCVector & );
    void                          EnableControlByAnimation( GEBool );
    void                          EnableGravitation( GEBool );
    void                          EnableMovementFromSPU( GEBool );
    void                          EnableRotationFromSPU( GEBool );
    void                          EnableRotationFromSPU( GEBool, bCVector2 const & );
    GEBool                        FindFloorWaterCeiling( bCVector const &, gSSpatialState &, GEBool, GEBool ) const;
    bCVector &                    GetAlignmentLookAt( void );
    bCVector const &              GetAlignmentLookAt( void ) const;
    GEFloat                       GetAlignmentSpeed( void ) const;
    eCEntity *                    GetAlignmentTarget( void );
    eCEntity const *              GetAlignmentTarget( void ) const;
    GEBool const &                GetApplyGravity( void ) const;
    GEFloat const &               GetBackwardSpeedMax( void ) const;
    GEFloat                       GetBrakingDistance( void ) const;
    GEFloat                       GetBrakingTime( void ) const;
    GEBool const &                GetCanBePushedWhileIdle( void ) const;
    GEFloat const &               GetClimbFlightForwardTime( void ) const;
    GEFloat const &               GetClimbFlightGravity( void ) const;
    GEFloat const &               GetClimbFrontDepth1( void ) const;
    GEFloat const &               GetClimbFrontDepth2( void ) const;
    GEFloat const &               GetClimbFrontDepth3( void ) const;
    GEFloat const &               GetClimbHeightHigh( void ) const;
    GEFloat const &               GetClimbHeightLow( void ) const;
    GEFloat const &               GetClimbHeightMid( void ) const;
    GEFloat const &               GetClimbHeightMin( void ) const;
    GEFloat const &               GetClimbTargetGroundAngleMax( void ) const;
    GEBool                        GetCombatContact( void ) const;
    bCVector                      GetCurGoalPosition( void ) const;
    GEFloat                       GetCurrentMaxSpeedOfDir( bCVector const & ) const;
    bCVector                      GetCurrentPosition( void ) const;
    GEFloat                       GetCurrentSpeedModifier( void ) const;
    GEFloat                       GetCurrentVelocity( void ) const;
    bCVector                      GetCurrentWayDirection( void );
    GEBool                        GetDebugMode( void );
    GEBool const &                GetDisableRotation( void ) const;
    GEBool const &                GetDisableTranslation( void ) const;
    GEFloat                       GetDistToCeiling( bCVector const &, GEBool ) const;
    GEBool                        GetDistToGround( bCVector const &, GEFloat &, GEBool ) const;
    GEBool const &                GetDoHeightCorrection( void ) const;
    GEFloat const &               GetDontStopFallAngleMin( void ) const;
    GEFloat                       GetFallDistance( void );
    GEFloat const &               GetFallDownMinGroundDist( void ) const;
    GEFloat const &               GetFallSteerScaleFactor( void ) const;
    GEFloat const &               GetFallVelocity( void ) const;
    GEFloat const &               GetFallXZDecceleration( void ) const;
    GEFloat const &               GetFallXZDeccelerationWarmUpTime( void ) const;
    GEFloat const &               GetFastModifier( void ) const;
    GEBool const &                GetForceGroundAlignment( void ) const;
    GEFloat const &               GetForwardSpeedMax( void ) const;
    GEBool                        GetGoalChanged( void ) const;
    eCEntity *                    GetGoalGroundEntity( void ) const;
    GEFloat                       GetGoalGroundOffset( void ) const;
    bCVector                      GetGoalPosition( void ) const;
    GEBool                        GetGoalReached( GEBool, GEBool, GEBool );
    GEFloat const &               GetGroundSlopeTransInertia( void ) const;
    GEFloat                       GetGroundSlopeTransScale( void ) const;
    GEFloat                       GetHalfSpeedTimer( void );
    GEBool                        GetIsProcessing( void );
    GEBool const &                GetIsQuadruped( void ) const;
    GEFloat const &               GetJumpFlightGravity( void ) const;
    GEFloat const &               GetJumpFrontSpeedFactor( void ) const;
    GEFloat const &               GetJumpHeight( void ) const;
    GEFloat const &               GetJumpRotationCtrlFactor( void ) const;
    GEFloat const &               GetJumpTranslationCtrlFactor( void ) const;
    gSClimbTestReport const &     GetLastClimbTestReport( void ) const;
    GEFloat const &               GetLastFallVelocity( void ) const;
    gSJumpTestReport *            GetLastJumpTestReport( void );
    gECharMovementMode            GetLastMovementMode( void ) const;
    bCVector const &              GetLatestGoalPosition( void ) const;
    bCQuaternion const &          GetLatestGoalRotation( void ) const;
    GEFloat const &               GetLevitationFallVelo( void ) const;
    GEFloat const &               GetLevitationMaxUpwardMove( void ) const;
    GEFloat const &               GetLevitationModifier( void ) const;
    GEFloat const &               GetLevitationUpVelo( void ) const;
    GEFloat                       GetLevitationUpVeloPercentage( void ) const;
    bCVector                      GetLocalAniVelocity( void ) const;
    bCVector                      GetLocalVelocity( void ) const;
    GEFloat const &               GetMoveAcceleration( void ) const;
    GEFloat const &               GetMoveDecceleration( void ) const;
    GEBool                        GetMovementIsControledByNavigation( void ) const;
    GEBool                        GetMovementIsControledByPlayer( void ) const;
    GEBool                        GetMovementIsSelfControled( void ) const;
    GEBool                        GetMovementIsStatic( void ) const;
    gECharMovementMode            GetMovementMode( void ) const;
    gECharMovementMode            GetMovementModeAtPosition( bCVector const &, gSSpatialState * );
    GEBool                        GetMovementModeIsStatic( void ) const;
    eCCollisionShape const *      GetMovementShape( void ) const;
    GEFloat                       GetNearIdleTime( void ) const;
    GEFloat                       GetPredictedDistanceByTime( GEFloat, bCVector * );
    GEFloat const &               GetQuadrupedSlopeInertia( void ) const;
    bCVector                      GetRigidBodyVelocity( void ) const;
    gCCharacterSensor *           GetSensor( void ) const;
    GEFloat const &               GetSensorAdvanceDuration( void ) const;
    GEBool const &                GetSensorAffectsDirection( void ) const;
    GEFloat const &               GetSensorInertia( void ) const;
    GEFloat const &               GetSensorMinSlideAngle( void ) const;
    GEFloat                       GetSlideDistance( void );
    GEFloat const &               GetSlideSpeed( void ) const;
    GEBool                        GetSlideStartedFrontally( void ) const;
    GEFloat const &               GetSlowModifier( void ) const;
    GEFloat const &               GetSneakModifier( void ) const;
    gSSpatialState &              GetSpatialState( void );
    gSSpatialState const &        GetSpatialState( void ) const;
    GEFloat                       GetSpeedByMode( gECharMovementMode );
    GEFloat const &               GetSteepGroundAngleMax( void ) const;
    GEFloat const &               GetSteepGroundAngleMin( void ) const;
    GEFloat const &               GetStepHeight( void ) const;
    GEFloat const &               GetStrafeSpeedMax( void ) const;
    GEBool const &                GetTreatWaterAsSolid( void ) const;
    GEFloat const &               GetTurnAcceleration( void ) const;
    GEFloat const &               GetTurnDecceleration( void ) const;
    GEFloat const &               GetTurnSpeedMax( void ) const;
    GEFloat const &               GetTurnSpeedModifier( void ) const;
    GEFloat const &               GetWalkDownSpeedScale( void ) const;
    GEFloat const &               GetWaterDeathDepth( void ) const;
    GEFloat                       GetWaterDepth( void ) const;
    GEFloat const &               GetWaterWadeDepth( void ) const;
    GEBool                        HasAdditionalMovementVelo( void ) const;
    GEBool                        HasMoved( GEFloat ) const;
    GEBool                        HasReachedClimbFinalTarget( void );
    GEBool                        HasReachedClimbJumpTarget( void );
    GEBool                        HasReachedJumpEnd( void );
    GEBool                        HasReachedLevitationBounds( void ) const;
    GEBool                        IsBraking( void ) const;
    GEBool                        IsClimbing( void ) const;
    GEBool                        IsCombatMovementEnabledFromSPU( void ) const;
    GEBool                        IsCombatRotationEnabledFromSPU( void ) const;
    GEBool                        IsControledByAnimation( void ) const;
    GEBool                        IsDiving( void ) const;
    GEBool                        IsFalling( void ) const;
    GEBool                        IsFloorFixed( void );
    GEBool                        IsFreeLOSAndSurrounding( eCEntity *, GEBool );
    GEBool                        IsFreeLOSAndSurrounding( bCVector, bCVector, GEBool, eCEntity * );
    GEBool                        IsGravitationEnabled( void ) const;
    GEBool                        IsInFreeNavigationJump( void ) const;
    GEBool                        IsInMovingState( void ) const;
    GEBool                        IsJumping( void ) const;
    GEBool                        IsLevitating( void ) const;
    GEBool                        IsMounted( void ) const;
    GEBool                        IsMovementEnabledFromSPU( void );
    GEBool                        IsRotationEnabledFromSPU( void );
    GEBool                        IsRunning( void ) const;
    GEBool                        IsSneaking( void ) const;
    GEBool                        IsSprinting( void ) const;
    GEBool                        IsStanding( void ) const;
    GEBool                        IsSwimming( void ) const;
    GEBool                        IsWalking( void ) const;
    void                          LiftUpToMinHeightAndMoveFwd( GEFloat, GEFloat, GEFloat, GEBool );
    void                          MarkSpatialStateAsUninited( GEBool );
    GEBool                        NextStepCanSlideBack( bCVector const &, bCVector const & ) const;
    void                          ProcessSensorMovements( void );
    GEFloat                       PutToGround( GEBool, GEBool );
    void                          ResetFallDistance( void );
    void                          ResetIsProcessing( void );
    void                          ResetSlideDistance( void );
    void                          SetAdditionalMovementVelo( bCVector const &, GEFloat, GEFloat, GEFloat );
    void                          SetAlignmentLookAt( bCVector const &, GEBool );
    void                          SetAlignmentSpeed( GEFloat );
    void                          SetAlignmentTarget( eCEntity const *, GEBool );
    void                          SetApplyGravity( GEBool const & );
    void                          SetBackwardSpeedMax( GEFloat const & );
    void                          SetCanBePushedWhileIdle( GEBool const & );
    void                          SetClimbFlightForwardTime( GEFloat const & );
    void                          SetClimbFlightGravity( GEFloat const & );
    void                          SetClimbFrontDepth1( GEFloat const & );
    void                          SetClimbFrontDepth2( GEFloat const & );
    void                          SetClimbFrontDepth3( GEFloat const & );
    void                          SetClimbHeightHigh( GEFloat const & );
    void                          SetClimbHeightLow( GEFloat const & );
    void                          SetClimbHeightMid( GEFloat const & );
    void                          SetClimbHeightMin( GEFloat const & );
    void                          SetClimbTargetGroundAngleMax( GEFloat const & );
    void                          SetCurrentSpeedModifier( GEFloat );
    void                          SetDebugMode( GEBool );
    void                          SetDisableRotation( GEBool const & );
    void                          SetDisableTranslation( GEBool const & );
    void                          SetDoHeightCorrection( GEBool const & );
    void                          SetDontStopFallAngleMin( GEFloat const & );
    void                          SetFallDownMinGroundDist( GEFloat const & );
    void                          SetFallSteerScaleFactor( GEFloat const & );
    void                          SetFallVelocity( GEFloat const & );
    void                          SetFallXZDecceleration( GEFloat const & );
    void                          SetFallXZDeccelerationWarmUpTime( GEFloat const & );
    void                          SetFastModifier( GEFloat const & );
    void                          SetForceGroundAlignment( GEBool const & );
    void                          SetForwardSpeedMax( GEFloat const & );
    void                          SetGoalGroundEntity( eCEntity * );
    void                          SetGoalGroundOffset( GEFloat );
    void                          SetGoalPose( bCMotion const &, GEBool, GEBool );
    void                          SetGoalPosition( bCVector const &, GEBool, GEBool );
    void                          SetGoalRotation( bCQuaternion const & );
    void                          SetGroundSlopeTransInertia( GEFloat const & );
    void                          SetHalfSpeedTimer( GEFloat );
    void                          SetIsQuadruped( GEBool const & );
    void                          SetJumpFlightGravity( GEFloat const & );
    void                          SetJumpFrontSpeedFactor( GEFloat const & );
    void                          SetJumpHeight( GEFloat const & );
    void                          SetJumpRotationCtrlFactor( GEFloat const & );
    void                          SetJumpTranslationCtrlFactor( GEFloat const & );
    void                          SetLastFallVelocity( GEFloat const & );
    void                          SetLevitationFallVelo( GEFloat const & );
    void                          SetLevitationMaxUpwardMove( GEFloat const & );
    void                          SetLevitationModifier( GEFloat const & );
    void                          SetLevitationUpVelo( GEFloat const & );
    void                          SetMoveAcceleration( GEFloat const & );
    void                          SetMoveDecceleration( GEFloat const & );
    void                          SetMovementMode( gECharMovementMode );
    void                          SetQuadrupedSlopeInertia( GEFloat const & );
    void                          SetSensorAdvanceDuration( GEFloat const & );
    void                          SetSensorAffectsDirection( GEBool const & );
    void                          SetSensorInertia( GEFloat const & );
    void                          SetSensorMinSlideAngle( GEFloat const & );
    void                          SetSlideSpeed( GEFloat const & );
    void                          SetSlowModifier( GEFloat const & );
    void                          SetSneakModifier( GEFloat const & );
    void                          SetSteepGroundAngleMax( GEFloat const & );
    void                          SetSteepGroundAngleMin( GEFloat const & );
    void                          SetStepHeight( GEFloat const & );
    void                          SetStrafeSpeedMax( GEFloat const & );
    void                          SetTreatWaterAsSolid( GEBool const & );
    void                          SetTurnAcceleration( GEFloat const & );
    void                          SetTurnDecceleration( GEFloat const & );
    void                          SetTurnSpeedMax( GEFloat const & );
    void                          SetTurnSpeedModifier( GEFloat const & );
    void                          SetWalkDownSpeedScale( GEFloat const & );
    void                          SetWaterDeathDepth( GEFloat const & );
    void                          SetWaterWadeDepth( GEFloat const & );
    void                          StartControlNPC( void );
    void                          StopControlNPC( void );
    void                          StopMovement( GEBool );
public:
    gCCharacterMovement_PS & operator = ( gCCharacterMovement_PS const & );
public:
    gCCharacterMovement_PS( gCCharacterMovement_PS const & );
    gCCharacterMovement_PS( void );
};
GE_ASSERT_SIZEOF( gCCharacterMovement_PS, 0x0554 )

#endif
