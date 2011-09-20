#ifndef GE_STATEGRAPHACTIONTRIGGER_H_INCLUDED
#define GE_STATEGRAPHACTIONTRIGGER_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionTrigger :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionTrigger, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual bEResult PostInitializeProperties( void );
public:    virtual         ~gCStateGraphActionTrigger( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fTimeOffset,           TimeOffset )
    GE_DECLARE_PROPERTY( GEI32,   m_i32TriggerTargetIndex, TriggerTargetIndex )
    GE_DECLARE_PROPERTY( GEBool,  m_bUnTriggerOnExit,      UnTriggerOnExit )
    GEBool                        __FIXME_002D;
    GE_PADDING( 2 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionTrigger, 0x0030 )

#endif
