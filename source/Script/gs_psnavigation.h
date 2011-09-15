#ifndef GS_PSNAVIGATION_H_INCLUDED
#define GS_PSNAVIGATION_H_INCLUDED

//
// ERoutineTime is returned by Script_Game!GetRoutineTime
//
//  gESpecies_Human
//  gESpecies_Wolf_Tame
//      00:00 Sleeping
//      06:00 Working
//      20:00 Relaxing
//  gESpecies_Boar
//  gESpecies_Chicken
//  gESpecies_Cow
//  gESpecies_Pig
//  gESpecies_Stingrat
//  gESpecies_Thundertail
//  gESpecies_Vulture
//  gESpecies_Wolf
//      00:00 Sleeping
//      05:00 Working
//      23:00 Sleeping
//  default
//      00:00 Working
//
enum ERoutineTime
{
    ERoutineTime_Sleeping,
    ERoutineTime_Working,
    ERoutineTime_Relaxing,
    ERoutineTime_ForceDWORD = GE_FORCE_DWORD
};

GS_DECLARE_PROPERTYSET( PSNavigation, gCNavigation_PS )
public:
    GS_DECLARE_PROPERTY( CurrentAniDirection,      gEDirection )
    GS_DECLARE_PROPERTY( GuideWalkMode,            gEWalkMode )
    GS_DECLARE_PROPERTY( IsOnDestination,          GEBool )
    GS_DECLARE_PROPERTY( IsOnDestinationTimeStamp, GEU32 )
    GS_DECLARE_PROPERTY( StartPosition,            bCVector )
public:
    Entity                      GetAIGotoDestination( void ) const;
    gEDirection                 GetAniDirection( void ) const;
    Entity                      GetCurrentDestinationPoint( void ) const;
    bCVector                    GetCurrentNavigationTarget( void ) const;
    Entity                      GetCurrentZone( void ) const;
    GEBool                      GetDCCEnabled( void ) const;
    GEFloat                     GetDCCRadius( void ) const;
    gEGotoStatus                GetGotoStatus( void ) const;
    bCVector                    GetLastNavigationPosition( void ) const;
    Entity                      GetLastWaterContact( void ) const;
    Entity                      GetLastZone( void ) const;
    eCScriptProxyScript const & GetOnEnterWaterScript( void ) const;
    eCScriptProxyScript const & GetOnLeaveWaterScript( void ) const;
    eCScriptProxyScript const & GetOnWaterScript( void ) const;
    Entity                      GetRelaxingPoint( void ) const;
    Entity                      GetRoutinePoint( ERoutineTime ) const;
    Entity                      GetSleepingPoint( void ) const;
    GEFloat                     GetUnderWaterDepth( void ) const;
    Entity                      GetWorkingPoint( void ) const;
    GEBool                      HasAnyDestination( void ) const;
    GEBool                      IsInProcessingRange( void ) const;
    GEBool                      IsTravelling( void ) const;
    GEBool                      IsValid( void ) const;
    void                        Reset( void ) const;
    void                        ResetAll( void ) const;
    GEBool                      SetCurrentDestinationPoint( Entity & );
    void                        SetDCCEnabled( GEBool );
    void                        SetDCCRadius( GEFloat );
    void                        SetOnEnterWaterScript( eCScriptProxyScript const & );
    void                        SetOnLeaveWaterScript( eCScriptProxyScript const & );
    void                        SetOnWaterScript( eCScriptProxyScript const & );
    GEBool                      SetRelaxingPoint( Entity & );
    GEBool                      SetRoutine( bCString const & );
    GEBool                      SetSleepingPoint( Entity & );
    GEBool                      SetWorkingPoint( Entity & );
    GEBool                      StartGoto( Entity &, Entity &, gEWalkMode );
    GEBool                      StartGoto( Entity &, bCVector const &, gEWalkMode );
    GEBool                      UpdateGotoMovementMode( gEWalkMode );
};

#endif
