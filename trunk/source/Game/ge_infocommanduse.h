#ifndef GE_INFOCOMMANDUSE_H_INCLUDED
#define GE_INFOCOMMANDUSE_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandUse :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandUse, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual gEInfoCommand   GetCommandTypeForScript( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString,              m_strEntity1,          Entity1 )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_Item,                Item )
    GE_DECLARE_PROPERTY( bCString,              m_strUseAnimationName, UseAnimationName )
    eCEntityProxy                               m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandUse, 0x001C )

#endif
