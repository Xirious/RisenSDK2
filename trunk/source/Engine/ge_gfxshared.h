#ifndef GE_GFXSHARED_H_INCLUDED
#define GE_GFXSHARED_H_INCLUDED

#define GE_MAX_TEXTURE_UNITS 16

typedef void (GE_STDCALL * GEFGfxGaugeCallback)( void );

namespace eCGfxShared
{
    // D3DX_CHANNEL
    enum eEChannel
    {
        eEChannel_Red        = 0x00000001,
        eEChannel_Blue       = 0x00000002,
        eEChannel_Green      = 0x00000004,
        eEChannel_Alpha      = 0x00000008,
        eEChannel_Luminance  = 0x00000010,
        eEChannel_ForceDWORD = GE_FORCE_DWORD
    };

    // D3DFORMAT
    enum eEColorFormat
    {
        eEColorFormat_Unknown       = 0x00000000,
        eEColorFormat_R8G8B8        = 0x00000014,
        eEColorFormat_A8R8G8B8      = 0x00000015,
        eEColorFormat_X8R8G8B8      = 0x00000016,
        eEColorFormat_R5G6B5        = 0x00000017,
        eEColorFormat_X1R5G5B5      = 0x00000018,
        eEColorFormat_A1R5G5B5      = 0x00000019,
        eEColorFormat_A4R4G4B4      = 0x0000001A,
        eEColorFormat_R3G3B2        = 0x0000001B,
        eEColorFormat_A8            = 0x0000001C,
        eEColorFormat_A8R3G3B2      = 0x0000001D,
        eEColorFormat_X4R4G4B4      = 0x0000001E,
        eEColorFormat_A2B10G10R10   = 0x0000001F,
        eEColorFormat_A8B8G8R8      = 0x00000020,
        eEColorFormat_X8B8G8R8      = 0x00000021,
        eEColorFormat_G16R16        = 0x00000022,
        eEColorFormat_A2R10G10B10   = 0x00000023,
        eEColorFormat_A16B16G16R16  = 0x00000024,
        eEColorFormat_A8P8          = 0x00000028,
        eEColorFormat_P8            = 0x00000029,
        eEColorFormat_L8            = 0x00000032,
        eEColorFormat_A8L8          = 0x00000033,
        eEColorFormat_A4L4          = 0x00000034,
        eEColorFormat_V8U8          = 0x0000003C,
        eEColorFormat_L6V5U5        = 0x0000003D,
        eEColorFormat_X8L8V8U8      = 0x0000003E,
        eEColorFormat_Q8W8V8U8      = 0x0000003F,
        eEColorFormat_V16U16        = 0x00000040,
        eEColorFormat_A2W10V10U10   = 0x00000043,
        eEColorFormat_L16           = 0x00000051,
        eEColorFormat_Q16W16V16U16  = 0x0000006E,
        eEColorFormat_R16F          = 0x0000006F,
        eEColorFormat_G16R16F       = 0x00000070,
        eEColorFormat_A16B16G16R16F = 0x00000071,
        eEColorFormat_R32F          = 0x00000072,
        eEColorFormat_G32R32F       = 0x00000073,
        eEColorFormat_A32B32G32R32F = 0x00000074,
        eEColorFormat_CxV8U8        = 0x00000075,
        eEColorFormat_DXT1          = 0x31545844,
        eEColorFormat_DXT2          = 0x32545844,
        eEColorFormat_YUY2          = 0x32595559,
        eEColorFormat_DXT3          = 0x33545844,
        eEColorFormat_DXT4          = 0x34545844,
        eEColorFormat_DXT5          = 0x35545844,
        eEColorFormat_UYVY          = 0x59565955
    };

    // D3DX_FILTER
    enum eECopyFilter
    {
        eECopyFilter_None            = 0x00000001,
        eECopyFilter_Point           = 0x00000002,
        eECopyFilter_Linear          = 0x00000003,
        eECopyFilter_Triangle        = 0x00000004,
        eECopyFilter_Box             = 0x00000005,
        eECopyFilter_MirrorU         = 0x00010000,
        eECopyFilter_MirrorV         = 0x00020000,
        eECopyFilter_MirrorW         = 0x00040000,
        eECopyFilter_Mirror          = 0x00070000,
        eECopyFilter_Dither          = 0x00080000,
        eECopyFilter_DitherDiffusion = 0x00100000,
        eECopyFilter_sRGB_In         = 0x00200000,
        eECopyFilter_sRGB_Out        = 0x00400000,
        eECopyFilter_sRGB            = 0x00600000,
        eECopyFilter_ForceDWORD      = GE_FORCE_DWORD
    };

    // D3DCUBEMAP_FACES
    enum eECubeMapFace
    {
        eECubeMapFace_PositiveX  = 0x00000000,
        eECubeMapFace_NegativeX  = 0x00000001,
        eECubeMapFace_PositiveY  = 0x00000002,
        eECubeMapFace_NegativeY  = 0x00000003,
        eECubeMapFace_PositiveZ  = 0x00000004,
        eECubeMapFace_NegativeZ  = 0x00000005,
        eECubeMapFace_None       = 0x00000006,
        eECubeMapFace_ForceDWORD = GE_FORCE_DWORD
    };

    // D3DX_NORMALMAP
    enum eENormalMapGen
    {
        eENormalMapGen_Default          = 0x00000000,
        eENormalMapGen_MirrorU          = 0x00010000,
        eENormalMapGen_MirrorV          = 0x00020000,
        eENormalMapGen_Mirror           = 0x00030000,
        eENormalMapGen_InvertSign       = 0x00080000,
        eENormalMapGen_ComputeOcclusion = 0x00100000,
        eENormalMapGen_ForceDWORD       = GE_FORCE_DWORD
    };
    
    // D3DTEXTUREFILTERTYPE
    enum eETexFilter
    {
        eETexFilter_None            = 0x00000000,
        eETexFilter_Point           = 0x00000001,
        eETexFilter_Linear          = 0x00000002,
        eETexFilter_Anisotropic     = 0x00000003,
        eETexFilter_FlatCubic       = 0x00000004,
        eETexFilter_GaussianCubic   = 0x00000005,
        eETexFilter_PyramidalQuad   = 0x00000006,
        eETexFilter_GaussianQuad    = 0x00000007,
        eETexFilter_ConvolutionMono = 0x00000008,
        eETexFilter_ForceDWORD      = GE_FORCE_DWORD
    };

    // D3DPOOL
    enum eEPoolType
    {
        eEPoolType_Default    = 0x00000000,
        eEPoolType_Managed    = 0x00000001,
        eEPoolType_SystemMem  = 0x00000002,
        eEPoolType_Scratch    = 0x00000003,
        eEPoolType_ForceDWORD = GE_FORCE_DWORD
    };

    enum eECmpFunc
    {
        eECmpFunc_ForceDWORD = GE_FORCE_DWORD
    };

    struct eSGfxLayersDesc
    {
        GEUInt        m_uiWidth;         // 0000
        GEUInt        m_uiHeight;        // 0004
        GEUInt        m_uiDepth;         // 0008
        GEBool        m_bCubeMap;        // 000C
                      GE_PADDING( 3 )
        GEUInt        m_uiLevelCount;    // 0010
        GEU32         m_u32Usage;        // 0014
        eEColorFormat m_enumFormat;      // 0018
        eEPoolType    m_enumPool;        // 001C
        GEUInt        m_uiResourceSize;  // 0020
        GELPCChar     m_pcFunctionName;  // 0024
    };
    GE_ASSERT_SIZEOF( eSGfxLayersDesc, 0x0028 )

    // D3DLOCKED_RECT
    struct eSGfxLockedRect
    {
        GEInt    m_iPitch;  // 0000
        GELPVoid m_pBits;   // 0004
    };
    GE_ASSERT_SIZEOF( eSGfxLockedRect, 0x0008 )

}

#endif
