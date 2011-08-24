#ifndef GS_PSDAMAGE_H_INCLUDED
#define GS_PSDAMAGE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSDamage, gCDamage_PS )
public:
    GS_DECLARE_PROPERTY( DamageAmount,     GEI32 )
    GS_DECLARE_PROPERTY( DamageBonus,      GEI32 )
    GS_DECLARE_PROPERTY( DamageMultiplier, GEFloat )
    GS_DECLARE_PROPERTY( DamageType,       gEDamageType )
    GS_DECLARE_PROPERTY( HitBone,          GEInt )
public:
    GEBool DoDamage( Entity &, Entity & );
    GEBool DoDamage( Entity & );
    Entity GetAgressor( void );
    GEBool IsValid( void ) const;
};

#endif
