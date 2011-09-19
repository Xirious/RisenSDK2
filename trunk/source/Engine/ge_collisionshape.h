#ifndef GE_COLLISIONSHAPE_H_INCLUDED
#define GE_COLLISIONSHAPE_H_INCLUDED

enum eECollisionShapeType
{
    eECollisionShapeType_None,
    eECollisionShapeType_TriMesh,
    eECollisionShapeType_Plane,
    eECollisionShapeType_Box,
    eECollisionShapeType_Capsule,
    eECollisionShapeType_Sphere,
    eECollisionShapeType_ConvexHull,
    eECollisionShapeType_Point,
    eECollisionShapeType_ForceDWORD = GE_FORCE_DWORD
};

enum eEShapeAABBAdapt
{
    eEShapeAABBAdapt_None,
    eEShapeAABBAdapt_LocalNode,
    eEShapeAABBAdapt_LocalTree,
    eEShapeAABBAdapt_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCCollisionShape'

class GE_DLLIMPORT eCCollisionShape :
    public bCObjectRefBase
{
GE_DECLARE_PROPERTY_OBJECT( eCCollisionShape, bCObjectRefBase )
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual GEInt                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;
protected: virtual                           ~eCCollisionShape( void );
protected:
    GE_DECLARE_ENUMPROP( eECollisionShapeType, m_enumShapeType, ShapeType )
    GE_DECLARE_ENUMPROP( eEShapeGroup,         m_enumGroup, Group )
    GE_DECLARE_ENUMPROP( eEShapeMaterial,      m_enumMaterial, Material )
    GE_DECLARE_ENUMPROP( eEShapeAABBAdapt,     m_enumShapeAABBAdaptMode, ShapeAABBAdaptMode )
    GE_DECLARE_PROPERTY( GEBool,               m_bIgnoredByTraceRay, IgnoredByTraceRay )
    GE_DECLARE_PROPERTY( GEBool,               m_bEnableCCD, EnableCCD )
    GE_DECLARE_PROPERTY( GEBool,               m_bOverrideEntityAABB, OverrideEntityAABB )
    GE_DECLARE_PROPERTY( GEBool,               m_bDisableCollision, DisableCollision )
    GE_DECLARE_PROPERTY( GEBool,               m_bDisableResponse, DisableResponse )
    GE_DECLARE_PROPERTY( GEBool,               m_bTriggersOnTouch, TriggersOnTouch )
    GE_DECLARE_PROPERTY( GEBool,               m_bTriggersOnUntouch, TriggersOnUntouch )
    GE_DECLARE_PROPERTY( GEBool,               m_bTriggersOnIntersect, TriggersOnIntersect )
    GE_DECLARE_PROPERTY( GEFloat,              m_fSkinWidth, SkinWidth )
    GE_DECLARE_PROPERTY( GEBool,               m_bIsLazyGenerated, IsLazyGenerated )
    GE_PADDING( 1 )
    GE_DECLARE_PROPERTY( GEU16,                m_u16FileVersion, FileVersion )
    GE_DECLARE_PROPERTY( GEBool,               m_bAdaptToAABB, AdaptToAABB )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,              m_fAdaptScale, AdaptScale )
    GEBool                                     m_bIsCachedIn;
    GE_PADDING( 1 )
    GEU16                                      m_u16ResourceIndex;
    bCBox                                      m_boxOuterAABBLocal;
    NxShape *                                  m_pProprietaryShape;
    NxCCDSkeleton *                            m_pCCDSkeleton;
    bCVector                                   m_vecLastPosition;
    eCCollisionShape_PS *                      m_pSourceShapePS;
    union
    {
        GELPVoid                               m_pShape;
        bCString *                             m_pShapeName;
        bCOrientedBox *                        m_pShapeBox;
        bCCapsule *                            m_pShapeCapsule;
        bCSphere *                             m_pShapeSphere;
        bCVector *                             m_pShapePoint;
    };
public:
    static GELPVoid operator new ( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );
public:
    static bCString GetMaterialName( eEShapeMaterial );
public:
    void                  DestroyShape( void );
    bCOrientedBox &       GetBox( void );
    bCOrientedBox const & GetBox( void ) const;
    bCCapsule &           GetCapsule( void );
    bCCapsule const &     GetCapsule( void ) const;
    bCVector &            GetCenter( void );
    bCVector const &      GetCenter( void ) const;
    void                  GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
    GEFloat const         GetDepth( void ) const;
    GEFloat               GetDepth( void );
    eCEntity *            GetEntity( void ) const;
    GEFloat const         GetHeight( void ) const;
    GEFloat               GetHeight( void );
    GEBool                GetIsCachedIn( void ) const;
    bCVector const &      GetLastPosition( void ) const;
    bCVector &            GetLastPosition( void );
    bCString &            GetMeshResourceName( void );
    bCString const &      GetMeshResourceName( void ) const;
    bCMatrix3 const &     GetOrientation( void ) const;
    bCMatrix3 &           GetOrientation( void );
    bCBox &               GetOuterAABBLocal( void );
    bCBox const &         GetOuterAABBLocal( void ) const;
    bCVector &            GetPoint( void );
    bCVector const &      GetPoint( void ) const;
    NxShape *             GetProprietaryShape( void ) const;
    GEU16                 GetResourceIndex( void ) const;
    bCMatrix3 const &     GetRuntimeOrientation( void ) const;
    bCMatrix3 &           GetRuntimeOrientation( void );
    eCCollisionShape_PS * GetSourceShapePS( void );
    bCSphere const &      GetSphere( void ) const;
    bCSphere &            GetSphere( void );
    GEFloat const         GetWidth( void ) const;
    GEFloat               GetWidth( void );
    GEBool                IntersectsRay( bCRay const & );
    GEBool                IsTrigger( void ) const;
    void                  SetBox( bCOrientedBox const & );
    bEResult              SetByLocalAABB( bCBox const & );
    void                  SetCapsule( bCCapsule const & );
    void                  SetCenter( bCVector const & );
    void                  SetDepth( GEFloat );
    void                  SetHeight( GEFloat );
    void                  SetIsCachedIn( GEBool );
    void                  SetLastPosition( bCVector const & );
    void                  SetMeshResourceName( bCString const & );
    void                  SetOrientation( bCMatrix3 const & );
    void                  SetPoint( bCVector const & );
    void                  SetProprietaryShape( NxShape * );
    void                  SetResourceIndex( GEU16 );
    void                  SetRuntimeOrientation( bCMatrix3 const & );
    bEResult              SetShape( bCCapsule const & );
    bEResult              SetShape( bCOrientedBox const & );
    bEResult              SetShape( bCSphere const & );
    bEResult              SetShape( bCString const &, GEU16, GEBool );
    bEResult              SetShape( bCVector const & );
    bEResult              SetShape( eCCollisionShape const & );
    bEResult              SetShapeAABBLocal( bCBox const & );
    void                  SetSourceShapePS( eCCollisionShape_PS * );
    void                  SetSphere( bCSphere const & );
    void                  SetWidth( GEFloat );
protected:
    void CalcShapeAABBLocal( void );
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCCollisionShape, 0x0078 )

#pragma warning( pop )

#endif
