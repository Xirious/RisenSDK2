#ifndef GE_MATRIX2_H_INCLUDED
#define GE_MATRIX2_H_INCLUDED

class GE_DLLIMPORT bCMatrix2
{
public:
    enum bEElement
    {
        bEElement_11,
        bEElement_12,
        bEElement_21,
        bEElement_22,
        bEElement_Count,
        bEElement_ForceDWORD = GE_FORCE_DWORD
    };
    enum bERow
    {
        bERow_XAxis,
        bERow_YAxis,
        bERow_Count,
        bERow_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEColumn
    {
        bEColumn_X,
        bEColumn_Y,
        bEColumn_Count,
        bEColumn_ForceDWORD = GE_FORCE_DWORD
    };
private:
    union
    {
        GEFloat m_fElements[ bEElement_Count ];
        GEFloat m_fRowColumn[ bERow_Count ][ bEColumn_Count ];
    };
public:
    static bCMatrix2 GE_STDCALL GetIdentity( void );
    static void      GE_STDCALL GetIdentity( bCMatrix2 & );
public:
    GEFloat &         AccessElement( GEInt );
    GEFloat &         AccessElement( GEInt, GEInt );
    bCVector2 &       AccessRow( GEInt );
    bCVector2 &       AccessXAxis( void );
    bCVector2 &       AccessYAxis( void );
    void              Add( bCMatrix2 const & );
    void              Clear( void );
    void              Divide( GEFloat );
    bCVector2         GetColumn( GEInt ) const;
    void              GetColumn( GEInt, bCVector2 & ) const;
    void              GetColumn( GEInt, GEFloat [ bERow_Count ] ) const;
    GEFloat           GetDeterminant( void ) const;
    bCMatrix2         GetDifference( bCMatrix2 const & ) const;
    void              GetDifference( bCMatrix2 &, bCMatrix2 const & ) const;
    GEFloat           GetElement( GEInt ) const;
    GEFloat           GetElement( GEInt, GEInt ) const;
    void              GetElement( GEInt, GEFloat & ) const;
    void              GetElement( GEInt, GEInt, GEFloat &) const;
    bCMatrix2         GetInverted( void ) const;
    void              GetInverted( bCMatrix2 & ) const;
    bCMatrix2         GetNegated( void ) const;
    void              GetNegated( bCMatrix2 & ) const;
    bCMatrix2         GetProduct( bCMatrix2 const & ) const;
    bCMatrix2         GetProduct( GEFloat ) const;
    void              GetProduct( bCMatrix2 &, bCMatrix2 const & ) const;
    void              GetProduct( bCMatrix2 &, GEFloat ) const;
    bCMatrix2         GetProductPrefix( bCMatrix2 const & ) const;
    void              GetProductPrefix( bCMatrix2 &, bCMatrix2 const & ) const;
    bCMatrix2         GetQuotient( GEFloat ) const;
    void              GetQuotient( bCMatrix2 &, GEFloat ) const;
    bCMatrix2         GetRotated( GEFloat ) const;
    void              GetRotated( bCMatrix2 &, GEFloat ) const;
    bCMatrix2         GetRotatedLocal( GEFloat ) const;
    void              GetRotatedLocal( bCMatrix2 &, GEFloat ) const;
    bCVector2 const & GetRow( GEInt ) const;
    void              GetRow( GEInt, bCVector2 & ) const;
    void              GetRow( GEInt, GEFloat [ bEColumn_Count ] ) const;
    bCMatrix2         GetSum( bCMatrix2 const & ) const;
    void              GetSum( bCMatrix2 &, bCMatrix2 const & ) const;
    bCMatrix2         GetTransposed( void ) const;
    void              GetTransposed( bCMatrix2 & ) const;
    bCVector2 const & GetXAxis( void ) const;
    void              GetXAxis( bCVector2 & ) const;
    bCVector2 const & GetYAxis( void ) const;
    void              GetYAxis( bCVector2 & ) const;
    void              Invert( void );
    GEBool            IsEqual( bCMatrix2 const & ) const;
    GEBool            IsIdentity( void ) const;
    void              ModifyXAxis( bCVector2 const & );
    void              ModifyYAxis( bCVector2 const & );
    void              Multiply( bCMatrix2 const & );
    void              Multiply( GEFloat );
    void              Negate( void );
    void              ReverseMultiply( bCMatrix2 const & );
    void              Rotate( GEFloat );
    void              RotateLocal( GEFloat );
    void              Scale( bCVector2 const & );
    void              Scale( GEFloat );
    void              SetElement( GEInt, GEInt, GEFloat );
    void              SetElement( GEInt, GEFloat );
    void              SetIdentity( void );
    void              SetMatrix( bCMatrix2 const & );
    void              SetMatrix( GEFloat );
    void              SetMatrix( GEFloat const [ bEElement_Count ] );
    void              SetMatrix( GEFloat const [ bERow_Count ][ bEColumn_Count ] );
    void              SetMatrix( bCVector2 const [ bERow_Count ] );
    void              SetRow( GEInt, bCVector2 const & );
    void              SetRow( GEInt, GEFloat const [ bEColumn_Count ] );
    void              SetToInverse( bCMatrix2 const & );                     // inline local: static bCMatrix2 matInverted;
    void              SetToProduct( bCMatrix2 const &, bCMatrix2 const & );  // inline local: static bCMatrix2 matProduct;
    void              SetToRotation( GEFloat );
    void              SetToScaling( bCVector2 const & );
    void              SetToScaling( GEFloat );
    void              Sub( bCMatrix2 const & );
    void              Transpose( void );
public:
    GEBool            operator == ( bCMatrix2 const & ) const;
    GEBool            operator != ( bCMatrix2 const & ) const;
    GEFloat &         operator [] ( GEInt );
    GEFloat           operator [] ( GEInt ) const;
    bCMatrix2         operator *  ( bCMatrix2 const & ) const;
    bCMatrix2         operator *  ( GEFloat ) const;
    bCVector2         operator *  ( bCVector2 const & ) const;
    bCMatrix2         operator -  ( bCMatrix2 const & ) const;
    bCMatrix2         operator -  ( void ) const;
    bCMatrix2         operator +  ( bCMatrix2 const & ) const;
    bCMatrix2         operator /  ( GEFloat ) const;
    GEFloat &         operator () ( GEInt, GEInt );
    bCVector2 &       operator () ( GEInt );
    bCVector2 const & operator () ( GEInt ) const;
    GEFloat           operator () ( GEInt, GEInt ) const;
    bCMatrix2         operator ~  ( void ) const;
    bCMatrix2 &       operator *= ( bCMatrix2 const & );
    bCMatrix2 &       operator *= ( GEFloat );
    bCMatrix2 &       operator += ( bCMatrix2 const & );
    bCMatrix2 &       operator -= ( bCMatrix2 const & );
    bCMatrix2 &       operator /= ( GEFloat );
    bCIStream &       operator << ( bCIStream & );
    bCOStream &       operator >> ( bCOStream & ) const;
    bCMatrix2 &       operator =  ( bCMatrix2 const & );
public:
    explicit bCMatrix2( GEFloat );
    explicit bCMatrix2( GEFloat const [ bEElement_Count ] );
    explicit bCMatrix2( GEFloat const [ bERow_Count ][ bEColumn_Count ] );
    explicit bCMatrix2( bCVector2 const [ bERow_Count ] );
             bCMatrix2( bCMatrix2 const & );
             bCMatrix2( void );
            ~bCMatrix2( void );
};

#endif
