#ifndef GE_POINT_H_INCLUDED
#define GE_POINT_H_INCLUDED

class GE_DLLIMPORT bCPoint
{
private:
    GEI32 m_i32X;   // 0000
    GEI32 m_i32Y;   // 0004
    // sizeof(bCPoint) 0008
public:
    GEI32 & AccessX( void );
    GEI32 & AccessY( void );
    void    Clear( void );
    bCPoint GetInvScaled( GEFloat ) const;
    bCPoint GetScaled( GEFloat ) const;
    GEI32   GetX( void ) const;
    void    GetX( GEI32 & ) const;
    GEI32   GetY( void ) const;
    void    GetY( GEI32 & ) const;
    void    InvScale( GEFloat );
    void    InvTranslate( bCPoint const & );
    void    InvTranslate( GEI32, GEI32 );
    void    Scale( GEFloat );
    void    SetPoint( bSPoint const & );
    void    SetPoint( bCPoint const & );
    void    SetPoint( GEI32, GEI32 );
    void    SetX( GEI32 );
    void    SetY( GEI32 );
    void    Translate( bCPoint const & );
    void    Translate( GEI32, GEI32 );
public:
                    operator bSPoint &       ( void );
                    operator bSPoint *       ( void );
                    operator bSPoint const & ( void ) const;
                    operator bSPoint const * ( void ) const;
    bCPoint const & operator =               ( bSPoint const & );
    GEBool          operator ==              ( bCPoint const & ) const;
    GEBool          operator !=              ( bCPoint const & ) const;
    GEI32 &         operator []              ( GEInt );
    GEI32           operator []              ( GEInt ) const;
    bCPoint         operator *               ( float ) const;
    bCPoint         operator -               ( bCPoint const & ) const;
    bCPoint         operator -               ( void ) const;
    bCPoint         operator +               ( bCPoint const & ) const;
    bCPoint const & operator +               ( void ) const;
    bCPoint         operator /               ( GEFloat ) const;
    bCPoint &       operator *=              ( GEFloat );
    bCPoint const & operator +=              ( bCPoint const & );
    bCPoint const & operator -=              ( bCPoint const & );
    bCPoint &       operator /=              ( GEFloat );
    bCIStream &     operator <<              ( bCIStream & );
    bCOStream &     operator >>              ( bCOStream & ) const;
    bCPoint const & operator =               ( bCPoint const & );
public:
    bCPoint( bSPoint const & );
    bCPoint( GEI32, GEI32 );
    bCPoint( bCPoint const & );
    bCPoint( void );
   ~bCPoint( void );
};

#endif
