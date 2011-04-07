#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Engine.h"
#include "Music.h"

enum gEAniState
{
    gEAniState_Dummy0        = 0x00000000,
    gEAniState_Dummy1        = 0x00000001,
    gEAniState_Stand         = 0x00000002,
    gEAniState_Sneak         = 0x00000003,
    gEAniState_Attack        = 0x00000004,
    gEAniState_Parade        = 0x00000005,
    gEAniState_Kneel         = 0x00000006,
    gEAniState_SitGround     = 0x00000007,
    gEAniState_SitStool      = 0x00000008,
    gEAniState_SitBench      = 0x00000009,
    gEAniState_SitThrone     = 0x0000000A,
    gEAniState_SleepBed      = 0x0000000B,
    gEAniState_SleepGround   = 0x0000000C,
    gEAniState_SitBathtub    = 0x0000000D,
    gEAniState_Down          = 0x0000000E,
    gEAniState_DownBack      = 0x0000000F,
    gEAniState_Dead          = 0x00000010,
    gEAniState_DeadBack      = 0x00000011,
    gEAniState_Finished      = 0x00000012,
    gEAniState_FinishedBack  = 0x00000013,
    gEAniState_TalkStand     = 0x00000014,
    gEAniState_TalkSitGround = 0x00000015,
    gEAniState_TalkSitStool  = 0x00000016,
    gEAniState_TalkSitBench  = 0x00000017,
    gEAniState_TalkSitThrone = 0x00000018,
    gEAniState_Wade          = 0x00000019,
    gEAniState_Swim          = 0x0000001A,
    gEAniState_Dive          = 0x0000001B,
    gEAniState_Stumble       = 0x0000001C,
    gEAniState_Levitate      = 0x0000001D,
    gEAniState_ForceDWORD    = GE_FORCE_DWORD
};

enum gEAttitude
{
    gEAttitude_None       = 0x00000000,
    gEAttitude_Friendly   = 0x00000001,
    gEAttitude_Neutral    = 0x00000002,
    gEAttitude_Angry      = 0x00000003,
    gEAttitude_Hostile    = 0x00000004,
    gEAttitude_ForceDWORD = GE_FORCE_DWORD
};

enum gEBraveryOverride
{
    gEBraveryOverride_None       = 0x00000000,
    gEBraveryOverride_Brave      = 0x00000001,
    gEBraveryOverride_Coward     = 0x00000002,
    gEBraveryOverride_ForceDWORD = GE_FORCE_DWORD
};

enum gECharMovementMode
{
    //FIXME: gECharMovementMode constants.
    gECharMovementMode_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatMode
{
    gECombatMode_None       = 0x00000000,
    gECombatMode_Carry      = 0x00000001,
    gECombatMode_Melee      = 0x00000002,
    gECombatMode_Ranged     = 0x00000003,
    gECombatMode_Magic      = 0x00000004,
    gECombatMode_Cast       = 0x00000005,
    gECombatMode_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatPose
{
    gECombatPose_P0         = 0x00000000,
    gECombatPose_P1         = 0x00000001,
    gECombatPose_P2         = 0x00000002,
    gECombatPose_ForceDWORD = GE_FORCE_DWORD
};

enum gEComment
{
    gEComment_None              = 0x00000000,
    gEComment_DefeatInquisition = 0x00000001,
    gEComment_Theft             = 0x00000002,
    gEComment_Livestock         = 0x00000003,
    gEComment_Defeat            = 0x00000004,
    gEComment_Count             = 0x00000005,
    gEComment_ForceDWORD        = GE_FORCE_DWORD
};

enum gECrime
{
    gECrime_None            = 0x00000000,
    gECrime_MurderLivestock = 0x00000001,
    gECrime_Theft           = 0x00000002,
    gECrime_Murder          = 0x00000003,
    gECrime_Count           = 0x00000004,
    gECrime_ForceDWORD      = GE_FORCE_DWORD
};

enum gEDamageCalculationType
{
    gEDamageCalculationType_Normal     = 0x00000000,
    gEDamageCalculationType_Monster    = 0x00000001,
    gEDamageCalculationType_Immortal   = 0x00000002,
    gEDamageCalculationType_ForceDWORD = GE_FORCE_DWORD
};

enum gEDamageType
{
    gEDamageType_None       = 0x00000000,
    gEDamageType_Edge       = 0x00000001,
    gEDamageType_Blunt      = 0x00000002,
    gEDamageType_Point      = 0x00000003,
    gEDamageType_Fire       = 0x00000004,
    gEDamageType_Ice        = 0x00000005,
    gEDamageType_Magic      = 0x00000006,
    gEDamageType_Physics    = 0x00000007,
    gEDamageType_ForceDWORD = GE_FORCE_DWORD
};

enum gEDirection
{
    //FIXME: gEDirection constants.
    gEDirection_ForceDWORD = GE_FORCE_DWORD
};

enum gEFight
{
    gEFight_None       = 0x00000000,
    gEFight_Lost       = 0x00000001,
    gEFight_Won        = 0x00000002,
    gEFight_Cancel     = 0x00000003,
    gEFight_Running    = 0x00000004,
    gEFight_ForceDWORD = GE_FORCE_DWORD
};

enum gEGuardStatus
{
    gEGuardStatus_Active          = 0x00000000,
    gEGuardStatus_FirstWarnGiven  = 0x00000001,
    gEGuardStatus_SecondWarnGiven = 0x00000002,
    gEGuardStatus_Inactive        = 0x00000003,
    gEGuardStatus_Behind          = 0x00000004,
    gEGuardStatus_ForceDWORD      = GE_FORCE_DWORD
};

enum gEGender
{
    gEGender_Male       = 0x00000000,
    gEGender_Female     = 0x00000001,
    gEGender_ForceDWORD = GE_FORCE_DWORD
};

enum gEGuild
{
    gEGuild_None       = 0x00000000,
    gEGuild_Don        = 0x00000001,
    gEGuild_Dig        = 0x00000002,
    gEGuild_Grd        = 0x00000003,
    gEGuild_Cit        = 0x00000004,
    gEGuild_Inq        = 0x00000005,
    gEGuild_Mag        = 0x00000006,
    gEGuild_Pir        = 0x00000007,
    gEGuild_Count      = 0x00000008,
    gEGuild_ForceDWORD = GE_FORCE_DWORD
};

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

enum gEOutputType
{
    //FIXME: gEOutputType constants.
    gEOutputType_ForceDWORD = GE_FORCE_DWORD
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

enum gEReason
{
    gEReason_None            = 0x00000000,
    gEReason_SVM_Ambient     = 0x00000001,
    gEReason_SVM_Combat      = 0x00000002,
    gEReason_SVM_Party       = 0x00000003,
    gEReason_PlayerTalk      = 0x00000004,
    gEReason_ImportantInfo   = 0x00000005,
    gEReason_PlayerSneaking  = 0x00000006,
    gEReason_PlayerWeapon    = 0x00000007,
    gEReason_PlayerRoom      = 0x00000008,
    gEReason_PlayerUseBed    = 0x00000009,
    gEReason_Eat             = 0x0000000A,
    gEReason_Ransack         = 0x0000000B,
    gEReason_Fighter         = 0x0000000C,
    gEReason_Attacker        = 0x0000000D,
    gEReason_Nuisance        = 0x0000000E,
    gEReason_Joke            = 0x0000000F,
    gEReason_Frost           = 0x00000010,
    gEReason_Damage          = 0x00000011,
    gEReason_DamageLivestock = 0x00000012,
    gEReason_MurderLivestock = 0x00000013,
    gEReason_Theft           = 0x00000014,
    gEReason_Illusion        = 0x00000015,
    gEReason_GateGuard       = 0x00000016,
    gEReason_Defeat          = 0x00000017,
    gEReason_Inspect         = 0x00000018,
    gEReason_Finish          = 0x00000019,
    gEReason_Raider          = 0x0000001A,
    gEReason_Enemy           = 0x0000001B,
    gEReason_Murder          = 0x0000001C,
    gEReason_Duel            = 0x0000001D,
    gEReason_Arena           = 0x0000001E,
    gEReason_Kill            = 0x0000001F,
    gEReason_Count           = 0x00000020,
    gEReason_ForceDWORD      = GE_FORCE_DWORD
};

enum gESecurityLevel
{
    //FIXME: gESecurityLevel constants.
    gESecurityLevel_ForceDWORD = GE_FORCE_DWORD
};

enum gESkill
{
    gESkill_None            = 0xFFFFFFFF,
    gESkill_Atrib_HP        = 0x00000000,
    gESkill_Atrib_MP        = 0x00000001,
    gESkill_Stat_LV         = 0x00000002,
    gESkill_Stat_XP         = 0x00000003,
    gESkill_Stat_LP         = 0x00000004,
    gESkill_Stat_HP         = 0x00000005,
    gESkill_Stat_MP         = 0x00000006,
    gESkill_Stat_STR        = 0x00000007,
    gESkill_Stat_DEX        = 0x00000008,
    gESkill_Stat_INT        = 0x00000009,
    gESkill_Prot_Edge       = 0x0000000A,
    gESkill_Prot_Blunt      = 0x0000000B,
    gESkill_Prot_Point      = 0x0000000C,
    gESkill_Prot_Fire       = 0x0000000D,
    gESkill_Prot_Ice        = 0x0000000E,
    gESkill_Prot_Magic      = 0x0000000F,
    gESkill_Combat_Sword    = 0x00000010,
    gESkill_Combat_Axe      = 0x00000011,
    gESkill_Combat_Staff    = 0x00000012,
    gESkill_Combat_Bow      = 0x00000013,
    gESkill_Combat_CrossBow = 0x00000014,
    gESkill_Magic_Circle    = 0x00000015,
    gESkill_Magic_Fireball  = 0x00000016,
    gESkill_Magic_Frost     = 0x00000017,
    gESkill_Magic_Missile   = 0x00000018,
    gESkill_Misc_Smith      = 0x00000019,
    gESkill_Misc_Mining     = 0x0000001A,
    gESkill_Misc_Lockpick   = 0x0000001B,
    gESkill_Misc_Pickpocket = 0x0000001C,
    gESkill_Misc_Sneak      = 0x0000001D,
    gESkill_Misc_Acrobat    = 0x0000001E,
    gESkill_Misc_Alchemy    = 0x0000001F,
    gESkill_Misc_Scribe     = 0x00000020,
    gESkill_Misc_Trophy     = 0x00000021,
    gESkill_Count           = 0x00000022,
    gESkill_ForceDWORD      = GE_FORCE_DWORD
};

enum gESkillCategroy
{
    //NOTE: I did not use the typo for the constants.
    gESkillCategory_Atrib      = 0x00000000,
    gESkillCategory_Stat1      = 0x00000001,  // LV/XP/LP
    gESkillCategory_Stat2      = 0x00000002,  // HP/MP/STR/DEX/INT
    gESkillCategory_Prot       = 0x00000003,
    gESkillCategory_Combat     = 0x00000004,
    gESkillCategory_Magic      = 0x00000005,
    gESkillCategory_Misc       = 0x00000006,
    gESkillCategory_ForceDWORD = GE_FORCE_DWORD
};

enum gESkillModifier
{
    gESkillModifier_AddValue        = 0x00000000,
    gESkillModifier_SetToMax        = 0x00000001,
    gESkillModifier_SetToValue      = 0x00000002,
    gESkillModifier_AddPercentOfMax = 0x00000003,
    gESkillModifier_ForceDWORD      = GE_FORCE_DWORD
};

enum gESpecies
{
    gESpecies_None          = 0x00000000,
    gESpecies_Human         = 0x00000001,
    gESpecies_Lizard        = 0x00000002,
    gESpecies_Brontok       = 0x00000003,
    gESpecies_Wolf_Tame     = 0x00000004,
    gESpecies_Lurker        = 0x00000005,
    gESpecies_Ashbeast      = 0x00000006,
    gESpecies_Nautilus      = 0x00000007,
    gESpecies_Dragonfly     = 0x00000008,
    gESpecies_Mantis        = 0x00000009,
    gESpecies_Scorpion      = 0x0000000A,
    gESpecies_Skeleton      = 0x0000000B,
    gESpecies_Swampmummy    = 0x0000000C,
    gESpecies_Rotworm       = 0x0000000D,
    gESpecies_Skeleton_Tame = 0x0000000E,
    gESpecies_Gnome         = 0x0000000F,
    gESpecies_Boar          = 0x00000010,
    gESpecies_Wolf          = 0x00000011,
    gESpecies_Stingrat      = 0x00000012,
    gESpecies_Vulture       = 0x00000013,
    gESpecies_Thundertail   = 0x00000014,
    gESpecies_Ogre          = 0x00000015,
    gESpecies_Ogre_Tame     = 0x00000016,
    gESpecies_Cow           = 0x00000017,
    gESpecies_Pig           = 0x00000018,
    gESpecies_Chicken       = 0x00000019,
    gESpecies_Ghost         = 0x0000001A,
    gESpecies_Count         = 0x0000001B,
    gESpecies_ForceDWORD    = GE_FORCE_DWORD
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

class eCAudioChannel{};
class eCSoundResource2{};

#include "Game/ge_npc_ps.h"
#include "Game/ge_skillvaluebase.h"
#include "Game/ge_skillvalue.h"
#include "Game/ge_modifyskill.h"
#include "Game/ge_skills_ps.h"

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

typedef eSScriptBase gSScript;
#include "Game/ge_scriptproxyaicallback.h"
typedef eSScriptBase gSScriptAICallback;
#include "Game/ge_scriptproxyaifunction.h"
typedef eSScriptBase gSScriptAIFunction;
#include "Game/ge_scriptproxyaistate.h"
typedef eSScriptBase gSScriptAIState;

struct gSArgsForScriptBase{};
#include "Game/ge_scriptprocessingunit.h"
#include "Game/ge_scriptroutine_ps.h"
#include "Game/ge_scriptinit.h"
#include "Game/ge_scriptadmin.h"

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
/** /
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

#endif
