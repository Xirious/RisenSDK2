#ifndef GE_WINDOW_H_INCLUDED
#define GE_WINDOW_H_INCLUDED

class GE_DLLIMPORT eCWindow :
    public eCMessageHandler
{
public:
    enum eEWindowMode
    {
        eEWindowMode_Dialog     = 0x00C80000,  // WS_CAPTION | WS_SYSMENU
        eEWindowMode_Sizeable   = 0x00CF0000,  // WS_OVERLAPPEDWINDOW
        eEWindowMode_FullScreen = 0x90000000   // WS_POPUP | WS_VISIBLE
    };
    struct eSCreate
    {
        HINSTANCE    m_hInstance;
        HWND         m_hHandle;
        GELPVoid     m_funcWindowProc;
        eEWindowMode m_enumWindowMode;
        bCString     m_strCaption;
        bCRect       m_rectWindowSize;
        GEBool       m_bCenter;
                     GE_PADDING( 3 )
    };
    GE_ASSERT_SIZEOF( eSCreate, 0x0028 )

public:    virtual GEBool   Create( eSCreate const & );
// eCMessageHandler
protected: virtual bEResult Create( void );
protected: virtual void     Destroy( void );
public:    virtual         ~eCWindow( void );
protected: virtual GEInt    OnActivate( GEUInt, GEI32 );
protected: virtual GEInt    OnDestroy( GEUInt, GEI32 );
protected: virtual GEInt    OnQuit( GEUInt, GEI32 );
protected: virtual GEInt    OnPaint( GEUInt, GEI32 );
protected:
    eEWindowMode m_enumWindowMode;
    HINSTANCE    m_hInstance;
    GEBool       m_bCreated;
    GEBool       m_bAttached;
    GEBool       m_bSubClassed;
    GEBool       m_bMinimized;
    GEBool       m_bActive;
                 GE_PADDING( 3 )
public:
    eCWindow( void );
    eCWindow( eCWindow const & );
public:
    eCWindow & operator =               ( eCWindow const & );
               operator HINSTANCE       ( void );
               operator HINSTANCE const ( void ) const;
               operator HWND            ( void );
               operator HWND const      ( void ) const;
public:
    void             AttachTo( HINSTANCE const, HDC const );
    void             AttachTo( HINSTANCE const, HWND const );
    void             Center( void );
    GEInt            GetClientHeight( void ) const;
    GEInt            GetClientWidth( void ) const;
    HDC              GetDeviceContext( void ) const;
    HWND             GetHandle( void ) const;
    HINSTANCE        GetInstance( void ) const;
    bCRect           GetPosition( void ) const;
    GEInt            GetWindowHeight( void ) const;
    eEWindowMode     GetWindowMode( void ) const;
    GEInt            GetWindowWidth( void ) const;
    GEBool           IsAttached( void ) const;
    GEBool           IsCreated( void ) const;
    GEBool           IsSubClassed( void ) const;
    GEBool           IsTopMost( void ) const;
    GEBool           IsVisible( void ) const;
    GEI32 GE_STDCALL SendMessageA( GEUInt, GEUInt, GEI32 );
    GEBool           SetCaption( bCString const & );
    GEBool           SetClientSize( GEInt, GEInt, GEBool );
    GEBool           SetPosition( bCRect const & );
    GEBool           SetResolution( GEU32, GEU32, eEWindowMode );
    GEBool           SetResolutionEx( GEU32, GEU32, GEU32, GEU32, eEWindowMode );
    void             SetTopMost( GEBool );
    void             SetVisible( GEBool );
    void             SetWindowMode( eEWindowMode );
    GEBool           SetWindowSize( GEInt, GEInt, GEBool );
    void             Validate( void );
protected:
    static GEInt ms_iDesktopHeight;
    static GEInt ms_iDesktopWidth;
protected:
    static GEI32 GE_STDCALL Receive( HWND, GEUInt, GEUInt, GEI32 );
    static void  GE_STDCALL RegisterWindow( HWND, eCWindow * );
protected:
    GEBool Create( HINSTANCE, GELPVoid, bCString const &, bCRect const &, eEWindowMode );
    GEBool Create( HINSTANCE, GELPVoid, eEWindowMode );
    void   Invalidate( void );
};
GE_ASSERT_SIZEOF( eCWindow, 0x0020 )

#endif
