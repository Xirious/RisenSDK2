#ifndef GE_INFOCOMMANDBOOSTATTRIBS_H_INCLUDED
#define GE_INFOCOMMANDBOOSTATTRIBS_H_INCLUDED

enum gEBoostTarget
{
    gEBoostTarget_Strength     = 0x00000000,
    gEBoostTarget_Dexterity    = 0x00000001,
    gEBoostTarget_Intelligence = 0x00000002,
    gEBoostTarget_ForceDWORD   = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCInfoCommandBoostAttribs'

class GE_DLLIMPORT gCInfoCommandBoostAttribs :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandBoostAttribs, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,      m_strEntity1,      Entity1 )
    GE_DECLARE_ENUMPROP( gEBoostTarget, m_enumBoostTarget, BoostTarget )
    eCEntityProxy                       m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandBoostAttribs, 0x001C )

#pragma warning( pop )

#endif
