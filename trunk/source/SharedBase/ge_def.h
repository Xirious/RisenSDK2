#ifndef GE_DEF_H_INCLUDED
#define GE_DEF_H_INCLUDED

#define GE_PADDING( X ) char __padding[ X ];
#define GE_PADDING1( X ) char __padding1[ X ];
#define GE_PADDING2( X ) char __padding2[ X ];

#define GE_FORCE_DWORD 0x7FFFFFFFL
#define GE_SERIALIZE_VERSION( VERSION ) enum { bEPropertyPersistence_Version = VERSION }

#define GE_CDECL __cdecl
#define GE_STDCALL __stdcall
#define GE_FASTCALL __fastcall

#define GE_C_LINKAGE extern "C"
#define GE_DLLIMPORT __declspec( dllimport )

#endif
