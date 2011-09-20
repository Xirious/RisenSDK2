#ifndef GE_STATEGRAPHACTIONSTARTEFFECT_H_INCLUDED
#define GE_STATEGRAPHACTIONSTARTEFFECT_H_INCLUDED

class GE_DLLIMPORT gCStateGraphActionStartEffect :
    public gCStateGraphAction
{
GE_DECLARE_PROPERTY_OBJECT( gCStateGraphActionStartEffect, gCStateGraphAction )
public:    virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~gCStateGraphActionStartEffect( void );
public:    virtual void     GetDescription( bCString & ) const;
public:    virtual void     GetActionDescription( bCString & ) const;
public:    virtual void     OnEnter( void );
public:    virtual GEBool   OnProcess( void );
public:    virtual void     OnExit( void );
public:    virtual void     GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected:
    GE_DECLARE_PROPERTY( GEFloat,  m_fTimeOffset, TimeOffset )
    GE_DECLARE_PROPERTY( bCString, m_strEffect,   Effect )
    GE_DECLARE_PROPERTY( GEBool,   m_bStopEffect, StopEffect )
    GE_DECLARE_PROPERTY( GEBool,   m_bWait,       Wait )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( bCVector, m_vecOffset,   Offset )
    GEBool                         __FIXME_003C;
    GE_PADDING( 3 )
    GELPVoid                       m_pEffect;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraphActionStartEffect, 0x0044 )

#endif
