#ifndef GE_FLIGHTPATHBALLISTIC_H_INCLUDED
#define GE_FLIGHTPATHBALLISTIC_H_INCLUDED

class GE_DLLIMPORT gCFlightPathBallistic :
    public gCFlightPathBase
{
public: virtual GEBool                     MoveProjectile( bCVector &, bCVector &, GEFloat );
public: virtual GEBool                     FindInitialDirection( bCVector &, GEFloat, bCVector const &, bCVector const &, bCVector const & );
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~gCFlightPathBallistic( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEFloat m_fVelocityLoss;          // 0004
    GEFloat m_fDeactivationVelocity;  // 0008
    GEFloat m_fGravity;               // 000C
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &       AccessDeactivationVelocity( void );
    GEFloat &       AccessGravity( void );
    GEFloat &       AccessVelocityLoss( void );
    GEFloat const & GetDeactivationVelocity( void ) const;
    GEFloat const & GetGravity( void ) const;
    GEFloat const & GetVelocityLoss( void ) const;
    void            SetDeactivationVelocity( GEFloat const & );
    void            SetGravity( GEFloat const & );
    void            SetVelocityLoss( GEFloat const & );
public:
    gCFlightPathBallistic & operator =  ( gCFlightPathBallistic const & );
    GEBool                  operator == ( gCFlightPathBallistic const & ) const;
public:
    gCFlightPathBallistic( gCFlightPathBallistic const & );
    gCFlightPathBallistic( void );
};
GE_ASSERT_SIZEOF( gCFlightPathBallistic, 0x0010 )

#endif