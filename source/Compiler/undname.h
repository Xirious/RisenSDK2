#ifndef UNDNAME_H_INCLUDED
#define UNDNAME_H_INCLUDED

#include <string>

enum UndecorateFlags {
    Undecorate_Complete             = 0,
    Undecorate_NoUnderScore         = 0x00000001,
    Undecorate_NoMSKeywords         = 0x00000002,
    Undecorate_NoFunctionReturns    = 0x00000004,
    Undecorate_NoAllocationModel    = 0x00000008,
    Undecorate_NoAllocationLanguage = 0x00000010,
    Undecorate_NoThisTypes          = 0x00000060,
    Undecorate_NoAccessSpecifiers   = 0x00000080,
    Undecorate_NoThrowTypes         = 0x00000100,
    Undecorate_NoMemberTypes        = 0x00000200,
    Undecorate_NameOnly             = 0x00001000,
    Undecorate_TypeOnly             = 0x00002000,
    Undecorate_TemplateParameters   = 0x00004000,
    Undecorate_NoEcsu               = 0x00008000,
    Undecorate_NoIdentCharCheck     = 0x00010000,
    Undecorate_NoPtr64              = 0x00020000,
    Undecorate_NoEllipsis           = 0x00040000
};
static inline UndecorateFlags operator | ( UndecorateFlags const & a, UndecorateFlags const & b )
{
    return static_cast< UndecorateFlags >( static_cast< int >( a ) | static_cast< int >( b ) );
}

std::string UndecorateName( std::string const & name, UndecorateFlags = Undecorate_Complete );

#endif
