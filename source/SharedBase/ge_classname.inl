template< typename T >
bCString const & bTClassName< T >::GetName( void )
{
    static bCString const strName( bCClassNameBase::UnMangle( typeid( T ).name() ) );
    return strName;
}
