#ifndef GE_INFOCOMMANDGIVE_H_INCLUDED
#define GE_INFOCOMMANDGIVE_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandGive :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandGive, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandGive( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,              m_strEntity1, Entity1 )
    GE_DECLARE_PROPERTY( bCString,              m_strEntity2, Entity2 )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_Item,       Item )
    GE_DECLARE_PROPERTY( GEU32,                 m_u32Amount,  Amount )
    eCEntityProxy                               m_EntityProxy1;
    eCEntityProxy                               m_EntityProxy2;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandGive, 0x0028 )

#endif
