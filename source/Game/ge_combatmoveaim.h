#ifndef GE_COMBATMOVEAIM_H_INCLUDED
#define GE_COMBATMOVEAIM_H_INCLUDED

struct gSCombatMoveInstanceAimData
{
    void *  m_pInstance;
    void *  m_pEntity;
    void *  m_pInventory;
    void *  m_pAnimation;
    void *  m_pActor;
    void *  m_pItem;
    void *  m_pItemAnimation;
    void *  m_pItemActor;
    GEFloat m_fValue;
    GEFloat m_fScale;
};
GE_ASSERT_SIZEOF( gSCombatMoveInstanceAimData, 0x0028 )

class GE_DLLIMPORT gCCombatMoveAim :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveAim( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gCCombatMove *             GetMove( gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual GEBool                     CanStartComboMove( gSCombatMoveInstance *, gECombatMove ) const;
public:    virtual GEBool                     StartCombo( gSCombatMoveInstance *, gECombatMove );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual gSComboData *              CreateComboData( gSCombatMoveInstance * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString            m_strRelaxedAnimationFile;
    bCString            m_strStretchedAnimationFile;
    bCString            m_strBowAnimationFile;
    bCRange1            m_ElevationAngle; 
    bCRange1            m_StretchDuration;
    bCRange1            m_RaiseDuration;
    bCRange1            m_LowerDuration;
    eCScriptProxyScript m_OnCalcAimAngle;
    eCScriptProxyScript m_OnCalcAimStretch;
    bCString            m_strComboAttack;
    bCRange1            m_ComboAttackBeginTime;
    bCString            m_strArcherEffect;
    bCString            m_strBowEffect;
    eCScriptProxyScript m_OnGetSpeedFactor;
private:
    GEFloat CalcShootPower( gSCombatMoveInstance * );
    GEFloat GetSpeedFactor( gCCombatSystem_PS * );
    GEFloat GetSpeedScaledValue( gCCombatSystem_PS *, bCRange1 const & );
    void    StartArcher( gSCombatMoveInstanceAimData & );
    void    StartBow( gSCombatMoveInstanceAimData & );
    void    StopArcher( gSCombatMoveInstanceAimData & );
    void    StopBow( gSCombatMoveInstanceAimData & );
    void    UpdateAI( gSCombatMoveInstanceAimData & );
    void    UpdateArcher( gSCombatMoveInstanceAimData & );
    void    UpdateBow( gSCombatMoveInstanceAimData & );
    void    UpdateCommon( gSCombatMoveInstanceAimData & );
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                  AccessArcherEffect( void );
    bCString &                  AccessBowAnimationFile( void );
    bCString &                  AccessBowEffect( void );
    bCString &                  AccessComboAttack( void );
    bCRange1 &                  AccessComboAttackBeginTime( void );
    bCRange1 &                  AccessElevationAngle( void );
    bCRange1 &                  AccessLowerDuration( void );
    eCScriptProxyScript &       AccessOnCalcAimAngle( void );
    eCScriptProxyScript &       AccessOnCalcAimStretch( void );
    eCScriptProxyScript &       AccessOnGetSpeedFactor( void );
    bCRange1 &                  AccessRaiseDuration( void );
    bCString &                  AccessRelaxedAnimationFile( void );
    bCRange1 &                  AccessStretchDuration( void );
    bCString &                  AccessStretchedAnimationFile( void );
    bCString const &            GetArcherEffect( void ) const;
    bCString const &            GetBowAnimationFile( void ) const;
    bCString const &            GetBowEffect( void ) const;
    bCString const &            GetComboAttack( void ) const;
    bCRange1 const &            GetComboAttackBeginTime( void ) const;
    bCRange1 const &            GetElevationAngle( void ) const;
    bCRange1 const &            GetLowerDuration( void ) const;
    eCScriptProxyScript const & GetOnCalcAimAngle( void ) const;
    eCScriptProxyScript const & GetOnCalcAimStretch( void ) const;
    eCScriptProxyScript const & GetOnGetSpeedFactor( void ) const;
    bCRange1 const &            GetRaiseDuration( void ) const;
    bCString const &            GetRelaxedAnimationFile( void ) const;
    bCRange1 const &            GetStretchDuration( void ) const;
    bCString const &            GetStretchedAnimationFile( void ) const;
    void                        SetArcherEffect( bCString const & );
    void                        SetBowAnimationFile( bCString const & );
    void                        SetBowEffect( bCString const & );
    void                        SetComboAttack( bCString const & );
    void                        SetComboAttackBeginTime( bCRange1 const & );
    void                        SetElevationAngle( bCRange1 const & );
    void                        SetLowerDuration( bCRange1 const & );
    void                        SetOnCalcAimAngle( eCScriptProxyScript const & );
    void                        SetOnCalcAimStretch( eCScriptProxyScript const & );
    void                        SetOnGetSpeedFactor( eCScriptProxyScript const & );
    void                        SetRaiseDuration( bCRange1 const & );
    void                        SetRelaxedAnimationFile( bCString const & );
    void                        SetStretchDuration( bCRange1 const & );
    void                        SetStretchedAnimationFile( bCString const & );
public:
    gCCombatMoveAim & operator = ( gCCombatMoveAim const & );
public:
    gCCombatMoveAim( gCCombatMoveAim const & );
    gCCombatMoveAim( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveAim, 0x006C )

#endif
