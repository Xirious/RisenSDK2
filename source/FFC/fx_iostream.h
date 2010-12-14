#ifndef FX_IOSTREAM_H_INCLUDED
#define FX_IOSTREAM_H_INCLUDED

class FF_DLLIMPORT CFXIOStream
{
public: virtual FFU32  Read( FFLPVoid,  FFU32 ) const    = 0;  // [0000].0000
public: virtual FFU32  Write( FFLPCVoid, FFU32 )         = 0;  // [0000].0004
public: virtual FFBool GetPosition( FFI64 & ) const      = 0;  // [0000].0008
public: virtual FFBool SetPosition( FFI64, EFFFileSeek ) = 0;  // [0000].000C
public:
    FFU32 Read( FFI8 & ) const;
	FFU32 Read( FFU8 & ) const;
	FFU32 Read( FFI16 & ) const;
	FFU32 Read( FFU16 & ) const;
	FFU32 Read( FFI32 & ) const;
	FFU32 Read( FFU32 & ) const;
	FFU32 Read( FFI64 & ) const;
    FFU32 Read( FFU64 & ) const;
	FFU32 Read( FFBool & ) const;
	FFU32 Read( FFInt & ) const;
    FFU32 Read( FFChar & ) const;
	FFU32 Read( FFUnicodeChar & ) const;
	FFU32 Read( bCString & ) const;
	FFU32 Read( bCUnicodeString & ) const;
    FFU32 ReadLine( bCString & ) const;
	FFU32 ReadLine( bCUnicodeString & ) const;
	FFU32 Write( FFI8 );
	FFU32 Write( FFU8 );
	FFU32 Write( FFI16 );
	FFU32 Write( FFU16 );
	FFU32 Write( FFI32 );
	FFU32 Write( FFU32 );
	FFU32 Write( FFI64 );
	FFU32 Write( FFU64 );
	FFU32 Write( FFBool );
	FFU32 Write( FFInt );
	FFU32 Write( FFChar );
    FFU32 Write( FFUnicodeChar );
    FFU32 Write( bCString const & );
	FFU32 Write( bCUnicodeString const & );
    FFU32 WriteLine( bCString const & );
	FFU32 WriteLine( bCUnicodeString const & );
public:
    CFXIOStream & operator = ( CFXIOStream const & );
public:
    CFXIOStream( CFXIOStream const & );
    CFXIOStream( void );
};
GE_ASSERT_SIZEOF( CFXIOStream, 0x0004 )

#endif
