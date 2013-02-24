#ifndef GE_GIZMOTRANSFORMSPHERECOLLISIONSHAPE_H_INCLUDED
#define GE_GIZMOTRANSFORMSPHERECOLLISIONSHAPE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformSphereCollisionShape :
    public eCGizmoTransformSphere
{
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoTransformSphereCollisionShape( void );
public:
    eCGizmoTransformSphereCollisionShape( eCGizmoTransformSphereCollisionShape const & );
public:
    eCGizmoTransformSphereCollisionShape & operator = ( eCGizmoTransformSphereCollisionShape const & );
public:
    void SetSphereShape( eCCollisionShape *, GEFloat );
protected:
    eCGizmoTransformSphereCollisionShape( void );
protected:
    void Invalidate( void );
protected:
    eCCollisionShape * m_pSphereShape;
};
GE_ASSERT_SIZEOF( eCGizmoTransformSphereCollisionShape, 0x0070 );

#endif