#ifndef GE_COMBATMOVESTUMBLE_H_INCLUDED
#define GE_COMBATMOVESTUMBLE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatMoveStumble'

class GE_DLLIMPORT gCCombatMoveStumble :
    public gCCombatMove
{
public:
    struct gSCombatMoveInstanceStumble :
        public gSCombatMoveInstance
    {
        GEFloat  m_fPlayTime;
        bCVector m_vecRotation;
        bCVector m_vecMovement;
    };
    GE_ASSERT_SIZEOF( gSCombatMoveInstanceStumble, 0x002C );
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveStumble( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                          m_strAnimationFile;
    GEFloat                           m_fMovementDistance;
    GEFloat                           m_fMovementBegin;
    GEFloat                           m_fMovementEnd;
    bTPropertyContainer< gEAniState > m_enumResultingAniState;
    GEFloat                           m_fMoveDuration;
    GEFloat                           m_fStumbleDuration;
    GEFloat                           m_fBlendInTime;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                AccessAnimationFile( void );
    GEFloat &                                 AccessBlendInTime( void );
    GEFloat &                                 AccessMoveDuration( void );
    GEFloat &                                 AccessMovementBegin( void );
    GEFloat &                                 AccessMovementDistance( void );
    GEFloat &                                 AccessMovementEnd( void );
    bTPropertyContainer< gEAniState > &       AccessResultingAniState( void );
    GEFloat &                                 AccessStumbleDuration( void );
    bCString const &                          GetAnimationFile( void ) const;
    GEFloat const &                           GetBlendInTime( void ) const;
    GEFloat const &                           GetMoveDuration( void ) const;
    GEFloat const &                           GetMovementBegin( void ) const;
    GEFloat const &                           GetMovementDistance( void ) const;
    GEFloat const &                           GetMovementEnd( void ) const;
    bTPropertyContainer< gEAniState > const & GetResultingAniState( void ) const;
    GEFloat const &                           GetStumbleDuration( void ) const;
    void                                      SetAnimationFile( bCString const & );
    void                                      SetBlendInTime( GEFloat const & );
    void                                      SetMoveDuration( GEFloat const & );
    void                                      SetMovementBegin( GEFloat const & );
    void                                      SetMovementDistance( GEFloat const & );
    void                                      SetMovementEnd( GEFloat const & );
    void                                      SetResultingAniState( bTPropertyContainer< gEAniState > const & );
    void                                      SetStumbleDuration( GEFloat const & );
    gSCombatMoveInstanceStumble *             Start( gCCombatSystem_PS *, bCVector const &, bCVector const & );
public:
    gCCombatMoveStumble & operator = ( gCCombatMoveStumble const & );
public:
    gCCombatMoveStumble( gCCombatMoveStumble const & );
    gCCombatMoveStumble( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveStumble, 0x0038 )

#pragma warning( pop )

#endif
