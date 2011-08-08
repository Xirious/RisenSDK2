#ifndef GE_FLIGHTPATHBASE_H_INCLUDED
#define GE_FLIGHTPATHBASE_H_INCLUDED

class GE_DLLIMPORT gCFlightPathBase :
    public bCObjectBase
{
public: virtual GEBool                     MoveProjectile( bCVector &, bCVector &, GEFloat );
public: virtual GEBool                     FindInitialDirection( bCVector &, GEFloat, bCVector const &, bCVector const &, bCVector const & );
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCFlightPathBase( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    gCFlightPathBase & operator =  ( gCFlightPathBase const & );
    GEBool             operator == ( gCFlightPathBase const & ) const;
public:
    gCFlightPathBase( gCFlightPathBase const & );
    gCFlightPathBase( void );

};
GE_ASSERT_SIZEOF( gCFlightPathBase, 0x0004 )

#endif
