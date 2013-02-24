#ifndef GE_GIZMOTRANSLATEANDSCALE_H_INCLUDED
#define GE_GIZMOTRANSLATEANDSCALE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTranslateAndScale :
    public eCGizmoBase
{
public:    virtual GEBool        OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoTranslateAndScale( void );
public:    virtual void          SetLocalData( bCMatrix const & );
public:    virtual void          GetLocalData( bCMatrix & );
public:
    eCGizmoTranslateAndScale( eCGizmoTranslateAndScale const & );
public:
    eCGizmoTranslateAndScale & operator = ( eCGizmoTranslateAndScale const & );
protected:
    static eCIteratorPrimitiveMoveEdge  ms_PrimitiveMoveEdgeXY;
    static eCIteratorPrimitiveMoveEdge  ms_PrimitiveMoveEdgeXZ;
    static eCIteratorPrimitiveMoveEdge  ms_PrimitiveMoveEdgeYZ;
    static eCIteratorPrimitiveMoveArrow ms_PrimitiveMoveXArrow;
    static eCIteratorPrimitiveMoveLine  ms_PrimitiveMoveXLine;
    static eCIteratorPrimitiveMoveArrow ms_PrimitiveMoveYArrow;
    static eCIteratorPrimitiveMoveLine  ms_PrimitiveMoveYLine;
    static eCIteratorPrimitiveMoveArrow ms_PrimitiveMoveZArrow;
    static eCIteratorPrimitiveMoveLine  ms_PrimitiveMoveZLine;
    static eCIteratorPrimitiveScale     ms_PrimitiveScale;
protected:
    eCGizmoTranslateAndScale( void );
protected:
    void Invalidate( void );
protected:
    bCMatrix m_matTransform;
    bCVector m_vecScaling;
};
GE_ASSERT_SIZEOF( eCGizmoTranslateAndScale, 0x005C );

#endif
