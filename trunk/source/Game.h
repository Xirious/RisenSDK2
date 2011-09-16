#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Engine.h"
#include "Music.h"

enum gEHudMode
{
    //FIXME: gEHudMode constants.
    gEHudMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEHudPage
{
    gEHudPage_None             = 0x00000000,
    gEHudPage_Game             = 0x00000001,
    gEHudPage_Inventory        = 0x00000002,
    gEHudPage_Character        = 0x00000003,
    gEHudPage_Log              = 0x00000004,
    gEHudPage_Map              = 0x00000005,
    gEHudPage_CraftSelect      = 0x00000006,
    gEHudPage_ItemSelect       = 0x00000007,
    gEHudPage_Loot             = 0x00000008,
    gEHudPage_Pickpocket       = 0x00000009,
    gEHudPage_Trade            = 0x0000000A,
    gEHudPage_Dialog           = 0x0000000B,
    gEHudPage_Talk             = 0x0000000C,
    gEHudPage_Menu_Main        = 0x0000000D,
    gEHudPage_Menu_Game        = 0x0000000E,
    gEHudPage_Menu_Load        = 0x0000000F,
    gEHudPage_Menu_Save        = 0x00000010,
    gEHudPage_Menu_Achievement = 0x00000011,
    gEHudPage_Menu_Options     = 0x00000012,
    gEHudPage_Menu_Video       = 0x00000013,
    gEHudPage_Menu_Audio       = 0x00000014,
    gEHudPage_Menu_Input       = 0x00000015,
    gEHudPage_Menu_Settings    = 0x00000016,
    gEHudPage_Menu_System      = 0x00000017,
    gEHudPage_Menu_Credits     = 0x00000018,
    gEHudPage_Menu_Cheats      = 0x00000019,
    gEHudPage_Menu_Back        = 0x0000001A,
    gEHudPage_Outro            = 0x0000001B,
    gEHudPage_Loading          = 0x0000001C,
    gEHudPage_ForceDWORD       = GE_FORCE_DWORD
};

enum gELogMessageType
{
    gELogMessageType_Grey       = 0x00000000,
    gELogMessageType_Red        = 0x00000001,
    gELogMessageType_Gold       = 0x00000002,
    gELogMessageType_Lime       = 0x00000003,
    gELogMessageType_Count      = 0x00000004,
    gELogMessageType_ForceDWORD = GE_FORCE_DWORD
};

enum gENavTestResult
{
    gENavTestResult_Succeeded                        = 0x00000000,
    gENavTestResult_NavPathWithOneDeadEnd            = 0x00000001,
    gENavTestResult_NavPathWithTwoDeadEnds           = 0x00000002,
    gENavTestResult_NavPathBlockedByCollisionCircle  = 0x00000003,
    gENavTestResult_NavPathIllegalBuild              = 0x00000004,
    gENavTestResult_PrefPathOutOfNavZone             = 0x00000005,
    gENavTestResult_PrefPathBlockedByCollisionCircle = 0x00000006,
    gENavTestResult_PrefPathIllegalBuild             = 0x00000007,
    gENavTestResult_NavZoneInConflict                = 0x00000008,
    gENavTestResult_NavZoneIllegalBuild              = 0x00000009,
    gENavTestResult_NegZoneOutOfNavZone              = 0x0000000A,
    gENavTestResult_NegZoneIllegalBuild              = 0x0000000B,
    gENavTestResult_FreePointOutOfNavArea            = 0x0000000C,
    gENavTestResult_FreePointInNegZone               = 0x0000000D,
    gENavTestResult_FreePointInCollisionCircle       = 0x0000000E,
//  gENavTestResult_0000000F
    gENavTestResult_NavOffsetOutOfNavArea            = 0x00000010,
    gENavTestResult_ForceDWORD                       = GE_FORCE_DWORD
};

enum gEPageMode
{
    gEPageMode_None       = 0x00000000,
    gEPageMode_Panorama   = 0x00000001,
    gEPageMode_Dialog     = 0x00000003,
    gEPageMode_UserMin    = 0x00000004,
    gEPageMode_UserSlots  = 0x00000006,
    gEPageMode_UserMax    = 0x00000007,
    gEPageMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEWalkMode
{
    gEWalkMode_Sneak      = 0x00000000,
    gEWalkMode_Walk       = 0x00000001,
    gEWalkMode_Run        = 0x00000002,
    gEWalkMode_Sprint     = 0x00000003,
    gEWalkMode_ForceDWORD = GE_FORCE_DWORD
};

#include "Game/ge_letterlocstring.h"
#include "Game/ge_letter_ps.h"

#include "Game/ge_lock_ps.h"

#include "Game/ge_mapentry.h"
#include "Game/ge_map_ps.h"
#include "Game/ge_mapinfo_ps.h"
#include "Game/ge_maplocstring.h"

#include "Game/ge_party_ps.h"
#include "Game/ge_partyadmin.h"

#include "Game/ge_scriptproxyaicallback.h"
#include "Game/ge_scriptproxyaifunction.h"
#include "Game/ge_scriptproxyaistate.h"

#include "Game/ge_skillvaluebase.h"
#include "Game/ge_skillrange.h"
#include "Game/ge_skillvalue.h"
#include "Game/ge_modifyskill.h"
#include "Game/ge_skills_ps.h"

class gCInteraction_PS;
#include "Game/ge_interaction.h"
#include "Game/ge_interactionslot.h"
#include "Game/ge_interaction_ps.h"
#include "Game/ge_interactionadmin.h"

#include "Game/ge_npc_ps.h"
#include "Game/ge_aizone_ps.h"
#include "Game/ge_anchor_ps.h"
#include "Game/ge_arena_ps.h"
#include "Game/ge_book_ps.h"
#include "Game/ge_castinfo_ps.h"
#include "Game/ge_clock_ps.h"
#include "Game/ge_damage_ps.h"
#include "Game/ge_dialog_ps.h"
#include "Game/ge_door_ps.h"
#include "Game/ge_effect_ps.h"

class eCAudioChannel{};

class gCCharacterControl{};
class gCCharacterSensor{};
#include "Game/ge_actionadmin.h"

#include "Game/ge_charactermovement_ps.h"

#include "Game/ge_collisioncircle_psobj.h"
#include "Game/ge_collisioncircle_ps.h"
#include "Game/ge_prefpath_psobj.h"
#include "Game/ge_prefpath_ps.h"
class gCDynamicCollisionCircle_PS;
#include "Game/ge_navpath_ps.h"
#include "Game/ge_navigation_ps.h"
#include "Game/ge_negzone_psobj.h"
#include "Game/ge_negzone_ps.h"
#include "Game/ge_navzone_ps.h"
#include "Game/ge_dynamiccollisioncircle_ps.h"

#include "Game/ge_flightpathbase.h"
#include "Game/ge_flightpathballistic.h"
#include "Game/ge_flightpathseeking.h"
#include "Game/ge_projectile2_ps.h"

#include "Game/ge_effectcommand.h"
#include "Game/ge_effectcommandearthquake.h"
#include "Game/ge_effectcommandmodifyentity.h"
#include "Game/ge_effectcommandplaysound.h"
#include "Game/ge_effectcommandplayvoice.h"
#include "Game/ge_effectcommandrunscript.h"
#include "Game/ge_effectcommandsaysvm.h"
#include "Game/ge_effectcommandstartimageeffect.h"
#include "Game/ge_effectcommandtriggerentity.h"
#include "Game/ge_effectcommandentity.h"
#include "Game/ge_effectcommandkillentity.h"
#include "Game/ge_effectcommandkillentityrange.h"
#include "Game/ge_effectcommandspawnentity.h"
#include "Game/ge_effectcommandspawnentitylist.h"
#include "Game/ge_effectcommandspawnentityswitch.h"
#include "Game/ge_effectcommandsequence2.h"
#include "Game/ge_effect.h"

#include "Game/ge_scriptargs.h"
class gCScriptAdmin;
class gCScriptRoutine_PS;
#include "Game/ge_scriptprocessingunit.h"
#include "Game/ge_scriptroutine_ps.h"
#include "Game/ge_scriptinit.h"
#include "Game/ge_scriptadmin.h"

enum gESlot;
class gCInventory_PS;
#include "Game/ge_item_ps.h"
#include "Game/ge_inventoryslot.h"
#include "Game/ge_inventorystack.h"
#include "Game/ge_inventorylistener.h"
#include "Game/ge_inventory_ps.h"

#include "Game/ge_combatobject.h"
class gCCombatAI;
class gCCombatStyle;
class gCCombatSpecies;
class gCCombatSystem_PS;
#include "Game/ge_combatmove.h"
#include "Game/ge_combatmoveaim.h"
#include "Game/ge_combatmovecomboswitch.h"
#include "Game/ge_combatmovefinishing.h"
#include "Game/ge_combatmovemelee.h"
#include "Game/ge_combatmoveoverlaystumble.h"
#include "Game/ge_combatmoveparade.h"
#include "Game/ge_combatmovereload.h"
#include "Game/ge_combatmovescriptstate.h"
#include "Game/ge_combatmoveshoot.h"
#include "Game/ge_combatmovestumble.h"
#include "Game/ge_combatai.h"
#include "Game/ge_combataimelee.h"
#include "Game/ge_combatairanged.h"
#include "Game/ge_combatweaponconfig.h"
#include "Game/ge_combatstyleanipose.h"
#include "Game/ge_combatstyleweaponconfig.h"
#include "Game/ge_combatstyle.h"
#include "Game/ge_combatstylemelee.h"
#include "Game/ge_combatstyleranged.h"
#include "Game/ge_combatspecies.h"
#include "Game/ge_combatsystem_ps.h"
#include "Game/ge_combatadmin.h"

#include "Game/ge_questactor.h"
#include "Game/ge_questlocstring.h"
enum gEInfoLocation;
class gCInfoSystem;
class gCQuestManager;
#include "Game/ge_quest.h"
#include "Game/ge_questmanager.h"

class gCInfo;
class gCInfoCommand;
#include "Game/ge_runtimeinfo.h"
class gCInfoCondition;
#include "Game/ge_info.h"
#include "Game/ge_infolocstring.h"
#include "Game/ge_npcinfolocstring.h"
#include "Game/ge_infocommand.h"
#include "Game/ge_infocommandaddinfosystemendscript.h"
#include "Game/ge_infocommandaddlogtext.h"
#include "Game/ge_infocommandaddnpcinfo.h"
#include "Game/ge_infocommandaddquestactor.h"
#include "Game/ge_infocommandattack.h"
#include "Game/ge_infocommandback.h"
#include "Game/ge_infocommandboostattribs.h"
#include "Game/ge_infocommandcleargameevent.h"
#include "Game/ge_infocommandclosequest.h"
#include "Game/ge_infocommandcreateitem.h"
#include "Game/ge_infocommanddescription.h"
#include "Game/ge_infocommanddestroyitem.h"
#include "Game/ge_infocommanddoloot.h"
#include "Game/ge_infocommanddotrade.h"
#include "Game/ge_infocommandend.h"
#include "Game/ge_infocommandendgame.h"
#include "Game/ge_infocommandfullstop.h"
#include "Game/ge_infocommandgive.h"
#include "Game/ge_infocommandgivexp.h"
#include "Game/ge_infocommandheal.h"
#include "Game/ge_infocommandinfowait.h"
#include "Game/ge_infocommandkillnpc.h"
#include "Game/ge_infocommandmoveto.h"
#include "Game/ge_infocommandpickpocket.h"
#include "Game/ge_infocommandplaymusic.h"
#include "Game/ge_infocommandremovenpc.h"
#include "Game/ge_infocommandremovenpcinfo.h"
#include "Game/ge_infocommandremovequestactor.h"
#include "Game/ge_infocommandrunaiscript.h"
#include "Game/ge_infocommandruninfo.h"
#include "Game/ge_infocommandrunquest.h"
#include "Game/ge_infocommandrunscript.h"
#include "Game/ge_infocommandsay.h"
#include "Game/ge_infocommandsayconfirm.h"
#include "Game/ge_infocommandsayholdingposition.h"
#include "Game/ge_infocommandsaykeepitup.h"
#include "Game/ge_infocommandsaysvm.h"
#include "Game/ge_infocommandsaysound.h"
#include "Game/ge_infocommandsetgameevent.h"
#include "Game/ge_infocommandsetguardstatus.h"
#include "Game/ge_infocommandsetmobenabled.h"
#include "Game/ge_infocommandsetpartyenabled.h"
#include "Game/ge_infocommandsetrelaxingpoint.h"
#include "Game/ge_infocommandsetroutine.h"
#include "Game/ge_infocommandsetsectorstatus.h"
#include "Game/ge_infocommandsetslaveryenabled.h"
#include "Game/ge_infocommandsetsleepingpoint.h"
#include "Game/ge_infocommandsetteachenabled.h"
#include "Game/ge_infocommandsettradeenabled.h"
#include "Game/ge_infocommandsetworkingpoint.h"
#include "Game/ge_infocommandshowpicture.h"
#include "Game/ge_infocommandshowsubtitle.h"
#include "Game/ge_infocommandsleep.h"
#include "Game/ge_infocommandstarteffect.h"
#include "Game/ge_infocommandstartfixcamera.h"
#include "Game/ge_infocommandstarttutorial.h"
#include "Game/ge_infocommandstopfixcamera.h"
#include "Game/ge_infocommandsucceedquest.h"
#include "Game/ge_infocommandteach.h"
#include "Game/ge_infocommandteleportnpc.h"
#include "Game/ge_infocommandthink.h"
#include "Game/ge_infocommandtrigger.h"
#include "Game/ge_infocommanduse.h"
#include "Game/ge_infocommandwear.h"
#include "Game/ge_infocondition.h"
#include "Game/ge_infoconditioncanteachskill.h"
#include "Game/ge_infoconditionitemamount.h"
#include "Game/ge_infoconditionnpcstatus.h"
#include "Game/ge_infoconditionownerinarea.h"
#include "Game/ge_infoconditionownernearentity.h"
#include "Game/ge_infoconditionplayerknows.h"
#include "Game/ge_infoconditionplayernotknows.h"
#include "Game/ge_infoconditionqueststatus.h"
#include "Game/ge_infoconditionscript.h"
#include "Game/ge_infoconditionskillvalue.h"
#include "Game/ge_infoconditionteachenabled.h"
#include "Game/ge_infosystem.h"
#include "Game/ge_infomodule.h"

#include "Game/ge_sessioncheats.h"
#include "Game/ge_sessioninfo.h"
#include "Game/ge_session.h"
class gCSector;
#include "Game/ge_layerbase.h"
#include "Game/ge_dynamiclayer.h"
//FIXME: gSSaveGameConflict
class gCWorld;
#include "Game/ge_sector.h"
class gCProject;
#include "Game/ge_world.h"
class gCWorkspace;
#include "Game/ge_project.h"
#include "Game/ge_database.h"
#include "Game/ge_workspace.h"
#include "Game/ge_gameapp.h"

#endif