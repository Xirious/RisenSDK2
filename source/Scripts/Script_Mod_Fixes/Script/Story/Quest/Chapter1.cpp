#include "Chapter1.h"

GEInt GE_STDCALL OnQuestSuccess_CloseQuestWine( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt )
{
//  QuestManager::CloseQuest( "Bronco_ArenaFight" );
    QuestManager::CloseQuest( "Caspar_TrickBronco" );
    return 1;
};
