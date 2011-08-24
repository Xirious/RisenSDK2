#ifndef GS_PSITEM_H_INCLUDED
#define GS_PSITEM_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSItem, gCItem_PS )
public:
    GS_DECLARE_PROPERTY( Dropped,           GEBool )
    GS_DECLARE_PROPERTY( EffectMaterial,    bCString )
    GS_DECLARE_PROPERTY( HoldType,          gEItemHoldType )
    GS_DECLARE_PROPERTY( IsDangerousWeapon, GEBool )
    GS_DECLARE_PROPERTY( UseType,           gEItemUseType )
public:
    static bCString GE_STDCALL GetHoldType( gEItemHoldType );
public:
    void                                ApplyModSkills( Entity & );
    GEU32                               GetAmount( void ) const;
    gEItemCategory                      GetCategory( void ) const;
    Entity                              GetEquipOwner( void ) const;
    GEInt                               GetGoldValue( void ) const;
    bCString                            GetHoldType( void ) const;
    bCString                            GetIconImage( void ) const;
    bTObjArray< gCModifySkill > const & GetModSkills( void ) const;
    Entity                              GetSpell( void ) const;
    gEItemUseType                       GetUseType( void ) const;
    GEBool                              HasRequiredSkills( Entity &, bTObjArray< gSMissingSkill > & );
    GEBool                              IsEquipped( void ) const;
    GEBool                              IsMissionItem( void ) const;
    GEBool                              IsValid( void ) const;
    void                                SetAmount( GEU32 );
    void                                UnApplyModSkills( Entity & );
};

#endif
