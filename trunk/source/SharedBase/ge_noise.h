#ifndef GE_NOISE_H_INCLUDED
#define GE_NOISE_H_INCLUDED

enum bENoiseAmplitude
{
    bEAmplitude_UsePersistence,
    bEAmplitude_InverseFrequency,
    bEAmplitude_ForceDWORD = GE_FORCE_DWORD
};

enum bENoiseTurbulence
{
    bETurbulence_FractalSum,
    bETurbulence_FractalAbsSum,
    bETurbulence_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCNoise
{
public: virtual void    SetSeed( GEInt ) = 0;
public: virtual GEFloat GetNoise( GEFloat ) const = 0;
public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const = 0;
public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const = 0;
public: virtual        ~bCNoise( void );
protected:
    void CopyFrom( bCNoise const & );
    void CopyTo( bCNoise & ) const;
public:
    GEFloat GetNoise( bCVector2 const & ) const;
    GEFloat GetNoise( bCVector const & ) const;
    GEFloat GetTurbulence( bCVector2 const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
    GEFloat GetTurbulence( bCVector const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
    GEFloat GetTurbulence( GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
    GEFloat GetTurbulence( GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
    GEFloat GetTurbulence( GEFloat, GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
    void    SetTimedSeed( void );
protected:
    bCNoise & operator = ( bCNoise const & );
protected:
    bCNoise( bCNoise const & );
    bCNoise( void );
};

#endif
