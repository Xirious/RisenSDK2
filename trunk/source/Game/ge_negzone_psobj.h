#ifndef GE_NEGZONE_PSOBJ_H_INCLUDED
#define GE_NEGZONE_PSOBJ_H_INCLUDED

class GE_DLLIMPORT gCNegZone_PSObj
{
public: virtual ~gCNegZone_PSObj( void );
protected:
    char __FIXME[ 0x00DC -sizeof(void *) ];
public:
    gCNegZone_PSObj( void );
    gCNegZone_PSObj( gCNegZone_PSObj const & );
public:
    gCNegZone_PSObj & operator = ( gCNegZone_PSObj const & );
public:
    gENavTestResult &              AccessNavTestResult( void );
    bCPropertyID &                 AccessNavZoneEntityID( void );
    bEResult                       CopyFrom( gCNegZone_PSObj const & );
    void                           Destroy( void );
    bCVector const &               Get3DEvade( void );
    bCPropertyID const &           GetEntityID( void ) const;
    gENavTestResult const &        GetNavTestResult( void ) const;
    bCPropertyID const &           GetNavZoneEntityID( void ) const;
    GEFloat const &                GetRadius( void ) const;
    GEInt                          GetRegIndex( void ) const;
    bTValArray< bCVector > const & GetWorldPoint( void ) const;
    bCVector const &               GetWorldRadiusOffset( void ) const;
    GEBool const &                 GetZoneIsCCW( void ) const;
    GEBool                         IntersectsArea( bCVector const &, GEFloat );
    GEBool                         IntersectsPoint( bCVector const &, GEBool );
    GEBool                         IntersectsStretch( bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool );
    GEBool                         IsZoneIllegal( void );
    void                           OnStakesChanged( void );
    void                           SetEntityID( bCPropertyID const & );
    void                           SetNavTestResult( gENavTestResult const & );
    void                           SetNavZoneEntityID( bCPropertyID const & );
    void                           SetRadius( GEFloat const & );
    void                           SetRegIndex( GEInt );
    void                           SetWorldPoint( bTValArray< bCVector > const & );
    void                           SetWorldRadiusOffset( bCVector const & );
    void                           SetZoneIsCCW( GEBool const & );
    GEBool                         Test3DPointInZone( bCVector const &, GEBool );
    GEBool                         TestPoint( bCVector const &, GEBool );
    GEBool                         TestStretch( bCStretch const & );
protected:
    bEResult          AddLeftAndRightAngle( bCVector &, bCVector &, GEFloat &, GEFloat & );
    GEFloat           CalcAngleSumStakeA( GEInt & );
    GEFloat           CalcAngleSumStakeB( GEInt & );
    bEResult          GetAngleSums( GEFloat &, GEFloat & );
    bCVector2 const & GetEvade( void );
    void              Invalidate( void );
    bCVector2 const & RunNPCInZoneNavigation( GEBool );
    bCVector2 const & RunTargetBehindZoneNavigation( void );
    bCVector2 const & RunTargetInZoneNavigation( GEBool );
    GEBool            SetFirstIntersection( GEFloat & );
    bEResult          TestNPCAndTargetLocation( GEBool &, GEBool & );
    GEBool            TestRealIntersection( bCStretch const &, GEFloat &, GEBool );
};
GE_ASSERT_SIZEOF( gCNegZone_PSObj, 0x00DC )

#endif
