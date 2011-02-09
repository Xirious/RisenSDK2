#ifndef GE_PERLINNOISE_H_INCLUDED
#define GE_PERLINNOISE_H_INCLUDED

class GE_DLLIMPORT bCPerlinNoise :
    public bCNoise
{
public:
    enum bEAlgorithm
    {
        bEAlgorithm_Default,
        bEAlgorithm_Improved,
        bEAlgorithm_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual void    SetSeed( GEInt );
public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat ) const;
public: virtual        ~bCPerlinNoise( void );
private:
    bEAlgorithm m_enumAlgorithm;
    GEFloat     m_pfTable[ 256 + 256 + 2 ];
    GEFloat     m_pfGrad3[ 256 + 256 + 2 ][ 3 ];
    GEFloat     m_pfGrad2[ 256 + 256 + 2 ][ 2 ];
    GEFloat     m_pfGrad1[ 256 + 256 + 2 ];
protected:
    static GEInt * ms_piPermutations;
protected:
    void   CopyFrom( bCPerlinNoise const & );
    void   CopyTo( bCPerlinNoise & ) const;
    void   Initialize( GEInt );
    void   Invalidate( void );
    GEBool Read( bCIStream & );
    void   Write( bCOStream & ) const;
public:
    static bCPerlinNoise & GE_STDCALL GetPerlinNoise( void );
public:
    bEAlgorithm GetAlgorithm( void ) const;
    GEFloat     ImprovedNoise( GEFloat ) const;
    GEFloat     ImprovedNoise( GEFloat, GEFloat ) const;
    GEFloat     ImprovedNoise( GEFloat, GEFloat, GEFloat ) const;
    GEFloat     Noise( GEFloat ) const;
    GEFloat     Noise( GEFloat, GEFloat ) const;
    GEFloat     Noise( GEFloat, GEFloat, GEFloat ) const;
    void        SetAlgorithm( bEAlgorithm );
protected:
    bCIStream &     operator << ( bCIStream & );
    bCOStream &     operator >> ( bCOStream & ) const;
    bCPerlinNoise & operator =  ( bCPerlinNoise const & );
protected:
    bCPerlinNoise( bCPerlinNoise const & );
    bCPerlinNoise( void );
};

#endif
