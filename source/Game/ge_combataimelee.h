#ifndef GE_COMBATAIMELEE_H_INCLUDED
#define GE_COMBATAIMELEE_H_INCLUDED

class GE_DLLIMPORT gCCombatAIMelee :
    public gCCombatAI
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatAIMelee( void );
public:    virtual gECombatMove               SelectNextMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
public:    virtual gECombatMove               SelectComboMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
public:    virtual GEBool                     IsToNear( gCCombatSystem_PS *, GEFloat );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat m_fProbParade;
    GEFloat m_fProbStrafe;
    GEFloat m_fProbAttack;
    GEFloat m_fProbCounterParade;
    GEFloat m_fProbAttackSec;
    GEFloat m_fProbCounterAttack;
    GEFloat m_fProbStormAttack;
    GEFloat m_fProbComboAttack;
    GEFloat m_fProbWait;
    GEFloat m_fProbRestlessly;
    GEFloat m_fProbHoldDistance;
    GEFloat m_fProbMistake;
    GEFloat m_fIntuition;
    GEFloat m_fAttackSpeed;
    GEFloat m_fAggressiveness;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &       AccessAggressiveness( void );
    GEFloat &       AccessAttackSpeed( void );
    GEFloat &       AccessIntuition( void );
    GEFloat &       AccessProbAttack( void );
    GEFloat &       AccessProbAttackSec( void );
    GEFloat &       AccessProbComboAttack( void );
    GEFloat &       AccessProbCounterAttack( void );
    GEFloat &       AccessProbCounterParade( void );
    GEFloat &       AccessProbHoldDistance( void );
    GEFloat &       AccessProbMistake( void );
    GEFloat &       AccessProbParade( void );
    GEFloat &       AccessProbRestlessly( void );
    GEFloat &       AccessProbStormAttack( void );
    GEFloat &       AccessProbStrafe( void );
    GEFloat &       AccessProbWait( void );
    GEFloat const & GetAggressiveness( void ) const;
    GEFloat const & GetAttackSpeed( void ) const;
    GEFloat const & GetIntuition( void ) const;
    GEFloat const & GetProbAttack( void ) const;
    GEFloat const & GetProbAttackSec( void ) const;
    GEFloat const & GetProbComboAttack( void ) const;
    GEFloat const & GetProbCounterAttack( void ) const;
    GEFloat const & GetProbCounterParade( void ) const;
    GEFloat const & GetProbHoldDistance( void ) const;
    GEFloat const & GetProbMistake( void ) const;
    GEFloat const & GetProbParade( void ) const;
    GEFloat const & GetProbRestlessly( void ) const;
    GEFloat const & GetProbStormAttack( void ) const;
    GEFloat const & GetProbStrafe( void ) const;
    GEFloat const & GetProbWait( void ) const;
    void            SetAggressiveness( GEFloat const & );
    void            SetAttackSpeed( GEFloat const & );
    void            SetIntuition( GEFloat const & );
    void            SetProbAttack( GEFloat const & );
    void            SetProbAttackSec( GEFloat const & );
    void            SetProbComboAttack( GEFloat const & );
    void            SetProbCounterAttack( GEFloat const & );
    void            SetProbCounterParade( GEFloat const & );
    void            SetProbHoldDistance( GEFloat const & );
    void            SetProbMistake( GEFloat const & );
    void            SetProbParade( GEFloat const & );
    void            SetProbRestlessly( GEFloat const & );
    void            SetProbStormAttack( GEFloat const & );
    void            SetProbStrafe( GEFloat const & );
    void            SetProbWait( GEFloat const & );
public:
    gCCombatAIMelee & operator = ( gCCombatAIMelee const & );
public:
    gCCombatAIMelee( gCCombatAIMelee const & );
    gCCombatAIMelee( void );
};
GE_ASSERT_SIZEOF( gCCombatAIMelee, 0x006C )

#endif
