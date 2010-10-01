#ifndef GE_RANGE1_H_INCLUDED
#define GE_RANGE1_H_INCLUDED

class GE_DLLIMPORT bCRange1
{
private:
    GEFloat m_fMin;
    GEFloat m_fMax;
public:
    GEFloat GetCenter( void ) const;
    void    GetCenter( GEFloat & ) const;
    GEFloat GetClamped( GEFloat ) const;
    GEFloat GetLerp( GEFloat ) const;
    GEFloat GetMagnitude( void ) const;
    void    GetMagnitude( GEFloat & ) const;
    GEFloat GetRandom( void ) const;
    void    GetRandom( GEFloat & ) const;
    GEInt   GetRandomInt( void ) const;
    void    GetRandomInt( GEInt & ) const;
    GEFloat GetRelativePos( GEFloat ) const;
    void    Normalize( void );
    void    SetAverageAndVariance( GEFloat, GEFloat );
    void    SetMinMax( GEFloat, GEFloat );
public:
    GEBool      operator == ( bCRange1 const & ) const;
    GEBool      operator != ( bCRange1 const & ) const;
    bCRange1 &  operator =  ( bCRange1 const & );
    bCOStream & operator >> ( bCOStream & ) const;
    bCIStream & operator << ( bCIStream & );
};

#endif
