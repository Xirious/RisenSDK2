#ifndef GE_INFOCOMMANDSAYKEEPITUP_H_INCLUDED
#define GE_INFOCOMMANDSAYKEEPITUP_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSayKeepItUp :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSayKeepItUp, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandSayKeepItUp( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strSpeaker,  Speaker )
    GE_DECLARE_PROPERTY( bCString, m_strListener, Listener )
    eCEntityProxy                  m_EntityProxy1;
    eCEntityProxy                  m_EntityProxy2;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSayKeepItUp, 0x0020 )

#endif
