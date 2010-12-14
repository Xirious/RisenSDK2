#ifndef FX_PHYSICALFILE_H_INCLUDED
#define FX_PHYSICALFILE_H_INCLUDED

class FF_DLLIMPORT CFXPhysicalFile :
    public CFXIOStream
{
public: virtual FFU32  Read( FFLPVoid, FFU32 ) const;      // [0000].0000
public: virtual FFU32  Write( FFLPCVoid, FFU32 );          // [0000].0004
public: virtual FFBool GetPosition( FFI64 & ) const;       // [0000].0008
public: virtual FFBool SetPosition( FFI64, EFFFileSeek );  // [0000].000C
public: virtual       ~CFXPhysicalFile( void );            // [0000].0010
protected:
    bCString              m_strPhysicalFilePath;  // 0004
    CFXPhysicalFileStream m_PhysicalFileStream;   // 0008
public:
    using CFXIOStream::Read;
    using CFXIOStream::Write;
public:
    void     Close( void );
    FFBool   Create( bCString const & );
    void     Destroy( void );
    FFBool   Exists( void ) const;
    FFU32    GetAttributes( void ) const;
    FFBool   GetCreationTime( SFFFileTime & ) const;
    bCString GetFileExtension( void ) const;
    bCString GetFileName( void ) const;
    FFU64    GetFileSize( void ) const;
    FFBool   GetFileTimes( SFFFileTime *, SFFFileTime *, SFFFileTime * ) const;
    bCString GetFileTitle2( void ) const;
    bCString GetFileTitleA( void ) const;
    FFBool   GetLastAccessTime( SFFFileTime & ) const;
    FFBool   GetModificationTime( SFFFileTime & ) const;
    bCString GetPhysicalFilePath( void ) const;
    bCString GetPhysicalRootPath( void ) const;
    FFBool   IsArchived( void ) const;
    FFBool   IsCached( void ) const;
    FFBool   IsCompressed( void ) const;
    FFBool   IsDeleted( void ) const;
    FFBool   IsDirectory( void ) const;
    FFBool   IsEncrypted( void ) const;
    FFBool   IsHidden( void ) const;
    FFBool   IsOpen( void ) const;
    FFBool   IsPacked( void ) const;
    FFBool   IsPhysical( void ) const;
    FFBool   IsReadOnly( void ) const;
    FFBool   IsSystem( void ) const;
    FFBool   IsTemporary( void ) const;
    FFBool   IsVirtual( void ) const;
    FFBool   MatchesMask( FFU32 ) const;
    FFBool   Open( EFFFileCreate, EFFFileAccess, FFU32, FFU32 );
public:
    CFXPhysicalFile & operator = ( CFXPhysicalFile const & );
public:
    CFXPhysicalFile( bCString const & );
    CFXPhysicalFile( CFXPhysicalFile const & );
    CFXPhysicalFile( void );
};
GE_ASSERT_SIZEOF( CFXPhysicalFile,  0x0010 )

#endif
