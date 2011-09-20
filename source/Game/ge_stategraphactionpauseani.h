#ifndef GE_STATEGRAPHACTIONPAUSEANI_H_INCLUDED
#define GE_STATEGRAPHACTIONPAUSEANI_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionPauseAni :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionPauseAni, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionPauseAni( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat,  m_fTimeOffset,  TimeOffset )
    GE_DECLARE_PROPERTY( bCString, m_strAnimation, Animation )
    GE_DECLARE_PROPERTY( GEBool,   m_bPause,       Pause )
    GEBool                         __FIXME_002D;
    GE_PADDING( 2 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionPauseAni, 0x0030 )

#endif
