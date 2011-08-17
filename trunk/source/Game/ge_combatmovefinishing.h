#ifndef GE_COMBATMOVEFINISHING_H_INCLUDED
#define GE_COMBATMOVEFINISHING_H_INCLUDED

class GE_DLLIMPORT gCCombatMoveFinishing :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveFinishing( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString            m_strAnimationFile;
    GEFloat             m_fHitPoint;
    eCScriptProxyScript m_HitScript;
    GEFloat             m_fMovementBegin;
    GEFloat             m_fMovementEnd;
    GEFloat             m_fDesiredDistanceToTarget;
    GEFloat             m_fMaxDistanceToTarget;
    GEFloat             m_fMoveDuration;
    GEFloat             m_fFinishingDuration;
    GEFloat             m_fBlendInTime;
    bCString            m_strFollowMoveP0;
    bCString            m_strFollowMoveP1;
    bCString            m_strFollowMoveP2;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                  AccessAnimationFile( void );
    GEFloat &                   AccessBlendInTime( void );
    GEFloat &                   AccessDesiredDistanceToTarget( void );
    GEFloat &                   AccessFinishingDuration( void );
    bCString &                  AccessFollowMoveP0( void );
    bCString &                  AccessFollowMoveP1( void );
    bCString &                  AccessFollowMoveP2( void );
    GEFloat &                   AccessHitPoint( void );
    eCScriptProxyScript &       AccessHitScript( void );
    GEFloat &                   AccessMaxDistanceToTarget( void );
    GEFloat &                   AccessMoveDuration( void );
    GEFloat &                   AccessMovementBegin( void );
    GEFloat &                   AccessMovementEnd( void );
    bCString const &            GetAnimationFile( void ) const;
    GEFloat const &             GetBlendInTime( void ) const;
    GEFloat const &             GetDesiredDistanceToTarget( void ) const;
    GEFloat const &             GetFinishingDuration( void ) const;
    bCString const &            GetFollowMoveP0( void ) const;
    bCString const &            GetFollowMoveP1( void ) const;
    bCString const &            GetFollowMoveP2( void ) const;
    GEFloat const &             GetHitPoint( void ) const;
    eCScriptProxyScript const & GetHitScript( void ) const;
    GEFloat const &             GetMaxDistanceToTarget( void ) const;
    GEFloat const &             GetMoveDuration( void ) const;
    GEFloat const &             GetMovementBegin( void ) const;
    GEFloat const &             GetMovementEnd( void ) const;
    void                        SetAnimationFile( bCString const & );
    void                        SetBlendInTime( GEFloat const & );
    void                        SetDesiredDistanceToTarget( GEFloat const & );
    void                        SetFinishingDuration( GEFloat const & );
    void                        SetFollowMoveP0( bCString const & );
    void                        SetFollowMoveP1( bCString const & );
    void                        SetFollowMoveP2( bCString const & );
    void                        SetHitPoint( GEFloat const & );
    void                        SetHitScript( eCScriptProxyScript const & );
    void                        SetMaxDistanceToTarget( GEFloat const & );
    void                        SetMoveDuration( GEFloat const & );
    void                        SetMovementBegin( GEFloat const & );
    void                        SetMovementEnd( GEFloat const & );
public:
    gCCombatMoveFinishing & operator = ( gCCombatMoveFinishing const & );
public:
    gCCombatMoveFinishing( gCCombatMoveFinishing const & );
    gCCombatMoveFinishing( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveFinishing, 0x004C )

#endif
