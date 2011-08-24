#ifndef GE_SKILLRANGE_H_INCLUDED
#define GE_SKILLRANGE_H_INCLUDED

class GE_DLLIMPORT gCSkillRange :
    public gCSkillValueBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCSkillRange( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEI32 m_i32MinValue;
    GEI32 m_i32MaxValue;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEI32 &       AccessMaxValue( void );
    GEI32 &       AccessMinValue( void );
    GEI32 const & GetMaxValue( void ) const;
    GEI32 const & GetMinValue( void ) const;
    void          SetMaxValue( GEI32 const & );
    void          SetMinValue( GEI32 const & );
public:
    GEBool         operator == ( gCSkillRange const & ) const;
    gCSkillRange & operator =  ( gCSkillRange const & );
public:
    gCSkillRange( gCSkillRange const & );
    gCSkillRange( gESkill, GEInt, GEInt );
    gCSkillRange( void );
};
GE_ASSERT_SIZEOF( gCSkillRange, 0x0014 )

#endif
