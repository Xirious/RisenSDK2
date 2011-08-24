#ifndef GE_DAMAGE_PS_H_INCLUDED
#define GE_DAMAGE_PS_H_INCLUDED

enum gEDamageType
{
    gEDamageType_None,
    gEDamageType_Edge,
    gEDamageType_Blunt,
    gEDamageType_Point,
    gEDamageType_Fire,
    gEDamageType_Ice,
    gEDamageType_Magic,
    gEDamageType_Physics,
    gEDamageType_Count,
    gEDamageType_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA GELPCChar const g_ppszDamageTypes[ gEDamageType_Count ];

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCDamage_PS'

class GE_DLLIMPORT gCDamage_PS :
    public eCEntityPropertySet
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCDamage_PS( void );
public: virtual eEPropertySetType          GetPropertySetType( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEDamageType > m_enumDamageType;
    eCEntityProxy                       m_Agressor;
    GEI32                               m_i32DamageBonus;
    GEI32                               m_i32DamageAmount;
    GEFloat                             m_fDamageMultiplier;
    GEInt                               m_iHitBone;
    eCScriptProxyScript                 m_DamageScript;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityProxy &                             AccessAgressor( void );
    GEI32 &                                     AccessDamageAmount( void );
    GEI32 &                                     AccessDamageBonus( void );
    GEFloat &                                   AccessDamageMultiplier( void );
    eCScriptProxyScript &                       AccessDamageScript( void );
    bTPropertyContainer< gEDamageType > &       AccessDamageType( void );
    GEInt &                                     AccessHitBone( void );
    GEBool                                      DoDamage( eCEntity *, eCEntity * );
    GEBool                                      DoDamage( eCEntity * );
    eCEntityProxy const &                       GetAgressor( void ) const;
    GEI32 const &                               GetDamageAmount( void ) const;
    GEI32 const &                               GetDamageBonus( void ) const;
    GEFloat const &                             GetDamageMultiplier( void ) const;
    eCScriptProxyScript const &                 GetDamageScript( void ) const;
    bTPropertyContainer< gEDamageType > const & GetDamageType( void ) const;
    GEInt const &                               GetHitBone( void ) const;
    void                                        SetAgressor( eCEntityProxy const & );
    void                                        SetDamageAmount( GEI32 const & );
    void                                        SetDamageBonus( GEI32 const & );
    void                                        SetDamageMultiplier( GEFloat const & );
    void                                        SetDamageScript( eCScriptProxyScript const & );
    void                                        SetDamageType( bTPropertyContainer< gEDamageType > const & );
    void                                        SetHitBone( GEInt const & );
public:
    gCDamage_PS & operator = ( gCDamage_PS const & );
public:
    gCDamage_PS( gCDamage_PS const & );
    gCDamage_PS( void );
};
GE_ASSERT_SIZEOF( gCDamage_PS, 0x0038 )

#pragma warning( pop )

#endif
