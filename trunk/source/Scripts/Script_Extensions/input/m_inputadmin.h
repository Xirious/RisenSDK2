#ifndef M_INPUTADMIN_H_INCLUDED
#define M_INPUTADMIN_H_INCLUDED

#include "Game.h"

class mCInputAdmin :
    public eIInputReceiver
{
public:
    typedef void ( GE_STDCALL * MFKeyEvent )( eEScanCode a_enuScanCode, GEBool a_bKeyState );
public:
    class CKeyHandle;
    class CAnalogHandle;
public:
    static GEBool GetCapsLockToggled( void );
    static GEBool GetRawKeyState( eEScanCode a_enuScanCode );
private:
public:  virtual void KeyPressed( GEU32 a_u32ID );
public:  virtual void KeyReleased( GEU32 a_u32ID );
public:  virtual void AnalogInput( GEU32 a_u32ID, GEInt a_iVal );
public:  virtual void DebugKeyPressed( GEU32 a_u32ID );
public:  virtual void DebugKeyReleased( GEU32 a_u32ID );
private: virtual     ~mCInputAdmin( void );
private:
    struct SKeyEntry;
    struct SKeyHandle;
private:
    static mCInputAdmin * GE_STDCALL GetInstance( void );
    static void           GE_STDCALL OnAddKeyAction( GEU32 a_u32ScanCode, GEU32 a_u32ID, GEU8 a_u8UseIndex );
    static void           GE_STDCALL OnChangeKeyAction( GEU32 a_u32OldScanCode, GEU32 a_u32NewScanCode, GEU32 a_u32ID );
    static void           GE_STDCALL OnClearActions( void );
private:
    SKeyEntry * AccessKeyEntry( eEScanCode a_enuScanCode );
    SKeyEntry * AddKeyEntry( eEScanCode a_enuScanCode );
    GEBool      KeyEvent( GEI32 a_i32ID, GEBool a_bState );
    void        RemoveKeyEntry( eEScanCode a_enuScanCode );
    void        UpdateKeyEntry( eEScanCode a_enuScanCode );
private:
    mCInputAdmin( void );
    mCInputAdmin( mCInputAdmin const & );
private:
    static mCInputAdmin *  s_pInstance;
    static eCInputAdmin *  s_pEngineInputAdmin;
    static gCActionAdmin * s_pGameActionAdmin;
private:
    GEU32                   m_arrGameActionScanCodes[ gEActionKey_Count ][ 4 ];
    GEU8                    m_arrKeyEntryIndices[ eEScanCode_Count ];
                            GE_PADDING( 1 )
    bTValArray< SKeyEntry > m_arrKeyEntries;
    GEI32                   m_i32X;
    GEI32                   m_i32Y;
    GEUInt                  m_uAnalogBlockCount;
};

class mCInputAdmin::CKeyHandle
{
public:
    CKeyHandle( eEScanCode a_enuScanCode );
    CKeyHandle( CKeyHandle const & a_Source );
   ~CKeyHandle( void );
public:
    CKeyHandle & operator = ( CKeyHandle const & a_Source );
    CKeyHandle & operator = ( eEScanCode a_enuScanCode );
public:
    void       EmulateActionKeyKlick( void ) const;
    void       EmulateActionKeyPress( void ) const;
    void       EmulateActionKeyRelease( void ) const;
    GEFloat    GetPressedDurationInSeconds( void ) const;
    GEUInt     GetTimesPressed( void ) const;
    eEScanCode GetScanCode( void ) const;
    GEBool     GetState( void ) const;
    void       HideInputFromGame( void );
    void       ResetTimesPressed( void );
    void       SetKeyEventCallback( MFKeyEvent a_pfuncCallback );
    void       StopHideInputFromGame( void );
    void       Swap( CKeyHandle & a_Other );
private:
    static SKeyHandle * CreatePrivateHandle( eEScanCode a_enuScanCode );
private:
    CKeyHandle( void );
private:
    SKeyEntry & AccessKeyEntry( void ) const;
private:
    SKeyHandle * m_pHandle;
};

class mCInputAdmin::CAnalogHandle
{
public:
    CAnalogHandle( void );
   ~CAnalogHandle( void );
public:
    void      Emulate2DInput( bCVector2 a_vecDelta ) const;
    void      Emulate2DInput( bCVector a_vecDelta ) const;
    void      Emulate2DInput( GEFloat a_fDeltaX, GEFloat a_fDeltaY ) const;
    void      Emulate2DInput( GEI32 a_i32RawDeltaX, GEI32 a_i32RawDeltaY ) const;
    GEI32     GetRawX( void ) const;
    GEI32     GetRawY( void ) const;
    GEFloat   GetSensitivity( void ) const;
    void      HideInputFromGame( void );
    GEFloat   GetX( void ) const;
    GEFloat   GetY( void ) const;
    bCVector2 Get2D( void ) const;
    bCVector  Get3D( void ) const;
    void      ResetXY( void );
    void      SetSensitivity( GEFloat a_fSensitivity );
    void      StopHideInputFromGame( void );
private:
    GEI32   m_i32X;
    GEI32   m_i32Y;
    GEFloat m_fSensitivity;
    GEFloat m_fDeltaX;
    GEFloat m_fDeltaY;
    GEBool  m_bBlocked;
            GE_PADDING( 3 )
};

struct mCInputAdmin::SKeyEntry
{
    GEU32        m_u32ScanCode;
    GEU32        m_u32PressedTimeStamp;
    GEUInt       m_uTimesPressed;
    GEUInt       m_uBlockCount;
    SKeyHandle * m_pFirstHandle;
    GEBool       m_bState;
                 GE_PADDING( 3 )
};

struct mCInputAdmin::SKeyHandle
{
    GEInt        m_iKeyEntryIndex;
    GEUInt       m_uTimesPressed;
    MFKeyEvent   m_pfuncCallback;
    SKeyHandle * m_pNext;
    GEBool       m_bBlocked;
                 GE_PADDING( 3 )
};

#endif