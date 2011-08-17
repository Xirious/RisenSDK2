#ifndef GE_COMBATMOVEOVERLAYSTUMBLE_H_INCLUDED
#define GE_COMBATMOVEOVERLAYSTUMBLE_H_INCLUDED

class GE_DLLIMPORT gCCombatMoveOverlayStumble :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveOverlayStumble( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEBool                     IsInteruptable( gSCombatMoveInstance * ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString m_strAnimationFile;
    GEFloat  m_fMovementVelocity;
    GEFloat  m_fMovementDuration;
    GEFloat  m_fMovementFadeIn;
    GEFloat  m_fMovementFadeOut;
    GEFloat  m_fBlendInTime;
    GEFloat  m_fBlendOutTime;
    GEFloat  m_fStumbleDuration;
    GEBool   m_bInteruptable;
             GE_PADDING( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void GE_STDCALL gCCombatMoveOverlayStumble::StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessAnimationFile( void );
    GEFloat &        AccessBlendInTime( void );
    GEFloat &        AccessBlendOutTime( void );
    GEBool &         AccessInteruptable( void );
    GEFloat &        AccessMovementDuration( void );
    GEFloat &        AccessMovementFadeIn( void );
    GEFloat &        AccessMovementFadeOut( void );
    GEFloat &        AccessMovementVelocity( void );
    GEFloat &        AccessStumbleDuration( void );
    bCString const & GetAnimationFile( void ) const;
    GEFloat const &  GetBlendInTime( void ) const;
    GEFloat const &  GetBlendOutTime( void ) const;
    GEBool const &   GetInteruptable( void ) const;
    GEFloat const &  GetMovementDuration( void ) const;
    GEFloat const &  GetMovementFadeIn( void ) const;
    GEFloat const &  GetMovementFadeOut( void ) const;
    GEFloat const &  GetMovementVelocity( void ) const;
    GEFloat const &  GetStumbleDuration( void ) const;
    void             SetAnimationFile( bCString const & );
    void             SetBlendInTime( GEFloat const & );
    void             SetBlendOutTime( GEFloat const & );
    void             SetInteruptable( GEBool const & );
    void             SetMovementDuration( GEFloat const & );
    void             SetMovementFadeIn( GEFloat const & );
    void             SetMovementFadeOut( GEFloat const & );
    void             SetMovementVelocity( GEFloat const & );
    void             SetStumbleDuration( GEFloat const & );
public:
    gCCombatMoveOverlayStumble & operator = ( gCCombatMoveOverlayStumble const & );
public:
    gCCombatMoveOverlayStumble( gCCombatMoveOverlayStumble const & );
    gCCombatMoveOverlayStumble( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveOverlayStumble, 0x0038 )

#endif
