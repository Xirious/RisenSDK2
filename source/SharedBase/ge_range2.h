#ifndef GE_RANGE2_H_INCLUDED
#define GE_RANGE2_H_INCLUDED

class GE_DLLIMPORT bCRange2
{
private:
    bCVector2 m_vecMin;
    bCVector2 m_vecMax;
public:
    bCVector2 GetCenter( void ) const;
    void      GetCenter( bCVector2 & ) const;
    bCVector2 GetMagnitude( void ) const;
    void      GetMagnitude( bCVector2 & ) const;
    bCVector2 GetRandom( void ) const;
    void      GetRandom( bCVector2 & ) const;
    void      SetAverageAndVariance( bCVector2 const &, bCVector2 const & );
    void      SetMinMax( bCVector2 const &, bCVector2 const & );
public:
    GEBool      operator == ( bCRange2 const & ) const;
    GEBool      operator != ( bCRange2 const & ) const;
    bCIStream & operator << ( bCIStream & );
    bCOStream & operator >> ( bCOStream & ) const;
    bCRange2 &  operator =  ( bCRange2 const & );
public:
    bCRange2( bCRange2 const & );
    bCRange2( void );
   ~bCRange2( void );
};

#endif
