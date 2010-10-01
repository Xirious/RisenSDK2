#ifndef FF_DEF_H_INCLUDED
#define FF_DEF_H_INCLUDED

#define FF_PADDING( X ) char __padding[ X ];

#define FF_FORCE_DWORD 0x7FFFFFFFL

#define FF_CDECL __cdecl
#define FF_STDCALL __stdcall

#define FF_C_LINKAGE extern "C"
#define FF_DLLIMPORT __declspec( dllimport )

#define FF_DECLARE_INTERFACE( iff, iid ) class __declspec( uuid( iid ) ) __declspec( novtable ) iff

#endif
