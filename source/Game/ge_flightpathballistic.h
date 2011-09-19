#ifndef GE_FLIGHTPATHBALLISTIC_H_INCLUDED
#define GE_FLIGHTPATHBALLISTIC_H_INCLUDED

class GE_DLLIMPORT gCFlightPathBallistic :
    public gCFlightPathBase
{
GE_DECLARE_PROPERTY_OBJECT( gCFlightPathBallistic, gCFlightPathBase )
public: virtual GEBool   OnRead( bCIStream & );
public: virtual GEBool   OnWrite( bCOStream & );
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual bEResult PostInitializeProperties( void );
public: virtual         ~gCFlightPathBallistic( void );
public: virtual GEBool   MoveProjectile( bCVector &, bCVector &, GEFloat );
public: virtual GEBool   FindInitialDirection( bCVector &, GEFloat, bCVector const &, bCVector const &, bCVector const & );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fVelocityLoss,         VelocityLoss )
    GE_DECLARE_PROPERTY( GEFloat, m_fDeactivationVelocity, DeactivationVelocity )
    GE_DECLARE_PROPERTY( GEFloat, m_fGravity,              Gravity )
public:
    GEBool operator == ( gCFlightPathBallistic const & ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCFlightPathBallistic, 0x0010 )

#endif