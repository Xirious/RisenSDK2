#ifndef GE_INFOCOMMANDRUNINFO_H_INCLUDED
#define GE_INFOCOMMANDRUNINFO_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandRunInfo :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandRunInfo, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strInfo, Info )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandRunInfo, 0x000C )

#endif
