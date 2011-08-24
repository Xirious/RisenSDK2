#ifndef FF_DEF_H_INCLUDED
#define FF_DEF_H_INCLUDED

#define FF_PADDING( X ) char __padding[ X ];
#define FF_PADDING1( X ) char __padding1[ X ];
#define FF_PADDING2( X ) char __padding2[ X ];

#define FF_FORCE_DWORD 0x7FFFFFFFL

#define FF_CCALL __cdecl
#define FF_STDCALL __stdcall

#define FF_DLLIMPORT __declspec( dllimport )
#define FF_DLLIMPORT_EXTC extern "C" FF_DLLIMPORT
#define FF_DLLIMPORT_DATA extern "C++" FF_DLLIMPORT

#define FF_DECLARE_INTERFACE( iff, iid ) class __declspec( uuid( iid ) ) __declspec( novtable ) iff

#endif
