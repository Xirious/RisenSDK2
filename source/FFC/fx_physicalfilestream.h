#ifndef FX_PHYSICALFILESTREAM_H_INCLUDED
#define FX_PHYSICALFILESTREAM_H_INCLUDED

class FF_DLLIMPORT CFXPhysicalFileStream :
    public CFXIOStream
{
public: virtual FFU32  Read( FFLPVoid, FFU32 ) const;      // [0000].0000
public: virtual FFU32  Write( FFLPCVoid, FFU32 );          // [0000].0004
public: virtual FFBool GetPosition( FFI64 & ) const;       // [0000].0008
public: virtual FFBool SetPosition( FFI64, EFFFileSeek );  // [0000].000C
public: virtual       ~CFXPhysicalFileStream( void );      // [0000].0010
protected:
    FFLPVoid m_hHandle;  // 0004
public:
    using CFXIOStream::Read;
    using CFXIOStream::Write;
public:
    void     Close( void );
    FFBool   Create( bCString const &, EFFFileCreate, EFFFileAccess, FFU32, FFU32 );
    FFLPVoid CreateMapping( EFFFileMapProtection, FFU64 );
    FFBool   GetFileInformation( SFFFileData & ) const;
    FFLPVoid GetHandle( void ) const;
    FFBool   IsOpen( void ) const;
public:
    CFXPhysicalFileStream & operator = ( CFXPhysicalFileStream const & );
public:
    CFXPhysicalFileStream( CFXPhysicalFileStream const & );
    CFXPhysicalFileStream( FFLPVoid = 0 );
};
GE_ASSERT_SIZEOF( CFXPhysicalFileStream, 0x0008 )

#endif
