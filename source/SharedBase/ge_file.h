#ifndef GE_FILE_H_INCLUDED
#define GE_FILE_H_INCLUDED

enum bEFileCreationMode
{
    bEFileCreationMode_OpenExisting,
    bEFileCreationMode_OpenAlways,
    bEFileCreationMode_CreateAlways,
    bEFileCreationMode_ForceDWORD = GE_FORCE_DWORD
};

enum bEStreamSeekMode
{
    bEStreamSeekMode_Begin,
    bEStreamSeekMode_Current,
    bEStreamSeekMode_End,
    bEStreamSeekMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT bCFile :
    public bCIOStream
{
public: using bCIStream::Read;
public: virtual         ~bCFile( void );
public: virtual GEI64    GetPosition( void ) const;
public: virtual GEBool   Seek( GEI64, bEStreamSeekMode ) = 0;
public: virtual GEBool   IsValid( void ) const;
public: virtual GEBool   IsOpen( void ) const;
public: virtual GEI64    GetLength( void ) const;
public: virtual GEBool   Open( bCString const &, bEFileCreationMode );
public: virtual GEBool   Close( void );
public: virtual GEBool   Seek( GEI64, bEStreamSeekMode ) const;
public: using bCOStream::Write;
public:
    GEBool Eof( void ) const;
    GEBool SeekToBegin( void ) const;
    GEBool SeekToEnd( void ) const;
public:
    bCFile & operator = ( bCFile const & );
public:
    bCFile( bCFile const & );
    bCFile( void );
};

#endif
