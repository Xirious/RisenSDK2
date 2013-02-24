#ifndef GE_PREFPATH_PSOBJ_H_INCLUDED
#define GE_PREFPATH_PSOBJ_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCPrefPath_PSObj'

class GE_DLLIMPORT gCPrefPath_PSObj
{
public: virtual ~gCPrefPath_PSObj( void );
protected:
    GEInt                  m_iRegIndex;
    bCPropertyID           m_EntityID;
    bTValArray< bCVector > m_arrWorldPoint;
    bTValArray< GEFloat >  m_arrPointRadius;
    GEFloat                m_fRadius;
    bCVector               m_vecWorldRadiusOffset;
    bCPropertyID           m_NavZoneEntityID;
    gENavTestResult        m_enumNavTestResult;
    bCInfDoubleCylinder    __FIXME_005C;
    bCInfCylinder          __FIXME_007C;
    int                    __FIXME_008C;
    int                    __FIXME_0090;
    bCVector               __FIXME_0094;
    bCVector               __FIXME_00A0;
public:
    gCPrefPath_PSObj( void );
    gCPrefPath_PSObj( gCPrefPath_PSObj const & );
public:
    gCPrefPath_PSObj & operator = ( gCPrefPath_PSObj const & );
public:
    gENavTestResult &              AccessNavTestResult( void );
    bCPropertyID &                 AccessNavZoneEntityID( void );
    GEBool                         ContainsPosition( bCVector const & );
    bEResult                       CopyFrom( gCPrefPath_PSObj const & );
    void                           Destroy( void );
    bCPropertyID const &           GetEntityID( void ) const;
    gENavTestResult const &        GetNavTestResult( void ) const;
    bCPropertyID const &           GetNavZoneEntityID( void ) const;
    bTValArray< GEFloat> const &   GetPointRadius( void ) const;
    GEFloat const &                GetRadius( void ) const;
    GEInt                          GetRegIndex( void ) const;
    bTValArray< bCVector > const & GetWorldPoint( void ) const;
    bCVector const &               GetWorldRadiusOffset( void ) const;
    GEBool                         IntersectsArea( bCVector const &, GEFloat );
    void                           SetEntityID( bCPropertyID const & );
    void                           SetNavTestResult( gENavTestResult const & );
    void                           SetNavZoneEntityID( bCPropertyID const & );
    void                           SetPointRadius( bTValArray< GEFloat > const & );
    void                           SetRadius( GEFloat const & );
    void                           SetRegIndex( GEInt );
    void                           SetWorldPoint( bTValArray< bCVector > const & );
    void                           SetWorldRadiusOffset( bCVector const & );
    GEBool                         TestPreferredPathUse( bCStretch const &, GEFloat &, bCVector const & );
    GEBool                         UsePreferredPath( bCVector &, bCVector &, GEInt &, GEInt & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCPrefPath_PSObj, 0x00AC )

#pragma warning( pop )

#endif
