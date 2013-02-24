#ifndef GE_INPUTADMIN_H_INCLUDED
#define GE_INPUTADMIN_H_INCLUDED

enum eERawInputAxis
{
    eERawInputAxis_Undefined,
    eERawInputAxis_Mouse_X,
    eERawInputAxis_Mouse_Y,
    eERawInputAxis_GamePad_1,
    eERawInputAxis_GamePad_2,
    eERawInputAxis_GamePad_3,
    eERawInputAxis_GamePad_4,
    eERawInputAxis_Count,
    eERawInputAxis_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA GELPCChar const g_ppszRawInputAxisNames[ eERawInputAxis_Count ];

enum eEScanCode
{
    eEScanCode_ESC                = 0x00000001,
    eEScanCode_1                  = 0x00000002,
    eEScanCode_2                  = 0x00000003,
    eEScanCode_3                  = 0x00000004,
    eEScanCode_4                  = 0x00000005,
    eEScanCode_5                  = 0x00000006,
    eEScanCode_6                  = 0x00000007,
    eEScanCode_7                  = 0x00000008,
    eEScanCode_8                  = 0x00000009,
    eEScanCode_9                  = 0x0000000A,
    eEScanCode_0                  = 0x0000000B,
    eEScanCode_SZ                 = 0x0000000C,
    eEScanCode_AKUT               = 0x0000000D,
    eEScanCode_BACKSPACE          = 0x0000000E,
    eEScanCode_TAB                = 0x0000000F,
    eEScanCode_Q                  = 0x00000010,
    eEScanCode_W                  = 0x00000011,
    eEScanCode_E                  = 0x00000012,
    eEScanCode_R                  = 0x00000013,
    eEScanCode_T                  = 0x00000014,
    eEScanCode_Z                  = 0x00000015,
    eEScanCode_U                  = 0x00000016,
    eEScanCode_I                  = 0x00000017,
    eEScanCode_O                  = 0x00000018,
    eEScanCode_P                  = 0x00000019,
    eEScanCode_UE                 = 0x0000001A,
    eEScanCode_PLUS               = 0x0000001B,
    eEScanCode_RETURN             = 0x0000001C,
    eEScanCode_CTRL_L             = 0x0000001D,
    eEScanCode_A                  = 0x0000001E,
    eEScanCode_S                  = 0x0000001F,
    eEScanCode_D                  = 0x00000020,
    eEScanCode_F                  = 0x00000021,
    eEScanCode_G                  = 0x00000022,
    eEScanCode_H                  = 0x00000023,
    eEScanCode_J                  = 0x00000024,
    eEScanCode_K                  = 0x00000025,
    eEScanCode_L                  = 0x00000026,
    eEScanCode_OE                 = 0x00000027,
    eEScanCode_AE                 = 0x00000028,
    eEScanCode_CIRCUMFLEX         = 0x00000029,
    eEScanCode_SHIFT_L            = 0x0000002A,
    eEScanCode_CROSSHATCH         = 0x0000002B,
    eEScanCode_Y                  = 0x0000002C,
    eEScanCode_X                  = 0x0000002D,
    eEScanCode_C                  = 0x0000002E,
    eEScanCode_V                  = 0x0000002F,
    eEScanCode_B                  = 0x00000030,
    eEScanCode_N                  = 0x00000031,
    eEScanCode_M                  = 0x00000032,
    eEScanCode_COMMA              = 0x00000033,
    eEScanCode_POINT              = 0x00000034,
    eEScanCode_MINUS              = 0x00000035,
    eEScanCode_SHIFT_R            = 0x00000036,
    eEScanCode_ALT_L              = 0x00000038,
    eEScanCode_SPACE              = 0x00000039,
    eEScanCode_CAPSLOCK           = 0x0000003A,
    eEScanCode_F1                 = 0x0000003B,
    eEScanCode_F2                 = 0x0000003C,
    eEScanCode_F3                 = 0x0000003D,
    eEScanCode_F4                 = 0x0000003E,
    eEScanCode_F5                 = 0x0000003F,
    eEScanCode_F6                 = 0x00000040,
    eEScanCode_F7                 = 0x00000041,
    eEScanCode_F8                 = 0x00000042,
    eEScanCode_F9                 = 0x00000043,
    eEScanCode_F10                = 0x00000044,
    eEScanCode_PAUSE              = 0x00000045,
    eEScanCode_SCROLLLOCK         = 0x00000046,
    eEScanCode_NUM_7              = 0x00000047,
    eEScanCode_NUM_8              = 0x00000048,
    eEScanCode_NUM_9              = 0x00000049,
    eEScanCode_NUM_MINUS          = 0x0000004A,
    eEScanCode_NUM_4              = 0x0000004B,
    eEScanCode_NUM_5              = 0x0000004C,
    eEScanCode_NUM_6              = 0x0000004D,
    eEScanCode_NUM_PLUS           = 0x0000004E,
    eEScanCode_NUM_1              = 0x0000004F,
    eEScanCode_NUM_2              = 0x00000050,
    eEScanCode_NUM_3              = 0x00000051,
    eEScanCode_NUM_0              = 0x00000052,
    eEScanCode_NUM_DECIMAL        = 0x00000053,
    eEScanCode_SMALLER            = 0x00000056,
    eEScanCode_F11                = 0x00000057,
    eEScanCode_F12                = 0x00000058,
    eEScanCode_ENTER              = 0x0000011C,
    eEScanCode_CTRL_R             = 0x0000011D,
    eEScanCode_PRINT              = 0x00000137,
    eEScanCode_ALT_R              = 0x00000138,
    eEScanCode_NUMLOCK            = 0x00000145,
    eEScanCode_BREAK              = 0x00000146,
    eEScanCode_HOME               = 0x00000147,
    eEScanCode_CURSOR_UP          = 0x00000148,
    eEScanCode_PAGE_UP            = 0x00000149,
    eEScanCode_CURSOR_LEFT        = 0x0000014B,
    eEScanCode_CURSOR_RIGHT       = 0x0000014D,
    eEScanCode_END                = 0x0000014F,
    eEScanCode_CURSOR_DOWN        = 0x00000150,
    eEScanCode_PAGE_DOWN          = 0x00000151,
    eEScanCode_INSERT             = 0x00000152,
    eEScanCode_DELETE             = 0x00000153,
    eEScanCode_WINDOWS_L          = 0x0000015B,
    eEScanCode_WINDOWS_R          = 0x0000015C,
    eEScanCode_Mouse_ButtonLeft   = 0x00000200,
    eEScanCode_Mouse_ButtonRight  = 0x00000201,
    eEScanCode_Mouse_ButtonMiddle = 0x00000202,
    eEScanCode_Mouse_Button4      = 0x00000203,
    eEScanCode_Mouse_Button5      = 0x00000204,
    eEScanCode_Mouse_WheelUp      = 0x00000205,
    eEScanCode_Mouse_WheelDown    = 0x00000206,
    eEScanCode_Count              = 0x00000207,
    eEScanCode_ForceDWORD         = GE_FORCE_DWORD
};

class eIInputReceiver
{
public: virtual void KeyPressed( GEU32 )         = 0;
public: virtual void KeyReleased( GEU32 )        = 0;
public: virtual void AnalogInput( GEU32, GEInt ) = 0;
public: virtual void DebugKeyPressed( GEU32 )    = 0;
public: virtual void DebugKeyReleased( GEU32 )   = 0;
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'eCInputAdmin'

class GE_DLLIMPORT eCInputAdmin :
    public eCEngineComponentBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     IsValid( void ) const;
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual                           ~eCInputAdmin( void );
public: virtual bEResult                   Initialize( void );
public: virtual bEResult                   Shutdown( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCInputAdmin( eCInputAdmin const & );
    eCInputAdmin( void );
public:
    eCInputAdmin & operator = ( eCInputAdmin const & );
public:
    void   AddAxisAction( GEU32, GEU32 );
    void   AddKeyAction( GEU32, GEU32, GEU8 );
    void   AddKeyDebug( GEU32, GEU32, GEU32 );
    void   ChangeKeyAction( GEU32, GEU32, GEU32 );
    void   ClearActions( void );
    GEBool DispatchAnalogInput( GEU32, GEU32 );
    GEBool DispatchKeyPressed( GEU32 );
    GEBool DispatchKeyReleased( GEU32 );
    GEU32  GetActionKey( eEScanCode ) const;
    GEBool GetRawKeyState( eEScanCode );
    GEU8   GetUseIndex( eEScanCode ) const;
    void   Invalidate( void );
    GEBool OnHandleMessage( GEUInt, GEUInt, long );
    void   ResetBufferedInput( void );
    void   SetInputReceiver( eIInputReceiver * );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEBool              m_arrRawKeyStates[ eEScanCode_Count ];
                        GE_PADDING( 1 )
    GEU32               m_arrKeyEntries[ eEScanCode_Count ];
    GEU32               m_arrAxisActions[ eERawInputAxis_Count ];
    bTValArray< GEU32 > m_arrSecondaryDebugScanCodeArrays[ eEScanCode_Count ];
    bTValArray< GEU32 > m_arrSecondaryDebugScanCodes;
    eIInputReceiver *   m_pInputReceiver;
};
GE_ASSERT_SIZEOF( eCInputAdmin, 0x22B4 );

#pragma warning( pop )

#endif