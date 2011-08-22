#include "../Script.h"

template< typename T >
T & EntityPropertySet::Property( void )
{
    return *reinterpret_cast< T::_tProperty * >( this );
}

template< typename T >
T const & EntityPropertySet::Property( void ) const
{
    return *reinterpret_cast< T::_tProperty const * >( this );
}

