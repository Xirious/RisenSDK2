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

enum gEDirection
{
    //FIXME: gEDirection constants.
    gEDirection_ForceDWORD = GE_FORCE_DWORD
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

enum gEOutputType
{
    //FIXME: gEOutputType constants.
    gEOutputType_ForceDWORD = GE_FORCE_DWORD
};

enum gEQuestActor
{
    gEQuestActor_Client,
    gEQuestActor_Target,
    gEQuestActor_ForceDWORD = GE_FORCE_DWORD
};

enum gESecurityLevel
{
    //FIXME: gESecurityLevel constants.
    gESecurityLevel_ForceDWORD = GE_FORCE_DWORD
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
class gCScriptRoutine_PS{};
#include "Game/ge_scriptprocessingunit.h"
#include "Game/ge_scriptinit.h"
#include "Game/ge_scriptadmin.h"

#endif
