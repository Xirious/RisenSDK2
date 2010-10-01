#ifndef GE_RANDOM_H_INCLUDED
#define GE_RANDOM_H_INCLUDED

class GE_DLLIMPORT bCRandom
{
private:
    GEInt mutable m_iSeed;
                  GE_PADDING( 4 )
    GEI64 mutable m_i64State;
protected:
    void Invalidate( void );
public:
    static bCRandom const & GE_STDCALL GetRandom( void );
public:
    GEDouble DRand48( GEDouble, GEDouble ) const;
    GEDouble DRand48( void ) const;
    GEFloat  FRand48( GEFloat, GEFloat ) const;
    GEFloat  FRand48( void ) const;
    GEInt    GetValue( GEInt, GEInt ) const;
    GEInt    GetValue( void ) const;
    GEFloat  GetValue( GEFloat, GEFloat ) const;
    void     SetSeed( GEInt ) const;
    void     SetTimedSeed( void ) const;
protected:
    bCRandom & operator = ( bCRandom const & );
protected:
    bCRandom( bCRandom const & );
    bCRandom( void );
public:
   ~bCRandom( void );
};

#endif
