#ifndef GE_ACTIONADMIN_H_INCLUDED
#define GE_ACTIONADMIN_H_INCLUDED

enum gEActionAxis
{
    gEActionAxis_Undefined,
    gEActionAxis_TurnLeftRight,
    gEActionAxis_TurnUpDown,
    gEActionAxis_Count,
    gEActionAxis_ForceDWORD = GE_FORCE_DWORD
};

enum gEActionKey
{
    gEActionKey_Undefined,
    gEActionKey_MoveForward,
    gEActionKey_MoveBackward,
    gEActionKey_MoveLeft,
    gEActionKey_MoveRight,
    gEActionKey_MoveUp,
    gEActionKey_MoveDown,
    gEActionKey_TurnLeft,
    gEActionKey_TurnRight,
    gEActionKey_TurnUp,
    gEActionKey_TurnDown,
    gEActionKey_ZoomIn,
    gEActionKey_ZoomOut,
    gEActionKey_LookBack,
    gEActionKey_Walk,
    gEActionKey_WeaponMode,
    gEActionKey_PrimaryAction,
    gEActionKey_SecondaryAction,
    gEActionKey_QuickUse0,
    gEActionKey_QuickUse1,
    gEActionKey_QuickUse2,
    gEActionKey_QuickUse3,
    gEActionKey_QuickUse4,
    gEActionKey_QuickUse5,
    gEActionKey_QuickUse6,
    gEActionKey_QuickUse7,
    gEActionKey_QuickUse8,
    gEActionKey_QuickUse9,
    gEActionKey_QuickBar,
    gEActionKey_Inventory,
    gEActionKey_Map,
    gEActionKey_Log,
    gEActionKey_Equipment,
    gEActionKey_Escape,
    gEActionKey_QuickSave,
    gEActionKey_QuickLoad,
    gEActionKey_Count,
    gEActionKey_ForceDWORD = GE_FORCE_DWORD
};

struct gSAction
{
    gEActionKey m_enumAction;
    GEFloat     m_fFrameTime;
    int         m_iInputType;  // 3 action, 4 turning
    GEFloat     m_fAmplitude;  // action 1.0, turning +/-
};
GE_ASSERT_SIZEOF( gSAction, 0x0010 )

struct gSActionKeyInfo
{
    bCString    m_strName;
    GEBool      m_bLocked;
                GE_PADDING( 3 )
    eCLocString m_locDesc;
};
GE_ASSERT_SIZEOF( gSActionKeyInfo, 0x0014 );

struct gSDebugAction
{
    GEU32 m_u32DebugKeyIndex;
    // Enumeration from bitfield:
    //  GEU32 m_bPressed      : 1
    //  GEU32 m_bPressedBefore: 1
    //  GEU32 m_Reserved      : 30
    enum gEKeyAction
    {
        gEKeyAction_Down       = 0x000000000001,
        gEKeyAction_Repeat     = 0x000000000003,
        gEKeyAction_Up         = 0x000000000002,
        gEKeyAction_ForceDWORD = GE_FORCE_DWORD
    } m_enumKeyAction;
};

class GE_DLLIMPORT gCActionAdmin :
    public eCEngineComponentBase,
    public eIInputReceiver
{
protected:
    class CPostProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CPostProcessor( void );                
    protected:
        gCActionAdmin * m_pActionAdmin;
    };
    GE_ASSERT_SIZEOF( CPostProcessor, 0x0010 )
    class CPreProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CPreProcessor( void );                
    protected:
        gCActionAdmin * m_pActionAdmin;
    };
    GE_ASSERT_SIZEOF( CPreProcessor, 0x0010 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     IsValid( void ) const;
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual                           ~gCActionAdmin( void );
public: virtual bEResult                   Initialize( void );
public: virtual bEResult                   Shutdown( void );
public: virtual void                       ApplyConfiguration( void );
public: virtual void                       EngineMessageProc( eSEngineMessage & );
public: virtual void                       ProcessBegin( void );
public: virtual void                       ProcessEnd( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    static GEU32 const s_u32DebugKey_MAX;
protected:
    char __FIXME[ 0x01F4 - sizeof(eCEngineComponentBase) - sizeof(eIInputReceiver) ];
protected:
    void   CreateAxisEntry( eERawInputAxis, gEActionAxis );
    void   CreateDebugKeyEntry( eEScanCode, bCString const & );
    void   CreateDefaultActionMap( void );
    void   Invalidate( void );
    void   ProcessDebugKeys( void );
    GEBool ReadActionMap( void );
    GEBool ReadDebugKeyMap( void );
    void   SendActionEvent( gSAction const & );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gEActionKey                GE_STDCALL GetActionKey( bCString const & );
    static gEActionKey                GE_STDCALL GetActionKey( eEScanCode );
    static bCUnicodeString            GE_STDCALL GetActionKeyDescription( gEActionKey );
    static bCString                   GE_STDCALL GetActionKeyImage( gEActionKey, GEU8 );
    static gSActionKeyInfo const &    GE_STDCALL GetActionKeyInfo( gEActionKey );
    static bCUnicodeString            GE_STDCALL GetActionKeyTag( gEActionKey, GEU8 );
    static eEScanCode                 GE_STDCALL GetScanCode( gEActionKey, GEU8 );
    static bCUnicodeString            GE_STDCALL GetScanCodeDescription( eEScanCode );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                  ChangeKeyEntry( eEScanCode, eEScanCode, gEActionKey );
    void                  CreateKeyEntry( eEScanCode, gEActionKey, GEU8 );
    void                  GameReset( void );
    GEBool                GetActionKeyState( gEActionKey ) const;
    gCCharacterControl *  GetCharacterController( void );
    gCCharacterSensor *   GetCharacterSensor( void );
    gSAction const &      GetCurrentActionEvent( void ) const;
    gSDebugAction const & GetCurrentDebugEvent( void ) const;
    GEFloat               GetKeyPressDuration( gEActionKey ) const;
    GEFloat               GetKeyReleasedDuration( gEActionKey ) const;
    gEActionKey           GetLastKeyDown( GEFloat & ) const;
    gEActionKey           GetLastKeyUp( GEFloat & ) const;
    void                  ResetKeyStates( void );
    void                  ScanForTestMode( GEUnicodeChar );
    void                  SetActionKeyScript( eCScriptProxyScript const & );
    void                  SetPauseActionKeyScript( eCScriptProxyScript const & );
    void                  SetToDefault( void );
    GEBool                WasKeyPressedThisFrame( gEActionKey ) const;
public:
    gCActionAdmin & operator = ( gCActionAdmin const & );
public:
    gCActionAdmin( gCActionAdmin const & );
    gCActionAdmin( void );
};
GE_ASSERT_SIZEOF( gCActionAdmin, 0x01F4 )

#endif
