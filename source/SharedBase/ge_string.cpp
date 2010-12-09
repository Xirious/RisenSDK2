#include "../SharedBase.h"

GELPChar bCString::bSStringData::GetText( void )
{
    return reinterpret_cast< GELPChar >( this + 1 );
}

