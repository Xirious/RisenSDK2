#ifndef GE_COLLISIONSHAPE_PS_H_INCLUDED
#define GE_COLLISIONSHAPE_PS_H_INCLUDED

enum eEPhysicRangeType
{
    eEPhysicRangeType_World           = 0x00000000,
    eEPhysicRangeType_ProcessingRange = 0x00000001,
    eEPhysicRangeType_VisibilityRange = 0x00000002,
    eEPhysicRangeType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT eCCollisionShape_PS :
    public eCCollisionShapeBase_PS
{
public:    using                     eCCollisionShapeBase_PS::SetShape;
public:    virtual bEResult                                   SetShape( bCString const &, GEBool );
public:    virtual bEResult                                   AddShape( bCString const &, GEBool );
public:    using                     eCCollisionShapeBase_PS::AddShape;
public:    virtual bEResult                                   AddShape( eECollisionShapeType, eEShapeGroup, bCVector const &, bCVector const & );
public:    virtual GEBool                                     AddShapesFromSpeedTreePS( void );
public:    virtual GEBool                                     AddShapesFromSpeedTreeResource( eCSpeedTreeResource2 * );
public:    virtual bEResult                                   AddDynamicShape( eECollisionShapeType, eEShapeGroup, eEShapeAABBAdapt, GEFloat );
public:    virtual bEResult                                   AddPointShape( eEShapeGroup, bCVector const & );
public:    virtual bEResult                                   AddTouchingShape( eCCollisionShape * );
public:    using                     eCCollisionShapeBase_PS::GetShapeAtIndex;
public:    virtual eCCollisionShape *                         GetShapeAtIndex( GEInt ) const;
public:    virtual NxShape *                                  GetProprietaryShapeAtIndex( GEU32 ) const;
public:    virtual void                                       RemoveShapes( void );
public:    virtual void                                       RemoveShapes( eEShapeGroup );
public:    virtual void                                       RemoveShapes( eECollisionShapeType );
public:    virtual void                                       RemoveShape( eCCollisionShape * );
public:    virtual void                                       RemoveTouchingShape( eCCollisionShape * );
public:    virtual void                                       RemoveShapeAt( GEInt );
protected: virtual void                                       EnableShapeGroupCollisionInternal( eEShapeGroup, GEBool, GEInt );
protected: virtual void                                       SetShapeGroupInternal( eEShapeGroup, eEShapeGroup );
protected: virtual void                                       RemoveShapesInternal( void );
protected: virtual void                                       RemoveShapesInternal( eEShapeGroup );
protected: virtual void                                       RemoveShapesInternal( eECollisionShapeType );
protected: virtual void                                       RemoveShapesInternal( NxShape * );
public:    virtual void                                       OnPreTouch( eCEntity *, eCContactIterator & );
public:    virtual void                                       OnPreUntouch( eCEntity *, eCContactIterator & );
public:    virtual void                                       OnPostTouch( eCEntity *, eCContactIterator & );
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                                   PostInitializeProperties( void );
public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEInt                                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr                     GetNativePropertyAt( GEInt ) const;
public:    virtual                                           ~eCCollisionShape_PS( void );
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual GEBool                                     IsEntityListener( void ) const;
public:    virtual GEBool                                     IsPhysicRelevant( void ) const;
public:    virtual GEBool                                     IsEditorRelevant( void ) const;
public:    virtual GEBool                                     IsTriggerable( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                                       OnTrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnUntrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnExitProcessingRange( void );
public:    virtual void                                       OnRenderDebug( void );
public:    virtual void                                       RenderGizmo( eCCameraBase *, GEInt );
public:    virtual void                                       RenderAlphaGizmo( eCCameraBase *, GEInt );
public:    virtual GEBool                                     PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );
public:    virtual GEBool                                     OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );
public:    virtual void                                       GetBoundary( bCBox &, GEBool );
public:    virtual void                                       OnPostRead( void );
public:    virtual GEBool                                     IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
protected: virtual void                                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected: virtual void                                       OnUpdatedWorldTreeBoundary( void );
public:    virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
protected: virtual void                                       OnCacheIn( void );
protected: virtual void                                       OnCacheOut( void );
protected: virtual void                                       OnPrefetch( bCVector const & );
protected:
    bTPropertyContainer< eECollisionGroup >  m_Group;               // 0010
    bTPropertyContainer< eEPhysicRangeType > m_Range;               // 0018
    GEBool                                   m_bDisableCollision;   // 0020
    GEBool                                   m_bDisableResponse;    // 0021
    GEBool                                   m_bIgnoredByTraceRay;  // 0022
    GEBool                                   m_bIsUnique;           // 0023
    GEBool                                   m_bIsClimbable;        // 0024
    GEBool                                   m_bHitByProjectile;    // 0025 
                                             GE_PADDING( 2 ) 
    bTRefPtrArray< eCCollisionShape * >      m_arrShapes;           // 0028
    bTRefPtrArray< eCCollisionShape * >      m_arrTouchingShapes;   // 0034
    GEBool                                   __FIXME_0040;          // 0040 // IsRootRemoved? HasTouchingShapes?
                                             GE_PADDING1( 3 )
    eEPropertySetType                        m_enuTouchType;        // 0044
    bCString                                 m_strTouchingBone;     // 0048
protected:
    void    GetGizmoData( eCCollisionShape *, GELPVoid );
    GEFloat GetGizmoScaling( eCCameraBase * ) const;
    void    GetGizmoTrafoSpaceWorldMatrix( eCCameraBase *, eCCollisionShape *, bCMatrix & ) const;
    void    Invalidate( void );
    GEBool  IsGizmoEditingAllowed( void );
    void    OnProprietaryShapesChanged( void );
    void    SetGizmoData( eCCollisionShape *, GELPVoid );
    void    SetProprietaryShapes( void );
    void    ShrinkTouchingShapes( void );
public:
    static bCObjectBase *             CreateObject( void );
    static bCPropertyObjectTypeBase & GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                                         AccessDisableCollision( void );
    GEBool &                                         AccessDisableResponse( void );
    bTPropertyContainer< eECollisionGroup > &        AccessGroup( void );
    GEBool &                                         AccessHitByProjectile( void );
    GEBool &                                         AccessIgnoredByTraceRay( void );
    GEBool &                                         AccessIsClimbable( void );
    GEBool &                                         AccessIsUnique( void );
    bTPropertyContainer< eEPhysicRangeType > &       AccessRange( void );
    void                                             ClearTouchingShapes( void );
    void                                             EnableShapeGroupCollision( eEShapeGroup, GEBool, GEInt );
    GEBool const &                                   GetDisableCollision( void ) const;
    GEBool const &                                   GetDisableResponse( void ) const;
    bTPropertyContainer< eECollisionGroup > const &  GetGroup( void ) const;
    GEBool const &                                   GetHitByProjectile( void ) const;
    GEBool const &                                   GetIgnoredByTraceRay( void ) const;
    GEBool const &                                   GetIsClimbable( void ) const;
    GEBool const &                                   GetIsUnique( void ) const;
    GEU32                                            GetNumTouchingShapes( void ) const;
    NxShape *                                        GetProprietaryTouchingShape( GEU32 ) const;
    bTPropertyContainer< eEPhysicRangeType > const & GetRange( void ) const;
    bTRefPtrArray< eCCollisionShape * > const &      GetShapes( void ) const;
    bCString const &                                 GetTouchingBone( void ) const;
    eCCollisionShape *                               GetTouchingShapeAtIndex( GEU32 ) const;
    eEPropertySetType                                GetTouchType( void ) const;
    GEBool const                                     HasConvexMesh( void ) const;
    GEBool const                                     HasGroup( eEShapeGroup ) const;
    GEBool const                                     HasScalableMesh( void ) const;
    GEBool const                                     HasTriangleMesh( void ) const;
    GEBool                                           IsClimbable( void ) const;
    void                                             SetDisableCollision( GEBool const & );
    void                                             SetDisableResponse( GEBool const & );
    void                                             SetGroup( bTPropertyContainer< eECollisionGroup > const & );
    void                                             SetHitByProjectile( GEBool const & );
    void                                             SetIgnoredByTraceRay( GEBool const & );
    void                                             SetIsClimbable( GEBool const & );
    void                                             SetIsUnique( GEBool const & );
    void                                             SetRange( bTPropertyContainer< eEPhysicRangeType > const & );
    void                                             SetShapeGroup( eEShapeGroup, eEShapeGroup );
    void                                             SetShapes( bTRefPtrArray< eCCollisionShape * > const & );
    void                                             SetTouchingShapesDirty( void );
    GEBool                                           TraceRayFirstHit( bCRay & );
public:
    eCCollisionShape_PS & operator = ( eCCollisionShape_PS const & );
public:
    eCCollisionShape_PS( eCCollisionShape_PS const & );
    eCCollisionShape_PS( void );
};
GE_ASSERT_SIZEOF( eCCollisionShape_PS, 0x004C )

#endif