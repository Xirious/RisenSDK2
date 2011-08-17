#ifndef GE_COMBATMOVEMELEE_H_INCLUDED
#define GE_COMBATMOVEMELEE_H_INCLUDED

enum gEAlignToTarget
{
    gEAlignToTarget_None       = 0x00000000,
    gEAlignToTarget_TargetDir  = 0x00000001,
    gEAlignToTarget_Target     = 0x00000002,
    gEAlignToTarget_Free       = 0x00000003,
    gEAlignToTarget_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatAttackStumble
{
    gECombatAttackStumble_None       = 0x00000000,
    gECombatAttackStumble_ParadeType = 0x00000001,
    gECombatAttackStumble_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatComboParade
{
    gECombatComboParade_None       = 0x00000000,
    gECombatComboParade_Parade     = 0x00000001,
    gECombatComboParade_Parade1    = 0x00000002,
    gECombatComboParade_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatHitDirection
{
    gECombatHitDirection_Fore       = 0x00000000,
    gECombatHitDirection_Left       = 0x00000001,
    gECombatHitDirection_Right      = 0x00000002,
    gECombatHitDirection_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatPhaseType
{
    gECombatPhaseType_None          = 0x00000000,
    gECombatPhaseType_Raise         = 0x00000001,
    gECombatPhaseType_PowerRaise    = 0x00000002,
    gECombatPhaseType_Hit           = 0x00000003,
    gECombatPhaseType_Hoover        = 0x00000004,
    gECombatPhaseType_Recover       = 0x00000005,
    gECombatPhaseType_Parade        = 0x00000006,
    gECombatPhaseType_Strafe        = 0x00000007,
    gECombatPhaseType_CounterParade = 0x00000008,
    gECombatPhaseType_CounterAttack = 0x00000009,
    gECombatPhaseType_ForceDWORD    = GE_FORCE_DWORD
};

class gCCombatMoveMeleePhase :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCCombatMoveMeleePhase( void );
protected:
    bTPropertyContainer< gECombatPhaseType > m_enumPhaseType;
    GEFloat                                  m_fPhaseBegin;
    bCString                                 m_strPhaseEffect;
    GEFloat                                  m_fHitPoint;
    GEFloat                                  m_fMinAngle;
    GEFloat                                  m_fMaxAngle;
//NOTE: gCCombatMoveMeleePhase is not exported. Use the property system to create and access the object.
private:
    gCCombatMoveMeleePhase & operator = ( gCCombatMoveMeleePhase const & );  // not defined
    gCCombatMoveMeleePhase( gCCombatMoveMeleePhase const & );                // not defined
    gCCombatMoveMeleePhase( void );                                          // not defined
};
GE_ASSERT_SIZEOF( gCCombatMoveMeleePhase, 0x0020 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveMelee'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveMelee'

class GE_DLLIMPORT gCCombatMoveMelee :
    public gCCombatMove
{
public:
    enum gEHitTargetResult
    {
        //FIXME: gCCombatMoveMelee::gEHitTargetResult constants.
        gEHitTargetResult_ForceDWORD = GE_FORCE_DWORD
    };
    struct gSCombatMoveInstanceMelee :
        public gSCombatMoveInstance
    {
        //FIXME: gCCombatMoveMelee::gSCombatMoveInstanceMelee members.
        char __FIXME[ 0x0098 - sizeof(gSCombatMoveInstance) ];
    };
    GE_ASSERT_SIZEOF( gSCombatMoveInstanceMelee, 0x0098 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveMelee( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gECombatParadeType         GetParadeType( gCCombatStyle * ) const;
public:    virtual gECombatParadeType         GetAttackType( gCCombatStyle * ) const;
public:    virtual gCCombatMove *             GetMove( gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual eCGeometryEntity *         GetWeapon( gCCombatSystem_PS * ) const;
public:    virtual GEBool                     CanStartComboMove( gSCombatMoveInstance *, gECombatMove ) const;
public:    virtual GEBool                     StartStumble( gSCombatMoveInstance *, gCCombatSystem_PS * );
public:    virtual GEBool                     StartCombo( gSCombatMoveInstance *, gECombatMove );
public:    virtual void                       StopCombo( gSCombatMoveInstance * );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Interupt( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEBool                     IsInParade( gSCombatMoveInstance *, gECombatParadeType, bCVector const & );
public:    virtual GEBool                     IsInAttack( gCCombatSystem_PS *, eCGeometryEntity *, GEFloat & );
public:    virtual GEBool                     IsInteruptable( gSCombatMoveInstance * ) const;
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual gSComboData *              CreateComboData( gSCombatMoveInstance * );
public:    virtual GEBool                     CanCounterMove( gCCombatSystem_PS *, gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual GEBool                     CanBufferNextMove( gSCombatMoveInstance *, gECombatMove ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gECombatAction >        m_enumAction;
    GEBool                                       m_bOverwriteAttackType;
                                                 GE_PADDING( 3 )
    bTPropertyContainer< gECombatParadeType >    m_enumAttackType;
    bCString                                     m_strAnimationFile;
    bCString                                     m_strFollowAnimationFileP0;
    bCString                                     m_strFollowAnimationFileP1;
    bCString                                     m_strFollowAnimationFileP2;
    bTPropertyContainer< gECombatHitDirection >  m_enumHitDirection;
    GEFloat                                      m_fMovementDistance;
    GEFloat                                      m_fMovementBegin;
    GEFloat                                      m_fMovementEnd;
    bCString                                     m_strFollowMoveP0;
    bCString                                     m_strFollowMoveP1;
    bCString                                     m_strFollowMoveP2;
    bCString                                     m_strCombo;
    bCString                                     m_strComboSec;
    bCString                                     m_strComboPower;
    bCString                                     m_strComboLeft;
    bCString                                     m_strComboRight;
    bTPropertyContainer< gECombatComboParade >   m_enumComboParade;
    GEFloat                                      m_fComboBegin;
    GEFloat                                      m_fComboEnd;
    bTObjArray< gCCombatMoveMeleePhase >         m_arrPhases;
    bTPropertyContainer< gECombatMoveSide >      m_enumWeaponSide;
    GEFloat                                      m_fForce;
    GEFloat                                      m_fMoveDuration;
    GEFloat                                      m_fBlendInTime;
    bTPropertyContainer< gEAlignToTarget >       m_enumAlignToTarget;
    GEFloat                                      m_fHitDistanceOffset;
    bTPropertyContainer< gECombatMove >          m_enumStumbleReaction;
    bTPropertyContainer< gECombatMove >          m_enumParadeReaction;
    GEFloat                                      m_fHitEffectOffset;
    GEBool                                       m_bIsInteruptable;
                                                 GE_PADDING1( 3 )
    GEFloat                                      m_fInteruptableBegin;
    GEFloat                                      m_fMovementDirection;
    GEFloat                                      m_fHitSlomoDuration;
    GEFloat                                      m_fSlomoBegin;
    GEFloat                                      m_fSlomoEnd;
    GEFloat                                      m_fSlomoTimeScale;
    bCString                                     m_strSpecialEffect;
    GEFloat                                      m_fSpecialEffectBegin;
    bTPropertyContainer< gECombatAttackStumble > m_enumAttackStumbleType;
    bCVector2                                    m_vecPlayerRotationLimit;
    GEFloat                                      m_fPhaseDurationHit;
    GEFloat                                      m_fPhaseDurationRaise;
    GEFloat                                      m_fPhaseDurationPowerRaise;
    GEFloat                                      m_fPhaseDurationHoover;
    GEFloat                                      m_fPhaseDurationRecover;
    GEFloat                                      m_fPhaseDurationParade;
    GEFloat                                      m_fPhaseDurationStrafe;
    GEFloat                                      m_fPhaseDurationCounterAttack;
    GEFloat                                      m_fPhaseDurationCounterParade;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gECombatAction > &              AccessAction( void );
    bTPropertyContainer< gEAlignToTarget > &             AccessAlignToTarget( void );
    bCString &                                           AccessAnimationFile( void );
    bTPropertyContainer< gECombatAttackStumble > &       AccessAttackStumbleType( void );
    bTPropertyContainer< gECombatParadeType > &          AccessAttackType( void );
    GEFloat &                                            AccessBlendInTime( void );
    bCString &                                           AccessCombo( void );
    GEFloat &                                            AccessComboBegin( void );
    GEFloat &                                            AccessComboEnd( void );
    bCString &                                           AccessComboLeft( void );
    bTPropertyContainer< gECombatComboParade > &         AccessComboParade( void );
    bCString &                                           AccessComboPower( void );
    bCString &                                           AccessComboRight( void );
    bCString &                                           AccessComboSec( void );
    bCString &                                           AccessFollowAnimationFileP0( void );
    bCString &                                           AccessFollowAnimationFileP1( void );
    bCString &                                           AccessFollowAnimationFileP2( void );
    bCString &                                           AccessFollowMoveP0( void );
    bCString &                                           AccessFollowMoveP1( void );
    bCString &                                           AccessFollowMoveP2( void );
    GEFloat &                                            AccessForce( void );
    bTPropertyContainer< gECombatHitDirection > &        AccessHitDirection( void );
    GEFloat &                                            AccessHitDistanceOffset( void );
    GEFloat &                                            AccessHitEffectOffset( void );
    GEFloat &                                            AccessHitSlomoDuration( void );
    GEFloat &                                            AccessInteruptableBegin( void );
    GEBool &                                             AccessIsInteruptable( void );
    GEFloat &                                            AccessMoveDuration( void );
    GEFloat &                                            AccessMovementBegin( void );
    GEFloat &                                            AccessMovementDirection( void );
    GEFloat &                                            AccessMovementDistance( void );
    GEFloat &                                            AccessMovementEnd( void );
    GEBool &                                             AccessOverwriteAttackType( void );
    bTPropertyContainer< gECombatMove > &                AccessParadeReaction( void );
    GEFloat &                                            AccessPhaseDurationCounterAttack( void );
    GEFloat &                                            AccessPhaseDurationCounterParade( void );
    GEFloat &                                            AccessPhaseDurationHit( void );
    GEFloat &                                            AccessPhaseDurationHoover( void );
    GEFloat &                                            AccessPhaseDurationParade( void );
    GEFloat &                                            AccessPhaseDurationPowerRaise( void );
    GEFloat &                                            AccessPhaseDurationRaise( void );
    GEFloat &                                            AccessPhaseDurationRecover( void );
    GEFloat &                                            AccessPhaseDurationStrafe( void );
    bTObjArray< gCCombatMoveMeleePhase > &               AccessPhases( void );
    bCVector2 &                                          AccessPlayerRotationLimit( void );
    GEFloat &                                            AccessSlomoBegin( void );
    GEFloat &                                            AccessSlomoEnd( void );
    GEFloat &                                            AccessSlomoTimeScale( void );
    bCString &                                           AccessSpecialEffect( void );
    GEFloat &                                            AccessSpecialEffectBegin( void );
    bTPropertyContainer< gECombatMove > &                AccessStumbleReaction( void );
    bTPropertyContainer< gECombatMoveSide > &            AccessWeaponSide( void );
    bCVector                                             CalcMoveDir( gCCombatSystem_PS * ) const;
    GEBool                                               CanAlignTarget( gCCombatSystem_PS *, eCGeometryEntity * ) const;
    GEBool                                               CounterTargets( gSCombatMoveInstanceMelee * );
    bTPropertyContainer< gECombatAction > const &        GetAction( void ) const;
    bTPropertyContainer< gEAlignToTarget > const &       GetAlignToTarget( void ) const;
    GEFloat                                              GetAniByMoveTime( GEFloat ) const;
    bCString const &                                     GetAnimationFile( void ) const;
    bTPropertyContainer< gECombatAttackStumble > const & GetAttackStumbleType( void ) const;
    bTPropertyContainer< gECombatParadeType > const &    GetAttackType( void ) const;
    GEFloat const &                                      GetBlendInTime( void ) const;
    bCString const &                                     GetCombo( void ) const;
    GEFloat const &                                      GetComboBegin( void ) const;
    GEFloat const &                                      GetComboEnd( void ) const;
    bCString const &                                     GetComboLeft( void ) const;
    bTPropertyContainer< gECombatComboParade > const &   GetComboParade( void ) const;
    bCString const &                                     GetComboPower( void ) const;
    bCString const &                                     GetComboRight( void ) const;
    bCString const &                                     GetComboSec( void ) const;
    GEFloat                                              GetFAIAttackWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc & );
    GEFloat                                              GetFAIParadeWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc & );
    bCString const &                                     GetFollowAnimationFileP0( void ) const;
    bCString const &                                     GetFollowAnimationFileP1( void ) const;
    bCString const &                                     GetFollowAnimationFileP2( void ) const;
    bCString const &                                     GetFollowMoveP0( void ) const;
    bCString const &                                     GetFollowMoveP1( void ) const;
    bCString const &                                     GetFollowMoveP2( void ) const;
    GEFloat const &                                      GetForce( void ) const;
    bTPropertyContainer< gECombatHitDirection > const &  GetHitDirection( void ) const;
    GEFloat const &                                      GetHitDistanceOffset( void ) const;
    GEFloat const &                                      GetHitEffectOffset( void ) const;
    GEFloat                                              GetHitRange( gCCombatSystem_PS *, gCCombatStyle * );
    GEFloat const &                                      GetHitSlomoDuration( void ) const;
    GEFloat const &                                      GetInteruptableBegin( void ) const;
    GEBool const &                                       GetIsInteruptable( void ) const;
    GEFloat                                              GetMaxHitRange( gCCombatStyle * );
    GEFloat                                              GetMoveByAniTime( GEFloat ) const;
    GEFloat const &                                      GetMoveDuration( void ) const;
    GEFloat const &                                      GetMovementBegin( void ) const;
    GEFloat const &                                      GetMovementDirection( void ) const;
    GEFloat                                              GetMovementDistance( GEFloat, GEFloat );
    GEFloat const &                                      GetMovementDistance( void ) const;
    GEFloat const &                                      GetMovementEnd( void ) const;
    GEInt                                                GetNextHitPointPhase( GEFloat &, GEFloat ) const;
    GEInt                                                GetNextPhase( gECombatPhaseType, GEFloat &, GEFloat &, GEFloat ) const;
    GEBool const &                                       GetOverwriteAttackType( void ) const;
    bTPropertyContainer< gECombatMove > const &          GetParadeReaction( void ) const;
    GEFloat                                              GetPhaseAniDuration( GEInt ) const;
    GEFloat                                              GetPhaseDuration( GEInt ) const;
    GEFloat                                              GetPhaseDurationByType( gECombatPhaseType ) const;
    GEFloat const &                                      GetPhaseDurationCounterAttack( void ) const;
    GEFloat const &                                      GetPhaseDurationCounterParade( void ) const;
    GEFloat const &                                      GetPhaseDurationHit( void ) const;
    GEFloat const &                                      GetPhaseDurationHoover( void ) const;
    GEFloat const &                                      GetPhaseDurationParade( void ) const;
    GEFloat const &                                      GetPhaseDurationPowerRaise( void ) const;
    GEFloat const &                                      GetPhaseDurationRaise( void ) const;
    GEFloat const &                                      GetPhaseDurationRecover( void ) const;
    GEFloat const &                                      GetPhaseDurationStrafe( void ) const;
    GEFloat                                              GetPhaseSpeed( GEInt ) const;
    bTObjArray< gCCombatMoveMeleePhase > const &         GetPhases( void ) const;
    bCVector2 const &                                    GetPlayerRotationLimit( void ) const;
    GEFloat const &                                      GetSlomoBegin( void ) const;
    GEFloat const &                                      GetSlomoEnd( void ) const;
    GEFloat const &                                      GetSlomoTimeScale( void ) const;
    bCString const &                                     GetSpecialEffect( void ) const;
    GEFloat const &                                      GetSpecialEffectBegin( void ) const;
    bTPropertyContainer< gECombatMove > const &          GetStumbleReaction( void ) const;
    bCString const &                                     GetWeaponMaterial( gCCombatSystem_PS * ) const;
    bTPropertyContainer< gECombatMoveSide > const &      GetWeaponSide( void ) const;
    GEBool                                               HitTargets( gSCombatMoveInstanceMelee * );
    GEBool                                               HitWater( gSCombatMoveInstanceMelee * );
    GEBool                                               InteruptPowerRaise( gSCombatMoveInstance * );
    gEHitTargetResult                                    IsHitTarget( gCCombatSystem_PS *, GEInt, eCGeometryEntity *, GEFloat, bCVector );
    gEHitTargetResult                                    IsHitTarget( gCCombatSystem_PS *, eCGeometryEntity *, GEFloat );
    void                                                 SetAction( bTPropertyContainer< gECombatAction > const & );
    void                                                 SetAlignToTarget( bTPropertyContainer< gEAlignToTarget > const & );
    void                                                 SetAnimationFile( bCString const & );
    void                                                 SetAttackStumbleType( bTPropertyContainer< gECombatAttackStumble > const & );
    void                                                 SetAttackType( bTPropertyContainer< gECombatParadeType > const & );
    void                                                 SetBlendInTime( GEFloat const & );
    void                                                 SetCombo( bCString const & );
    void                                                 SetComboBegin( GEFloat const & );
    void                                                 SetComboEnd( GEFloat const & );
    void                                                 SetComboLeft( bCString const & );
    void                                                 SetComboParade( bTPropertyContainer< gECombatComboParade > const & );
    void                                                 SetComboPower( bCString const & );
    void                                                 SetComboRight( bCString const & );
    void                                                 SetComboSec( bCString const & );
    void                                                 SetFollowAnimationFileP0( bCString const & );
    void                                                 SetFollowAnimationFileP1( bCString const & );
    void                                                 SetFollowAnimationFileP2( bCString const & );
    void                                                 SetFollowMoveP0( bCString const & );
    void                                                 SetFollowMoveP1( bCString const & );
    void                                                 SetFollowMoveP2( bCString const & );
    void                                                 SetForce( GEFloat const & );
    void                                                 SetHitDirection( bTPropertyContainer< gECombatHitDirection > const & );
    void                                                 SetHitDistanceOffset( GEFloat const & );
    void                                                 SetHitEffectOffset( GEFloat const & );
    void                                                 SetHitSlomoDuration( GEFloat const & );
    void                                                 SetInteruptableBegin( GEFloat const & );
    void                                                 SetIsInteruptable( GEBool const & );
    void                                                 SetMoveDuration( GEFloat const & );
    void                                                 SetMovementBegin( GEFloat const & );
    void                                                 SetMovementDirection( GEFloat const & );
    void                                                 SetMovementDistance( GEFloat const & );
    void                                                 SetMovementEnd( GEFloat const & );
    void                                                 SetOverwriteAttackType( GEBool const & );
    void                                                 SetParadeReaction( bTPropertyContainer< gECombatMove > const & );
    void                                                 SetPhaseDurationCounterAttack( GEFloat const & );
    void                                                 SetPhaseDurationCounterParade( GEFloat const & );
    void                                                 SetPhaseDurationHit( GEFloat const & );
    void                                                 SetPhaseDurationHoover( GEFloat const & );
    void                                                 SetPhaseDurationParade( GEFloat const & );
    void                                                 SetPhaseDurationPowerRaise( GEFloat const & );
    void                                                 SetPhaseDurationRaise( GEFloat const & );
    void                                                 SetPhaseDurationRecover( GEFloat const & );
    void                                                 SetPhaseDurationStrafe( GEFloat const & );
    void                                                 SetPhases( bTObjArray< gCCombatMoveMeleePhase > const & );
    void                                                 SetPlayerRotationLimit( bCVector2 const & );
    void                                                 SetSlomoBegin( GEFloat const & );
    void                                                 SetSlomoEnd( GEFloat const & );
    void                                                 SetSlomoTimeScale( GEFloat const & );
    void                                                 SetSpecialEffect( bCString const & );
    void                                                 SetSpecialEffectBegin( GEFloat const & );
    void                                                 SetStumbleReaction( bTPropertyContainer< gECombatMove > const & );
    void                                                 SetWeaponSide( bTPropertyContainer< gECombatMoveSide > const & );
    GEBool                                               StartAttackStumble( gCCombatSystem_PS *, gECombatHitDirection );
    void                                                 StartHitEffect( gCCombatSystem_PS *, gCCombatSystem_PS *, bCString const &, bCMatrix *, GEFloat, GEBool );
    void                                                 StartParadeStumble( gSCombatMoveInstanceMelee *, gCCombatSystem_PS * );
public:
    gCCombatMoveMelee & operator = ( gCCombatMoveMelee const & );
public:
    gCCombatMoveMelee( gCCombatMoveMelee const & );
    gCCombatMoveMelee( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveMelee, 0x0114 )

#pragma warning( pop )

#endif
