#ifndef GE_APITEXTURE_H_INCLUDED
#define GE_APITEXTURE_H_INCLUDED

class GE_DLLIMPORT eCAPITexture
{
public: virtual bEResult LockRect( GEUInt, eCGfxShared::eSGfxLockedRect *, bSRect const *, GEU32 )                                                    = 0;  // [0000].0000
public: virtual bEResult UnlockRect( GEUInt )                                                                                                         = 0;  // [0000].0004
public: virtual bEResult LockImageLayer( GEUInt, GEU32, GEInt *, GELPVoid * )                                                                         = 0;  // [0000].0008
public: virtual bEResult UnlockImageLayer( GEUInt )                                                                                                   = 0;  // [0000].000C
public: virtual bEResult GetRenderTargetHandle( GELPVoid * )                                                                                          = 0;  // [0000].0010
public: virtual bEResult SetTexture( GEU32 )                                                                                                          = 0;  // [0000].0014
public: virtual bEResult ComputeNormalMap( eCAPITexture *, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat )                             = 0;  // [0000].0018
public: virtual bEResult ConvertFrom( eCAPITexture *, eCGfxShared::eECopyFilter, GEBool, GEInt )                                                      = 0;  // [0000].001C
public: virtual bEResult GenerateTextureMipMaps( GEUInt, eCGfxShared::eECopyFilter )                                                                  = 0;  // [0000].0020
public: virtual bEResult SaveTextureToFile( GELPChar const )                                                                                          = 0;  // [0000].0024
public: virtual bEResult SaveTextureToMemory( bCMemoryStream & )                                                                                      = 0;  // [0000].0028
public: virtual bEResult CopyCurrentRTToImage( eCGfxShared::eETexFilter, bCRect *, bCRect * )                                                         = 0;  // [0000].002C
public: virtual bEResult CopyImageToCurrentRT( eCGfxShared::eETexFilter, bCRect *, bCRect * )                                                         = 0;  // [0000].0030
public: virtual bEResult CopySurface( eCAPITexture * )                                                                                                = 0;  // [0000].0034
public: virtual bEResult LoadSurfaceFromSurface( GEUInt, GELPCVoid, bCRect const *, eCAPITexture *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32 ) = 0;  // [0000].0038
public: virtual bEResult GetRenderTargetData( eCAPITexture *, GEInt )                                                                                 = 0;  // [0000].003C
public: virtual ~eCAPITexture( void );                                                                                                                      // [0000].0040
protected:
    GEU32 m_u32RefCounter;  // 0004
public:
    GEU32 AddRef( void );
    GEU32 Release( void );
public:
    eCAPITexture & operator = ( eCAPITexture const & );
protected:
    eCAPITexture( void );
public:
    eCAPITexture( eCAPITexture const & );
};
GE_ASSERT_SIZEOF( eCAPITexture, 0x0008 )

#endif
