#ifndef GE_STATEGRAPHACTIONEVENTDISPATCHER_H_INCLUDED
#define GE_STATEGRAPHACTIONEVENTDISPATCHER_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionEventDispatcher :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionEventDispatcher, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual bEResult PostInitializeProperties( void );
public:    virtual         ~gCStateGraphActionEventDispatcher( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
protected: virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
public:    virtual void     OnEnter( void );
public:    virtual void     OnEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( GEI32,  m_i32TriggerTargetIndex, TriggerTargetIndex )
    GE_DECLARE_PROPERTY( GEBool, m_bDispatchEventSource,  DispatchEventSource )
    GE_PADDING( 3 )
protected:
    void DispatchEvent( eCDynamicEntity *, gEStateGraphEventType, eCEntity *, GELPVoid );
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionEventDispatcher, 0x002C )

#endif
