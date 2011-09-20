#ifndef GE_STATEGRAPHEVENTFILTER_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTER_H_INCLUDED

enum gEStateGraphEventType
{
    gEStateGraphEventType_None,
    gEStateGraphEventType_Trigger,
    gEStateGraphEventType_Untrigger,
    gEStateGraphEventType_Touch,
    gEStateGraphEventType_Untouch,
    gEStateGraphEventType_Damage,
    gEStateGraphEventType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCStateGraphEventFilter :
    public bCObjectRefBase
{
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilter, bCObjectRefBase )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilter( void );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilter, 0x0008 )

#endif
