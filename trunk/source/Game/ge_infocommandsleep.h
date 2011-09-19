#ifndef GE_INFOCOMMANDSLEEP_H_INCLUDED
#define GE_INFOCOMMANDSLEEP_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSleep :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSleep, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandSleep( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strEntity1,    Entity1 )
    GE_DECLARE_PROPERTY( GEU32,    m_u32TargetHour, TargetHour )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSleep, 0x0018 )

#endif
