#ifndef GE_COMBATSTYLE_H_INCLUDED
#define GE_COMBATSTYLE_H_INCLUDED

enum gECombatMode
{
    gECombatMode_None       = 0x00000000,
    gECombatMode_Carry      = 0x00000001,
    gECombatMode_Melee      = 0x00000002,
    gECombatMode_Ranged     = 0x00000003,
    gECombatMode_Magic      = 0x00000004,
    gECombatMode_Cast       = 0x00000005,
    gECombatMode_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCCombatStyle'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatStyle'

class GE_DLLIMPORT gCCombatStyle :
    public gCCombatObject
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCCombatStyle( void );
public:    virtual gCCombatMove *             GetMove( gECombatMove ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCString                                  m_strAttack;
    bTObjArray< gCCombatStyleWeaponConfig >   m_arrWeaponConfigs;
    bTPropertyContainer< gECombatParadeType > m_enumParadeType;
    bTPropertyContainer< gECombatParadeType > m_enumAttackType;
    bCString                                  m_strActiveFightAI;
    bCString                                  m_strPassiveFightAI;
    gCCombatStyleAniPose                      m_AniPose;
    bTPropertyContainer< gECombatMode >       m_enumCombatMode;
    bCString                                  m_strMoveGoTo;
    bCString                                  m_strMoveGoFwd;
    bCString                                  m_strMoveGoBack;
    bCString                                  m_strMoveGoLeft;
    bCString                                  m_strMoveGoRight;
    bCString                                  m_strMoveWait;
    gCCombatSpecies *                         m_pCombatSpecies;
protected:
    void Invalidate( void );
    void SetCombatSpecies( gCCombatSpecies * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                        AccessActiveFightAI( void );
    gCCombatStyleAniPose &                            AccessAniPose( void );
    bCString &                                        AccessAttack( void );
    bTPropertyContainer< gECombatParadeType > &       AccessAttackType( void );
    bTPropertyContainer< gECombatMode > &             AccessCombatMode( void );
    bCString &                                        AccessMoveGoBack( void );
    bCString &                                        AccessMoveGoFwd( void );
    bCString &                                        AccessMoveGoLeft( void );
    bCString &                                        AccessMoveGoRight( void );
    bCString &                                        AccessMoveGoTo( void );
    bCString &                                        AccessMoveWait( void );
    bTPropertyContainer< gECombatParadeType > &       AccessParadeType( void );
    bCString &                                        AccessPassiveFightAI( void );
    bTObjArray< gCCombatStyleWeaponConfig > &         AccessWeaponConfigs( void );
    bCString const &                                  GetActiveFightAI( void ) const;
    gCCombatStyleAniPose const &                      GetAniPose( void ) const;
    bCString const &                                  GetAttack( void ) const;
    bTPropertyContainer< gECombatParadeType > const & GetAttackType( void ) const;
    bTPropertyContainer< gECombatMode > const &       GetCombatMode( void ) const;
    gCCombatSpecies *                                 GetCombatSpecies( void ) const;
    bCString const &                                  GetMoveGoBack( void ) const;
    bCString const &                                  GetMoveGoFwd( void ) const;
    bCString const &                                  GetMoveGoLeft( void ) const;
    bCString const &                                  GetMoveGoRight( void ) const;
    bCString const &                                  GetMoveGoTo( void ) const;
    bCString const &                                  GetMoveWait( void ) const;
    bTPropertyContainer< gECombatParadeType > const & GetParadeType( void ) const;
    bCString const &                                  GetPassiveFightAI( void ) const;
    gCCombatStyleWeaponConfig const *                 GetValidWeaponConfig( gCCombatWeaponConfig const &, gCSkills_PS * ) const;
    bTObjArray< gCCombatStyleWeaponConfig > const &   GetWeaponConfigs( void ) const;
    void                                              SetActiveFightAI( bCString const & );
    void                                              SetAniPose( gCCombatStyleAniPose const & );
    void                                              SetAttack( bCString const & );
    void                                              SetAttackType( bTPropertyContainer< gECombatParadeType > const & );
    void                                              SetCombatMode( bTPropertyContainer< gECombatMode > const & );
    void                                              SetMoveGoBack( bCString const & );
    void                                              SetMoveGoFwd( bCString const & );
    void                                              SetMoveGoLeft( bCString const & );
    void                                              SetMoveGoRight( bCString const & );
    void                                              SetMoveGoTo( bCString const & );
    void                                              SetMoveWait( bCString const & );
    void                                              SetParadeType( bTPropertyContainer< gECombatParadeType > const & );
    void                                              SetPassiveFightAI( bCString const & );
    void                                              SetWeaponConfigs( bTObjArray< gCCombatStyleWeaponConfig > const & );
public:
    gCCombatStyle & operator = ( gCCombatStyle const & );
public:
    gCCombatStyle( gCCombatStyle const & );
    gCCombatStyle( void );
};
GE_ASSERT_SIZEOF( gCCombatStyle, 0x007C )

#pragma warning( pop )

#endif
