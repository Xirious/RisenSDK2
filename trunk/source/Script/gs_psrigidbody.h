#ifndef GS_PSRIGIDBODY_H_INCLUDED
#define GS_PSRIGIDBODY_H_INCLUDED

GS_DECLARE_PROPERTYSET( PSRigidBody, eCRigidBody_PS )
public:
    GS_DECLARE_PROPERTY( AngularDamping, GEFloat )
    GS_DECLARE_PROPERTY( BodyFlag,       eERigidbody_Flag )
    GS_DECLARE_PROPERTY( LinearDamping,  GEFloat )
public:
    void     AddActorFlag( eEPhysicObjectFlag );
    void     AddBodyFlag( eERigidbody_Flag );
    void     AddForce( bCVector const & );
    void     EnableControlByAI( GEBool );
    void     EnableGraivity( GEBool );
    bCVector GetPivotVelocity( void ) const;
    GEBool   HasHoverGoalReached( void ) const;
    void     HoverTo( bCVector const &, GEFloat );
    GEBool   IsValid( void ) const;
    void     RemoveActorFlag( eEPhysicObjectFlag );
    void     RemoveBodyFlag( eERigidbody_Flag );
    void     SetAngularVelocity( bCVector const & );
    void     SetIsSleeping( GEBool );
    void     SetLinearVelocity( bCVector const & );
    void     SetPose( bCMatrix );
    void     SetPosition( bCVector );
    void     SetRotation( bCQuaternion );
};

#endif
