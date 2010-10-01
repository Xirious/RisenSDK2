#ifndef GE_SPHERICALROTATION_H_INCLUDED
#define GE_SPHERICALROTATION_H_INCLUDED

class GE_DLLIMPORT bCSphericalRotation
{
private:
    GEFloat m_fLatitude;
    GEFloat m_fLongitude;
    GEFloat m_fAzimuth;
public:
    GEFloat & AccessAzimuth( void );
    GEFloat & AccessLatitude( void );
    GEFloat & AccessLongitude( void );
    GEFloat   GetAzimuth( void ) const;
    void      GetAzimuth( GEFloat & ) const;
    GEFloat   GetLatitude( void ) const;
    void      GetLatitude( GEFloat & ) const;
    GEFloat   GetLongitude( void ) const;
    void      GetLongitude( GEFloat & ) const;
    void      SetAzimuth( GEFloat );
    void      SetLatitude( GEFloat );
    void      SetLongitude( GEFloat );
public:
    bCIStream &           operator << ( bCIStream & );
    bCOStream &           operator >> ( bCOStream & ) const;
    bCSphericalRotation & operator =  ( bCSphericalRotation const & );
public:
    bCSphericalRotation( void );
   ~bCSphericalRotation( void );
};

#endif
