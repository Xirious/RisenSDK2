#ifndef GE_COMBATMOVE_H_INCLUDED
#define GE_COMBATMOVE_H_INCLUDED

enum gECombatAction
{
    gECombatAction_Attack     = 0x00000001,
    gECombatAction_Parade     = 0x00000002,
    gECombatAction_Stumble    = 0x00000003,
    gECombatAction_ForceDWORD = GE_FORCE_DWORD
};

enum gECombatMove
{
    gECombatMove_None                = 0x00000000,
    gECombatMove_Attack              = 0x00000001,
    gECombatMove_AttackSec           = 0x00000002,
    gECombatMove_Attack3             = 0x00000003,  //FIXME: Ranged Attack?
    gECombatMove_AttackLeft          = 0x00000004,
    gECombatMove_AttackRight         = 0x00000005,
    gECombatMove_StrafeAttackLeft    = 0x00000006,
    gECombatMove_StrafeAttackRight   = 0x00000007,
    gECombatMove_CounterAttack       = 0x00000008,  // StormAttack
    gECombatMove_CounterParade       = 0x00000009,
    gECombatMove_Parade              = 0x0000000A,
    gECombatMove_AttackStumble       = 0x0000000B,
    gECombatMove_AttackStumbleLeft   = 0x0000000C,
    gECombatMove_AttackStumbleRight  = 0x0000000D,
    gECombatMove_ParadeStumble       = 0x0000000E,
    gECombatMove_ParadeStumbleHeavy  = 0x0000000F,
    gECombatMove_Finishing           = 0x00000010,
    gECombatMove_Wait                = 0x00000011,
    gECombatMove_GoTo                = 0x00000012,
    gECombatMove_StormTo             = 0x00000013,
    gECombatMove_GoFwd               = 0x00000014,
    gECombatMove_GoBack              = 0x00000015,
    gECombatMove_GoLeft              = 0x00000016,
    gECombatMove_GoRight             = 0x00000017,
    gECombatMove_JumpBack            = 0x00000018,
    gECombatMove_Stumble             = 0x00000019,
    gECombatMove_StumbleLight        = 0x0000001A,
    gECombatMove_StumbleHeavy        = 0x0000001B,
    gECombatMove_StumbleOverlay      = 0x0000001C,
    gECombatMove_StumbleOverlayLight = 0x0000001D,
    gECombatMove_StumbleOverlayHeavy = 0x0000001E,
    gECombatMove_StumbleBack         = 0x0000001F,
    gECombatMove_StumbleDown         = 0x00000020,
    gECombatMove_StumbleDownBack     = 0x00000021,
    gECombatMove_StumbleDead         = 0x00000022,
    gECombatMove_StumbleDeadBack     = 0x00000023,
    gECombatMove_StrafeLeft          = 0x00000024,
    gECombatMove_StrafeRight         = 0x00000025,
    gECombatMove_Aim                 = 0x00000026,
    gECombatMove_Sniper              = 0x00000027,
    gECombatMove_Reload              = 0x00000028,
    gECombatMove_ForceDWORD          = GE_FORCE_DWORD
};

enum gECombatParadeType
{
    gECombatParadeType_None       = 0x00000000,
    gECombatParadeType_Fist       = 0x00000001,
    gECombatParadeType_Weapon     = 0x00000002,
    gECombatParadeType_Magic      = 0x00000004,
    gECombatParadeType_Ranged     = 0x00000008,
    gECombatParadeType_Monster    = 0x00000010,
    gECombatParadeType_Shield     = 
        gECombatParadeType_Fist |
        gECombatParadeType_Weapon |
        gECombatParadeType_Ranged |
        gECombatParadeType_Monster,
    gECombatParadeType_ForceDWORD = GE_FORCE_DWORD
};

struct gSCombatMoveInstance
{
    //FIXME: gSCombatMoveInstance members.
};

struct gSComboData
{
    //FIXME: gSComboData members.
};

struct gSFAIMoveDesc
{
    //FIXME: gSFAIMoveDesc members.
};

class GE_DLLIMPORT gCCombatMove :
    public gCCombatObject
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatMove( void );
public:    virtual gECombatAction             GetCombatAction( void ) const;
public:    virtual gECombatParadeType         GetParadeType( gCCombatStyle * ) const;
public:    virtual gECombatParadeType         GetAttackType( gCCombatStyle * ) const;
public:    virtual gCCombatMove *             GetMove( gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual eCGeometryEntity *         GetWeapon( gCCombatSystem_PS * ) const;
public:    virtual GEBool                     CanStartComboMove( gSCombatMoveInstance *, gECombatMove ) const;
public:    virtual GEBool                     StartStumble( gSCombatMoveInstance *, gCCombatSystem_PS * );
public:    virtual GEBool                     StartCombo( gSCombatMoveInstance *, gECombatMove );
public:    virtual void                       StopCombo( gSCombatMoveInstance * );
public:    virtual gSCombatMoveInstance *     Start( gCCombatSystem_PS *, gCCombatStyle *, gSComboData * );
public:    virtual void                       Stop( gSCombatMoveInstance * );
public:    virtual void                       Interupt( gSCombatMoveInstance * );
public:    virtual void                       Finish( gSCombatMoveInstance * );
public:    virtual GEBool                     Update( gSCombatMoveInstance * );
public:    virtual GEBool                     IsInParade( gSCombatMoveInstance *, gECombatParadeType, bCVector const & );
public:    virtual GEBool                     IsInAttack( gCCombatSystem_PS *, eCGeometryEntity *, GEFloat & );
public:    virtual GEBool                     IsInteruptable( gSCombatMoveInstance * ) const;
public:    virtual GEFloat                    GetFAIWeight( gCCombatSystem_PS *, gCCombatSystem_PS *, gSFAIMoveDesc &, gSComboData * );
public:    virtual gSComboData *              CreateComboData( gSCombatMoveInstance * );
public:    virtual GEBool                     CanCounterMove( gCCombatSystem_PS *, gCCombatSystem_PS *, gECombatMove ) const;
public:    virtual void                       OnAction( gSAction const &, gSCombatMoveInstance * );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCCombatSpecies * m_pCombatSpecies;
protected:
    GEBool         CanParade( gECombatParadeType, gECombatParadeType ) const;
    gCCombatMove * GetMoveOfStyle( gCCombatSystem_PS *, bCString const &, gECombatMove ) const;
    void           Invalidate( void );
    void           SetCombatSpecies( gCCombatSpecies * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCCombatSpecies * GetCombatSpecies( void ) const;
public:
    gCCombatMove & operator = ( gCCombatMove const & );
public:
    gCCombatMove( gCCombatMove const & );
    gCCombatMove( void );
};
GE_ASSERT_SIZEOF( gCCombatMove, 0x0014 )

#endif
