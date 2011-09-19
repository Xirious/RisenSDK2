#ifndef GE_INFOCOMMANDSTOPFIXCAMERA_H_INCLUDED
#define GE_INFOCOMMANDSTOPFIXCAMERA_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandStopFixCamera :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandStopFixCamera, gCInfoCommand )
public: virtual void           Destroy( void );
public: virtual               ~gCInfoCommandStopFixCamera( void );
public: virtual gEInfoCommand  GetCommandType( void ) const;
public: virtual GEBool         Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool         IsValid( bCString &, gCInfo const & ) const;
public: using bCObjectRefBase::IsValid;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandStopFixCamera, 0x0008 )

#endif