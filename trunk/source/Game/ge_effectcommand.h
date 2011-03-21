#ifndef GE_EFFECTCOMMAND_H_INCLUDED
#define GE_EFFECTCOMMAND_H_INCLUDED

class gCEffect;

struct gSEffectCommandInstance
{
    gCEffect * m_pEffect;
    void *     __FIXME_0004;
    void *     __FIXME_0008;
    void *     __FIXME_000C;  // eCAudioChannel * (gCEffectCommandPlaySound)
};
GE_ASSERT_SIZEOF( gSEffectCommandInstance, 0x0010 )

class GE_DLLIMPORT gCEffectCommand :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual void                       Destroy( void );
public:    virtual                           ~gCEffectCommand( void );
public:    virtual GEInt                      GetCommandPriority( void ) const;
public:    virtual bCString                   GetCommandString( void ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
protected: virtual void                       OnStop( gSEffectCommandInstance & ) const;
protected: virtual GEBool                     OnProcess( gSEffectCommandInstance & ) const;
public:    virtual GEBool                     Prefetch( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat m_fTimeOffset;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &       AccessTimeOffset( void );
    GEFloat const & GetTimeOffset( void ) const;
    GEBool          Process( gSEffectCommandInstance & ) const;
    void            SetTimeOffset( GEFloat const & );
    GEBool          Stop( gSEffectCommandInstance & ) const;
public:
    gCEffectCommand & operator = ( gCEffectCommand const & );
public:
    gCEffectCommand( gCEffectCommand const & );
    gCEffectCommand( void );
};
GE_ASSERT_SIZEOF( gCEffectCommand, 0x000C )

#endif
