#ifndef GE_STATEGRAPHEVENTFILTERISPLAYER_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERISPLAYER_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterIsPlayer :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterIsPlayer, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterIsPlayer( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterIsPlayer, 0x0008 )

#endif
