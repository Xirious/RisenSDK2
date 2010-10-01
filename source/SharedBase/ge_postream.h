#ifndef GE_POSTREAM_H_INCLUDED
#define GE_POSTREAM_H_INCLUDED

class GE_DLLIMPORT bCPOStream :
    public bCMemoryStream
{
public: using bCIStream::Read;
public: virtual GEU32    Read( bCString & );
public: virtual GEU32    Read( GELPVoid, GEU32 );
public: virtual      ~bCPOStream( void );
public: using bCOStream::Write;
public: virtual GEU32    Write( bCString const & );
public: virtual GEU32    Write( GELPCVoid, GEU32 );
private:
    GEBool m_bIsMain;
    GEBool m_bIsForcedLegacyMode;
           GE_PADDING( 6 )
protected:
    static GEBool                    ms_bLegacyMode;
    static bCPOStream *              ms_pMainPOStream;
    static bTObjArray< bCString > *  ms_parrStringList;
    static bTStringValMap< GEI32 > * ms_pmapStringSaveHashmap;
protected:
    void Invalidate( void );
public:
    static void   GE_STDCALL DisableLegacyMode( void );
    static void   GE_STDCALL GetStringList( bTObjArray< bCString > * &, bTStringValMap< GEI32 > * & );
    static GEBool GE_STDCALL IsInLegacyMode( void );
    static void   GE_STDCALL SetStringList( bTObjArray< bCString > *, bTStringValMap< GEI32 > * );
public:
    void   ClearStringHeaderMap( void );
    void   Create( void );
    void   Destroy( void );
    void   FakeMainPOStream( GEBool );
    void   ForceLegacyMode( void );
    GEBool IsForcedLegacyMode( void ) const;
    GEBool IsMain( void ) const;
    GEBool ReadFile( bCIStream & );
    GEBool WriteFile( bCOStream & );
public:
    bCPOStream & operator = ( bCPOStream const & );
public:
    bCPOStream( bCPOStream const & );
    bCPOStream( void );
};

#endif
