#ifndef GE_MAPBASE_H_INCLUDED
#define GE_MAPBASE_H_INCLUDED

template< typename T >
inline GEU32 g_GetHashValue( T const & _e )
{
    return reinterpret_cast< GEU32 >( _e ) >> 4;
}

#define GE_DECLARE_MAP_ITERATORS()                                                          \
public:                                                                                     \
    class bCConstIterator;                                                                  \
    class bCIterator;                                                                       \
    friend class bCConstIterator;                                                           \
    friend class bCIterator;                                                                \
    class bCConstIterator                                                                   \
    {                                                                                       \
    protected:                                                                              \
        bTPtrArray< bSNode * > * m_parrNodes;                                               \
        GEInt                    m_iHash;                                                   \
        bSNode *                 m_pNode;                                                   \
    public:                                                                                 \
        GEInt GetHash( void ) const                                                         \
        {                                                                                   \
            return this->m_iHash;                                                           \
        }                                                                                   \
        K const & GetKey( void ) const                                                      \
        {                                                                                   \
            return this->m_pNode->m_Key;                                                    \
        }                                                                                   \
        bSNode const * GetNode( void ) const                                                \
        {                                                                                   \
            return this->m_pNode;                                                           \
        }                                                                                   \
        T const & operator * ( void ) const                                                 \
        {                                                                                   \
            return this->m_pNode->m_Element;                                                \
        }                                                                                   \
        T const * operator -> ( void ) const                                                \
        {                                                                                   \
            return &**this;                                                                 \
        }                                                                                   \
        bCConstIterator operator ++ ( GEInt )                                               \
        {                                                                                   \
            bCConstIterator _x = *this;                                                     \
            ++*this;                                                                        \
            return _x;                                                                      \
        }                                                                                   \
        bCConstIterator & operator ++ ( void )                                              \
        {                                                                                   \
            this->m_pNode = this->m_pNode->m_pNext;                                         \
            while( !this->m_pNode && (++this->m_iHash < this->m_parrNodes->GetCount()) )    \
                this->m_pNode = (*this->m_parrNodes)[ this->m_iHash ];                      \
            return *this;                                                                   \
        }                                                                                   \
        GEBool operator == ( bCConstIterator const & _x ) const                             \
        {                                                                                   \
            return                                                                          \
                (_x.m_parrNodes == this->m_parrNodes) &&                                    \
                (_x.m_iHash == this->m_iHash) &&                                            \
                (_x.m_pNode == this->m_pNode);                                              \
        }                                                                                   \
        GEBool operator != ( bCConstIterator const & _x ) const                             \
        {                                                                                   \
            return !(_x == *this);                                                          \
        }                                                                                   \
        bCConstIterator( bTPtrArray< bSNode * > const * _a, GEInt _h, bSNode const * _p ) : \
            m_parrNodes( const_cast< bTPtrArray< bSNode * > * >( _a ) ),                    \
            m_iHash( _h ),                                                                  \
            m_pNode( const_cast< bSNode * >( _p ) )                                         \
        {                                                                                   \
        }                                                                                   \
        bCConstIterator( bCIterator const & _x ) :                                          \
            m_parrNodes( _x.m_parrNodes ),                                                  \
            m_iHash( _x.m_iHash ),                                                          \
            m_pNode( _x.m_pNode )                                                           \
        {                                                                                   \
        }                                                                                   \
        bCConstIterator( void ) :                                                           \
            m_parrNodes( 0 ),                                                               \
            m_iHash( -1 ),                                                                  \
            m_pNode( 0 )                                                                    \
        {                                                                                   \
        }                                                                                   \
    };                                                                                      \
    class bCIterator :                                                                      \
        public bCConstIterator                                                              \
    {                                                                                       \
    public:                                                                                 \
        bSNode * GetNode( void ) const                                                      \
        {                                                                                   \
            return this->m_pNode;                                                           \
        }                                                                                   \
        T & operator * ( void ) const                                                       \
        {                                                                                   \
            return this->m_pNode->m_Element;                                                \
        }                                                                                   \
        T * operator -> ( void ) const                                                      \
        {                                                                                   \
            return &**this;                                                                 \
        }                                                                                   \
        bCIterator operator ++ ( GEInt )                                                    \
        {                                                                                   \
            bCIterator _x = *this;                                                          \
            ++*this;                                                                        \
            return _x;                                                                      \
        }                                                                                   \
        bCIterator & operator ++ ( void )                                                   \
        {                                                                                   \
            this->m_pNode = this->m_pNode->m_pNext;                                         \
            while( !this->m_pNode && (++this->m_iHash < this->m_parrNodes->GetCount()) )    \
                this->m_pNode = (*this->m_parrNodes)[ this->m_iHash ];                      \
            return *this;                                                                   \
        }                                                                                   \
        GEBool operator == ( bCIterator const & _x ) const                                  \
        {                                                                                   \
            return                                                                          \
                (_x.m_parrNodes == this->m_parrNodes) &&                                    \
                (_x.m_iHash == this->m_iHash) &&                                            \
                (_x.m_pNode == this->m_pNode);                                              \
        }                                                                                   \
        GEBool operator != ( bCIterator const & _x ) const                                  \
        {                                                                                   \
            return !(_x == *this);                                                          \
        }                                                                                   \
        bCIterator( bTPtrArray< bSNode* > * _a, GEInt _h, bSNode * _p ) :                   \
            bCConstIterator( _a, _h, _p )                                                   \
        {                                                                                   \
        }                                                                                   \
        bCIterator( void )                                                                  \
        {                                                                                   \
        }                                                                                   \
    };                                                                                      \
    typedef bCIterator bCForwardIterator;                                                   \
    typedef bCConstIterator bCConstForwardIterator;

#endif
