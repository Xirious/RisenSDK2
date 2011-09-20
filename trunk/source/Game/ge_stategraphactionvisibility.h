#ifndef GE_STATEGRAPHACTIONVISIBILITY_H_INCLUDED
#define GE_STATEGRAPHACTIONVISIBILITY_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionVisibility :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionVisibility, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionVisibility( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fTimeOffset, TimeOffset )
    GE_DECLARE_PROPERTY( GEFloat, m_fAlpha,      Alpha )
    GE_DECLARE_PROPERTY( GEFloat, m_fFadeTime,   FadeTime )
    GEFloat                       __FIXME_0030;
    GEFloat                       __FIXME_0034;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionVisibility, 0x0038 )

#endif
