#include "m_inputadmin.h"
#include "../m_hook.h"

#pragma warning( push )
#pragma warning( disable : 4738 )  // storing 32-bit float result in memory, possible loss of performance

mCInputAdmin *  mCInputAdmin::s_pInstance = 0;
eCInputAdmin *  mCInputAdmin::s_pEngineInputAdmin = 0;
gCActionAdmin * mCInputAdmin::s_pGameActionAdmin = 0;

GEBool mCInputAdmin::GetCapsLockToggled( void )
{
    return ( ( ::GetKeyState( VK_CAPITAL ) & 1 ) != 0 );
}

GEBool mCInputAdmin::GetRawKeyState( eEScanCode a_enuScanCode )
{
    GetInstance();
    return s_pEngineInputAdmin->GetRawKeyState( a_enuScanCode );
}

void mCInputAdmin::KeyPressed( GEU32 a_u32ID )
{
    if ( KeyEvent( static_cast< GEI32 >( a_u32ID ), GETrue ) && a_u32ID < gEActionKey_Count && !s_pGameActionAdmin->GetActionKeyState( static_cast< gEActionKey >( a_u32ID ) ) )
        s_pGameActionAdmin->KeyPressed( a_u32ID );
}

void mCInputAdmin::KeyReleased( GEU32 a_u32ID )
{
    if ( KeyEvent( static_cast< GEI32 >( a_u32ID ), GEFalse ) && a_u32ID < gEActionKey_Count && s_pGameActionAdmin->GetActionKeyState( static_cast< gEActionKey >( a_u32ID ) ) )
        s_pGameActionAdmin->KeyReleased( a_u32ID );
}

void mCInputAdmin::AnalogInput( GEU32 a_u32ID, GEInt a_iVal )
{
    if ( a_u32ID == 1 )
        m_i32X += a_iVal;
    else if ( a_u32ID == 2 )
        m_i32Y += a_iVal;
    if ( !m_uAnalogBlockCount )
        s_pGameActionAdmin->AnalogInput( a_u32ID, a_iVal );
}

void mCInputAdmin::DebugKeyPressed( GEU32 a_u32ID )
{
    s_pGameActionAdmin->DebugKeyPressed( a_u32ID );
}

void mCInputAdmin::DebugKeyReleased( GEU32 a_u32ID )
{
    s_pGameActionAdmin->DebugKeyReleased( a_u32ID );
}

mCInputAdmin::~mCInputAdmin( void )
{
}

mCInputAdmin * mCInputAdmin::GetInstance( void )
{
    if ( !s_pInstance )
        s_pInstance = new mCInputAdmin;
    return s_pInstance;
}

namespace
{
    mCCallHook * s_pAddKeyActionHook = 0;
    mCCallHook * s_pChangeKeyActionHook = 0;
    mCCallHook * s_pClearActionsHook = 0;
}

void mCInputAdmin::OnAddKeyAction( GEU32 a_u32ScanCode, GEU32 a_u32ID, GEU8 a_u8UseIndex )
{
    ( *mCCallHook::GetOriginalFunctionProxy( &OnAddKeyAction ) )( a_u32ScanCode, a_u32ID, a_u8UseIndex );
    if ( a_u8UseIndex >= 4 || a_u32ID >= gEActionKey_Count )
        return;
    GetInstance()->m_arrGameActionScanCodes[ a_u32ID ][ a_u8UseIndex ] = a_u32ScanCode;
    GetInstance()->UpdateKeyEntry( static_cast< eEScanCode >( a_u32ScanCode ) );
}

void mCInputAdmin::OnChangeKeyAction( GEU32 a_u32OldScanCode, GEU32 a_u32NewScanCode, GEU32 a_u32ID )
{
    ( *mCCallHook::GetOriginalFunctionProxy( &OnChangeKeyAction ) )( a_u32OldScanCode, a_u32NewScanCode, a_u32ID );
    GEU8 u8UseIndex = s_pEngineInputAdmin->GetUseIndex( static_cast< eEScanCode >( a_u32NewScanCode ) );
    if ( u8UseIndex >= 4 || a_u32ID >= gEActionKey_Count )
        return;
    GetInstance()->m_arrGameActionScanCodes[ a_u32ID ][ u8UseIndex ] = a_u32NewScanCode;
    GetInstance()->UpdateKeyEntry( static_cast< eEScanCode >( a_u32OldScanCode ) );
}

void mCInputAdmin::OnClearActions( void )
{
    ( *mCCallHook::GetOriginalFunctionProxy( &OnClearActions ) )();
    mCInputAdmin * pInstance = GetInstance();
    g_ZeroMemory( pInstance->m_arrGameActionScanCodes, sizeof( pInstance->m_arrGameActionScanCodes ) );
    for ( GEU32 u = eEScanCode_Count; u--; pInstance->UpdateKeyEntry( static_cast< eEScanCode >( u ) ) );
}

mCInputAdmin::SKeyEntry * mCInputAdmin::AccessKeyEntry( eEScanCode a_enuScanCode )
{
    if ( m_arrKeyEntryIndices[ a_enuScanCode ] )
        return &m_arrKeyEntries[ m_arrKeyEntryIndices[ a_enuScanCode ] - 1 ];
    return 0;
}

mCInputAdmin::SKeyEntry * mCInputAdmin::AddKeyEntry( eEScanCode a_enuScanCode )
{
    if ( AccessKeyEntry( a_enuScanCode ) )
        return AccessKeyEntry( a_enuScanCode );
    GEInt iIndex = 0;
    for ( GEInt iCount = m_arrKeyEntries.GetCount(); iIndex != iCount; ++iIndex )
        if ( !m_arrKeyEntries[ iIndex ].m_u32ScanCode )
            break;
    if ( iIndex == m_arrKeyEntries.GetCount() )
        m_arrKeyEntries.AddNew();
    if ( !s_pEngineInputAdmin->GetActionKey( a_enuScanCode ) )
        s_pEngineInputAdmin->AddKeyAction( a_enuScanCode, static_cast< GEU32 >( iIndex + gEActionKey_Count ), 0 );
    m_arrKeyEntryIndices[ a_enuScanCode ] = static_cast< GEU8 >( iIndex + 1 );
    m_arrKeyEntries[ iIndex ].m_u32ScanCode = a_enuScanCode;
    m_arrKeyEntries[ iIndex ].m_bState = GetRawKeyState( a_enuScanCode );
    return &m_arrKeyEntries[ iIndex ];
}

GEBool mCInputAdmin::KeyEvent( GEI32 a_i32ID, GEBool a_bState )
{
    if ( a_i32ID < gEActionKey_Count )
        for ( GEU32 u = 0, u32ScanCode; u != 4 && ( u32ScanCode = m_arrGameActionScanCodes[ a_i32ID ][ u ] ) != 0; ++u )
            if ( m_arrKeyEntryIndices[ u32ScanCode ] )
                if ( GetRawKeyState( static_cast< eEScanCode >( u32ScanCode ) ) != AccessKeyEntry( static_cast< eEScanCode >( u32ScanCode ) )->m_bState )
                    a_i32ID = m_arrKeyEntryIndices[ u32ScanCode ] - 1 + gEActionKey_Count;
    if ( a_i32ID < gEActionKey_Count || ( a_i32ID -= gEActionKey_Count, a_i32ID >= m_arrKeyEntries.GetCount() ) )
        return GETrue;
    SKeyEntry & Entry = m_arrKeyEntries[ a_i32ID ];
    Entry.m_bState = a_bState;
    if ( a_bState )
    {
        ++Entry.m_uTimesPressed;
        Entry.m_u32PressedTimeStamp = bCTimer::GetTimeStamp();
    }
    else
        Entry.m_u32PressedTimeStamp = bCTimer::GetTimeStamp() - Entry.m_u32PressedTimeStamp;
    for ( SKeyHandle * pHandle = Entry.m_pFirstHandle; pHandle; pHandle = pHandle->m_pNext )
        if ( pHandle->m_pfuncCallback )
            ( *( pHandle->m_pfuncCallback ) )( static_cast< eEScanCode >( Entry.m_u32ScanCode ), a_bState );
    return Entry.m_uBlockCount == 0;
}

void mCInputAdmin::RemoveKeyEntry( eEScanCode a_enuScanCode )
{
    SKeyEntry * pEntry = AccessKeyEntry( a_enuScanCode );
    if ( !pEntry )
        return;
    if ( s_pEngineInputAdmin->GetActionKey( a_enuScanCode ) >= gEActionKey_Count )
        s_pEngineInputAdmin->AddKeyAction( a_enuScanCode, 0, 0 );
    g_ZeroMemory( pEntry, sizeof( *pEntry ) );
    m_arrKeyEntryIndices[ a_enuScanCode ] = 0;
}

void mCInputAdmin::UpdateKeyEntry( eEScanCode a_enuScanCode )
{
    if ( !AccessKeyEntry( a_enuScanCode ) )
        return;
    GEInt iEntryIndex = m_arrKeyEntryIndices[ a_enuScanCode ] - 1;
    SKeyEntry Temp = *AccessKeyEntry( a_enuScanCode );
    RemoveKeyEntry( a_enuScanCode );
    AddKeyEntry( a_enuScanCode );
    *AccessKeyEntry( a_enuScanCode ) = Temp;
    if ( m_arrKeyEntryIndices[ a_enuScanCode ] - 1 != iEntryIndex )
        for ( SKeyHandle * pHandle = AccessKeyEntry( a_enuScanCode )->m_pFirstHandle; pHandle; pHandle = pHandle->m_pNext )
            pHandle->m_iKeyEntryIndex = m_arrKeyEntryIndices[ a_enuScanCode ] - 1;
}

mCInputAdmin::mCInputAdmin( void )
{
    g_ZeroMemory( m_arrGameActionScanCodes, sizeof( m_arrGameActionScanCodes ) );
    g_ZeroMemory( m_arrKeyEntryIndices, sizeof( m_arrKeyEntryIndices ) );
    s_pEngineInputAdmin = dynamic_cast< eCInputAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCInputAdmin" ) );
    s_pGameActionAdmin = dynamic_cast< gCActionAdmin * >( eCModuleAdmin::GetInstance().FindModule( "gCActionAdmin" ) );
    s_pAddKeyActionHook    = s_pAddKeyActionHook ?    s_pAddKeyActionHook :    new mCCallHook( g_CallHookParams( &eCInputAdmin::AddKeyAction,    &mCInputAdmin::OnAddKeyAction,    GEFalse, 0 ) );
    s_pChangeKeyActionHook = s_pChangeKeyActionHook ? s_pChangeKeyActionHook : new mCCallHook( g_CallHookParams( &eCInputAdmin::ChangeKeyAction, &mCInputAdmin::OnChangeKeyAction, GEFalse, 0 ) );
    s_pClearActionsHook    = s_pClearActionsHook ?    s_pClearActionsHook :    new mCCallHook( g_CallHookParams( &eCInputAdmin::ClearActions,    &mCInputAdmin::OnClearActions,    GEFalse, 0 ) );
    if ( !s_pGameActionAdmin || !s_pAddKeyActionHook->IsValid() || !s_pChangeKeyActionHook->IsValid() || !s_pClearActionsHook->IsValid() )
        s_pEngineInputAdmin = 0;
    if ( !s_pEngineInputAdmin )
        return;
    for ( GEU32 u = eEScanCode_Count; u--; )
    {
        GEU32 u32ActionKey = s_pEngineInputAdmin->GetActionKey( static_cast< eEScanCode >( u ) );
        GEU8 u8UseIndex = s_pEngineInputAdmin->GetUseIndex( static_cast< eEScanCode >( u ) );
        if ( u32ActionKey < gEActionKey_Count && u8UseIndex < 4 )
            m_arrGameActionScanCodes[ u32ActionKey ][ u8UseIndex ] = u;
    }
    s_pEngineInputAdmin->SetInputReceiver( this );
}

mCInputAdmin::CKeyHandle::CKeyHandle( eEScanCode a_enuScanCode ) :
    m_pHandle( CreatePrivateHandle( a_enuScanCode ) )
{
}

mCInputAdmin::CKeyHandle::CKeyHandle( CKeyHandle const & a_Source ) :
    m_pHandle( CreatePrivateHandle( static_cast< eEScanCode >( a_Source.AccessKeyEntry().m_u32ScanCode ) ) )
{
    m_pHandle->m_pfuncCallback = a_Source.m_pHandle->m_pfuncCallback;
    m_pHandle->m_uTimesPressed = a_Source.m_pHandle->m_uTimesPressed;
}

mCInputAdmin::CKeyHandle::~CKeyHandle( void )
{
    SKeyEntry & KeyEntry = AccessKeyEntry();
    SKeyHandle ** pHandlePtr = &KeyEntry.m_pFirstHandle;
    for ( ; *pHandlePtr != m_pHandle; pHandlePtr = &( *pHandlePtr )->m_pNext );
    *pHandlePtr = m_pHandle->m_pNext;
    if ( !KeyEntry.m_pFirstHandle )
        mCInputAdmin::GetInstance()->RemoveKeyEntry( static_cast< eEScanCode >( KeyEntry.m_u32ScanCode ) );
    delete m_pHandle;
}

mCInputAdmin::CKeyHandle & mCInputAdmin::CKeyHandle::operator = ( CKeyHandle const & a_Source )
{
    CKeyHandle handleTemp( a_Source );
    Swap( handleTemp );
    return *this;
}

mCInputAdmin::CKeyHandle & mCInputAdmin::CKeyHandle::operator = ( eEScanCode a_enuScanCode )
{
    CKeyHandle handleTemp( a_enuScanCode );
    Swap( handleTemp );
    return *this;
}

void mCInputAdmin::CKeyHandle::EmulateActionKeyKlick( void ) const
{
    EmulateActionKeyPress();
    EmulateActionKeyRelease();
}

void mCInputAdmin::CKeyHandle::EmulateActionKeyPress( void ) const
{
    GEU32 u32ID = s_pEngineInputAdmin->GetActionKey( GetScanCode() );
    if ( !u32ID )
        return;
    if ( GetState() )
        mCInputAdmin::GetInstance()->KeyReleased( u32ID );
    mCInputAdmin::GetInstance()->KeyPressed( u32ID );
}

void mCInputAdmin::CKeyHandle::EmulateActionKeyRelease( void ) const
{
    if ( !GetState() )
        return;
    GEU32 u32ID = s_pEngineInputAdmin->GetActionKey( GetScanCode() );
    if ( u32ID )
        mCInputAdmin::GetInstance()->KeyReleased( u32ID );
}

GEFloat mCInputAdmin::CKeyHandle::GetPressedDurationInSeconds( void ) const
{
    if ( !GetState() )
        return ( AccessKeyEntry().m_u32PressedTimeStamp ) / 1000.0f;
    return ( bCTimer::GetTimeStamp() - AccessKeyEntry().m_u32PressedTimeStamp ) / 1000.0f;
}

GEUInt mCInputAdmin::CKeyHandle::GetTimesPressed( void ) const
{
    return AccessKeyEntry().m_uTimesPressed - m_pHandle->m_uTimesPressed;
}

eEScanCode mCInputAdmin::CKeyHandle::GetScanCode( void ) const
{
    return static_cast< eEScanCode >( AccessKeyEntry().m_u32ScanCode );
}

GEBool mCInputAdmin::CKeyHandle::GetState( void ) const
{
    return AccessKeyEntry().m_bState;
}

void mCInputAdmin::CKeyHandle::HideInputFromGame( void )
{
    if ( m_pHandle->m_bBlocked )
        return;
    if ( GetState() )
        if ( s_pEngineInputAdmin->GetActionKey( GetScanCode() ) < gEActionKey_Count )
            s_pGameActionAdmin->KeyReleased( s_pEngineInputAdmin->GetActionKey( GetScanCode() ) );
    ++AccessKeyEntry().m_uBlockCount;
    m_pHandle->m_bBlocked = GETrue;
}

void mCInputAdmin::CKeyHandle::ResetTimesPressed( void )
{
    m_pHandle->m_uTimesPressed = AccessKeyEntry().m_uTimesPressed;
}

void mCInputAdmin::CKeyHandle::SetKeyEventCallback( MFKeyEvent a_pfuncCallback )
{
    m_pHandle->m_pfuncCallback = a_pfuncCallback;
}

void mCInputAdmin::CKeyHandle::StopHideInputFromGame( void )
{
    if ( !m_pHandle->m_bBlocked )
        return;
    --AccessKeyEntry().m_uBlockCount;
    m_pHandle->m_bBlocked = GEFalse;
}

void mCInputAdmin::CKeyHandle::Swap( CKeyHandle & a_Other )
{
    SKeyHandle * pHandle = m_pHandle;
    m_pHandle = a_Other.m_pHandle;
    a_Other.m_pHandle = pHandle;
}

mCInputAdmin::SKeyHandle * mCInputAdmin::CKeyHandle::CreatePrivateHandle( eEScanCode a_enuScanCode )
{
    SKeyEntry * pEntry = mCInputAdmin::GetInstance()->AddKeyEntry( a_enuScanCode );
    SKeyHandle * pResult = new SKeyHandle;
    pResult->m_bBlocked = GEFalse;
    pResult->m_pfuncCallback = 0;
    pResult->m_iKeyEntryIndex = pEntry - mCInputAdmin::GetInstance()->m_arrKeyEntries.AccessArray();
    pResult->m_uTimesPressed = pEntry->m_uTimesPressed;
    pResult->m_pNext = pEntry->m_pFirstHandle;
    pEntry->m_pFirstHandle = pResult;
    return pResult;
}

mCInputAdmin::SKeyEntry & mCInputAdmin::CKeyHandle::AccessKeyEntry( void ) const
{
    return mCInputAdmin::GetInstance()->m_arrKeyEntries[ m_pHandle->m_iKeyEntryIndex ];
}

mCInputAdmin::CAnalogHandle::CAnalogHandle( void ) :
    m_i32X( mCInputAdmin::GetInstance()->m_i32X ),
    m_i32Y( mCInputAdmin::GetInstance()->m_i32Y ),
    m_fSensitivity( 1.0f ),
    m_fDeltaX( 0.0f ),
    m_fDeltaY( 0.0f ),
    m_bBlocked( GEFalse )
{
}

mCInputAdmin::CAnalogHandle::~CAnalogHandle( void )
{
}

void mCInputAdmin::CAnalogHandle::Emulate2DInput( bCVector2 a_vecDelta ) const
{
    Emulate2DInput( a_vecDelta.GetX(), a_vecDelta.GetY() );
}

void mCInputAdmin::CAnalogHandle::Emulate2DInput( bCVector a_vecDelta ) const
{
    Emulate2DInput( a_vecDelta.GetX(), a_vecDelta.GetY() );
}

inline
void mCInputAdmin::CAnalogHandle::Emulate2DInput( GEFloat a_fDeltaX, GEFloat a_fDeltaY ) const
{
    Emulate2DInput( static_cast< GEI32 >( 0.5f + a_fDeltaX / m_fSensitivity ), static_cast< GEI32 >( 0.5f + a_fDeltaY / m_fSensitivity ) );
}

inline
void mCInputAdmin::CAnalogHandle::Emulate2DInput( GEI32 a_i32RawDeltaX, GEI32 a_i32RawDeltaY ) const
{
    mCInputAdmin * pInputAdmin = mCInputAdmin::GetInstance();
    pInputAdmin->AnalogInput( 1, a_i32RawDeltaX );
    pInputAdmin->AnalogInput( 2, a_i32RawDeltaY );
}

inline
GEI32 mCInputAdmin::CAnalogHandle::GetRawX( void ) const
{
    return mCInputAdmin::GetInstance()->m_i32X - m_i32X;
}

inline
GEI32 mCInputAdmin::CAnalogHandle::GetRawY( void ) const
{
    return mCInputAdmin::GetInstance()->m_i32Y - m_i32Y;
}

GEFloat mCInputAdmin::CAnalogHandle::GetSensitivity( void ) const
{
    return m_fSensitivity;
}

void mCInputAdmin::CAnalogHandle::HideInputFromGame( void )
{
    if ( m_bBlocked )
        return;
    m_bBlocked = GETrue;
    ++mCInputAdmin::GetInstance()->m_uAnalogBlockCount;
}

inline
GEFloat mCInputAdmin::CAnalogHandle::GetX( void ) const
{
    return m_fDeltaX + m_fSensitivity * GetRawX();
}

inline
GEFloat mCInputAdmin::CAnalogHandle::GetY( void ) const
{
    return m_fDeltaY + m_fSensitivity * GetRawY();
}

bCVector2 mCInputAdmin::CAnalogHandle::Get2D( void ) const
{
    return bCVector2( GetX(), GetY() );
}

bCVector mCInputAdmin::CAnalogHandle::Get3D( void ) const
{
    return bCVector( GetX(), GetY(), 0.0f );
}

void mCInputAdmin::CAnalogHandle::ResetXY( void )
{
    mCInputAdmin * pInputAdmin = mCInputAdmin::GetInstance();
    m_fDeltaX = m_fDeltaY = 0.0f;
    m_i32X = pInputAdmin->m_i32X;
    m_i32Y = pInputAdmin->m_i32Y;
}

void mCInputAdmin::CAnalogHandle::SetSensitivity( GEFloat a_fSensitivity )
{
    bCVector2 vec2DBefore = Get2D();
    m_fSensitivity = a_fSensitivity;
    bCVector2 vec2DAfter = Get2D();
    m_fDeltaX = vec2DBefore.GetX() - vec2DAfter.GetX();
    m_fDeltaY = vec2DBefore.GetY() - vec2DAfter.GetY();
}

void mCInputAdmin::CAnalogHandle::StopHideInputFromGame( void )
{
    if ( !m_bBlocked )
        return;
    m_bBlocked = GEFalse;
    --mCInputAdmin::GetInstance()->m_uAnalogBlockCount;
}

#pragma warning( pop )