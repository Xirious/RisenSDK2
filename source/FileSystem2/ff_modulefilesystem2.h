#ifndef FF_MODULEFILESYSTEM2_H_INLCUDED
#define FF_MODULEFILESYSTEM2_H_INLCUDED

//
//FIXME: IFFModuleFileSystem2 references.
//

#define CFFFindFile void
#define IFFFileChangeListener2 void /* {842E0AAF-C883-4B09-BF9F-581C134B047E} */
#define IFFFileStream2 void         /* {8C70F102-809D-42E0-A51D-3AB707ABC765} */
#define IFFFileSystemNode2 void     /* {60B8F34C-1847-414B-8072-E88834B3AD08} */
#define IFFPackedVolume2 void       /* {86C27761-08EB-4A9F-A080-BB362F3B1176} */
#define IFFVersionControlProvider2 void

struct SFFAsynFileReadDesc
{
    //FIXME: SFFAsynFileReadDesc members.
};

struct SFFMountInfo
{
    bCString m_strAbsVirtualPath;
    bCString m_strAbsPhysicalPath;
};

struct SFFVersionControlAction
{
    //FIXME: SFFVersionControlAction members.
};

struct SFFVolumeInfo
{
    bCString m_strRoot;
};

FF_DECLARE_INTERFACE( IFFModuleFileSystem2, "842E0AAF-C883-4B09-BF9F-581C134B047E" ) :
    virtual public IFFUnknown
{
public:
    virtual IFFFileSystemNode2 * GetRootNode( void ) const = 0;
    virtual FFBool               CreateVolume( bCString const & ) = 0;
    virtual FFBool               RemoveVolume( bCString const & ) = 0;
    virtual FFLPVoid             GetFirstVolumePosition( void ) const = 0;
    virtual FFBool               GetNextVolumeInfo( FFLPVoid &, SFFVolumeInfo & ) const = 0;
    virtual FFBool               GetVolumeInfo( bCString const &, SFFVolumeInfo & ) const = 0;
    virtual void                 __FIXME_0018( void ) = 0;
    virtual void                 __FIXME_001C( void ) = 0;
    virtual FFBool               CreateDirectoryA( bCString const & ) = 0;
    virtual FFBool               RemoveDirectoryA( bCString const & ) = 0;
    virtual FFU32                GetFileAttributesA( bCString const & ) const = 0;
    virtual IFFFileStream2 *     CreateFileA( bCString const &, EFFFileCreate, EFFFileAccess, FFU32, FFU32, SFFAsynFileReadDesc * ) = 0;
    virtual void                 __FIXME_0030( void ) = 0;
    virtual void                 __FIXME_0034( void ) = 0;
    virtual void                 __FIXME_0038( void ) = 0;
    virtual FFBool               CopyFileA( bCString const &, bCString const &, FFBool ) = 0;
    virtual FFBool               MoveFileA( bCString const &, bCString const &, FFBool ) = 0;
    virtual FFBool               DeleteFileA( bCString const & ) = 0;
    virtual CFFFindFile *        FindFirstFileA( bCString const &, SFFFileFind & ) const = 0;
    virtual FFBool               FindNextFileA( CFFFindFile *, SFFFileFind & ) const = 0;
    virtual FFBool               FindClose( CFFFindFile * ) const = 0;
    virtual IFFPackedVolume2 *   CreatePackFile( void ) = 0;
    virtual FFBool               MountDirectory( bCString const &, bCString const &, FFU32 ) = 0;
    virtual FFBool               MountPackFile( bCString const &, bCString const &, FFU32 ) = 0;
    virtual FFBool               UnmountDirectory( bCString const & ) = 0;
    virtual FFBool               UnmountPackFiles( bCString const & ) = 0;
    virtual FFLPVoid             GetFirstMountPosition( void ) const = 0;
    virtual FFBool               GetNextMountInfo( FFLPVoid &, SFFMountInfo & ) const = 0;
    virtual FFBool               GetMountInfo( bCString const &, SFFMountInfo & ) const = 0;
    virtual FFBool               IsCacheEnabled( void ) const = 0;
    virtual void                 EnableCache( FFBool ) = 0;
    virtual FFBool               LookupCachedVirtualPath( bCString const &, bCString & ) const = 0;
    virtual FFBool               LookupCachedPhysicalPath( bCString const &, bCString & ) const = 0;
    virtual FFLPVoid             GetFileMapStartPosition( void ) const = 0;
    virtual IFFFileSystemNode2 * GetNextFileMapNode( FFLPVoid & ) const = 0;
    virtual FFBool               SyncCache( bCString const & ) = 0;
    virtual FFBool               RegisterDirectoryListener( IFFFileChangeListener2 * ) = 0;
    virtual FFBool               UnregisterDirectoryListener( IFFFileChangeListener2 * ) = 0;
    virtual FFBool               RegisterVersionControlProvider( IFFVersionControlProvider2 * ) = 0;
    virtual FFBool               UnregisterVersionControlProvider( IFFVersionControlProvider2 * ) = 0;
    virtual FFBool               RequestVersionControlAction( SFFVersionControlAction const & ) = 0;
    virtual FFBool               PathExists( bCString const & ) const = 0;
    virtual FFBool               PathCanonicalize( bCString const &, bCString & ) const = 0;
    virtual void                 PathMakeVirtual( bCString & ) const = 0;
    virtual void                 PathMakePhysical( bCString & ) const = 0;
    virtual void                 PathMakeVirtualFile( bCString & ) const = 0;
    virtual void                 PathMakePhysicalFile( bCString & ) const = 0;
    virtual void                 PathMakeVirtualDirectory( bCString & ) const = 0;
    virtual void                 PathMakePhysicalDirectory( bCString & ) const = 0;
    virtual void                 SplitVirtualPath( bCString const &, bCString *, bCString *, bCString *, bCString * ) const = 0;
    virtual void                 MakeVirtualPath( bCString &, bCString const *, bCString const *, bCString const *, bCString const * ) const = 0;
    virtual FFBool               PhysicalToVirtualPath( bCString const &, bCString & ) const = 0;
    virtual FFBool               VirtualToPhysicalPath( bCString const &, bCString & ) const = 0;
    virtual void                 __FIXME_00D4( void ) = 0;
    virtual void                 Lock( void ) const = 0;
    virtual void                 Unlock( void ) const = 0;
    virtual void                 __FIXME_00E0( void ) = 0;
};

FF_DLLIMPORT IFFModuleFileSystem2 * FF_STDCALL FFFileSystem2_QueryModule( void );

#endif
