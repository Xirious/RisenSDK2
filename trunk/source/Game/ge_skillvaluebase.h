#ifndef GE_SKILLVALUEBASE_H_INCLUDED
#define GE_SKILLVALUEBASE_H_INCLUDED

enum gESkill
{
    gESkill_None            = 0xFFFFFFFF,
    gESkill_Atrib_HP        = 0x00000000,
    gESkill_Atrib_MP        = 0x00000001,
    gESkill_Stat_LV         = 0x00000002,
    gESkill_Stat_XP         = 0x00000003,
    gESkill_Stat_LP         = 0x00000004,
    gESkill_Stat_HP         = 0x00000005,
    gESkill_Stat_MP         = 0x00000006,
    gESkill_Stat_STR        = 0x00000007,
    gESkill_Stat_DEX        = 0x00000008,
    gESkill_Stat_INT        = 0x00000009,
    gESkill_Prot_Edge       = 0x0000000A,
    gESkill_Prot_Blunt      = 0x0000000B,
    gESkill_Prot_Point      = 0x0000000C,
    gESkill_Prot_Fire       = 0x0000000D,
    gESkill_Prot_Ice        = 0x0000000E,
    gESkill_Prot_Magic      = 0x0000000F,
    gESkill_Combat_Sword    = 0x00000010,
    gESkill_Combat_Axe      = 0x00000011,
    gESkill_Combat_Staff    = 0x00000012,
    gESkill_Combat_Bow      = 0x00000013,
    gESkill_Combat_CrossBow = 0x00000014,
    gESkill_Magic_Circle    = 0x00000015,
    gESkill_Magic_Fireball  = 0x00000016,
    gESkill_Magic_Frost     = 0x00000017,
    gESkill_Magic_Missile   = 0x00000018,
    gESkill_Misc_Smith      = 0x00000019,
    gESkill_Misc_Mining     = 0x0000001A,
    gESkill_Misc_Lockpick   = 0x0000001B,
    gESkill_Misc_Pickpocket = 0x0000001C,
    gESkill_Misc_Sneak      = 0x0000001D,
    gESkill_Misc_Acrobat    = 0x0000001E,
    gESkill_Misc_Alchemy    = 0x0000001F,
    gESkill_Misc_Scribe     = 0x00000020,
    gESkill_Misc_Trophy     = 0x00000021,
    gESkill_Count           = 0x00000022,
    gESkill_ForceDWORD      = GE_FORCE_DWORD
};

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
