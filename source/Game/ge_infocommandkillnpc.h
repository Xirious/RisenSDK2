#ifndef GE_INFOCOMMANDKILLNPC_H_INCLUDED
#define GE_INFOCOMMANDKILLNPC_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandKillNPC :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandKillNPC, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandKillNPC( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strNPC, NPC )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandKillNPC, 0x0014 )

#endif
