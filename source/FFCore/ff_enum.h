#ifndef FF_ENUM_H_INCLUDED
#define FF_ENUM_H_INCLUDED

enum EFFFileAccess
{
    EFFFileAccess_Read       = 0x00000001,
    EFFFileAccess_Write      = 0x00000002,
    EFFFileAccess_ReadWrite  = 0x00000003,
    EFFFileAccess_ForceDWORD = FF_FORCE_DWORD
};

enum EFFFileCreate
{
    EFFFileCreate_CreateAlways     = 0x00000001,
    EFFFileCreate_CreateNew        = 0x00000002,
    EFFFileCreate_OpenAlways       = 0x00000003,
    EFFFileCreate_OpenExisting     = 0x00000004,
    EFFFileCreate_TruncateExisting = 0x00000005,
    EFFFileCreate_ForceDWORD       = FF_FORCE_DWORD
};

enum EFFFileMapProtection
{
    EFFFileMapProtection_ReadOnly   = 0x00000002,
    EFFFileMapProtection_ReadWrite  = 0x00000004,
    EFFFileMapProtection_ForceDWORD = FF_FORCE_DWORD
};

enum EFFFileSeek
{
    EFFFileSeek_Begin      = 0x00000000,
    EFFFileSeek_Current    = 0x00000001,
    EFFFileSeek_End        = 0x00000002,
    EFFFileSeek_ForceDWORD = FF_FORCE_DWORD
};

enum EFFSpecialFolder
{
    EFFSpecialFolder_User         = 0x00000000,
    EFFSpecialFolder_MyDocuments  = 0x00000001,
    EFFSpecialFolder_AppData      = 0x00000002,
    EFFSpecialFolder_LocalAppData = 0x00000003,
    EFFSpecialFolder_SavedGames   = 0x00000004,
    EFFSpecialFolder_System       = 0x00000005,
    EFFSpecialFolder_ForceDWORD   = FF_FORCE_DWORD
};

#endif
