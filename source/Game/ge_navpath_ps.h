#ifndef GE_NAVPATH_PS_H_INCLUDED
#define GE_NAVPATH_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCNavPath_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCNavPath_PS'

class GE_DLLIMPORT gCNavPath_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCNavPath_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
public:    virtual bEResult          PostInitializeProperties( void );
protected: virtual GEBool            HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
protected: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                  ~gCNavPath_PS( void );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsReferencedByTemplate( void ) const;
public:    virtual GEBool            IsEntityListener( void ) const;
protected: virtual void              OnTouch( eCEntity *, eCContactIterator & );
protected: virtual void              OnIntersect( eCEntity *, eCContactIterator & );
protected: virtual void              OnUntouch( eCEntity *, eCContactIterator & );
public:    virtual void              GetBoundary( bCBox &, GEBool );
public:    virtual void              OnPostRead( void );
public:    virtual GEBool            OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_PROPERTY( bTValArray< bCVector >, m_arrPoint,                    Point )
    GE_DECLARE_PROPERTY( bTValArray< GEFloat >,  m_arrRadius,                   Radius )
    GE_DECLARE_PROPERTY( GEBool,                 m_bUnlimitedHeight,            UnlimitedHeight )
    GE_DECLARE_PROPERTY( GEBool,                 m_bOnlyPlayerAsTarget,         OnlyPlayerAsTarget )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( eCEntityProxy,          m_ZoneAEntityProxy,            ZoneAEntityProxy )
    GE_DECLARE_PROPERTY( eCEntityProxy,          m_ZoneBEntityProxy,            ZoneBEntityProxy )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneAIntersectionMargin1, ZoneAIntersectionMargin1 )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneAIntersectionMargin2, ZoneAIntersectionMargin2 )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneAIntersectionCenter,  ZoneAIntersectionCenter )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneBIntersectionMargin1, ZoneBIntersectionMargin1 )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneBIntersectionMargin2, ZoneBIntersectionMargin2 )
    GE_DECLARE_PROPERTY( bCVector,               m_vecZoneBIntersectionCenter,  ZoneBIntersectionCenter )
    GE_DECLARE_PROPERTY( GEFloat,                m_fCostFactor,                 CostFactor )
    GE_DECLARE_PROPERTY( GEFloat,                m_fTopToleranz,                TopToleranz )
    GE_DECLARE_PROPERTY( GEFloat,                m_fBottomToleranz,             BottomToleranz )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerArea,              LinkInnerArea )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerTopArea,           LinkInnerTopArea )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerBottomArea,        LinkInnerBottomArea )
    GE_PADDING1( 1 )
    GE_DECLARE_ENUMPROP( gENavTestResult,        m_enumNavTestResult,           NavTestResult )
    char __FIXME[ 0x0120 - 0x009C ];
public:
    GEFloat            CalcAbsHeightDiffFlagAndPrioFlag( bCVector const &, GEBool &, GEBool & );
    bCVector           CalcNearestPathPoint( bCVector const & );
    bEResult           CalcPathHeights( void );
    bEResult           DeregisterDCCPS( gCDynamicCollisionCircle_PS * );
    GEFloat            GetCosts( bCVector const &, bCVector const & ) const;
    GEFloat            GetCosts( void ) const;
    eCEntity *         GetDoorEntity( void );
    bCDateTime const & GetLastModificationTime( void ) const;
    GEU32              GetNetIndex( void );
    GEBool             GetOpenStatus( void ) const;
    GEFloat            GetPathBottomHeight( void );
    GEFloat            GetPathTopHeight( void );
    GEBool             HasOpenWay( bCVector const &, bCVector const & );
    GEBool             IsPathIllegal( GEBool ) const;
    bEResult           RegisterDCCPS( gCDynamicCollisionCircle_PS * );
    void               SetDoorEntity( eCEntity *, bCVector const & );
    void               SetNetIndex( GEU32 );
    void               SetOpenStatus( GEBool );
    GEBool             Test3DPointOnPath( bCVector const &, GEInt *, GEFloat * );
    GEBool             TestPointAgainstDCCs( bCVector const &, eCEntity const & );
    GEBool             TestSegmentHeight( GEFloat, GEFloat, GEFloat );
    GEBool             TestStretchOnPath( bCStretch const & );
    GEBool             UseNavigationPath( bCVector const &, bCVector const &, bCMatrix &, GEInt &, GEInt & );
protected:
    void GameReset( void );
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCNavPath_PS, 0x0120 )

#pragma warning( pop )

#endif
