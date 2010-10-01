#ifndef GE_MATRIX_H_INCLUDED
#define GE_MATRIX_H_INCLUDED

class GE_DLLIMPORT bCMatrix
{
public:
    enum bEElement
    {
        bEElement_11,
        bEElement_12,
        bEElement_13,
        bEElement_14,
        bEElement_21,
        bEElement_22,
        bEElement_23,
        bEElement_24,
        bEElement_31,
        bEElement_32,
        bEElement_33,
        bEElement_34,
        bEElement_41,
        bEElement_42,
        bEElement_43,
        bEElement_44,
        bEElement_Count,
        bEElement_ForceDWORD = GE_FORCE_DWORD
    };
    enum bERow
    {
        bERow_XAxis,
        bERow_YAxis,
        bERow_ZAxis,
        bERow_Translation,
        bERow_Count,
        bERow_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEColumn
    {
        bEColumn_X,
        bEColumn_Y,
        bEColumn_Z,
        bEColumn_Reserved,
        bEColumn_Count,
        bEColumn_ForceDWORD = GE_FORCE_DWORD
    };
private:
    union
    {
        GEFloat m_fElements[ bEElement_Count ];
        GEFloat m_fRowColumn[ bERow_Count ][ bEColumn_Count ];
    };
protected:
    bCVector4 &       AccessRow4( GEInt );
    bCVector &        AccessRow( GEInt );
    bCMatrix          GetInvertedExcentric( void ) const;
    void              GetInvertedExcentric( bCMatrix & ) const;
    bCVector4 const & GetRow4( GEInt ) const;
    bCVector const &  GetRow( GEInt ) const;
    void              GetRow( GEInt, bCVector4 & ) const;
    void              GetRow( GEInt, bCVector & ) const;
    void              InvertExcentric( void );
    void              ValidateReserved( void );
public:
    static bCMatrix const & GE_STDCALL GetIdentity( void );
    static void             GE_STDCALL GetIdentity( bCMatrix & );
    static bCMatrix const & GE_STDCALL GetZero( void );
public:
    GEFloat &         AccessElement( GEInt );
    GEFloat &         AccessElement( GEInt, GEInt );
    bCVector &        AccessTranslation( void );
    bCVector4 &       AccessTranslation4( void );
    bCVector &        AccessXAxis( void );
    bCVector4 &       AccessXAxis4( void );
    bCVector &        AccessYAxis( void );
    bCVector4 &       AccessYAxis4( void );
    bCVector &        AccessZAxis( void );
    bCVector4 &       AccessZAxis4( void );
    void              Add( bCMatrix const & );
    void              Clear( void );
    void              ClearRotation( void );
    void              Divide( GEFloat );
    bCVector          GetColumn( GEInt ) const;
    bCVector4         GetColumn4( GEInt ) const;
    void              GetColumn( GEInt, bCVector & ) const;
    void              GetColumn( GEInt, bCVector4 & ) const;
    void              GetColumn( GEInt, GEFloat [ bERow_Count ] ) const;
    GEFloat           GetDeterminant( void ) const;
    GEFloat           GetDeterminantAdjoint( GEInt, GEInt ) const;
    GEFloat           GetDeterminantRotation( void ) const;
    bCMatrix          GetDifference( bCMatrix const & ) const;
    void              GetDifference( bCMatrix &,  bCMatrix const & ) const;
    GEFloat           GetElement( GEInt ) const;
    GEFloat           GetElement( GEInt, GEInt ) const;
    void              GetElement( GEInt, GEFloat & ) const;
    void              GetElement( GEInt, GEInt, GEFloat & ) const;
    bCMatrix          GetInverted( void ) const;
    void              GetInverted( bCMatrix & ) const;
    bCMatrix          GetNegated( void ) const;
    void              GetNegated( bCMatrix & ) const;
    bCMatrix          GetOrthogonalized( void ) const;
    void              GetOrthogonalized( bCMatrix & ) const;
    bCMatrix          GetOrthonormalized( void ) const;
    void              GetOrthonormalized( bCMatrix & ) const;
    bCMatrix          GetProduct( bCMatrix const & ) const;
    bCMatrix          GetProduct( GEFloat ) const;
    void              GetProduct( bCMatrix &,  bCMatrix const & ) const;
    void              GetProduct( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetProductPrefix( bCMatrix const & ) const;
    void              GetProductPrefix( bCMatrix &,  bCMatrix const & ) const;
    bCMatrix          GetPureRotation( void ) const;
    bCVector          GetPureScaling( void ) const;
    bCMatrix          GetQuotient( GEFloat ) const;
    void              GetQuotient( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotated( bCAxisAngle const & ) const;
    bCMatrix          GetRotated( bCEulerAngles const & ) const;
    bCMatrix          GetRotated( bCQuaternion const & ) const;
    void              GetRotated( bCMatrix &,  bCAxisAngle const & ) const;
    void              GetRotated( bCMatrix &,  bCEulerAngles const & ) const;
    void              GetRotated( bCMatrix &,  bCQuaternion const & ) const;
    bCMatrix          GetRotatedByAxisX( GEFloat ) const;
    void              GetRotatedByAxisX( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedByAxisY( GEFloat ) const;
    void              GetRotatedByAxisY( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedByAxisZ( GEFloat ) const;
    void              GetRotatedByAxisZ( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedByLocalAxisX( GEFloat ) const;
    void              GetRotatedByLocalAxisX( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedByLocalAxisY( GEFloat ) const;
    void              GetRotatedByLocalAxisY( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedByLocalAxisZ( GEFloat ) const;
    void              GetRotatedByLocalAxisZ( bCMatrix &,  GEFloat ) const;
    bCMatrix          GetRotatedLocal( bCAxisAngle const & ) const;
    bCMatrix          GetRotatedLocal( bCEulerAngles const & ) const;
    bCMatrix          GetRotatedLocal( bCQuaternion const & ) const;
    void              GetRotatedLocal( bCMatrix &,  bCAxisAngle const & ) const;
    void              GetRotatedLocal( bCMatrix &,  bCEulerAngles const & ) const;
    void              GetRotatedLocal( bCMatrix &,  bCQuaternion const & ) const;
    void              GetRotation( bCMatrix & ) const;
    void              GetRotation( bCMatrix3 & ) const;
    bCMatrix          GetRotation( void ) const;
    bCMatrix3         GetRotation3( void ) const;
    void              GetRow( GEInt, GEFloat [ bEColumn_Count ] ) const;
    bCMatrix          GetSum( bCMatrix const & ) const;
    void              GetSum( bCMatrix &,  bCMatrix const & ) const;
    void              GetTranslation( bCVector & ) const;
    void              GetTranslation( bCVector4 & ) const;
    bCVector const &  GetTranslation( void ) const;
    bCVector4 const & GetTranslation4( void ) const;
    void              GetXAxis( bCVector & ) const;
    void              GetXAxis( bCVector4 & ) const;
    bCVector const &  GetXAxis( void ) const;
    bCVector4 const & GetXAxis4( void ) const;
    void              GetYAxis( bCVector & ) const;
    void              GetYAxis( bCVector4 & ) const;
    bCVector const &  GetYAxis( void ) const;
    bCVector4 const & GetYAxis4( void ) const;
    void              GetZAxis( bCVector & ) const;
    void              GetZAxis( bCVector4 & ) const;
    bCVector const &  GetZAxis( void ) const;
    bCVector4 const & GetZAxis4( void ) const;
    void              Invert( void );
    GEBool            IsEqual( bCMatrix const & ) const;
    GEBool            IsExcentric( void ) const;
    GEBool            IsIdentity( void ) const;
    GEBool const      IsOrthogonal( void ) const;
    GEBool const      IsOrthonormal( void ) const;
    GEBool const      IsValid( void ) const;
    void              LookAt( bCVector const &,  bCVector const & );
    void              LookAt( bCVector const & );
    void              ModifyRotation( bCAxisAngle const & );
    void              ModifyRotation( bCEulerAngles const & );
    void              ModifyRotation( bCMatrix3 const & );
    void              ModifyRotation( bCQuaternion const & );
    void              ModifyRotationAxisX( GEFloat );
    void              ModifyRotationAxisY( GEFloat );
    void              ModifyRotationAxisZ( GEFloat );
    void              ModifyScaling( bCVector const & );
    void              ModifyScaling( GEFloat );
    void              ModifyTranslation( bCVector const & );
    void              ModifyXAxis( bCVector const & );
    void              ModifyXAxis( bCVector4 const & );
    void              ModifyYAxis( bCVector const & );
    void              ModifyYAxis( bCVector4 const & );
    void              ModifyZAxis( bCVector const & );
    void              ModifyZAxis( bCVector4 const & );
    void              Multiply( bCMatrix const & );
    void              Multiply( GEFloat );
    void              Negate( void );
    void              Orthogonalize( void );
    void              Orthonormalize( void );
    void              PrintDebug( bCString & );
    void              ReverseMultiply( bCMatrix const & );
    void              Rotate( bCAxisAngle const & );
    void              Rotate( bCEulerAngles const & );
    void              Rotate( bCQuaternion const & );
    void              RotateAxisX( GEFloat );
    void              RotateAxisY( GEFloat );
    void              RotateAxisZ( GEFloat );
    void              RotateLocal( bCAxisAngle const & );
    void              RotateLocal( bCEulerAngles const & );
    void              RotateLocal( bCQuaternion const & );
    void              RotateLocalAxisX( GEFloat );
    void              RotateLocalAxisY( GEFloat );
    void              RotateLocalAxisZ( GEFloat );
    void              Scale( bCVector const & );
    void              Scale( GEFloat );
    void              SetElement( GEInt, GEInt, GEFloat );
    void              SetElement( GEInt, GEFloat );
    void              SetIdentity( void );
    void              SetIdentityRotation( void );
    void              SetMatrix( bCMatrix const & );
    void              SetMatrix( bCAxisAngle const &, bCVector const & );
    void              SetMatrix( bCEulerAngles const &, bCVector const & );
    void              SetMatrix( bCMotion const & );
    void              SetMatrix( bCQuaternion const &, bCVector const & );
    void              SetMatrix( bCVector const &, bCEulerAngles const &, bCVector const & );
    void              SetMatrix( bCVector const &, bCQuaternion const &, bCVector const & );
    void              SetMatrix( GEFloat );
    void              SetMatrix( GEFloat const [ bERow_Count ][ bEColumn_Count ] );
    void              SetMatrix( GEFloat const [ bEElement_Count ] );
    void              SetMatrix( bCVector4 const [ bERow_Count ] );
    void              SetMatrix( bCVector const [ bERow_Count ] );
    void              SetRow( GEInt, bCVector4 const & );
    void              SetRow( GEInt, bCVector const & );
    void              SetRow( GEInt, GEFloat const [ bEColumn_Count ] );
    void              SetToCrossProduct( bCVector const & );
    void              SetToProduct( bCMatrix const &,  bCMatrix const & );  // inline local: static bCMatrix matProduct;
    void              SetToRotation( bCAxisAngle const & );
    void              SetToRotation( bCEulerAngles const & );
    void              SetToRotation( bCQuaternion const & );
    void              SetToRotationAxisX( GEFloat );
    void              SetToRotationAxisY( GEFloat );
    void              SetToRotationAxisZ( GEFloat );
    void              SetToScaling( bCVector const & );
    void              SetToScaling( GEFloat );
    void              SetToTranslation( bCVector const & );
    void              SetXAxis( bCVector4 const & );
    void              SetXAxis( bCVector const & );
    void              SetYAxis( bCVector4 const & );
    void              SetYAxis( bCVector const & );
    void              SetZAxis( bCVector4 const & );
    void              SetZAxis( bCVector const & );
    void              Sub( bCMatrix const & );
    void              Transpose( void );
    void              TransposeRotation( void );

public:
    GEBool           operator == ( bCMatrix const & ) const;
    GEBool           operator != ( bCMatrix const & ) const;
    GEFloat &        operator [] ( GEInt );
    GEFloat          operator [] ( GEInt ) const;
    bCMatrix         operator *  ( bCMatrix const & ) const;
    bCMatrix         operator *  ( bCAxisAngle const & ) const;
    bCMatrix         operator *  ( bCEulerAngles const & ) const;
    bCMatrix         operator *  ( bCQuaternion const & ) const;
    bCMatrix         operator *  ( GEFloat ) const;
    bCVector         operator *  ( bCVector const & ) const;
    bCMatrix         operator -  ( bCMatrix const & ) const;
    bCMatrix         operator -  ( void ) const;
    bCMatrix         operator +  ( bCMatrix const & ) const;
    bCMatrix         operator /  ( GEFloat ) const;
    GEFloat &        operator () ( GEInt, GEInt );
    bCVector &       operator () ( GEInt );
    bCVector const & operator () ( GEInt ) const;
    GEFloat          operator () ( GEInt, GEInt ) const;
    bCMatrix         operator ~  ( void ) const;
    bCMatrix &       operator *= ( bCMatrix const & );
    bCMatrix &       operator *= ( bCAxisAngle const & );
    bCMatrix &       operator *= ( bCEulerAngles const & );
    bCMatrix &       operator *= ( bCQuaternion const & );
    bCMatrix &       operator *= ( GEFloat );
    bCMatrix &       operator += ( bCMatrix const & );
    bCMatrix &       operator -= ( bCMatrix const & );
    bCMatrix &       operator /= ( GEFloat );
    bCIStream &      operator << ( bCIStream & );
    bCOStream &      operator >> ( bCOStream & ) const;
    bCMatrix &       operator =  ( bCMatrix const & );
public:
             bCMatrix( bCAxisAngle const &,  bCVector const & );
             bCMatrix( bCEulerAngles const &,  bCVector const & );
             bCMatrix( bCQuaternion const &,  bCVector const & );
    explicit bCMatrix( GEFloat );
    explicit bCMatrix( GEFloat const [ bEElement_Count ] );
    explicit bCMatrix( GEFloat [ bERow_Count ][ bEColumn_Count ] );
    explicit bCMatrix( bCVector const [ bERow_Count ] );
    explicit bCMatrix( bCVector4 const [ bERow_Count ] );
             bCMatrix( bCMatrix const & );
             bCMatrix( void );
            ~bCMatrix( void );
};

typedef bCMatrix bCMatrix4;

#endif
