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
public:
    struct eSCreate
    {
        HINSTANCE    m_hInstance;       // 0000
        HWND         m_hHandle;         // 0004
        GELPVoid     m_funcWindowProc;  // 0008
        eEWindowMode m_enumWindowMode;  // 000C
        bCString     m_strCaption;      // 0010
        bCRect       m_rectWindowSize;  // 0014
        GEBool       m_bCenter;         // 0024
                     GE_PADDING( 3 )
        // sizeof(eCWindow::eSCreate)      0028
    };
protected: virtual bEResult Create( void );               // 002C
protected: virtual void     Destroy( void );              // 0030
public:    virtual         ~eCWindow( void );             // 0070
protected: virtual GEInt    OnActivate( GEUInt, GEI32 );  // 00A8
protected: virtual GEInt    OnDestroy( GEUInt, GEI32 );   // 00C4
protected: virtual GEInt    OnQuit( GEUInt, GEI32 );      // 0110
protected: virtual GEInt    OnPaint( GEUInt, GEI32 );     // 0150
public:    virtual GEBool   Create( eSCreate const & );   // 0278
protected:
    static GEInt ms_iDesktopHeight;
    static GEInt ms_iDesktopWidth;
protected:
    eEWindowMode m_enumWindowMode;  // 0010
    HINSTANCE    m_hInstance;       // 0014
    GEBool       m_bCreated;        // 0018
    GEBool       m_bAttached;       // 0019
    GEBool       m_bSubClassed;     // 001A
    GEBool       m_bMinimized;      // 001B
    GEBool       m_bActive;         // 001C
                 GE_PADDING( 3 )
    // sizeof(eCWindow)                0020
protected:
    static GEI32 GE_STDCALL Receive( HWND, GEUInt, GEUInt, GEI32 );
    static void  GE_STDCALL RegisterWindow( HWND, eCWindow * );
protected:
    GEBool Create( HINSTANCE, GELPVoid, bCString const &, bCRect const &, eEWindowMode );
    GEBool Create( HINSTANCE, GELPVoid, eEWindowMode );
    void   Invalidate( void );
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
public:
               operator HINSTANCE       ( void );
               operator HINSTANCE const ( void ) const;
               operator HWND            ( void );
               operator HWND const      ( void ) const;
    eCWindow & operator =               ( eCWindow const & );
public:
    eCWindow( eCWindow const & );
    eCWindow( void );
};

#endif
