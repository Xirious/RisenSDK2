#ifndef FF_STRUCT_H_INCLUDED
#define FF_STRUCT_H_INCLUDED

struct FFGUID
{
    GUID m_Guid;
};

struct SFFFileTime
{
    FILETIME m_FileTime;
};

struct SFFFileFind
{
    SFFFileTime m_CreationTime;       // 0000
    SFFFileTime m_LastAccessTime;     // 0008
    SFFFileTime m_LastWriteTime;      // 0010
    FFU32       m_u32FileSizeHigh;    // 0018
    FFU32       m_u32FileSizeLow;     // 001C
    FFU32       m_u32Reserved0;       // 0020
    FFU32       m_u32Reserved1;       // 0024
    FFU32       m_u32FileAttributes;  // 0028
    bCString    m_strFileName;        // 002C
    // sizeof(SFFFileFind)               0030
};

typedef SFFFileFind SFFFileData;

#endif
