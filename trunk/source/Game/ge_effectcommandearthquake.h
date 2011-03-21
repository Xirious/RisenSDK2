#ifndef GE_EFFECTCOMMANDEARTHQUAKE_H_INCLUDED
#define GE_EFFECTCOMMANDEARTHQUAKE_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandEarthquake :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandEarthquake( void );
public:    virtual bCString                   GetCommandString( void ) const;
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strCameraEffectName;
    GEFloat  m_fEffectWeight;
    GEFloat  m_fEffectDuration;
    GEFloat  m_fWarmUp;
    GEFloat  m_fCoolDown;
    GEFloat  m_fInnerRadius;
    GEFloat  m_fOuterRadius;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessCameraEffectName( void );
    GEFloat &        AccessCoolDown( void );
    GEFloat &        AccessEffectDuration( void );
    GEFloat &        AccessEffectWeight( void );
    GEFloat &        AccessInnerRadius( void );
    GEFloat &        AccessOuterRadius( void );
    GEFloat &        AccessWarmUp( void );
    bCString const & GetCameraEffectName( void ) const;
    GEFloat const &  GetCoolDown( void ) const;
    GEFloat const &  GetEffectDuration( void ) const;
    GEFloat const &  GetEffectWeight( void ) const;
    GEFloat const &  GetInnerRadius( void ) const;
    GEFloat const &  GetOuterRadius( void ) const;
    GEFloat const &  GetWarmUp( void ) const;
    void             SetCameraEffectName( bCString const & );
    void             SetCoolDown( GEFloat const & );
    void             SetEffectDuration( GEFloat const & );
    void             SetEffectWeight( GEFloat const & );
    void             SetInnerRadius( GEFloat const & );
    void             SetOuterRadius( GEFloat const & );
    void             SetWarmUp( GEFloat const & );
public:
    gCEffectCommandEarthquake & operator = ( gCEffectCommandEarthquake const & );
public:
    gCEffectCommandEarthquake( gCEffectCommandEarthquake const & );
    gCEffectCommandEarthquake( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandEarthquake, 0x0028 )

#endif
