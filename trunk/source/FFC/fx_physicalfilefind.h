#ifndef FX_PHYSICALFILEFIND_H_INCLUDED
#define FX_PHYSICALFILEFIND_H_INCLUDED

class FF_DLLIMPORT CFXPhysicalFileFind
{
public: virtual ~CFXPhysicalFileFind( void );  
protected:
    bCString      m_strRootPath;     // 0004
    FFLPVoid      m_hFileFind;       // 0008
    SFFFileFind * m_pFileFind[ 2 ];  // 0010
public:
    void     Close( void );
    FFBool   FindFile( bCString const &, bCString const & );
    FFBool   FindFile( bCString const & );
    FFBool   FindNext( void );
    FFU32    GetAttributes( void ) const;
    FFBool   GetCreationTime( SFFFileTime & ) const;
    FFBool   GetFileData( SFFFileData & ) const;
    bCString GetFileExtension( void ) const;
    bCString GetFileName( void ) const;
    FFBool   GetFileTimes( SFFFileTime *, SFFFileTime *, SFFFileTime * ) const;
    bCString GetFileTitleA( void ) const;
    FFBool   GetFindData( SFFFileFind & ) const;
    FFBool   GetLastAccessTime( SFFFileTime & ) const;
    FFBool   GetModificationTime( SFFFileTime & ) const;
    bCString GetPhysicalFilePath( void ) const;
    bCString GetPhysicalRootPath( void ) const;
    FFBool   IsArchived( void ) const;
    FFBool   IsCompressed( void ) const;
    FFBool   IsDeleted( void ) const;
    FFBool   IsDirectory( void ) const;
    FFBool   IsDots( void ) const;
    FFBool   IsEncrypted( void ) const;
    FFBool   IsHidden( void ) const;
    FFBool   IsReadOnly( void ) const;
    FFBool   IsSystem( void ) const;
    FFBool   IsTemporary( void ) const;
    FFBool   MatchesMask( FFU32 ) const;
public:
    CFXPhysicalFileFind & operator = ( CFXPhysicalFileFind const & );
public:
    CFXPhysicalFileFind( CFXPhysicalFileFind const & );
    CFXPhysicalFileFind( void );
};
GE_ASSERT_SIZEOF( CFXPhysicalFileFind, 0x0014 )

#endif
