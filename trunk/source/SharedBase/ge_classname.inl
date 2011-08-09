#pragma warning( push )
#pragma warning( disable : 4640 )  // construction of local static object is not thread-safe

template< typename T >
bCString const & bTClassName< T >::GetName( void )
{
    static bCString const strName( bCClassNameBase::UnMangle( typeid( T ).name() ) );
    return strName;
}

#pragma warning( pop )
