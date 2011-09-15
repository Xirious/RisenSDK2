#ifndef GE_COLLISIONCIRCLE_PSOBJ_H_INCLUDED
#define GE_COLLISIONCIRCLE_PSOBJ_H_INCLUDED

enum gENavObstacleType
{
    gENavObstacleType_Obstacle,
    gENavObstacleType_Climbable,
    gENavObstacleType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCCollisionCircle_PSObj'

class GE_DLLIMPORT gCCollisionCircle_PSObj
{
public: virtual ~gCCollisionCircle_PSObj( void );
protected:
    char __FIXME[ 0x0064 - sizeof(void *) ];
public:
    gCCollisionCircle_PSObj( void );
    gCCollisionCircle_PSObj( gCCollisionCircle_PSObj const & );
public:
    gCCollisionCircle_PSObj & operator = ( gCCollisionCircle_PSObj const & );
public:
    bTValArray< gCCollisionCircle_PSObj * > *       AccessClusteredCollisionCirclePSObj( bCPropertyID const & );
    bTValArray< bCPropertyID > &                    AccessNavZoneEntityIDs( void );
    bTValArray< gCCollisionCircle_PSObj * > &       AddAndAccessClusteredCollisionCirclePSObj( bCPropertyID const & );
    void                                            AddCollisionCircleOffset( bTValArray< bCMotion > &, bCVector const &, bCVector const &, GEBool );
    bEResult                                        CalculateEvade( bCStretch const &, GEFloat, GEInt );
    bEResult                                        CopyFrom( gCCollisionCircle_PSObj const & );
    void                                            Destroy( void );
    void                                            DetectCollisionCircleGateway( bCMatrix const &, bCVector &, GEInt );
    bTValArray< gCCollisionCircle_PSObj * > const & GetClusteredCollisionCirclePSObj( bCPropertyID const & );
    GEBool                                          GetEnabled( void ) const;
    bCPropertyID const &                            GetEntityID( void ) const;
    bCVector2 const &                               GetEvade( void ) const;
    GEBool                                          GetNPCCircle( void ) const;
    gENavObstacleType const &                       GetNavObstacleType( void ) const;
    bTValArray< bCPropertyID > const &              GetNavZoneEntityIDs( void ) const;
    bTValArray< GEFloat > const &                   GetRadius( void ) const;
    GEInt                                           GetRegIndex( void ) const;
    bTValArray< bCVector > const &                  GetWorldOffset( void ) const;
    GEFloat                                         GetWorldPositionY( void ) const;
    GEBool                                          Intersects( gCCollisionCircle_PSObj * );
    GEBool                                          Intersects( bCInfCylinder * );
    GEBool                                          Intersects( bCInfDoubleCylinder * );
    GEBool                                          IntersectsArea( bCVector const &, GEFloat );
    GEBool                                          IntersectsPoint( bCVector const &, GEBool );
    GEBool                                          IntersectsStretch( bCStretch const &, GEFloat &, GEBool );
    void                                            SetEnabled( GEBool );
    void                                            SetEntityID( bCPropertyID const & );
    void                                            SetNPCCircle( GEBool );
    void                                            SetNavObstacleType( gENavObstacleType const & );
    void                                            SetNavZoneEntityIDs( bTValArray< bCPropertyID > const & );
    void                                            SetRadius( bTValArray< GEFloat > const &, GEFloat );
    void                                            SetRegIndex( GEInt );
    void                                            SetWorldOffset( bTValArray< bCVector > const & );
    void                                            SetWorldPositionY( GEFloat );
    GEBool                                          TestPoint( bCVector const &, GEBool );
    GEBool                                          TestStretch( bCStretch const &, GEBool );
protected:
    static bTValArray< gCCollisionCircle_PSObj * > s_arrDummyCollisionCircle;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCCollisionCircle_PSObj, 0x0064 )

#pragma warning( pop )

#endif
