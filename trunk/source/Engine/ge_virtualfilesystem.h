#ifndef GE_VIRTUALFILESYSTEM_H_INCLUDED
#define GE_VIRTUALFILESYSTEM_H_INCLUDED

struct eSMount
{
    bCString m_strAbsVirtualPath;
    bCString m_strAbsPhysicalPath;
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<>' needs to have dll-interface to be used by clients of class 'eCVirtualFileSystem'

class GE_DLLIMPORT eCVirtualFileSystem
{
protected:
    enum EMount
    {
        EMount_Bin,
        EMount_Physical,
        EMount_Packed,
        EMount_ForceDWORD = GE_FORCE_DWORD
    };
private:
    /* 0000 */ bCString              m_strBinPath;
    /* 0004 */ bCString              m_strPhysicalRootPath;
    /* 0008 */ bCString              m_strVirtualRootPath;
    /* 000C */ GEBool                m_bIsCompiledProjectFolder;
    /* 000D */ GEBool                m_bNoWatch;
    /* 000E */ GEBool                m_bNoPacked;
    /* 000F */ GEBool                m_bNoPhysical;
    /* 0010 */ bTObjArray< eSMount > m_arrMounts;
    // 001C // sizeof(eCVirtualFileSystem)
protected:
    GEBool DisplayCacheConflicts( void );
//  void   Mount( eCConfigFile_SectionObject const *, EMount );
    GEBool MountDirectory( bCString const &, bCString const & );
//  GEBool ProcessMountList( eCConfigFile & );
    GEBool ProcessMountList( bCString const & );
    GEBool Unmount( bCString const & );
public:
    static eCVirtualFileSystem & GE_STDCALL GetInstance( void );
public:
    GEBool                        CopyFileA( bCString const &, bCString const & );
    GEBool                        DeleteDir( bCString const & );
    GEBool                        DeleteFileA( bCString const & );
    GEBool                        ExistsFile( bCString const & );
    GEBool                        FindDirectories( bCString const &, bTObjArray< bCString > & );
    GEBool                        FindFiles( bCString const &, bCString const &, bTObjArray< bCString > & );
    GEBool                        FindFiles( bCString const &, bTObjArray< bCString > & );
    GEBool                        FindFilesWithExt( bCString const &, bCString const &, bTObjArray< bCString > & );
    bCString                      GetBinPath( void );
    bTObjArray< eSMount > const & GetMounts( void ) const;
    bCString                      GetPhysicalRootPath( void );
    bCString                      GetVirtualRootPath( void );
    GEBool                        Initialize( bCCommandLine const & );
    GEBool                        IsAbsPhysical( bCString const & );
    GEBool                        IsAbsVirtual( bCString const & );
    GEBool                        IsCompiledProjectFolder( void );
    GEBool                        MakeAbsPhysicalPath( bCString & );
    GEBool                        MakeAbsVirtualPath( bCString & );
    GEBool                        MakeDir( bCString const & );
    GEBool                        MoveDir( bCString const &, bCString const & );
    GEBool                        MoveFileA( bCString const &, bCString const & );
//  GEBool                        RegisterFileChangeListener( IFFFileChangeListener2 * );
    void                          Shutdown( void );
    GEBool                        SplitPath( bCString const &, bCString &, bCString &, bCString &, bCString & );
    GEBool                        SplitPath( bCString const &, bCString *, bCString *, bCString *, bCString * );
//  GEBool                        UnregisterFileChangeListener( IFFFileChangeListener2 * );
public:
    eCVirtualFileSystem & operator = ( eCVirtualFileSystem const & );
protected:
    eCVirtualFileSystem( void );
   ~eCVirtualFileSystem( void );
public:
    eCVirtualFileSystem( eCVirtualFileSystem const & );
};

#pragma warning( pop )

#endif
