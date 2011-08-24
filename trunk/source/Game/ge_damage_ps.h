#ifndef GE_DAMAGE_PS_H_INCLUDED
#define GE_DAMAGE_PS_H_INCLUDED

enum gEDamageType
{
    gEDamageType_None       = 0x00000000,
    gEDamageType_Edge       = 0x00000001,
    gEDamageType_Blunt      = 0x00000002,
    gEDamageType_Point      = 0x00000003,
    gEDamageType_Fire       = 0x00000004,
    gEDamageType_Ice        = 0x00000005,
    gEDamageType_Magic      = 0x00000006,
    gEDamageType_Physics    = 0x00000007,
    gEDamageType_ForceDWORD = GE_FORCE_DWORD
};

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
