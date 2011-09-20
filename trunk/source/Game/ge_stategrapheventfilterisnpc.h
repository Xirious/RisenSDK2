#ifndef GE_STATEGRAPHEVENTFILTERISNPC_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERISNPC_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterIsNPC :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterIsNPC, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterIsNPC( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterIsNPC, 0x0008 )

#endif
