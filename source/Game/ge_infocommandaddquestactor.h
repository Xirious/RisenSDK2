#ifndef GE_INFOCOMMANDADDQUESTACTOR_H_INCLUDED
#define GE_INFOCOMMANDADDQUESTACTOR_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandAddQuestActor :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandAddQuestActor, gCInfoCommand )
public: virtual               ~gCInfoCommandAddQuestActor( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: virtual void           OnAttachedToInfo( gCInfo const & );
public: virtual bCString       ToString( void ) const;
public: virtual void           FromString( bCString const & );
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,     m_strQuestName, QuestName )
    GE_DECLARE_PROPERTY( gCQuestActor, m_Actor,        Actor )
};
GE_ASSERT_SIZEOF( gCInfoCommandAddQuestActor, 0x0020 )

#endif
