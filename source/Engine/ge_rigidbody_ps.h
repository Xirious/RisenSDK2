#ifndef GE_RIGIDBODY_PS_H_INCLUDED
#define GE_RIGIDBODY_PS_H_INCLUDED

enum eERigidbody_Flag
{
    eERigidbody_Flag_NONE            = 0x00000000,
    eERigidbody_Flag_DISABLE_GRAVITY = 0x00000001,  // NX_BF_DISABLE_GRAVITY
    eERigidbody_Flag_FROZEN          = 0x0000007E,  // NX_BF_FROZEN
    eERigidbody_Flag_Kinematic       = 0x00000080,  // NX_BF_KINEMATIC
    eERigidbody_Flag_ForceDWORD      = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCRigidBody_PS'

class GE_DLLIMPORT eCRigidBody_PS :
    public eCRigidBodyBase_PS
{
public:    virtual bCVector     GetPivotVelocity( void ) const;
public:    virtual bCVector     GetPointVelocity( bCVector const & ) const;
public:    virtual bCVector     GetLocalPointVelocity( bCVector const & ) const;
public:    virtual void         AddBodyFlag( eERigidbody_Flag );
public:    virtual void         RemoveBodyFlag( eERigidbody_Flag );
public:    virtual GEBool       ContainsBodyFlag( eERigidbody_Flag ) const;
public:    virtual void         AddActorFlag( eEPhysicObjectFlag );
public:    virtual void         RemoveActorFlag( eEPhysicObjectFlag );
public:    virtual void         EnableMovementControlByAI( GEBool, GEBool, GEBool );
public:    virtual GEBool       IsMovementControledByAI( void ) const;
public:    virtual GEBool       UpdateEntityIfControlledByAI( void ) const;
GE_DECLARE_PROPERTY_OBJECT( eCRigidBody_PS, eCRigidBodyBase_PS )
public:    virtual GEU16        GetVersion( void ) const;
public:    virtual GEBool       OnRead( bCIStream & );
public:    virtual GEBool       OnWrite( bCOStream & );
public:    virtual bEResult     Create( void );
public:    virtual void         Destroy( void );
public:    virtual bEResult     PostInitializeProperties( void );
protected: virtual GEBool       OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
protected: virtual GEBool       IsEntityListener( void ) const;
public:    virtual GEBool       IsPhysicRelevant( void ) const;
public:    virtual GEBool       IsEditorRelevant( void ) const;
protected: virtual void         OnEnterProcessingRange( void );
protected: virtual void         OnExitProcessingRange( void );
public:    virtual void         GetBoundary( bCBox &, GEBool );
protected: virtual void         OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected: virtual GEBool       OnListenEntityEvent( eSEntityListenerEvent const & );
public:    virtual void         StopMotion( void );
public:    virtual void         StopRotation( void );
public:    virtual void         StopMovement( void );
public:    virtual void         SetPosition( bCVector const & );
public:    virtual void         SetPose( bCMatrix const & );
public:    virtual void         SetRotation( bCQuaternion const & );
public:    virtual void         SetRotation( bCMatrix3 const & );
public:    virtual void         SetLinearVelocity( bCVector const & );
public:    virtual void         SetAngularVelocity( bCVector const & );
public:    virtual void         SetLinearMomentum( bCVector const & );
public:    virtual void         SetAngularMomentum( bCVector const & );
public:    virtual bCVector     GetPosition( void ) const;
public:    virtual bCMatrix     GetPose( void ) const;
public:    virtual bCMatrix3    GetRotation( void ) const;
public:    virtual bCQuaternion GetRotationQuat( void ) const;
public:    virtual bCVector     GetLinearVelocity( void ) const;
public:    virtual bCVector     GetAngularVelocity( void ) const;
public:    virtual bCVector     GetLinearMomentum( void ) const;
public:    virtual bCVector     GetAngularMomentum( void ) const;
public:    virtual void         SetMass( GEFloat const & );
public:    virtual GEFloat      GetMass( void ) const;
public:    virtual void         SetCenterOfGravity( bCVector const & );
public:    virtual bCVector     GetCenterOfGravity( void ) const;
public:    virtual void         SetMassSpaceInertiaTensor( bCVector const & );
public:    virtual bCVector     GetMassSpaceInertiaTensor( void ) const;
public:    virtual void         AddForce( bCVector const &, eEForceMode );
public:    virtual void         AddTorque( bCVector const &, eEForceMode );
public:    virtual void         AddRelForce( bCVector const &, eEForceMode );
public:    virtual void         AddRelTorque( bCVector const &, eEForceMode );
public:    virtual void         AddForceAtPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void         AddForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void         AddRelForceAtPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void         AddRelForceAtRelPos( bCVector const &, bCVector const &, eEForceMode );
public:    virtual void         SetGravityEnabled( GEBool );
public:    virtual GEBool       GetGravityEnabled( void ) const;
public:    virtual void         SetIsSleeping( GEBool );
public:    virtual GEBool       GetIsSleeping( void ) const;
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fTotalMass, TotalMass )
    GE_DECLARE_PROPERTY( bCVector, m_vecStartVelocity, StartVelocity )
    GE_DECLARE_PROPERTY( bCVector, m_vecStartAngularVelocity, StartAngularVelocity )
    GE_DECLARE_PROPERTY( bCVector, m_vecStartForce, StartForce )
    GE_DECLARE_PROPERTY( bCVector, m_vecStartTorque, StartTorque )
    GE_DECLARE_PROPERTY( GEFloat, m_fWakeUpCounter, WakeUpCounter )
    GE_DECLARE_PROPERTY( GEFloat, m_fLinearDamping, LinearDamping )
    GE_DECLARE_PROPERTY( GEFloat, m_fAngularDamping, AngularDamping )
    GE_DECLARE_PROPERTY( GEFloat, m_fMaxAngularVelocity, MaxAngularVelocity )
    GE_DECLARE_PROPERTY( bCVector, m_vecMassSpaceInertia, MassSpaceInertia )
    GE_DECLARE_PROPERTY( bCVector, m_vecCenterOfMass, CenterOfMass )
    GE_DECLARE_PROPERTY( GEFloat, m_fCCDMotionTreshold, CCDMotionTreshold )
    GE_DECLARE_ENUMPROP( eERigidbody_Flag, m_enumBodyFlag, BodyFlag )
    char __FIXME[ 0x0108 - 0x007C ];
public:
    GEBool GetMoverGoalReached( void ) const;
    GEBool IsBodyRotationDisabled( void ) const;
    void   SetBodyRotationDisabled( GEBool );
    void   SetFixedStepTranslation( bCVector const & );
    void   SetFixedYStep( GEFloat );
    void   SetMoverGoal( bCVector const &, GEFloat );
protected:
    GEBool       GetIsSleepingToggled( void ) const;
    bCQuaternion GetStepRotation( GEFloat );
    bCVector     GetStepTranslation( GEFloat );
    void         Invalidate( void );
    void         ProcessMovement( void );
    void         SaveStep( void );
    void         SetActor( NxActor * );
    void         SetIsSleepingToggled( GEBool );
};
GE_ASSERT_SIZEOF( eCRigidBody_PS, 0x0108 )

#pragma warning( pop )

#endif
