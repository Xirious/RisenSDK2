#ifndef GE_INTERACTION_PS_H_INCLUDED
#define GE_INTERACTION_PS_H_INCLUDED

enum gEFocusNameType
{
    gEFocusNameType_Skeleton   = 0x00000000,
    gEFocusNameType_Entity     = 0x00000001,
    gEFocusNameType_Bone       = 0x00000002,
    gEFocusNameType_Disable    = 0x00000003,
    gEFocusNameType_Center     = 0x00000004,
    gEFocusNameType_ForceDWORD = GE_FORCE_DWORD
};

enum gEFocusPriority
{
    gEFocusPriority_None       = 0x00000000,
    gEFocusPriority_Lowest     = 0x00000001,
    gEFocusPriority_Low        = 0x00000002,
    gEFocusPriority_Normal     = 0x00000003,
    gEFocusPriority_High       = 0x00000004,
    gEFocusPriority_Highest    = 0x00000005,
    gEFocusPriority_ForceDWORD = GE_FORCE_DWORD
};

enum gEInteractionUseType
{
    gEInteractionUseType_None           = 0x00000000,
    gEInteractionUseType_Item           = 0x00000001,
    gEInteractionUseType_NPC            = 0x00000002,
    gEInteractionUseType_Roam           = 0x00000003,
    gEInteractionUseType_CoolWeapon     = 0x00000004,
    gEInteractionUseType_Anvil          = 0x00000005,
    gEInteractionUseType_Forge          = 0x00000006,
    gEInteractionUseType_GrindStone     = 0x00000007,
    gEInteractionUseType_Cauldron       = 0x00000008,
    gEInteractionUseType_Barbecue       = 0x00000009,
    gEInteractionUseType_Alchemy        = 0x0000000A,
    gEInteractionUseType_LookAt         = 0x0000000B,
    gEInteractionUseType_Bookstand      = 0x0000000C,
    gEInteractionUseType_TakeCarryable  = 0x0000000D,
    gEInteractionUseType_DropCarryable  = 0x0000000E,
    gEInteractionUseType_PickOre        = 0x0000000F,
    gEInteractionUseType_PickGround     = 0x00000010,
    gEInteractionUseType_DigGround      = 0x00000011,
    gEInteractionUseType_Fieldwork      = 0x00000012,
    gEInteractionUseType_WriteScroll    = 0x00000013,
    gEInteractionUseType_SawLog         = 0x00000014,
    gEInteractionUseType_PracticeStaff  = 0x00000015,
    gEInteractionUseType_Bed            = 0x00000016,
    gEInteractionUseType_SleepGround    = 0x00000017,
    gEInteractionUseType_SweepFloor     = 0x00000018,
    gEInteractionUseType_Dance          = 0x00000019,
    gEInteractionUseType_Flute          = 0x0000001A,
    gEInteractionUseType_Boss           = 0x0000001B,
    gEInteractionUseType_Throne         = 0x0000001C,
    gEInteractionUseType_Pace           = 0x0000001D,
    gEInteractionUseType_Bard           = 0x0000001E,
    gEInteractionUseType_Stool          = 0x0000001F,
    gEInteractionUseType_Bench          = 0x00000020,
    gEInteractionUseType_Waterpipe      = 0x00000021,
    gEInteractionUseType_Fountain       = 0x00000022,
    gEInteractionUseType_PirateTreasure = 0x00000023,
    gEInteractionUseType_Campfire       = 0x00000024,
    gEInteractionUseType_Stove          = 0x00000025,
    gEInteractionUseType_SitGround      = 0x00000026,
    gEInteractionUseType_Smalltalk      = 0x00000027,
    gEInteractionUseType_Preach         = 0x00000028,
    gEInteractionUseType_Spectator      = 0x00000029,
    gEInteractionUseType_Stand          = 0x0000002A,
    gEInteractionUseType_Guard          = 0x0000002B,
    gEInteractionUseType_Trader         = 0x0000002C,
    gEInteractionUseType_Listener       = 0x0000002D,
    gEInteractionUseType_Cupboard       = 0x0000002E,
    gEInteractionUseType_Pee            = 0x0000002F,
    gEInteractionUseType_Bathtub        = 0x00000030,
    gEInteractionUseType_Door           = 0x00000031,
    gEInteractionUseType_Chest          = 0x00000032,
    gEInteractionUseType_Flee           = 0x00000033,
    gEInteractionUseType_Lever          = 0x00000034,
    gEInteractionUseType_Button         = 0x00000035,
    gEInteractionUseType_Winch          = 0x00000036,
    gEInteractionUseType_Destructable   = 0x00000037,
    gEInteractionUseType_Goldsmith      = 0x00000038,
    gEInteractionUseType_Altar          = 0x00000039,
    gEInteractionUseType_Sarcophagus    = 0x0000003A,
    gEInteractionUseType_SecretRing     = 0x0000003B,
    gEInteractionUseType_MagicOrb       = 0x0000003C,
    gEInteractionUseType_RedBarrier     = 0x0000003D,
    gEInteractionUseType_BlueBarrier    = 0x0000003E,
    gEInteractionUseType_LizardBook     = 0x0000003F,
    gEInteractionUseType_PracticeSword  = 0x00000040,
    gEInteractionUseType_PracticeMagic  = 0x00000041,
    gEInteractionUseType_Plunder        = 0x00000042,
    gEInteractionUseType_Loo            = 0x00000043,
    gEInteractionUseType_Attack         = 0x00000044,
    gEInteractionUseType_Keyhole        = 0x00000045,
    gEInteractionUseType_ForceDWORD     = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCInteraction_PS :
    public eCEntityPropertySet
{
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                                   PostInitializeProperties( void );
public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEInt                                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr                     GetNativePropertyAt( GEInt ) const;
public:    virtual                                           ~gCInteraction_PS( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
protected: virtual GEBool                                     IsVisual( void ) const;
protected: virtual GEBool                                     IsEntityListener( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
protected: virtual void                                       OnTrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnUntrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnTouch( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnIntersect( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnUntouch( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
protected: virtual void                                       OnEnterProcessingRange( void );
protected: virtual void                                       OnExitProcessingRange( void );
protected: virtual void                                       OnRenderDebug( void );
protected: virtual void                                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected: virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
public:    virtual void                                       OnCacheIn( void );
public:    virtual void                                       OnCacheOut( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0114 -sizeof(eCEntityPropertySet) ];
protected:
    void Invalidate( void );
    void SetCurrentInteractionTarget( eCEntity *, gCInteraction *, GEInt );
    void SetCurrentUser( eCEntity * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCScriptProxyScript &                               AccessAttachedSlotScript( void );
    eCScriptProxyScript &                               AccessCanAttachSlotScript( void );
    eCScriptProxyScript &                               AccessDamageScript( void );
    eCScriptProxyScript &                               AccessDetachedSlotScript( void );
    eCScriptProxyScript &                               AccessEnterROIScript( void );
    eCScriptProxyScript &                               AccessExitROIScript( void );
    bCString &                                          AccessFocusNameBone( void );
    bTPropertyContainer< gEFocusNameType > &            AccessFocusNameType( void );
    bTPropertyContainer< gEFocusPriority > &            AccessFocusPriority( void );
    eCScriptProxyScript &                               AccessFocusPriorityScript( void );
    bCVector &                                          AccessFocusViewOffset( void );
    bCVector &                                          AccessFocusWorldOffset( void );
    GEBool &                                            AccessGroundBias( void );
    GEInt &                                             AccessInteractionCounter( void );
    eCScriptProxyScript &                               AccessIntersectScript( void );
    eCEntityProxy &                                     AccessOwner( void );
    eCScriptProxyScript &                               AccessRoomChangedScript( void );
    gCScriptProxyAIState &                              AccessRoutineTask( void );
    bTObjArray< gCInteractionSlot > &                   AccessSlots( void );
    eCTemplateEntityProxy &                             AccessSpell( void );
    eCScriptProxyScript &                               AccessTouchScript( void );
    eCScriptProxyScript &                               AccessTriggerScript( void );
    eCScriptProxyScript &                               AccessUntouchScript( void );
    eCScriptProxyScript &                               AccessUntriggerScript( void );
    bTPropertyContainer< gEInteractionUseType > &       AccessUseType( void );
    void                                                AddInteraction( gCInteraction * );
    eCEntity *                                          Attach( eCTemplateEntity * );
    GEBool                                              BeginInteraction( eCEntity *, gEInteractionType, GEInt );
    GEBool                                              CanAttach( eCTemplateEntity * ) const;
    GEBool                                              CanInteractWith( eCEntity *, gEInteractionType, GEInt ) const;
    GEBool                                              Detach( eCEntity * );
    GEBool                                              EndInteraction( void );
    eCEntity *                                          GetAnchorPoint( void ) const;
    eCScriptProxyScript const &                         GetAttachedSlotScript( void ) const;
    eCScriptProxyScript const &                         GetCanAttachSlotScript( void ) const;
    GEInt                                               GetCurrentIntParam( void ) const;
    eCEntity *                                          GetCurrentTarget( void ) const;
    gCInteraction *                                     GetCurrentTargetInteraction( void ) const;
    eCEntity *                                          GetCurrentUser( void ) const;
    eCScriptProxyScript const &                         GetDamageScript( void ) const;
    eCScriptProxyScript const &                         GetDetachedSlotScript( void ) const;
    eCScriptProxyScript const &                         GetEnterROIScript( void ) const;
    eCScriptProxyScript const &                         GetExitROIScript( void ) const;
    bCUnicodeString                                     GetFocusName( void ) const;
    bCString const &                                    GetFocusNameBone( void ) const;
    GEBool                                              GetFocusNameOffsets( bCVector &, bCVector & );
    bTPropertyContainer< gEFocusNameType > const &      GetFocusNameType( void ) const;
    bTPropertyContainer< gEFocusPriority > const &      GetFocusPriority( void ) const;
    eCScriptProxyScript const &                         GetFocusPriorityScript( void ) const;
    bCVector const &                                    GetFocusViewOffset( void ) const;
    bCVector const &                                    GetFocusWorldOffset( void ) const;
    GEBool const &                                      GetGroundBias( void ) const;
    gCInteraction *                                     GetInteractionAt( GEInt ) const;
    GEInt                                               GetInteractionCount( void ) const;
    GEInt const &                                       GetInteractionCounter( void ) const;
    GEInt                                               GetInteractionIndex( gCInteraction * ) const;
    eCScriptProxyScript const &                         GetIntersectScript( void ) const;
    eCEntity *                                          GetNavigationZone( void ) const;
    bCPropertyID const &                                GetNavigationZoneID( void ) const;
    GEBool                                              GetNavigationZoneIsPath( void ) const;
    eCEntityProxy const &                               GetOwner( void ) const;
    bCUnicodeString                                     GetPlainFocusName( void ) const;
    eCScriptProxyScript const &                         GetRoomChangedScript( void ) const;
    gCScriptProxyAIState const &                        GetRoutineTask( void ) const;
    bTObjArray< gCInteractionSlot > const &             GetSlots( void ) const;
    eCTemplateEntityProxy const &                       GetSpell( void ) const;
    eCScriptProxyScript const &                         GetTouchScript( void ) const;
    eCScriptProxyScript const &                         GetTriggerScript( void ) const;
    eCScriptProxyScript const &                         GetUntouchScript( void ) const;
    eCScriptProxyScript const &                         GetUntriggerScript( void ) const;
    bTPropertyContainer< gEInteractionUseType > const & GetUseType( void ) const;
    GEBool                                              IsAttached( eCEntity * ) const;
    GEBool                                              IsFreeDestination( eCEntity * ) const;
    GEBool                                              IsOutOfNavigationArea( void ) const;
    void                                                RemoveInteraction( gCInteraction * );
    void                                                SetAnchorPoint( eCEntity * );
    void                                                SetAttachedSlotScript( eCScriptProxyScript const & );
    void                                                SetCanAttachSlotScript( eCScriptProxyScript const & );
    void                                                SetDamageScript( eCScriptProxyScript const & );
    void                                                SetDetachedSlotScript( eCScriptProxyScript const & );
    void                                                SetEnterROIScript( eCScriptProxyScript const & );
    void                                                SetExitROIScript( eCScriptProxyScript const & );
    void                                                SetFocusName( bCUnicodeString const & );
    void                                                SetFocusNameBone( bCString const & );
    void                                                SetFocusNameType( bTPropertyContainer< gEFocusNameType > const & );
    void                                                SetFocusPriority( bTPropertyContainer< gEFocusPriority > const & );
    void                                                SetFocusPriorityScript( eCScriptProxyScript const & );
    void                                                SetFocusViewOffset( bCVector const & );
    void                                                SetFocusWorldOffset( bCVector const & );
    void                                                SetGroundBias( GEBool const & );
    void                                                SetInteractionCounter( GEInt const & );
    void                                                SetIntersectScript( eCScriptProxyScript const & );
    void                                                SetNavigationZone( eCEntity * );
    void                                                SetNavigationZoneID( bCPropertyID const & );
    void                                                SetNavigationZoneIsPath( GEBool );
    void                                                SetOwner( eCEntityProxy const & );
    void                                                SetRoomChangedScript( eCScriptProxyScript const & );
    void                                                SetRoutineTask( gCScriptProxyAIState const & );
    void                                                SetSlots( bTObjArray< gCInteractionSlot > const & );
    void                                                SetSpell( eCTemplateEntityProxy const & );
    void                                                SetTouchScript( eCScriptProxyScript const & );
    void                                                SetTriggerScript( eCScriptProxyScript const & );
    void                                                SetUntouchScript( eCScriptProxyScript const & );
    void                                                SetUntriggerScript( eCScriptProxyScript const & );
    void                                                SetUseType( bTPropertyContainer< gEInteractionUseType > const & );
public:
    gCInteraction_PS & operator = ( gCInteraction_PS const & );
public:
    gCInteraction_PS( gCInteraction_PS const & );
    gCInteraction_PS( void );
};
GE_ASSERT_SIZEOF( gCInteraction_PS, 0x0114 )

#endif
