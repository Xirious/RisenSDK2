#ifndef GE_COMBATSTYLEMELEE_H_INCLUDED
#define GE_COMBATSTYLEMELEE_H_INCLUDED

class GE_DLLIMPORT gCCombatStyleMelee :
    public gCCombatStyle
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatStyleMelee( void );
public:    virtual gCCombatMove *             GetMove( gECombatMove ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat  m_fHitRange;  // 7C
    bCString m_strAttackSec;  // 80
    bCString m_strAttackLeft;  // 84
    bCString m_strAttackRight;  // 88
    bCString m_strStrafeAttackLeft;  // 8C
    bCString m_strStrafeAttackRight;  // 90
    bCString m_strStormAttack;  // 94
    bCString m_strCounterAttack;  // 98
    bCString m_strCounterParade;  // 9C
    bCString m_strParade;  // A0
    bCString m_strParade1;  // A4
    bCString m_strAttackStumble;  // A8
    bCString m_strAttackStumbleLeft;  // AC
    bCString m_strAttackStumbleRight;  // B0
    bCString m_strParadeStumble;  // B4
    bCString m_strParadeStumbleHeavy;  // B8
    bCString m_strFinishing;  // BC
    bCString m_strMoveStormTo;  // C0
    GEBool   m_bEnableSideAttacks;  // C4
    GEBool   m_bEnableAttackSec;  // C5
    GEBool   m_bEnablePowerRaise;  // C6
             GE_PADDING( 1 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &       AccessAttackLeft( void );
    bCString &       AccessAttackRight( void );
    bCString &       AccessAttackSec( void );
    bCString &       AccessAttackStumble( void );
    bCString &       AccessAttackStumbleLeft( void );
    bCString &       AccessAttackStumbleRight( void );
    bCString &       AccessCounterAttack( void );
    bCString &       AccessCounterParade( void );
    GEBool &         AccessEnableAttackSec( void );
    GEBool &         AccessEnablePowerRaise( void );
    GEBool &         AccessEnableSideAttacks( void );
    bCString &       AccessFinishing( void );
    GEFloat &        AccessHitRange( void );
    bCString &       AccessMoveStormTo( void );
    bCString &       AccessParade( void );
    bCString &       AccessParade1( void );
    bCString &       AccessParadeStumble( void );
    bCString &       AccessParadeStumbleHeavy( void );
    bCString &       AccessStormAttack( void );
    bCString &       AccessStrafeAttackLeft( void );
    bCString &       AccessStrafeAttackRight( void );
    bCString const & GetAttackLeft( void ) const;
    bCString const & GetAttackRight( void ) const;
    bCString const & GetAttackSec( void ) const;
    bCString const & GetAttackStumble( void ) const;
    bCString const & GetAttackStumbleLeft( void ) const;
    bCString const & GetAttackStumbleRight( void ) const;
    bCString const & GetCounterAttack( void ) const;
    bCString const & GetCounterParade( void ) const;
    GEBool const &   GetEnableAttackSec( void ) const;
    GEBool const &   GetEnablePowerRaise( void ) const;
    GEBool const &   GetEnableSideAttacks( void ) const;
    bCString const & GetFinishing( void ) const;
    GEFloat const &  GetHitRange( void ) const;
    bCString const & GetMoveStormTo( void ) const;
    bCString const & GetParade( void ) const;
    bCString const & GetParade1( void ) const;
    bCString const & GetParadeStumble( void ) const;
    bCString const & GetParadeStumbleHeavy( void ) const;
    bCString const & GetStormAttack( void ) const;
    bCString const & GetStrafeAttackLeft( void ) const;
    bCString const & GetStrafeAttackRight( void ) const;
    void             SetAttackLeft( bCString const & );
    void             SetAttackRight( bCString const & );
    void             SetAttackSec( bCString const & );
    void             SetAttackStumble( bCString const & );
    void             SetAttackStumbleLeft( bCString const & );
    void             SetAttackStumbleRight( bCString const & );
    void             SetCounterAttack( bCString const & );
    void             SetCounterParade( bCString const & );
    void             SetEnableAttackSec( GEBool const & );
    void             SetEnablePowerRaise( GEBool const & );
    void             SetEnableSideAttacks( GEBool const & );
    void             SetFinishing( bCString const & );
    void             SetHitRange( GEFloat const & );
    void             SetMoveStormTo( bCString const & );
    void             SetParade( bCString const & );
    void             SetParade1( bCString const & );
    void             SetParadeStumble( bCString const & );
    void             SetParadeStumbleHeavy( bCString const & );
    void             SetStormAttack( bCString const & );
    void             SetStrafeAttackLeft( bCString const & );
    void             SetStrafeAttackRight( bCString const & );
public:
    gCCombatStyleMelee & operator = ( gCCombatStyleMelee const & );
public:
    gCCombatStyleMelee( gCCombatStyleMelee const & );
    gCCombatStyleMelee( void );
};
GE_ASSERT_SIZEOF( gCCombatStyleMelee, 0x00C8 )

#endif
