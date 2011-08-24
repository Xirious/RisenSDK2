#ifndef GE_COMBATSTYLEANIPOSE_H_INCLUDED
#define GE_COMBATSTYLEANIPOSE_H_INCLUDED

enum gECombatPose
{
    gECombatPose_P0,
    gECombatPose_P1,
    gECombatPose_P2,
    gECombatPose_Count,
    gECombatPose_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA bCString const g_pstrPoseString[ gECombatPose_Count ];

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCombatStyleAniPose'

class GE_DLLIMPORT gCCombatStyleAniPose :
    public gCCombatWeaponConfig
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~gCCombatStyleAniPose( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gECombatPose > m_enumPose;
    bCString                            m_strFallbackStyle;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                                  AccessFallbackStyle( void );
    bTPropertyContainer< gECombatPose > &       AccessPose( void );
    bCString const &                            GetFallbackStyle( void ) const;
    bTPropertyContainer< gECombatPose > const & GetPose( void ) const;
    void                                        SetFallbackStyle( bCString const & );
    void                                        SetPose( bTPropertyContainer< gECombatPose > const & );
public:
    GEBool                 operator == ( gCCombatStyleAniPose const & ) const;
    gCCombatStyleAniPose & operator =  ( gCCombatStyleAniPose const & );
public:
    gCCombatStyleAniPose( gCCombatStyleAniPose const & );
    gCCombatStyleAniPose( void );
};
GE_ASSERT_SIZEOF( gCCombatStyleAniPose, 0x0020 )

#pragma warning( pop )

#endif
