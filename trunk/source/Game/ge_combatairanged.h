#ifndef GE_COMBATAIRANGED_H_INCLUDED
#define GE_COMBATAIRANGED_H_INCLUDED

class GE_DLLIMPORT gCCombatAIRanged :
    public gCCombatAI
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatAIRanged( void );
public:    virtual gECombatMove               SelectNextMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
public:    virtual gECombatMove               SelectComboMove( gCCombatSystem_PS *, eCGeometryEntity *, gECombatMove );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat m_fProbAttack;
    GEFloat m_fProbComboAttack;
    GEFloat m_fProbWait;
    GEFloat m_fProbRestlessly;
    GEFloat m_fProbHoldDistance;
    GEFloat m_fAttackSpeed;
    GEFloat m_fPrecision;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &       AccessAttackSpeed( void );
    GEFloat &       AccessPrecision( void );
    GEFloat &       AccessProbAttack( void );
    GEFloat &       AccessProbComboAttack( void );
    GEFloat &       AccessProbHoldDistance( void );
    GEFloat &       AccessProbRestlessly( void );
    GEFloat &       AccessProbWait( void );
    GEFloat const & GetAttackSpeed( void ) const;
    GEFloat const & GetPrecision( void ) const;
    GEFloat const & GetProbAttack( void ) const;
    GEFloat const & GetProbComboAttack( void ) const;
    GEFloat const & GetProbHoldDistance( void ) const;
    GEFloat const & GetProbRestlessly( void ) const;
    GEFloat const & GetProbWait( void ) const;
    void            SetAttackSpeed( GEFloat const & );
    void            SetPrecision( GEFloat const & );
    void            SetProbAttack( GEFloat const & );
    void            SetProbComboAttack( GEFloat const & );
    void            SetProbHoldDistance( GEFloat const & );
    void            SetProbRestlessly( GEFloat const & );
    void            SetProbWait( GEFloat const & );
public:
    gCCombatAIRanged & operator = ( gCCombatAIRanged const & );
public:
    gCCombatAIRanged( gCCombatAIRanged const & );
    gCCombatAIRanged( void );
};
GE_ASSERT_SIZEOF( gCCombatAIRanged, 0x004C )

#endif
