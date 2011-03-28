#ifndef GE_INFOCOMMANDADDLOGTEXT_H_INCLUDED
#define GE_INFOCOMMANDADDLOGTEXT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAddLogText :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandAddLogText( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual void                       GetTableKeys( bTObjArray< bCString> & );
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCInfoLocString m_locText;
    bCString        m_strQuestName;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &              AccessQuestName( void );
    gCInfoLocString &       AccessText( void );
    bCString const &        GetQuestName( void ) const;
    gCInfoLocString const & GetText( void ) const;
    void                    SetQuestName( bCString const & );
    void                    SetText( gCInfoLocString const & );
public:
    gCInfoCommandAddLogText & operator = ( gCInfoCommandAddLogText const & );
public:
    gCInfoCommandAddLogText( gCInfoCommandAddLogText const & );
    gCInfoCommandAddLogText( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAddLogText, 0x0018 )

#endif

