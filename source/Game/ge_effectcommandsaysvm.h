#ifndef GE_EFFECTCOMMANDSAYSVM_H_INCLUDED
#define GE_EFFECTCOMMANDSAYSVM_H_INCLUDED

class GE_DLLIMPORT gCEffectCommandSaySVM :
    public gCEffectCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCEffectCommandSaySVM( void );
public:    virtual bCString                   GetCommandString( void ) const;
protected: virtual void                       OnStart( gSEffectCommandInstance & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEInt    m_iMaxVariationCount;
    bCString m_strSVMID;
    GEBool   m_bInDialog;
             GE_PADDING( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &         AccessInDialog( void );
    GEInt &          AccessMaxVariationCount( void );
    bCString &       AccessSVMID( void );
    GEBool const &   GetInDialog( void ) const;
    GEInt const &    GetMaxVariationCount( void ) const;
    bCString const & GetSVMID( void ) const;
    void             SetInDialog( GEBool const & );
    void             SetMaxVariationCount( GEInt const & );
    void             SetSVMID( bCString const & );
public:
    gCEffectCommandSaySVM & operator = ( gCEffectCommandSaySVM const & );
public:
    gCEffectCommandSaySVM( gCEffectCommandSaySVM const & );
    gCEffectCommandSaySVM( void );
};
GE_ASSERT_SIZEOF( gCEffectCommandSaySVM, 0x0018 )

#endif
