#ifndef GE_EIGENVECTOR_H_INCLUDED
#define GE_EIGENVECTOR_H_INCLUDED

class GE_DLLIMPORT bCEigenVector
{
private:
    static GEUInt const invalid_size;
    static GEUInt const allocation_failed;
    static GEUInt const ql_exceeded;
    static GELPCChar *  message;
public:
    static GEUInt error;  // invalid_size: 1, allocation_failed: 1, ql_exceeded: 1
private:
    GEI32        m_i32MatrixSize;
    GEDouble * * m_ppdVector;
    GEDouble *   m_pdDiags;
    GEDouble *   m_pdSubDiags;
private:
    static GEI32 GE_STDCALL Number( GEUInt );
    static void  GE_STDCALL Report( GEUInt );
private:
    void DecreasingSort( GEI32, GEDouble *, GEDouble * * );
    void IncreasingSort( GEI32, GEDouble *, GEDouble * * );
    void QLAlgorithm( GEI32, GEDouble *, GEDouble *, GEDouble * * );
    void Tridiagonal2( GEDouble * *, GEDouble *, GEDouble * );
    void Tridiagonal3( GEDouble * *, GEDouble *, GEDouble * );
    void Tridiagonal4( GEDouble * *, GEDouble *, GEDouble * );
    void TridiagonalN( GEI32, GEDouble * *, GEDouble *, GEDouble * );
public:
    void               DecrSortEigenStuff( void );
    void               DecrSortEigenStuff2( void );
    void               DecrSortEigenStuff3( void );
    void               DecrSortEigenStuff4( void );
    void               DecrSortEigenStuffN( void );
    void               EigenStuff( void );
    void               EigenStuff2( void );
    void               EigenStuff3( void );
    void               EigenStuff4( void );
    void               EigenStuffN( void );
    GEDouble const *   Eigenvalue( void );
    GEDouble           Eigenvalue( GEI32 );
    GEDouble const * * Eigenvector( void );
    GEDouble           Eigenvector( GEI32, GEI32 );
    void               Eigenvector( GEI32, bCVector & ) const;
    void               IncrSortEigenStuff( void );
    void               IncrSortEigenStuff2( void );
    void               IncrSortEigenStuff3( void );
    void               IncrSortEigenStuff4( void );
    void               IncrSortEigenStuffN( void );
    GEDouble &         Matrix( GEI32, GEI32 );
    bCEigenVector &    Matrix( GEDouble * * );
    void               Reduce( void );
    GEDouble &         Tdiag( GEI32 );
    GEDouble &         Tsubdiag( GEI32 );
public:
    bCEigenVector & operator = ( bCEigenVector const & );
public:
    bCEigenVector( GEI32 );
   ~bCEigenVector( void );
};

#endif
