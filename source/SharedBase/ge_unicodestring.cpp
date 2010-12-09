#include "../SharedBase.h"

GELPUnicodeChar bCUnicodeString::bSUnicodeStringData::GetText( void )
{
    return reinterpret_cast< GELPUnicodeChar >( this + 1 );
}

