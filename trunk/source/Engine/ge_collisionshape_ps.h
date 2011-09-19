#ifndef GE_COLLISIONSHAPE_PS_H_INCLUDED
#define GE_COLLISIONSHAPE_PS_H_INCLUDED

enum eEPhysicRangeType
{
    eEPhysicRangeType_World,
    eEPhysicRangeType_ProcessingRange,
    eEPhysicRangeType_VisibilityRange,
    eEPhysicRangeType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCCollisionShape_PS'

class GE_DLLIMPORT eCCollisionShape_PS :
    public eCCollisionShapeBase_PS
{

public:    virtual bEResult                                   SetShape( bCString const &, GEBool );
public:    virtual bEResult                                   AddShape( bCString const &, GEBool );
public:    virtual bEResult                                   AddShape( eECollisionShapeType, eEShapeGroup, bCVector const &, bCVector const & );
public:    virtual GEBool                                     AddShapesFromSpeedTreePS( void );
public:    virtual GEBool                                     AddShapesFromSpeedTreeResource( eCSpeedTreeResource2 * );
public:    virtual bEResult                                   AddDynamicShape( eECollisionShapeType, eEShapeGroup, eEShapeAABBAdapt, GEFloat );
public:    virtual bEResult                                   AddPointShape( eEShapeGroup, bCVector const & );
public:    virtual bEResult                                   AddTouchingShape( eCCollisionShape * );
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
GE_DECLARE_PROPERTY_OBJECT( eCCollisionShape_PS, eCCollisionShapeBase_PS )
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
public:    virtual bEResult                                   SetShape( eCCollisionShape * );
public:    virtual bEResult                                   AddShape( eCCollisionShape * );
public:    virtual GEU32                                      GetNumShapes( void ) const;
protected: using                     eCCollisionShapeBase_PS::AddShape;
protected: using                     eCCollisionShapeBase_PS::GetShapeAtIndex;
protected: using                     eCCollisionShapeBase_PS::SetShape;
protected:
    GE_DECLARE_ENUMPROP( eECollisionGroup,  m_enumGroup,          Group )
    GE_DECLARE_ENUMPROP( eEPhysicRangeType, m_enumRange,          Range )
    GE_DECLARE_PROPERTY( GEBool,            m_bDisableCollision,  DisableCollision )
    GE_DECLARE_PROPERTY( GEBool,            m_bDisableResponse,   DisableResponse )
    GE_DECLARE_PROPERTY( GEBool,            m_bIgnoredByTraceRay, IgnoredByTraceRay )
    GE_DECLARE_PROPERTY( GEBool,            m_bIsUnique,          IsUnique )
    GE_DECLARE_PROPERTY( GEBool,            m_bIsClimbable,       IsClimbable )
    GE_DECLARE_PROPERTY( GEBool,            m_bHitByProjectile,   HitByProjectile )
    GE_PADDING( 2 )
    bTRefPtrArray< eCCollisionShape * >     m_arrShapes;
    bTRefPtrArray< eCCollisionShape * >     m_arrTouchingShapes;
    GEBool                                  m_bTouchingShapesDirty;
    GE_PADDING( 3 )
    eEPropertySetType                       m_enumTouchType;
    bCString                                m_strTouchingBone;
public:
    void                                        ClearTouchingShapes( void );
    void                                        EnableShapeGroupCollision( eEShapeGroup, GEBool, GEInt );
    GEU32                                       GetNumTouchingShapes( void ) const;
    NxShape *                                   GetProprietaryTouchingShape( GEU32 ) const;
    bTRefPtrArray< eCCollisionShape * > const & GetShapes( void ) const;
    bCString const &                            GetTouchingBone( void ) const;
    eCCollisionShape *                          GetTouchingShapeAtIndex( GEU32 ) const;
    eEPropertySetType                           GetTouchType( void ) const;
    GEBool const                                HasConvexMesh( void ) const;
    GEBool const                                HasGroup( eEShapeGroup ) const;
    GEBool const                                HasScalableMesh( void ) const;
    GEBool const                                HasTriangleMesh( void ) const;
    GEBool                                      IsClimbable( void ) const;
    void                                        SetShapeGroup( eEShapeGroup, eEShapeGroup );
    void                                        SetShapes( bTRefPtrArray< eCCollisionShape * > const & );
    void                                        SetTouchingShapesDirty( void );
    GEBool                                      TraceRayFirstHit( bCRay & );
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
};
GE_ASSERT_SIZEOF( eCCollisionShape_PS, 0x004C )

#pragma warning( pop )

#endif