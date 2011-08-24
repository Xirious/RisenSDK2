#ifndef GE_COMBATSYSTEM_PS_H_INCLUDED
#define GE_COMBATSYSTEM_PS_H_INCLUDED

enum gECombatFightAIMode
{
    gECombatFightAIMode_Active     = 0x00000000,
    gECombatFightAIMode_Passive    = 0x00000001,
    gECombatFightAIMode_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatSystem_PS'

class GE_DLLIMPORT gCCombatSystem_PS :
    public eCEntityPropertySet
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCCombatSystem_PS * m_pCombatSystemPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                           ~gCCombatSystem_PS( void );
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;
public:    virtual GEBool                     IsReferencedByTemplate( void ) const;
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual GEBool                     IsClassProcessible( void ) const;
public:    virtual GEBool                     IsClassProcessingEnabled( void ) const;
public:    virtual void                       EnableClassProcessing( GEBool );
public:    virtual void                       EnterProcessingRange( void );
public:    virtual void                       ExitProcessingRange( void );
public:    virtual void                       OnProcess( void );
protected: virtual GEBool                     OnListenEntityEvent( eSEntityListenerEvent const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                                   m_strCombatSpecies;
    bCString                                   m_strActiveFightAI;
    bCString                                   m_strPassiveFightAI;
    bTPropertyContainer< gECombatFightAIMode > m_enumFightAIMode;
    eCEntityProxy                              m_ActiveAttacker;
    bCString                                   m_strFightVoice;
    CProcessor                                 m_Processor;
    gCCombatSpecies *                          m_pSpecies;
    gSCombatMoveInstance *                     m_pCurrentMoveInstance;
    gCCombatMove *                             m_pCurrentMove;
    gECombatMove                               m_enumCurrentCombatMove;
    eCEntityProxy                              m_CurrentTarget;
    gECombatMove                               m_enumNextMove;
    GEFloat                                    m_fNextWalkDuration;
    GEFloat                                    m_f__FIXME_0060;
    gECombatMove                               m_enumLastAttackMove;
    GEFloat                                    m_f__FIXME_0068;
    GEFloat                                    m_fNextAttackTimeStamp;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityProxy &                                    AccessActiveAttacker( void );
    bCString &                                         AccessActiveFightAI( void );
    bCString &                                         AccessCombatSpecies( void );
    bTPropertyContainer< gECombatFightAIMode > &       AccessFightAIMode( void );
    bCString &                                         AccessFightVoice( void );
    bCString &                                         AccessPassiveFightAI( void );
    GEBool                                             CanCounterCurrentTarget( gECombatMove ) const;
    GEBool                                             DelegateActiveStatus( void );
    void                                               FinishCurrentMove( void );
    eCEntityProxy const &                              GetActiveAttacker( void ) const;
    bCString const &                                   GetActiveFightAI( void ) const;
    gECombatMode                                       GetCombatMode( gEItemUseType, gEItemUseType ) const;
    bCString const &                                   GetCombatSpecies( void ) const;
    gECombatMode                                       GetCurrentCombatMode( void ) const;
    gECombatMove                                       GetCurrentCombatMove( void ) const;
    gCCombatAI *                                       GetCurrentFightAI( void ) const;
    gCCombatMove *                                     GetCurrentMove( void ) const;
    gSCombatMoveInstance *                             GetCurrentMoveInstance( void ) const;
    gCCombatStyle *                                    GetCurrentStyle( void ) const;
    eCEntity *                                         GetCurrentTarget( void ) const;
    bCString const &                                   GetEffectMaterial( void ) const;
    bTPropertyContainer< gECombatFightAIMode > const & GetFightAIMode( void ) const;
    bCString const &                                   GetFightVoice( void ) const;
    GEFloat                                            GetHitSufferRadius( void ) const;
    gECombatMove                                       GetLastAttackMove( void ) const;
    GEFloat                                            GetNextAttackTimeStamp( void ) const;
    gECombatMove                                       GetNextMove( void ) const;
    GEFloat                                            GetNextWalkDuration( void ) const;
    bCString const &                                   GetPassiveFightAI( void ) const;
    gCCombatSpecies *                                  GetSpecies( void ) const;
    gCCombatStyle *                                    GetStyle( gEItemUseType, gEItemUseType ) const;
    GEBool                                             HasMoveAttackCombo( void );
    void                                               InteruptCurrentMove( void );
    GEBool                                             IsCurrentMoveInteruptable( void );
    GEBool                                             IsInParade( gCCombatSystem_PS *, bCVector const & );
    GEBool                                             IsInParade( gECombatParadeType, bCVector const & );
    GEBool                                             IsToFar( GEFloat, GEFloat );
    GEBool                                             IsToNear( GEFloat, GEFloat );
    GEBool                                             IsToNearMeleeDistance( GEFloat, GEFloat );
    void                                               OnAction( gSAction const & );
    GEBool                                             RequestActiveStatus( void );
    GEBool                                             SelectNextMove( gECombatMove );
    void                                               SetActiveAttacker( eCEntityProxy const & );
    void                                               SetActiveFightAI( bCString const & );
    void                                               SetCombatSpecies( bCString const & );
    GEBool                                             SetCurrentTarget( eCEntity * );
    void                                               SetFightAIMode( bTPropertyContainer< gECombatFightAIMode > const & );
    void                                               SetFightVoice( bCString const & );
    void                                               SetNextMove( gECombatMove );
    void                                               SetPassiveFightAI( bCString const & );
    GEBool                                             StartComboMove( gECombatMove );
    GEBool                                             StartMove( gCCombatMove *, gCCombatStyle *, gECombatMove );
    GEBool                                             StartMove( gECombatMove );
    GEBool                                             StartStumble( eCEntity * );
    GEBool                                             StartStumble( eCEntity *, gECombatMove, gECombatMove );
    GEBool                                             StartStumble( gECombatMove, bCVector const &, bCVector const & );
    void                                               StopCurrentCombo( void );
    void                                               StopCurrentMove( void );
    GEBool                                             UpdateCurrentMove( void );
public:
    gCCombatSystem_PS & operator = ( gCCombatSystem_PS const & );
public:
    gCCombatSystem_PS( gCCombatSystem_PS const & );
    gCCombatSystem_PS( void );
};
GE_ASSERT_SIZEOF( gCCombatSystem_PS, 0x0070 )

#pragma warning( pop )

#endif
