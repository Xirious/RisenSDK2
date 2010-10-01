template< typename T >
void bTQueueBase< T >::Copy( T * _d, T const * _s, GEInt _n )
{
    while( _n-- )
        *_d++ = *_s++;
}

template< typename T >
void bTQueueBase< T >::Delete( T * _e, GEInt _n )
{
    for( ; _n--; _e++ )
        _e->~T();
}

template< typename T >
void bTQueueBase< T >::Move( T * _d, T const * _s, GEInt _n )
{
    if( _n > 0 )
        ::memmove( _d, _s, _n * sizeof( T ) );
}

template< typename T >
void bTQueueBase< T >::New( T * _e, GEInt _n )
{
    g_ZeroMemory( _e, _n * sizeof( T ) );
    for( ; _n--; _e++ )
        ::new( _e ) T;
}

template< typename T >
GEInt bTQueueBase< T >::IndexToOffset( GEInt _i ) const
{
    return (this->m_u32Head + _i) % this->GetCapacity();
}

template< typename T >
void bTQueueBase< T >::Init( void )
{
    this->m_pArray = 0;
    this->m_u32Capacity = 0;
    this->m_u32Head = 0;
    this->m_u32Tail = 0;
    this->m_bFull = GEFalse;
}

template< typename T >
GEInt bTQueueBase< T >::OffsetToIndex( GEInt _o ) const
{
    GEInt _i = _o - this->m_u32Head;
    if( _i < 0 )
    {
        _i += this->GetCapacity();
        if( _i < 0 )
            _i = bEIndex_Invalid;
    }
    return _i;
}

template< typename T >
T * bTQueueBase< T >::AccessArray( void )
{
    return this->m_pArray;
}

template< typename T >
T & bTQueueBase< T >::AccessAt( GEInt _i )
{
    return this->m_pArray[ this->IndexToOffset( _i ) ];
}

template< typename T >
T const * bTQueueBase< T >::GetArray( void ) const
{
    return this->m_pArray;
}

template< typename T >
T const & bTQueueBase< T >::GetAt( GEInt _i ) const
{
    return this->m_pArray[ this->IndexToOffset( _i ) ];
}

template< typename T >
void bTQueueBase< T >::GetAt( GEInt _i, T & _e ) const
{
    _e = this->GetAt( _i );
}

template< typename T >
GEInt bTQueueBase< T >::GetCapacity( void ) const
{
    return this->m_u32Capacity;
}

template< typename T >
GEInt bTQueueBase< T >::GetCount( void ) const
{
    if( this->m_u32Head == this->m_u32Tail )
    {
        if( this->m_bFull )
            return this->GetCapacity();
        return 0;
    }
    if( this->m_u32Head < this->m_u32Tail )
        return this->m_u32Tail - this->m_u32Head;
    return this->GetCapacity() - (this->m_u32Head - this->m_u32Tail);
}

template< typename T >
GEInt bTQueueBase< T >::IndexOf( T const & _e ) const
{
    for( GEInt _i = 0; _i < this->GetCount(); _i++ )
        if( _e == this->GetAt( _i ) )
            return _i;
    return bEIndex_Invalid;
}

template< typename T >
GEBool bTQueueBase< T >::IsEmpty( void ) const
{
    if( this->m_bFull )
        return GEFalse;
    if( (0 == this->m_pArray) || (this->m_u32Head == this->m_u32Tail) )
        return GETrue;
    return GEFalse;
}

template< typename T >
GEBool bTQueueBase< T >::IsFull( void ) const
{
    return this->m_bFull;
}

template< typename T >
T & bTQueueBase< T >::operator [] ( GEInt _i )
{
    return this->AccessAt( _i );
}

template< typename T >
T const & bTQueueBase< T >::operator [] ( GEInt _i ) const
{
    return this->GetAt( _i );
}

template< typename T >
bTQueueBase< T >::bTQueueBase( void )
{
    this->Init();
}

template< typename T >
bTQueueBase< T >::~bTQueueBase( void )
{
}
