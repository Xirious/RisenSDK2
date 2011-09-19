#ifndef GE_INFOCOMMANDEND_H_INCLUDED
#define GE_INFOCOMMANDEND_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandEnd :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandEnd, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoCommandEnd( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandEnd, 0x0008 )

#endif
