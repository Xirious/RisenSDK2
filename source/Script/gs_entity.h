#ifndef GS_ENTITY_H_INCLUDED
#define GS_ENTITY_H_INCLUDED

enum EDifficulty
{
    EDifficulty_Easy       = 0x00000000,
    EDifficulty_Normal     = 0x00000001,
    EDifficulty_Hard       = 0x00000002,
    EDifficulty_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'Entity'

class GE_DLLIMPORT Entity
{
public:
    GS_DECLARE_PROPERTYSET_TEMPLATE( Entity )
protected:
    eCEntity * m_pEngineEntity;
public:
    static bTObjArray< Entity > ms_arrEntities;
    static bTObjArray< Entity > ms_arrNPCs;
    static GEU32                ms_u32LastFrame;
protected:
    static GEInt GE_CCALL   SortEntites( GELPCVoid, GELPCVoid );
    static void  GE_STDCALL UpdateEntityLists( void );
protected:
    GEBool     CopyFrom( Entity const & );
    eCEntity * GetEngineEntity( void ) const;
    void       Invalidate( void );
public:
    static bCString                 GE_STDCALL FindNextNPC( bCString const &, bCString const & );
    static bCMatrix                 GE_STDCALL GetCameraPose( void );
    static Entity const             GE_STDCALL GetCameraTarget( Entity &, GEBool &, bCVector & );
    static Entity                   GE_STDCALL GetControledNPC( void );
    static bCString &               GE_STDCALL GetCurrentCameraName( void );
    static GEU32                    GE_STDCALL GetCurrentChapter( void );
    static EDifficulty              GE_STDCALL GetCurrentDifficulty( void );
    static bTObjArray< Entity >     GE_STDCALL GetEntities( void );
    static bTValArray< eCEntity * > GE_STDCALL GetEntitiesByName( bCString );
    static Entity                   GE_STDCALL GetEntity( bCString );
    static bCString                 GE_STDCALL GetMaterialName( eEShapeMaterial );
    static bTObjArray< Entity >     GE_STDCALL GetNPCs( void );
    static Entity                   GE_STDCALL GetNextPatrolPoint( Entity const & );
    static Entity                   GE_STDCALL GetOriginalPlayer( void );
    static Entity                   GE_STDCALL GetPlayer( void );
    static GEFloat                  GE_STDCALL GetPlayingTime( void );
    static GEFloat                  GE_STDCALL GetPlayingTimeInSeconds( void );
    static GEInt                    GE_STDCALL GetRandomNumber( GEInt );
    static gECombatMode             GE_STDCALL GetRestorePlayerCombatMode( void );
    static bTValArray< eCEntity * > GE_STDCALL GetRoamingPointsByName( bCString );
    static Entity                   GE_STDCALL GetRoom( bCVector const & );
    static GEFloat                  GE_STDCALL GetTimeStampInSeconds( void );
    static Entity                   GE_STDCALL GetWorldEntity( void );
    static GEFloat                  GE_STDCALL GetWorldTime( void );
    static eCEntityProxy const &    GE_STDCALL GetWorldTorch( void );
    static GEBool                   GE_STDCALL HasCopyCheckFailed( void );
    static GEBool                   GE_STDCALL IsAdvancedTestModeEnabled( void );
    static GEBool                   GE_STDCALL IsCameraInDestinationPose( void );
    static GEBool                   GE_STDCALL IsCheatGodEnabled( void );
    static GEBool                   GE_STDCALL IsCheatInvisibleEnabled( void );
    static GEBool                   GE_STDCALL IsDialogCameraActive( void );
    static GEBool                   GE_STDCALL IsFixCamActive( void );
    static GEBool                   GE_STDCALL IsTestModeEnabled( void );
    static GEBool                   GE_STDCALL PrefetchResource( bCString );
    static GEInt                    GE_STDCALL ProcessWorldTorchTimer( void );
    static void                     GE_STDCALL ResetWorldTorchTimer( GEInt );
    static void                     GE_STDCALL RestoreWorldTorch( void );
    static GEBool                   GE_STDCALL SaveCameraDump( bCUnicodeString, bCUnicodeString );
    static void                     GE_STDCALL SetCameraTarget( Entity const &, Entity const &, GEBool, bCVector const &, GEBool, Entity const &, GEFloat );
    static void                     GE_STDCALL SetCurrentCameraByName( bCString const &, GEBool );
    static void                     GE_STDCALL SetCurrentChapter( GEU32 );
    static void                     GE_STDCALL SetDialogRoles( Entity const &, Entity const & );
    static void                     GE_STDCALL SetPlayingTime( GEFloat );
    static void                     GE_STDCALL SetRestorePlayerCombatMode( gECombatMode );
    static void                     GE_STDCALL SetWorldTime( GEFloat );
    static void                     GE_STDCALL SetWorldTorch( Entity const & );
    static void                     GE_STDCALL SortEntityListByDistanceTo( bTObjArray< Entity > &, Entity const & );
    static Entity                   GE_STDCALL Spawn( Template, bCMatrix const &, GEBool );
    static Entity                   GE_STDCALL Spawn( Template, Entity, GEBool, gEDirection );
    static void                     GE_STDCALL StartDialogCamera( Entity const &, Entity const & );
    static void                     GE_STDCALL StartFixCam( bCMatrix const &, bCVector const &, GEBool, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEBool );
    static void                     GE_STDCALL StartFixCam( bCMatrix const &, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEBool, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEFloat, GEBool );
    static void                     GE_STDCALL StopFixCam( void );
public:
    GEBool               AttachTo( eCEntity * );
    GEBool               CanEvade( Entity const &, gEDirection ) const;
    GEBool               CanGoto( Entity const & ) const;
    GEBool               CanGoto( bCVector const & ) const;
    GEBool               CanJumpToZone( Entity const & ) const;
    void                 Decay( void );
    GEBool               DestroyWaterEmitter( void ) const;
    void                 EnableCollision( eEShapeGroup, GEBool, GEInt );
    void                 EnableCollision( GEBool );
    void                 EnableCollisionWith( Entity const &, GEBool );
    void                 EnableRendering( GEBool );
    void                 EnableTraceRay( GEBool );
    void                 EndTakeOver( void );
    GEFloat              FindDeepPoint( GEFloat, bCVector & );
    bCString             FindNextPropertySet( bCString const & );
    bCString             FindNextPropertySetAttribute( bCString const &, bCString const & );
    GEBool               FindSpawnPose( bCMatrix &, Entity const &, GEBool, GEU16 ) const;
    bCString             GetAIZoneGroup( void ) const;
    gEGuild              GetAIZoneGuild( void ) const;
    gESecurityLevel      GetAIZoneSecurityLevel( void ) const;
    Entity               GetAlignmentTarget( void ) const;
    bCString             GetAni( bCString const &, bCString const &, gEDirection, GEBool, gECombatPose, gEAniState ) const;
    bCString             GetAni( bCString const &, gEItemUseType, gEItemUseType, bCString const &, gEDirection, GEBool, gECombatPose, gEAniState, GEBool ) const;
    bCString             GetAniEx( bCString const &, bCString const &, GEBool, gEDirection, GEBool, gECombatPose, gEAniState ) const;
    bCString             GetAniEx( gEItemUseType, gEItemUseType, bCString const &, bCString const &, GEBool, gEDirection, GEBool, gECombatPose, gEAniState, GEBool ) const;
    bCVector             GetAtVector( void ) const;
    void                 GetAziElev( Entity const &, GEFloat &, GEFloat & ) const;
    void                 GetAziElev( bCVector const &, GEFloat &, GEFloat & ) const;
    GEFloat              GetBoundingRadius( void ) const;
    bCSphere             GetBoundingSphere( void ) const;
    eECollisionGroup     GetCollisionGroup( void ) const;
    gEDirection          GetCurrentAniDirection( void ) const;
    bCVector             GetDirectionTo( Entity const & ) const;
    bCString             GetDisplayName( void ) const;
    GEFloat              GetDistanceTo( Entity const & ) const;
    bTObjArray< Entity > GetEntitiesByDistance( void ) const;
    bCVector             GetEvadeDestination( Entity const &, gEDirection ) const;
    Entity               GetFleePoint( Entity &, GEBool, GEFloat );
    bCString             GetHoldAni( bCString const &, gEItemHoldType, gEItemHoldType, bCString const &, gEDirection, GEBool, gECombatPose ) const;
    bCString             GetHoldAniEx( gEItemHoldType, gEItemHoldType, bCString const &, bCString const &, GEBool, gEDirection, GEBool, gECombatPose ) const;
    bCString             GetHoldOverlayAni( bCString const &, gEItemHoldType, gEItemHoldType, bCString const &, gEDirection, GEBool, gECombatPose ) const;
    eCEntity *           GetInstance( void ) const;
    bCVector             GetLinearVelocity( void ) const;
    GEBool               GetListOfAreaWithProperty( bCString const &, bTObjArray< bCString > & );
    GEBool               GetListOfAreaWithProperty( bCString const &, bTValArray< eCEntity * > & );
    GEBool               GetListOfAreaWithProperty( bCVector const &, bCString const &, bTObjArray< bCString > & );
    GEBool               GetListOfAreaWithProperty( bCVector const &, bCString const &, bTValArray< eCEntity * > & );
    GEBool               GetListOfPropertyNames( bTObjArray< bCString > & );
    GEBool               GetListOfPropertyNames( bCVector const &, bTObjArray< bCString > & );
    gECharMovementMode   GetMovementMode( void ) const;
    bCString             GetName( void ) const;
    Entity               GetNearestFleePoint( Entity &, GEFloat );
    bCVector             GetNearestNavigationPoint( bCVector, GEFloat );
    GEU32                GetNetIndex( void ) const;
    bCString             GetOverlayAni( bCString const &, bCString const &, gEDirection, GEBool, gECombatPose ) const;
    bCString             GetOverlayAni( bCString const &, gEItemUseType, gEItemUseType, bCString const &, gEDirection, GEBool, gECombatPose ) const;
    Entity               GetOwner( void ) const;
    bCMatrix             GetPose( void ) const;
    bCVector             GetPosition( void ) const;
    bCString             GetPropertySetAttribute( bCString const &, bCString const & );
    bCVector             GetRandomNavigationPoint( bCVector, GEFloat );
    Entity               GetRoom( void ) const;
    bCString             GetSampleTitle( bCString ) const;
    bCString             GetSkeletonName( void ) const;
    bCString             GetSmalltalkString( void );
    GEFloat              GetSquareDistanceTo( Entity const & ) const;
    Template             GetTemplate( void ) const;
    bCVector             GetUnitDirectionTo( Entity const & ) const;
    Entity               GetUser( void ) const;
    bCVector             GetVelocity( void ) const;
    bCString             GetWaterEffect( bCString const &, bCString const & ) const;
    bCString             GetWaterEffectMaterial( void ) const;
    Entity               GetWaterEmitter( void ) const;
    Entity               GetZone( void ) const;
    GEBool               HasCommentInfo( Entity const & ) const;
    GEBool               HasFreePlace( bCMatrix & ) const;
    GEBool               HasImportantInfo( Entity const & ) const;
    GEBool               HasInFOV( Entity const & ) const;
    GEBool               HasInfo( Entity const & ) const;
    GEBool               HasNewsInfo( Entity const & ) const;
    GEBool               HasRefuseInfo( Entity const & ) const;
    GEBool               HasSVMBlock( bCString const & );
    GEBool               HasWaterContact( void );
    GEBool               IsBraking( void ) const;
    GEBool               IsBurned( void ) const;
    GEBool               IsCharacter( void ) const;
    GEBool               IsClimbing( void ) const;
    GEBool               IsControledNPC( void ) const;
    GEBool               IsDead( void ) const;
    GEBool               IsDecalEnabled( void ) const;
    GEBool               IsDiving( void ) const;
    GEBool               IsDown( void ) const;
    GEBool               IsFalling( void ) const;
    GEBool               IsFreeLOS( Entity const &, GEBool ) const;
    GEBool               IsFreeLOSKneeHeight( Entity const & ) const;
    GEBool               IsFrozen( void ) const;
    GEBool               IsHighlighted( void ) const;
    GEBool               IsInAreaWithProperties( bTObjArray< bCString > const &, GEBool, bTObjArray< bCString > const &, GEBool );
    GEBool               IsInAreaWithProperties( bCVector const &, bTObjArray< bCString > const &, GEBool, bTObjArray< bCString > const &, GEBool );
    GEBool               IsInAreaWithProperty( bCString const & );
    GEBool               IsInAreaWithProperty( bCVector const &, bCString const & );
    GEBool               IsInMovingState( void ) const;
    GEBool               IsInteractObject( void ) const;
    GEBool               IsItem( void ) const;
    GEBool               IsJumping( void ) const;
    GEBool               IsLevitating( void ) const;
    GEBool               IsNPC( void ) const;
    GEBool               IsPlayer( void ) const;
    GEBool               IsProcessingRangeEntered( void ) const;
    GEBool               IsReady( void ) const;
    GEBool               IsRunning( void ) const;
    GEBool               IsSneaking( void ) const;
    GEBool               IsSprinting( void ) const;
    GEBool               IsStanding( void ) const;
    GEBool               IsSwimming( void ) const;
    GEBool               IsTemplateEntity( void ) const;
    void                 Kill( void );
    void                 MoveTo( Entity const & );
    void                 MoveTo( bCMatrix const & );
    void                 ReAttach( void );
    void                 ResetInteractAnimation( GEFloat, GEFloat );
    void                 RevertPlayingAni( GEFloat );
    void                 SetAIZoneGroup( bCString & );
    void                 SetAIZoneGuild( gEGuild );
    void                 SetAIZoneSecurityLevelFunc( bCString & );
    void                 SetAlignmentTarget( Entity const & );
    void                 SetAlpha( GEFloat );
    void                 SetBurned( GEBool );
    void                 SetCollisionGroup( eECollisionGroup );
    void                 SetCurrentAniDirection( gEDirection );
    void                 SetForcedAlignmentTarget( Entity const & );
    void                 SetFrozen( GEBool );
    void                 SetHighlighted( GEBool );
    void                 SetLinearVelocity( bCVector const & );
    void                 SetLookAtTarget( Entity const & );
    void                 SetMovementMode( gECharMovementMode );
    void                 SetName( bCString const & );
    void                 SetPose( bCMatrix const & );
    void                 SetPropertySetAttribute( bCString const &, bCString const &, bCString const & );
    GEBool               StartComment( Entity const & ) const;
    void                 StartFacialAni( bCString );
    GEBool               StartGoto( Entity &, gEWalkMode );
    GEBool               StartGoto( bCVector const &, gEWalkMode );
    void                 StartOutput( bCString, gEOutputType );
    void                 StartPlayAni( bCString, GEInt, GEBool, GEFloat, GEBool, eAnimShared::eEMotionType );
    void                 StartPlayAniEx( bCString const &, GEInt, GEBool, GEBool, GEFloat, GEBool );
    void                 StartPlayOverlayAni( bCString, GEInt, GEBool, GEFloat );
    void                 StartSay( Entity &, bCString, GEBool, GEBool );
    void                 StartSayEx( Entity &, bCString, bCString, GEBool, GEBool );
    void                 StartSaySVM( Entity &, bCString, GEBool, GEBool );
    void                 StartTakeOver( void );
    GEBool               StartTurnTo( Entity const & );
    void                 StopFacialAni( void );
    void                 StopGoto( void );
    void                 StopOutput( void );
    void                 StopPlayAni( void );
    void                 StopPlayOverlayAni( void );
    GEBool               Teleport( Entity const & );
    GEBool               Teleport( bCString const & );
    void                 Trigger( Entity );
    void                 UnTrigger( Entity );
public:
             operator eCEntity * ( void ) const;
    GEBool   operator ==         ( Entity const & ) const;
    GEBool   operator !=         ( Entity const & ) const;
    Entity & operator =          ( Entity const & );
public:
    Entity( Entity const & );
    Entity( eCEntityProxy const & );
    Entity( eCEntity const * );
    Entity( void );
   ~Entity( void );
};

#pragma warning( pop )

GE_C_LINKAGE GE_DLLIMPORT Entity None;

#endif
