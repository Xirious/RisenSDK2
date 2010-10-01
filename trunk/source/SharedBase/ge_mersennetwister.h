#ifndef GE_MERSENNETWISTER_H_INCLUDED
#define GE_MERSENNETWISTER_H_INCLUDED

class GE_DLLIMPORT bCMersenneTwister
{
private:
    GEU32 m_pu32State[ 624 ];
private:
    void InitSeed( void );
public:
    static bCMersenneTwister & GE_STDCALL GetInstance( void );
public:
    GEInt   Rand( GEInt );
    GEInt   Rand( GEInt, GEInt );
    GEU32   Rand( GEU32 );
    GEU32   Rand( GEU32, GEU32 );
    GEFloat Rand( GEFloat );
    GEFloat Rand( GEFloat, GEFloat );
    GEInt   RandCount( GEInt );
    GEInt   RandCount( GEInt, GEInt );
    GEU32   RandCount( GEU32 );
    GEU32   RandCount( GEU32, GEU32 );
    GEFloat RandCount( GEFloat );
    GEFloat RandCount( GEFloat, GEFloat );
    GEFloat RandF2( void );
    GEFloat RandF3( void );
    GEFloat RandF( void );
    GEU32   RandU31( void );
    GEU32   RandU32( void );
private:
    bCMersenneTwister & operator = ( bCMersenneTwister const & );
private:
    bCMersenneTwister( bCMersenneTwister const & );
    bCMersenneTwister( void );
public:
   ~bCMersenneTwister( void );
};

#endif
