#ifndef GE_RIGIDBODYBASE_PS_H_INCLUDED
#define GE_RIGIDBODYBASE_PS_H_INCLUDED

class GE_DLLIMPORT eCRigidBodyBase_PS :
    public eCEntityPropertySet
{
public:    virtual void              StopMotion( void );
public:    virtual void              StopRotation( void );
public:    virtual void              StopMovement( void );
public:    virtual void              SetPosition( bCVector const & );
public:    virtual void              SetPose( bCMatrix const & );
public:    virtual void              SetRotation( bCMatrix3 const & );
public:    virtual void              SetRotation( bCQuaternion const & );
public:    virtual void              SetLinearVelocity( bCVector const & );
public:    virtual void              SetAngularVelocity( bCVector const & );
public:    virtual void              SetLinearMomentum( bCVector const & );
public:    virtual void              SetAngularMomentum( bCVector const & );
public:    virtual bCVector          GetPosition( void ) const;
public:    virtual bCMatrix          GetPose( void ) const;
public:    virtual bCMatrix3         GetRotation( void ) const;
public:    virtual bCQuaternion      GetRotationQuat( void ) const;
public:    virtual bCVector          GetLinearVelocity( void ) const;
public:    virtual bCVector          GetAngularVelocity( void ) const;
public:    virtual bCVector          GetLinearMomentum( void ) const;
public:    virtual bCVector          GetAngularMomentum( void ) const;
public:    virtual void              SetMass( GEFloat const & );
public:    virtual GEFloat           GetMass( void ) const;
public:    virtual void              SetCenterOfGravity( bCVector const & );
public:    virtual bCVector          GetCenterOfGravity( void ) const;
public:    virtual void              SetMassSpaceInertiaTensor( bCVector const & );
public:    virtual bCVector          GetMassSpaceInertiaTensor( void ) const;
public:    virtual void              AddForce( bCVector const &, eEForceMode );
public:    virtual void              AddTorque( bCVector const &, eEForceMode );
public:    virtual void              AddRelForce( bCVector const &, eEForceMode );
public:    virtual void              AddRelTorque( bCVector const &, eEForceMode );
public:    virtual void              AddForceAtPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void              AddForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void              AddRelForceAtPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void              AddRelForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void              SetGravityEnabled( GEBool );
public:    virtual GEBool            GetGravityEnabled( void ) const;
public:    virtual void              SetIsSleeping( GEBool );
public:    virtual GEBool            GetIsSleeping( void ) const;
GE_DECLARE_PROPERTY_OBJECT( eCRigidBodyBase_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
public:    virtual bEResult          PostInitializeProperties( void );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsEditorRelevant( void ) const;
protected: virtual void              OnProcess( void );
protected:
    GE_DECLARE_PROPERTY( GEBool, m_bPhysicsEnabled, PhysicsEnabled )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCRigidBodyBase_PS, 0x0014 )

#endif
