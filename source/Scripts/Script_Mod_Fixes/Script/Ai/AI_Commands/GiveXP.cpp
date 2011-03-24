#include "../../../Script_Mod_Fixes.h"

namespace CallScript
{
    eCScriptProxyScript IsPlayerPartyOrGuide( "IsPlayerPartyOrGuide" );
    eCScriptProxyScript IsSmall( "IsSmall" );
}

GEInt GE_STDCALL GiveXP( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iIntParameter )
{
    Entity Self;
    if( a_pSelfEntity )
        Self = *static_cast< Entity const * >( a_pSelfEntity );
    else
        Self.AttachTo( a_pSPU->GetSelfEntity() );

    Entity Other;
    if( a_pOtherEntity )
        Other = *static_cast< Entity const * >( a_pOtherEntity );
    else
        Other.AttachTo( a_pSPU->GetOtherEntity() );

    GEInt iAmount = a_iIntParameter;
    GEBool bLevel = (iAmount == -1);

    if( CallScript::IsPlayerPartyOrGuide( Other, 0, 0 ) &&
        (!bLevel || !CallScript::IsPlayerPartyOrGuide( Self, 0, 0 )) )
	{
        if( bLevel && Self.PropertySet< PSNpc >().IsValid() )
        {
            iAmount = Self.PropertySet< PSSkills >().GetLevel() * 10;
            if( CallScript::IsSmall( Self, 0, 0 ) )
            {
                if( iAmount < 10 )
                    iAmount = 10;
            }
            else
            {
                if( iAmount < 50 )
                    iAmount = 50;
            }
        }

        gui2.PrintGameLog(
            eCLocString( "GO_XP" ).GetString() +
            bCUnicodeString( " + " ) +
            bCUnicodeString( iAmount ),
            gELogMessageType_Gold, GEFalse, 0 );

        Entity Player = Entity::GetPlayer();  
        Entity OriginalPlayer = Entity::GetOriginalPlayer();
        PSSkills & PlayerSkills = OriginalPlayer.PropertySet< PSNpc >().IsValid() ?
            OriginalPlayer.PropertySet< PSSkills >() : Player.PropertySet< PSSkills >();
        do
        {
            GEInt iExperience = PlayerSkills.GetExperience();
            PlayerSkills.SetExperience( iAmount, gESkillModifier_AddValue );
            iAmount -= (PlayerSkills.GetExperience() - iExperience);
        }
        while( iAmount > 0 );

        return 1;
    }
    return 0;
}
