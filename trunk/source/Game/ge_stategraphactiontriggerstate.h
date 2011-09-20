#ifndef GE_STATEGRAPHACTIONTRIGGERSTATE_H_INCLUDED
#define GE_STATEGRAPHACTIONTRIGGERSTATE_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionTriggerState :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionTriggerState, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual bEResult PostInitializeProperties( void );
public:    virtual         ~gCStateGraphActionTriggerState( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat,  m_fTimeOffset,                TimeOffset )
    GE_DECLARE_PROPERTY( GEI32,    m_i32TriggerStateTargetIndex, TriggerStateTargetIndex )
    GE_DECLARE_PROPERTY( bCString, m_strTriggerStateName,        TriggerStateName )
    GEBool                         __FIXME_0030;
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
    void TriggerState( eCDynamicEntity * );
};
GE_ASSERT_SIZEOF( gCStateGraphActionTriggerState, 0x0034 )

#endif
