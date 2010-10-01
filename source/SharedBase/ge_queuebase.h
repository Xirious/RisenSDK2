#ifndef GE_QUEUEBASE_H_INCLUDED
#define GE_QUEUEBASE_H_INCLUDED

template< typename T >
class bTQueueBase
{
public:
    enum bEIndex
    {
        bEIndex_Invalid = 0xFFFFFFFFL
    };
private:
    bTQueueBase< T > & operator = ( bTQueueBase< T > const & _s );  // not defined
protected:
    T *    m_pArray;
    GEU32  m_u32Capacity;
    GEU32  m_u32Head;
    GEU32  m_u32Tail;
    GEBool m_bFull;
           GE_PADDING( 3 )
protected:
    static void GE_STDCALL Copy( T * _d, T const * _s, GEInt _n );
    static void GE_STDCALL Delete( T * _e, GEInt _n );
    static void GE_STDCALL Move( T * _d, T const * _s, GEInt _n );
    static void GE_STDCALL New( T * _e, GEInt _n );
protected:
    GEInt IndexToOffset( GEInt _i ) const;
    void  Init( void );
    GEInt OffsetToIndex( GEInt _o ) const;
public:
    T *       AccessArray( void );
    T &       AccessAt( GEInt _i );
    T const * GetArray( void ) const;
    T const & GetAt( GEInt _i ) const;
    void      GetAt( GEInt _i , T & _e ) const;
    GEInt     GetCapacity( void ) const;
    GEInt     GetCount( void ) const;
    GEInt     IndexOf( T const & _e ) const;
    GEBool    IsEmpty( void ) const;
    GEBool    IsFull( void ) const;
public:
    T &       operator [] ( GEInt _i );
    T const & operator [] ( GEInt _i ) const;
protected:
             bTQueueBase( bTQueueBase< T > const & _s );  // not defined
    explicit bTQueueBase( GEInt _c );                     // not defined
             bTQueueBase( void );
            ~bTQueueBase( void );
};

#include "ge_queuebase.inl"

#endif
