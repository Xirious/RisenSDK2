#ifndef GE_ANIMATION_PS_H_INCLUDED
#define GE_ANIMATION_PS_H_INCLUDED

class GE_DLLIMPORT eCAnimation_PS :
    public eCEntityPropertySet
{
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                                   PostInitializeProperties( void );
public:    virtual                                           ~eCAnimation_PS( void );
protected: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual GEBool                                     IsVisual( void ) const;
public:    virtual eCRenderContext *                          CreateRenderContext( void );
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                                       OnEnterProcessingRange( void );
protected: virtual void                                       OnExitProcessingRange( void );
public:    virtual void                                       OnRenderDebug( void );
public:    virtual void                                       GetBoundary( bCBox &, GEBool );
public:    virtual GEBool                                     IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
protected: virtual void                                       OnUpdateInternals( void );
protected: virtual void                                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
public:    virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
public:    virtual void                                       OnCacheIn( void );
public:    virtual void                                       OnCacheOut( void );
protected: virtual void                                       OnPrefetch( bCVector const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    static GEBool ms_bRenderDebug;
    static GEBool ms_bRenderDebugCM;
protected:
    char __FIXME[ 0x0160 - sizeof(eCEntityPropertySet) ];
protected:
    GEBool CheckRagdollDeathPose( void );
    void   DisableProcessing( GEBool );
    void   DrawCollisionMesh( void );
    void   DrawNodeAxesDebug( bCMatrix const &, GEFloat );
    void   DrawSkeleton( void );
    void   Invalidate( void );
    void   StopAllMotions( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static GEBool                     GE_STDCALL GetRenderDebug( void );
    static GEBool                     GE_STDCALL GetRenderDebugCM( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL SetRenderDebug( GEBool );
    static void                       GE_STDCALL SetRenderDebugCM( GEBool );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                             AccessEnableRepositioning( void );
    GEInt &                              AccessMaterialSwitch( void );
    GEFloat &                            AccessRagDollMass( void );
    GEBool                               AddAttachment( eCEntity *, bCString const &, bCMatrix const *, GEU32, GEBool );
    GEBool                               AddAttachment( eCEntity *, bCString const &, eCActorAttachment::eFUpdateCallback );
    GEBool                               AddAttachment( eCEntity *, GEU32, bCMatrix const *, GEU32, GEBool );
    GEBool                               AddAttachment( eCEntity *, GEU32, eCActorAttachment::eFUpdateCallback );
    GEBool                               AddBodyPart( eCBodyPart_PS * );
    void                                 AddForceAtPos( bCVector const &, bCVector const & );
    GEBool                               AddLookAtController( bCString const &, bCVector const &, bCVector const &, GEFloat );
    void                                 ClearStaticPose( void );
    void                                 EnableSkeletonCollision( GEBool );
    void                                 EnableSkeletonCollisionWith( eCGeometryEntity *, GEBool );
    eCWrapper_emfx3ActorInstance *       GetActorWrapper( void );
    eCWrapper_emfx3ActorInstance const * GetActorWrapper( void ) const;
    eCBodyPart_PS *                      GetBodyPart( GEInt );
    eCWrapper_emfx3ActorInstance *       GetBodyPartActorWrapper( GEInt );
    GEBool                               GetBoneMatrix( bCString const &, bCMatrix & );
    GEBool                               GetBoneMatrix( GEInt, bCMatrix & );
    eCAnimation_PS *                     GetChildByActor( NxActor * );
    GEBool                               GetDebugMode( void );
    GEBool const &                       GetEnableRepositioning( void ) const;
    GEBool                               GetLastAmbientWasLoop( void ) const;
    GEInt                                GetLastAnimationVariation( void ) const;
    GEBool                               GetLocalBoneMatrix( bCString const &, bCMatrix & );
    GEBool                               GetLocalBoneMatrix( GEInt, bCMatrix & );
    GEInt const &                        GetMaterialSwitch( void ) const;
    eAnimShared::eEMotionOwner           GetMotionOwner( eAnimShared::eEMotionType ) const;
    GEU32                                GetNumAttachments( void );
    GEInt                                GetNumBodyParts( void );
    GEBool                               GetRagDollEnabled( void ) const;
    GEFloat const &                      GetRagDollMass( void ) const;
    GEInt                                GetRandomPointsOnMesh( bCVector *, GEInt, bCVector *, GEFloat ) const;
    bCVector const &                     GetRepositioningVector( void ) const;
    bCString                             GetResourceFilePath( void ) const;
    GEBool                               GetShowSkeleton( void );
    GEBool                               GetUseAmbientVariationExclusionForNextAnimation( void ) const;
    GEBool                               HasMotion( eAnimShared::eEMotionType ) const;
    GEBool                               HasStaticPose( void ) const;
    GEBool                               IsDead( void ) const;
    GEBool                               IsFrozen( void ) const;
    GEBool                               IsVisible( void ) const;
    GEBool                               NeedsDeathAnimation( void ) const;
    void                                 PlayMotion( eAnimShared::eEMotionType, eAnimShared::eSMotionPlayBackDesc *, GEBool );
    void                                 Process( GEFloat, GEBool );
    void                                 Reactivate( void );
    void                                 ReleaseResources( void );
    GEBool                               RemoveAttachment( eCEntity * );
    GEBool                               RemoveBodyPart( eCBodyPart_PS * );
    void                                 Render( GEU16, GEU16, GEBool, GEFloat );
    GEBool                               RequestResources( void );
    void                                 RestoreStaticPose( void );
    void                                 SaveStaticPose( void );
    void                                 SetActorFrozen( GEBool );
    void                                 SetDebugMode( GEBool );
    void                                 SetEnableRepositioning( GEBool const & );
    void                                 SetLastAmbientWasLoop( GEBool );
    void                                 SetLastAnimationVariation( GEInt );
    void                                 SetLookAtTarget( eCEntity *, bCString const & );
    void                                 SetMaterialSwitch( GEInt const & );
    void                                 SetMotion( eAnimShared::eEMotionType, eCMotionResource2 * );
    void                                 SetMotionOwner( eAnimShared::eEMotionType, eAnimShared::eEMotionOwner );
    void                                 SetRagDollEnabled( GEBool, GEBool, bCVector * );
    void                                 SetRagDollMass( GEFloat const & );
    void                                 SetResourceFilePath( bCString const & );
    void                                 SetShowSkeleton( GEBool );
    void                                 SetUseAmbientVariationExclusionForNextAnimation( GEBool );
    void                                 StopAtLoopEnd( eAnimShared::eEMotionType );
    void                                 StopMotion( eAnimShared::eEMotionType, GEFloat );
    void                                 StopRagDoll( void );
    void                                 UpdateAttachments( void );
    void                                 UpdateLookAtControllers( void );
    void                                 UpdatePosition( void );
private:
    eCAnimation_PS & operator = ( eCAnimation_PS const & );  // not defined
public:
    eCAnimation_PS( eCAnimation_PS const & );
    eCAnimation_PS( void );
};
GE_ASSERT_SIZEOF( eCAnimation_PS, 0x0160 )

#endif
