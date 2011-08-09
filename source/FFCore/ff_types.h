#ifndef FF_TYPES_H_INCLUDED
#define FF_TYPES_H_INCLUDED

#define FFTrue true
#define FFFalse false

typedef signed char           FFI8;
typedef unsigned char         FFU8;
typedef short                 FFI16;
typedef unsigned short        FFU16;
typedef long                  FFI32;
typedef unsigned long         FFU32;
typedef int                   FFInt;
typedef unsigned int          FFUInt;
typedef __int64               FFI64;
typedef unsigned __int64      FFU64;
typedef bool                  FFBool;
typedef float                 FFFloat;
typedef double                FFDouble;
typedef void *                FFLPVoid;
typedef void const *          FFLPCVoid;
typedef char                  FFChar;
typedef char *                FFLPChar;
typedef char const *          FFLPCChar;
typedef unsigned char         FFUChar;
typedef unsigned char *       FFLPUChar;
typedef unsigned char const * FFLPCUChar;
typedef wchar_t               FFUnicodeChar;
typedef wchar_t *             FFLPUnicodeChar;
typedef wchar_t const *       FFLPCUnicodeChar;

FF_C_LINKAGE FF_DLLIMPORT FFChar const g_cUnixDirTerminator;
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_cVolumeNamePrefix;
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_cVolumeTerminator;
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_cWindowsDirTerminator;
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_pcDirTerminators[ 2 ];
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_pcIllegalNameCharacters[ 9 ];
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_pcIllegalNameFilterCharacters[ 7 ];
FF_C_LINKAGE FF_DLLIMPORT FFChar const g_pcIllegalVolumeCharacters[ 8 ];
FF_C_LINKAGE FF_DLLIMPORT FFLPCChar    g_pszParent;
FF_C_LINKAGE FF_DLLIMPORT FFLPCChar    g_pszSelf;

#endif
