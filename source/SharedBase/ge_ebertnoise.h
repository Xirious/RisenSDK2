#ifndef GE_EBERTNOISE_H_INCLUDED
#define GE_EBERTNOISE_H_INCLUDED

class GE_DLLIMPORT bCEbertNoise :
    public bCNoise
{
public: virtual void    SetSeed( GEInt );
public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
public: virtual GEFloat GetNoise( GEFloat ) const;
public: virtual        ~bCEbertNoise( void );
private:
    //FIXME: bCEbertNoise private members.
protected:
    void   CopyFrom( bCEbertNoise const & );
    void   CopyTo( bCEbertNoise & ) const;
    void   Initialize( GEInt );
    void   Invalidate( void );
    GEBool Read( bCIStream & );
    void   Write( bCOStream & ) const;
public:
    static bCEbertNoise & GE_STDCALL GetEbertNoise( void );
protected:
    bCIStream &    operator << ( bCIStream & );
    bCOStream &    operator >> ( bCOStream & ) const;
    bCEbertNoise & operator =  ( bCEbertNoise const & );
protected:
    bCEbertNoise( bCEbertNoise const & );
    bCEbertNoise( void );
};

#endif
