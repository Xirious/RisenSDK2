#ifndef GM_FUNCTIONTRACER_H_INCLUDED
#define GM_FUNCTIONTRACER_H_INCLUDED

#include "..\Utils.h"

class mCFunctionTracer
{
protected:
    typedef GEInt ( mCFunctionTracer::*HandleFuncPtr )( GEU32 );
public:
    typedef void ( *InitFuncPtr )( mCFunctionTracer * );
    typedef void ( *CallbackFuncPtr )( GEInt );
protected:
    enum EMode
    {
        EMode_WaitingForFirstTrace,
        EMode_WaitingForRegistrations,
        EMode_CountingToInitFuncRet,
        EMode_ProcessingArgs,
        EMode_ProcessingVars,
        EMode_CountingCallsToBeSkipped,
        EMode_SkippingCalls,
        EMode_WaitingForRetAddr
    };
public:
    enum { E_FunctionTracerError = 407327 };
protected:
    struct FuncInfo
    {
        GEInt                    m_ID;
        GEU32                    m_Addr;
        GEInt                    m_ArgCount;
        GEInt                    m_VarCount;
        GEInt                    m_SkipCount;
        bTObjArray< FuncInfo * > m_arrCallers;
    };
protected:
    static HandleFuncPtr s_HandleFuncPtr;
protected:
    EMode                    m_enuMode;
    GEInt                    m_Counter;
    FuncInfo *               m_pNewInfo;
    FuncInfo *               m_pCurrentInfo;
    bTObjArray< FuncInfo * > m_arrInfos;
    CallbackFuncPtr          m_CallbackFuncPtr;
protected:
    GEInt  HandleStackValue( GEU32 a_u32Value );
    GEBool IsRetToInitFunc( GEU32 a_u32Addr );
    GEBool FindInfo( GEU32 a_u32Addr );
public:
    void AnnounceFunction( GEU32 a_ArgumentCount );
    void RegisterAs( GEInt a_ID );
    void Trace( void );
public:
    mCFunctionTracer( InitFuncPtr a_InitFuncPtr, CallbackFuncPtr a_CallbackFuncPtr );
   ~mCFunctionTracer( void );
};

#endif