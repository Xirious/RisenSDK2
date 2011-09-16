#ifndef GE_FLIGHTPATHSEEKING_H_INCLUDED
#define GE_FLIGHTPATHSEEKING_H_INCLUDED

class GE_DLLIMPORT gCFlightPathSeeking :
    public gCFlightPathBase
{
GE_DECLARE_PROPERTY_OBJECT( gCFlightPathSeeking, gCFlightPathBase )
public: virtual GEBool   OnRead( bCIStream & );
public: virtual GEBool   OnWrite( bCOStream & );
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual bEResult PostInitializeProperties( void );
public: virtual GEBool   MoveProjectile( bCVector &, bCVector &, GEFloat );
public: virtual GEBool   FindInitialDirection( bCVector &, GEFloat, bCVector const &, bCVector const &, bCVector const & );
protected:
    GE_DECLARE_PROPERTY( eCEntityProxy, m_TargetEntity, TargetEntity )
public:
    GEBool operator == ( gCFlightPathSeeking const & ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCFlightPathSeeking, 0x000C )

#endif