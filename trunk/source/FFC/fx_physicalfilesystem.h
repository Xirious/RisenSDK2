#ifndef FX_PHYSICALFILESYSTEM_H_INCLUDED
#define FX_PHYSICALFILESYSTEM_H_INCLUDED

class FF_DLLIMPORT CFXPhysicalFileSystem
{
protected: virtual ~CFXPhysicalFileSystem( void );  
public:
    static CFXPhysicalFileSystem & FF_STDCALL GetInstance( void );
public:
    FFBool   CopyFileA( bCString const &, bCString const &, FFBool );
    FFBool   CreateDirectoryA( bCString const & );
    FFLPVoid CreateFileA( bCString const &, EFFFileCreate, EFFFileAccess, FFU32, FFU32 );
    FFBool   DeleteDir( bCString const & );
    FFBool   DeleteFileA( bCString const & );
    FFBool   FindClose( FFLPVoid ) const;
    FFLPVoid FindFirstFileA( bCString const &, SFFFileFind & ) const;
    FFBool   FindNextFileA( FFLPVoid, SFFFileFind & ) const;
    bCString GetCurrentDirectoryA( void ) const;
    bCString GetCurrentVolume( void ) const;
    FFU32    GetFileAttributesA( bCString const & ) const;
    FFU64    GetFileSize( bCString const & ) const;
    FFBool   GetFileTimes( bCString const &, SFFFileTime *, SFFFileTime *, SFFFileTime * ) const;
    FFLPVoid GetFirstVolumePosition( void ) const;
    FFBool   GetNextVolumeInfo( FFLPVoid &, SFFVolumeInfo & ) const;
    FFBool   GetVolumeInfo( bCString const &, SFFVolumeInfo & ) const;
    FFBool   MakeDir( bCString const & );
    FFBool   MakePhysicalPath( bCString &, bCString const *, bCString const *, bCString const *, bCString const *) const;
    FFBool   MoveFileA( bCString const &, bCString const &, FFBool );
    FFBool   PathCanonicalize( bCString & ) const;
    FFBool   PathCanonicalize( bCString const &, bCString & ) const;
    FFBool   PathExists( bCString const & ) const;
    FFBool   PathGetFileExtension( bCString const &, bCString & ) const;
    FFBool   PathGetFileName( bCString const &, bCString & ) const;
    FFBool   PathGetFileTitle( bCString const &, bCString & ) const;
    FFBool   PathGetRootDirectory( bCString const &, bCString & ) const;
    FFBool   PathMakePhysicalDirectory( bCString & ) const;
    FFBool   PathMakePhysicalFile( bCString & ) const;
    FFBool   RemoveDirectoryA( bCString const & );
    FFBool   SetCurrentDirectoryA( bCString const & );
    FFBool   SetCurrentVolume( bCString const & );
    FFBool   SplitPhysicalPath( bCString const &, bCString *, bCString *, bCString *, bCString * ) const;
public:
    CFXPhysicalFileSystem & operator = ( CFXPhysicalFileSystem const & );
protected:
    CFXPhysicalFileSystem( void );
public:
    CFXPhysicalFileSystem( CFXPhysicalFileSystem const & );
};
GE_ASSERT_SIZEOF( CFXPhysicalFileSystem, 0x0004 )

#endif
