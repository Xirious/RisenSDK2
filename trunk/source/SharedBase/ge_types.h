#ifndef GE_TYPES_H_INCLUDED
#define GE_TYPES_H_INCLUDED

#pragma warning( push, 1 )
#include <typeinfo>
#pragma warning( pop )

#define GETrue true
#define GEFalse false

enum bEResult
{
    bEResult_False = GEFalse,
    bEResult_Ok    = GETrue,
    //FIXME: bEResult constants.
    bEResult_ForceDWORD = GE_FORCE_DWORD
};

typedef signed char           GEI8;
typedef unsigned char         GEU8;
typedef short                 GEI16;
typedef unsigned short        GEU16;
typedef long                  GEI32;
typedef unsigned long         GEU32;
typedef int                   GEInt;
typedef unsigned int          GEUInt;
typedef __int64               GEI64;
typedef unsigned __int64      GEU64;
typedef bool                  GEBool;
typedef float                 GEFloat;
typedef double                GEDouble;
typedef void *                GELPVoid;
typedef void const *          GELPCVoid;
typedef char                  GEChar;
typedef char *                GELPChar;
typedef char const *          GELPCChar;
typedef unsigned char         GEByte;
typedef unsigned char *       GELPByte;
typedef unsigned char const * GELPCByte;
typedef wchar_t               GEUnicodeChar;
typedef wchar_t *             GELPUnicodeChar;
typedef wchar_t const *       GELPCUnicodeChar;

GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_f2PI;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fDegToRad;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fEpsilon;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fHuge;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fInvEpsilon;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fInvPI;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fNegInfinity;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fPI;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fPIDiv2;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fPIDiv4;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fPosInfinity;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fRadToDeg;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fSqrt2;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fZFar;
GE_C_LINKAGE GE_DLLIMPORT GEFloat const g_fZNear;

GE_C_LINKAGE GE_DLLIMPORT GEInt const g_idInvalid;

#endif
