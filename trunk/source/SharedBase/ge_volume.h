#ifndef GE_VOLUME_H_INCLUDED
#define GE_VOLUME_H_INCLUDED

class GE_DLLIMPORT bCVolume
{
public: virtual void       GetCenter( bCVector & a_vecCenter ) const = 0;
public: virtual bCVector   GetCenter( void ) const = 0;
public: virtual bCVolume * Clone( void ) const = 0;
public: virtual void       Transform( bCMatrix const & a_matTransform ) = 0;
public: virtual void       Translate( bCVector const & a_vecOffset ) = 0;
public: virtual GEBool     Intersects( bCVolume const & a_Volume ) const = 0;
public: virtual GEBool     Intersects( bCVector const & a_vecPoint ) const = 0;
public: virtual GEBool     Intersects( bCSphere const & a_Sphere ) const = 0;
public: virtual GEBool     Intersects( bCFrustum const & a_Frustum ) const = 0;
public: virtual GEBool     Intersects( bCBox const & a_Box ) const = 0;
public: virtual GEBool     Intersects( bCTriangle const & a_Triangle ) const = 0;
public: virtual GEBool     Intersects( bCUnitedRay const & a_UnitedRay ) const = 0;
public: virtual GEBool     Intersects( bCUnitedRay const & a_UnitedRay, GEFloat & a_fDistance ) const = 0;
public: virtual GEBool     Intersects( bCPlane const & a_Plane ) const = 0;
public: virtual           ~bCVolume( void );
public:
    bCVolume & operator = ( bCVolume const & );
public:
    bCVolume( bCVolume const & );
    bCVolume( void );
};

template< typename T >
class bTVolume :
    public bCVolume
{
public: virtual void       GetCenter( bCVector & a_vecCenter ) const;
public: virtual bCVector   GetCenter( void ) const;
public: virtual bCVolume * Clone( void ) const;
public: virtual void       Transform( bCMatrix const & a_matTransform );
public: virtual void       Translate( bCVector const & a_vecOffset );
public: virtual GEBool     Intersects( bCVolume const & a_Volume ) const;
public: virtual GEBool     Intersects( bCVector const & a_vecPoint ) const;
public: virtual GEBool     Intersects( bCSphere const & a_Sphere ) const;
public: virtual GEBool     Intersects( bCFrustum const & a_Frustum ) const;
public: virtual GEBool     Intersects( bCBox const & a_Box ) const;
public: virtual GEBool     Intersects( bCTriangle const & a_Triangle ) const;
public: virtual GEBool     Intersects( bCUnitedRay const & a_UnitedRay ) const;
public: virtual GEBool     Intersects( bCUnitedRay const & a_UnitedRay, GEFloat & a_fDistance ) const;
public: virtual GEBool     Intersects( bCPlane const & a_Plane ) const;
public: virtual           ~bTVolume( void );
private:
    T m_Volume;
public:
    bTVolume< T > & operator = ( bTVolume< T > const & a_Source );
public:
    bTVolume( T const & a_Volume );
    bTVolume( bTVolume< T > const & a_Source );
    bTVolume( void );
};

#include "ge_volume.inl"

#endif
