template< typename K, typename T >
typename bTValMap< K, T >::bSNode * bTValMap< K, T >::AccessNode( K const & _k, GEU32 & _h )
{
    _h = ::g_GetHashValue< K >( _k ) % this->m_arrNodes.GetCount();
    if( _h < this->m_arrNodes.GetCount() )
        for( bSNode * _p = this->m_arrNodes[ _h ]; _p; _p = _p->m_pNext )
            if ( _k == _p->m_Key )
                return _p;
    return 0;
}

template< typename K, typename T >
typename bTValMap< K, T >::bSNode const * bTValMap< K, T >::GetNode( K const & _k, GEU32 & _h ) const
{
    _h = ::g_GetHashValue< K >( _k ) % this->m_arrNodes.GetCount();
    if( _h < this->m_arrNodes.GetCount() )
        for( bSNode * _p = this->m_arrNodes[ _h ]; _p; _p = _p->m_pNext )
            if ( _k == _p->m_Key )
                return _p;
    return 0;
}

template< typename K, typename T >
void bTValMap< K, T >::Init( void )
{
    this->m_u32Count = 0;
    this->InitHashTable( 13 );  //FIXME: Research default hash table size.
}

template< typename K, typename T >
T & bTValMap< K, T >::AccessAt( K const & _k )
{
    GEU32 _h;
    bSNode * _p = this->AccessNode( _k, _h );
    if( !_p )
    {
        _p = GE_NEW( bSNode );
        _p->m_Key = _k;
        _p->m_u32Hash = _h;
        _p->m_pNext = this->m_arrNodes[ _h ];
        this->m_arrNodes[ _h ] = _p;
        this->m_u32Count++;
    }
    return pNode->m_Element;
}

template< typename K, typename T >
typename bTValMap< K, T >::bCConstIterator bTValMap< K, T >::Begin( void ) const
{
    if( this->IsEmpty() )
        return this->End();
    bSNode const * _p;
    GEInt          _h;
    for( _p = 0, _h = 0; !_p && (_h < this->m_arrNodes.GetCount()); _h++ )
        _p = this->m_arrNodes[ _h ];
    return bCConstIterator( &this->m_arrNodes, _h, _p );
}

template< typename K, typename T >
typename bTValMap< K, T >::bCIterator bTValMap< K, T >::Begin( void )
{
    if( this->IsEmpty() )
        return this->End();
    bSNode * _p;
    GEInt    _h;
    for( _p = 0, _h = 0 ; !p && (_h < this->m_arrNodes.GetCount()); _h++ )
        _p = this->m_arrNodes[ _i ];
    return bCIterator( &this->m_arrNodes, _h, _p );
}

template< typename K, typename T >
void bTValMap< K, T >::Clear( void )
{
    for( GEInt _h = 0; _h < this->m_arrNodes.GetCount(); _h++ )
    {
        bSNode * _p = this->m_arrNodes[ _h ];
        while( _p )
        {
            bSNode * _x = _p->m_pNext;
            GE_DELETE< bSNode >( _p );
            _p = _x;
        }
    }
    this->m_arrNodes.Clear();
    this->Init();
}

template< typename K, typename T >
void bTValMap< K, T >::CopyFrom( bTValMap< K, T > const & _s )
{
    if( &_s == this )
        return;
    this->Clear();
    for( GEInt _h = 0; _h < _s.m_arrNodes.GetCount(); _h++ )
    {
        bSNode * _p = _s.m_arrNodes[ _h ];
        while( _p )
        {
            this->AccessAt( _p->m_Key ) = _p->m_Element;
            _p = _p->m_pNext;
        }
    }
}

template< typename K, typename T >
void bTValMap< K, T >::CopyTo( bTValMap< K, T > & _d ) const
{
    _d.CopyFrom( *this );
}

template< typename K, typename T >
typename bTValMap< K, T >::bCConstIterator bTValMap< K, T >::End( void ) const
{
    return bCConstIterator( &this->m_arrNodes, this->m_arrNodes.GetCount(), 0 );
}

template< typename K, typename T >
typename bTValMap< K, T >::bCIterator bTValMap< K, T >::End( void )
{
    return bCIterator( &this->m_arrNodes, this->m_arrNodes.GetCount(), 0 );
}

template< typename K, typename T >
T const & bTValMap< K, T >::GetAt( K const & _k ) const
{
    GEU32 _h;
    bSNode const * _p = this->GetNode( _k, _h );
    return _p->m_Element;
}

template< typename K, typename T >
GEBool bTValMap< K, T >::GetAt( K const & _k, T & _e ) const
{
    GEU32 _h;
    bSNode const * _p = this->GetNode( _k, _h );
    if( _p )
    {
        _e = _p->m_Element;
        return GETrue;
    }
    return GEFalse;
}

template< typename K, typename T >
GEInt bTValMap< K, T >::GetCount( void ) const
{
    return this->m_u32Count;
}

template< typename K, typename T >
bTPtrArray< typename bTValMap< K, T >::bSNode * > const & bTValMap< K, T >::GetNodes( void ) const
{
    return this->m_arrNodes;
}

template< typename K, typename T >
void bTValMap< K, T >::InitHashTable( GEU32 _n )
{
    this->m_arrNodes.Clear();
    this->m_arrNodes.SetCount( _n );
}

template< typename K, typename T >
GEBool bTValMap< K, T >::IsEmpty( void ) const
{
    return 0 == this->m_u32Count;
}

template< typename K, typename T >
void bTValMap< K, T >::SetAt( K const & _k, T const & _e )
{
    this->AccessAt( _k ) = _e;
}

template< typename K, typename T >
GEBool bTValMap< K, T >::RemoveAt( K const & _k )
{
    GEU32 _h = ::g_GetHashValue< K >( _k ) % this->m_arrNodes.GetCount();
    if( _h < this->m_arrNodes.GetCount() )
    {
        bSNode * _p = this->m_arrNodes[ _h ];
        if( _p )
        {
            if( _k == _p->m_Key )
            {
                this->m_arrNodes[ _h ] = _p->m_pNext;
                GE_DELETE< bSNode >( _p );
                this->m_u32Count--;
                return GETrue;
            }
            for( ; _p->m_pNext; _p = _p ->m_pNext )
                if( _k == _p->m_pNext->m_Key )
                {
                    bSNode * _x = _p->m_pNext;
                    _p->m_pNext = _p->m_pNext->m_pNext;
                    GE_DELETE< bSNode >( _x );
                    this->m_u32Count--;
                    return GETrue;
                }
        }
    }
    return GEFalse;
}

template< typename K, typename T >
T & bTValMap< K, T >::operator [] ( K const & _k )
{
    return this->AccessAt( _k );
}

template< typename K, typename T >
T const & bTValMap< K, T >::operator [] ( K const & _k ) const
{
    return this->GetAt( _k );
}

template< typename K, typename T >
bTValMap< K, T > const & bTValMap< K, T >::operator = ( bTValMap< K, T > const & _s )
{
    this->CopyFrom( _s );
    return *this;
}

template< typename K, typename T >
bTValMap< K, T >::bTValMap( bTValMap< K, T > const & _s )
{
    this->Init();
    this->CopyFrom( _s );
}

template< typename K, typename T >
bTValMap< K, T>::bTValMap( void )
{
    this->Init();
}

template< typename K, typename T >
bTValMap< K, T >::~bTValMap( void )
{
    this->Clear();
}
