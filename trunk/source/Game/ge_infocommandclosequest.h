#ifndef GE_INFOCOMMANDCLOSEQUEST_H_INCLUDED
#define GE_INFOCOMMANDCLOSEQUEST_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandCloseQuest :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandCloseQuest( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strQuestName;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessQuestName( void );
    bCString const & GetQuestName( void ) const;
    void             SetQuestName( bCString const & );
public:
    gCInfoCommandCloseQuest & operator = ( gCInfoCommandCloseQuest const & );
public:
    gCInfoCommandCloseQuest( gCInfoCommandCloseQuest const & );
    gCInfoCommandCloseQuest( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandCloseQuest, 0x000C )

#endif
