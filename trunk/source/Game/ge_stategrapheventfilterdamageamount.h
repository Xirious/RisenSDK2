#ifndef GE_STATEGRAPHEVENTFILTERDAMAGEAMOUNT_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERDAMAGEAMOUNT_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterDamageAmount :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterDamageAmount, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterDamageAmount( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( GEInt, m_iDamageAmount, DamageAmount )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterDamageAmount, 0x000C )

#endif
