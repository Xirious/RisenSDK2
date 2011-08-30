#ifndef GE_INFOCOMMANDREMOVENPCINFO_H_INCLUDED
#define GE_INFOCOMMANDREMOVENPCINFO_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandRemoveNPCInfo'

class GE_DLLIMPORT gCInfoCommandRemoveNPCInfo :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandRemoveNPCInfo, gCInfoCommand )
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,       m_strNPC,       NPC )
    GE_DECLARE_ENUMPROP( gEInfoLocation, m_enumLocation, Location )
    GE_DECLARE_ENUMPROP( gEInfoNPCType,  m_enumType,     Type )
};
GE_ASSERT_SIZEOF( gCInfoCommandRemoveNPCInfo, 0x001C )

#pragma warning( pop )

#endif
