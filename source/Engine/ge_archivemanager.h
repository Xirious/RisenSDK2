#ifndef GE_ARCHIVEMANAGER_H_INLCUDED
#define GE_ARCHIVEMANAGER_H_INCLUDED

class GE_DLLIMPORT eCArchiveManager
{
public:
    static eCArchiveManager & GE_STDCALL GetInstance( void );
public:
    eCArchiveFile CreateFileA( bCString const & );
    GEBool        CreateFileA( bCString const &, eCArchiveFile & );
    GEBool        FindFiles( bCString const &, bTObjArray< eCArchiveFile > &, GEBool );
    GEBool        FindFilesWithExt( bCString const &, bCString const &, bTObjArray< eCArchiveFile > &, GEBool );
    eCArchiveFile GetFile( bCString const & );
    GEBool        GetFile( bCString const &, eCArchiveFile & );
    bCString      PathGetFileName( bCString const & );
    bCString      PathGetFileTitle( bCString const & );
    GEBool        SplitPath( bCString const &, bCString *, bCString *, bCString * );
public:
    eCArchiveManager & operator = ( eCArchiveManager const & );
protected:
    eCArchiveManager( void );
   ~eCArchiveManager( void );
};

#endif
