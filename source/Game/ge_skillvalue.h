#ifndef GE_SKILLVALUE_H_INCLUDED
#define GE_SKILLVALUE_H_INCLUDED

class GE_DLLIMPORT gCSkillValue :
    public gCSkillValueBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCSkillValue( void );

private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEI32 m_i32Amount;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEI32 &       AccessAmount( void );
    GEI32 const & GetAmount( void ) const;
    void          SetAmount( GEI32 const & );
public:
    GEBool         operator == ( gCSkillValue const & ) const;
    gCSkillValue & operator =  ( gCSkillValue const & );
public:
    gCSkillValue( gESkill, GEInt );
    gCSkillValue( gCSkillValue const & );
    gCSkillValue( void );
};
GE_ASSERT_SIZEOF( gCSkillValue, 0x0010 )

#endif
