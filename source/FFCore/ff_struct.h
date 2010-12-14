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

struct SFFFileData
{
    SFFFileTime m_CreationTime;      // 0000
    SFFFileTime m_LastAccessTime;    // 0008
    SFFFileTime m_ModificationTime;  // 0010
    FFU32       m_u32FileSizeHigh;   // 0018
    FFU32       m_u32FileSizeLow;    // 001C
    FFU32       m_u32Reserved0;      // 0020
    FFU32       m_u32Reserved1;      // 0024
    FFU32       m_u32Attributes;     // 0028
};
GE_ASSERT_SIZEOF( SFFFileData, 0x002C )

struct SFFFileFind
{
    SFFFileData m_FileData;     // 0000
    bCString    m_strFileName;  // 002C
    bCString    m_strFilePath;  // 0030
};
GE_ASSERT_SIZEOF( SFFFileFind, 0x0034 )


#endif
