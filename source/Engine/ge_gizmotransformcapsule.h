#ifndef GE_GIZMOTRANSFORMCAPSULE_H_INCLUDED
#define GE_GIZMOTRANSFORMCAPSULE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformCapsule :
    public eCGizmoTransform
{
public:    virtual GEBool  Pick( bCMatrix const &, eSRayIntersectionDesc &, eSGizmoPickInfo * );
public:    virtual GEBool  OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void    RenderAlpha( bCMatrix const & );
public:    virtual void    Destroy( void );
public:    virtual GEBool  Create( void );
protected: virtual        ~eCGizmoTransformCapsule( void );
public:    virtual GEBool  PickShape( bCMatrix const &, eSRayIntersectionDesc &, eCPrimitiveCollisionDesc * * );
public: using eCGizmoBase::RenderShape;
public:    virtual void    RenderShape( bCMatrix const &, GEU32 );
public:
    eCGizmoTransformCapsule( eCGizmoTransformCapsule const & );
public:
    eCGizmoTransformCapsule & operator = ( eCGizmoTransformCapsule const & );
public:
    void SetCapsule( bCCapsule const &, GEFloat );
protected:
    static eCIteratorPrimitiveBottomArea      ms_PrimitiveBottomArea;
    static eCIteratorPrimitiveCapsuleCap      ms_PrimitiveCapsuleCapBottom;
    static eCIteratorPrimitiveCapsuleCap      ms_PrimitiveCapsuleCapTop;
    static eCIteratorPrimitiveCapsuleCylinder ms_PrimitiveCapsuleCylinder;
    static eCIteratorPrimitiveRadiusArea      ms_PrimitiveRadiusArea;
    static eCIteratorPrimitiveTopArea         ms_PrimitiveTopArea;
protected:
    eCGizmoTransformCapsule( void );
protected:
    void Invalidate( void );
protected:
    bCCapsule m_cpsCapsule;
};
GE_ASSERT_SIZEOF( eCGizmoTransformCapsule, 0x0094 );

#endif