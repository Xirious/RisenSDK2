#ifndef GE_GIZMOTRANSFORMSPHERE_H_INCLUDED
#define GE_GIZMOTRANSFORMSPHERE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformSphere :
    public eCGizmoTransform
{
public:    virtual GEBool  Pick( bCMatrix const &, eSRayIntersectionDesc &, eSGizmoPickInfo * );
public:    virtual GEBool  OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void    RenderAlpha( bCMatrix const & );
public:    virtual void    Destroy( void );
public:    virtual GEBool  Create( void );
protected: virtual        ~eCGizmoTransformSphere( void );
public:    virtual GEBool  PickShape( bCMatrix const &, eSRayIntersectionDesc &, eCPrimitiveCollisionDesc * * );
public: using eCGizmoBase::RenderShape;
public:    virtual void    RenderShape( bCMatrix const &, GEU32 );
public:
    eCGizmoTransformSphere( eCGizmoTransformSphere const & );
public:
    eCGizmoTransformSphere & operator = ( eCGizmoTransformSphere const & );
public:
    void SetSphere( bCSphere const &, GEFloat );
protected:
    static eCIteratorPrimitiveRadiusBackArea   ms_PrimitiveRadiusBackArea;
    static eCIteratorPrimitiveRadiusBottomArea ms_PrimitiveRadiusBottomArea;
    static eCIteratorPrimitiveRadiusFrontArea  ms_PrimitiveRadiusFrontArea;
    static eCIteratorPrimitiveRadiusLeftArea   ms_PrimitiveRadiusLeftArea;
    static eCIteratorPrimitiveRadiusRightArea  ms_PrimitiveRadiusRightArea;
    static eCIteratorPrimitiveRadiusTopArea    ms_PrimitiveRadiusTopArea;
    static eCIteratorPrimitiveSphere           ms_PrimitiveSphere;
protected:
    eCGizmoTransformSphere( void );
protected:
    void Invalidate( void );
protected:
    bCSphere m_sphSphere;
};
GE_ASSERT_SIZEOF( eCGizmoTransformSphere, 0x006C );

#endif