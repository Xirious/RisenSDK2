#ifndef GE_GFXIMAGEDATA_H_INCLUDED
#define GE_GFXIMAGEDATA_H_INCLUDED

typedef GEBool (GE_STDCALL * GEFImageLoadMaxMipmapCallback)( GEU32, GEU32, GEU32, GEBool & );

class GE_DLLIMPORT eCGfxImageData :
    public eCGfxObject
{
public:    using     eCGfxObject::GetObjectType;                        // [0000].0000
public:    using bCObjectRefBase::GetVersion;                           // [0000].0004
public:    using bCObjectRefBase::IsValid;                              // [0000].0008
public:    using    bCObjectBase::Deserialize;                          // [0000].000C
public:    using    bCObjectBase::Serialize;                            // [0000].0010
public:    using    bCObjectBase::Read;                                 // [0000].0014
public:    using    bCObjectBase::Write;                                // [0000].0018
protected: using    bCObjectBase::OnDeserialize;                        // [0000].001C
protected: using    bCObjectBase::OnSerialize;                          // [0000].0020
public:    virtual GEBool         OnRead( bCIStream & );                // [0000].0024
public:    virtual GEBool         OnWrite( bCOStream & );               // [0000].0028
public:    virtual bEResult       Create( void );                       // [0000].002C
public:    virtual void           Destroy( void );                      // [0000].0030
public:    using    bCObjectBase::CopyFrom;                             // [0000].0034
protected: using    bCObjectBase::OnCopyFrom;                           // [0000].0038
protected: using    bCObjectBase::OnCopyPatchableOnly;                  // [0000].003C
public:    using bCObjectRefBase::AddReference;                         // [0000].0040
public:    using bCObjectRefBase::ReleaseReference;                     // [0000].0044
public:    using    bCObjectBase::GetReferenceCount;                    // [0000].0048
public:    using    bCObjectBase::BindPOType;                           // [0000].004C
public:    using    bCObjectBase::PostInitializeProperties;             // [0000].0050
public:    using    bCObjectBase::HandleDeprecatedProperty;             // [0000].0054
public:    using    bCObjectBase::NotifyPropertyValueChangedEnterEx;    // [0000].0058
public:    using    bCObjectBase::NotifyPropertyValueChangedExitEx;     // [0000].005C
public:    using    bCObjectBase::OnNotifyPropertyValueChangedEnterEx;  // [0000].0060
public:    using    bCObjectBase::OnNotifyPropertyValueChangedExitEx;   // [0000].0064
public:    using    bCObjectBase::GetNativePropertyCount;               // [0000].0068
public:    using    bCObjectBase::GetNativePropertyAt;                  // [0000].006C
protected: virtual               ~eCGfxImageData( void );               // [0000].0070
protected:
    static GEBool                        ms_bOptimize;
    static GEBool                        ms_bReset;
    static eCGfxImageData *              ms_pActiveImageData[ GE_MAX_TEXTURE_UNITS ];
    static eCGfxImageData *              ms_pMasterImageData[ GE_MAX_TEXTURE_UNITS ];
    static GEFGfxGaugeCallback           ms_pRegisterImageDataExecuteCall;
    static GEFImageLoadMaxMipmapCallback ms_pfuncLoadMaxMipmapCallback;
    static GEU32                         ms_u32UserData;
protected:
    void *                       m_pDeviceHandle;           // 0008 //FIXME: eCAPIDevice *
    eCGfxShared::eSGfxLayersDesc m_LayersDescription;       // 000C
    eCGfxShared::eEColorFormat   m_enumColorFormat;         // 0034
    GEU32                        m_u32UnitNumber;           // 0038
    GEBool                       m_bLocked;                 // 003C
                                 GE_PADDING( 3 )
    GEU32                        m_u32MipMapCount;          // 0040
    GEBool                       m_bUseDefaultPool;         // 0044
                                 GE_PADDING1( 3 )
    eCAPITexture *               m_pTextureHandle;          // 0048
    GEBool                       m_bMipMapCountModified;    // 004C
                                 GE_PADDING2( 3 )
    eCVideoPlayer *              m_pVideoPlayer;            // 0050
protected:
    static void             GE_STDCALL sDisableOptimization( void );
    static void             GE_STDCALL sEnableOptimization( void );
    static eCGfxImageData * GE_STDCALL sGetActiveImageData( GEU32 );
    static eCGfxImageData * GE_STDCALL sGetMasterImageData( GEU32 );
    static void             GE_STDCALL sResetCachedStates( void );
    static void             GE_STDCALL sSetImageDataExecuteCallback( GEFGfxGaugeCallback );
    static void             GE_STDCALL sSetMasterImageData( GEU32, eCGfxImageData * );
protected:
    bEResult ComputeNormalMap( eCGfxImageData &, eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat );
    bEResult ComputeNormalMapInPlace( eCGfxShared::eENormalMapGen, eCGfxShared::eEChannel, GEFloat );
    bEResult ConvertCubeMap( eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool );
    bEResult ConvertCubeMapInPlace( GEInt );
    bEResult ConvertCubeMapInPlace( eCGfxShared::eEColorFormat );
    bEResult ConvertTexture( eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool );
    bEResult ConvertTextureInPlace( GEInt );
    bEResult ConvertTextureInPlace( eCGfxShared::eEColorFormat );
    bEResult ConvertVolume( eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool );
    bEResult ConvertVolumeInPlace( GEInt );
    bEResult ConvertVolumeInPlace( eCGfxShared::eEColorFormat );
    bEResult CopyCurrentRTToImage( eCGfxShared::eETexFilter, bCRect *, bCRect * );
    bEResult CopyImageToCurrentRT( eCGfxShared::eETexFilter, bCRect *, bCRect * );
    bEResult CreateImageFromFile( eCGfxShared::eEPoolType, GEUInt, GELPChar const, GEU8 );
    bEResult CreateLayers( eCGfxShared::eSGfxLayersDesc const & );
    bEResult DestroyLayers( void );
    bEResult FillImageFromFile( eCGfxShared::eSGfxLayersDesc &, GELPChar const, GEU8 );
    bEResult FillImageFromMemory( eCGfxShared::eSGfxLayersDesc &, GELPVoid, GEUInt, GEU8 );
    bEResult GenerateMipMaps( GEUInt, eCGfxShared::eECopyFilter );
    bEResult GetTextureHandle( eCAPITexture * * );
    GEBool   HasAlphaLayer( bCString const & );
    bEResult SaveImageToFile( GELPChar const );
    bEResult SaveImageToMemory( bCMemoryStream & );
    bEResult UpdateCompleteSize( GEInt, GEU32 * );
    bEResult WrapAPITexture( eCAPITexture *, eCGfxShared::eSGfxLayersDesc & );
public:
    static void GE_STDCALL FillResourceSizeAndLevelCount( eCGfxShared::eSGfxLayersDesc &, GEInt );
    static void GE_STDCALL SetImageLoadMaxMipmapCallback( GEFImageLoadMaxMipmapCallback, GEU32 );
public:
    bEResult        CompressNormalMapToDXT5InPlace( void );
    bEResult        ConvertFrom( eCGfxImageData &, eCGfxShared::eECopyFilter, GEBool );
    bEResult        ConvertInPlace( GEInt );
    bEResult        ConvertInPlace( eCGfxShared::eEColorFormat );
    bEResult        Create( eCGfxShared::eSGfxLayersDesc const & );
    bEResult        Create( eCGfxShared::eEColorFormat );
    bEResult        CreateImageFromMemory( eCGfxShared::eEPoolType, GEUInt, GELPVoid, GEUInt, GEU8 );
    bEResult        CreateImageFromMemoryExt( eCGfxShared::eEPoolType, GEInt, GELPCVoid, GEUInt, GEU8 );
    bEResult        Execute( void );
    bEResult        GetLayersDescription( eCGfxShared::eSGfxLayersDesc & );
    bEResult        GetMipMapCountForRead( GEU32 & ) const;
    bEResult        GetRenderTargetData( eCGfxShared::eECubeMapFace, eCGfxImageData *, GEInt );
    bEResult        GetRenderTargetHandle( eCGfxShared::eECubeMapFace, GELPVoid & ) const;
    GEU32           GetResourceSize( GEInt );
    bEResult        GetUnitNumber( GEU32 & ) const;
    eCVideoPlayer * GetVideoPlayer( void );
    bEResult        Import( bCString const &, GEBool );
    void            Invalidate( void );
    bEResult        LoadSurfaceFromSurface( GEUInt, GELPCVoid, bCRect const *, eCGfxImageData *, GEUInt, GELPCVoid, bCRect const *, GEU32, GEU32 );
    bEResult        LockLayer( GEUInt, eCGfxShared::eECubeMapFace, GEU32, GEInt &, GEInt &, GELPVoid * );
    bEResult        LockRect( eCGfxShared::eECubeMapFace, GEUInt, eCGfxShared::eSGfxLockedRect *, bSRect const *, GEU32 );
    GEBool          SaveToStream( bCMemoryStream & );
    bEResult        SetMipMapCountForRead( GEU32 );
    bEResult        SetUnitNumber( GEU32 );
    bEResult        UnlockLayer( eCGfxShared::eECubeMapFace, GEUInt );
    bEResult        UnlockRect( eCGfxShared::eECubeMapFace, GEUInt );
    bEResult        UseDefaultPoolForRead( GEBool );
public:
    eCGfxImageData & operator = ( eCGfxImageData const & );
public:
    eCGfxImageData( eCGfxImageData const & );
    eCGfxImageData( void );
};
GE_ASSERT_SIZEOF(  eCGfxImageData,  0x0054  )

#endif
