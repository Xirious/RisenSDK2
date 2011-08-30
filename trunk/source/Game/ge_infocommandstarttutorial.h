#ifndef GE_INFOCOMMANDSTARTTUTORIAL_H_INCLUDED
#define GE_INFOCOMMANDSTARTTUTORIAL_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandStartTutorial :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandStartTutorial, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strTutorialEventName,          TutorialEventName )
    GE_DECLARE_PROPERTY( GEBool,   m_bIgnoreTutorialEventCondition, IgnoreTutorialEventCondition )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandStartTutorial, 0x0010 )

#endif
