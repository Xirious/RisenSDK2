#ifndef GE_STATEGRAPHACTIONPLAYANI_H_INCLUDED
#define GE_STATEGRAPHACTIONPLAYANI_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionPlayAni :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionPlayAni, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionPlayAni( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat,  m_fTimeOffset,     TimeOffset )
    GE_DECLARE_PROPERTY( bCString, m_strAnimation,    Animation )
    GE_DECLARE_PROPERTY( GEBool,   m_bPauseAnimation, PauseAnimation )
    GE_DECLARE_PROPERTY( GEBool,   m_bWait,           Wait )
    GE_DECLARE_PROPERTY( GEBool,   m_bStopAnimation,  StopAnimation )
    GEBool                         __FIXME_002F;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionPlayAni, 0x0030 )

#endif
