#ifndef GE_RECT_H_INCLUDED
#define GE_RECT_H_INCLUDED

class GE_DLLIMPORT bCRect
{
public:
    enum bECoordinate
    {
        bECoordinate_Left,
        bECoordinate_Top,
        bECoordinate_Right,
        bECoordinate_Bottom,
        bECoordinate_Count,
        bECoordinate_ForceDWORD = GE_FORCE_DWORD
    };
    enum bEPoint
    {
        bEPoint_TopLeft,
        bEPoint_BottomRight,
        bEPoint_Count,
        bEPoint_ForceDWORD = GE_FORCE_DWORD
    };
private:
    bCPoint m_TopLeft;      // 0000
    bCPoint m_BottomRight;  // 0008
    // sizeof(bCRect)          0010
public:
    GEI32 &         AccessBottom( void );
    bCPoint &       AccessBottomRight( void );
    GEI32 &         AccessCoordinate( GEInt );
    GEI32 &         AccessLeft( void );
    bCPoint &       AccessPoint( GEInt );
    GEI32 &         AccessRight( void );
    GEI32 &         AccessTop( void );
    bCPoint &       AccessTopLeft( void );
    GEBool          Contains( bCRect const & ) const;
    GEBool          Contains( bCPoint const & ) const;
    GEBool          ContainsExclusive( bCPoint const & ) const;
    GEBool          ContainsInclusive( bCPoint const & ) const;
    GEI32           GetBottom( void ) const;
    void            GetBottom( GEI32 & ) const;
    bCPoint const & GetBottomRight( void ) const;
    void            GetBottomRight( bCPoint & ) const;
    bCPoint         GetCenterPoint( void ) const;
    GEI32           GetCoordinate( GEInt ) const;
    void            GetCoordinate( GEI32 &, GEInt ) const;
    GEI32           GetHeight( void ) const;
    bCRect          GetIntersected( bCRect const & ) const;
    GEI32           GetLeft( void ) const;
    void            GetLeft( GEI32 & ) const;
    bCPoint         GetMagnitude( void ) const;
    bCRect          GetMerged( bCRect const & ) const;
    bCPoint const & GetPoint( GEInt ) const;
    void            GetPoint( bCPoint &, GEInt ) const;
    GEI32           GetRight( void ) const;
    void            GetRight( GEI32 & ) const;
    GEI32           GetTop( void ) const;
    void            GetTop( GEI32 & ) const;
    bCPoint const & GetTopLeft( void ) const;
    void            GetTopLeft( bCPoint & ) const;
    GEI32           GetWidth( void ) const;
    void            Inflate( GEI32 const & );
    void            Intersect( bCRect const & );
    GEBool          Intersects( bCRect const & ) const;
    void            InvTranslate( bCPoint const & );
    void            InvTranslate( GEI32, GEI32 );
    void            Invalidate( void );
    GEBool          IsEmpty( void ) const;
    GEBool          IsNormalized( void ) const;
    GEBool          IsValid( void ) const;
    void            Merge( bCRect const & );
    void            Merge( bCPoint const & );
    void            Normalize( void );
    void            SetBottom( GEI32 );
    void            SetBottomRight( bCPoint const & );
    void            SetCoordinate( GEI32, GEInt );
    void            SetLeft( GEI32 );
    void            SetPoint( bCPoint const &, GEInt );
    void            SetPosX( GEI32 );
    void            SetPosY( GEI32 );
    void            SetRect( bSRect const & );
    void            SetRect( bCRect const & );
    void            SetRect( bCPoint const &, bCPoint const & );
    void            SetRect( GEI32, GEI32, GEI32, GEI32 );
    void            SetRect( void );
    void            SetRight( GEI32 );
    void            SetSizeX( GEI32 );
    void            SetSizeY( GEI32 );
    void            SetTop( GEI32 );
    void            SetTopLeft( bCPoint const & );
    void            Shrink( bCRect const & );
    void            Shrink( bCPoint const & );
    void            Translate( bCPoint const & );
    void            Translate( GEI32, GEI32 );
    void            Widen( bCRect const & );
    void            Widen( bCPoint const & );
public:
                    operator bSRect &       ( void );
                    operator bSRect *       ( void );
                    operator bSRect const & ( void ) const;
                    operator bSRect const * ( void ) const;
    bCRect &        operator =              ( bSRect const & );
    GEBool          operator ==             ( bCRect const & ) const;
    GEBool          operator !=             ( bCRect const & ) const;
    bCPoint &       operator []             ( GEInt );
    bCPoint const & operator []             ( GEInt ) const;
    bCRect          operator -              ( bCPoint const & ) const;
    bCRect          operator +              ( bCPoint const & ) const;
    bCRect          operator &              ( bCRect const & ) const;
    GEI32 &         operator ()             ( GEInt );
    GEI32           operator ()             ( GEInt ) const;
    bCRect          operator |              ( bCRect const & ) const;
    bCRect &        operator +=             ( bCPoint const & );
    bCRect &        operator -=             ( bCPoint const & );
    bCRect &        operator &=             ( bCRect const & );
    bCRect &        operator |=             ( bCRect const & );
    bCIStream &     operator <<             ( bCIStream & );
    bCOStream &     operator >>             ( bCOStream & ) const;
    bCRect &        operator =              ( bCRect const & );
public:
    bCRect( bSRect const & );
    bCRect( GEI32, GEI32, GEI32, GEI32 );
    bCRect( bCPoint const &, bCPoint const & );
    bCRect( bCRect const & );
    bCRect( void );
   ~bCRect( void );
};

#endif
