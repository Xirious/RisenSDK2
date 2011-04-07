#ifndef GE_INFOCOMMANDCLEARGAMEEVENT_H_INCLUDED
#define GE_INFOCOMMANDCLEARGAMEEVENT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandClearGameEvent :
    public gCInfoCommand
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual void                       Destroy( void );
protected: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                           ~gCInfoCommandClearGameEvent( void );
public:    virtual gEInfoCommand              GetCommandType( void ) const;
public:    virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public:    using             bCObjectRefBase::IsValid;
public:    virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strGameEvent;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessGameEvent( void );
    bCString const & GetGameEvent( void ) const;
    void             SetGameEvent( bCString const & );
public:
    gCInfoCommandClearGameEvent & operator = ( gCInfoCommandClearGameEvent const & );
public:
    gCInfoCommandClearGameEvent( gCInfoCommandClearGameEvent const & );
    gCInfoCommandClearGameEvent( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandClearGameEvent, 0x000C )

#endif
