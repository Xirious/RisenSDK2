#ifndef GE_STATEGRAPHEVENTFILTERSCRIPT_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERSCRIPT_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterScript :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterScript, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterScript( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( eCScriptProxyScript, m_Script, Script )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterScript, 0x0010 )

#endif
