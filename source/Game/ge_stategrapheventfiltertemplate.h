#ifndef GE_STATEGRAPHEVENTFILTERTEMPLATE_H_INCLUDED
#define GE_STATEGRAPHEVENTFILTERTEMPLATE_H_INCLUDED

class GE_DLLIMPORT gCStateGraphEventFilterTemplate :
    public gCStateGraphEventFilter
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphEventFilterTemplate, gCStateGraphEventFilter )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphEventFilterTemplate( void );
public:    virtual GEBool   FilterEvent( gEStateGraphEventType, eCEntity *, eCEntity *, GELPVoid );
protected:
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_CreatorTemplate, CreatorTemplate )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphEventFilterTemplate, 0x000C )

#endif
