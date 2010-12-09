#ifndef GE_MESSAGEHANDLER_H_INCLUDED
#define GE_MESSAGEHANDLER_H_INCLUDED

class GE_DLLIMPORT eCMessageHandler :
    public bCObjectRefBase
{
public:    virtual      ~eCMessageHandler( void );                                 // [0000].0070
public:    virtual HWND  GetWindowHandle( void );                                  // [0000].0074
public:    virtual void  SetWindowHandle( HWND );                                  // [0000].0078
public:    virtual void  Idle( void );                                             // [0000].007C
public:    virtual GEInt LoopMessages( void );                                     // [0000].0080
public:    virtual void  ProcessNextMessage( MSG &, GEBool &, GEBool &, GEBool );  // [0000].0084
public:    virtual GEInt ProcessNextMessage( void );                               // [0000].0088
public:    virtual GEInt HandleMessage( GEUInt, GEUInt, GEI32 );                   // [0000].008C
public:    virtual GEInt HandleMessage( HWND, GEUInt, GEUInt, GEI32 );             // [0000].0090
public:    virtual GEInt OnMessage( GEUInt, GEUInt, GEI32 );                       // [0000].0094
protected: virtual GEInt OnIdle( GEUInt, GEI32 );                                  // [0000].0098
protected: virtual GEInt OnUser( GEUInt, GEI32 );                                  // [0000].009C
protected: virtual GEInt OnEngine( GEUInt, GEI32 );                                // [0000].00A0
protected: virtual GEInt OnGameApplication( GEUInt, GEI32 );                       // [0000].00A4
protected: virtual GEInt OnActivate( GEUInt, GEI32 );                              // [0000].00A8
protected: virtual GEInt OnActivateApp( GEUInt, GEI32 );                           // [0000].00AC
protected: virtual GEInt OnCancelMode( GEUInt, GEI32 );                            // [0000].00B0
protected: virtual GEInt OnChildActivate( GEUInt, GEI32 );                         // [0000].00B4
protected: virtual GEInt OnClose( GEUInt, GEI32 );                                 // [0000].00B8
protected: virtual GEInt OnCompacting( GEUInt, GEI32 );                            // [0000].00BC
protected: virtual GEInt OnCreate( GEUInt, GEI32 );                                // [0000].00C0
protected: virtual GEInt OnDestroy( GEUInt, GEI32 );                               // [0000].00C4
protected: virtual GEInt OnEnable( GEUInt, GEI32 );                                // [0000].00C8
protected: virtual GEInt OnEnterSizeMove( GEUInt, GEI32 );                         // [0000].00CC
protected: virtual GEInt OnExitSizeMove( GEUInt, GEI32 );                          // [0000].00D0
protected: virtual GEInt OnGetIcon( GEUInt, GEI32 );                               // [0000].00D4
protected: virtual GEInt OnGetMinMaxInfo( GEUInt, GEI32 );                         // [0000].00D8
protected: virtual GEInt OnGetText( GEUInt, GEI32 );                               // [0000].00DC
protected: virtual GEInt OnGetTextLength( GEUInt, GEI32 );                         // [0000].00E0
protected: virtual GEInt OnInputLangChange( GEUInt, GEI32 );                       // [0000].00E4
protected: virtual GEInt OnInputLangChangeRequest( GEUInt, GEI32 );                // [0000].00E8
protected: virtual GEInt OnMove( GEUInt, GEI32 );                                  // [0000].00EC
protected: virtual GEInt OnMoving( GEUInt, GEI32 );                                // [0000].00F0
protected: virtual GEInt OnNcAvtivate( GEUInt, GEI32 );                            // [0000].00F4
protected: virtual GEInt OnNcCalcSize( GEUInt, GEI32 );                            // [0000].00F8
protected: virtual GEInt OnNcCreate( GEUInt, GEI32 );                              // [0000].00FC
protected: virtual GEInt OnNcDestroy( GEUInt, GEI32 );                             // [0000].0100
protected: virtual GEInt OnParentNotify( GEUInt, GEI32 );                          // [0000].0104
protected: virtual GEInt OnQueryDragIcon( GEUInt, GEI32 );                         // [0000].0108
protected: virtual GEInt OnQueryOpen( GEUInt, GEI32 );                             // [0000].010C
protected: virtual GEInt OnQuit( GEUInt, GEI32 );                                  // [0000].0110
protected: virtual GEInt OnSetIcon( GEUInt, GEI32 );                               // [0000].0114
protected: virtual GEInt OnSetText( GEUInt, GEI32 );                               // [0000].0118
protected: virtual GEInt OnSettingChange( GEUInt, GEI32 );                         // [0000].011C
protected: virtual GEInt OnShowWindow( GEUInt, GEI32 );                            // [0000].0120
protected: virtual GEInt OnSize( GEUInt, GEI32 );                                  // [0000].0124
protected: virtual GEInt OnSizing( GEUInt, GEI32 );                                // [0000].0128
protected: virtual GEInt OnStyleChanged( GEUInt, GEI32 );                          // [0000].012C
protected: virtual GEInt OnStyleChanging( GEUInt, GEI32 );                         // [0000].0130
protected: virtual GEInt OnUserChanged( GEUInt, GEI32 );                           // [0000].0134
protected: virtual GEInt OnWindowPosChanged( GEUInt, GEI32 );                      // [0000].0138
protected: virtual GEInt OnWindowPosChanging( GEUInt, GEI32 );                     // [0000].013C
protected: virtual GEInt OnDisplayChange( GEUInt, GEI32 );                         // [0000].0140
protected: virtual GEInt OnEraseBackground( GEUInt, GEI32 );                       // [0000].0144
protected: virtual GEInt OnIconEraseBackground( GEUInt, GEI32 );                   // [0000].0148
protected: virtual GEInt OnNcPaint( GEUInt, GEI32 );                               // [0000].014C
protected: virtual GEInt OnPaint( GEUInt, GEI32 );                                 // [0000].0150
protected: virtual GEInt OnPaintIcon( GEUInt, GEI32 );                             // [0000].0154
protected: virtual GEInt OnPrint( GEUInt, GEI32 );                                 // [0000].0158
protected: virtual GEInt OnPrintClient( GEUInt, GEI32 );                           // [0000].015C
protected: virtual GEInt OnSetReDraw( GEUInt, GEI32 );                             // [0000].0160
protected: virtual GEInt OnSyncPaint( GEUInt, GEI32 );                             // [0000].0164
protected: virtual GEInt OnPaletteChanged( GEUInt, GEI32 );                        // [0000].0168
protected: virtual GEInt OnPaletteIsChanging( GEUInt, GEI32 );                     // [0000].016C
protected: virtual GEInt OnQueryNewPalette( GEUInt, GEI32 );                       // [0000].0170
protected: virtual GEInt OnSysColorChange( GEUInt, GEI32 );                        // [0000].0174
protected: virtual GEInt OnCaptureChanged( GEUInt, GEI32 );                        // [0000].0178
protected: virtual GEInt OnMouseButtonLeftClickDouble( GEUInt, GEI32 );            // [0000].017C
protected: virtual GEInt OnMouseButtonLeftDown( GEUInt, GEI32 );                   // [0000].0180
protected: virtual GEInt OnMouseButtonLeftUp( GEUInt, GEI32 );                     // [0000].0184
protected: virtual GEInt OnMouseButtonMiddleClickDouble( GEUInt, GEI32 );          // [0000].0188
protected: virtual GEInt OnMouseButtonMiddleDown( GEUInt, GEI32 );                 // [0000].018C
protected: virtual GEInt OnMouseButtonMiddleUp( GEUInt, GEI32 );                   // [0000].0190
protected: virtual GEInt OnMouseActivate( GEUInt, GEI32 );                         // [0000].0194
protected: virtual GEInt OnMouseMove( GEUInt, GEI32 );                             // [0000].0198
protected: virtual GEInt OnMouseWheel( GEUInt, GEI32 );                            // [0000].019C
protected: virtual GEInt OnNcHitTest( GEUInt, GEI32 );                             // [0000].01A0
protected: virtual GEInt OnNcMouseButtonLeftClickDouble( GEUInt, GEI32 );          // [0000].01A4
protected: virtual GEInt OnNcMouseButtonLeftDown( GEUInt, GEI32 );                 // [0000].01A8
protected: virtual GEInt OnNcMouseButtonLeftUp( GEUInt, GEI32 );                   // [0000].01AC
protected: virtual GEInt OnNcMouseButtonMiddleClickDouble( GEUInt, GEI32 );        // [0000].01B0
protected: virtual GEInt OnNcMouseButtonMiddleDown( GEUInt, GEI32 );               // [0000].01B4
protected: virtual GEInt OnNcMouseButtonMiddleUp( GEUInt, GEI32 );                 // [0000].01B8
protected: virtual GEInt OnNcMouseMove( GEUInt, GEI32 );                           // [0000].01BC
protected: virtual GEInt OnNcMouseButtonRightClickDouble( GEUInt, GEI32 );         // [0000].01C0
protected: virtual GEInt OnNcMouseButtonRightDown( GEUInt, GEI32 );                // [0000].01C4
protected: virtual GEInt OnNcMouseButtonRightUp( GEUInt, GEI32 );                  // [0000].01C8
protected: virtual GEInt OnMouseButtonRightClickDouble( GEUInt, GEI32 );           // [0000].01CC
protected: virtual GEInt OnMouseButtonRightDown( GEUInt, GEI32 );                  // [0000].01D0
protected: virtual GEInt OnMouseButtonRightUp( GEUInt, GEI32 );                    // [0000].01D4
protected: virtual GEInt OnChar( GEUInt, GEI32 );                                  // [0000].01D8
protected: virtual GEInt OnDeadChar( GEUInt, GEI32 );                              // [0000].01DC
protected: virtual GEInt OnGetHotKey( GEUInt, GEI32 );                             // [0000].01E0
protected: virtual GEInt OnHotKey( GEUInt, GEI32 );                                // [0000].01E4
protected: virtual GEInt OnKeyDown( GEUInt, GEI32 );                               // [0000].01E8
protected: virtual GEInt OnKeyUp( GEUInt, GEI32 );                                 // [0000].01EC
protected: virtual GEInt OnKillFocus( GEUInt, GEI32 );                             // [0000].01F0
protected: virtual GEInt OnSetFocus( GEUInt, GEI32 );                              // [0000].01F4
protected: virtual GEInt OnSetHotKey( GEUInt, GEI32 );                             // [0000].01F8
protected: virtual GEInt OnSysChar( GEUInt, GEI32 );                               // [0000].01FC
protected: virtual GEInt OnSysDeadChar( GEUInt, GEI32 );                           // [0000].0200
protected: virtual GEInt OnSysKeyDown( GEUInt, GEI32 );                            // [0000].0204
protected: virtual GEInt OnSysKeyUp( GEUInt, GEI32 );                              // [0000].0208
protected: virtual GEInt OnCommand( GEUInt, GEI32 );                               // [0000].020C
protected: virtual GEInt OnSysCommand( GEUInt, GEI32 );                            // [0000].0210
protected: virtual GEInt OnContextMenu( GEUInt, GEI32 );                           // [0000].0214
protected: virtual GEInt OnDrawItem( GEUInt, GEI32 );                              // [0000].0218
protected: virtual GEInt OnEnterMenuLoop( GEUInt, GEI32 );                         // [0000].021C
protected: virtual GEInt OnInitMenu( GEUInt, GEI32 );                              // [0000].0220
protected: virtual GEInt OnInitMenuPopUp( GEUInt, GEI32 );                         // [0000].0224
protected: virtual GEInt OnMeasureItem( GEUInt, GEI32 );                           // [0000].0228
protected: virtual GEInt OnMenuChar( GEUInt, GEI32 );                              // [0000].022C
protected: virtual GEInt OnMenuSelect( GEUInt, GEI32 );                            // [0000].0230
protected: virtual GEInt OnNextMenu( GEUInt, GEI32 );                              // [0000].0234
protected: virtual GEInt OnAskClipBoardFormatName( GEUInt, GEI32 );                // [0000].0238
protected: virtual GEInt OnChangeClipBoardChain( GEUInt, GEI32 );                  // [0000].023C
protected: virtual GEInt OnClear( GEUInt, GEI32 );                                 // [0000].0240
protected: virtual GEInt OnCopy( GEUInt, GEI32 );                                  // [0000].0244
protected: virtual GEInt OnCut( GEUInt, GEI32 );                                   // [0000].0248
protected: virtual GEInt OnDestroyClipBoard( GEUInt, GEI32 );                      // [0000].024C
protected: virtual GEInt OnDrawClipBoard( GEUInt, GEI32 );                         // [0000].0250
protected: virtual GEInt OnHorizontalScrollClipBoard( GEUInt, GEI32 );             // [0000].0254
protected: virtual GEInt OnPaintClipBoard( GEUInt, GEI32 );                        // [0000].0258
protected: virtual GEInt OnPaste( GEUInt, GEI32 );                                 // [0000].025C
protected: virtual GEInt OnRenderAllFormats( GEUInt, GEI32 );                      // [0000].0260
protected: virtual GEInt OnRenderFormat( GEUInt, GEI32 );                          // [0000].0264
protected: virtual GEInt OnSizeClipBoard( GEUInt, GEI32 );                         // [0000].0268
protected: virtual GEInt OnVerticalScrollClipBoard( GEUInt, GEI32 );               // [0000].026C
protected: virtual GEInt OnTimer( GEUInt, GEI32 );                                 // [0000].0270
protected: virtual GEInt OnCopyData( GEUInt, GEI32 );                              // [0000].0274
protected:
    GEBool m_bEnabled;        // 0008
    GEBool m_bIdleActivated;  // 0009
    GEBool m_bRedirected;     // 000A
    GEBool m_bTerminated;     // 000B
    HWND   m_hWindowHandle;   // 000C
    // sizeof(eCMessageHandler)  0010
public:
    void ActivateIdle( GEBool );
    void Enable( GEBool );
    void Redirect( GEBool );
    void Terminate( GEBool );
public:
    eCMessageHandler & operator = ( eCMessageHandler const & );
public:
    eCMessageHandler( eCMessageHandler const & );
    eCMessageHandler( void );
};

#endif
