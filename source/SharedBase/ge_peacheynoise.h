#ifndef GE_PEACHEYNOISE_H_INCLUDED
#define GE_PEACHEYNOISE_H_INCLUDED

class GE_DLLIMPORT bCPeacheyNoise :
    public bCNoise
{
public:
    enum bEAlgorithm
    {
        //FIXME: bCPeacheyNoise::bEAlgorithm constants.
        bEAlgorithm_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual void    SetSeed( GEInt );
public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat ) const;
public: virtual        ~bCPeacheyNoise( void );
private:
    //FIXME: bCPeacheyNoise private members.
protected:
    static GEU8 * ms_pu8Permutations;
protected:
    GEFloat CatRom2( GEFloat ) const;
    void    CopyFrom( bCPeacheyNoise const & );
    void    CopyTo( bCPeacheyNoise & ) const;
    GEFloat GLattice( GEInt, GEInt, GEInt, GEFloat, GEFloat, GEFloat ) const;
    void    Initialize( GEInt );
    void    Invalidate( void );
    GEBool  Read( bCIStream & );
    GEFloat Spline( GEFloat, GEInt, GEFloat const * ) const;
    GEFloat VLattice( GEInt, GEInt, GEInt ) const;
    void    Write( bCOStream & ) const;
public:
    static bCPeacheyNoise & GE_STDCALL GetPeacheyNoise( void );
public:
    GEFloat     GNoise( GEFloat, GEFloat, GEFloat ) const;
    GEFloat     GVNoise( GEFloat, GEFloat, GEFloat, GEFloat ) const;
    bEAlgorithm GetAlgorithm( void ) const;
    void        SetAlgorithm( bEAlgorithm );
    GEFloat     SCNoise( GEFloat, GEFloat, GEFloat ) const;
    GEFloat     VCNoise( GEFloat, GEFloat, GEFloat ) const;
    GEFloat     VNoise( GEFloat, GEFloat, GEFloat ) const;
protected:
    bCIStream &      operator << ( bCIStream & );
    bCOStream &      operator >> ( bCOStream & ) const;
    bCPeacheyNoise & operator =  ( bCPeacheyNoise const & );
protected:
    bCPeacheyNoise( bCPeacheyNoise const & );
    bCPeacheyNoise( void );
};

#endif
