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
    SFFFileTime m_CreationTime;
    SFFFileTime m_LastAccessTime;
    SFFFileTime m_ModificationTime;
    FFU32       m_u32FileSizeHigh;
    FFU32       m_u32FileSizeLow;
    FFU32       m_u32Reserved0;
    FFU32       m_u32Reserved1;
    FFU32       m_u32Attributes;
};
GE_ASSERT_SIZEOF( SFFFileData, 0x002C )

struct SFFFileFind
{
    SFFFileData m_FileData;
    bCString    m_strFileName;
    bCString    m_strFilePath;
};
GE_ASSERT_SIZEOF( SFFFileFind, 0x0034 )


#endif
