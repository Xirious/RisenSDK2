#ifndef GE_ITEM_PS_H_INCLUDED
#define GE_ITEM_PS_H_INCLUDED

enum gEItemCategory
{
    gEItemCategory_None       = 0x00000000,
    gEItemCategory_Weapon     = 0x00000001,
    gEItemCategory_Armor      = 0x00000002,
    gEItemCategory_Consumable = 0x00000003,
    gEItemCategory_Empty_D    = 0x00000004,
    gEItemCategory_Magic      = 0x00000005,
    gEItemCategory_Misc       = 0x00000006,
    gEItemCategory_Written    = 0x00000007,
    gEItemCategory_Empty_B    = 0x00000008,
    gEItemCategory_Empty_E    = 0x00000009,
    gEItemCategory_Empty_F    = 0x0000000A,
    gEItemCategory_Count      = 0x0000000B,
    gEItemCategory_ForceDWORD = GE_FORCE_DWORD
};

enum gEItemHoldType
{
    gEItemHoldType_None,
    gEItemHoldType_1H,
    gEItemHoldType_2H,
    gEItemHoldType_BS,
    gEItemHoldType_Arrow,
    gEItemHoldType_Bow,
    gEItemHoldType_CrossBow,
    gEItemHoldType_Bolt,
    gEItemHoldType_Fist,
    gEItemHoldType_Shield,
    gEItemHoldType_Armor,
    gEItemHoldType_Helmet,
    gEItemHoldType_Staff,
    gEItemHoldType_Amulet,
    gEItemHoldType_Ring,
    gEItemHoldType_Rune,
    gEItemHoldType_Torch,
    gEItemHoldType_CarryFront,
    gEItemHoldType_Axe,
    gEItemHoldType_Apple,
    gEItemHoldType_Bread,
    gEItemHoldType_Jar,
    gEItemHoldType_Joint,
    gEItemHoldType_Meat,
    gEItemHoldType_Potion,
    gEItemHoldType_Saringda,
    gEItemHoldType_Saw,
    gEItemHoldType_Scoop,
    gEItemHoldType_Stew,
    gEItemHoldType_Cast,
    gEItemHoldType_Magic,
    gEItemHoldType_FocusCast,
    gEItemHoldType_MagicMissile,
    gEItemHoldType_MagicFireball,
    gEItemHoldType_MagicIcelance,
    gEItemHoldType_Flute,
    gEItemHoldType_Count,
    gEItemHoldType_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA GELPCChar const g_ppszItemHoldTypes[ gEItemHoldType_Count ];

enum gEItemUseType
{
    gEItemUseType_None,
    gEItemUseType_1H,
    gEItemUseType_2H,
    gEItemUseType_BS,
    gEItemUseType_Arrow,
    gEItemUseType_Bow,
    gEItemUseType_CrossBow,
    gEItemUseType_Bolt,
    gEItemUseType_Fist,
    gEItemUseType_Shield,
    gEItemUseType_Armor,
    gEItemUseType_Helmet,
    gEItemUseType_Staff,
    gEItemUseType_Amulet,
    gEItemUseType_Ring,
    gEItemUseType_Rune,
    gEItemUseType_Torch,
    gEItemUseType_CarryFront,
    gEItemUseType_Axe,
    gEItemUseType_Cast,
    gEItemUseType_FocusCast,
    gEItemUseType_MagicMissile,
    gEItemUseType_MagicFireball,
    gEItemUseType_MagicIcelance,
    gEItemUseType_MagicAmmo,
    gEItemUseType_MagicFrost,
    gEItemUseType_Head,
    gEItemUseType_Count,
    gEItemUseType_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA GELPCChar const g_ppszItemUseTypes[ gEItemUseType_Count ];

class GE_DLLIMPORT gCItem_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public: virtual GEU16                                      GetVersion( void ) const;
public: virtual GEBool                                     OnRead( bCIStream & );
public: virtual GEBool                                     OnWrite( bCOStream & );
public: virtual bEResult                                   Create( void );
public: virtual void                                       Destroy( void );
public: virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public: virtual bEResult                                   PostInitializeProperties( void );
public: virtual GEInt                                      GetNativePropertyCount( void ) const;
public: virtual bCPropertyConverterPtr                     GetNativePropertyAt( GEInt ) const;
public: virtual                                           ~gCItem_PS( void );
public: virtual eEPropertySetType                          GetPropertySetType( void ) const;
public: virtual GEBool                                     IsReferencedByTemplate( void ) const;
public: virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public: virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x009C - sizeof(eCEntityPropertySet) ];
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &                                       AccessAmount( void );
    eCScriptProxyScript &                         AccessCanEquipScript( void );
    bTPropertyContainer< gEItemCategory > &       AccessCategory( void );
    GEFloat &                                     AccessCombatHitRangeOffset( void );
    GEBool &                                      AccessDropped( void );
    bCString &                                    AccessEffectMaterial( void );
    eCScriptProxyScript &                         AccessEquipScript( void );
    GEI32 &                                       AccessGoldValue( void );
    bCVector &                                    AccessHoldOffset( void );
    bTPropertyContainer< gEItemHoldType > &       AccessHoldType( void );
    eCGuiBitmapProxy2 &                           AccessIconImage( void );
    GEBool &                                      AccessIsDangerousWeapon( void );
    eCTemplateEntityProxy &                       AccessItemInventory( void );
    eCTemplateEntityProxy &                       AccessItemWorld( void );
    GEBool &                                      AccessMissionItem( void );
    bTObjArray< gCModifySkill > &                 AccessModifySkills( void );
    GEBool &                                      AccessPermanent( void );
    bTObjArray< gCSkillValue > &                  AccessRequiredSkills( void );
    GEI32 &                                       AccessSortValue( void );
    eCTemplateEntityProxy &                       AccessSpell( void );
    eCScriptProxyScript &                         AccessUnEquipScript( void );
    bTPropertyContainer< gEItemUseType > &        AccessUseType( void );
    void                                          ApplyModSkills( eCEntity * ) const;
    GEInt                                         Compare( gCItem_PS const &, gCInventory_PS const & ) const;
    GEU32 const &                                 GetAmount( void ) const;
    eCScriptProxyScript const &                   GetCanEquipScript( void ) const;
    bTPropertyContainer< gEItemCategory > const & GetCategory( void ) const;
    GEFloat const &                               GetCombatHitRangeOffset( void ) const;
    bCUnicodeString                               GetDescription( void ) const;
    GEBool const &                                GetDropped( void ) const;
    bCString const &                              GetEffectMaterial( void ) const;
    eCEntity *                                    GetEquipOwner( void ) const;
    eCScriptProxyScript const &                   GetEquipScript( void ) const;
    GEI32 const &                                 GetGoldValue( void ) const;
    bCVector const &                              GetHoldOffset( void ) const;
    bTPropertyContainer< gEItemHoldType > const & GetHoldType( void ) const;
    eCGuiBitmapProxy2 const &                     GetIconImage( void ) const;
    GEBool const &                                GetIsDangerousWeapon( void ) const;
    eCTemplateEntityProxy const &                 GetItemInventory( void ) const;
    eCTemplateEntityProxy const &                 GetItemWorld( void ) const;
    GEBool const &                                GetMissionItem( void ) const;
    GEInt                                         GetModValue( gESkill ) const;
    bTObjArray< gCModifySkill > const &           GetModifySkills( void ) const;
    GEBool const &                                GetPermanent( void ) const;
    bCUnicodeString                               GetPlainDescription( void ) const;
    bTObjArray< gCSkillValue > const &            GetRequiredSkills( void ) const;
    gESlot                                        GetSlot( void ) const;
    GEI32 const &                                 GetSortValue( void ) const;
    eCTemplateEntityProxy const &                 GetSpell( void ) const;
    eCScriptProxyScript const &                   GetUnEquipScript( void ) const;
    bTPropertyContainer< gEItemUseType > const &  GetUseType( void ) const;
    GEBool                                        HasRequiredSkills( eCEntity *, bTObjArray< gSMissingSkill > & ) const;
    GEBool                                        IsEquipped( void ) const;
    GEBool                                        IsVisible( void ) const;
    void                                          SetAmount( GEU32 const & );
    void                                          SetCanEquipScript( eCScriptProxyScript const & );
    void                                          SetCategory( bTPropertyContainer< gEItemCategory > const & );
    void                                          SetCombatHitRangeOffset( GEFloat const & );
    void                                          SetDescription( bCUnicodeString const & );
    void                                          SetDropped( GEBool const & );
    void                                          SetEffectMaterial( bCString const & );
    void                                          SetEquipScript( eCScriptProxyScript const & );
    void                                          SetGoldValue( GEI32 const & );
    void                                          SetHoldOffset( bCVector const & );
    void                                          SetHoldType( bTPropertyContainer< gEItemHoldType > const & );
    void                                          SetIconImage( eCGuiBitmapProxy2 const & );
    void                                          SetIsDangerousWeapon( GEBool const & );
    void                                          SetItemInventory( eCTemplateEntityProxy const & );
    void                                          SetItemWorld( eCTemplateEntityProxy const & );
    void                                          SetMissionItem( GEBool const & );
    void                                          SetModifySkills( bTObjArray< gCModifySkill > const & );
    void                                          SetPermanent( GEBool const & );
    void                                          SetRequiredSkills( bTObjArray< gCSkillValue > const & );
    void                                          SetSlot( gESlot );
    void                                          SetSortValue( GEI32 const & );
    void                                          SetSpell( eCTemplateEntityProxy const & );
    void                                          SetUnEquipScript( eCScriptProxyScript const & );
    void                                          SetUseType( bTPropertyContainer< gEItemUseType > const & );
    void                                          SetVisible( GEBool );
    void                                          UnApplyModSkills( eCEntity * ) const;
public:
    gCItem_PS & operator = ( gCItem_PS const & );
public:
    gCItem_PS( gCItem_PS const & );
    gCItem_PS( void );
};
GE_ASSERT_SIZEOF( gCItem_PS, 0x009C )

#endif
