#ifndef GE_INFOCOMMANDINFOWAIT_H_INCLUDED
#define GE_INFOCOMMANDINFOWAIT_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandInfoWait :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandInfoWait, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual gEInfoCommand  GetCommandTypeForScript( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( GEU32, m_u32Time, Time )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandInfoWait, 0x000C )

#endif
