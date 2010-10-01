#ifndef GE_RAY_H_INCLUDED
#define GE_RAY_H_INCLUDED

class GE_DLLIMPORT bCRay
{
private:
    bCVector m_vecOrigin;
    bCVector m_vecDirection;
protected:
    static GEFloat m_fDummy;
protected:
    bCVector & AccessDirection( void );
public:
    bCVector &       AccessOrigin( void );
    bCVector const & GetDirection( void ) const;
    void             GetDirection( bCVector & ) const;
    GEFloat          GetIntersectionDistance( bCBox const & ) const;
    GEFloat          GetIntersectionDistance( bCPlane const & ) const;
    GEFloat          GetIntersectionDistance( bCTriangle const & ) const;
    GEFloat          GetIntersectionDistance( bCVector const [ bCTriangle::bEVector_Count ] ) const;
    bCVector const & GetOrigin( void ) const;
    void             GetOrigin( bCVector & ) const;
    bCVector         GetPoint( GEFloat ) const;
    void             GetPoint( bCVector &, GEFloat ) const;
    GEBool           Intersects( bCBox const &, GEFloat & ) const;
    GEBool           Intersects( bCFrustum const &, GEFloat & ) const;
    GEBool           Intersects( bCPlane const &, GEFloat & ) const;
    GEBool           Intersects( bCSphere const &, GEFloat & ) const;
    GEBool           Intersects( bCTriangle const &, GEFloat & ) const;
    GEBool           Intersects( bCTriangle const &, bCTriangle::bESides, GEFloat & ) const;
    GEBool           Intersects( bCVector const [ bCTriangle::bEVector_Count ], GEFloat & ) const;
    GEBool           Intersects( bCVector const [ bCTriangle::bEVector_Count ], bCTriangle::bESides, GEFloat & ) const;
    void             InvTransform( bCMatrix const & );
    void             InvTranslate( bCVector const & );
    void             SetDirection( bCVector const & );
    void             SetOrigin( bCVector const & );
    void             SetRay( bCRay const & );
    void             SetRay( bCVector const &, bCVector const & );
    void             SetRay( bCRay const * );
    void             Transform( bCMatrix const & );
    void             Translate( bCVector const & );
public:
    bCRay         operator *  ( bCMatrix const & ) const;
    bCRay         operator -  ( bCVector const & ) const;
    bCRay         operator +  ( bCVector const & ) const;
    bCRay &       operator *= ( bCMatrix const & );
    bCRay &       operator += ( bCVector const & );
    bCRay &       operator -= ( bCVector const & );
    bCIStream &   operator << ( bCIStream & );
    bCOStream &   operator >> ( bCOStream & ) const;
    bCRay const & operator =  ( bCRay const & );
public:
    bCRay( bCVector const &, bCVector const & );
    bCRay( bCRay const * );
    bCRay( bCRay const & );
    bCRay( void );
   ~bCRay( void );
};

#endif
