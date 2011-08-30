#ifndef GE_INFOCOMMANDTRIGGER_H_INCLUDED
#define GE_INFOCOMMANDTRIGGER_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandTrigger :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandTrigger, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strTargetEntity, TargetEntity )
    GE_DECLARE_PROPERTY( GEBool,   m_bDoUntrigger,    DoUntrigger )
    GE_PADDING( 3 )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandTrigger, 0x0018 )

#endif
