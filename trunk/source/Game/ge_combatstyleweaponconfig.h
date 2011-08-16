#ifndef GE_COMBATSTYLEWEAPONCONFIG_H_INCLUDED
#define GE_COMBATSTYLEWEAPONCONFIG_H_INCLUDED

class GE_DLLIMPORT gCCombatStyleWeaponConfig :
    public gCCombatWeaponConfig
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCCombatStyleWeaponConfig( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCSkillValue m_RequiredSkill;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCSkillValue &       AccessRequiredSkill( void );
    gCSkillValue const & GetRequiredSkill( void ) const;
    void                 SetRequiredSkill( gCSkillValue const & );
public:
    GEBool                      operator == ( gCCombatStyleWeaponConfig const & ) const;
    gCCombatStyleWeaponConfig & operator =  ( gCCombatStyleWeaponConfig const & );
public:
    gCCombatStyleWeaponConfig( gCCombatStyleWeaponConfig const & );
    gCCombatStyleWeaponConfig( void );
};
GE_ASSERT_SIZEOF( gCCombatStyleWeaponConfig, 0x0024 )

#endif
