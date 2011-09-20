#ifndef GE_STATEGRAPHEVENTFILTERISENTITY_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERISENTITY_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterIsEntity :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterIsEntity, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterIsEntity( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( eCEntityProxy, m_Entity, Entity )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterIsEntity, 0x0010 )

#endif
