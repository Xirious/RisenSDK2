#ifndef FX_VIRTUALFILE_H_INCLUDED
#define FX_VIRTUALFILE_H_INCLUDED

class FF_DLLIMPORT CFXVirtualFile :
    public CFXIOStream
{
public: virtual FFU32  Read( FFLPVoid, FFU32 ) const;
public: virtual FFU32  Write( FFLPCVoid, FFU32 );
public: virtual FFBool GetPosition( FFI64 & ) const;
public: virtual FFBool SetPosition( FFI64, EFFFileSeek );
public: virtual       ~CFXVirtualFile( void );
protected:
    bCString             m_strVirtualFilePath;
    CFXVirtualFileStream m_Stream;
public:
    void                         Close( void );
    FFBool                       Create( bCString const & );
    void                         Destroy( void );
    FFBool                       Exists( void ) const;
    FFU32                        GetAttributes( void ) const;
    FFBool                       GetCreationTime( SFFFileTime & ) const;
    bCString                     GetFileExtension( void ) const;
    bCString                     GetFileName( void ) const;
    FFU64                        GetFileSize( void ) const;
    FFBool                       GetFileTimes( SFFFileTime *, SFFFileTime *, SFFFileTime * ) const;
    bCString                     GetFileTitleA( void ) const;
    bCString                     GetFileTitle2( void ) const;
    FFBool                       GetLastAccessTime( SFFFileTime & ) const;
    FFBool                       GetModificationTime( SFFFileTime & ) const;
    bCString                     GetPhysicalFilePath( void ) const;
    bCString                     GetPhysicalRootPath( void ) const;
    CFXVirtualFileStream &       GetStream( void );
    CFXVirtualFileStream const & GetStream( void ) const;
    bCString                     GetVirtualFilePath( void ) const;
    bCString                     GetVirtualRootPath( void ) const;
    FFBool                       IsArchived( void ) const;
    FFBool                       IsCached( void ) const;
    FFBool                       IsCompressed( void ) const;
    FFBool                       IsDeleted( void ) const;
    FFBool                       IsDirectory( void ) const;
    FFBool                       IsEncrypted( void ) const;
    FFBool                       IsHidden( void ) const;
    FFBool                       IsOpen( void ) const;
    FFBool                       IsPacked( void ) const;
    FFBool                       IsPhysical( void ) const;
    FFBool                       IsReadOnly( void ) const;
    FFBool                       IsReady( void ) const;
    FFBool                       IsSystem( void ) const;
    FFBool                       IsTemporary( void ) const;
    FFBool                       IsVirtual( void ) const;
    FFBool                       MatchesMask( FFU32 ) const;
    FFBool                       Open( EFFFileCreate, EFFFileAccess, FFU32, FFU32, SFFAsynFileReadDesc * );
public:
    CFXVirtualFile & operator = ( CFXVirtualFile const & );
public:
             CFXVirtualFile( CFXVirtualFileStream const &, bCString const & );
    explicit CFXVirtualFile( bCString const & );
             CFXVirtualFile( CFXVirtualFile const & );
             CFXVirtualFile( void );
};
GE_ASSERT_SIZEOF( CFXVirtualFile, 0x0010 )

#endif
