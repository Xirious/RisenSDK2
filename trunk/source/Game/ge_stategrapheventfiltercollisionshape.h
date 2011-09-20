#ifndef GE_STATEGRAPHEVENTFILTERCOLLISIONSHAPE_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERCOLLISIONSHAPE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCStateGraphEventFilterCollisionShape'

class GE_DLLIMPORT gCStateGraphEventFilterCollisionShape :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterCollisionShape, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterCollisionShape( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_ENUMPROP( eEShapeGroup,    m_enumGroup,    Group )
    GE_DECLARE_ENUMPROP( eEShapeMaterial, m_enumMaterial, Material )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterCollisionShape, 0x0018 )

#pragma warning( pop )

#endif
