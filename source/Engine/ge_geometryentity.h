#ifndef GE_GEOMETRYENTITY_H_INCLUDED
#define GE_GEOMETRYENTITY_H_INCLUDED

class GE_DLLIMPORT eCGeometryEntity :
    public eCEntity
{
public:    virtual void                   SetName( bCString const & );                                                              
public:    virtual GEBool                 HasCreator( void ) const;                                                                 
protected: virtual void                   OnPortalRoomChanged( eCEntity * );                                                        
protected: virtual void                   OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );                               
protected: virtual void                   OnUpdatedWorldTreeBoundary( void );                                                       
public:    virtual void                   SetLocalMatrix( bCMatrix const & );                                                       
public:    virtual void                   SetWorldTreeBoundary( bCBox const & );                                                    
public:    virtual bCMatrix const &       GetLocalMatrix( void ) const;                                                             
public:    virtual bCBox const &          GetLocalNodeBoundary( void ) const;                                                       
public:    virtual bCBox const &          GetWorldNodeBoundary( void ) const;                                                       
public:    virtual bCSphere const &       GetWorldNodeSphere( void ) const;                                                         
public:    virtual eCLightSet *           QueryLightSet( void );                                                                    
public:    virtual GEU16                  GetVersion( void ) const;                                                                 
public:    virtual GEBool                 OnRead( bCIStream & );                                                                    
public:    virtual GEBool                 OnWrite( bCOStream & );                                                                   
public:    virtual bEResult               Create( void );                                                                           
public:    virtual void                   Destroy( void );                                                                          
public:    virtual GEBool                 OnCopyFrom( bCObjectBase const & );                                                       
public:    virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;                                                       
protected: virtual                       ~eCGeometryEntity( void );                                                                 
public:    virtual eCGeometryEntity *     QueryGeometryEntity( void );                                                              
private:   virtual void                   OnAttachChild( eCNode * );                                                                
private:   virtual void                   OnDetachChild( eCNode * );                                                                
public:    virtual void                   Enable( GEBool );                                                                         
public:    virtual bCString const &       GetName( void ) const;                                                                    
protected: virtual void                   CopyEntityPrivateData( eCEntity const &, GEBool );                                        
public:    virtual void                   OnUpdateBoundary( void );                                                                 
protected: virtual void                   OnCacheIn( void );                                                                        
protected: virtual void                   OnCacheOut( void );                                                                       
protected: virtual void                   EnterProcessingRange( void );                                                             
protected: virtual void                   ExitProcessingRange( void );                                                              
public:    virtual void                   CacheOut( void );                                                                         
public:    virtual void                   RenderGizmo( eCCameraBase *, GEInt );                                                     
public:    virtual void                   RenderAlphaGizmo( eCCameraBase *, GEInt );                                                
public:    virtual GEBool                 PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );                           
public:    virtual GEBool                 OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );  
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
