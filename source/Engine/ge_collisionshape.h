#ifndef GE_COLLISIONSHAPE_H_INCLUDED
#define GE_COLLISIONSHAPE_H_INCLUDED

class NxShape;              // forward
class NxCCDSkeleton;        // forward
class eCCollisionShape_PS;  // forward

enum eECollisionShapeType
{
    eECollisionShapeType_Box        = 0x00000003,
    eECollisionShapeType_TriMesh    = 0x00000001,
    eECollisionShapeType_ConvexHull = 0x00000006,
    eECollisionShapeType_None       = 0x00000000,
    eECollisionShapeType_Plane      = 0x00000002,
    eECollisionShapeType_Capsule    = 0x00000004,
    eECollisionShapeType_Sphere     = 0x00000005,
    eECollisionShapeType_Point      = 0x00000007,
    eECollisionShapeType_ForceDWORD = GE_FORCE_DWORD
};

enum eEShapeAABBAdapt
{
    eEShapeAABBAdapt_None       = 0x00000000,
    eEShapeAABBAdapt_LocalNode  = 0x00000001,
    eEShapeAABBAdapt_LocalTree  = 0x00000002,
    eEShapeAABBAdapt_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT eCCollisionShape :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
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
    bTPropertyContainer< eECollisionShapeType > m_ShapeAABBAdaptMode;    // 0008
    bTPropertyContainer< eEShapeGroup >         m_Group;                 // 0010
    bTPropertyContainer< eEShapeMaterial >      m_Material;              // 0018
    bTPropertyContainer< eEShapeAABBAdapt >     m_ShapeType;             // 0020
    GEBool                                      m_bIgnoredByTraceRay;    // 0028
    GEBool                                      m_bEnableCCD;            // 0029
    GEBool                                      m_bOverrideEntityAABB;   // 002A
    GEBool                                      m_bDisableCollision;     // 002B
    GEBool                                      m_bDisableResponse;      // 002C
    GEBool                                      m_bTriggersOnTouch;      // 002D
    GEBool                                      m_bTriggersOnUntouch;    // 002E
    GEBool                                      m_bTriggersOnIntersect;  // 002F
    GEFloat                                     m_fSkinWidth;            // 0030
    GEBool                                      m_bIsLazyGenerated;      // 0034
                                                GE_PADDING( 1 )
    GEU16                                       m_u16FileVersion;        // 0036
    GEBool                                      m_bAdaptToAABB;          // 0038
                                                GE_PADDING1( 3 )
    GEFloat                                     m_fAdaptScale;           // 003C
    GEBool                                      m_bIsCachedIn;           // 0040
                                                GE_PADDING2( 1 )
    GEU16                                       m_u16ResourceIndex;      // 0042
    bCBox                                       m_boxOuterAABBLocal;     // 0044
    NxShape *                                   m_pProprietaryShape;     // 005C
    NxCCDSkeleton *                             m_pCCDSkeleton;          // 0060
    bCVector                                    m_vecLastPosition;       // 0064
    eCCollisionShape_PS *                       m_pSourceShapePS;        // 0070
    GELPVoid                                    m_pShape;                // 0074
    // m_pShape can be of type bCString *, bCOrientedBox *, bCSphere *, bCCapsule * or bCVector *.
protected:
    void CalcShapeAABBLocal( void );
    void Invalidate( void );
public:
    static bCObjectBase *             CreateObject( void );
    static bCString                   GetMaterialName( eEShapeMaterial );
    static bCPropertyObjectTypeBase & GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                                           AccessAdaptScale( void );
    GEBool &                                            AccessAdaptToAABB( void );
    GEBool &                                            AccessDisableCollision( void );
    GEBool &                                            AccessDisableResponse( void );
    GEBool &                                            AccessEnableCCD( void );
    GEU16 &                                             AccessFileVersion( void );
    bTPropertyContainer< eEShapeGroup > &               AccessGroup( void );
    GEBool &                                            AccessIgnoredByTraceRay( void );
    GEBool &                                            AccessIsLazyGenerated( void );
    bTPropertyContainer< eEShapeMaterial > &            AccessMaterial( void );
    GEBool &                                            AccessOverrideEntityAABB( void );
    bTPropertyContainer< eEShapeAABBAdapt > &           AccessShapeAABBAdaptMode( void );
    bTPropertyContainer< eECollisionShapeType > &       AccessShapeType( void );
    GEFloat &                                           AccessSkinWidth( void );
    GEBool &                                            AccessTriggersOnIntersect( void );
    GEBool &                                            AccessTriggersOnTouch( void );
    GEBool &                                            AccessTriggersOnUntouch( void );
    void                                                DestroyShape( void );
    GEFloat const &                                     GetAdaptScale( void ) const;
    GEBool const &                                      GetAdaptToAABB( void ) const;
    bCOrientedBox &                                     GetBox( void );
    bCOrientedBox const &                               GetBox( void ) const;
    bCCapsule &                                         GetCapsule( void );
    bCCapsule const &                                   GetCapsule( void ) const;
    bCVector &                                          GetCenter( void );
    bCVector const &                                    GetCenter( void ) const;
    void                                                GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
    GEFloat const                                       GetDepth( void ) const;
    GEFloat                                             GetDepth( void );
    GEBool const &                                      GetDisableCollision( void ) const;
    GEBool const &                                      GetDisableResponse( void ) const;
    GEBool const &                                      GetEnableCCD( void ) const;
    eCEntity *                                          GetEntity( void ) const;
    GEU16 const &                                       GetFileVersion( void ) const;
    bTPropertyContainer< eEShapeGroup > const &         GetGroup( void ) const;
    GEFloat const                                       GetHeight( void ) const;
    GEFloat                                             GetHeight( void );
    GEBool const &                                      GetIgnoredByTraceRay( void ) const;
    GEBool                                              GetIsCachedIn( void ) const;
    GEBool const &                                      GetIsLazyGenerated( void ) const;
    bCVector const &                                    GetLastPosition( void ) const;
    bCVector &                                          GetLastPosition( void );
    bTPropertyContainer< eEShapeMaterial > const &      GetMaterial( void ) const;
    bCString &                                          GetMeshResourceName( void );
    bCString const &                                    GetMeshResourceName( void ) const;
    bCMatrix3 const &                                   GetOrientation( void ) const;
    bCMatrix3 &                                         GetOrientation( void );
    bCBox &                                             GetOuterAABBLocal( void );
    bCBox const &                                       GetOuterAABBLocal( void ) const;
    GEBool const &                                      GetOverrideEntityAABB( void ) const;
    bCVector &                                          GetPoint( void );
    bCVector const &                                    GetPoint( void ) const;
    NxShape *                                           GetProprietaryShape( void ) const;
    GEU16                                               GetResourceIndex( void ) const;
    bCMatrix3 const &                                   GetRuntimeOrientation( void ) const;
    bCMatrix3 &                                         GetRuntimeOrientation( void );
    bTPropertyContainer< eEShapeAABBAdapt > const &     GetShapeAABBAdaptMode( void ) const;
    bTPropertyContainer< eECollisionShapeType > const & GetShapeType( void ) const;
    GEFloat const &                                     GetSkinWidth( void ) const;
    eCCollisionShape_PS *                               GetSourceShapePS( void );
    bCSphere const &                                    GetSphere( void ) const;
    bCSphere &                                          GetSphere( void );
    GEBool const &                                      GetTriggersOnIntersect( void ) const;
    GEBool const &                                      GetTriggersOnTouch( void ) const;
    GEBool const &                                      GetTriggersOnUntouch( void ) const;
    GEFloat const                                       GetWidth( void ) const;
    GEFloat                                             GetWidth( void );
    GEBool                                              IntersectsRay( bCRay const & );
    GEBool                                              IsTrigger( void ) const;
    void                                                SetAdaptScale( GEFloat const & );
    void                                                SetAdaptToAABB( GEBool const & );
    void                                                SetBox( bCOrientedBox const & );
    bEResult                                            SetByLocalAABB( bCBox const & );
    void                                                SetCapsule( bCCapsule const & );
    void                                                SetCenter( bCVector const & );
    void                                                SetDepth( GEFloat );
    void                                                SetDisableCollision( GEBool const & );
    void                                                SetDisableResponse( GEBool const & );
    void                                                SetEnableCCD( GEBool const & );
    void                                                SetFileVersion( GEU16 const & );
    void                                                SetGroup( bTPropertyContainer< eEShapeGroup > const & );
    void                                                SetHeight( GEFloat );
    void                                                SetIgnoredByTraceRay( GEBool const & );
    void                                                SetIsCachedIn( GEBool );
    void                                                SetIsLazyGenerated( GEBool const & );
    void                                                SetLastPosition( bCVector const & );
    void                                                SetMaterial( bTPropertyContainer< eEShapeMaterial > const & );
    void                                                SetMeshResourceName( bCString const & );
    void                                                SetOrientation( bCMatrix3 const & );
    void                                                SetOverrideEntityAABB( GEBool const & );
    void                                                SetPoint( bCVector const & );
    void                                                SetProprietaryShape( NxShape * );
    void                                                SetResourceIndex( GEU16 );
    void                                                SetRuntimeOrientation( bCMatrix3 const & );
    bEResult                                            SetShape( bCCapsule const & );
    bEResult                                            SetShape( bCOrientedBox const & );
    bEResult                                            SetShape( bCSphere const & );
    bEResult                                            SetShape( bCString const &, GEU16, GEBool );
    bEResult                                            SetShape( bCVector const & );
    bEResult                                            SetShape( eCCollisionShape const & );
    void                                                SetShapeAABBAdaptMode( bTPropertyContainer< eEShapeAABBAdapt > const & );
    bEResult                                            SetShapeAABBLocal( bCBox const & );
    void                                                SetShapeType( bTPropertyContainer< eECollisionShapeType > const & );
    void                                                SetSkinWidth( GEFloat const & );
    void                                                SetSourceShapePS( eCCollisionShape_PS * );
    void                                                SetSphere( bCSphere const & );
    void                                                SetTriggersOnIntersect( GEBool const & );
    void                                                SetTriggersOnTouch( GEBool const & );
    void                                                SetTriggersOnUntouch( GEBool const & );
    void                                                SetWidth( GEFloat );
public:
    static GELPVoid operator new ( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );
public:
    eCCollisionShape & operator = ( eCCollisionShape const & );
public:
    eCCollisionShape( eCCollisionShape const & );
    eCCollisionShape( void );
};
GE_ASSERT_SIZEOF( eCCollisionShape, 0x0078 )
    
#endif
