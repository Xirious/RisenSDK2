#ifndef GE_INFOCOMMANDSAYSOUND_H_INCLUDED
#define GE_INFOCOMMANDSAYSOUND_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSaySound :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSaySound, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strSpeaker,   Speaker )
    GE_DECLARE_PROPERTY( bCString, m_strSoundName, SoundName )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSaySound, 0x0018 )

#endif
