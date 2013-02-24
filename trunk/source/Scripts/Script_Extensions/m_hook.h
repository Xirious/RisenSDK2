#include "SharedBase.h"

#pragma pack( push, 1 )

class mCCallHook
{
private:
    struct SHookParams;
    struct SRedirector;
public:
    mCCallHook( SHookParams a_HookParams );
   ~mCCallHook( void );
public:
    // The following three functions are designated for the use from within hooks.
    template< typename T > static T        GetOriginalFunction( T a_pfuncCaller );       // Supports __cdecl and __stdcall.
    template< typename T > static T        GetOriginalFunctionProxy( T a_pfuncCaller );  // Supports __cdecl, __stdcall and __thiscall (ECX is restored automatically).
                           static GELPVoid GetSelf( void );                              // Supports __thiscall.
public:
    GEBool IsValid( void ) const;
private:
    mCCallHook( void );
    mCCallHook( mCCallHook const & );
private:
    mCCallHook & operator = ( mCCallHook const & );
private:
    static void GE_STDCALL OnRedirect( GELPVoid a_pOldTarget, GELPVoid a_pSelf );
    static void GE_STDCALL OnCallOriginalFuntion( void );
private:
    GEBool SetCallTarget( GELPVoid a_pTarget, GELPVoid & a_pOldTarget );
private:
    static GELPVoid s_pSelf;
    static GELPVoid s_pOldTarget;
private:
    GELPByte      m_pCode;
    SRedirector * m_pRedirector;
private:
    template< typename T, typename U >
    friend SHookParams g_CallHookParams( T, U, GEBool, GEU32 );
};

template< typename T, typename U >
mCCallHook::SHookParams g_CallHookParams( T a_pCode, U a_pfuncNewFunction, GEBool a_bFollowOneJump = GEFalse, GEU32 a_u32Offset = 0 );

struct mCCallHook::SHookParams
{
    GELPByte m_pFunc;
    GELPByte m_pCode;
    GEBool   m_bFollowOneJump;
    GEU32    m_u32Offset;
};

struct mCCallHook::SRedirector
{
    GEByte        m_byteNop;
    GEByte        m_bytePushEcx;
    GEByte        m_bytePushImm32;
    GELPVoid      m_pOldTarget;
    GEByte        m_byteCall;
    GEI32         m_i32OnRedirectOffset;
    GEByte        m_byteJumpRel32;
    GEI32         m_i32NewTargetOffset;
    GEU32         m_u32Magic;
    SRedirector * m_pNext;
};

template< typename T >
T mCCallHook::GetOriginalFunction( T )
{
    GE_ASSERT_SIZEOF( T, sizeof( GELPVoid ) )
    return *reinterpret_cast< T * >( &s_pOldTarget );
}

template< typename T >
T mCCallHook::GetOriginalFunctionProxy( T )
{
    GE_ASSERT_SIZEOF( T, sizeof( GELPVoid ) )
    GELPVoid pProxy = &OnCallOriginalFuntion;
    return *reinterpret_cast< T * >( &pProxy );
}

template< typename T, typename U >
mCCallHook::SHookParams g_CallHookParams( T a_pCode, U a_pfuncNewFunction, GEBool a_bFollowOneJump, GEU32 a_u32Offset )
{
    GE_ASSERT_SIZEOF( T, sizeof( GELPVoid ) )
    GE_ASSERT_SIZEOF( U, sizeof( GELPVoid ) )
    mCCallHook::SHookParams Result;
    Result.m_pFunc = *reinterpret_cast< GELPByte * >( &a_pfuncNewFunction );
    Result.m_pCode = *reinterpret_cast< GELPByte * >( &a_pCode );
    Result.m_bFollowOneJump = a_bFollowOneJump;
    Result.m_u32Offset = a_u32Offset;
    return Result;
}

#pragma pack( pop )