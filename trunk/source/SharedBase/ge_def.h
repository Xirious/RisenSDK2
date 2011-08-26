#ifndef GE_DEF_H_INCLUDED
#define GE_DEF_H_INCLUDED

#define GE_PADDING( X ) char __padding[ X ];
#define GE_PADDING1( X ) char __padding1[ X ];
#define GE_PADDING2( X ) char __padding2[ X ];

#define GE_FORCE_DWORD 0x7FFFFFFFL

#define GE_CCALL __cdecl
#define GE_STDCALL __stdcall
#define GE_FASTCALL __fastcall

#define GE_DLLIMPORT __declspec( dllimport )
#define GE_DLLIMPORT_EXTC extern "C" GE_DLLIMPORT
#define GE_DLLIMPORT_DATA extern "C++" GE_DLLIMPORT

#define GE_PASTE_TOKENS( A, B ) GE_PASTE_TOKENS_( A, B )
#define GE_PASTE_TOKENS_( A, B ) GE_PASTE_TOKENS__( A, B )
#define GE_PASTE_TOKENS__( A, B ) A##B
namespace Genome
{
    template< bool match > struct SIZEOF_ASSERTION;
    template<> struct SIZEOF_ASSERTION< true >{ enum { value = 1 }; };
    template< int x > struct sizeof_test{};
}
#define GE_ASSERT_SIZEOF( TYPE, SIZE ) typedef ::Genome::sizeof_test< sizeof( ::Genome::SIZEOF_ASSERTION< sizeof( TYPE ) == ( SIZE ) > ) > GE_PASTE_TOKENS( Genome_sizeof_, __COUNTER__ );

#endif
