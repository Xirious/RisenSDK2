#ifndef FF_DEF_H_INCLUDED
#define FF_DEF_H_INCLUDED

#define __FF_PASTE_TOKENS( A, B ) A##B
#define _FF_PASTE_TOKENS( A, B ) __FF_PASTE_TOKENS( A, B )
#define FF_PASTE_TOKENS( A, B ) _FF_PASTE_TOKENS( A, B )

#define FF_PADDING( X ) char FF_PASTE_TOKENS( __padding, __LINE__ )[ X ];

#define FF_FORCE_DWORD 0x7FFFFFFFL

#define FF_CCALL __cdecl
#define FF_STDCALL __stdcall

#define FF_DLLIMPORT __declspec( dllimport )
#define FF_DLLIMPORT_EXTC extern "C" FF_DLLIMPORT
#define FF_DLLIMPORT_DATA extern "C++" FF_DLLIMPORT

#define FF_DECLARE_INTERFACE( iff, iid ) class __declspec( uuid( iid ) ) __declspec( novtable ) iff

#endif
