#ifndef GE_GIZMOTRANSFORMOBBCOLLISIONSHAPE_H_INCLUDED
#define GE_GIZMOTRANSFORMOBBCOLLISIONSHAPE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformOBBCollisionShape :
    public eCGizmoTransformOBB
{
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoTransformOBBCollisionShape( void );
public:
    eCGizmoTransformOBBCollisionShape( eCGizmoTransformOBBCollisionShape const & );
public:
    eCGizmoTransformOBBCollisionShape & operator = ( eCGizmoTransformOBBCollisionShape const & );
public:
    void SetOBBShape( eCCollisionShape *, GEFloat );
protected:
    eCGizmoTransformOBBCollisionShape( void );
protected:
    void Invalidate( void );
protected:
    eCCollisionShape * m_pOBBShape;
};
GE_ASSERT_SIZEOF( eCGizmoTransformOBBCollisionShape, 0x009C );

#endif