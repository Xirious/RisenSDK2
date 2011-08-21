#ifndef GS_PSROUTINE_H_INCLUDED
#define GS_PSROUTINE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSRoutine )
public:
    using Entity::Property;
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
protected:
                         operator gCScriptRoutine_PS *       ( void );
                         operator gCScriptRoutine_PS const * ( void ) const;
    gCScriptRoutine_PS * operator ->                         ( void );
public:
    gCScriptRoutine_PS const * operator -> ( void ) const;
//FIXME: PSRoutine assignment operator shouldn’t be used (only one byte is copied).
//public: PSRoutine & operator = ( PSRoutine const & );
};

//NOTE: The strings are not const, but they shouldn’t be modified.
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Aim;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Alchemy;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Altar;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Ambient;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Anvil;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Applaud;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ArmsCrossed;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Attack;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_BabeAmbient;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_BabeHandsOnHips;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Barbecue;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Berserker;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Bookstand;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_BreakDoor;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ButtonPushIn;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Cauldron;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_CheckFloor;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_CheckWall;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_CleanFloor;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ClimbHigh;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ClimbLow;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ClimbMid;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Cock;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeApple;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeBread;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeJar;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeJoint;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeMeat;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumePotion;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_ConsumeStew;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_CoolWeapon;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Dance;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Dead;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DeadBack;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Die;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DigGround;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DoorClose;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DoorOpen;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Down;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DownBack;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DrinkWater;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_DrinkWaterBarrel;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Drop;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Eat;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Enjoy;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Fall;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Fan;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_FieldWork;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Finished;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_FlameSword;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_FocusCast;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Forge;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Fry;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Goldsmith;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_GrindStone;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Guard;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_HandsOnHips;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Heal;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Hold;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_HoldLeft;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_HoldOrcBoulder;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_HoldRight;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Jump;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_JumpUpHigh;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_JumpUpLow;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_JumpUpMid;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Kneel;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Laugh;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_LeverDraw;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_LeverFlip;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Levitate;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_LieKnockDown;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_LiftOrcBoulder;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_LizardBook;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Lockpick;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Lumberjack;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_MagicOpen;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_MagicOrb;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_MediumHeal;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_MinorHeal;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_None;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_OpenChest;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_OpenCupboard;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_OrcDrum;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Pee;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PickGround;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PickOre;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PirateTreasure;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PlayFlute;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PlayGuitar;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Plunder;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PracticeMagic;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_PracticeStaff;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Protection;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_RakeField;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Reach;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Reload;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Repair;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Roar;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SawLog;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Say;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SecretRingPull;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitBathtub;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitBench;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitGround;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitKnockDown;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitStool;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SitThrone;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SleepBed;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SleepGround;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Slide;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Stand;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Stoneplate;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Stove;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Summon;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_SummonLight;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Summoned;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Take;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TakeHover;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Telekinesis;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TelekinesisPull;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TelekinesisPush;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Think;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TiltOrcBoulder;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Transfer;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TransformBeast;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_TransformNautilus;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Use;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Warn;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_Waterpipe;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_WinchRelease;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_WinchSpin;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strAction_WriteScroll;

//NOTE: The strings are not const, but they shouldn’t be modified.
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Aim;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Ambient;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Angry;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Approve;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Beg;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Begin;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_BeginHard;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_End;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Fail;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_First;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Hit;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Jump;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Loop;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Nervous;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Point;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Preach;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Proud;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Raise;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Read;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Recover;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Run;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Sad;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Stand;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Third;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Thoughtful;
GE_C_LINKAGE GE_DLLIMPORT bCString const g_strPhase_Threaten;

#endif
