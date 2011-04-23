#ifndef GE_IOSTREAM_H_INCLUDED
#define GE_IOSTREAM_H_INCLUDED

enum bEStreamSeekMode
{
    bEStreamSeekMode_Begin,
    bEStreamSeekMode_Current,
    bEStreamSeekMode_End,
    bEStreamSeekMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCIOStream :
    public bCIStream,
    public bCOStream
{
public: using bCIStream::Read;
public: virtual         ~bCIOStream( void );
public: virtual GEI64    GetPosition( void ) const = 0;
public: virtual GEBool   Seek( GEI64, bEStreamSeekMode ) = 0;
public: using bCOStream::Write;
public:
    bCIOStream & operator = ( bCIOStream const & );
public:
    bCIOStream( bCIOStream const & );
    bCIOStream( void );
};
GE_ASSERT_SIZEOF( bCIOStream, 0x000C )

#endif
