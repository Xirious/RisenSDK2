#ifndef GE_NAVZONE_PS_H_INCLUDED
#define GE_NAVZONE_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCNavZone_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCNavZone_PS'

class GE_DLLIMPORT gCNavZone_PS :
    public eCEntityPropertySet
{
protected:
    struct bSIntersection
    {
        bCVector2 __FIXME_0000;
        GEFloat   __FIXME_0008;
    };
    GE_ASSERT_SIZEOF( bSIntersection, 0x000C )
    
GE_DECLARE_PROPERTY_OBJECT( gCNavZone_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
public:    virtual bEResult          PostInitializeProperties( void );
protected: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
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
    GE_DECLARE_PROPERTY( bTValArray< bCVector >, m_arrPoint,             Point )
    GE_DECLARE_PROPERTY( GEFloat,                m_fRadius,              Radius )
    GE_DECLARE_PROPERTY( bCVector,               m_vecRadiusOffset,      RadiusOffset )
    GE_DECLARE_PROPERTY( GEBool,                 m_bZoneIsCCW,           ZoneIsCCW )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,                m_fCostFactor,          CostFactor )
    GE_DECLARE_PROPERTY( GEFloat,                m_fTopToleranz,         TopToleranz )
    GE_DECLARE_PROPERTY( GEFloat,                m_fBottomToleranz,      BottomToleranz )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerArea,       LinkInnerArea )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerTopArea,    LinkInnerTopArea )
    GE_DECLARE_PROPERTY( GEBool,                 m_bLinkInnerBottomArea, LinkInnerBottomArea )
    GE_PADDING1( 1 )
    GE_DECLARE_ENUMPROP( gENavTestResult,        m_enumNavTestResult,    NavTestResult )
    char __FIXME[ 0x0170 - 0x0048 ];
public:
    void               AddCollisionCircleOffset( bTValArray< bCMotion > &, bCVector const &, bCVector const &, GEBool );
    bEResult           BuildClusterLists( void );
    GEFloat            CalcAbsHeightDiffFlagAndPrioFlag( bCVector const &, GEBool &, GEBool & );
    bEResult           CalcZoneHeights( void );
    bEResult           DeregisterCollisionCirclePSObject( gCCollisionCircle_PSObj * );
    bEResult           DeregisterDCCPS( gCDynamicCollisionCircle_PS * );
    bEResult           DeregisterNegZonePSObject( gCNegZone_PSObj * );
    bEResult           DeregisterPrefPathPSObject( gCPrefPath_PSObj * );
    GEBool             DetectCollisionCircleGateway( bCMatrix const &, bCVector &, GEInt );
    void               DynAttachCollisionCirclePSObj( gCCollisionCircle_PSObj * );
    void               DynDeattachCollisionCirclePSObj( gCCollisionCircle_PSObj * );
    bCVector const &   Get3DEvade( void );
    GEFloat            GetCosts( bCVector const &, bCVector const & ) const;
    bCDateTime const & GetLastModificationTime( void ) const;
    GEU32              GetNetIndex( void );
    GEFloat            GetZoneBottomHeight( void );
    GEFloat            GetZoneTopHeight( void );
    GEBool             IntersectsStretch( bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool );
    GEBool             IsZoneIllegal( GEBool ) const;
    void               OnStakesChanged( void );
    bEResult           RegisterCollisionCirclePSObject( gCCollisionCircle_PSObj * );
    bEResult           RegisterDCCPS( gCDynamicCollisionCircle_PS * );
    bEResult           RegisterNegZonePSObject( gCNegZone_PSObj * );
    bEResult           RegisterPrefPathPSObject(gCPrefPath_PSObj * );
    void               SetNetIndex( GEU32 );
    GEBool             Test3DPointInInternalNegZone( bCVector const & );
    GEBool             Test3DPointInZone( bCVector const &, GEBool );
    GEBool             TestPointAgainstCollCircles( bCVector const &, GEBool, GEBool *, GEBool );
    GEBool             TestPointAgainstDCCs( bCVector const &, eCEntity const & );
    GEBool             TestPointAgainstNegZones( bCVector const &, GEBool );
    GEBool             TestStretchAgainstCollCircles( bCStretch const &, GEBool, GEBool );
    GEBool             TestStretchAgainstNegZones( bCStretch const & );
    GEBool             TestStretchInZone( bCStretch const & );
protected:
    static GEInt GE_CCALL __SortIntersections( GELPCVoid, GELPCVoid );
protected:
    bEResult          AddLeftAndRightAngle( bCVector const &, bCVector const &, GEFloat &, GEFloat & );
    void              GameReset( void );
    bEResult          GetAngleSums( GEFloat &, GEFloat & );
    bCVector2 const & GetEvade( GEInt );
    GEBool            GetInnerZoneEdgeEvadeDirection( bCVector const &, bCVector const &, GEInt, GEInt, GEBool & );
    GEBool            GetNearestIntersections( bCVector2 const &, bCVector2 const &, GEFloat, GEFloat, bSIntersection &, bSIntersection &, GEBool );
    void              Invalidate( void );
};
GE_ASSERT_SIZEOF( gCNavZone_PS, 0x0170 )

#pragma warning( pop )

#endif
