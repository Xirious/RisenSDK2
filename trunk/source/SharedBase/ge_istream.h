#ifndef GE_ISTREAM_H_INCLUDED
#define GE_ISTREAM_H_INCLUDED

class GE_DLLIMPORT bCIStream
{
public: virtual GEU32 Read( GELPVoid, GEU32 );
public: virtual GEU32 Read( bCString & );
public: virtual      ~bCIStream( void );
private:
    GEU16 m_u16StreamVersion;
          GE_PADDING( 2 )
protected:
    void SetStreamVersion( GEU16 );
public:
    GEU16 GetStreamVersion( void ) const;
    GEU32 Read( GEI8 & );
    GEU32 Read( GEU8 & );
    GEU32 Read( GEI16 & );
    GEU32 Read( GEU16 & );
    GEU32 Read( GEI32 & );
    GEU32 Read( GEU32 & );
    GEU32 Read( GEInt & );
    GEU32 Read( GEUInt & );
    GEU32 Read( GEI64 & );
    GEU32 Read( GEU64 & );
    GEU32 Read( GEBool & );
    GEU32 Read( GEFloat & );
    GEU32 Read( GEDouble & );
    GEU32 Read( GEChar & );
    GEU32 Read( bCUnicodeString & );
    GEU32 Read( bCGuid & );
    GEU32 Read( bCDateTime & );
    GEU32 Read( bCVariant & );
    GEU32 ReadLine( bCString & );
    GEU32 ReadLine( bCUnicodeString & );
public:
    bCIStream & operator >> ( GEI8 & );
    bCIStream & operator >> ( GEU8 & );
    bCIStream & operator >> ( GEI16 & );
    bCIStream & operator >> ( GEU16 & );
    bCIStream & operator >> ( GEI32 & );
    bCIStream & operator >> ( GEU32 & );
    bCIStream & operator >> ( GEInt & );
    bCIStream & operator >> ( GEUInt & );
    bCIStream & operator >> ( GEI64 & );
    bCIStream & operator >> ( GEU64 & );
    bCIStream & operator >> ( GEBool & );
    bCIStream & operator >> ( GEFloat & );
    bCIStream & operator >> ( GEDouble & );
    bCIStream & operator >> ( GEChar & );
    bCIStream & operator >> ( bCString & );
    bCIStream & operator >> ( bCUnicodeString & );
    bCIStream & operator >> ( bCGuid & );
    bCIStream & operator >> ( bCDateTime & );
    bCIStream & operator >> ( bCVariant & );
    bCIStream & operator =  ( bCIStream const & );
public:
    bCIStream( bCIStream const & );
    bCIStream( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEI8 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEU8 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEI16 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEU16 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEI32 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEU32 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEInt &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEUInt &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEI64 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEU64 &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEBool &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEFloat &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEDouble &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( GEChar &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( bCString &,bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( bCUnicodeString &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( bCGuid &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( bCDateTime &, bCIStream & );
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator << ( bCVariant &, bCIStream & );
};
GE_ASSERT_SIZEOF( bCIStream, 0x0008 )

#endif
