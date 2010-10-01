template< typename T >
void bTValQueue< T >::SetAtOffset( GEInt _o, T const & _e )
{
    bTQueueBase< T >::Copy( this->AccessArray() + _o, &_e, 1 );
}

template< typename T >
void bTValQueue< T >::Clear( void )
{
    if( this->m_pArray )
        GE_FREE( this->m_pArray );
    this->Init();
}

template< typename T >
void bTValQueue< T >::CopyFrom( bTValQueue< T > const & _s )
{
    if( this != &_s )
    {
        this->Clear();
        if( !_s.IsEmpty() )
        {
            GEInt const _n = _s.GetCount();
            GEU32 const _h = _s.m_u32Head;
            GEU32 const _t = _s.m_u32Tail;
            this->Reserve( _n );
            if ( _h < _t )
                bTQueueBase< ELEMENT >::Copy( this->m_pArray, _s.m_pArray + _h, _t - _h  );
            else
            {
                GEInt const _o = _s.GetCapacity() - _h;
                bTQueueBase< T >::Copy( this->m_pArray, _s.m_pArray + _h, _o );
                bTQueueBase< T >::Copy( this->m_pArray + _o, _s.m_pArray, _t );
            }
            this->m_u32Tail = _n % this->GetCapacity();
            this->m_bFull = this->m_u32Head == this->m_u32Tail;
        }
    }
}

template< typename T >
void bTValQueue< T >::CopyTo( bTValQueue< T > & _s ) const
{
    _s.CopyFrom( *this );
}

template< typename T >
GEBool bTValQueue< T >::Push( T const & _e )
{
    if( this->IsFull() )
        return GEFalse;
    GEInt const _o = this->m_u32Tail++;
    if( this->m_u32Tail == this->m_u32Capacity )
        this->m_u32Tail = 0;
    this->m_bFull = this->m_u32Tail == this->m_u32Head;
    this->SetAtOffset( _o, _e );
    return GETrue;
}

template< typename T >
GEBool bTValQueue< T >::Pop( T & _e )
{
    if( this->IsEmpty() )
        return GEFalse;
    _e = this->m_pArray[ this->m_u32Head ];
    this->m_u32Head++;
    if( this->m_u32Head == this->m_u32Capacity )
        this->m_u32Head = 0;
    this->m_bFull = GEFalse;
    return GETrue;
}

template< typename T >
void bTValQueue< T >::Reserve( GEInt _n )
{
    if( _n > this->GetCapacity() )
    {
        if( (this->IsFull() && this->m_u32Head) ||
            (this->m_u32Head > this->m_u32Tail) )
        {
            GEInt const _c = this->GetCount();
            GEInt const _o = this->GetCapacity() - this->m_u32Head;
            T * pArray = static_cast< T * >( GE_MALLOC( _n * sizeof(T) ) );
            bTQueueBase< T >::Copy( pArray, this->m_pArray + this->m_u32Head, _o );
            bTQueueBase< T >::Copy( pArray + _o, this->m_pArray, _c - _o );
            this->m_u32Head = 0;
            this->m_u32Tail = _c;
            GE_FREE( this->m_pArray );
            this->m_pArray = pArray;
        }
        else
        {
            this->m_pArray = static_cast< T * >( GE_REALLOC( this->m_pArray, _n * sizeof(T) ) );
            if( this->IsFull() )
                this->m_u32Tail = this->m_u32Capacity;
        }
        this->m_u32Capacity = _n;
        this->m_bFull = GEFalse;
    }
}

template< typename T >
bTValQueue< T > & bTValQueue< T >::operator = ( bTValQueue< T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename T >
bTValQueue< T >::bTValQueue( bTValQueue< T > const & _s ) :
    bTQueueBase< T >()
{
    this->CopyFrom( _s );
}

template< typename T >
bTValQueue< T >::bTValQueue( GEInt _c ) :
    bTQueueBase< T >()
{
    this->Reserve( _c );
}

template< typename T >
bTValQueue< T >::bTValQueue() :
    bTQueueBase< T >()
{
}

template< typename T >
bTValQueue< T >::~bTValQueue()
{
    this->Clear();
}
