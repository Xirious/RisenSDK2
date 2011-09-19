#ifndef GE_INFOCOMMANDCLOSEQUEST_H_INCLUDED
#define GE_INFOCOMMANDCLOSEQUEST_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandCloseQuest :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandCloseQuest, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoCommandCloseQuest( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strQuestName, QuestName )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandCloseQuest, 0x000C )

#endif
