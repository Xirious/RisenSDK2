#ifndef GS_PSROUTINE_H_INCLUDED
#define GS_PSROUTINE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSRoutine, gCScriptRoutine_PS )
public:
    GS_DECLARE_PROPERTY( AIDelay,            GEI32 )
    GS_DECLARE_PROPERTY( AIMode,             gEAIMode )
    GS_DECLARE_PROPERTY( ActionString,       bCString )
    GS_DECLARE_PROPERTY( AmbientAction,      gEAmbientAction )
    GS_DECLARE_PROPERTY( CommandTime,        GEI32 )
    GS_DECLARE_PROPERTY( EndAttackTimestamp, GEFloat )
    GS_DECLARE_PROPERTY( HitDirection,       gEHitDirection )
    GS_DECLARE_PROPERTY( LastAIMode,         gEAIMode )
    GS_DECLARE_PROPERTY( LockAIInterrupt,    GEBool )
    GS_DECLARE_PROPERTY( LockAIResult,       GEBool )
    GS_DECLARE_PROPERTY( Routine,            eCScriptProxyScript )
    GS_DECLARE_PROPERTY( RoutineChanged,     GEBool )
    GS_DECLARE_PROPERTY( StatePosition,      GEI32 )
    GS_DECLARE_PROPERTY( TaskPosition,       GEI32 )
public:
    void       ContinueRoutine( void );
    void       FullStop( void );
    Entity     GetActionTarget( void ) const;
    gEAniState GetAniState( void ) const;
    bCString   GetCurrentRoutineTask( void ) const;
    bCString   GetCurrentState( void ) const;
    bCString   GetCurrentTask( void ) const;
    gEAniState GetFallbackAniState( void ) const;
    bCString   GetLastTask( void ) const;
    bCString   GetLocalCallback( void ) const;
    GEFloat    GetStateTime( void ) const;
    bCString   GetTaskCallback( void ) const;
    GEFloat    GetTaskTime( void ) const;
    GEBool     IsValid( void ) const;
    void       SetActionTarget( Entity & );
    void       SetAniState( gEAniState, gEAniState );
    void       SetLocalCallback( bCString );
    void       SetState( bCString );
    void       SetStateTime( GEFloat );
    void       SetTask( bCString );
    void       SetTaskCallback( bCString );
    void       SetTaskTime( GEFloat );
    void       StartOutput( bCString, gEOutputType );
    void       StopAICombatMove( void );
    void       StopAIGoto( GEBool );
    void       StopAIOutput( void );
    void       StopAIPlayAnimation( void );
    void       StopAIWait( void );
    void       StopOutput( void );
};

//NOTE: The strings are not const, but they shouldn't be modified.
GE_DLLIMPORT_EXTC bCString const g_strAction_Aim;
GE_DLLIMPORT_EXTC bCString const g_strAction_Alchemy;
GE_DLLIMPORT_EXTC bCString const g_strAction_Altar;
GE_DLLIMPORT_EXTC bCString const g_strAction_Ambient;
GE_DLLIMPORT_EXTC bCString const g_strAction_Anvil;
GE_DLLIMPORT_EXTC bCString const g_strAction_Applaud;
GE_DLLIMPORT_EXTC bCString const g_strAction_ArmsCrossed;
GE_DLLIMPORT_EXTC bCString const g_strAction_Attack;
GE_DLLIMPORT_EXTC bCString const g_strAction_BabeAmbient;
GE_DLLIMPORT_EXTC bCString const g_strAction_BabeHandsOnHips;
GE_DLLIMPORT_EXTC bCString const g_strAction_Barbecue;
GE_DLLIMPORT_EXTC bCString const g_strAction_Berserker;
GE_DLLIMPORT_EXTC bCString const g_strAction_Bookstand;
GE_DLLIMPORT_EXTC bCString const g_strAction_BreakDoor;
GE_DLLIMPORT_EXTC bCString const g_strAction_ButtonPushIn;
GE_DLLIMPORT_EXTC bCString const g_strAction_Cauldron;
GE_DLLIMPORT_EXTC bCString const g_strAction_CheckFloor;
GE_DLLIMPORT_EXTC bCString const g_strAction_CheckWall;
GE_DLLIMPORT_EXTC bCString const g_strAction_CleanFloor;
GE_DLLIMPORT_EXTC bCString const g_strAction_ClimbHigh;
GE_DLLIMPORT_EXTC bCString const g_strAction_ClimbLow;
GE_DLLIMPORT_EXTC bCString const g_strAction_ClimbMid;
GE_DLLIMPORT_EXTC bCString const g_strAction_Cock;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeApple;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeBread;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeJar;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeJoint;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeMeat;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumePotion;
GE_DLLIMPORT_EXTC bCString const g_strAction_ConsumeStew;
GE_DLLIMPORT_EXTC bCString const g_strAction_CoolWeapon;
GE_DLLIMPORT_EXTC bCString const g_strAction_Dance;
GE_DLLIMPORT_EXTC bCString const g_strAction_Dead;
GE_DLLIMPORT_EXTC bCString const g_strAction_DeadBack;
GE_DLLIMPORT_EXTC bCString const g_strAction_Die;
GE_DLLIMPORT_EXTC bCString const g_strAction_DigGround;
GE_DLLIMPORT_EXTC bCString const g_strAction_DoorClose;
GE_DLLIMPORT_EXTC bCString const g_strAction_DoorOpen;
GE_DLLIMPORT_EXTC bCString const g_strAction_Down;
GE_DLLIMPORT_EXTC bCString const g_strAction_DownBack;
GE_DLLIMPORT_EXTC bCString const g_strAction_DrinkWater;
GE_DLLIMPORT_EXTC bCString const g_strAction_DrinkWaterBarrel;
GE_DLLIMPORT_EXTC bCString const g_strAction_Drop;
GE_DLLIMPORT_EXTC bCString const g_strAction_Eat;
GE_DLLIMPORT_EXTC bCString const g_strAction_Enjoy;
GE_DLLIMPORT_EXTC bCString const g_strAction_Fall;
GE_DLLIMPORT_EXTC bCString const g_strAction_Fan;
GE_DLLIMPORT_EXTC bCString const g_strAction_FieldWork;
GE_DLLIMPORT_EXTC bCString const g_strAction_Finished;
GE_DLLIMPORT_EXTC bCString const g_strAction_FlameSword;
GE_DLLIMPORT_EXTC bCString const g_strAction_FocusCast;
GE_DLLIMPORT_EXTC bCString const g_strAction_Forge;
GE_DLLIMPORT_EXTC bCString const g_strAction_Fry;
GE_DLLIMPORT_EXTC bCString const g_strAction_Goldsmith;
GE_DLLIMPORT_EXTC bCString const g_strAction_GrindStone;
GE_DLLIMPORT_EXTC bCString const g_strAction_Guard;
GE_DLLIMPORT_EXTC bCString const g_strAction_HandsOnHips;
GE_DLLIMPORT_EXTC bCString const g_strAction_Heal;
GE_DLLIMPORT_EXTC bCString const g_strAction_Hold;
GE_DLLIMPORT_EXTC bCString const g_strAction_HoldLeft;
GE_DLLIMPORT_EXTC bCString const g_strAction_HoldOrcBoulder;
GE_DLLIMPORT_EXTC bCString const g_strAction_HoldRight;
GE_DLLIMPORT_EXTC bCString const g_strAction_Jump;
GE_DLLIMPORT_EXTC bCString const g_strAction_JumpUpHigh;
GE_DLLIMPORT_EXTC bCString const g_strAction_JumpUpLow;
GE_DLLIMPORT_EXTC bCString const g_strAction_JumpUpMid;
GE_DLLIMPORT_EXTC bCString const g_strAction_Kneel;
GE_DLLIMPORT_EXTC bCString const g_strAction_Laugh;
GE_DLLIMPORT_EXTC bCString const g_strAction_LeverDraw;
GE_DLLIMPORT_EXTC bCString const g_strAction_LeverFlip;
GE_DLLIMPORT_EXTC bCString const g_strAction_Levitate;
GE_DLLIMPORT_EXTC bCString const g_strAction_LieKnockDown;
GE_DLLIMPORT_EXTC bCString const g_strAction_LiftOrcBoulder;
GE_DLLIMPORT_EXTC bCString const g_strAction_LizardBook;
GE_DLLIMPORT_EXTC bCString const g_strAction_Lockpick;
GE_DLLIMPORT_EXTC bCString const g_strAction_Lumberjack;
GE_DLLIMPORT_EXTC bCString const g_strAction_MagicOpen;
GE_DLLIMPORT_EXTC bCString const g_strAction_MagicOrb;
GE_DLLIMPORT_EXTC bCString const g_strAction_MediumHeal;
GE_DLLIMPORT_EXTC bCString const g_strAction_MinorHeal;
GE_DLLIMPORT_EXTC bCString const g_strAction_None;
GE_DLLIMPORT_EXTC bCString const g_strAction_OpenChest;
GE_DLLIMPORT_EXTC bCString const g_strAction_OpenCupboard;
GE_DLLIMPORT_EXTC bCString const g_strAction_OrcDrum;
GE_DLLIMPORT_EXTC bCString const g_strAction_Pee;
GE_DLLIMPORT_EXTC bCString const g_strAction_PickGround;
GE_DLLIMPORT_EXTC bCString const g_strAction_PickOre;
GE_DLLIMPORT_EXTC bCString const g_strAction_PirateTreasure;
GE_DLLIMPORT_EXTC bCString const g_strAction_PlayFlute;
GE_DLLIMPORT_EXTC bCString const g_strAction_PlayGuitar;
GE_DLLIMPORT_EXTC bCString const g_strAction_Plunder;
GE_DLLIMPORT_EXTC bCString const g_strAction_PracticeMagic;
GE_DLLIMPORT_EXTC bCString const g_strAction_PracticeStaff;
GE_DLLIMPORT_EXTC bCString const g_strAction_Protection;
GE_DLLIMPORT_EXTC bCString const g_strAction_RakeField;
GE_DLLIMPORT_EXTC bCString const g_strAction_Reach;
GE_DLLIMPORT_EXTC bCString const g_strAction_Reload;
GE_DLLIMPORT_EXTC bCString const g_strAction_Repair;
GE_DLLIMPORT_EXTC bCString const g_strAction_Roar;
GE_DLLIMPORT_EXTC bCString const g_strAction_SawLog;
GE_DLLIMPORT_EXTC bCString const g_strAction_Say;
GE_DLLIMPORT_EXTC bCString const g_strAction_SecretRingPull;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitBathtub;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitBench;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitGround;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitKnockDown;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitStool;
GE_DLLIMPORT_EXTC bCString const g_strAction_SitThrone;
GE_DLLIMPORT_EXTC bCString const g_strAction_SleepBed;
GE_DLLIMPORT_EXTC bCString const g_strAction_SleepGround;
GE_DLLIMPORT_EXTC bCString const g_strAction_Slide;
GE_DLLIMPORT_EXTC bCString const g_strAction_Stand;
GE_DLLIMPORT_EXTC bCString const g_strAction_Stoneplate;
GE_DLLIMPORT_EXTC bCString const g_strAction_Stove;
GE_DLLIMPORT_EXTC bCString const g_strAction_Summon;
GE_DLLIMPORT_EXTC bCString const g_strAction_SummonLight;
GE_DLLIMPORT_EXTC bCString const g_strAction_Summoned;
GE_DLLIMPORT_EXTC bCString const g_strAction_Take;
GE_DLLIMPORT_EXTC bCString const g_strAction_TakeHover;
GE_DLLIMPORT_EXTC bCString const g_strAction_Telekinesis;
GE_DLLIMPORT_EXTC bCString const g_strAction_TelekinesisPull;
GE_DLLIMPORT_EXTC bCString const g_strAction_TelekinesisPush;
GE_DLLIMPORT_EXTC bCString const g_strAction_Think;
GE_DLLIMPORT_EXTC bCString const g_strAction_TiltOrcBoulder;
GE_DLLIMPORT_EXTC bCString const g_strAction_Transfer;
GE_DLLIMPORT_EXTC bCString const g_strAction_TransformBeast;
GE_DLLIMPORT_EXTC bCString const g_strAction_TransformNautilus;
GE_DLLIMPORT_EXTC bCString const g_strAction_Use;
GE_DLLIMPORT_EXTC bCString const g_strAction_Warn;
GE_DLLIMPORT_EXTC bCString const g_strAction_Waterpipe;
GE_DLLIMPORT_EXTC bCString const g_strAction_WinchRelease;
GE_DLLIMPORT_EXTC bCString const g_strAction_WinchSpin;
GE_DLLIMPORT_EXTC bCString const g_strAction_WriteScroll;

//NOTE: The strings are not const, but they shouldn't be modified.
GE_DLLIMPORT_EXTC bCString const g_strPhase_Aim;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Ambient;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Angry;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Approve;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Beg;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Begin;
GE_DLLIMPORT_EXTC bCString const g_strPhase_BeginHard;
GE_DLLIMPORT_EXTC bCString const g_strPhase_End;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Fail;
GE_DLLIMPORT_EXTC bCString const g_strPhase_First;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Hit;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Jump;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Loop;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Nervous;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Point;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Preach;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Proud;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Raise;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Read;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Recover;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Run;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Sad;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Stand;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Third;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Thoughtful;
GE_DLLIMPORT_EXTC bCString const g_strPhase_Threaten;

#endif
