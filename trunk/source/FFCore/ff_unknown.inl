template< typename T >
T * IFFUnknown::QueryInterface( void )
{
    T * pObject = 0;
    this->QueryInterface( *reinterpret_cast< FFGUID const * >( &__uuidof( T ) ), reinterpret_cast< FFLPVoid * >( &pObject ) );
    return pObject;
}
