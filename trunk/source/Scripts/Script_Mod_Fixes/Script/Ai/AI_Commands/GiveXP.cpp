#include "../../../Script_Mod_Fixes.h"

eCScriptProxyScript IsPlayerPartyOrGuide( "IsPlayerPartyOrGuide" );
eCScriptProxyScript IsSmall( "IsSmall" );

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

    //NOTE: Entity::GetEntity( "PC_Hero" ) to gain experience while being transformed.
    Entity Player = Entity::GetPlayer();  
    GEInt iAmount = a_iIntParameter;
    GEBool bLevel = (iAmount == -1);

    if( IsPlayerPartyOrGuide( Other, 0, 0 ) && ((IsPlayerPartyOrGuide( Self, 0, 0 ) != 1) || (bLevel != GETrue)) )
	{
        if( (Self.PropertySet< PSNpc >().IsValid() == GETrue) && (bLevel == GETrue) )
        {
            GEInt iLevel = Self.PropertySet< PSSkills >().GetLevel();
            if( iLevel < 1 )
                iLevel = 1;
            iAmount = iLevel * 10;
            if( IsSmall( Self, 0, 0 ) == 1 )
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

        do
		{
			GEInt iExperience = Player.PropertySet< PSSkills >().GetExperience();
			Player.PropertySet< PSSkills >().SetExperience( iAmount, gESkillModifier_AddValue );
			iAmount -= (Player.PropertySet< PSSkills >().GetExperience() - iExperience);
		}
		while( iAmount > 0 );

		return 1;
	}
    return 0;
}
