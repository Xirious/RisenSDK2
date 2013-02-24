#ifndef GE_GIZMOTRANSFORMOBB_H_INCLUDED
#define GE_GIZMOTRANSFORMOBB_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformOBB :
    public eCGizmoTransform
{
public:    virtual GEBool  Pick( bCMatrix const &, eSRayIntersectionDesc &, eSGizmoPickInfo * );
public:    virtual GEBool  OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void    RenderAlpha( bCMatrix const & );
public:    virtual void    Destroy( void );
public:    virtual GEBool  Create( void );
protected: virtual        ~eCGizmoTransformOBB( void );
public:    virtual GEBool  PickShape( bCMatrix const &, eSRayIntersectionDesc &, eCPrimitiveCollisionDesc * * );
public: using eCGizmoBase::RenderShape;
public:    virtual void    RenderShape( bCMatrix const &, GEU32 );
public:
    eCGizmoTransformOBB( eCGizmoTransformOBB const & );
public:
    eCGizmoTransformOBB & operator = ( eCGizmoTransformOBB const & );
public:
    void SetOBB( bCOrientedBox const &, GEFloat );
protected:
    static eCIteratorPrimitiveBackArea   ms_PrimitiveBackArea;
    static eCIteratorPrimitiveBottomArea ms_PrimitiveBottomArea;
    static eCIteratorPrimitiveBox        ms_PrimitiveBox;
    static eCIteratorPrimitiveFrontArea  ms_PrimitiveFrontArea;
    static eCIteratorPrimitiveLeftArea   ms_PrimitiveLeftArea;
    static eCIteratorPrimitiveRightArea  ms_PrimitiveRightArea;
    static eCIteratorPrimitiveTopArea    ms_PrimitiveTopArea;
protected:
    eCGizmoTransformOBB( void );
protected:
    void Invalidate( void );
protected:
    bCOrientedBox m_oboxOBB;
};
GE_ASSERT_SIZEOF( eCGizmoTransformOBB, 0x0098 );

#endif