#ifndef FF_MODULEMUSIC_H_INLCUDED
#define FF_MODULEMUSIC_H_INLCUDED

FF_DECLARE_INTERFACE( IFFModuleMusic, "BBF55EF7-BAA5-49D4-A0C0-ACA6AAE7145E" ) :
    virtual public IFFUnknown
{
private: virtual void __FIXME_0000( void ) = 0; // [0000].0000
private: virtual void __FIXME_0004( void ) = 0; // [0000].0004
private: virtual void __FIXME_0008( void ) = 0; // [0000].0008
private: virtual void __FIXME_000C( void ) = 0; // [0000].000C
private: virtual void __FIXME_0010( void ) = 0; // [0000].0010
private: virtual void __FIXME_0014( void ) = 0; // [0000].0014
private: virtual void __FIXME_0018( void ) = 0; // [0000].0018
private: virtual void __FIXME_001C( void ) = 0; // [0000].001C
private: virtual void __FIXME_0020( void ) = 0; // [0000].0020
private: virtual void __FIXME_0024( void ) = 0; // [0000].0024
private: virtual void __FIXME_0028( void ) = 0; // [0000].0028
private: virtual void __FIXME_002C( void ) = 0; // [0000].002C
private: virtual void __FIXME_0030( void ) = 0; // [0000].0030
private: virtual void __FIXME_0034( void ) = 0; // [0000].0034
private: virtual void __FIXME_0038( void ) = 0; // [0000].0038
private: virtual void __FIXME_003C( void ) = 0; // [0000].003C
private: virtual void __FIXME_0040( void ) = 0; // [0000].0040
private: virtual void __FIXME_0044( void ) = 0; // [0000].0044
private: virtual void __FIXME_0048( void ) = 0; // [0000].0048
private: virtual void __FIXME_004C( void ) = 0; // [0000].004C
private: virtual void __FIXME_0050( void ) = 0; // [0000].0050
private: virtual void __FIXME_0054( void ) = 0; // [0000].0054
private: virtual void __FIXME_0058( void ) = 0; // [0000].0058
private: virtual void __FIXME_005C( void ) = 0; // [0000].005C
private: virtual void __FIXME_0060( void ) = 0; // [0000].0060
private: virtual void __FIXME_0064( void ) = 0; // [0000].0064
private: virtual void __FIXME_0068( void ) = 0; // [0000].0068
private: virtual void __FIXME_006C( void ) = 0; // [0000].006C
private: virtual void __FIXME_0070( void ) = 0; // [0000].0070
private: virtual void __FIXME_0074( void ) = 0; // [0000].0074
private: virtual void __FIXME_0078( void ) = 0; // [0000].0078
};

FF_C_LINKAGE FF_DLLIMPORT FFBool           FF_STDCALL FFMusic_Lock( void );
FF_C_LINKAGE FF_DLLIMPORT IFFModuleMusic * FF_STDCALL FFMusic_QueryModule( void );
FF_C_LINKAGE FF_DLLIMPORT FFBool           FF_STDCALL FFMusic_Unlock( void );

#endif
