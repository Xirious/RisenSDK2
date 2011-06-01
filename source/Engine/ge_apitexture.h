#ifndef GE_APITEXTURE_H_INCLUDED
#define GE_APITEXTURE_H_INCLUDED

class GE_DLLIMPORT eCAPITexture
{
public: virtual bEResult LockRect( GEUInt, eCGfxShared::eSGfxLockedRect *, bSRect const *, GEU32 )                                                    = 0;  
public: virtual bEResult UnlockRect( GEUInt )                                                                                                         = 0;  
public: virtual bEResult LockImageLayer( GEUInt, GEU32, GEInt *, GELPVoid * )                                                                         = 0;  
public: virtual bEResult UnlockImageLayer( GEUInt )                                                                                                   = 0;  
public: virtual bEResult GetRenderTargetHandle( GELPVoid * )                                                                                          = 0;  
public: virtual bEResult SetTexture( GEU32 )                                                                                                          = 0;  
public: virtual bEResult ComputeNormalMap( eCAPITexture *, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat )                             = 0;  
public: virtual bEResult ConvertFrom( eCAPITexture *, eCGfxShared::eECopyFilter, GEBool, GEInt )                                                      = 0;  
public: virtual bEResult GenerateTextureMipMaps( GEUInt, eCGfxShared::eECopyFilter )                                                                  = 0;  
public: virtual bEResult SaveTextureToFile( GELPChar const )                                                                                          = 0;  
public: virtual bEResult SaveTextureToMemory( bCMemoryStream & )                                                                                      = 0;  
public: virtual bEResult CopyCurrentRTToImage( eCGfxShared::eETexFilter, bCRect *, bCRect * )                                                         = 0;  
public: virtual bEResult CopyImageToCurrentRT( eCGfxShared::eETexFilter, bCRect *, bCRect * )                                                         = 0;  
public: virtual bEResult CopySurface( eCAPITexture * )                                                                                                = 0;  
public: virtual bEResult LoadSurfaceFromSurface( GEUInt, GELPCVoid, bCRect const *, eCAPITexture *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32 ) = 0;  
public: virtual bEResult GetRenderTargetData( eCAPITexture *, GEInt )                                                                                 = 0;  
public: virtual ~eCAPITexture( void );                                                                                                                      
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
