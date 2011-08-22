#ifndef GE_ACTORWRAPPER_H_INCLUDED
#define GE_ACTORWRAPPER_H_INCLUDED

class GE_DLLIMPORT eCWrapper_emfx3ActorInstance :
    public bCObjectBase
{
public: virtual GEU16    GetVersion( void ) const;
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual GEBool   OnCopyFrom( bCObjectBase const & );
public: virtual         ~eCWrapper_emfx3ActorInstance( void );
public: virtual GEBool   IntersectsRay( eSRayIntersectionDesc &, eCCollisionDesc * * ) const;
protected:
    char __FIXME[ 0x0094 - sizeof(bCObjectBase) ];
protected:
    void Invalidate( void );
public:
    static bCMatrix *       GE_STDCALL GetWorldMatrices( EMotionFX::ActorInstance * );
    static bCMatrix const * GE_STDCALL GetWorldMatrices( EMotionFX::ActorInstance const * );
public:
    GEBool                           DeformBodyParts( void ) const;
    bCString const &                 GetActorName( void ) const;
    bCString                         GetBoneName( GEInt ) const;
    GEBool                           GetBoundary( bCBox & ) const;
    GEFloat                          GetExtroBlending( eAnimShared::eEMotionType ) const;
    EMotionFX::ActorInstance *       GetInstance( void );
    EMotionFX::ActorInstance const * GetInstance( void ) const;
    GEFloat                          GetIntroBlending( eAnimShared::eEMotionType ) const;
    GEDouble                         GetMaxTime( eAnimShared::eEMotionType ) const;
    bCMatrix                         GetMeshNodeMatrix( void ) const;
    bCString                         GetMotionName( eAnimShared::eEMotionType ) const;
    eAnimShared::eEMotionPlayMode    GetOverlay1PlayMode( void ) const;
    eCEntityPropertySet *            GetOwnerPS( void );
    GEFloat                          GetPlaySpeed( eAnimShared::eEMotionType ) const;
    GEDouble                         GetPlayTime( eAnimShared::eEMotionType ) const;
    eAnimShared::eEMotionPlayMode    GetPrimary1PlayMode( void ) const;
    GEInt                            GetRandomPointsOnMesh( bCVector *, GEInt, bCVector *, GEFloat ) const;
    bTValArray< bCMatrix > const &   GetRenderMatrices( void ) const;
    bCVector const &                 GetRepositioningVector( void ) const;
    eCMotionActorResource2 *         GetResourceActor( void ) const;
    GEFloat                          GetTargetWeight( eAnimShared::eEMotionType ) const;
    bCMatrix *                       GetWorldMatrices( void );
    bCMatrix const *                 GetWorldMatrices( void ) const;
    GEBool                           GetWorldMatrices( bTValArray< bCMatrix > & ) const;
    GEBool                           HasMotionInstance( eAnimShared::eEMotionType ) const;
    GEBool                           IsActorPlaying( eAnimShared::eEMotionType ) const;
    GEBool                           IsMotionRunning( eAnimShared::eEMotionType ) const;
    void                             PlayMotion( eAnimShared::eEMotionType, eCMotionResource2 *, eAnimShared::eSMotionPlayBackDesc *, GEBool );
    GEBool                           ReleaseResources( void );
    GEBool                           RequestResources( void );
    void                             RunStopPrevention( GEFloat );
    void                             SetActorName( bCString const & );
    void                             SetIntroExtroBlending( eAnimShared::eEMotionType, bCString & );
    void                             SetIntroExtroBlending( eAnimShared::eEMotionType, GEFloat, GEFloat );
    void                             SetOwnerPS( eCEntityPropertySet * );
    void                             SetPlaySpeed( eAnimShared::eEMotionType, GEFloat );
    void                             SetPlayTime( eAnimShared::eEMotionType, GEFloat );
    void                             SetTargetWeight( eAnimShared::eEMotionType, GEFloat, GEFloat );
    GEBool                           SetWorldMatrices( bTValArray< bCMatrix > const & );
    void                             StopAtLoopEnd( eAnimShared::eEMotionType );
    void                             StopMotion( eAnimShared::eEMotionType, GEFloat, GEBool );
    void                             SwitchFadeOut( eAnimShared::eEMotionType, GEBool, GEFloat );
    void                             UpdateBoundary( GEInt, eAnimShared::eEBoundsType );
    GEBool                           UpdateRenderMatrices( GEU32 );
    void                             UpdateRepositioning( GEBool );
    void                             UpdateTransformations( GEFloat, GEBool );
protected:
    eCWrapper_emfx3ActorInstance const & operator = ( eCWrapper_emfx3ActorInstance const & );
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    eCWrapper_emfx3ActorInstance( eCWrapper_emfx3ActorInstance const & );
    eCWrapper_emfx3ActorInstance( void );
};
GE_ASSERT_SIZEOF( eCWrapper_emfx3ActorInstance, 0x0094 )

#endif