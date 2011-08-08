#ifndef GE_FLIGHTPATHSEEKING_H_INCLUDED
#define GE_FLIGHTPATHSEEKING_H_INCLUDED

class GE_DLLIMPORT gCFlightPathSeeking :
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
public: virtual                           ~gCFlightPathSeeking( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCEntityProxy m_TargetEntity;  // 0004
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCEntityProxy &       AccessTargetEntity( void );
    eCEntityProxy const & GetTargetEntity( void ) const;
    void                  SetTargetEntity( eCEntityProxy const & );
public:
    gCFlightPathSeeking & operator =  ( gCFlightPathSeeking const & );
    GEBool                operator == ( gCFlightPathSeeking const & ) const;
public:
    gCFlightPathSeeking( gCFlightPathSeeking const & );
    gCFlightPathSeeking( void );
};
GE_ASSERT_SIZEOF( gCFlightPathSeeking, 0x000C )

#endif