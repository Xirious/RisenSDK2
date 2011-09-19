#ifndef GE_FLIGHTPATHBASE_H_INCLUDED
#define GE_FLIGHTPATHBASE_H_INCLUDED

class GE_DLLIMPORT gCFlightPathBase :
    public bCObjectBase
{
public: virtual GEBool   MoveProjectile( bCVector &, bCVector &, GEFloat );
public: virtual GEBool   FindInitialDirection( bCVector &, GEFloat, bCVector const &, bCVector const &, bCVector const & );
GE_DECLARE_PROPERTY_OBJECT( gCFlightPathBase, bCObjectBase )
public: virtual GEBool   OnRead( bCIStream & );
public: virtual GEBool   OnWrite( bCOStream & );
public: virtual bEResult Create( void );
public: virtual void     Destroy( void );
public: virtual bEResult PostInitializeProperties( void );
public: virtual         ~gCFlightPathBase( void );
public:
    GEBool operator == ( gCFlightPathBase const & ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCFlightPathBase, 0x0004 )

#endif
