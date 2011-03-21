#ifndef GE_EFFECTCOMMANDSTARTIMAGEEFFECT_H_INCLUDED
#define GE_EFFECTCOMMANDSTARTIMAGEEFFECT_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandStartImageEffect :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual void                       Destroy( void );
public:    virtual                           ~gCEffectCommandStartImageEffect( void );
public:    virtual bCString                   GetCommandString( void ) const;
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
protected: virtual void                       OnStop( gSEffectCommandInstance & ) const;
protected: virtual GEBool                     OnProcess( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strImageEffect;
    GEFloat  m_fDuration;
    GEFloat  m_fBlendInTime;
    GEFloat  m_fBlendOutTime;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &        AccessBlendInTime( void );
    GEFloat &        AccessBlendOutTime( void );
    GEFloat &        AccessDuration( void );
    bCString &       AccessImageEffect( void );
    GEFloat const &  GetBlendInTime( void ) const;
    GEFloat const &  GetBlendOutTime( void ) const;
    GEFloat const &  GetDuration( void) const;
    bCString const & GetImageEffect( void ) const;
    void             SetBlendInTime( GEFloat const & );
    void             SetBlendOutTime( GEFloat const & );
    void             SetDuration( GEFloat const & );
    void             SetImageEffect( bCString const & );
public:
    gCEffectCommandStartImageEffect & operator = ( gCEffectCommandStartImageEffect const & );
public:
    gCEffectCommandStartImageEffect( gCEffectCommandStartImageEffect const & );
    gCEffectCommandStartImageEffect( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandStartImageEffect, 0x001C )

#endif
