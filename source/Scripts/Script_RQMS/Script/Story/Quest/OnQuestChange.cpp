#include "../../../Script_RQMS.h"

namespace CallScript
{
    eCScriptProxyScript GiveXP( "GiveXP" );
}

GEInt GE_STDCALL OnQuestChange( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt a_iIntParameter )
{
    struct SQuestChange {
        bCString      m_strName;
        gEQuestStatus m_enumStatus;
        gEQuestStatus m_enumPreviousStatus;
    } const & QuestChange = *reinterpret_cast< SQuestChange const * >( a_iIntParameter );

    if( gEQuestStatus_Success == QuestChange.m_enumStatus )
    {
        gCQuestManager * pQuestManager = gCQuestManager::GetInstance();
        if( pQuestManager )
        {
            gCQuest const * pQuest = pQuestManager->GetQuest( QuestChange.m_strName );
            if( pQuest && !pQuest->GetSilent() )
            {
                Entity Player = Entity::GetPlayer();
                Entity OriginalPlayer = Entity::GetOriginalPlayer();
                GEBool bPlayerIsTransformed = OriginalPlayer.GetPropertySet< PSNpc >().IsValid();
                GEBool bRetroQuestMessageSystemActivated = pQuestManager->GetRetroQuestMessageSystemActivated();

                //NOTE: ModifySkillsSuccess has not been used in the original quests.
                if( bRetroQuestMessageSystemActivated || bPlayerIsTransformed )
                {
                    gCSkills_PS * pPlayerEngineSkills = bPlayerIsTransformed ?
                        OriginalPlayer.AccessEnginePropertySet< PSSkills >() :
                        Player.AccessEnginePropertySet< PSSkills >();
                    if( pPlayerEngineSkills )
                        pPlayerEngineSkills->ModifySkillValues( pQuest->GetModifySkillsSuccess(), GETrue );
                }
                if( bRetroQuestMessageSystemActivated )
                {
                    GEInt iExperiencePoints = static_cast< GEInt >( pQuest->GetExperiencePoints() );
                    if( iExperiencePoints )
                        CallScript::GiveXP( 0, Player, iExperiencePoints );
                }
            }
        }

        //NOTE: This is the original code for succeeded quests.
        achievement.OnHandleQuestSuccess( QuestChange.m_strName );
    }
    return 1;
};
