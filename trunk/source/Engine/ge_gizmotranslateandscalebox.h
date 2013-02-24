#ifndef GE_GIZMOTRANSLATEANDSCALEBOX_H_INCLUDED
#define GE_GIZMOTRANSLATEANDSCALEBOX_H_INCLUDED

class GE_DLLIMPORT eCGizmoTranslateAndScaleBox :
    public eCGizmoTranslateAndScale
{
public:    virtual GEBool  Pick( bCMatrix const &, eSRayIntersectionDesc &, eSGizmoPickInfo * );
public:    virtual GEBool  OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void    RenderAlpha( bCMatrix const & );
public:    virtual void    Destroy( void );
public:    virtual GEBool  Create( void );
protected: virtual        ~eCGizmoTranslateAndScaleBox( void );
public: using eCGizmoBase::RenderShape;
public:    virtual void    RenderShape( bCMatrix const &, GEU32 );
public:
    eCGizmoTranslateAndScaleBox( eCGizmoTranslateAndScaleBox const & );
public:
    eCGizmoTranslateAndScaleBox & operator = ( eCGizmoTranslateAndScaleBox const & );
public:
    void SetBox( bCBox const &, GEFloat );
protected:
    static eCIteratorPrimitiveBackArea   ms_PrimitiveBackArea;
    static eCIteratorPrimitiveBottomArea ms_PrimitiveBottomArea;
    static eCIteratorPrimitiveBox        ms_PrimitiveBox;
    static eCIteratorPrimitiveFrontArea  ms_PrimitiveFrontArea;
    static eCIteratorPrimitiveLeftArea   ms_PrimitiveLeftArea;
    static eCIteratorPrimitiveRightArea  ms_PrimitiveRightArea;
    static eCIteratorPrimitiveTopArea    ms_PrimitiveTopArea;
protected:
    eCGizmoTranslateAndScaleBox( void );
protected:
    void Invalidate( void );
protected:
    bCBox m_boxBox;
};
GE_ASSERT_SIZEOF( eCGizmoTranslateAndScaleBox, 0x74 );

#endif