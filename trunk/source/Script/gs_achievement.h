#ifndef GS_ACHIEVEMENT_H_INCLUDED
#define GS_ACHIEVEMENT_H_INCLUDED

class GE_DLLIMPORT Achievement
{
public:
    void     EnableGameLog( GEBool );
    GEBool   GetProperty( GEInt, GEInt, GEI32 & ) const;
    GEBool   GetProperty( GEInt, GEInt, GEFloat & ) const;
    GEBool   GetProperty( GEInt, GEInt, GEDouble & ) const;
    GEBool   GetProperty( GEInt, GEInt, GEI64 & ) const;
    GEBool   IsGameLogEnable( void ) const;
    GEI32    ModifyProperty( GEInt, GEInt, GEI32 );
    GEFloat  ModifyProperty( GEInt, GEInt, GEFloat );
    GEDouble ModifyProperty( GEInt, GEInt, GEDouble );
    GEI64    ModifyProperty( GEInt, GEInt, GEI64 );
//  GEI32    ModifyPropertyEx( GEInt, GEInt, GEI32, GEI32, GEInt, XUSER_ACHIEVEMENT * );
//  GEFloat  ModifyPropertyEx( GEInt, GEInt, GEFloat, GEFloat, GEInt, XUSER_ACHIEVEMENT * );
//  GEDouble ModifyPropertyEx( GEInt, GEInt, GEDouble, GEDouble, GEInt, XUSER_ACHIEVEMENT * );
//  GEI64    ModifyPropertyEx( GEInt, GEInt, GEI64, GEI64, GEInt, XUSER_ACHIEVEMENT * );
    void     OnHandleDeadByFall( void );
    void     OnHandleDeadByTideworm( void );
    void     OnHandleDialogInfo( bCString const & );
    void     OnHandleForgeWeapon( void );
    void     OnHandleItemAmountChange( bCString const &, gEItemUseType, GEInt, GEInt );
    void     OnHandleJokeSpell( void );
    void     OnHandleLeverInteract( GEBool, bCString const & );
    void     OnHandleLockpick( void );
    void     OnHandleNPCKilled( Entity );
    void     OnHandlePickpocket( void );
    void     OnHandleQuestSuccess( bCString const & );
    void     OnHandleRaiseTreasure( void );
    void     OnHandleSkillBaseChange( gESkill, GEI32, GEI32 );
    void     SetProperty( GEInt, GEInt, GEI32 );
    void     SetProperty( GEInt, GEInt, GEFloat );
    void     SetProperty( GEInt, GEInt, GEDouble );
    void     SetProperty( GEInt, GEInt, GEI64 );
    GEBool   ShowAchievementsUI( GEInt );
//  GEBool   WriteAchievements( GEInt, XUSER_ACHIEVEMENT * );
public:
    Achievement & operator = ( Achievement const & );
public:
    Achievement( void );
   ~Achievement( void );
};

GE_DLLIMPORT_EXTC Achievement achievement;

#endif
