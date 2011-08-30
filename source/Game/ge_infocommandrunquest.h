#ifndef GE_INFOCOMMANDRUNQUEST_H_INCLUDED
#define GE_INFOCOMMANDRUNQUEST_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunQuest :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandRunQuest, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strQuestName, QuestName )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunQuest, 0x000C )

#endif
