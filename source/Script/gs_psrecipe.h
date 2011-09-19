#ifndef GS_PSRecipe_H_INCLUDED
#define GS_PSRecipe_H_INCLUDED

//NOTE: PSRecipe::PropertyResultQuality has not been declared as script property.
// Only the copy assignment operator is exported (but the other two are missing).

GS_DECLARE_PROPERTYSET( PSRecipe, gCRecipe_PS )
public:
    GS_DECLARE_PROPERTY( Craft,        gERecipeCategory )
    GS_DECLARE_PROPERTY( ResultAmount, GEU32 )
public:
    GEInt   GetIngredientAmount( GEInt ) const;
    GEU32   GetIngredientCount( void ) const;
    Entity  GetIngredientItem( GEInt ) const;
    gESkill GetRequiredSkill( GEInt ) const;
    GEInt   GetRequiredSkillAmount( GEInt ) const;
    GEU32   GetRequiredSkillCount( void ) const;
    Entity  GetResultItem( void ) const;
    GEBool  HasRequiredSkills( Entity & ) const;
    GEBool  IsValid( void ) const;
};

#endif
