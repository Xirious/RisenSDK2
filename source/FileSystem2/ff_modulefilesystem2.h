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
    public virtual IFFUnknown
{
public:
    /* [0000].0000 */ virtual IFFFileSystemNode2 * GetRootNode( void ) const = 0;
    /* [0000].0004 */ virtual FFBool               CreateVolume( bCString const & ) = 0;
    /* [0000].0008 */ virtual FFBool               RemoveVolume( bCString const & ) = 0;
    /* [0000].000C */ virtual FFLPVoid             GetFirstVolumePosition( void ) const = 0;
    /* [0000].0010 */ virtual FFBool               GetNextVolumeInfo( FFLPVoid &, SFFVolumeInfo & ) const = 0;
    /* [0000].0014 */ virtual FFBool               GetVolumeInfo( bCString const &, SFFVolumeInfo & ) const = 0;
    /* [0000].0018 */ virtual void                 __FIXME_0018( void ) = 0;
    /* [0000].001C */ virtual void                 __FIXME_001C( void ) = 0;
    /* [0000].0020 */ virtual FFBool               CreateDirectoryA( bCString const & ) = 0;
    /* [0000].0024 */ virtual FFBool               RemoveDirectoryA( bCString const & ) = 0;
    /* [0000].0028 */ virtual FFU32                GetFileAttributesA( bCString const & ) const = 0;
    /* [0000].002C */ virtual IFFFileStream2 *     CreateFileA( bCString const &, EFFFileCreate, EFFFileAccess, FFU32, FFU32, SFFAsynFileReadDesc * ) = 0;
    /* [0000].0030 */ virtual void                 __FIXME_0030( void ) = 0;
    /* [0000].0034 */ virtual void                 __FIXME_0034( void ) = 0;
    /* [0000].0038 */ virtual void                 __FIXME_0038( void ) = 0;
    /* [0000].003C */ virtual FFBool               CopyFileA( bCString const &, bCString const &, FFBool ) = 0;
    /* [0000].0040 */ virtual FFBool               MoveFileA( bCString const &, bCString const &, FFBool ) = 0;
    /* [0000].0044 */ virtual FFBool               DeleteFileA( bCString const & ) = 0;
    /* [0000].0048 */ virtual CFFFindFile *        FindFirstFileA( bCString const &, SFFFileFind & ) const = 0;
    /* [0000].004C */ virtual FFBool               FindNextFileA( CFFFindFile *, SFFFileFind & ) const = 0;
    /* [0000].0050 */ virtual FFBool               FindClose( CFFFindFile * ) const = 0;
    /* [0000].0054 */ virtual IFFPackedVolume2 *   CreatePackFile( void ) = 0;
    /* [0000].0058 */ virtual FFBool               MountDirectory( bCString const &, bCString const &, FFU32 ) = 0;
    /* [0000].005C */ virtual FFBool               MountPackFile( bCString const &, bCString const &, FFU32 ) = 0;
    /* [0000].0060 */ virtual FFBool               UnmountDirectory( bCString const & ) = 0;
    /* [0000].0064 */ virtual FFBool               UnmountPackFiles( bCString const & ) = 0;
    /* [0000].0068 */ virtual FFLPVoid             GetFirstMountPosition( void ) const = 0;
    /* [0000].006C */ virtual FFBool               GetNextMountInfo( FFLPVoid &, SFFMountInfo & ) const = 0;
    /* [0000].0070 */ virtual FFBool               GetMountInfo( bCString const &, SFFMountInfo & ) const = 0;
    /* [0000].0074 */ virtual FFBool               IsCacheEnabled( void ) const = 0;
    /* [0000].0078 */ virtual void                 EnableCache( FFBool ) = 0;
    /* [0000].007C */ virtual FFBool               LookupCachedVirtualPath( bCString const &, bCString & ) const = 0;
    /* [0000].0080 */ virtual FFBool               LookupCachedPhysicalPath( bCString const &, bCString & ) const = 0;
    /* [0000].0084 */ virtual FFLPVoid             GetFileMapStartPosition( void ) const = 0;
    /* [0000].0088 */ virtual IFFFileSystemNode2 * GetNextFileMapNode( FFLPVoid & ) const = 0;
    /* [0000].008C */ virtual FFBool               SyncCache( bCString const & ) = 0;
    /* [0000].0090 */ virtual FFBool               RegisterDirectoryListener( IFFFileChangeListener2 * ) = 0;
    /* [0000].0094 */ virtual FFBool               UnregisterDirectoryListener( IFFFileChangeListener2 * ) = 0;
    /* [0000].0098 */ virtual FFBool               RegisterVersionControlProvider( IFFVersionControlProvider2 * ) = 0;
    /* [0000].009C */ virtual FFBool               UnregisterVersionControlProvider( IFFVersionControlProvider2 * ) = 0;
    /* [0000].00A0 */ virtual FFBool               RequestVersionControlAction( SFFVersionControlAction const & ) = 0;
    /* [0000].00A4 */ virtual FFBool               PathExists( bCString const & ) const = 0;
    /* [0000].00A8 */ virtual FFBool               PathCanonicalize( bCString const &, bCString & ) const = 0;
    /* [0000].00AC */ virtual void                 PathMakeVirtual( bCString & ) const = 0;
    /* [0000].00B0 */ virtual void                 PathMakePhysical( bCString & ) const = 0;
    /* [0000].00B4 */ virtual void                 PathMakeVirtualFile( bCString & ) const = 0;
    /* [0000].00B8 */ virtual void                 PathMakePhysicalFile( bCString & ) const = 0;
    /* [0000].00BC */ virtual void                 PathMakeVirtualDirectory( bCString & ) const = 0;
    /* [0000].00C0 */ virtual void                 PathMakePhysicalDirectory( bCString & ) const = 0;
    /* [0000].00C4 */ virtual void                 SplitVirtualPath( bCString const &, bCString *, bCString *, bCString *, bCString * ) const = 0;
    /* [0000].00C8 */ virtual void                 MakeVirtualPath( bCString &, bCString const *, bCString const *, bCString const *, bCString const * ) const = 0;
    /* [0000].00CC */ virtual FFBool               PhysicalToVirtualPath( bCString const &, bCString & ) const = 0;
    /* [0000].00D0 */ virtual FFBool               VirtualToPhysicalPath( bCString const &, bCString & ) const = 0;
    /* [0000].00D4 */ virtual void                 __FIXME_00D4( void ) = 0;
    /* [0000].00D8 */ virtual void                 Lock( void ) const = 0;
    /* [0000].00DC */ virtual void                 Unlock( void ) const = 0;
    /* [0000].00E0 */ virtual void                 __FIXME_00E0( void ) = 0;
};

FF_DLLIMPORT IFFModuleFileSystem2 * FF_STDCALL FFFileSystem2_QueryModule( void );

#endif
