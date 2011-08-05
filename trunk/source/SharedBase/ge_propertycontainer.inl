template< typename T >
void bTPropertyContainer< T >::Invalidate( void )
{
    this->m_Value = bTPropertyContainer< T >::GetDefaultValue();
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
    a_Stream << bTPropertyContainer< T >::GetVersion();
    a_Stream.Write( &this->m_Value, sizeof( T ) );
    return bEResult_Ok;
}

template< typename T >
T bTPropertyContainer< T >::ms_DefaultValue;

template< typename T >
GEU16 bTPropertyContainer< T >::GetVersion( void )
{
    return static_cast< GEU16 >( bTPropertyContainer< T >::bEPropertyPersistence_Version );
}

template< typename T >
T const & bTPropertyContainer< T >::GetDefaultValue( void )
{
    return bTPropertyContainer< T >::ms_DefaultValue;
}

template< typename T >
bCString const & bTPropertyContainer< T >::GetTypeName( void )
{
    return bTClassName< T >::GetName();
}

template< typename T >
void bTPropertyContainer< T >::SetDefaultValue( T const & a_Value )
{
    bTPropertyContainer< T >::ms_DefaultValue = a_Value;
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
bTPropertyContainer< T >::operator GEU32 ( void ) const
{
    return static_cast< GEU32 >( this->m_Value );
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

template< typename T >
bTPropertyContainer< T > & bTPropertyContainer< T >::operator = ( bTPropertyContainer< T > const & a_Source )
{
    this->m_Value = a_Source.m_Value;
    return *this;
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
bTPropertyContainer< T >::bTPropertyContainer( void )
{
    this->Invalidate();
}

template< typename T >
bTPropertyContainer< T >::~bTPropertyContainer( void )
{
}
