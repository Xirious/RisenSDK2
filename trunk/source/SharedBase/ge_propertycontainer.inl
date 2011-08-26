
template< typename T >
void bTPropertyContainer< T >::Invalidate( void )
{
    g_MemSet( &this->m_Value, -1, sizeof( T ) );
}

template< typename T >
bEResult bTPropertyContainer< T >::Read( bCIStream & a_Stream )
{
    GEU16 u16Version;
    a_Stream >> u16Version;
    a_Stream.Read( &this->m_Value, sizeof( T ) );
    return bEResult_Ok;
}

template< typename T >
bEResult bTPropertyContainer< T >::Write( bCOStream & a_Stream ) const
{
    GEU16 const u16Version = 201;
    a_Stream << u16Version;
    a_Stream.Write( &this->m_Value, sizeof( T ) );
    return bEResult_Ok;
}

template< typename T >
T & bTPropertyContainer< T >::AccessValue( void )
{
    return this->m_Value;
}

template< typename T >
T const & bTPropertyContainer< T >::GetValue( void ) const
{
    return this->m_Value;
}

template< typename T >
void bTPropertyContainer< T >::SetValue( T const & a_Value )
{
    this->m_Value = a_Value;
}

template< typename T >
bTPropertyContainer< T >::bTPropertyContainer( T const & a_Value )
{
    this->m_Value = a_Value;
}

template< typename T >
bTPropertyContainer< T >::bTPropertyContainer( bTPropertyContainer< T > const & a_Source )
{
    this->m_Value = a_Source.m_Value;
}

template< typename T >
bTPropertyContainer< T >::operator T & ( void )
{
    return this->m_Value;
}

template< typename T >
bTPropertyContainer< T >::operator T const & ( void ) const
{
    return this->m_Value;
}

template< typename T >
GEBool bTPropertyContainer< T >::operator == ( bTPropertyContainer< T > const & a_Other ) const
{
    return a_Other.m_Value == this->m_Value;
}

template< typename T >
GEBool bTPropertyContainer< T >::operator == ( T const & a_Value ) const
{
    return a_Value == this->m_Value;
}

template< typename T >
GEBool bTPropertyContainer< T >::operator != ( bTPropertyContainer< T > const & a_Other ) const
{
    return !(this->operator == ( a_Other ));
}

template< typename T >
GEBool bTPropertyContainer< T >::operator != ( T const & a_Value ) const
{
    return !(this->operator == ( a_Value ));
}

