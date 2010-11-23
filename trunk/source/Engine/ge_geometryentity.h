#ifndef GE_GEOMETRYENTITY_H_INCLUDED
#define GE_GEOMETRYENTITY_H_INCLUDED

class GE_DLLIMPORT eCGeometryEntity :
    public eCEntity
{
public:    using                  eCNode::GetObjectType;                                                                            // [0000].0000
public:    virtual GEU16                  GetVersion( void ) const;                                                                 // [0000].0004
public:    using                  eCNode::IsValid;                                                                                  // [0000].0008
public:    using            bCObjectBase::Deserialize;                                                                              // [0000].000C
public:    using            bCObjectBase::Serialize;                                                                                // [0000].0010
public:    using            bCObjectBase::Read;                                                                                     // [0000].0014
public:    using            bCObjectBase::Write;                                                                                    // [0000].0018
protected: using            bCObjectBase::OnDeserialize;                                                                            // [0000].001C
protected: using            bCObjectBase::OnSerialize;                                                                              // [0000].0020
public:    virtual GEBool                 OnRead( bCIStream & );                                                                    // [0000].0024
public:    virtual GEBool                 OnWrite( bCOStream & );                                                                   // [0000].0028
public:    virtual bEResult               Create( void );                                                                           // [0000].002C
public:    virtual void                   Destroy( void );                                                                          // [0000].0030
public:    using            bCObjectBase::CopyFrom;                                                                                 // [0000].0034
public:    virtual GEBool                 OnCopyFrom( bCObjectBase const & );                                                       // [0000].0038
protected: using            bCObjectBase::OnCopyPatchableOnly;                                                                      // [0000].003C
public:    using         bCObjectRefBase::AddReference;                                                                             // [0000].0040
public:    using                  eCNode::ReleaseReference;                                                                         // [0000].0044
public:    using            bCObjectBase::GetReferenceCount;                                                                        // [0000].0048
public:    using            bCObjectBase::BindPOType;                                                                               // [0000].004C
public:    using            bCObjectBase::PostInitializeProperties;                                                                 // [0000].0050
public:    using            bCObjectBase::HandleDeprecatedProperty;                                                                 // [0000].0054
public:    using            bCObjectBase::NotifyPropertyValueChangedEnterEx;                                                        // [0000].0058
public:    using            bCObjectBase::NotifyPropertyValueChangedExitEx;                                                         // [0000].005C
protected: using            bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                                                      // [0000].0060
protected: using            bCObjectBase::OnNotifyPropertyValueChangedExitEx;                                                       // [0000].0064
public:    using                eCEntity::GetNativePropertyCount;                                                                   // [0000].0068
public:    virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;                                                       // [0000].006C
protected: virtual                       ~eCGeometryEntity( void );                                                                 // [0000].0070
public:    using                eCEntity::QueryEntity;                                                                              // [0000].0074
public:    virtual eCGeometryEntity *     QueryGeometryEntity( void );                                                              // [0000].0078
public:    using                  eCNode::QueryDynamicEntity;                                                                       // [0000].007C
public:    using                  eCNode::QueryTemplateEntity;                                                                      // [0000].0080
public:    using                  eCNode::GetEntityID;                                                                              // [0000].0084
protected: using                  eCNode::OnReadContent;                                                                            // [0000].0088
protected: using                eCEntity::OnParentChanged;                                                                          // [0000].008C
private:   virtual void                   OnAttachChild( eCNode * );                                                                // [0000].0090
private:   virtual void                   OnDetachChild( eCNode * );                                                                // [0000].0094
public:    using                  eCNode::UpdateParentBoundaries;                                                                   // [0000].0098
public:    using                  eCNode::UpdateChildDependencies;                                                                  // [0000].009C
protected: using                  eCNode::DoClone;                                                                                  // [0000].00A0
public:    using                eCEntity::GetID;                                                                                    // [0000].00A4
public:    virtual void                   Enable( GEBool );                                                                         // [0000].00A8
public:    using                eCEntity::EnablePicking;                                                                            // [0000].00AC
public:    using                eCEntity::IsDummy;                                                                                  // [0000].00B0
public:    using                eCEntity::SetCreator;                                                                               // [0000].00B4
public:    using                eCEntity::GetCreator;                                                                               // [0000].00B8
public:    virtual bCString const &       GetName( void ) const;                                                                    // [0000].00BC
public:    using                eCEntity::AddPropertySet;                                                                           // [0000].00C0
public:    using                eCEntity::SetPropertySets;                                                                          // [0000].00C4
public:    using                eCEntity::RemovePropertySet;                                                                        // [0000].00C8
public:    using                eCEntity::GetPropertySet;                                                                           // [0000].00CC
public:    using                eCEntity::Decay;                                                                                    // [0000].00D0
public:    using                eCEntity::IsAutoKillEnabled;                                                                        // [0000].00D4
protected: virtual void                   CopyEntityPrivateData( eCEntity const &, GEBool );                                        // [0000].00D8
public:    using                eCEntity::OnPatchWithTemplate;                                                                      // [0000].00DC
public:    virtual void                   OnUpdateBoundary( void );                                                                 // [0000].00E0
public:    using                eCEntity::Prefetch;                                                                                 // [0000].00E4
protected: virtual void                   OnCacheIn( void );                                                                        // [0000].00E8
protected: virtual void                   OnCacheOut( void );                                                                       // [0000].00EC
protected: virtual void                   EnterProcessingRange( void );                                                             // [0000].00F0
protected: virtual void                   ExitProcessingRange( void );                                                              // [0000].00F4
public:    virtual void                   CacheOut( void );                                                                         // [0000].00F8
public:    virtual void                   RenderGizmo( eCCameraBase *, GEInt );                                                     // [0000].00FC
public:    virtual void                   RenderAlphaGizmo( eCCameraBase *, GEInt );                                                // [0000].0100
public:    virtual GEBool                 PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );                           // [0000].0104
public:    virtual GEBool                 OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );  // [0000].0108
public:    virtual void                   SetName( bCString const & );                                                              // [0000].010C
public:    virtual GEBool                 HasCreator( void ) const;                                                                 // [0000].0110
protected: virtual void                   OnPortalRoomChanged( eCEntity * );                                                        // [0000].0114
protected: virtual void                   OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );                               // [0000].0118
protected: virtual void                   OnUpdatedWorldTreeBoundary( void );                                                       // [0000].011C
public:    virtual void                   SetLocalMatrix( bCMatrix const & );                                                       // [0000].0120
public:    virtual void                   SetWorldTreeBoundary( bCBox const & );                                                    // [0000].0124
public:    virtual bCMatrix const &       GetLocalMatrix( void ) const;                                                             // [0000].0128
public:    virtual bCBox const &          GetLocalNodeBoundary( void ) const;                                                       // [0000].012C
public:    virtual bCBox const &          GetWorldNodeBoundary( void ) const;                                                       // [0000].0130
public:    virtual bCSphere const &       GetWorldNodeSphere( void ) const;                                                         // [0000].0134
public:    virtual eCLightSet *           QueryLightSet( void );                                                                    // [0000].0138
private:
    eCPhysicObject *     m_pPhysicObject;         // 0030
    bCMatrix             m_matMatrix;             // 0034
    bCBox                m_boxBoundary;           // 0074
    bCSphere             m_sphSphere;             // 008C
    GEFloat              m_fRenderAlphaValue;     // 009C
    GEFloat              m_fViewRange;            // 00A0
    GEFloat              m_fCacheInRange;         // 00A4
    eCFrustumElementItem m_FrustumElementItem;    // 00A8
    eCContextBase *      m_pContext;              // 00C8
    GEU32                m_u32PrefetchSphere;     // 00CC
    // sizeof(eCGeometryEntity)                      00D0
private:
    void SetPhysicObject( eCPhysicObject * );
protected:
    bCVector const & GetLocalPosition( void ) const;
    void             GetLocalPosition( bCVector & ) const;
    bCQuaternion     GetLocalRotation( void ) const;
    void             GetLocalRotation( bCQuaternion & ) const;
    void             Invalidate( void );
    void             MoveToLocalNode( eCGeometryEntity * );
    void             SetLocalPosition( bCVector const & );
    void             SetLocalRotation( bCQuaternion const & );
public:
    void                         CreatePhysicObject( void );
    void                         DestroyPhysicObject( void );
    void                         EnableCollision( GEBool );
    void                         GetAziElev( bCVector const &, GEFloat &, GEFloat & ) const;
    GEFloat                      GetCacheInRange( void ) const;
    eCContextBase *              GetContext( void );
    eCContextBase const *        GetContext( void ) const;
    GEFloat                      GetDistanceToEntity( eCGeometryEntity const & ) const;
    GEFloat                      GetDistanceToEntity2( eCGeometryEntity const & ) const;
    eCFrustumElementItem &       GetFrustumElementItem( void );
    eCFrustumElementItem const & GetFrustumElementItem( void ) const;
    void                         GetGizmoData( void * );
    GEFloat                      GetGizmoScaling( eCCameraBase * );
    void                         GetGizmoTrafoSpaceWorldMatrix( eCCameraBase *, bCMatrix & );
    eCPhysicObject *             GetPhysicObject( void );
    eCPhysicObject const *       GetPhysicObject( void ) const;
    GEU32                        GetPrefetchSphere( void ) const;
    GEFloat                      GetRenderAlphaValue( void ) const;
    GEFloat                      GetUniformScaling( void ) const;
    GEFloat                      GetViewRange( void ) const;
    bCMatrix const &             GetWorldMatrix( void ) const;
    bCVector const &             GetWorldPosition( void ) const;
    void                         GetWorldPosition( bCVector & ) const;
    bCQuaternion                 GetWorldRotation( void ) const;
    void                         GetWorldRotation( bCQuaternion & ) const;
    bCBox const &                GetWorldTreeBoundary( void ) const;
    bCSphere const &             GetWorldTreeSphere( void ) const;
    GEBool                       IsFreeLOS( eCGeometryEntity *, GEBool ) const;
    GEBool                       IsInContext( void ) const;
    void                         MoveToWorldNode( eCGeometryEntity * );
    void                         PrintDebug( void );
    void                         RenderBoundingBox( GEU32, GEBool, GEBool );
    void                         RenderCoordinateAxes( GEFloat, GEBool, GEBool, GEBool );
    void                         RenderTranslationAxes( GEFloat, GEBool, GEBool, GEBool );
    void                         SetCacheInRange( GEFloat );
    void                         SetContext( eCContextBase * );
    void                         SetGizmoData( void * );
    void                         SetPrefetchSphere( GEU32 );
    void                         SetRenderAlphaValue( GEFloat );
    void                         SetToWorldMatrix( bCMatrix const & );
    void                         SetViewRange( GEFloat );
    void                         SetWorldMatrix( bCMatrix const & );
    void                         SetWorldPosition( bCVector const & );
protected:
    eCGeometryEntity const & operator = ( eCGeometryEntity const & );
protected:
    eCGeometryEntity( eCGeometryEntity const & );
    eCGeometryEntity( void );
};

#endif
