#ifndef GE_COMBATWEAPONCONFIG_H_INCLUDED
#define GE_COMBATWEAPONCONFIG_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatWeaponConfig'

class GE_DLLIMPORT gCCombatWeaponConfig :
    public bCObjectBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCCombatWeaponConfig( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEItemUseType > m_enumLeftUseType;
    bTPropertyContainer< gEItemUseType > m_enumRightUseType;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEItemUseType > &       AccessLeftUseType( void );
    bTPropertyContainer< gEItemUseType > &       AccessRightUseType( void );
    bTPropertyContainer< gEItemUseType > const & GetLeftUseType( void ) const;
    bTPropertyContainer< gEItemUseType > const & GetRightUseType( void ) const;
    void                                         SetLeftUseType( bTPropertyContainer< gEItemUseType > const & );
    void                                         SetRightUseType( bTPropertyContainer< gEItemUseType > const & );
public:
    GEBool                 operator == ( gCCombatWeaponConfig const & ) const;
    gCCombatWeaponConfig & operator =  ( gCCombatWeaponConfig const & );
public:
    gCCombatWeaponConfig( gEItemUseType, gEItemUseType );
    gCCombatWeaponConfig( gCCombatWeaponConfig const & );
    gCCombatWeaponConfig( void );
};
GE_ASSERT_SIZEOF( gCCombatWeaponConfig, 0x0014 )

#pragma warning( pop )

#endif
