#ifndef GE_SCENECOMPILER_H_INCLUDED
#define GE_SCENECOMPILER_H_INCLUDED

class GE_DLLIMPORT iCSceneCompiler :
    public bCObjectRefBase
{
protected:
    struct iSStaticBoundaryItem
    {
        //FIXME: iCSceneCompiler::iSStaticBoundaryItem members.
    };
public:
    enum iECompileOptions
    {
        //FIXME: iCSceneCompiler::iECompileOptions constants.
        iECompileOptions_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual GEU16    GetVersion( void ) const;
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual         ~iCSceneCompiler( void );
protected:
    char __FIXME[ 0x003C - sizeof(bCObjectRefBase) ];
protected:
    GEBool BuildKDTree( eCEntity *, bTPtrArray< bCObjectRefBase * > &, bCBox const & );
    GEBool BuildKDTree( eCEntity *, GEBool );
    GEBool BuildKDTree( gCLayerBase * );
    GEBool BuildKDTree( gCSector * );
    void   CleanWorld( gCWorld * );
    GEBool CollectKDEntities( eCEntity *, bTPtrArray< bCObjectRefBase * > & );
    void   CompileForStatic( gCWorld * );
    GEBool CompileLightmaps( gCWorld *, eCCameraBase & );
    GEBool CompilePhysicEntityRecursive( eCEntity * );
    GEBool CompilePhysicMeshes( gCWorld * );
    void   CompressWorld( gCWorld * );
    void   CopyPhysicalDir( bCString const &, bCString const & );
    void   DeleteEmptySectors( gCWorld * );
    void   DeleteOldDynamicLayers( gCWorld * );
    void   DeletePhysicalDir( bCString const & );
    void   Invalidate( void );
    void   OptimizeDynamicGeometry( gCWorld * );
    void   OptimizeVegetation( eCEntity *, iSStaticBoundaryItem & );
    GEBool PrefetchWorld( gCWorld *, eCCameraBase & );
    void   PrepareCompilation( gCWorld * );
    void   SaveWorld( gCWorld * );
public:
    bEResult CompileWorld( bCString const &, iECompileOptions, GEBool );
    GEBool   IsCompileSuccessfull( void ) const;
    GEBool   ParseCommandLine( bCCommandLine const & );
public:
    iCSceneCompiler & operator = ( iCSceneCompiler const & );
protected:
    iCSceneCompiler( iCSceneCompiler const & );
public:
    iCSceneCompiler( void );
};
GE_ASSERT_SIZEOF( iCSceneCompiler, 0x003C );

#endif
