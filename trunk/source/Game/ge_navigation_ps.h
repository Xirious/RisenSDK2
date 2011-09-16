#ifndef GE_NAVIGATION_PS_H_INCLUDED
#define GE_NAVIGATION_PS_H_INCLUDED

enum gEGotoStatus
{
    //FIXME: gEGotoStatus constants.
    gEGotoStatus_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCNavigation_PS'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCNavigation_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCNavigation_PS'
                                   // class 'gCNavigation_PS::CProcessor' needs to have dll-interface to be used by clients of class 'gCNavigation_PS'

class GE_DLLIMPORT gCNavigation_PS :
    public eCEntityPropertySet
{
public:
    struct gSObstacleEvadeSwitch
    {
        bCPropertyID __FIXME_0000;
        GEBool       __FIXME_0014;
        GE_PADDING( 3 )
    };
    GE_ASSERT_SIZEOF( gSObstacleEvadeSwitch, 0x0018 )
    struct gSRoutine
    {
        bCString      m_strName;
        eCEntityProxy m_WorkingPoint;
        eCEntityProxy m_RelaxingPoint;
        eCEntityProxy m_SleepingPoint;
    };
    GE_ASSERT_SIZEOF( gSRoutine, 0x001C )
    struct gSTrailElement
    {
        bCMotion __FIXME_0000;
        long     __FIXME_001C;
        char     __FIXME_0020;
        GE_PADDING( 3 )
    };
    GE_ASSERT_SIZEOF( gSTrailElement, 0x0024 )
    struct gSVisitedNavCluster
    {
        long     __FIXME_0000;
        bCVector __FIXME_0004;
    };
    GE_ASSERT_SIZEOF( gSVisitedNavCluster, 0x0010 )
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCNavigation_PS * m_pNavigationPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( gCNavigation_PS, eCEntityPropertySet )
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
protected: virtual bEResult                                   PostInitializeProperties( void );
public:    virtual GEBool                                     HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public:    virtual GEBool                                     OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEInt                                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr                     GetNativePropertyAt( GEInt ) const;
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual GEBool                                     IsEntityListener( void ) const;
public:    virtual GEBool                                     SupportsRenderDebugOutput( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       OnSaveGameEntityPostRead( void );
protected: virtual void                                       OnTouch( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnIntersect( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnUntouch( eCEntity *, eCContactIterator & );
public:    virtual GEBool                                     IsClassProcessible( void ) const;
public:    virtual GEBool                                     IsClassProcessingEnabled( void ) const;
public:    virtual void                                       EnableClassProcessing( GEBool );
public:    virtual void                                       EnterProcessingRange( void );
public:    virtual void                                       ExitProcessingRange( void );
protected: virtual void                                       OnEnterProcessingRange( void );
protected: virtual void                                       OnExitProcessingRange( void );
public:    virtual void                                       OnRenderDebug( void );
public:    virtual void                                       GetBoundary( bCBox &, GEBool );
public:    virtual void                                       OnProcess( void );
public:    virtual void                                       OnPostRead( void );
public:    virtual void                                       OnPostCopy( eCEntityPropertySet const & );
public:    virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_PROPERTY( eCScriptProxyScript,               m_OnEnterWater,                     OnEnterWater )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,               m_OnLeaveWater,                     OnLeaveWater )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,               m_OnWater,                          OnWater )
    GE_DECLARE_PROPERTY( bCVector,                          m_vecStartPosition,                 StartPosition )
    GE_DECLARE_PROPERTY( GEI32,                             m_i32CurrentRoutine,                CurrentRoutine )
    GE_DECLARE_PROPERTY( bTObjArray< gSRoutine >,           m_arrRoutines,                      Routines )
    GE_DECLARE_PROPERTY( eCEntityProxy,                     m_CurrentDestinationPointProxy,     CurrentDestinationPointProxy )
    GE_DECLARE_PROPERTY( eCEntityProxy,                     m_CurrentZoneEntityProxy,           CurrentZoneEntityProxy )
    GE_DECLARE_PROPERTY( eCEntityProxy,                     m_LastZoneEntityProxy,              LastZoneEntityProxy )
    GE_DECLARE_PROPERTY( bCVector,                          m_vecLastUseableNavigationPosition, LastUseableNavigationPosition )
    GE_DECLARE_PROPERTY( eCEntityProxy,                     m_LastUseableNavigationZoneProxy,   LastUseableNavigationZoneProxy )
    GE_DECLARE_PROPERTY( GEBool,                            m_bLastUseableNavigationZoneIsPath, LastUseableNavigationZoneIsPath )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bTObjArray< gSVisitedNavCluster >, m_arrVisitedNavClusters,            VisitedNavClusters )
    GE_DECLARE_PROPERTY( bTObjArray< gSTrailElement >,      m_arrBackTrail,                     BackTrail )
    GE_DECLARE_ENUMPROP( gEWalkMode,                        m_enumGuideWalkMode,                GuideWalkMode )
    CProcessor                                              m_Processor;
    GEBool                                                  m_bHasWaterContact;
    GEBool                                                  m_bIsOnDestination;
    GE_PADDING1( 2 )
    GEU32                                                   m_u32IsOnDestinationTimeStamp;
    bTValArray< bCMotion >                                  m_arrDestination;
    bTValArray< bCVector >                                  m_arrEvade;
    bCPropertyID                                            m_LastObstacleID;
    bTValArray< bCMotion >                                  m_arrNext;
    bTValArray< bCVector >                                  m_arrPassed;
    eCEntityProxy                                           m_WishedTargetEntityProxy;
    eCEntityProxy                                           m_ReachedTargetEntityProxy;
    eCEntityProxy                                           m_LastWaterContactEntityProxy;
    gEDirection                                             m_enumCurrentAniDirection;
    GEFloat                                                 m_fUnderWaterDepth;
    bTValArray< gSTrailElement >                            m_arrFreeGotoTrail;
    GEU32                                                   m_u32FreeNavigationTime;
    bTValArray< bCVector >                                  m_arrCurrentDestination;
    bTValArray< bCPropertyID >                              m_arrCurrentDestinationID;
    bTValArray< gCNavPath_PS * >                            m_arrCurrentNavPath;
    bCVector                                                m_vecCurrentTarget;
    bTValArray< bCMotion >                                  m_arrCurrentInterPose;
    GEInt                                                   m_iLastNegZoneStake;
    GEBool                                                  m_bOnTheWay;
    GEBool                                                  m_bFinalTargetDetected;
    GE_PADDING2( 2 )
    gCPrefPath_PSObj *                                      m_pPreferredPathPSObject;
    gCNavPath_PS *                                          m_pNavigationPath;
    gCDynamicCollisionCircle_PS *                           m_pDCC;
    gCCharacterMovement_PS *                                m_pCharacterMovement;
    GEBool                                                  __FIXME_0174;
    GEBool                                                  m_bIsInProcessingRange;
    GEBool                                                  m_bIsFloorDetectionFailed;
    GE_PADDING( 1 )
    GEFloat                                                 m_fSimpleMovementTime;
    bCMotion                                                m_GoalPose;
    GEBool                                                  __FIXME_0198;
    GEBool                                                  __FIXME_0199;
    GE_PADDING( 2 )
    gEDirection                                             m_enumNextAniDirection;
    GEBool                                                  __FIXME_01A0;
    GEBool                                                  m_bNewInterPose;
    GEBool                                                  m_bIsNavigateBackModusActive;
    GE_PADDING( 1 )
    eCEntity *                                              m_pInteractObject;
    gECharMovementMode                                      m_enumWishedMovementMode;
    gEGotoStatus                                            m_enumGotoStatus;
    GEBool                                                  m_bHasFinalTarget;
    GE_PADDING( 3 )
    gSObstacleEvadeSwitch                                   m_ObstacleEvadeSwitch;
    gSObstacleEvadeSwitch                                   m_NPCEvadeSwitch;
    GEBool                                                  m_bEnabled;
    GEBool                                                  m_bKilledByDeadlock;
    GEBool                                                  m_bResetWanted;
    GEBool                                                  m_bJumpToNextNavPointWanted;
    GEBool                                                  __FIXME_01E8;
    GEBool                                                  __FIXME_01E9;
    GEBool                                                  __FIXME_01EA;
    GE_PADDING( 1 )
    GEInt                                                   m_iWantedNetIndex;
public:
    gEDirection &                        AccessCurrentAniDirection( void );
    bTValArray< bCVector > &             AccessCurrentDestination( void );
    bTValArray< bCPropertyID > &         AccessCurrentDestinationID( void );
    bTValArray< bCMotion > &             AccessCurrentInterPose( void );
    bTValArray< gCNavPath_PS * > &       AccessCurrentNavPath( void );
    bTValArray< bCMotion > &             AccessDestination( void );
    bTValArray< bCVector > &             AccessEvade( void );
    GEU32 &                              AccessIsOnDestinationTimeStamp( void );
    bCPropertyID &                       AccessLastObstacleID( void );
    gSObstacleEvadeSwitch &              AccessNPCEvadeSwitch( void );
    bTValArray< bCMotion > &             AccessNext( void );
    gSObstacleEvadeSwitch &              AccessObstacleEvadeSwitch( void );
    bTValArray< bCVector > &             AccessPassed( void );
    eCEntityProxy &                      AccessReachedTargetEntityProxy( void );
    GEFloat &                            AccessUnderWaterDepth( void );
    eCEntityProxy &                      AccessWishedTargetEntityProxy( void );
    GEBool                               CanCorrectTarget( bCVector const & );
    GEBool                               FillNextForNavigationPath( bCVector const &, bCVector const & );
    GEBool                               FillNextForPreferredPath( void );
    gCCharacterMovement_PS *             GetCharacterMovement( void );
    gEDirection                          GetCurrentAniDirection( void ) const;
    bTValArray< bCVector > const &       GetCurrentDestination( void ) const;
    bTValArray< bCPropertyID > const &   GetCurrentDestinationID( void ) const;
    bTValArray< bCMotion > const &       GetCurrentInterPose( void ) const;
    bTValArray< gCNavPath_PS * > const & GetCurrentNavPath( void ) const;
    eCEntity *                           GetCurrentRelaxingPoint( void ) const;
    eCEntity *                           GetCurrentSleepingPoint( void ) const;
    bCVector const &                     GetCurrentTarget( void ) const;
    eCEntity *                           GetCurrentWorkingPoint( void ) const;
    gCDynamicCollisionCircle_PS *        GetDCC( void );
    bTValArray< bCMotion > const &       GetDestination( void ) const;
    GEBool                               GetDontUseLimitedNavPaths( void );
    GEBool                               GetEnabled( void ) const;
    bTValArray< bCVector > const &       GetEvade( void ) const;
    GEBool const                         GetFinalTargetDetected( void ) const;
    bCMotion const &                     GetGoalPose( void );
    GEBool                               GetGoalReached( void );
    gEGotoStatus                         GetGotoStatus( void ) const;
    GEBool                               GetHasFinalTarget( void ) const;
    eCEntity *                           GetInteractObject( void ) const;
    GEBool                               GetIsOnDestination( void ) const;
    GEU32                                GetIsOnDestinationTimeStamp( void ) const;
    GEBool                               GetJumpToNextNavPointWanted( void );
    GEBool                               GetKilledByDeadlock( void ) const;
    GEInt const                          GetLastNegZoneStake( void ) const;
    bCPropertyID const &                 GetLastObstacleID( void ) const;
    bCVector const &                     GetLastUseableNavPosition( void ) const;
    GEBool                               GetLastUseableNavZoneID( bCPropertyID & ) const;
    eCEntityProxy const &                GetLastWaterContactEntityProxy( void ) const;
    gCNavPath_PS *                       GetNavigationPath( void ) const;
    GEBool                               GetNewInterPose( void ) const;
    bTValArray< bCMotion > const &       GetNext( void ) const;
    gEDirection const                    GetNextAniDirection( void ) const;
    GEBool const                         GetOnTheWay( void ) const;
    bTValArray< bCVector > const &       GetPassed( void ) const;
    gCPrefPath_PSObj *                   GetPreferredPathPSObject( void ) const;
    eCEntityProxy const &                GetReachedTargetEntityProxy( void ) const;
    GEBool                               GetResetWanted( void );
    bCString const &                     GetRoutine( void ) const;
    GEFloat                              GetUnderWaterDepth( void ) const;
    GEInt                                GetWantedNetIndex( void ) const;
    gECharMovementMode                   GetWishedMovementMode( void ) const;
    eCEntityProxy const &                GetWishedTargetEntityProxy( void ) const;
    GEBool                               HasRoutinePointRoamOrPatrol( void );
    GEBool                               HasWaterContact( void ) const;
    GEBool                               IsFloorDetectionFailed( void ) const;
    GEBool                               IsInProcessingRange( void ) const;
    GEBool                               IsNavigateBackModusActive( void ) const;
    void                                 Reset( GEBool, GEBool, GEBool );
    void                                 ResetFreeGotoTrail( void );
    GEBool                               RunFreeNavigation( GEFloat & );
    void                                 RunHeightCorrectionInProcessingRange( void );
    GEBool                               RunNPCTeleportToNavArea( GEInt );
    GEBool                               RunNextFreeGotoStep( eCGeometryEntity *, GEBool, GEBool );
    GEBool                               RunSimpleMovement( void );
    void                                 SetCharacterMovement( gCCharacterMovement_PS * );
    void                                 SetCurrentAniDirection( gEDirection );
    GEBool                               SetCurrentRelaxingPoint( eCEntity * );
    GEBool                               SetCurrentSleepingPoint( eCEntity * );
    void                                 SetCurrentTarget( bCVector const & );
    GEBool                               SetCurrentWorkingPoint( eCEntity * );
    void                                 SetDCC( gCDynamicCollisionCircle_PS * );
    void                                 SetEnabled( GEBool );
    void                                 SetFinalTargetDetected( GEBool );
    void                                 SetGoalPose( bCMotion const &, GEBool );
    void                                 SetGoalReached( void );
    void                                 SetGotoStatus( gEGotoStatus );
    void                                 SetHasFinalTarget( GEBool );
    void                                 SetInteractObject( eCEntity * );
    void                                 SetIsOnDestination( GEBool );
    void                                 SetIsOnDestinationTimeStamp( GEU32 );
    void                                 SetJumpToNextNavPointWanted( GEBool );
    void                                 SetKilledByDeadlock( GEBool );
    void                                 SetLastNegZoneStake( GEInt );
    void                                 SetLastUseableNavPosition( bCVector const &, bCPropertyID const &, GEBool );
    void                                 SetLastWaterContactEntityProxy( eCEntityProxy const & );
    void                                 SetNavigationPath( gCNavPath_PS * );
    void                                 SetNewInterPose( GEBool );
    void                                 SetNextAniDirection( gEDirection );
    void                                 SetOnTheWay( GEBool );
    void                                 SetPreferredPathPSObject( gCPrefPath_PSObj * );
    void                                 SetReachedTargetEntityProxy( eCEntityProxy const & );
    void                                 SetResetWanted( GEBool );
    GEBool                               SetRoutine( bCString const & );
    void                                 SetUnderWaterDepth( GEFloat );
    void                                 SetWantedNetIndex( GEInt );
    void                                 SetWishedMovementMode( gECharMovementMode );
    void                                 SetWishedTargetEntityProxy( eCEntityProxy const & );
    GEBool                               TestNextOnPreferredPath( void );
    GEFloat                              TestPreferredPathUse( gCPrefPath_PSObj * );
    void                                 UpdateBackTrail( void );
    void                                 UpdateInteractObject( void );
    void                                 UpdateSimpleMovementTime( GEFloat, GEBool );
    void                                 UpdateZoneIDs( GEBool );
protected:
    GEBool ActivateFreeNavigationJump( bCVector const &, GEBool, GEInt & );
    GEBool ActivateNextFreeGoal( eCGeometryEntity * );
    void   DeregisterDCC( void );
    GEBool ExtendFreeGotoTrail( eCGeometryEntity *, GEBool &, GEBool );
    void   GameReset( void );
    GEBool GoalCorrectionForFreeGoto( GEFloat &, GEFloat, bCVector &, eCGeometryEntity * );
    void   Invalidate( void );
    GEBool WaitingForNextFreeGoalReached( void );
};
GE_ASSERT_SIZEOF( gCNavigation_PS, 0x01F0 )

#pragma warning( pop )

#endif
