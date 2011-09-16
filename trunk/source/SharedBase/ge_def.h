#ifndef GE_DEF_H_INCLUDED
#define GE_DEF_H_INCLUDED

#define __GE_PASTE_TOKENS( A, B ) A##B
#define _GE_PASTE_TOKENS( A, B ) __GE_PASTE_TOKENS( A, B )
#define GE_PASTE_TOKENS( A, B ) _GE_PASTE_TOKENS( A, B )

#define GE_PADDING( X ) char GE_PASTE_TOKENS( __padding, __LINE__ )[ X ];
//NOTE: [NicoDE] GE_PADDINGx will be removed during next code review.
#define GE_PADDING1( X ) GE_PADDING( X )
#define GE_PADDING2( X ) GE_PADDING( X )

#define GE_FORCE_DWORD 0x7FFFFFFFL

#define GE_CCALL __cdecl
#define GE_STDCALL __stdcall
#define GE_FASTCALL __fastcall

#define GE_DLLIMPORT __declspec( dllimport )
#define GE_DLLIMPORT_EXTC extern "C" GE_DLLIMPORT
#define GE_DLLIMPORT_DATA extern "C++" GE_DLLIMPORT

namespace Genome
{
    template< bool match > struct SIZEOF_ASSERTION;
    template<> struct SIZEOF_ASSERTION< true >{ enum { value = 1 }; };
    template< int x > struct sizeof_test{};
}
#define GE_ASSERT_SIZEOF( TYPE, SIZE ) typedef ::Genome::sizeof_test< sizeof( ::Genome::SIZEOF_ASSERTION< sizeof( TYPE ) == ( SIZE ) > ) > GE_PASTE_TOKENS( Genome_sizeof_, __COUNTER__ );

#endif
