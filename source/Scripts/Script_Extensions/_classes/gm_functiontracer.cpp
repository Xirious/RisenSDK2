#include "gm_functiontracer.h"

mCFunctionTracer::HandleFuncPtr mCFunctionTracer::s_HandleFuncPtr = &mCFunctionTracer::HandleStackValue;

#pragma auto_inline( off )

void mCFunctionTracer::Trace( void )
{
    __asm {
        xor  edx, edx
label_loop:
        mov  eax, [ esp + edx ]
        push edx
        push ecx
        push eax
        call s_HandleFuncPtr
        pop  ecx
        pop  edx
        add  edx, 4
        test eax, eax
        jnz  label_loop
        ret
    }
}

GEBool mCFunctionTracer::IsRetToInitFunc( GEU32 a_u32Addr )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static GEU32 s_OldAddr;

#pragma warning( pop )

    if ( m_enuMode == EMode_WaitingForFirstTrace )
        s_OldAddr = a_u32Addr;
    if ( ( a_u32Addr - s_OldAddr ) < ( GEU32 )( 60 ) )
    {
        s_OldAddr = a_u32Addr;
        return true;
    }
    return false;
}

GEBool mCFunctionTracer::FindInfo( GEU32 a_u32Addr )
{
    for ( GEInt i = 0, ie = m_pCurrentInfo->m_arrCallers.GetCount(); i != ie; ++i )
    {
        if ( a_u32Addr == m_pCurrentInfo->m_arrCallers[ i ]->m_Addr )
        {
            m_pCurrentInfo = m_pCurrentInfo->m_arrCallers[ i ];
            return true;
        }
    }
    return false;
}

void mCFunctionTracer::AnnounceFunction( GEU32 a_ArgumentCount )
{
    if ( m_enuMode != EMode_WaitingForRegistrations )
        throw ( GEInt )( E_FunctionTracerError );
    m_pNewInfo = new FuncInfo;
    m_pNewInfo->m_ArgCount = 44;
    m_arrInfos.AddNew() = m_pNewInfo;
    m_pNewInfo->m_ArgCount = ( GEInt )( a_ArgumentCount );
    m_enuMode = EMode_WaitingForRetAddr;
}

void mCFunctionTracer::RegisterAs( GEInt a_ID )
{
    if ( m_enuMode != EMode_CountingCallsToBeSkipped )
        throw ( GEInt )( E_FunctionTracerError );
    m_pNewInfo->m_SkipCount = m_Counter;
    m_pNewInfo->m_ID = a_ID;
    m_pNewInfo = 0;
    m_pCurrentInfo = m_arrInfos[ 0 ];
    m_enuMode = EMode_WaitingForRegistrations;
}

mCFunctionTracer::mCFunctionTracer( InitFuncPtr a_InitFuncPtr, CallbackFuncPtr a_CallbackFuncPtr ) :
    m_enuMode( EMode_WaitingForFirstTrace ),
    m_Counter( 0 ),
    m_pNewInfo( 0 ),
    m_CallbackFuncPtr( a_CallbackFuncPtr )
{
    m_pCurrentInfo = new FuncInfo;
    m_arrInfos.Add( m_pCurrentInfo );
    m_pCurrentInfo->m_ArgCount = 0;
    m_pCurrentInfo->m_Addr = 0;
    m_pCurrentInfo->m_ID = -1;
    m_pCurrentInfo->m_VarCount = 0;
    m_pCurrentInfo->m_SkipCount = 0;
    ( *a_InitFuncPtr )( this );
    m_enuMode = EMode_WaitingForRetAddr;
}

mCFunctionTracer::~mCFunctionTracer( void )
{
    for ( GEInt i = 0, ie = m_arrInfos.GetCount(); i != ie; ++i )
        delete m_arrInfos[ i ];
}

GEInt mCFunctionTracer::HandleStackValue( GEU32 a_u32Value )
{
    switch ( m_enuMode )
    {
    case EMode_WaitingForFirstTrace:
        {
            IsRetToInitFunc( a_u32Value );
            m_enuMode = EMode_WaitingForRegistrations;
            return 0;
        }
    case EMode_CountingToInitFuncRet:
        {
            ++m_Counter;
            if ( !IsRetToInitFunc( a_u32Value ) )
                return 1;
            m_pNewInfo->m_VarCount = ( m_Counter - 1 );
            m_Counter = 0;
            m_enuMode = EMode_CountingCallsToBeSkipped;
            return 0;
        }
    case EMode_ProcessingArgs:
        {
            --m_Counter;
            if ( m_Counter )
                return 1;
            if ( m_pCurrentInfo == m_pNewInfo )
            {
                m_enuMode = EMode_CountingToInitFuncRet;
            }
            else
            {
                m_Counter = m_pCurrentInfo->m_VarCount;
                if ( m_Counter )
                    m_enuMode = EMode_ProcessingVars;
                else
                    m_enuMode = EMode_WaitingForRetAddr;
            }
            return 1;
        }
    case EMode_ProcessingVars:
        {
            --m_Counter;
            if ( m_Counter )
                return 1;
            m_enuMode = EMode_WaitingForRetAddr;
            return 1;
        }
    case EMode_CountingCallsToBeSkipped:
        {
            ++m_Counter;
            return 0;
        }
    case EMode_SkippingCalls:
        {
            --m_Counter;
            if ( !m_Counter )
            {
                ( *m_CallbackFuncPtr )( m_pCurrentInfo->m_ID );
                m_pCurrentInfo = m_arrInfos[ 0 ];
                m_enuMode = EMode_WaitingForRetAddr;
            }
            return 0;
        }
    case EMode_WaitingForRetAddr:
        {
            GEInt ArgumentCount = m_pCurrentInfo->m_ArgCount;
            if ( FindInfo( a_u32Value ) )
            {
                if ( ArgumentCount )
                {
                    m_Counter = ArgumentCount;
                    m_enuMode = EMode_ProcessingArgs;
                }
                else if ( m_pCurrentInfo->m_VarCount )
                {
                    m_Counter = m_pCurrentInfo->m_VarCount;
                    m_enuMode = EMode_ProcessingVars;
                }
                return 1;
            }
            if ( !m_pNewInfo )
            {
                if ( m_pCurrentInfo->m_SkipCount )
                {
                    m_Counter = m_pCurrentInfo->m_SkipCount;
                    m_enuMode = EMode_SkippingCalls;
                    return 0;
                }
                ( *m_CallbackFuncPtr )( m_pCurrentInfo->m_ID );
                m_pCurrentInfo = m_arrInfos[ 0 ];
                return 0;
            }
            m_pCurrentInfo->m_arrCallers.Add( m_pNewInfo );
            m_pNewInfo->m_Addr = a_u32Value;
            m_pCurrentInfo = m_pNewInfo;
            if ( ArgumentCount )
            {
                m_Counter = ArgumentCount;
                m_enuMode = EMode_ProcessingArgs;
            }
            else
            {
                m_Counter = 0;
                m_enuMode = EMode_CountingToInitFuncRet;
            }
            return 1;
        }
    case EMode_WaitingForRegistrations:
        {
            throw ( GEInt )( E_FunctionTracerError );
        }
    default:
        {
            throw ( GEInt )( E_FunctionTracerError );
        }
    }
}

#pragma auto_inline( on )