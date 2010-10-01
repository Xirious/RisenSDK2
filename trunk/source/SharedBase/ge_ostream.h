#ifndef GE_OSTREAM_H_INCLUDED
#define GE_OSTREAM_H_INCLUDED

class GE_DLLIMPORT bCOStream
{
public: virtual GEU32 Write( bCString const & );
public: virtual GEU32 Write( GELPCVoid, GEU32 );
public: virtual      ~bCOStream( void );
public:
    GEU32 Write( GEI8 );
    GEU32 Write( GEU8 );
    GEU32 Write( GEI16 );
    GEU32 Write( GEU16 );
    GEU32 Write( GEI32 );
    GEU32 Write( GEU32 );
    GEU32 Write( GEInt );
    GEU32 Write( GEUInt );
    GEU32 Write( GEI64 );
    GEU32 Write( GEU64 );
    GEU32 Write( GEBool );
    GEU32 Write( GEFloat );
    GEU32 Write( GEDouble );
    GEU32 Write( GEChar );
    GEU32 Write( bCUnicodeString const & );
    GEU32 Write( bCGuid const & );
    GEU32 Write( bCDateTime const & );
    GEU32 Write( bCVariant const & );
    GEU32 WriteLine( bCString const & );
public:
    bCOStream & operator << ( GEI8 );
    bCOStream & operator << ( GEU8 );
    bCOStream & operator << ( GEI16 );
    bCOStream & operator << ( GEU16 );
    bCOStream & operator << ( GEI32 );
    bCOStream & operator << ( GEU32 );
    bCOStream & operator << ( GEInt );
    bCOStream & operator << ( GEUInt );
    bCOStream & operator << ( GEI64 );
    bCOStream & operator << ( GEU64 );
    bCOStream & operator << ( GEBool );
    bCOStream & operator << ( GEFloat );
    bCOStream & operator << ( GEDouble );
    bCOStream & operator << ( GEChar );
    bCOStream & operator << ( bCString const & );
    bCOStream & operator << ( bCUnicodeString const & );
    bCOStream & operator << ( bCGuid const & );
    bCOStream & operator << ( bCDateTime const & );
    bCOStream & operator << ( bCVariant const & );
    bCOStream & operator =  ( bCOStream const & );
public:
    bCOStream( bCOStream const & );
    bCOStream( void );
public:
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEI8, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEU8, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEI16, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEU16, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEI32, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEU32, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEInt, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEUInt, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEI64, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEU64, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEBool, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEFloat, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEDouble, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( GEChar, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( bCString const &, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( bCUnicodeString const &, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( bCGuid const &, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( bCDateTime const &, bCOStream & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator >> ( bCVariant const &, bCOStream & );
};

#endif
