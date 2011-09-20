#ifndef GE_STATEGRAPHACTIONCALLSCRIPT_H_INCLUDED
#define GE_STATEGRAPHACTIONCALLSCRIPT_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionCallScript :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionCallScript, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionCallScript( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
public:    virtual void     OnEvent( gEStateGraphEventType, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_EnterScript,   EnterScript )
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_ExitScript,    ExitScript )
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_ProcessScript, ProcessScript )
    GE_DECLARE_PROPERTY( GEBool,              m_bWait,         Wait )
    GE_PADDING( 3 )
    eCEntityProxy                             m_EntityProxy;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionCallScript, 0x0048 )

#endif
