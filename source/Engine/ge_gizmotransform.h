#ifndef GE_GIZMOTRANSFORM_H_INCLUDED
#define GE_GIZMOTRANSFORM_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransform :
    public eCGizmoTranslateAndScale
{
public:    virtual GEBool        OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoTransform( void );
public:
    eCGizmoTransform( eCGizmoTransform const & );
public:
    eCGizmoTransform & operator = ( eCGizmoTransform const & );
protected:
    static eCIteratorPrimitiveRotateBox ms_PrimitiveRotateXBox;
    static eCIteratorPrimitiveRotateBox ms_PrimitiveRotateYBox;
    static eCIteratorPrimitiveRotateBox ms_PrimitiveRotateZBox;
protected:
    eCGizmoTransform( void );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCGizmoTransform, 0x005C );

#endif
