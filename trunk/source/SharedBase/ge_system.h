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

GE_DLLIMPORT_EXTC void GE_SILENTLOG_ERR( GELPCChar, ... );
GE_DLLIMPORT_EXTC void GE_SILENTLOG_OUT( GELPCChar, ... );

// C2733: GetVersion conflicts with kernel32.GetVersion
namespace GESystem
{
    GE_DLLIMPORT_EXTC GEBool   GE_STDCALL CheckFileVersion( GELPCChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
    GE_DLLIMPORT_EXTC GEBool   GE_STDCALL GetDLLVersion( GELPCChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
    GE_DLLIMPORT_EXTC GELPChar GE_STDCALL GetVersion( GELPCChar );
    GE_DLLIMPORT_EXTC GEBool   GE_STDCALL ParseVersionString( GELPChar, GEU32 *, GEU32 *, GEU32 *, GEU32 * );
}
using namespace GESystem;

GE_DLLIMPORT_EXTC GELongBool   GE_STDCALL g_CloseMutex( GELPVoid );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_CoCreateGuid( bSGuid * );
GE_DLLIMPORT_EXTC void         GE_STDCALL g_CopyGUID( bSGuid *, bSGuid const * );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_CreateMutex( GELPCChar );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_DateToChar( bSFileTime const *, GELPChar );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_DateToCharW( bSFileTime const *, GELPUnicodeChar );
GE_DLLIMPORT_EXTC void         GE_STDCALL g_DebugBreak( void );
GE_DLLIMPORT_EXTC GEU32        GE_STDCALL g_GetCurrentProcessId( void );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_GetCurrentThread( void );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_GetFileDate( GELPCChar, GELPChar, GEU32 );
GE_DLLIMPORT_EXTC GEU32        GE_STDCALL g_GetModuleFileName( GELPVoid, GELPChar, GEU32 );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_GetProcAddress( GELPVoid, GELPCChar );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_GetShortDateChar( bSFileTime const *, GELPChar );
GE_DLLIMPORT_EXTC bSFileTime * GE_STDCALL g_GetSystemTime( bSFileTime * );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_GetThreadPriority( GELPVoid );
GE_DLLIMPORT_EXTC GEBool       GE_STDCALL g_IIDFromString( GELPCUnicodeChar, bSGuid * );
GE_DLLIMPORT_EXTC GEBool       GE_STDCALL g_IsEqualGUID( bSGuid const *, bSGuid const * );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_LoadModule( GELPCChar );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_MemCmp( GELPCVoid, GELPCVoid, GEU32 );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_MemCpy( GELPVoid, GELPCVoid, GEU32 );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_MemSet( GELPVoid, GEInt, GEInt );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_MessageBox( GELPVoid, GELPCChar, GELPCChar, GEU32 );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_MultiByteToWideChar( GEU32, GEU32, GELPCChar, GEInt, GELPUnicodeChar, GEInt );
GE_DLLIMPORT_EXTC void         GE_STDCALL g_OutputDebugString( GELPCChar );
GE_DLLIMPORT_EXTC GEBool       GE_STDCALL g_SetThreadPriority( GELPVoid, GEInt );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_StringFromGUID2( bSGuid const *, GELPUnicodeChar, GEInt );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_TimeToChar( bSFileTime const *, GELPChar );
GE_DLLIMPORT_EXTC GELongBool   GE_STDCALL g_UnloadModule( GELPVoid );
GE_DLLIMPORT_EXTC GEInt        GE_STDCALL g_WideCharToMultiByte( GEU32, GEU32, GELPCUnicodeChar, GEInt, GELPChar, GEInt, GELPCChar, GELongBool * );
GE_DLLIMPORT_EXTC GELPVoid     GE_STDCALL g_ZeroMemory( GELPVoid, GEU32 );

GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_acosf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_asinf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_atan2f( GEFloat, GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_cosf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_fabsf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_fcopysign( GEFloat, GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_floorf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_pow( GEFloat, GEInt );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_sinf( GEFloat );
GE_DLLIMPORT_EXTC GEFloat GE_STDCALL g_sqrtf( GEFloat );

GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswalnum( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswalpha( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswascii( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswdigit( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswlower( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswspace( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEBool          GE_STDCALL g_iswupper( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEUnicodeChar   GE_STDCALL g_towlower( GEUnicodeChar );
GE_DLLIMPORT_EXTC GEUnicodeChar   GE_STDCALL g_towupper( GEUnicodeChar );
GE_DLLIMPORT_EXTC GELPUnicodeChar GE_STDCALL g_wcschr( GELPCUnicodeChar, GEUnicodeChar );
GE_DLLIMPORT_EXTC GEInt           GE_STDCALL g_wcscmp( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GEU32           GE_STDCALL g_wcscspn( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GEInt           GE_STDCALL g_wcsicmp( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GEU32           GE_STDCALL g_wcslen( GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GEInt           GE_STDCALL g_wcsncmp( GELPCUnicodeChar, GELPCUnicodeChar, GEU32 );
GE_DLLIMPORT_EXTC GELPUnicodeChar GE_STDCALL g_wcspbrk( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GELPUnicodeChar GE_STDCALL g_wcsrchr( GELPCUnicodeChar, GEUnicodeChar );
GE_DLLIMPORT_EXTC GEU32           GE_STDCALL g_wcsspn( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GELPUnicodeChar GE_STDCALL g_wcsstr( GELPCUnicodeChar, GELPCUnicodeChar );
GE_DLLIMPORT_EXTC GEDouble        GE_STDCALL g_wcstod( GELPCUnicodeChar, GELPUnicodeChar * );
GE_DLLIMPORT_EXTC GEInt           GE_STDCALL g_wcstol( GELPCUnicodeChar, GELPUnicodeChar *, GEInt );

GE_DLLIMPORT_EXTC GEInt GE_STDCALL g_vsscanf( GELPChar, GELPCChar, GELPVoid );

#endif
