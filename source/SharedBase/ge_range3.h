#ifndef GE_RANGE3_H_INCLUDED
#define GE_RANGE3_H_INCLUDED

class GE_DLLIMPORT bCRange3
{
private:
    bCVector m_vecMin;
    bCVector m_vecMax;
public:
    bCVector GetCenter( void ) const;
    void     GetCenter( bCVector & ) const;
    bCVector GetMagnitude( void ) const;
    void     GetMagnitude( bCVector & ) const;
    bCVector GetRandom( void ) const;
    void     GetRandom( bCVector & ) const;
    void     SetAverageAndVariance( bCVector const &, bCVector const & );
    void     SetMinMax( bCVector const &, bCVector const & );
public:
    GEBool      operator == ( bCRange3 const & ) const;
    GEBool      operator != ( bCRange3 const & ) const;
    bCIStream & operator << ( bCIStream & );
    bCOStream & operator >> ( bCOStream & ) const;
    bCRange3 &  operator =  ( bCRange3 const & );
public:
    bCRange3( bCRange3 const & );
    bCRange3( void );
   ~bCRange3( void );
};

#endif
