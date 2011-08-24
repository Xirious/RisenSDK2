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

enum gEItemHoldType
{
    gEItemHoldType_None          = 0x00000000,
    gEItemHoldType_1H            = 0x00000001,
    gEItemHoldType_2H            = 0x00000002,
    gEItemHoldType_BS            = 0x00000003,
    gEItemHoldType_Arrow         = 0x00000004,
    gEItemHoldType_Bow           = 0x00000005,
    gEItemHoldType_CrossBow      = 0x00000006,
    gEItemHoldType_Bolt          = 0x00000007,
    gEItemHoldType_Fist          = 0x00000008,
    gEItemHoldType_Shield        = 0x00000009,
    gEItemHoldType_Armor         = 0x0000000A,
    gEItemHoldType_Helmet        = 0x0000000B,
    gEItemHoldType_Staff         = 0x0000000C,
    gEItemHoldType_Amulet        = 0x0000000D,
    gEItemHoldType_Ring          = 0x0000000E,
    gEItemHoldType_Rune          = 0x0000000F,
    gEItemHoldType_Torch         = 0x00000010,
    gEItemHoldType_CarryFront    = 0x00000011,
    gEItemHoldType_Axe           = 0x00000012,
    gEItemHoldType_Apple         = 0x00000013,
    gEItemHoldType_Bread         = 0x00000014,
    gEItemHoldType_Jar           = 0x00000015,
    gEItemHoldType_Joint         = 0x00000016,
    gEItemHoldType_Meat          = 0x00000017,
    gEItemHoldType_Potion        = 0x00000018,
    gEItemHoldType_Saringda      = 0x00000019,
    gEItemHoldType_Saw           = 0x0000001A,
    gEItemHoldType_Scoop         = 0x0000001B,
    gEItemHoldType_Stew          = 0x0000001C,
    gEItemHoldType_Cast          = 0x0000001D,
    gEItemHoldType_Magic         = 0x0000001E,
    gEItemHoldType_FocusCast     = 0x0000001F,
    gEItemHoldType_MagicMissile  = 0x00000020,
    gEItemHoldType_MagicFireball = 0x00000021,
    gEItemHoldType_MagicIcelance = 0x00000022,
    gEItemHoldType_Flute         = 0x00000023,
    gEItemHoldType_ForceDWORD    = GE_FORCE_DWORD
};

enum gEItemUseType
{
    gEItemUseType_None          = 0x00000000,
    gEItemUseType_1H            = 0x00000001,
    gEItemUseType_2H            = 0x00000002,
    gEItemUseType_BS            = 0x00000003,
    gEItemUseType_Arrow         = 0x00000004,
    gEItemUseType_Bow           = 0x00000005,
    gEItemUseType_CrossBow      = 0x00000006,
    gEItemUseType_Bolt          = 0x00000007,
    gEItemUseType_Fist          = 0x00000008,
    gEItemUseType_Shield        = 0x00000009,
    gEItemUseType_Armor         = 0x0000000A,
    gEItemUseType_Helmet        = 0x0000000B,
    gEItemUseType_Staff         = 0x0000000C,
    gEItemUseType_Amulet        = 0x0000000D,
    gEItemUseType_Ring          = 0x0000000E,
    gEItemUseType_Rune          = 0x0000000F,
    gEItemUseType_Torch         = 0x00000010,
    gEItemUseType_CarryFront    = 0x00000011,
    gEItemUseType_Axe           = 0x00000012,
    gEItemUseType_Cast          = 0x00000013,
    gEItemUseType_FocusCast     = 0x00000014,
    gEItemUseType_MagicMissile  = 0x00000015,
    gEItemUseType_MagicFireball = 0x00000016,
    gEItemUseType_MagicIcelance = 0x00000017,
    gEItemUseType_MagicAmmo     = 0x00000018,
    gEItemUseType_MagicFrost    = 0x00000019,
    gEItemUseType_Head          = 0x0000001A,
    gEItemUseType_ForceDWORD    = GE_FORCE_DWORD
};

enum gELockCombi
{
    //FIXME: gELockCombi constants.
    gELockCombi_ForceDWORD = GE_FORCE_DWORD
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

enum gESlot
{
    //FIXME: gESlot constants.
    gESlot_ForceDWORD = GE_FORCE_DWORD
};

enum gEStackType
{
    gEStackType_Normal     = 0x00000000,
    gEStackType_Trade      = 0x00000001,
    gEStackType_Hidden     = 0x00000002,
    gEStackType_ForceDWORD = GE_FORCE_DWORD
};

enum gEWalkMode
{
    gEWalkMode_Sneak      = 0x00000000,
    gEWalkMode_Walk       = 0x00000001,
    gEWalkMode_Run        = 0x00000002,
    gEWalkMode_Sprint     = 0x00000003,
    gEWalkMode_ForceDWORD = GE_FORCE_DWORD
};

typedef eSScriptBase gSScript;
#include "Game/ge_scriptproxyaicallback.h"
typedef eSScriptBase gSScriptAICallback;
#include "Game/ge_scriptproxyaifunction.h"
typedef eSScriptBase gSScriptAIFunction;
#include "Game/ge_scriptproxyaistate.h"
typedef eSScriptBase gSScriptAIState;

#include "Game/ge_skillvaluebase.h"
#include "Game/ge_skillrange.h"
#include "Game/ge_skillvalue.h"
#include "Game/ge_modifyskill.h"
#include "Game/ge_skills_ps.h"

#include "Game/ge_npc_ps.h"
#include "Game/ge_aizone_ps.h"
class gCInteraction_PS{};
#include "Game/ge_anchor_ps.h"
#include "Game/ge_arena_ps.h"
#include "Game/ge_book_ps.h"
#include "Game/ge_castinfo_ps.h"
#include "Game/ge_clock_ps.h"
#include "Game/ge_damage_ps.h"
#include "Game/ge_dialog_ps.h"
#include "Game/ge_door_ps.h"

class eCAudioChannel{};

class gCCharacterControl{};
class gCCharacterSensor{};
#include "Game/ge_actionadmin.h"

#include "Game/ge_charactermovement_ps.h"

#include "Game/ge_flightpathbase.h"
#include "Game/ge_flightpathballistic.h"
#include "Game/ge_flightpathseeking.h"

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

struct gSArgsForScriptBase{};
class gCScriptAdmin;
class gCScriptRoutine_PS;
#include "Game/ge_scriptprocessingunit.h"
#include "Game/ge_scriptroutine_ps.h"
#include "Game/ge_scriptinit.h"
#include "Game/ge_scriptadmin.h"

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

class eCGuiBitmapProxy2
{
    void * m_pBitmap;  // eCDeferredGuiBitmap2 *
};
class gCInventory_PS{};
class gCInventoryStack{};

#include "Game/ge_questactor.h"
#include "Game/ge_questlocstring.h"
#include "Game/ge_quest.h"
#include "Game/ge_questmanager.h"

#include "Game/ge_info.h"
#include "Game/ge_infolocstring.h"
#include "Game/ge_npcinfolocstring.h"
#include "Game/ge_runtimeinfo.h"
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
/** /
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
/**/
#include "Game/ge_infocondition.h"
/** /
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
/**/
class gCInfoSystem{};

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