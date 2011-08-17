#ifndef GE_COMBATMOVERELOAD_H_INCLUDED
#define GE_COMBATMOVERELOAD_H_INCLUDED

struct gSCombatMoveInstanceReloadData
{
    void * m_pInstance;
    void * m_pEntity;
    void * m_pAnimation;
    void * m_pActor;
    void * m_pInventory;
    void * m_pItem;
    void * m_pItemAnimation;
    void * m_pItemActor;
};
GE_ASSERT_SIZEOF( gSCombatMoveInstanceReloadData, 0x0020 )

class GE_DLLIMPORT gCCombatMoveReload :
    public gCCombatMove
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMoveReload( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString            m_strBowAnimationFile;
    bCString            m_strReloadAnimationFile;
    GEFloat             m_fItemLinkFrame;
    bCRange1            m_ReloadDuration;
    eCScriptProxyScript m_OnLinkItem;
    eCScriptProxyScript m_OnGetFAIWeight;
    eCScriptProxyScript m_OnGetSpeedFactor;
private:
    GEFloat GetSpeedFactor( gCCombatSystem_PS * );
    GEFloat GetSpeedScaledValue( gCCombatSystem_PS *, bCRange1 const & );
    GEBool  StartArcher( gSCombatMoveInstanceReloadData & );
    void    StartBow( gSCombatMoveInstanceReloadData & );
    void    StopArcher( gSCombatMoveInstanceReloadData & );
    void    StopBow( gSCombatMoveInstanceReloadData & );
    GEBool  UpdateArcher( gSCombatMoveInstanceReloadData & );
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                  AccessBowAnimationFile( void );
    GEFloat &                   AccessItemLinkFrame( void );
    eCScriptProxyScript &       AccessOnGetFAIWeight( void );
    eCScriptProxyScript &       AccessOnGetSpeedFactor( void );
    eCScriptProxyScript &       AccessOnLinkItem( void );
    bCString &                  AccessReloadAnimationFile( void );
    bCRange1 &                  AccessReloadDuration( void );
    bCString const &            GetBowAnimationFile( void ) const;
    GEFloat const &             GetItemLinkFrame( void ) const;
    eCScriptProxyScript const & GetOnGetFAIWeight( void ) const;
    eCScriptProxyScript const & GetOnGetSpeedFactor( void ) const;
    eCScriptProxyScript const & GetOnLinkItem( void ) const;
    bCString const &            GetReloadAnimationFile( void ) const;
    bCRange1 const &            GetReloadDuration( void ) const;
    void                        SetBowAnimationFile( bCString const & );
    void                        SetItemLinkFrame( GEFloat const & );
    void                        SetOnGetFAIWeight( eCScriptProxyScript const & );
    void                        SetOnGetSpeedFactor( eCScriptProxyScript const & );
    void                        SetOnLinkItem( eCScriptProxyScript const & );
    void                        SetReloadAnimationFile( bCString const & );
    void                        SetReloadDuration( bCRange1 const & );
public:
    gCCombatMoveReload & operator = ( gCCombatMoveReload const & );
public:
    gCCombatMoveReload( gCCombatMoveReload const & );
    gCCombatMoveReload( void );
};
GE_ASSERT_SIZEOF( gCCombatMoveReload, 0x0040 )

#endif
