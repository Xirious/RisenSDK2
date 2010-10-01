#ifndef FF_SYSTEM_H_INCLUDED
#define FF_SYSTEM_H_INCLUDED

enum EFFFileAccess
{
    EFFFileAccess_Read       = 1,
    EFFFileAccess_Write      = 2,
    EFFFileAccess_ReadWrite  = 3,
    EFFFileAccess_ForceDWORD = FF_FORCE_DWORD
};

enum EFFFileCreate
{
    EFFFileCreate_CreateAlways     = 1,
    EFFFileCreate_CreateNew        = 2,
    EFFFileCreate_OpenAlways       = 3,
    EFFFileCreate_OpenExisting     = 4,
    EFFFileCreate_TruncateExisting = 5,
    EFFFileCreate_ForceDWORD       = FF_FORCE_DWORD
};

enum EFFFileMapProtection
{
    EFFFileMapProtection_ReadOnly   = 2,
    EFFFileMapProtection_ReadWrite  = 4,
    EFFFileMapProtection_ForceDWORD = FF_FORCE_DWORD
};

enum EFFFileSeek
{
    EFFFileSeek_Begin      = 0,
    EFFFileSeek_Current    = 1,
    EFFFileSeek_End        = 2,
    EFFFileSeek_ForceDWORD = FF_FORCE_DWORD
};

enum EFFSpecialFolder
{
    EFFSpecialFolder_User         = 0,
    EFFSpecialFolder_MyDocuments  = 1,
    EFFSpecialFolder_AppData      = 2,
    EFFSpecialFolder_LocalAppData = 3,
    EFFSpecialFolder_SavedGames   = 4,
    EFFSpecialFolder_System       = 5,
    EFFSpecialFolder_ForceDWORD   = FF_FORCE_DWORD
};

struct FFGUID
{
    GUID m_Guid;
    operator GUID & ( void )
    {
        return this->m_Guid;
    }
    operator GUID * ( void )
    {
        return &(this->m_Guid);
    }
    operator GUID const & ( void ) const
    {
        return this->m_Guid;
    }
    operator GUID const * ( void ) const
    {
        return &(this->m_Guid);
    }
    FFGUID( GUID const & a_Guid )
    {
        this->m_Guid = a_Guid;
    }
    FFGUID( void )
    {
    }
};

struct SFFFileTime
{
    FILETIME m_FileTime;
};

struct SFFFileData
{
    /* 0000 */ SFFFileTime m_CreationTime;
    /* 0008 */ SFFFileTime m_LastAccessTime;
    /* 0010 */ SFFFileTime m_LastWriteTime;
    /* 0018 */ FFU32       m_u32FileSizeHigh;
    /* 001C */ FFU32       m_u32FileSizeLow;
    /* 0020 */ FFU32       __u32Reserved0;
    /* 0024 */ FFU32       __u32Reserved1;
    /* 0028 */ FFU32       m_u32FileAttributes;
    /* 002C */ bCString    __strFileName;
    // 0030 // sizeof(SFFFileData)
};

struct SFFFileFind
{
    /* 0000 */ SFFFileTime m_CreationTime;
    /* 0008 */ SFFFileTime m_LastAccessTime;
    /* 0010 */ SFFFileTime m_LastWriteTime;
    /* 0018 */ FFU32       m_u32FileSizeHigh;
    /* 001C */ FFU32       m_u32FileSizeLow;
    /* 0020 */ FFU32       m_u32Reserved0;
    /* 0024 */ FFU32       m_u32Reserved1;
    /* 0028 */ FFU32       m_u32FileAttributes;
    /* 002C */ bCString    m_strFileName;
    // 0030 // sizeof(SFFFileFind)
};

typedef CRITICAL_SECTION SFFCriticalSection;
typedef OVERLAPPED       SFFOverlapped;

typedef FFU32 (FF_STDCALL * FFFThreadStartRoutine)( FFLPVoid a_pParameter );
typedef void (FF_STDCALL * FFFOverlappedCompletionRoutine)( FFU32 a_u32dwErrorCode, FFU32 a_u32dwNumberOfBytesTransfered, SFFOverlapped * a_pOverlapped );

FF_DLLIMPORT FFU64    FF_STDCALL g_FFCalcTimeDiffMilliseconds( SFFFileTime const & a_FileTime1, SFFFileTime const & a_FileTime2 );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCloseFile( FFLPVoid a_hFile );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCloseFileMapping( FFLPVoid a_hFileMappingObject );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCloseIoCompletionPort( FFLPVoid a_hCompletionPort );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCloseThread( FFLPVoid a_hThread );
FF_DLLIMPORT FFInt    FF_STDCALL g_FFCompareFileTime( SFFFileTime const & a_FileTime1, SFFFileTime const & a_FileTime2 );
FF_DLLIMPORT FFInt    FF_STDCALL g_FFCompareNamesMatchCase( bCString const & a_strName1, bCString const & a_strName2 );
FF_DLLIMPORT FFInt    FF_STDCALL g_FFCompareNamesNoCase( bCString const & a_strName1, bCString const & a_strName2 );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCopyFile( FFLPCChar a_pcExistingFileName, FFLPCChar a_pcNewFileName, FFBool a_bFailIfExists );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFCreatEvent( FFLPCChar a_pcName, FFBool a_bManualReset, FFBool a_bInitialState );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCreateDirectory( FFLPCChar a_pcPathName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFCreateDirectoryChain( FFLPCChar a_pcPathName );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFCreateFile( FFLPCChar a_pcFileName, EFFFileCreate a_enuCreationDisposition, EFFFileAccess a_enuDesiredAccess, FFU32 a_u32ShareMode, FFU32 a_u32FlagsAndAttributes, FFLPVoid a_hTemplateFile );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFCreateFileMapping( FFLPVoid a_hFile, EFFFileMapProtection a_enuProtect, FFU64 a_u64MaximumSize, FFLPCChar a_pcName );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFCreateIoCompletionPort( FFLPVoid a_hFileHandle, FFLPVoid a_hExistingCompletionPort, FFLPVoid a_pCompletionKey, FFU32 a_u32NumberOfConcurrentThreads );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFCreateThread( FFU32 u_32StackSize, FFFThreadStartRoutine a_funcStartAddress, FFLPVoid a_pParameter, FFBool a_bCreateSuspended, FFU32 * a_pu32ThreadId );
FF_DLLIMPORT void     FF_STDCALL g_FFDeleteCriticalSection( SFFCriticalSection * a_pCriticalSection );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFDeleteFile( FFLPCChar a_pcFileName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFDestroyEvent( FFLPVoid a_hEvent );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFEnterCriticalSection( SFFCriticalSection * a_pCriticalSection );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFFindClose( FFLPVoid a_hFindFile );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFFindFirstFile( FFLPCChar a_pcFileName, SFFFileFind & a_FindFileData );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFFindNextFile( FFLPVoid a_hFindFile, SFFFileFind & a_FindFileData );
FF_DLLIMPORT FFLPChar FF_STDCALL g_FFFullPath( FFLPChar a_pcBuffer, FFLPCChar a_pcFileName, FFU32 a_u32BufferLength );
FF_DLLIMPORT FFU32    FF_STDCALL g_FFGetCurrentDirectory( FFLPChar a_pcBuffer, FFU32 a_u32BufferLength );
FF_DLLIMPORT void     FF_STDCALL g_FFGetCurrentFileTime( SFFFileTime & a_FileTime );
FF_DLLIMPORT FFU32    FF_STDCALL g_FFGetFileAttributes( FFLPCChar a_pcFileName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetFileInformation( FFLPVoid a_hFile, SFFFileData & a_FileInformation );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetFilePointer( FFLPVoid a_hFile, FFI64 & a_i64FilePointer );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetFileSize( FFLPVoid a_hFile, FFI64 & a_i64FileSize );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetFileTime( FFLPVoid a_hFile, SFFFileTime * a_pCreationTime, SFFFileTime * a_pLastAccessTime, SFFFileTime * a_pLastWriteTime );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetQueuedCompletionStatus( FFLPVoid a_hCompletionPort, FFU32 * a_pu32NumberOfBytesTransferred, FFLPVoid * a_ppCompletionKey, SFFOverlapped * * a_ppOverlapped, FFU32 a_u32Milliseconds );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetSpecialDirectory( EFFSpecialFolder a_enuKnownFolder, FFLPChar a_pcBuffer, FFU32 a_u32BufferLength );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetSystemAllocationGranularity( FFU32 & a_u32AllocationGranularity );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetSystemPageSize( FFU32 & a_u32PageSize );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFGetThreadExitCode( FFLPVoid a_hThread, FFU32 * a_u32ExitCode );
FF_DLLIMPORT FFInt    FF_STDCALL g_FFGetThreadPriority( FFLPVoid a_hThread );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFInitializeCriticalSection( SFFCriticalSection * a_pCriticalSection );
FF_DLLIMPORT void     FF_STDCALL g_FFInvalidateFileHandle( FFLPVoid & a_hFile );
FF_DLLIMPORT void     FF_STDCALL g_FFInvalidateFindHandle( FFLPVoid & a_hFindFile );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsDirectory( FFLPCChar a_pcFileName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsEqualFileTime( SFFFileTime const & a_FileTime1, SFFFileTime const & a_FileTime2 );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsEqualName( bCString const & a_strName1, bCString const & a_strName2 );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsFile( FFLPCChar a_pcFileName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsValidFileHandle( FFLPVoid a_hFile );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFIsValidFindHandle( FFLPVoid a_hFindFile );
FF_DLLIMPORT void     FF_STDCALL g_FFLeaveCriticalSection( SFFCriticalSection * a_pCriticalSection );
FF_DLLIMPORT void     FF_STDCALL g_FFMakePath( FFLPChar a_pcPath, FFLPCChar a_pcDrive, FFLPCChar a_pcDir, FFLPCChar a_pcFName, FFLPCChar a_pcExt );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFMapViewOfFile( FFLPVoid a_hFileMappingObject, FFU32 a_u32DesiredAccess, FFU64 a_u64FileOffset, FFU32 a_u32NumberOfBytesToMap );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFMoveFile( FFLPCChar a_pcExistingFileName, FFLPCChar a_pcNewFileName, FFBool a_bDontReplaceExisting );
FF_DLLIMPORT void     FF_STDCALL g_FFMsgBoxLastError( void );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFOpenDirectory( FFLPCChar a_pcFileName, FFBool a_bOverlapped );
FF_DLLIMPORT void     FF_STDCALL g_FFPathAddUnixDirSeparator( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathAddWindowsDirSeparator( bCString & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathCanonicalize( FFLPChar a_pcBuf, FFLPCChar a_pcPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathIsAbsPhysical( bCString const & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathIsAbsVirtual( bCString const & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathIsDots( bCString const & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathIsRelative( bCString const & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeUnix( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeUnixDir( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeUnixFile( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeVolumeRoot( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeWindows( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeWindowsDir( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathMakeWindowsFile( bCString & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPathMatchSpec( FFLPCChar a_pcFile, FFLPCChar a_pcSpec );
FF_DLLIMPORT void     FF_STDCALL g_FFPathRemoveUnixDirSeparator( bCString & a_strPath );
FF_DLLIMPORT void     FF_STDCALL g_FFPathRemoveWindowsDirSeparator( bCString & a_strPath );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFPostQueuedCompletionStatus( FFLPVoid a_hCompletionPort, FFU32 a_u32NumberOfBytesTransferred, FFLPVoid a_pCompletionKey, SFFOverlapped * a_pOverlapped );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFReadDirectoryChanges( FFLPVoid a_hDirectory, FFLPVoid a_pBuffer, FFU32 a_u32BufferLength, FFBool a_bWatchSubtree, FFU32 a_u32NotifyFilter, FFU32 * a_u32BytesReturned, SFFOverlapped * a_pOverlapped, FFFOverlappedCompletionRoutine a_funcCompletionRoutine );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFReadFile( FFLPVoid a_hFile, FFLPVoid a_pBuffer, FFU32 a_u32NumberOfBytesToRead, FFU32 * a_pu32NumberOfBytesRead );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFRemoveDirectory( FFLPCChar a_pcPathName );
FF_DLLIMPORT FFU32    FF_STDCALL g_FFResumeThread( FFLPVoid a_hThread );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetCurrentDirectory( FFLPCChar a_pcPathName );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetEndOfFile( FFLPVoid a_hFile );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetEvent( FFLPVoid a_hEvent, FFBool a_bSignaled );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetFileAttributes( FFLPCChar a_pcFileName, FFU32 a_u32FileAttributes );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetFilePointer( FFLPVoid hFile, FFI64 a_i64DistanceToMove, FFI64 * a_i64NewFilePointer, EFFFileSeek a_enuMoveMethod);
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetFileTime( FFLPVoid a_hFile, SFFFileTime const * a_pCreationTime, SFFFileTime const * a_pLastAccessTime, SFFFileTime const * a_pLastWriteTime );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFSetThreadPriority( FFLPVoid a_hThread, FFInt a_iPriority );
FF_DLLIMPORT void     FF_STDCALL g_FFSplitPath( FFLPCChar a_pcPath, FFLPChar a_pcDrive, FFLPChar a_pcDir, FFLPChar a_pcFName, FFLPChar a_pcExt );
FF_DLLIMPORT FFU32    FF_STDCALL g_FFSuspendThread( FFLPVoid a_hThread );
FF_DLLIMPORT void     FF_STDCALL g_FFTrace( FFLPCChar a_pcOutputString );
FF_DLLIMPORT void     FF_CDECL   g_FFTraceF( FFLPCChar a_pcFormat, ... );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFUnmapViewOfFile( FFLPCVoid a_pBaseAddress );
FF_DLLIMPORT FFU32    FF_STDCALL g_FFWaitForSingleObject( FFLPVoid a_hHandle, FFU32 a_u32Milliseconds );
FF_DLLIMPORT FFBool   FF_STDCALL g_FFWriteFile( FFLPVoid a_hFile, FFLPCVoid a_pBuffer, FFU32 a_u32NumberOfBytesToWrite, FFU32 * a_pu32NumberOfBytesWritten );
FF_DLLIMPORT FFLPVoid FF_STDCALL g_FFZeroMemory( FFLPVoid a_pDestination, FFU32 a_u32Length );

#endif
