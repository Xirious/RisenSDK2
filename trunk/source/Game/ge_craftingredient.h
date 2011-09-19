#ifndef GE_CRAFTINGREDIENT_H_INCLUDED
#define GE_CRAFTINGREDIENT_H_INCLUDED

class GE_DLLIMPORT gCCraftIngredient :
    public bCObjectBase
{
GE_DECLARE_PROPERTY_OBJECT( gCCraftIngredient, bCObjectBase )
public: virtual ~gCCraftIngredient( void );
protected:
    GE_DECLARE_PROPERTY( eCTemplateEntityProxy, m_ItemTemplate,  ItemTemplate )
    GE_DECLARE_PROPERTY( GEU32,                 m_u32ItemAmount, ItemAmount )
public:
    GEBool operator == ( gCCraftIngredient const & ) const;
};
GE_ASSERT_SIZEOF( gCCraftIngredient, 0x000C )

#endif
