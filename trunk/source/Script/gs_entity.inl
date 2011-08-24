#include "../Script.h"

template< typename T >
T & Entity::Property( void )
{
    return *reinterpret_cast< T::_tProperty * >( this );
}

template< typename T >
T const & Entity::Property( void ) const
{
    return *reinterpret_cast< T::_tProperty const * >( this );
}

template< typename T >
T & Entity::PropertySet( void )
{
    return *reinterpret_cast< T::_tPropertySet * >( this );
}

template< typename T >
T const & Entity::PropertySet( void ) const
{
    return *reinterpret_cast< T::_tPropertySet const * >( this );
}

