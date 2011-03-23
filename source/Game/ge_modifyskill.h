#ifndef GE_MODIFYSKILL_H_INLCUDED
#define GE_MODIFYSKILL_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCModifySkill'

class GE_DLLIMPORT gCModifySkill :
    public gCSkillValue
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCModifySkill( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gESkillModifier > m_enumModifier;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gESkillModifier > &       AccessModifier( void );
    bTPropertyContainer< gESkillModifier > const & GetModifier( void ) const;
    void                                           SetModifier( bTPropertyContainer< gESkillModifier > const & );
public:
    GEBool          operator == ( gCModifySkill const & ) const;
    gCModifySkill & operator =  ( gCModifySkill const & );
public:
    gCModifySkill( gESkill, GEInt, gESkillModifier );
    gCModifySkill( gCModifySkill const & );
    gCModifySkill( void );
};
GE_ASSERT_SIZEOF( gCModifySkill, 0x0018 )

#pragma warning( pop )

#endif
