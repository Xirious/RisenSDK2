#ifndef GE_STRETCH_H_INCLUDED
#define GE_STRETCH_H_INCLUDED

class GE_DLLIMPORT bCStretch
{
private:
    bCVector m_vecStart;
    bCVector m_vecEnd;
protected:
    static GEFloat bCStretch::m_fDummy;
public:
    bCVector &       AccessEnd( void );
    bCVector &       AccessStart( void );
    void             Add( bCStretch const & );
    void             Clear( void );
    void             CopyFrom( bCStretch const & );
    void             CopyTo( bCStretch & ) const;
    bCStretch        GetDifference( bCStretch const & ) const;
    void             GetDifference( bCStretch &, bCStretch const & ) const;
    bCVector         GetDirection( void ) const;
    void             GetDirection( bCVector & ) const;
    bCVector const & GetEnd( void ) const;
    void             GetEnd( bCVector & ) const;
    GEFloat          GetIntersectionDistance( bCBox const & ) const;
    GEFloat          GetIntersectionDistance( bCPlane const & ) const;
    GEFloat          GetIntersectionDistance( bCSphere const & ) const;
    GEFloat          GetIntersectionDistance( bCTriangle const & ) const;
    GEFloat          GetIntersectionDistance( bCVector [ bCTriangle::bEVector_Count ] ) const;
    bCStretch        GetInvScaled( GEFloat ) const;
    void             GetInvScaled( bCStretch &, GEFloat ) const;
    bCStretch        GetInvTransformed( bCMatrix3 const & ) const;
    bCStretch        GetInvTransformed( bCMatrix const & ) const;
    void             GetInvTransformed( bCStretch &, bCMatrix3 const & ) const;
    void             GetInvTransformed( bCStretch &, bCMatrix3 ) const;
    bCStretch        GetInvTranslated( bCVector const & ) const;
    void             GetInvTranslated( bCStretch &, bCVector const & ) const;
    bCStretch        GetInverted( void ) const;
    void             GetInverted( bCStretch & ) const;
    bCStretch        GetScaled( GEFloat ) const;
    void             GetScaled( bCStretch &, GEFloat ) const;
    GEFloat          GetSquareDistance( bCStretch const & ) const;
    GEFloat          GetSquareDistance( bCStretch const &, GEFloat &, GEFloat & ) const;
    GEFloat          GetSquareDistance( bCRay const & ) const;
    GEFloat          GetSquareDistance( bCRay const &, GEFloat &, GEFloat & ) const;
public: bCVector const & bCStretch::GetStart( void ) const;
    void             GetStart( bCVector & ) const;
    bCStretch        GetSum( bCStretch const & ) const;
    void             GetSum( bCStretch &, bCStretch const & ) const;
    bCStretch        GetTransformed( bCMatrix3 const & ) const;
    bCStretch        GetTransformed( bCMatrix const & ) const;
    void             GetTransformed( bCStretch &, bCMatrix3 const & ) const;
    void             GetTransformed( bCStretch &, bCMatrix3 ) const;
    bCStretch        GetTranslated( bCVector const & ) const;
    void             GetTranslated( bCStretch &, bCVector const & ) const;
    GEBool           Intersects( bCBox const &, GEFloat & ) const;
    GEBool           Intersects( bCFrustum const &, GEFloat & ) const;
    GEBool           Intersects( bCPlane const &, GEFloat & ) const;
    GEBool           Intersects( bCSphere const &, GEFloat & ) const;
    GEBool           Intersects( bCTriangle const &, GEFloat & ) const;
    GEBool           Intersects( bCTriangle const &, bCTriangle::bESides, GEFloat & ) const;
    GEBool           Intersects( bCVector const [ bCTriangle::bEVector_Count ], GEFloat & ) const;
    GEBool           Intersects( bCVector const [ bCTriangle::bEVector_Count ], bCTriangle::bESides, GEFloat & ) const;
    void             InvScale( GEFloat );
    void             InvTransform( bCMatrix3 const & );
    void             InvTransform( bCMatrix const & );
    void             InvTranslate( bCVector const & );
    void             Invert( void );
    void             Scale( GEFloat );
    void             SetEnd( bCVector const & );
    void             SetStart( bCVector const & );
    void             SetStretch( bCStretch const & );
    void             SetStretch( bCVector const &, bCVector const & );
    void             Sub( bCStretch const & );
    void             Transform( bCMatrix3 const & );
    void             Transform( bCMatrix const & );
    void             Translate( bCVector const & );
public:
    bCStretch   operator *  ( bCMatrix3 const & ) const;
    bCStretch   operator *  ( bCMatrix const & ) const;
    bCStretch   operator *  ( GEFloat ) const;
    bCStretch   operator -  ( bCStretch const & ) const;
    bCStretch   operator -  ( bCVector const & ) const;
    bCStretch   operator -  ( void ) const;
    bCStretch   operator +  ( bCStretch const & ) const;
    bCStretch   operator +  ( bCVector const & ) const;
    bCStretch   operator /  ( bCMatrix3 const & ) const;
    bCStretch   operator /  ( bCMatrix const & ) const;
    bCStretch   operator /  ( GEFloat ) const;
    bCStretch & operator *= ( GEFloat );
    bCStretch & operator += ( bCStretch const & );
    bCStretch & operator += ( bCVector const & );
    bCStretch & operator -= ( bCStretch const & );
    bCStretch & operator -= ( bCVector const & );
    bCStretch & operator /= ( GEFloat );
    bCIStream & operator << ( bCIStream & );
    bCOStream & operator >> ( bCOStream & ) const;
    bCStretch & operator =  ( bCStretch const & );
public:
    bCStretch( bCStretch const & );
    bCStretch( void );
   ~bCStretch( void );
};

#endif
