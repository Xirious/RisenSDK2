#ifndef GE_TRIANGLE_H_INCLUDED
#define GE_TRIANGLE_H_INCLUDED

class bCFrustum;    // forward
class bCLine;       // forward
class bCSphere;     // forward
class bCStretch;    // forward
class bCUnitedRay;  // forward

class GE_DLLIMPORT bCTriangle
{
public:
    enum bESides
    {
        bESides_Front = 0x00000001,
        bESides_Back  = 0x00000002,
        bESides_Both  = bESides_Front | bESides_Back,
        bESides_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEVector
    {
        bEVector_A,
        bEVector_B,
        bEVector_C,
        bEVector_Count,
        bEVector_ForceDWORD = GE_FORCE_DWORD
    };
private:
    bCVector m_vecA;
    bCVector m_vecB;
    bCVector m_vecC;
protected:
    static GEFloat m_fDummy;
public:
    bCVector &        AccessA( void );
    bCVector &        AccessB( void );
    bCVector &        AccessC( void );
    bCVector &        AccessVector( GEInt );
    bCVector (&       AccessVectors( void )) [ bEVector_Count ];
    bCVector          CalcNormal( void ) const;
    void              CalcNormal( bCVector & ) const;
    void              Clear( void );
    void              CopyFrom( bCTriangle const & );
    void              CopyTo( bCTriangle & ) const;
    GEBool            Cull( bCTriangle const & ) const;
    GEBool            Cull( bCBox const & ) const;
    GEBool            Cull( bCFrustum const & ) const;
    GEBool            Cull( bCLine const & ) const;
    GEBool            Cull( bCPlane const & ) const;
    GEBool            Cull( bCRay const & ) const;
    GEBool            Cull( bCSphere const & ) const;
    GEBool            Cull( bCStretch const & ) const;
    GEBool            Cull( bCUnitedRay const & ) const;
    GEBool            Cull( bCVector const [ bEVector_Count ] ) const;
    bCVector const &  GetA( void ) const;
    void              GetA( bCVector & ) const;
    bCVector const &  GetB( void ) const;
    void              GetB( bCVector & ) const;
    bCVector const &  GetC( void ) const;
    void              GetC( bCVector & ) const;
    void              GetCenter( bCVector & );
    GEFloat           GetIntersectionDistance( bCLine const & ) const;
    GEFloat           GetIntersectionDistance( bCRay const & ) const;
    GEFloat           GetIntersectionDistance( bCStretch const & ) const;
    bCTriangle        GetInvTransformed( bCMatrix3 const & ) const;
    bCTriangle        GetInvTransformed( bCMatrix const & ) const;
    void              GetInvTransformed( bCTriangle &, bCMatrix3 const & ) const;
    void              GetInvTransformed( bCTriangle &, bCMatrix3 ) const;
    bCTriangle        GetInvTranslated( bCVector const & ) const;
    void              GetInvTranslated( bCTriangle &, bCVector const & ) const;
    bCTriangle        GetTransformed( bCMatrix3 const & ) const;
    bCTriangle        GetTransformed( bCMatrix const & ) const;
    void              GetTransformed( bCTriangle &, bCMatrix3 const & ) const;
    void              GetTransformed( bCTriangle &, bCMatrix3 ) const;
    bCTriangle        GetTranslated( bCVector const & ) const;
    void              GetTranslated( bCTriangle &, bCVector const & ) const;
    bCVector const &  GetVector( GEInt ) const;
    bCVector const (& GetVectors( void ) const) [ bEVector_Count ];
    GEBool            Intersects( bCTriangle const & ) const;
    GEBool            Intersects( bCBox const & ) const;
    GEBool            Intersects( bCFrustum const & ) const;
    GEBool            Intersects( bCLine const &, GEFloat & ) const;
    GEBool            Intersects( bCLine const &, bESides, GEFloat & ) const;
    GEBool            Intersects( bCPlane const & ) const;
    GEBool            Intersects( bCRay const &, GEFloat & ) const;
    GEBool            Intersects( bCRay const &, bESides, GEFloat & ) const;
    GEBool            Intersects( bCSphere const & ) const;
    GEBool            Intersects( bCStretch const &, GEFloat & ) const;
    GEBool            Intersects( bCStretch const &, bESides, GEFloat & ) const;
    GEBool            Intersects( bCUnitedRay const &, GEFloat & ) const;
    GEBool            Intersects( bCUnitedRay const &, bESides, GEFloat & ) const;
    GEBool            Intersects( bCVector const [ bEVector_Count ] ) const;
    void              InvTransform( bCMatrix3 const & );
    void              InvTransform( bCMatrix const & );
    void              InvTranslate( bCVector const & );
    GEBool            IsDegenerated( void ) const;
    GEBool            Separates( bCVector const *, GEInt, bCVector const & ) const;
    void              SetA( bCVector const & );
    void              SetB( bCVector const & );
    void              SetC( bCVector const & );
    void              SetTriangle( bCTriangle const & );
    void              SetTriangle( bCVector const &, bCVector const &, bCVector const & );
    void              SetTriangle( bCVector [ bEVector_Count ] );
    void              Transform( bCMatrix3 const & );
    void              Transform( bCMatrix const & );
    void              Translate( bCVector const & );
public:
    bCVector &       operator [] ( GEInt );
    bCVector const & operator [] ( GEInt ) const;
    bCTriangle       operator *  ( bCMatrix3 const & ) const;
    bCTriangle       operator *  ( bCMatrix const & ) const;
    bCTriangle       operator /  ( bCMatrix3 const & ) const;
    bCTriangle       operator /  ( bCMatrix const & ) const;
    bCIStream &      operator << ( bCIStream & );
    bCOStream &      operator >> ( bCOStream & ) const;
    bCTriangle &     operator =  ( bCTriangle const & );
public:
    explicit bCTriangle( bCVector [ bEVector_Count ] );
             bCTriangle( bCVector const &, bCVector const &, bCVector const & );
             bCTriangle( bCTriangle const & );
             bCTriangle( void );
            ~bCTriangle( void );
};

#endif
