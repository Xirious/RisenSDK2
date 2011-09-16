#ifndef GS_PSPROJECTILE_H_INCLUDED
#define GS_PSPROJECTILE_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSProjectile, gCProjectile2_PS )
public:
    GS_DECLARE_PROPERTY( BallisticDeactivationVelocity, GEFloat )
    GS_DECLARE_PROPERTY( BallisticGravity,              GEFloat )
    GS_DECLARE_PROPERTY( BallisticVelocityLoss,         GEFloat )
    GS_DECLARE_PROPERTY( DistanceToImpact,              GEFloat )
    GS_DECLARE_PROPERTY( FlightPathType,                gEFlightPathType )
    GS_DECLARE_PROPERTY( OnHitScript,                   eCScriptProxyScript )
    GS_DECLARE_PROPERTY( OnIntersectScript,             eCScriptProxyScript )
    GS_DECLARE_PROPERTY( PivotOffset,                   GEFloat )
    GS_DECLARE_PROPERTY( PivotStuckOffset,              GEFloat )
    GS_DECLARE_PROPERTY( ShootScript,                   eCScriptProxyScript )
    GS_DECLARE_PROPERTY( StartVelocity,                 GEFloat )
public:
    GEBool          AttachToBone( Entity &, GEInt ) const;
    GEBool          CheckFlightPath( bCVector const & ) const;
    GEBool          CheckFlightPath( bCVector const &, bCVector const & ) const;
    void            Deactivate( void );
    bCVector        FindPointOfImpact( bCVector const &, bCVector const & ) const;
    GEInt           GetBoneIndex( GEInt ) const;
    GEFloat         GetHitAngle( GEInt ) const;
    eEShapeMaterial GetMaterial( GEInt ) const;
    bCVector        GetPointOfImpact( GEInt ) const;
    GEBool          GetShootDirection( bCVector &, Entity const &, bCVector const &, GEFloat, GEFloat );
    GEBool          GetShootDirection( bCVector &, Entity const &, GEFloat, GEFloat );
    Entity          GetShooter( void ) const;
    bCVector        GetSurfaceNormal( GEInt ) const;
    Entity          GetTarget( void ) const;
    bCVector        GetVelocity( void ) const;
    GEBool          IsActive( void ) const;
    GEBool          IsValid( void ) const;
    bCVector        MoveToPointOfImpact( GEInt, GEBool );
    void            SetShooter( Entity const & );
    void            SetTarget( Entity const & );
    void            SetVelocity( bCVector const & );
    void            Shoot( Entity & );
};

#endif
