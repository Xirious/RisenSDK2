#ifndef GE_SYSTEM_H_INCLUDED
#define GE_SYSTEM_H_INCLUDED

#pragma warning( push, 1 )
#include <windows.h>
#pragma warning( pop )
//FIXME: GetClassName macro "renames" some Genome class methods.
#ifdef GetClassName
#undef GetClassName
#endif

typedef BOOL GELongBool;
typedef CRITICAL_SECTION bSCriticalSection;
typedef EXCEPTION_POINTERS bSExceptionPointers;
typedef FILETIME bSFileTime;
typedef GUID bSGuid;
typedef POINT bSPoint;
typedef RECT bSRect;

GE_C_LINKAGE GE_DLLIMPORT void GE_SILENTLOG_ERR( GELPCChar, ... );
GE_C_LINKAGE GE_DLLIMPORT void GE_SILENTLOG_OUT( GELPCChar, ... );

// C2733: GetVersion conflicts with kernel32.GetVersion
namespace GESystem
{
    GE_C_LINKAGE GE_DLLIMPORT GEBool   GE_STDCALL CheckFileVersion( GELPCChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
    GE_C_LINKAGE GE_DLLIMPORT GEBool   GE_STDCALL GetDLLVersion( GELPCChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
    GE_C_LINKAGE GE_DLLIMPORT GELPChar GE_STDCALL GetVersion( GELPCChar );
    GE_C_LINKAGE GE_DLLIMPORT GEBool   GE_STDCALL ParseVersionString( GELPChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
}
using namespace GESystem;

GE_C_LINKAGE GE_DLLIMPORT GELongBool   GE_STDCALL g_CloseMutex( GELPVoid );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_CoCreateGuid( bSGuid * );
GE_C_LINKAGE GE_DLLIMPORT void         GE_STDCALL g_CopyGUID( bSGuid *, bSGuid const * );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_CreateMutex( GELPCChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_DateToChar( bSFileTime const *, GELPChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_DateToCharW( bSFileTime const *, GELPUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT void         GE_STDCALL g_DebugBreak( void );
GE_C_LINKAGE GE_DLLIMPORT GEU32        GE_STDCALL g_GetCurrentProcessId( void );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_GetCurrentThread( void );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_GetFileDate( GELPCChar, GELPChar, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GEU32        GE_STDCALL g_GetModuleFileName( GELPVoid, GELPChar, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_GetProcAddress( GELPVoid, GELPCChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_GetShortDateChar( bSFileTime const *, GELPChar );
GE_C_LINKAGE GE_DLLIMPORT bSFileTime * GE_STDCALL g_GetSystemTime( bSFileTime * );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_GetThreadPriority( GELPVoid );
GE_C_LINKAGE GE_DLLIMPORT GEBool       GE_STDCALL g_IIDFromString( GELPCUnicodeChar, bSGuid * );
GE_C_LINKAGE GE_DLLIMPORT GEBool       GE_STDCALL g_IsEqualGUID( bSGuid const *, bSGuid const * );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_LoadModule( GELPCChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_MemCmp( GELPCVoid, GELPCVoid, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_MemCpy( GELPVoid, GELPCVoid, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_MemSet( GELPVoid, GEInt, GEInt );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_MessageBox( GELPVoid, GELPCChar, GELPCChar, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_MultiByteToWideChar( GEU32, GEU32, GELPCChar, GEInt, GELPUnicodeChar, GEInt );
GE_C_LINKAGE GE_DLLIMPORT void         GE_STDCALL g_OutputDebugString( GELPCChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool       GE_STDCALL g_SetThreadPriority( GELPVoid, GEInt );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_StringFromGUID2( bSGuid const *, GELPUnicodeChar, GEInt );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_TimeToChar( bSFileTime const *, GELPChar );
GE_C_LINKAGE GE_DLLIMPORT GELongBool   GE_STDCALL g_UnloadModule( GELPVoid );
GE_C_LINKAGE GE_DLLIMPORT GEInt        GE_STDCALL g_WideCharToMultiByte( GEU32, GEU32, GELPCUnicodeChar, GEInt, GELPChar, GEInt, GELPCChar, GELongBool * );
GE_C_LINKAGE GE_DLLIMPORT GELPVoid     GE_STDCALL g_ZeroMemory( GELPVoid, GEU32 );

GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_acosf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_asinf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_atan2f( GEFloat, GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_cosf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_fabsf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_fcopysign( GEFloat, GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_floorf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_pow( GEFloat, GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_sinf( GEFloat );
GE_C_LINKAGE GE_DLLIMPORT GEFloat GE_STDCALL g_sqrtf( GEFloat );

GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswalnum( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswalpha( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswascii( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswdigit( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswlower( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswspace( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEBool          GE_STDCALL g_iswupper( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEUnicodeChar   GE_STDCALL g_towlower( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEUnicodeChar   GE_STDCALL g_towupper( GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GELPUnicodeChar GE_STDCALL g_wcschr( GELPCUnicodeChar, GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt           GE_STDCALL g_wcscmp( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEU32           GE_STDCALL g_wcscspn( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt           GE_STDCALL g_wcsicmp( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEU32           GE_STDCALL g_wcslen( GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEInt           GE_STDCALL g_wcsncmp( GELPCUnicodeChar, GELPCUnicodeChar, GEU32 );
GE_C_LINKAGE GE_DLLIMPORT GELPUnicodeChar GE_STDCALL g_wcspbrk( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GELPUnicodeChar GE_STDCALL g_wcsrchr( GELPCUnicodeChar, GEUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEU32           GE_STDCALL g_wcsspn( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GELPUnicodeChar GE_STDCALL g_wcsstr( GELPCUnicodeChar, GELPCUnicodeChar );
GE_C_LINKAGE GE_DLLIMPORT GEDouble        GE_STDCALL g_wcstod( GELPCUnicodeChar, GELPUnicodeChar * );
GE_C_LINKAGE GE_DLLIMPORT GEInt           GE_STDCALL g_wcstol( GELPCUnicodeChar, GELPUnicodeChar *, GEInt );

GE_C_LINKAGE GE_DLLIMPORT GEInt GE_STDCALL g_vsscanf( GELPChar, GELPCChar, GELPVoid );

#endif
