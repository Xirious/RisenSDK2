template< typename T >
T & Entity::PropertySet( void )
{
    return *static_cast< T * >( this );
}

template< typename T >
T const & Entity::PropertySet( void ) const
{
    return *static_cast< T const * >( this );
}
