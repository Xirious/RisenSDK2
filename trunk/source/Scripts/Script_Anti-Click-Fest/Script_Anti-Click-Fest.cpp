#include "Script.h"

class mCAntiClickFest
{
private:
    static GEBool              s_bPotentialMisTiming;
    static GEBool              s_bWasKeyPressedLastFrame;
    static bCString            s_strLastAnimation;
    static gCCombatMoveMelee * s_pLastCombatMove;
    static gCCombatMoveMelee   s_NoComboCombatMove;
    static gFScript            s_OriginalScriptFunction;
    static HANDLE              s_pTimerHandle;
public:
    static GEBool           IsWellTimed( void );
    static void             EndCombo( void );
    static void CALLBACK    CallBackFunc( GELPVoid a_pNull, BOOLEAN a_bNull );
    static GEInt GE_STDCALL OnPlayerGameKeyPressed( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs );
    static void Init( void );
};

GEBool              mCAntiClickFest::s_bPotentialMisTiming     = false;
GEBool              mCAntiClickFest::s_bWasKeyPressedLastFrame = false;
bCString            mCAntiClickFest::s_strLastAnimation        = "!";
gCCombatMoveMelee * mCAntiClickFest::s_pLastCombatMove         = 0;
gCCombatMoveMelee   mCAntiClickFest::s_NoComboCombatMove;
gFScript            mCAntiClickFest::s_OriginalScriptFunction  = 0;
HANDLE              mCAntiClickFest::s_pTimerHandle            = 0;

GEBool mCAntiClickFest::IsWellTimed( void )
{
    GEBool bResult = true;
    gCCombatSystem_PS * pPlayerEnginePS = dynamic_cast< gCCombatSystem_PS * >( Entity::GetPlayer().AccessEnginePropertySet< PSCombatSystem >() );
    gCCombatMoveMelee * pCurrentMove = dynamic_cast< gCCombatMoveMelee * >( pPlayerEnginePS->GetCurrentMove() );
    bCString strAnimation = Entity::GetPlayer().GetPropertySet< PSNpc >().GetCurrentMovementAni();
    if ( pCurrentMove )
    {
        bCString strCombo = pCurrentMove->GetCombo();
        bCString strComboSec = pCurrentMove->GetComboSec();
        if ( ( pCurrentMove == s_pLastCombatMove ) && ( strAnimation == s_strLastAnimation ) )
        {
            bResult = false;
        }
        s_pLastCombatMove = pCurrentMove;
    }
    else if ( !s_pTimerHandle )
    {
        ::CreateTimerQueueTimer( &s_pTimerHandle, 0, CallBackFunc, 0, 200, 0, 0 );
    }
    s_strLastAnimation = strAnimation;
    return bResult;
}

void mCAntiClickFest::EndCombo( void )
{
   gCCombatSystem_PS * pPlayerEnginePS = dynamic_cast< gCCombatSystem_PS * >( Entity::GetPlayer().AccessEnginePropertySet< PSCombatSystem >() );
   gCCombatMoveMelee * pCurrentMove = dynamic_cast< gCCombatMoveMelee * >( pPlayerEnginePS->GetCurrentMove() );
   if ( pCurrentMove )
   {
       s_NoComboCombatMove = *pCurrentMove;
       s_NoComboCombatMove.SetCombo( "" );
       s_NoComboCombatMove.SetComboLeft( "" );
       s_NoComboCombatMove.SetComboPower( "" );
       s_NoComboCombatMove.SetComboRight( "" );
       s_NoComboCombatMove.SetComboSec( "" );
       reinterpret_cast< GEU32 * >( pPlayerEnginePS )[ 18 ] = reinterpret_cast< GEU32 >( &s_NoComboCombatMove );
   }
}

void mCAntiClickFest::CallBackFunc( GELPVoid a_pNull, BOOLEAN a_bNull )
{
    UNREFERENCED_PARAMETER( a_pNull );
    UNREFERENCED_PARAMETER( a_bNull );
    if ( !IsWellTimed() )
        EndCombo();
    DeleteTimerQueueTimer( 0, s_pTimerHandle, 0 );
    CloseHandle( s_pTimerHandle );
    s_pTimerHandle = 0;
}

GEInt GE_STDCALL mCAntiClickFest::OnPlayerGameKeyPressed( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    if ( s_bWasKeyPressedLastFrame )
    {
        s_bWasKeyPressedLastFrame = false;
        s_bPotentialMisTiming = !IsWellTimed();
    }
    else if ( s_bPotentialMisTiming )
    {
        s_bPotentialMisTiming = false;
        EndCombo();
    }
    if ( input.WasKeyPressedThisFrame( gEActionKey_PrimaryAction ) )
    {
        s_bWasKeyPressedLastFrame = true;
    }
    return ( *s_OriginalScriptFunction )( a_pSPU, a_pSelfEntity, a_pOtherEntity, a_iArgs );
}

void mCAntiClickFest::Init( void )
{
    eSScriptBase * pScript = const_cast< eSScriptBase * >( eCScriptFunctionMap::GetInstance().GetScript( "OnPlayerGameKeyPressed" ) );
    if ( ( !pScript ) || ( !pScript->m_funcFunction ) )
    {
        gCScriptAdmin & ScriptAdmin = *dynamic_cast< gCScriptAdmin * >( eCModuleAdmin::GetInstance().FindModule( "gCScriptAdmin" ) );
        ScriptAdmin.LoadScriptDLL( "Script_Game.dll" );
        return Init();
    }
    s_OriginalScriptFunction = reinterpret_cast< gFScript >( pScript->m_funcFunction );
    pScript->m_funcFunction = OnPlayerGameKeyPressed;
}

extern "C" __declspec( dllexport ) gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    mCAntiClickFest::Init();

#pragma warning( push )
#pragma warning( disable : 4640 )

    static gSScriptInit s_ScriptInit;

#pragma warning( pop )

    s_ScriptInit.m_arrScriptAIStates.Clear();
    s_ScriptInit.m_arrScriptAIFunctions.Clear();
    s_ScriptInit.m_arrScriptAICallbacks.Clear();
    s_ScriptInit.m_arrScripts.Clear();

    return &s_ScriptInit;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
    UNREFERENCED_PARAMETER( lpReserved );
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}