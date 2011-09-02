#ifndef GE_APPLICATION_H_INCLUDED
#define GE_APPLICATION_H_INCLUDED

//FIXME: eCApplication dependencies.
struct eSSetupApplication{};
struct eSSetupWindow{};
namespace eCGfxShared{ struct eSGfxContextDesc{}; };

class GE_DLLIMPORT eCApplication :
    public eCWindow
{
public:
    struct eSHardwareEnvironmentDesc
    {
        //FIXME: eCApplication::eSHardwareEnvironmentDesc members.
    };

public:    virtual eCEntity const * GetEditorEntity( void ) const;
public:    virtual GEBool           IsCompilerRunning( void ) const;
public:    virtual GEBool           IsEditorRunning( void ) const;
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
public:    virtual void             Draw( HWND );
protected: virtual void             OnEngineReadyForBenchmark( void );
protected: virtual void             OnEngineCreated( void );
protected: virtual void             OnDestroyEngine( void );
protected: virtual void             OnDestroyWorkspace( void );
protected: virtual void             OnPostInitializeModules( void );
protected: virtual bEResult         OnInitializeApplication( eSSetupApplication & );
protected: virtual bEResult         OnCreateWindow( eCWindow::eSCreate & );
protected: virtual bEResult         OnInitializeEngine( void );
protected: virtual void             OnPostRender( void );
protected: virtual void             OnPreRender( void );
protected: virtual void             OnRenderDraw( void );
public:    virtual void             OnRun( void );
public:    virtual void             OnProcess( void );
public:    virtual void             OnWorldActivate( void );
public:    virtual void             OnWorldDeactivate( void );
public:    virtual void             SendEngineMessage( eSEngineMessage & );
protected: virtual bEResult         CreateWorkspace( void );
protected: virtual void             DestroyWorkspace( void );
protected: virtual void             CopyFrom( eCApplication const & );
protected: virtual GEBool           OnHandleMessage( GEUInt, GEUInt, GEI32, GEI32 * );
public:    virtual GEBool           LoadConfiguration( void );
public:    virtual GEBool           SaveConfiguration( void );
// eCWindow
protected: virtual bEResult         Create( void );
public:    virtual void             Destroy( void );
public:    virtual                 ~eCApplication( void );
protected: virtual GEInt            HandleMessage( HWND, GEUInt, GEUInt,GEI32 );
protected: virtual GEInt            OnIdle( GEUInt, GEI32 );
protected: virtual GEInt            OnSize( GEUInt, GEI32 );
protected: virtual GEInt            OnPaint( GEUInt, GEI32 );
protected: virtual GEInt            OnKillFocus( GEUInt, GEI32 );
protected: virtual GEInt            OnSetFocus( GEUInt, GEI32 );
protected: virtual GEInt            OnSysCommand( GEUInt, GEI32 );
protected: using      bCObjectBase::CopyFrom;
protected: using  eCMessageHandler::HandleMessage;
protected: using          eCWindow::Create;
protected: using          eCWindow::OnQuit;
protected:
    char __FIXME[ 0x0B98 - sizeof(eCWindow) ];
public:
    static void            GE_STDCALL CreateSplashScreen( void );
    static void            GE_STDCALL DestroySplashScreen( void );
    static eCApplication & GE_STDCALL GetInstance( void );
    static GEBool          GE_STDCALL IsEngineCreated( void );
    static GEBool          GE_STDCALL IsInitialised( void );
public:
    eCApplication( void );
    eCApplication( eCApplication const & );
public:
    void                                  ConfineCursor( void );
    bEResult                              Create( HINSTANCE, bCString const &, bCString const & );
    void                                  DrawTo( HWND );
    void                                  DrawTo( HWND, eCCameraBase const & );
    GEU32                                 GetAppState( void ) const;
    GEU32                                 GetAppStateTimeStamp( void ) const;
    bCString                              GetApplicationFileName( void );
    bCString                              GetApplicationVersionString( void );
    bCString const &                      GetCommandLineA( void ) const;
    eCConsole2 &                          GetConsole2( void );
    eCCameraBase &                        GetCurrentCamera( void );
    eSSetupWindow const &                 GetEngineSetup( void ) const;
    void                                  GetFileVersion( GEU32 &, GEU32 &, GEU32 &, GEU32 & );
    eSHardwareEnvironmentDesc &           GetHardwareEnvironmentDesc( void );
    bCString const &                      GetLastSnapshotName( void ) const;
    eCCameraBase &                        GetMainCamera( void );
    eCModuleAdmin &                       GetModuleAdmin( void );
    eCGfxShared::eSGfxContextDesc const & GetResolutionDesc( void ) const;
    eSSetupWindow const &                 GetSetupWindowDesc( void ) const;
    GEBool                                IsCameraValid( void ) const;
    GEBool                                IsInAdvancedTestMode( void ) const;
    GEBool                                IsInCompilingState( void ) const;
    void                                  OnQuit( void );
    void                                  PlayIntros( void );
    void                                  PlayVideo( bCString const &, GEBool );
    void                                  Process( void );
    void                                  RenderAndDrawTo( HWND, GEBool );
    void                                  RenderAndDrawTo( HWND, eCCameraBase const &, GEBool );
    void                                  RequestAppState( GEU32 );
    bEResult                              Run( void );
    void                                  SaveStatistics( void );
    void                                  SaveUserResolution( void );
    void                                  SetAdvancedTestMode( GEBool );
    void                                  SetAppState( GEU32 );
    void                                  SetCurrentCamera( eCCameraBase const * );
    GEBool                                SetFullscreen( GEBool );
    void                                  SetIntoCompilingState( GEBool );
    void                                  SetMainCamera( eCCameraBase const * );
    GEBool                                SetResolution( GEU32, GEU32, eCWindow::eEWindowMode );
    GEBool                                SetResolutionEx( GEU32, GEU32, GEU32, GEU32, eCWindow::eEWindowMode );
    void                                  SetTargetWindow( HWND );
    void                                  Snapshot( void );
    void                                  SnapshotEx( bCString const & );
    void                                  ToggleDebugResolution( void );
    GEBool                                ToggleFullscreen( void );
    void                                  ToggleGlobalStatistics( void );
protected:
    static GEBool          ms_bEngineCreated;
    static GEBool          ms_bInitialised;
    static eCApplication * ms_pApplication;
    static eCSplash *      ms_pSplash;
protected:
    static GEBool GE_STDCALL g_ErrorApplicationCall( bEErrorType, GEU32 );
    static GEBool GE_STDCALL g_TerminateApplicationCall( bEErrorType, GEU32 );
protected:
    eCApplication const & operator = ( eCApplication const & );
protected:
    void     CalculateHardwareEnvironment( void );
    GEBool   CheckAppStateFlags( GEU32 );
    void     CopyTo( eCApplication & ) const;
    bEResult CreateEngine( void );
    bEResult CreateGraphicsSubsystem( eSSetupWindow &, GEBool );
    bEResult CreateModules( void );
    void     CreateSoundSubsystem( eSSetupWindow & );
    void     DestroyEngine( void );
    void     DestroyGraphicsSubsystem( void );
    void     DestroyModules( void );
    void     DestroySoundSubsystem( void );
    void     DoRender( GEBool );
    void     DoSnapshot( void );
    void     Invalidate( void );
    GEBool   Reset( void );
};
GE_ASSERT_SIZEOF( eCApplication, 0x0B98 )

#endif
