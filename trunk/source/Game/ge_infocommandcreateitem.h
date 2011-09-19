#ifndef GE_INFOCOMMANDCREATEITEM_H_INCLUDED
#define GE_INFOCOMMANDCREATEITEM_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandCreateItem :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandCreateItem, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandCreateItem( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,              m_strEntity1, Entity1 )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_Item,       Item )
    GE_DECLARE_PROPERTY( GEU32,                 m_u32Amount,  Amount )
    eCEntityProxy                               m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandCreateItem, 0x001C )

#endif
