#include "Script.h"

static gFScript pfOriginalDoDamage = 0;

GEInt GE_STDCALL PrepareDoDamage( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    for ( ; ; )
    {
        eCEntity * pWeapon = a_pSPU->GetSelfEntity();
        if ( !pWeapon )
            break;
        gCItem_PS * pItemPropertySet = dynamic_cast< gCItem_PS * >( pWeapon->GetPropertySet( "gCItem_PS" ) );
        if ( !pItemPropertySet )
            break;
        gCDamage_PS * pDamagePropertySet = dynamic_cast< gCDamage_PS * >( pWeapon->GetPropertySet( "gCDamage_PS" ) );
        if ( !pDamagePropertySet )
            break;
        bCString strDamageScriptName = pDamagePropertySet->GetDamageScript().GetScriptName();
        if ( ( strDamageScriptName != "DoSwordDamage" ) && ( strDamageScriptName != "DoAxeDamage" ) && ( strDamageScriptName != "DoStaffDamage" ) )
            break;
        GEInt RequiresDexButNoStrenght = 0;
        bTObjArray< gCSkillValue > const & arrRequiredSkills = pItemPropertySet->GetRequiredSkills();
        for ( GEInt i = 0, ie = arrRequiredSkills.GetCount(); i != ie; ++i )
        {
            if ( arrRequiredSkills[ i ].GetSkill().GetValue() == gESkill_Stat_DEX )
                ++RequiresDexButNoStrenght;
            if ( arrRequiredSkills[ i ].GetSkill().GetValue() == gESkill_Stat_STR )
                RequiresDexButNoStrenght -= 20;
        }
        if ( RequiresDexButNoStrenght <= 0 )
            break;
        eCEntityProxy const & AggressorProxy = pDamagePropertySet->GetAgressor();
        if ( !AggressorProxy.IsEntityIDValid() )
            break;
        if ( !AggressorProxy.GetEntity()->GetPropertySet( "gCSkills_PS" ) )
            break;
        PSSkills const & AggressorSkills = Entity( AggressorProxy ).GetPropertySet< PSSkills >();
        GEDouble dMultiplier = Entity( pWeapon ).GetPropertySetProperty< PSDamage::PropertyDamageMultiplier >();
        a_iArgs += static_cast< GEInt >( static_cast< GEDouble >( AggressorSkills.GetDexterity() - AggressorSkills.GetStrength() ) * dMultiplier );
        break;
    }
    return ( *pfOriginalDoDamage )( a_pSPU, a_pSelfEntity, a_pOtherEntity, a_iArgs );
}

extern "C" __declspec( dllexport ) gSScriptInit const * GE_STDCALL ScriptInit( void )
{
eSScriptBase * pScript = const_cast< eSScriptBase * >( eCScriptFunctionMap::GetInstance().GetScript( "DoDamage" ) );
if ( ( !pScript ) || ( !pScript->m_funcFunction ) )
{
    gCScriptAdmin & ScriptAdmin = *dynamic_cast< gCScriptAdmin * >( eCModuleAdmin::GetInstance().FindModule( "gCScriptAdmin" ) );
    ScriptAdmin.LoadScriptDLL( "Script_Game.dll" );
    return ScriptInit();
}
pfOriginalDoDamage = reinterpret_cast< gFScript >( pScript->m_funcFunction );
pScript->m_funcFunction = &PrepareDoDamage;

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
