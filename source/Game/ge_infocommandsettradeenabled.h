#ifndef GE_INFOCOMMANDSETTRADEENABLED_H_INCLUDED
#define GE_INFOCOMMANDSETTRADEENABLED_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandSetTradeEnabled :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandSetTradeEnabled, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandSetTradeEnabled( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strEntity1,    Entity1 )
    GE_DECLARE_PROPERTY( GEBool,   m_bTradeEnabled, TradeEnabled )
    GE_PADDING( 3 )
    eCEntityProxy                  m_EntityProxy1;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandSetTradeEnabled, 0x0018 )

#endif
