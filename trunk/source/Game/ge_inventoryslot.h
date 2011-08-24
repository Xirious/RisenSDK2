#ifndef GE_INVENTORYSLOT_H_INCLUDED
#define GE_INVENTORYSLOT_H_INCLUDED

enum gEEquipSlot
{
    gEEquipSlot_None         = 0x00000000,
    gEEquipSlot_MeleeWeapon  = 0x00000001,
    gEEquipSlot_MeleeShield  = 0x00000002,
    gEEquipSlot_RangedWeapon = 0x00000003,
    gEEquipSlot_RangedAmmo   = 0x00000004,
    gEEquipSlot_Amulet       = 0x00000005,
    gEEquipSlot_Ring1        = 0x00000006,
    gEEquipSlot_Ring2        = 0x00000007,
    gEEquipSlot_Armor        = 0x00000008,
    gEEquipSlot_Helmet       = 0x00000009,
    gEEquipSlot_ForceDWORD   = GE_FORCE_DWORD
};

enum gESlot
{
    //FIXME: gESlot constants.
    gESlot_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCInventorySlot :
    public bCObjectBase
{
public:
    enum ELink
    {
        ELink_None,
        ELink_Slot,
        ELink_Body,
        ELink_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCInventorySlot( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCTemplateEntityProxy m_Template;
    eCEntityProxy         m_Item;
    gESlot                m_enumSlot;
protected:
    static GEBool     GE_STDCALL AttachItemToSekelton( eCEntity *, eCEntity *, gESlot );
    static GEBool     GE_STDCALL DetachItemFromSkeleton( eCEntity *, eCEntity *, gESlot );
    static GEBool     GE_STDCALL EnableItemRendering( eCEntity *, eCEntity *, gESlot, GEBool );
    static eCEntity * GE_STDCALL SpawnItem( eCEntity *, eCTemplateEntity const *, GEBool );
    static GEBool     GE_STDCALL UpdateItemVisibility( eCEntity *, eCEntity *, gESlot );
protected:
    void       ApplyDefaults( void );
    void       Invalidate( void );
    eCEntity * SpawnItem( eCEntity *, eCTemplateEntity const * ) const;
    eCEntity * SpawnPickUp( eCEntity * ) const;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gEEquipSlot                GE_STDCALL GetAltEquipSlot( gEItemUseType );
    static GEBool                     GE_STDCALL GetBone( gESlot, gEItemUseType, bCString &, ELink &, gESlot & );
    static gEEquipSlot                GE_STDCALL GetEquipSlot( gEItemUseType );
    static gESlot                     GE_STDCALL GetSlot( gEEquipSlot );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCTemplateEntityProxy &       AccessTemplate( void );
    GEBool                        EnableRendering( GEBool, eCEntity * );
    gEEquipSlot                   GetAlternativeEquipSlot( void ) const;
    gEItemCategory                GetCategory( void ) const;
    GEBool                        GetEquipSlots( gEEquipSlot &, gEEquipSlot & ) const;
    eCEntityProxy const &         GetItem( void ) const;
    gEEquipSlot                   GetPrimaryEquipSlot( void ) const;
    gESlot                        GetSlot( void ) const;
    eCTemplateEntityProxy const & GetTemplate( void ) const;
    gEItemUseType                 GetUseType( void ) const;
    GEBool                        IsLinked( void ) const;
    GEBool                        IsPermanent( void ) const;
    GEBool                        LinkToSlot( eCEntity *, gESlot );
    GEBool                        ReBuildSlot( eCEntity * );
    void                          SetItem( eCEntityProxy const & );
    void                          SetSlot( gESlot );
    void                          SetTemplate( eCTemplateEntityProxy const & );
    GEBool                        UnLinkFromSlot( eCEntity * );
    GEBool                        UpdateVisibility( eCEntity * );
public:
    gCInventorySlot & operator = ( gCInventorySlot const & );
public:
    gCInventorySlot( gCInventorySlot const & );
    gCInventorySlot( void );
};
GE_ASSERT_SIZEOF( gCInventorySlot, 0x0014 )

#endif
