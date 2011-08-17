#ifndef GE_COMBATMOVESHOOT_H_INCLUDED
#define GE_COMBATMOVESHOOT_H_INCLUDED

class GE_DLLIMPORT gCCombatMoveShoot :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveShoot( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gCCombatMove *             GetMove( gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual GEBool                     CanStartComboMove( gSCombatMoveInstance *, gECombatMove ) const;
public:    virtual GEBool                     StartCombo( gSCombatMoveInstance *, gECombatMove );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString              m_strAnimationFileUp;
    bCString              m_strAnimationFileFwd;
    bCString              m_strAnimationFileDown;
    bCRange1              m_ElevationAngle;
    eCTemplateEntityProxy m_Projectile;
    eCScriptProxyScript   m_OnShoot;
    eCScriptProxyScript   m_OnCalcShootAngle;
    GEFloat               m_fShootPoint;
    GEFloat               m_fAniDuration;
    bCRange1              m_ShootDuration;
    GEFloat               m_fBlendInTime;
    bCString              m_strFollowMove;
    bCString              m_strFollowAnimationFile;
    bCString              m_strComboAttack;
    eCScriptProxyScript   m_OnGetFAIWeight;
    GEFloat               m_fShotPower;
    GEBool                m_bBlendAnimations;
    GEBool                m_bOverlayAnimations;
                          GE_PADDING( 2 )
    eCScriptProxyScript   m_OnStartAutoCombo;
    eCScriptProxyScript   m_OnGetSpeedFactor;
protected:
    GEFloat GetSpeedFactor( gCCombatSystem_PS * );
    GEFloat GetSpeedScaledValue( gCCombatSystem_PS *, bCRange1 const & );
    void    Invalidate( void );
    void    ResetAnimations( eCAnimation_PS * );
    GEBool  StartAnimations( eCAnimation_PS *, bCString, bCString, GEFloat, GEFloat );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                     AccessAniDuration( void );
    bCString &                    AccessAnimationFileDown( void );
    bCString &                    AccessAnimationFileFwd( void );
    bCString &                    AccessAnimationFileUp( void );
    GEBool &                      AccessBlendAnimations( void );
    GEFloat &                     AccessBlendInTime( void );
    bCString &                    AccessComboAttack( void );
    bCRange1 &                    AccessElevationAngle( void );
    bCString &                    AccessFollowAnimationFile( void );
    bCString &                    AccessFollowMove( void );
    eCScriptProxyScript &         AccessOnCalcShootAngle( void );
    eCScriptProxyScript &         AccessOnGetFAIWeight( void );
    eCScriptProxyScript &         AccessOnGetSpeedFactor( void );
    eCScriptProxyScript &         AccessOnShoot( void );
    eCScriptProxyScript &         AccessOnStartAutoCombo( void );
    GEBool &                      AccessOverlayAnimations( void );
    eCTemplateEntityProxy &       AccessProjectile( void );
    bCRange1 &                    AccessShootDuration( void );
    GEFloat &                     AccessShootPoint( void );
    GEFloat &                     AccessShotPower( void );
    GEFloat const &               GetAniDuration( void ) const;
    bCString const &              GetAnimationFileDown( void ) const;
    bCString const &              GetAnimationFileFwd( void ) const;
    bCString const &              GetAnimationFileUp( void ) const;
    GEBool const &                GetBlendAnimations( void ) const;
    GEFloat const &               GetBlendInTime( void ) const;
    bCString const &              GetComboAttack( void ) const;
    bCRange1 const &              GetElevationAngle( void ) const;
    bCString const &              GetFollowAnimationFile( void ) const;
    bCString const &              GetFollowMove( void ) const;
    eCScriptProxyScript const &   GetOnCalcShootAngle( void ) const;
    eCScriptProxyScript const &   GetOnGetFAIWeight( void ) const;
    eCScriptProxyScript const &   GetOnGetSpeedFactor( void ) const;
    eCScriptProxyScript const &   GetOnShoot( void ) const;
    eCScriptProxyScript const &   GetOnStartAutoCombo( void ) const;
    GEBool const &                GetOverlayAnimations( void ) const;
    eCTemplateEntityProxy const & GetProjectile( void ) const;
    bCRange1 const &              GetShootDuration( void ) const;
    GEFloat const &               GetShootPoint( void ) const;
    GEFloat const &               GetShotPower( void ) const;
    void                          SetAniDuration( GEFloat const & );
    void                          SetAnimationFileDown( bCString const & );
    void                          SetAnimationFileFwd( bCString const & );
    void                          SetAnimationFileUp( bCString const & );
    void                          SetBlendAnimations( GEBool const & );
    void                          SetBlendInTime( GEFloat const & );
    void                          SetComboAttack( bCString const & );
    void                          SetElevationAngle( bCRange1 const & );
    void                          SetFollowAnimationFile( bCString const & );
    void                          SetFollowMove( bCString const & );
    void                          SetOnCalcShootAngle( eCScriptProxyScript const & );
    void                          SetOnGetFAIWeight( eCScriptProxyScript const & );
    void                          SetOnGetSpeedFactor( eCScriptProxyScript const & );
    void                          SetOnShoot( eCScriptProxyScript const & );
    void                          SetOnStartAutoCombo( eCScriptProxyScript const & );
    void                          SetOverlayAnimations( GEBool const & );
    void                          SetProjectile( eCTemplateEntityProxy const & );
    void                          SetShootDuration( bCRange1 const & );
    void                          SetShootPoint( GEFloat const & );
    void                          SetShotPower( GEFloat const & );
public:
    gCCombatMoveShoot & operator = ( gCCombatMoveShoot const & );
public:
    gCCombatMoveShoot( gCCombatMoveShoot const & );
    gCCombatMoveShoot( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveShoot, 0x007C )

#endif
