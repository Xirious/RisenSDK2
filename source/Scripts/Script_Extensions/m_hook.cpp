#include "m_hook.h"

GELPVoid mCCallHook::s_pSelf = 0;
GELPVoid mCCallHook::s_pOldTarget = 0;

mCCallHook::mCCallHook( SHookParams a_HookParams ) :
    m_pCode( 0 ),
    m_pRedirector( new SRedirector )
{
    SRedirector Redirector = { 0x90, 0x51, 0x68, 0, 0xE8, 0, 0xE9, 0, 0xDEADC0DE, 0 };
    *m_pRedirector = Redirector;
    GELPByte pCode = a_HookParams.m_pCode;
    if ( !pCode || ( *pCode != 0xE9 && a_HookParams.m_bFollowOneJump ) )
         return;
    if ( a_HookParams.m_bFollowOneJump )
        pCode += *reinterpret_cast< GEI32 * >( ++pCode ) + sizeof( GEI32 );
    pCode += a_HookParams.m_u32Offset;
    if ( *pCode != 0xE8 && ( *pCode != 0xE9 || a_HookParams.m_bFollowOneJump ) )
        return;
    m_pCode = ++pCode;
    if ( !SetCallTarget( m_pRedirector, m_pRedirector->m_pOldTarget ) )
    {
        m_pCode = 0;
        return;
    }
    m_pRedirector->m_i32OnRedirectOffset = ( reinterpret_cast< GELPByte >( &OnRedirect ) - ( reinterpret_cast< GELPByte >( m_pRedirector ) + 12 ) );
    m_pRedirector->m_i32NewTargetOffset = ( a_HookParams.m_pFunc - ( reinterpret_cast< GELPByte >( m_pRedirector ) + 17 ) );
    SRedirector * pPreviousRedirector = ( static_cast< SRedirector * >( m_pRedirector->m_pOldTarget ) );
    if ( pPreviousRedirector->m_byteNop == m_pRedirector->m_byteNop && pPreviousRedirector->m_u32Magic == m_pRedirector->m_u32Magic )
        pPreviousRedirector->m_pNext = m_pRedirector;
}

mCCallHook::~mCCallHook( void )
{
    SRedirector * pPreviousRedirector = ( static_cast< SRedirector * >( m_pRedirector->m_pOldTarget ) );
    if ( pPreviousRedirector->m_byteNop == m_pRedirector->m_byteNop && pPreviousRedirector->m_u32Magic == m_pRedirector->m_u32Magic )
        pPreviousRedirector->m_pNext = m_pRedirector->m_pNext;
    if ( m_pRedirector->m_pNext )
        m_pRedirector->m_pNext->m_pOldTarget = m_pRedirector->m_pOldTarget;
    else
        SetCallTarget( m_pRedirector->m_pOldTarget, m_pRedirector->m_pOldTarget );
    delete m_pRedirector;
}

GELPVoid mCCallHook::GetSelf( void )
{
    return s_pSelf;
}

GEBool mCCallHook::IsValid( void ) const
{
    return m_pCode != 0;
}

void mCCallHook::OnRedirect( GELPVoid a_pOldTarget, GELPVoid a_pSelf )
{
    s_pOldTarget = a_pOldTarget;
    s_pSelf = a_pSelf;
}

__declspec( naked )
void mCCallHook::OnCallOriginalFuntion( void )
{
    __asm mov ecx, s_pSelf
    __asm jmp s_pOldTarget
}

GEBool mCCallHook::SetCallTarget( GELPVoid a_pTarget, GELPVoid & a_pOldTarget )
{
    GEI32 * pOffset = reinterpret_cast< GEI32 * >( m_pCode );
    DWORD dwOldProtect = 0;
    if( !::VirtualProtect( static_cast< LPVOID >( pOffset ), sizeof( *pOffset ), PAGE_EXECUTE_WRITECOPY, &dwOldProtect ) )
        return GEFalse;
    a_pOldTarget = *pOffset + ( m_pCode + sizeof( GEI32 ) );
    *pOffset = static_cast< GELPByte >( a_pTarget ) - ( m_pCode + sizeof( GEI32 ) );
    ::VirtualProtect( static_cast< LPVOID >( pOffset ), sizeof( *pOffset ), dwOldProtect, &dwOldProtect );
    return GETrue;
}