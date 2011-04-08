#ifndef GE_INFOCOMMANDRUNQUEST_H_INCLUDED
#define GE_INFOCOMMANDRUNQUEST_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunQuest :
    public gCInfoCommand
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual void                       Destroy( void );
public: virtual                           ~gCInfoCommandRunQuest( void );
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
    gCInfoCommandRunQuest & operator = ( gCInfoCommandRunQuest const & );
public:
    gCInfoCommandRunQuest( gCInfoCommandRunQuest const & );
    gCInfoCommandRunQuest( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunQuest, 0x000C )

#endif
