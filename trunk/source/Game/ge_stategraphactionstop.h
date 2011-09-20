#ifndef GE_STATEGRAPHACTIONSTOP_H_INCLUDED
#define GE_STATEGRAPHACTIONSTOP_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionStop :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionStop, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionStop( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fTimeOffset, TimeOffset )
    GEBool                        __FIXME_0028;
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionStop, 0x002C )

#endif
