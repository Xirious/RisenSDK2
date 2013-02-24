#ifndef GE_GIZMOTRANSFORMCAPSULECOLLISIONSHAPE_H_INCLUDED
#define GE_GIZMOTRANSFORMCAPSULECOLLISIONSHAPE_H_INCLUDED

class GE_DLLIMPORT eCGizmoTransformCapsuleCollisionShape :
    public eCGizmoTransformCapsule
{
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoTransformCapsuleCollisionShape( void );
public:
    eCGizmoTransformCapsuleCollisionShape( eCGizmoTransformCapsuleCollisionShape const & );
public:
    eCGizmoTransformCapsuleCollisionShape & operator = ( eCGizmoTransformCapsuleCollisionShape const & );
public:
    void SetCapsuleShape( eCCollisionShape *, GEFloat );
protected:
    eCGizmoTransformCapsuleCollisionShape( void );
protected:
    void Invalidate( void );
protected:
    eCCollisionShape * m_pCapsuleShape;
};
GE_ASSERT_SIZEOF( eCGizmoTransformCapsuleCollisionShape, 0x0098 );

#endif