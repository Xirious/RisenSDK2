#ifndef GE_VECTOR4_H_INCLUDED
#define GE_VECTOR4_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4201 )  // nonstandard extension used : nameless struct/union

class GE_DLLIMPORT bCVector4
{
public:
    enum bECoordinate
    {
        bECoordinate_X,
        bECoordinate_Y,
        bECoordinate_Z,
        bECoordinate_W,
        bECoordinate_Count,
        bECoordinate_ForceDWORD = GE_FORCE_DWORD
    };
private:
    union
    {
        GEFloat m_fCoordinates[ bECoordinate_Count ];
        struct
        {
            GEFloat m_fX;
            GEFloat m_fY;
            GEFloat m_fZ;
            GEFloat m_fW;
        };
    };
public:
    static GEFloat GE_STDCALL DotProduct( bCVector4 const &, bCVector4 const & );
public:
    GEFloat &         AccessCoordinate( GEInt );
    GEFloat (&        AccessCoordinates( void )) [ bECoordinate_Count ];
    GEFloat &         AccessW( void );
    GEFloat &         AccessX( void );
    GEFloat &         AccessY( void );
    GEFloat &         AccessZ( void );
    void              Clear( void );
    GEFloat const &   GetCoordinate( GEInt ) const;
    void              GetCoordinate( GEInt, GEFloat & ) const;
    GEFloat const (&  GetCoordinates( void ) const) [ bECoordinate_Count ];
    void              GetCoordinates( GEFloat &, GEFloat &, GEFloat &, GEFloat & ) const;
    void              GetCoordinates( GEFloat [ bECoordinate_Count ] ) const;
    GEFloat           GetDotProduct( bCVector4 const & ) const;
    bCVector4         GetInvScaled( bCVector4 const & ) const;
    bCVector4         GetInvScaled( GEFloat ) const;
    bCVector4         GetInvTransformed( bCMatrix const & ) const;
    bCVector4         GetInvTranslated( bCVector4 const & ) const;
    bCVector4         GetInvTranslated( GEFloat ) const;
    bCVector4         GetInverted( void ) const;
    GEFloat           GetMagnitude( void ) const;
    GEFloat           GetMagnitudeApprox( void ) const;
    GEFloat           GetMagnitudeNormalize( void );
    bCVector4         GetNormalized( void ) const;
    bCVector4         GetScaled( bCVector4 const & ) const;
    bCVector4         GetScaled( GEFloat ) const;
    GEFloat           GetSquareMagnitude( void ) const;
    bCVector4         GetTransformed( bCMatrix const & ) const;
    bCVector4         GetTranslated( bCVector4 const & ) const;
    bCVector4         GetTranslated( GEFloat ) const;
    GEFloat           GetW( void ) const;
    void              GetW( GEFloat & ) const;
    GEFloat           GetX( void ) const;
    void              GetX( GEFloat & ) const;
    GEFloat           GetY( void ) const;
    void              GetY( GEFloat & ) const;
    GEFloat           GetZ( void ) const;
    void              GetZ( GEFloat & ) const;
    void              InvScale( bCVector4 const & );
    void              InvScale( GEFloat );
    void              InvTransform( bCMatrix const & );
    void              InvTranslate( bCVector4 const & );
    void              InvTranslate( GEFloat );
    void              Invert( void );
    GEBool            IsEqual( bCVector4 const & ) const;
    bCVector4 const & Normalize( void );
    bCVector4 const & NormalizeApprox( void );
    bCVector4 const & NormalizeSafe( void );
    void              Scale( bCVector4 const & );
    void              Scale( GEFloat );
    void              SetCoordinate( GEInt, GEFloat );
    void              SetCoordinates( GEFloat, GEFloat, GEFloat, GEFloat );
    void              SetCoordinates( GEFloat const [ bECoordinate_Count ] );
    void              SetTransformed( bCVector4 const &, bCMatrix const & );
    void              SetVector( bCVector4 const & );
    void              SetVector( GEFloat );
    void              SetVector( GEFloat, GEFloat, GEFloat, GEFloat );
    void              SetW( GEFloat const & );
    void              SetX( GEFloat const & );
    void              SetY( GEFloat const & );
    void              SetZ( GEFloat const & );
    void              Transform( bCMatrix const & );
    void              Translate( bCVector4 const & );
    void              Translate( GEFloat );
public:
    GEBool          operator == ( bCVector4 const & ) const;
    GEBool          operator != ( bCVector4 const & ) const;
    GEFloat &       operator [] ( GEInt );
    GEFloat const & operator [] ( GEInt ) const;
    bCVector4       operator *  ( bCMatrix const & ) const;
    bCVector4       operator *  ( GEFloat ) const;
    bCVector4       operator -  ( bCVector4 const & ) const;
    bCVector4       operator -  ( void ) const;
    bCVector4       operator +  ( bCVector4 const & ) const;
    bCVector4       operator /  ( bCMatrix const & ) const;
    bCVector4       operator /  ( GEFloat ) const;
    bCVector4 &     operator *= ( bCMatrix const & );
    bCVector4 &     operator *= ( GEFloat );
    bCVector4 &     operator += ( bCVector4 const & );
    bCVector4 &     operator -= ( bCVector4 const & );
    bCVector4 &     operator /= ( bCMatrix const & );
    bCVector4 &     operator /= ( GEFloat );
    bCIStream &     operator << ( bCIStream & );
    bCOStream &     operator >> ( bCOStream & ) const;
    bCVector4 &     operator =  ( bCVector4 const & );
public:
    explicit bCVector4( GEFloat );
    explicit bCVector4( GEFloat const [ bECoordinate_Count ] );
             bCVector4( GEFloat, GEFloat, GEFloat, GEFloat );
             bCVector4( bCVector4 const & );
             bCVector4( void );
            ~bCVector4( void );
};

#pragma warning( pop )

#endif
