#ifndef GE_SKILLVALUEBASE_H_INCLUDED
#define GE_SKILLVALUEBASE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCSkillValueBase'

class GE_DLLIMPORT gCSkillValueBase :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCSkillValueBase( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gESkill > m_enumSkill;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gESkill > &       AccessSkill( void );
    bTPropertyContainer< gESkill > const & GetSkill( void ) const;
    void                                   SetSkill( bTPropertyContainer< gESkill > const & );
public:
    gCSkillValueBase & operator = ( gCSkillValueBase const & );
public:
    gCSkillValueBase( gCSkillValueBase const & );
    gCSkillValueBase( void );
};
GE_ASSERT_SIZEOF( gCSkillValueBase, 0x000C )

#pragma warning( pop )

#endif
