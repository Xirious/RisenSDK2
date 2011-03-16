#include "Script.h"

typedef GEBool ( GE_STDCALL * FScriptAIState)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );

struct SScriptAIState
{
	bCString       m_strName;
	bCString       m_strSource;
	FScriptAIState m_funcScriptAIState;
};

typedef GEBool (GE_STDCALL * FScriptAIFunction)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );

struct SScriptAIFunction
{
	bCString          m_strName;
	bCString          m_strSource;
	FScriptAIFunction m_funcScriptAIFunction;
};

typedef GEBool (GE_STDCALL * FScriptAICallback)( gCScriptProcessingUnit * );

struct SScriptAICallback
{
	bCString          m_strName;
	bCString          m_strSource;
	FScriptAICallback m_funcScriptAICallback;
};

typedef GEInt (GE_STDCALL * FScript)( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );

struct SScript
{
	bCString m_strName;
	bCString m_strSource;
	FScript  m_funcScript;
    __forceinline SScript( GELPCChar a_pcName, GELPCChar a_pcSource, FScript a_funcScript ) :
        m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScript( a_funcScript )
    {
    }
    __forceinline SScript( void )
    {
    }
};

struct SScriptFunctions {
	bTObjArray< SScriptAIState >    m_arrScriptAIStates;
    bTObjArray< SScriptAIFunction > m_arrScriptAIFunctions;
    bTObjArray< SScriptAICallback > m_arrScriptAICallbacks;
    bTObjArray< SScript >           m_arrScripts;
    __forceinline SScriptFunctions( void )
    {
    }
    __forceinline ~SScriptFunctions( void )
    {
    }
};

