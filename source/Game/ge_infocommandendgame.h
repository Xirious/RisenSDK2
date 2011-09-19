#ifndef GE_INFOCOMMANDENDGAME_H_INCLUDED
#define GE_INFOCOMMANDENDGAME_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandEndGame :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandEndGame, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoCommandEndGame( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandEndGame, 0x0008 )

#endif
