#ifndef GE_GAMEAPP_H_INCLUDED
#define GE_GAMEAPP_H_INCLUDED

class GE_DLLIMPORT gCGameApp :
    public eCApplication
{
public:    virtual GEBool           IsInOutputStage( void );
// eCApplication
protected: virtual bEResult         Create( void );
public:    virtual void             Destroy( void );
public:    virtual                 ~gCGameApp( void );
protected: virtual GEInt            OnSize( GEUInt, GEI32 );
public:    virtual eCEntity const * GetEditorEntity( void ) const;
public:    virtual GEBool           IsGameRunning( void ) const;
public:    virtual bCString         GetCompiledMeshPath( void ) const;
public:    virtual bCString         GetMaterialPath( void ) const;
public:    virtual bCString         GetCompiledAnimationPath( void ) const;
public:    virtual bCString         GetRawAnimationPath( void ) const;
public:    virtual bCString         GetCompiledImagePath( void ) const;
public:    virtual bCString         GetCompiledSoundPath( void ) const;
public:    virtual bCString         GetRawSoundPath( void ) const;
public:    virtual bCString         GetCompiledPhysicPath( void ) const;
public:    virtual bCString         GetCommonPhysicPath( void ) const;
public:    virtual bCString         GetLightmapPath( void ) const;
protected: virtual void             OnEngineReadyForBenchmark( void );
protected: virtual void             OnEngineCreated( void );
protected: virtual void             OnDestroyEngine( void );
protected: virtual void             OnDestroyWorkspace( void );
protected: virtual bEResult         OnInitializeEngine( void );
protected: virtual bEResult         CreateWorkspace( void );
protected: virtual GEBool           OnHandleMessage( GEUInt, GEUInt, GEI32, GEI32 * );
public:    virtual GEBool           LoadConfiguration( void );
public:    virtual GEBool           SaveConfiguration( void );
protected: using          eCWindow::Create;
protected: using     eCApplication::Create;
protected: using     eCApplication::OnQuit;
protected:
    char __FIXME[ 0x0BA8 - sizeof(eCApplication) ];
public:
    gCGameApp( void );
public:
    gCGameApp & operator = ( gCGameApp const & );
public:
    gCWorkspace &        GetAccessToWorkspace( void );
    bCString const &     GetBackupFolder( void ) const;
    GEBool const         GetScriptAutoLoading( void ) const;
    bCString const &     GetScriptFolder( void ) const;
protected:
    void     AddAutodetectEntrys( bTValArray< GEU64 > &, GEU32, bCString const & );
    bEResult AutoBenchmark( void );
    bEResult AutoDetection( void );
    bEResult BuildUserOptions( GEU32 );
    void     Invalidate( void );
};
GE_ASSERT_SIZEOF( gCGameApp, 0x0BA8 )

#endif
