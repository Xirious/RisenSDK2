template< typename T >
T & PSNpc::Property( void )
{
    return *static_cast< T * >( static_cast< Entity * >( this ) );
}

template< typename T >
T const & PSNpc::Property( void ) const
{
    return *static_cast< T const * >( static_cast< Entity const * >( this ) );
}
