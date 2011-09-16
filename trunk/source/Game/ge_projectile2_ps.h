#ifndef GE_PROJECTILE2_PS_H_INCLUDED
#define GE_PROJECTILE2_PS_H_INCLUDED

enum gEFlightPathType
{
    gEFlightPathType_Ballistic,
    gEFlightPathType_Seeking,
    gEFlightPathType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCProjectile2_PS'
                                   // class 'gCProjectile2_PS::CProcessor' needs to have dll-interface to be used by clients of class 'gCProjectile2_PS'

class GE_DLLIMPORT gCProjectile2_PS :
    public eCEntityPropertySet
{
public:
    struct gSHitInfo
    {
        eCEntity * __FIXME_0000;
        bCVector   __FIXME_0004;
        int        __FIXME_0010;
        bCVector   __FIXME_0014;
        GEFloat    __FIXME_0020;
        GEU32      __FIXME_0024;
    };
    GE_ASSERT_SIZEOF( gSHitInfo, 0x0028 )
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCProjectile2_PS * m_pProjectilePS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( gCProjectile2_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
public:    virtual bEResult          PostInitializeProperties( void );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsReferencedByTemplate( void ) const;
public:    virtual void              GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void              OnEnterProcessingRange( void );
protected: virtual void              OnExitProcessingRange( void );
protected: virtual void              OnProcess( void );
protected:
    GE_DECLARE_PROPERTY( GEFloat,               m_fStartVelocity,      StartVelocity )
    GE_DECLARE_PROPERTY( GEFloat,               m_fPivotOffset,        PivotOffset )
    GE_DECLARE_PROPERTY( GEFloat,               m_fPivotStuckOffset,   PivotStuckOffset )
    GE_DECLARE_ENUMPROP( gEFlightPathType,      m_enumFlightPathType,  FlightPathType )
    GE_DECLARE_PROPERTY( gCFlightPathBallistic, m_FlightPathBallistic, FlightPathBallistic )
    GE_DECLARE_PROPERTY( gCFlightPathSeeking,   m_FlightPathSeeking,   FlightPathSeeking )
    GE_DECLARE_PROPERTY( GEBool,                m_bEnableSweepTest,    EnableSweepTest )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,               m_fSweepTestRadius,    SweepTestRadius )
    GE_DECLARE_PROPERTY( bCString,              m_strShootEffect,      ShootEffect )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,   m_ShootScript,         ShootScript )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,   m_OnIntersectScript,   OnIntersectScript )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,   m_OnHitScript,         OnHitScript )
    GE_DECLARE_PROPERTY( GEFloat,               m_fDistanceToImpact,   DistanceToImpact )
    GE_DECLARE_PROPERTY( GEBool,                m_bEnableSpining,      EnableSpining )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCVector,              m_vecSpiningSpeed,     SpiningSpeed )
    CProcessor                                  m_Processor;
    char __FIXME[ 0x0118 - 0x0088 ];
public:
    GEBool             AttachToBone( eCEntity *, gSHitInfo * );
    void               CallHitScript( gSHitInfo & );
    GEBool             CheckFlightPath( bCVector const &, bCVector const & );
    GEBool             CheckFlightPathSweep( bCVector const &, bCVector const & );
    void               Deactivate( void );
    void               FillHitInfoFromIterator( gSHitInfo &, bCUnitedRay & );
    GEBool             FindPointOfImpact( bCVector &, bCVector const &, bCVector const & );
    gCFlightPathBase * GetFlightPath( void ) const;
    eEShapeMaterial    GetPhysicsMaterial( bCVector const &, bCVector const &, eCEntity const * ) const;
    eCEntity *         GetShooter( void );
    eCEntity const *   GetShooter( void ) const;
    bCVector const &   GetVelocity( void ) const;
    GEBool             IsActive( void ) const;
    void               SetShooter( eCEntity * );
    void               SetVelocity( bCVector const & );
    void               Shoot( eCEntity * );
protected:
    static GEFloat const s_fTimeStep;
protected:
    void   Invalidate( void );
    GEBool ProcessSubStep( void );
};
GE_ASSERT_SIZEOF( gCProjectile2_PS, 0x0118 )

#pragma warning( pop )

#endif
