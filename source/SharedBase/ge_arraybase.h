#ifndef GE_ARRAYBASE_H_INCLUDED
#define GE_ARRAYBASE_H_INCLUDED

#define GE_DECLARE_ARRAY_ITERATORS()                                                   \
public:                                                                                \
    class bCIterator;                                                                  \
    class bCConstIterator                                                              \
    {                                                                                  \
    protected:                                                                         \
        GEInt m_iIndex;                                                                \
        T *   m_pArray;                                                                \
    public:                                                                            \
        T const & operator * ( void ) const                                            \
        {                                                                              \
            return this->m_pArray[ this->m_iIndex ];                                   \
        }                                                                              \
        T const & operator [] ( GEInt _n ) const                                       \
        {                                                                              \
            return this->m_pArray[ this->m_iIndex + _n ];                              \
        }                                                                              \
        bCConstIterator operator ++ ( GEInt )                                          \
        {                                                                              \
            bCConstIterator _x = *this;                                                \
            ++*this;                                                                   \
            return _x;                                                                 \
        }                                                                              \
        bCConstIterator & operator ++ ( void )                                         \
        {                                                                              \
            this->m_iIndex++;                                                          \
            return *this;                                                              \
        }                                                                              \
        bCConstIterator operator -- ( GEInt )                                          \
        {                                                                              \
            bCConstIterator _x = *this;                                                \
            --*this;                                                                   \
            return _x;                                                                 \
        }                                                                              \
        bCConstIterator & operator -- ( void )                                         \
        {                                                                              \
            this->m_iIndex--;                                                          \
            return *this;                                                              \
        }                                                                              \
        bCConstIterator & operator += ( GEInt _n )                                     \
        {                                                                              \
            this->m_iIndex += _n;                                                      \
            return *this;                                                              \
        }                                                                              \
        bCConstIterator & operator -= ( GEInt _n )                                     \
        {                                                                              \
            this->m_iIndex -= _n;                                                      \
            return *this;                                                              \
        }                                                                              \
        bCConstIterator operator + ( GEInt _n ) const                                  \
        {                                                                              \
            bCConstIterator _x = *this;                                                \
            return _x += _n;                                                           \
        }                                                                              \
        bCConstIterator operator - ( GEInt _n ) const                                  \
        {                                                                              \
            bCConstIterator _x = *this;                                                \
            return _x -= _n;                                                           \
        }                                                                              \
        bCConstIterator operator - ( bCConstIterator const & _x ) const                \
        {                                                                              \
            return (this->m_pArray + this->m_iIndex) - (_x.m_pArray + _x.m_iIndex);    \
        }                                                                              \
        GEBool operator == ( bCConstIterator const & _x ) const                        \
        {                                                                              \
            return (this->m_iIndex == _x.m_iIndex) && (this->m_pArray == _x.m_pArray); \
        }                                                                              \
        GEBool operator != ( bCConstIterator const & _x ) const                        \
        {                                                                              \
            return !(*this == _x);                                                     \
        }                                                                              \
        GEBool operator < ( bCConstIterator const & _x ) const                         \
        {                                                                              \
            return (this->m_pArray + this->m_iIndex) < (_x.m_pArray + _x.m_iIndex);    \
        }                                                                              \
        GEBool operator > ( bCConstIterator const & _x ) const                         \
        {                                                                              \
            return _x < *this;                                                         \
        }                                                                              \
        GEBool operator <= ( bCConstIterator const & _x ) const                        \
        {                                                                              \
            return !(_x < *this);                                                      \
        }                                                                              \
        GEBool operator >= ( bCConstIterator const & _x ) const                        \
        {                                                                              \
            return !(*this < _x);                                                      \
        }                                                                              \
        bCConstIterator( bCIterator const & _x ) :                                     \
            m_iIndex( _x.m_iIndex ),                                                   \
            m_pArray( _x.m_pArray )                                                    \
        {                                                                              \
        }                                                                              \
        bCConstIterator( T const * _p, GEInt _i ) :                                    \
            m_iIndex( _i ),                                                            \
            m_pArray( const_cast< T * >( _p ) )                                        \
        {                                                                              \
        }                                                                              \
        bCConstIterator( void ) :                                                      \
            m_iIndex( 0 ),                                                             \
            m_pArray( 0 )                                                              \
        {                                                                              \
        }                                                                              \
    };                                                                                 \
    class bCIterator :                                                                 \
        public bCConstIterator                                                         \
    {                                                                                  \
    public:                                                                            \
        T & operator * ( void ) const                                                  \
        {                                                                              \
            return this->m_pArray[ this->m_iIndex ];                                   \
        }                                                                              \
        T & operator [] ( GEInt _n ) const                                             \
        {                                                                              \
            return this->m_pArray[ this->m_iIndex + _n ];                              \
        }                                                                              \
        bCIterator operator ++ ( GEInt )                                               \
        {                                                                              \
            bCIterator _x = *this;                                                     \
            ++*this;                                                                   \
            return _x;                                                                 \
        }                                                                              \
        bCIterator & operator ++ ( void )                                              \
        {                                                                              \
            this->m_iIndex++;                                                          \
            return *this;                                                              \
        }                                                                              \
        bCIterator operator -- ( GEInt )                                               \
        {                                                                              \
            bCIterator _x = *this;                                                     \
            --*this;                                                                   \
            return _x;                                                                 \
        }                                                                              \
        bCIterator & operator -- ( void )                                              \
        {                                                                              \
            this->m_iIndex--;                                                          \
            return *this;                                                              \
        }                                                                              \
        bCIterator & operator += ( GEInt _n )                                          \
        {                                                                              \
            this->m_iIndex += _n;                                                      \
            return *this;                                                              \
        }                                                                              \
        bCIterator & operator -= ( GEInt _n )                                          \
        {                                                                              \
            this->m_iIndex -= _n;                                                      \
            return *this;                                                              \
        }                                                                              \
        bCIterator operator + ( GEInt _n ) const                                       \
        {                                                                              \
            bCIterator _x = *this;                                                     \
            return _x += _n;                                                           \
        }                                                                              \
        bCIterator operator - ( GEInt _n ) const                                       \
        {                                                                              \
            bCIterator _x = *this;                                                     \
            return _x -= _n;                                                           \
        }                                                                              \
        bCIterator operator - ( bCIterator const & _x ) const                          \
        {                                                                              \
            return (this->m_pArray + this->m_iIndex) - (_x.m_pArray + _x.m_iIndex);    \
        }                                                                              \
        GEBool operator == ( bCIterator const & _x ) const                             \
        {                                                                              \
            return (this->m_iIndex == _x.m_iIndex) && (this->m_pArray == _x.m_pArray); \
        }                                                                              \
        GEBool operator != ( bCIterator const & _x ) const                             \
        {                                                                              \
            return !(*this == _x);                                                     \
        }                                                                              \
        GEBool operator < ( bCIterator const & _x ) const                              \
        {                                                                              \
            return (this->m_pArray + this->m_iIndex) < (_x.m_pArray + _x.m_iIndex);    \
        }                                                                              \
        GEBool operator > ( bCIterator const & _x ) const                              \
        {                                                                              \
            return _x < *this;                                                         \
        }                                                                              \
        GEBool operator <= ( bCIterator const & _x ) const                             \
        {                                                                              \
            return !(_x < *this);                                                      \
        }                                                                              \
        GEBool operator >= ( bCIterator const & _x ) const                             \
        {                                                                              \
            return !(*this < _x);                                                      \
        }                                                                              \
        bCIterator( T * _p, GEInt _i ) :                                               \
            bCConstIterator( _p, _i )                                                  \
        {                                                                              \
        }                                                                              \
        bCIterator( void )                                                             \
        {                                                                              \
        }                                                                              \
    };                                                                                 \
    typedef bCIterator bCRandomAccessIterator;                                         \
    typedef bCConstIterator bCConstRandomAccessIterator;

template< typename T >
class bTArrayBase
{
    GE_DECLARE_ARRAY_ITERATORS()
public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };
protected:
    T *    m_pArray;
    GEU32  m_u32Count;
    GEU32  m_u32Capacity;
protected:
    static void GE_STDCALL Copy( T * _d, T const * _s, GEInt _n );
    static void GE_STDCALL Delete( T * _e, GEInt _n );
    static void GE_STDCALL Move( T * _d, T const * _s, GEInt _n );
    static void GE_STDCALL New( T * _e, GEInt _n );
protected:
    void Init( void );
private:
    bTArrayBase< T > & operator = ( bTArrayBase< T > const & );  // not defined
protected:
             bTArrayBase( bTArrayBase< T > const & _s );         // not defined
    explicit bTArrayBase( GEInt _n );                            // not defined
             bTArrayBase( void );
            ~bTArrayBase( void );
public:
    T *             AccessArray( void );
    T &             AccessAt( GEInt _i );
    bCConstIterator Begin( void ) const;
    bCIterator      Begin( void );
    T const *       GetArray( void ) const;
    T const &       GetAt( GEInt _i ) const;
    void            GetAt( GEInt _i, T & _e ) const;
    GEInt           GetCapacity( void ) const;
    GEInt           GetCount( void ) const;
    bCConstIterator End( void ) const;
    bCIterator      End( void );
    GEInt           IndexOf( T const & _e ) const;
    GEBool          IsEmpty( void ) const;
public:
    T &       operator [] ( GEInt _i );
    T const & operator [] ( GEInt _i ) const;
};

#include "ge_arraybase.inl"

#endif
