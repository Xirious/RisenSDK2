#ifndef GS_PSSKILLS_H_INCLUDED
#define GS_PSSKILLS_H_INCLUDED

class PSSkills
{
protected:
    eCEntity * m_pEngineEntity;
public:
    GEInt           GetAcrobat( void ) const;;
    GEInt           GetAlchemy( void ) const;
    GEInt           GetBase( gESkill ) const;
    gESkillCategroy GetCategory( gESkill ) const;;
    GEInt           GetCircle( void ) const;
    GEInt           GetCombatAxe( void ) const;
    GEInt           GetCombatBow( void ) const;
    GEInt           GetCombatCrossBow( void ) const;
    GEInt           GetCombatStaff( void ) const;
    GEInt           GetCombatSword( void ) const;
    GEInt           GetDefault( gESkill ) const;
    bCUnicodeString GetDescription( gESkill ) const;;
    GEInt           GetDexterity( void ) const;
    GEInt           GetExperience( void ) const;
    GEInt           GetFireball( void ) const;
    GEInt           GetFrost( void ) const;
    GEInt           GetHitPoints( void ) const;
    GEInt           GetHitPointsMax( void ) const;
    GEInt           GetHitPointsPercent( void ) const;
    GEInt           GetIntelligence( void ) const;
    GEInt           GetLearnPoints( void ) const;
    GEInt           GetLevel( void ) const;
    GEInt           GetLockpick( void ) const;
    GEInt           GetManaPoints( void ) const;
    GEInt           GetManaPointsMax( void ) const;
    GEInt           GetManaPointsPercent( void ) const;
    GEInt           GetMaximum( gESkill ) const;
    GEInt           GetMinimum( gESkill ) const;
    GEInt           GetMining( void ) const;
    GEInt           GetMissile( void ) const;
    GEInt           GetModification( gESkill ) const;
    bCUnicodeString GetName( gESkill ) const;
    GEInt           GetPickpocket( void ) const;
    GEInt           GetProtBlunt( void ) const;
    GEInt           GetProtEdge( void ) const;
    GEInt           GetProtFire( void ) const;
    GEInt           GetProtIce( void ) const;
    GEInt           GetProtMagic( void ) const;
    GEInt           GetProtPoint( void ) const;
    GEInt           GetProtection( gEDamageType );
    bCUnicodeString GetRequirement( gESkill ) const;
    GEInt           GetScribe( void ) const;
    GEInt           GetSmith( void ) const;
    GEInt           GetSneak( void ) const;
    GEU8            GetSortOrder( gESkill ) const;
    GEInt           GetStrength( void ) const;
    bCString        GetTag( gESkill ) const;
    GEInt           GetTotal( gESkill ) const;
    GEInt           GetTrophy( void ) const;
    GEBool          IsValid( void ) const;
    void            SetAcrobat( GEInt, gESkillModifier );
    void            SetAlchemy( GEInt, gESkillModifier );
    void            SetBase( gESkill, GEInt, gESkillModifier );
    void            SetCircle( GEInt, gESkillModifier );
    void            SetCombatAxe( GEInt, gESkillModifier );
    void            SetCombatBow( GEInt, gESkillModifier );
    void            SetCombatCrossBow( GEInt, gESkillModifier );
    void            SetCombatStaff( GEInt, gESkillModifier );
    void            SetCombatSword( GEInt, gESkillModifier );
    void            SetDexterity( GEInt, gESkillModifier );
    void            SetExperience( GEInt, gESkillModifier );
    void            SetFireball( GEInt, gESkillModifier );
    void            SetFrost( GEInt, gESkillModifier );
    void            SetHitPoints( GEInt, gESkillModifier );
    void            SetHitPointsMax( GEInt, gESkillModifier );
    void            SetIntelligence( GEInt, gESkillModifier );
    void            SetLearnPoints( GEInt, gESkillModifier );
    void            SetLevel( GEInt, gESkillModifier );
    void            SetLockpick( GEInt, gESkillModifier );
    void            SetManaPoints( GEInt, gESkillModifier );
    void            SetManaPointsMax( GEInt, gESkillModifier );
    void            SetMining( GEInt, gESkillModifier );
    void            SetMissile( GEInt, gESkillModifier );
    void            SetModification( gESkill, GEInt, gESkillModifier );
    void            SetPickpocket( GEInt, gESkillModifier );
    void            SetProtBlunt( GEInt, gESkillModifier );
    void            SetProtEdge( GEInt, gESkillModifier );
    void            SetProtFire( GEInt, gESkillModifier );
    void            SetProtIce( GEInt, gESkillModifier );
    void            SetProtMagic( GEInt, gESkillModifier );
    void            SetProtPoint( GEInt, gESkillModifier );
    void            SetScribe( GEInt, gESkillModifier );
    void            SetSmith( GEInt, gESkillModifier );
    void            SetSneak( GEInt, gESkillModifier );
    void            SetStrength( GEInt, gESkillModifier );
    void            SetTrophy( GEInt, gESkillModifier );
/** ///FIXME: class gCSkills_PS.
public:
    gCSkills_PS const * operator -> ( void ) const;
protected:
                  operator gCSkills_PS *       ( void );
                  operator gCSkills_PS const * ( void ) const;
    gCSkills_PS * operator ->                  ( void );
/**/
/** ///FIXME: PSSkills assignment operator seems to be buggy (only one byte is copied).
public:
    PSSkills & operator = ( PSSkills const & );
/**/
};

#endif
