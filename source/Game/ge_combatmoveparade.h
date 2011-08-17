#ifndef GE_COMBATMOVEPARADE_H_INCLUDED
#define GE_COMBATMOVEPARADE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveParade'

class GE_DLLIMPORT gCCombatMoveParade :
    public gCCombatMove
{
protected:
    struct gSCombatMoveInstanceParade :
        public gSCombatMoveInstance
    {
        //FIXME: gCCombatMoveParade::gSCombatMoveInstanceParade members.
        char __FIXME[ 0x002C - sizeof(gSCombatMoveInstance) ];
    };
    GE_ASSERT_SIZEOF( gSCombatMoveInstanceParade, 0x002C )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveParade( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gCCombatMove *             GetMove( gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual eCGeometryEntity *         GetWeapon( gCCombatSystem_PS * ) const;
public:    virtual GEBool                     CanStartComboMove( gSCombatMoveInstance *, gECombatMove ) const;
public:    virtual GEBool                     StartCombo( gSCombatMoveInstance *, gECombatMove );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEBool                     IsInParade( gSCombatMoveInstance *, gECombatParadeType, bCVector const & );
public:    virtual GEBool                     IsInteruptable( gSCombatMoveInstance * ) const;
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual void                       OnAction( gSAction const &, gSCombatMoveInstance * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                                m_strBlendInAnimationFile;
    GEFloat                                 m_fBlendAniDuration;
    GEFloat                                 m_fBlendInTime;
    GEFloat                                 m_fBlendOutTime;
    GEFloat                                 m_fHoldDuration;
    GEFloat                                 m_fParadeAngle;
    eCScriptProxyScript                     m_PlayerHoldScript;
    bTPropertyContainer< gECombatMoveSide > m_enumWeaponSide;
    bCVector                                m_vecEffectOffset;
    GEBool                                  m_bOverlayBlend;
                                            GE_PADDING( 3 )
protected:
    void   Invalidate( void );
    GEBool IsInParadeAngle( bCVector const &, bCVector const & ) const;
    void   StartAni( gSCombatMoveInstanceParade * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                                       AccessBlendAniDuration( void );
    bCString &                                      AccessBlendInAnimationFile( void );
    GEFloat &                                       AccessBlendInTime( void );
    GEFloat &                                       AccessBlendOutTime( void );
    bCVector &                                      AccessEffectOffset( void );
    GEFloat &                                       AccessHoldDuration( void );
    GEBool &                                        AccessOverlayBlend( void );
    GEFloat &                                       AccessParadeAngle( void );
    eCScriptProxyScript &                           AccessPlayerHoldScript( void );
    bTPropertyContainer< gECombatMoveSide > &       AccessWeaponSide( void );
    GEFloat const &                                 GetBlendAniDuration( void ) const;
    bCString const &                                GetBlendInAnimationFile( void ) const;
    GEFloat const &                                 GetBlendInTime( void ) const;
    GEFloat const &                                 GetBlendOutTime( void ) const;
    bCVector const &                                GetEffectOffset( void ) const;
    GEFloat const &                                 GetHoldDuration( void ) const;
    GEBool const &                                  GetOverlayBlend( void ) const;
    GEFloat const &                                 GetParadeAngle( void ) const;
    eCScriptProxyScript const &                     GetPlayerHoldScript( void ) const;
    bCString const &                                GetWeaponMaterial( gCCombatSystem_PS * ) const;
    bTPropertyContainer< gECombatMoveSide > const & GetWeaponSide( void ) const;
    void                                            SetBlendAniDuration( GEFloat const & );
    void                                            SetBlendInAnimationFile( bCString const & );
    void                                            SetBlendInTime( GEFloat const & );
    void                                            SetBlendOutTime( GEFloat const & );
    void                                            SetEffectOffset( bCVector const & );
    void                                            SetHoldDuration( GEFloat const & );
    void                                            SetOverlayBlend( GEBool const & );
    void                                            SetParadeAngle( GEFloat const & );
    void                                            SetPlayerHoldScript( eCScriptProxyScript const & );
    void                                            SetWeaponSide( bTPropertyContainer< gECombatMoveSide > const & );
    void                                            StartParadeEffect( gCCombatSystem_PS *, bCString const &, GEFloat );
public:
    gCCombatMoveParade & operator = ( gCCombatMoveParade const & );
public:
    gCCombatMoveParade( gCCombatMoveParade const & );
    gCCombatMoveParade( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveParade, 0x004C )

#pragma warning( pop )

#endif
