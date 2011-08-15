#ifndef GE_RESOURCECOMPILER_H_INCLUDED
#define GE_RESOURCECOMPILER_H_INCLUDED

class GE_DLLIMPORT iCResourceCompiler :
    public bCObjectRefBase
{
public:
    enum eEResourceCompilerType
    {
        eEResourceCompilerType_Image,
        eEResourceCompilerType_Sound,
        eEResourceCompilerType_Animation,
        eEResourceCompilerType_Meshes_Materials,
        eEResourceCompilerType_Meshes,
        eEResourceCompilerType_Materials,
        eEResourceCompilerType_LipSync,
        eEResourceCompilerType_Library,
        eEResourceCompilerType_ForceDWORD = GE_FORCE_DWORD
    };
public:    virtual GEU16    GetVersion( void ) const;
public:    virtual bEResult Create( void );
public:    virtual void     Destroy( void );
public:    virtual         ~iCResourceCompiler( void );
protected: virtual void     ConvertMeshes( bTObjArray< bCString > const &, GEBool, GEBool );
protected:
    char __FIXME[ 0x0024 - sizeof(bCObjectRefBase) ];
protected:
    void CheckRedundantNativeImages( bCString const & );
    void CollectFiles( bCString const &, bTObjArray< bCString > const &, bTObjArray< bCString > & );
    void CompileLipSync( bTObjArray< bCString > & );
    void CompileMaterials( bTObjArray< bCString > & );
    void DeleteFiles( bTObjArray< bCString > const & );
    void Invalidate( void );
public:
    void     CompileResources( bCString const &, eEResourceCompilerType );
    void     DeleteResources( bCString const &, eEResourceCompilerType );
    void     GetProprietaryFileExtensionList( eEResourceCompilerType, bTObjArray< bCString > & );
    bCString GetResourceNameString( eEResourceCompilerType );
    GEBool   ParseCommandLine( bCCommandLine const & );
public:
    iCResourceCompiler & operator = ( iCResourceCompiler const & );
protected:
    iCResourceCompiler( iCResourceCompiler const & );
public:
    iCResourceCompiler( void );
};
GE_ASSERT_SIZEOF( iCResourceCompiler, 0x0024 )

#endif
