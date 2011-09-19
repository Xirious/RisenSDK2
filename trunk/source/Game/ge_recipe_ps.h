#ifndef GE_RECIPE_PS_H_INCLUDED
#define GE_RECIPE_PS_H_INCLUDED

enum gERecipeCategory
{
    gERecipeCategory_Alchemy,
    gERecipeCategory_Cooking,
    gERecipeCategory_Smithing,
    gERecipeCategory_Frying,
    gERecipeCategory_Goldsmith,
    gERecipeCategory_WriteScroll,
    gERecipeCategory_Smith_Forge,
    gERecipeCategory_Smith_Anvil,
    gERecipeCategory_Smith_CoolWeapon,
    gERecipeCategory_Smith_GrindStone,
    gERecipeCategory_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCRecipe_PS'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCRecipe_PS'

class GE_DLLIMPORT gCRecipe_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCRecipe_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual bEResult          PostInitializeProperties( void );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
public: virtual GEBool            IsEditorRelevant( void ) const;
protected:
    GE_DECLARE_ENUMPROP( gERecipeCategory,                m_enumCraft,           Craft )
    GE_DECLARE_PROPERTY( bTObjArray< gCCraftIngredient >, m_arrCraftIngredients, CraftIngredients )
    GE_DECLARE_PROPERTY( bTObjArray< gCSkillValue >,      m_arrRequiredSkills,   RequiredSkills )
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy,           m_ResultItem,          ResultItem )
    GE_DECLARE_PROPERTY( GEU32,                           m_u32ResultAmount,     ResultAmount )
public:
    GEInt           CompareTo( gCRecipe_PS const & ) const;
    bCUnicodeString GetDescription( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCRecipe_PS, 0x0038 )

#pragma warning( pop )

#endif
