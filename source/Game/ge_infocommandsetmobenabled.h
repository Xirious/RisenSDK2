#ifndef GE_INFOCOMMANDSETMOBENABLED_H_INCLUDED
#define GE_INFOCOMMANDSETMOBENABLED_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSetMobEnabled :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSetMobEnabled, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandSetMobEnabled( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strEntity1,  Entity1 )
    GE_DECLARE_PROPERTY( GEBool,   m_bMobEnabled, MobEnabled )
    GE_PADDING( 3 )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSetMobEnabled, 0x0018 )

#endif
