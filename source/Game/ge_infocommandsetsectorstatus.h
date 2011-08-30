#ifndef GE_INFOCOMMANDSETSECTORSTATUS_H_INCLUDED
#define GE_INFOCOMMANDSETSECTORSTATUS_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSetSectorStatus :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSetSectorStatus, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual gEInfoCommand  GetCommandTypeForScript( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strSectorName,  SectorName )
    GE_DECLARE_PROPERTY( GEBool,   m_bSectorEnabled, SectorEnabled )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSetSectorStatus, 0x0010 )

#endif
