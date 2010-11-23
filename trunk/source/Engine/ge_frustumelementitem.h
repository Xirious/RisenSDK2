#ifndef GE_FRUSTUMELEMENTITEM_H_INCLUDED
#define GE_FRUSTUMELEMENTITEM_H_INCLUDED

class GE_DLLIMPORT eCFrustumElementItem
{
private:
    eCGeometryEntity * m_pEntity;        // 0000
    GEU32              __FIXME_0004;
    GEU32              __FIXME_0008;
    GEU16              __FIXME_000C;
                       GE_PADDING( 2 )
    GEU32              __FIXME_0010;
    eCIlluminated_PS * m_pIllumination;  // 0014
    eCPortalRoom_PS *  m_pPortalRoom;    // 0018
    GEFloat            __FIXME_001C;
    // sizeof(eCFrustumElementItem)         0020
protected:
    GEBool Create( void );
    void   Invalidate( void );
    void   SetPortalRoom( eCPortalRoom_PS * );
public:
    void    CacheIn( void );
    void    CacheOut( void );
    GEFloat                       CalculateFadeOut( eCFrustumDatabase & ) const;
    GEFloat                       CalculateObjectSize( eCFrustumDatabase & ) const;
    void                          CopyFrom( eCFrustumElementItem const & );
//  eCFrustumFilter::eECullStatus CullNode( eCFrustumDatabase & );
//  eCFrustumFilter::eECullStatus CullTree( eCFrustumDatabase & );
    void                          Destroy( void );
    eCGeometryEntity *            GetEntity( void );
    eCIlluminated_PS *            GetIlluminationPS( void ) const;
    eCPortalRoom_PS *             GetPortalRoom( void ) const;
    GEBool                        HasRenderContexts( void ) const;
    GEBool                        IsDynamic( void ) const;
    GEBool                        Request( eCFrustumDatabase &, GEU16, GEFloat );
    void                          RequestPrePasses( eCFrustumDatabase & );
    void                          SetEntity( eCGeometryEntity * );
    void                          SetIlluminationPS( eCIlluminated_PS * );
    void                          UpdatePortalRoom( void );
    void                          UpdatePortalRoom( GEBool );
    GEBool                        WasVisibleLastFrame( eCFrustumDatabase & ) const;
public:
    eCFrustumElementItem const & operator = ( eCFrustumElementItem const & );
protected:
    eCFrustumElementItem( eCFrustumElementItem const & );
public:
    eCFrustumElementItem( void );
   ~eCFrustumElementItem( void );
};

#endif
