#ifndef GE_STATEGRAPHACTIONWAIT_H_INCLUDED
#define GE_STATEGRAPHACTIONWAIT_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionWait :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionWait, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual bEResult PostInitializeProperties( void );
public:    virtual         ~gCStateGraphActionWait( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual GEBool   OnProcess( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fWaitTime,           WaitTime )
    GE_DECLARE_PROPERTY( GEBool,  m_bWaitWhileTouching,  WaitWhileTouching )
    GE_DECLARE_PROPERTY( GEBool,  m_bWaitWhileTriggered, WaitWhileTriggered )
    GE_PADDING( 2 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionWait, 0x002C )

#endif
