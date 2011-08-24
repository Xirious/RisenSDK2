#ifndef GE_INVENTORY_PS_H_INCLUDED
#define GE_INVENTORY_PS_H_INCLUDED

class GE_DLLIMPORT gCInventory_PS :
    public eCEntityPropertySet,
    public gCInventoryListener
{
protected:
    enum EEvent
    {
        EEvent_StackCreate,
        EEvent_StackChange,
        EEvent_StackDelete,
        EEvent_SortInventory,
        EEvent_DestroyInventory,
        EEvent_ForceDWORD = GE_FORCE_DWORD
    };
// eCEntityPropertySet
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual GEBool                                     OnCopyPatchableOnly( bCObjectBase const & );
public:    virtual GEInt                                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr                     GetNativePropertyAt( GEInt ) const;
public:    virtual                                           ~gCInventory_PS( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                                       OnCacheIn( void );
protected: virtual void                                       OnCacheOut( void );
protected: virtual void                                       OnPrefetch( bCVector const & );
public:    virtual void                                       AddListener( gCInventoryListener * );
public:    virtual void                                       RemoveListener( gCInventoryListener * );
// gCInventoryListener
public:    virtual void                                       OnStackCreate( GEInt, gCInventoryStack const * );
public:    virtual void                                       OnStackChange( GEInt, gCInventoryStack const * );
public:    virtual void                                       OnStackDelete( GEInt, gCInventoryStack const * );
public:    virtual void                                       OnSortInventory( void );
public:    virtual void                                       OnDestroyInventory( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0160 - sizeof(eCEntityPropertySet) -sizeof(gCInventoryListener) ];
protected:
    GEBool ClearDefaultItems( void );
    GEInt  FindListenerIndex( gCInventoryListener * ) const;
    void   Invalidate( void );
    GEBool LinkDefaultItemToSlot( gESlot );
    GEBool LinkDefaultItems( void );
    void   NotifyListeners( EEvent, GEInt, gCInventoryStack const * );
    void   PurgeListeners( void );
    GEBool ReadV212( bCIStream & );
    GEBool UnEqupiInvalidStacks( void );
    GEBool UnlinkDefaultItemFromSlot( gESlot );
    GEBool UnlinkDefaultItems( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static GEFloat                    GE_STDCALL GetPurchaseAmount( eCEntity const * );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                 AccessGeneratedPlunder( void );
    GEBool &                 AccessGeneratedTrade( void );
    GEInt                    AssureItems( bCPropertyID const &, GEU32, gEStackType );
    GEBool                   CanEquipStackToSlot( GEInt, gEEquipSlot );
    GEBool                   ConsumeItems( GEInt, GEU32 );
    GEInt                    CreateItems( bCPropertyID const &, GEU32, gEStackType );
    GEInt                    CreateItems( eCTemplateEntity const *, GEU32, gEStackType );
    GEInt                    CreateStack( void );
    GEBool                   DeleteItems( GEInt, GEU32 );
    GEBool                   DeleteStack( GEInt );
    eCEntity *               DropItemsFromSlot( gESlot, GEInt, bCMatrix const * );
    eCEntity *               DropItemsFromStack( GEInt, GEInt, bCMatrix const * );
    eCEntity *               DropSlot( gESlot, bCMatrix const * );
    eCEntity *               DropStack( GEInt, bCMatrix const * );
    void                     Dump( void ) const;
    GEBool                   EquipStack( GEInt );
    GEBool                   EquipStackToSlot( GEInt, gEEquipSlot );
    gCInventoryStack const * FindStack( bCPropertyID const &, GEInt ) const;
    gCInventoryStack const * FindStack( bCPropertyID const &, gEStackType, GEInt ) const;
    gCInventoryStack const * FindStack( bCString const &, GEInt ) const;
    gCInventoryStack const * FindStack( bCString const &, gEStackType, GEInt ) const;
    gCInventoryStack const * FindStack( eCTemplateEntity const *, GEInt ) const;
    gCInventoryStack const * FindStack( eCTemplateEntity const *, gEStackType, GEInt ) const;
    gCInventoryStack const * FindStack( gEEquipSlot ) const;
    gCInventoryStack const * FindStack( gEItemUseType, GEInt ) const;
    gCInventoryStack const * FindStack( gEItemUseType, gEStackType, GEInt ) const;
    gCInventoryStack const * FindStack( gESlot ) const;
    GEInt                    FindStackIndex( bCPropertyID const &, GEInt ) const;
    GEInt                    FindStackIndex( bCPropertyID const &, gEStackType, GEInt ) const;
    GEInt                    FindStackIndex( bCString const &, GEInt ) const;
    GEInt                    FindStackIndex( bCString const &, gEStackType, GEInt ) const;
    GEInt                    FindStackIndex( eCTemplateEntity const *, GEInt ) const;
    GEInt                    FindStackIndex( eCTemplateEntity const *, gEStackType, GEInt ) const;
    GEInt                    FindStackIndex( gEEquipSlot ) const;
    GEInt                    FindStackIndex( gEItemUseType, GEInt ) const;
    GEInt                    FindStackIndex( gEItemUseType, gEStackType, GEInt ) const;
    GEInt                    FindStackIndex( gESlot ) const;
    GEInt                    FindStackIndexByHotKey( GEU32 ) const;
    GEInt                    FindStackIndexByID( GEU32 ) const;
    GEInt                    GetAmount( GEInt ) const;
    void                     GetDefaultItem( gESlot, bCPropertyID & ) const;
    gCInventorySlot &        GetDefaultSlot( gESlot );
    gCInventorySlot const &  GetDefaultSlot( gESlot ) const;
    GEBool const &           GetGeneratedPlunder( void ) const;
    GEBool const &           GetGeneratedTrade( void ) const;
    GEFloat                  GetMoneyAmount( void ) const;
    GEFloat                  GetSaleAmount( eCEntity const * ) const;
    GEInt                    GetSelectLimit( GEInt ) const;
    GEInt                    GetSelectRemain( GEInt ) const;
    GEInt                    GetSelection( GEInt ) const;
    gCInventoryStack *       GetStack( GEInt );
    gCInventoryStack const * GetStack( GEInt ) const;
    gEItemCategory           GetStackCategory( GEInt ) const;
    GEInt                    GetStackCount( void ) const;
    eCGeometryEntity *       GetStackFromSlot( gESlot ) const;
    GEU32                    GetStackID( GEInt ) const;
    gEItemUseType            GetStackUseType( GEInt ) const;
    eCGeometryEntity *       GetWeapon( GEBool );
    GEBool                   HoldStackLeftHand( GEInt );
    GEBool                   HoldStackRightHand( GEInt );
    GEBool                   HoldStacks( GEInt, GEInt );
    GEInt                    InsertStack( eCEntity * );
    GEBool                   IsDisplaySlot( gESlot ) const;
    GEBool                   IsDisplayStack( GEInt ) const;
    GEBool                   IsValidIndex( GEInt ) const;
    GEBool                   LinkStackToSlot( GEInt, gESlot );
    GEBool                   LootSelections( gCInventory_PS * );
    void                     MergeStacks( void );
    void                     SetAmount( GEInt, GEInt const &, GEBool );
    void                     SetDefaultItem( gESlot, bCPropertyID const & );
    void                     SetGeneratedPlunder( GEBool const & );
    void                     SetGeneratedTrade( GEBool const & );
    void                     SetMaxSelectLimit( void );
    void                     SetMaxSelection( void );
    void                     SetMinSelectLimit( void );
    void                     SetMinSelection( void );
    void                     SetMoneyAmount( GEInt );
    void                     SetSelectLimit( GEInt, GEInt const &, GEBool );
    void                     SetSelection( GEInt, GEInt const &, GEBool );
    void                     SetStackHotKey( GEInt, GEU32 );
    GEBool                   ShowSlot( GEBool, gESlot );
    void                     SortStacks( void );
    GEBool                   SplitStack( GEInt, GEU32, GEInt & );
    GEBool                   TradeSelections( gCInventory_PS * );
    GEBool                   TransferAllTo( gCInventory_PS *, gEStackType );
    GEBool                   TransferItemsTo( gCInventory_PS *, GEInt, GEInt, gEStackType );
    GEBool                   TransferStackTo( gCInventory_PS *, GEInt, gEStackType );
    GEBool                   UnEquipStack( GEInt, GEBool );
    GEInt                    UnEquipStackFromSlot( gEEquipSlot );
    GEInt                    UnlinkStackFromSlot( gESlot );
    GEBool                   UpdateVisibility( void );
public:
    gCInventory_PS & operator = ( gCInventory_PS const & );
public:
    gCInventory_PS( gCInventory_PS const & );
    gCInventory_PS( void );
};
GE_ASSERT_SIZEOF( gCInventory_PS, 0x0160 )

#endif
