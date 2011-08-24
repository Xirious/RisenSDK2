#ifndef FF_MODULEMUSIC_H_INLCUDED
#define FF_MODULEMUSIC_H_INLCUDED

FF_DECLARE_INTERFACE( IFFModuleMusic, "BBF55EF7-BAA5-49D4-A0C0-ACA6AAE7145E" ) :
    virtual public IFFUnknown
{
private: virtual void __FIXME_0000( void ) = 0; 
private: virtual void __FIXME_0004( void ) = 0; 
private: virtual void __FIXME_0008( void ) = 0; 
private: virtual void __FIXME_000C( void ) = 0; 
private: virtual void __FIXME_0010( void ) = 0; 
private: virtual void __FIXME_0014( void ) = 0; 
private: virtual void __FIXME_0018( void ) = 0; 
private: virtual void __FIXME_001C( void ) = 0; 
private: virtual void __FIXME_0020( void ) = 0; 
private: virtual void __FIXME_0024( void ) = 0; 
private: virtual void __FIXME_0028( void ) = 0; 
private: virtual void __FIXME_002C( void ) = 0; 
private: virtual void __FIXME_0030( void ) = 0; 
private: virtual void __FIXME_0034( void ) = 0; 
private: virtual void __FIXME_0038( void ) = 0; 
private: virtual void __FIXME_003C( void ) = 0; 
private: virtual void __FIXME_0040( void ) = 0; 
private: virtual void __FIXME_0044( void ) = 0; 
private: virtual void __FIXME_0048( void ) = 0; 
private: virtual void __FIXME_004C( void ) = 0; 
private: virtual void __FIXME_0050( void ) = 0; 
private: virtual void __FIXME_0054( void ) = 0; 
private: virtual void __FIXME_0058( void ) = 0; 
private: virtual void __FIXME_005C( void ) = 0; 
private: virtual void __FIXME_0060( void ) = 0; 
private: virtual void __FIXME_0064( void ) = 0; 
private: virtual void __FIXME_0068( void ) = 0; 
private: virtual void __FIXME_006C( void ) = 0; 
private: virtual void __FIXME_0070( void ) = 0; 
private: virtual void __FIXME_0074( void ) = 0; 
private: virtual void __FIXME_0078( void ) = 0; 
};

FF_DLLIMPORT_EXTC FFBool           FF_STDCALL FFMusic_Lock( void );
FF_DLLIMPORT_EXTC IFFModuleMusic * FF_STDCALL FFMusic_QueryModule( void );
FF_DLLIMPORT_EXTC FFBool           FF_STDCALL FFMusic_Unlock( void );

#endif
