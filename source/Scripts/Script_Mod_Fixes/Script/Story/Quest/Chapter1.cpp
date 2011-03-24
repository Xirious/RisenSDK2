#include "../../../Script_Mod_Fixes.h"

GEInt GE_STDCALL OnQuestSuccess_CloseQuestWine( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt )
{
    QuestManager::CloseQuest( "Caspar_TrickBronco" );
    return 1;
};
