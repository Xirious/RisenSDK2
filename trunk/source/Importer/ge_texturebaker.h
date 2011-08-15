#ifndef GE_TEXTUREBAKER_H_INCLUDED
#define GE_TEXTUREBAKER_H_INCLUDED

class GE_DLLIMPORT iITextureBakerProgress
{
public: virtual void OnPercent( GEFloat )          = 0;
public: virtual void OnMessage( bCString const & ) = 0;
public:
    iITextureBakerProgress & operator = ( iITextureBakerProgress const & );
public:
    iITextureBakerProgress( iITextureBakerProgress const & );
    iITextureBakerProgress( void );
};
GE_ASSERT_SIZEOF( iITextureBakerProgress, 0x0004 )

class GE_DLLIMPORT iCTextureBaker
{
protected:
    //FIXME: iCTextureBaker::iSBakeTexture
    struct iSBakeTexture{};
    //FIXME: iCTextureBaker::iSUVGroup
    struct iSUVGroup{};
public: virtual ~iCTextureBaker( void );
protected:
    static GEDouble (* ms_arrSamples)[ 2 ];
    static GEInt       ms_iPixelBatchCount;
    static GEInt       ms_iSampleCount;
protected:
    char __FIXME[ 0x00F8 - sizeof(void *) ];
protected:
    GEBool   CollectBakeTextures( eCMeshResource2 * );
    bEResult Create( void );
    GEBool   CreateUVGroups( eCMeshResource2 *, bTObjArray< iSUVGroup > & );
    void     Destroy( void );
    void     FillTextureEdges( void );
    GEBool   FindBestHighPolyFace( eCMeshResource2 *, bCVector const &, bCVector const & );
    void     Invalidate( void );
    GEBool   ProcessBakeTexture( iSBakeTexture & );
    GEBool   RenderBakeTexture( iSBakeTexture const & );
public:
    GEBool Process( iITextureBakerProgress * );
public:
    iCTextureBaker & operator = ( iCTextureBaker const & );
public:
    iCTextureBaker( iCTextureBaker const & );
    iCTextureBaker( void );
};
GE_ASSERT_SIZEOF( iCTextureBaker, 0x00F8 )

#endif
