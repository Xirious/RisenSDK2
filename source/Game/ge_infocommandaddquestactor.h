#ifndef GE_INFOCOMMANDADDQUESTACTOR_H_INCLUDED
#define GE_INFOCOMMANDADDQUESTACTOR_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAddQuestActor :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCInfoCommandAddQuestActor( void );
public: virtual gEInfoCommand              GetCommandType( void ) const;
public: virtual GEBool                     Execute( gCRuntimeInfo &, GEBool );
public: using             bCObjectRefBase::IsValid;
public: virtual GEBool                     IsValid( bCString &, gCInfo const & ) const;
public: virtual void                       OnAttachedToInfo( gCInfo const & );
public: virtual bCString                   ToString( void ) const;
public: virtual void                       FromString( bCString const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString     m_strQuestName;
    gCQuestActor m_Actor;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCQuestActor &       AccessActor( void );
    bCString &           AccessQuestName( void );
    gCQuestActor const & GetActor( void ) const;
    bCString const &     GetQuestName( void ) const;
    void                 SetActor( gCQuestActor const & );
    void                 SetQuestName( bCString const & );
public:
    gCInfoCommandAddQuestActor & operator = ( gCInfoCommandAddQuestActor const & );
public:
    gCInfoCommandAddQuestActor( gCInfoCommandAddQuestActor const & );
    gCInfoCommandAddQuestActor( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandAddQuestActor, 0x0020 )

#endif
