#ifndef GE_INFOCOMMANDADDNPCINFO_H_INCLUDED
#define GE_INFOCOMMANDADDNPCINFO_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandAddNPCInfo'

class GE_DLLIMPORT gCInfoCommandAddNPCInfo :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandAddNPCInfo, gCInfoCommand )
public: virtual               ~gCInfoCommandAddNPCInfo( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,           m_strNPC,         NPC )
    GE_DECLARE_ENUMPROP( gEInfoLocation,     m_enumLocation,   Location )
    GE_DECLARE_ENUMPROP( gEInfoNPCType,      m_enumType,       Type )
    GE_DECLARE_PROPERTY( gCNPCInfoLocString, m_locDescription, Description )
};
GE_ASSERT_SIZEOF( gCInfoCommandAddNPCInfo, 0x0028 )

#pragma warning( pop )

#endif
