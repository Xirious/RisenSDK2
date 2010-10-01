#ifndef GE_VALQUEUE_H_INCLUDED
#define GE_VALQUEUE_H_INCLUDED

template< typename T >
class bTValQueue :
    public bTQueueBase< T >
{
protected:
    void SetAtOffset( GEInt _o, T const & _e );
public:
    void   Clear( void );
    void   CopyFrom( bTValQueue< T > const & _s );
    void   CopyTo( bTValQueue< T > & _d ) const;
    GEBool Push( T const & _e );
    GEBool Pop( T & _e );
    void   Reserve( GEInt _n );
public:
    bTValQueue< T > & operator = ( bTValQueue< T > const & _s );
public:
             bTValQueue( bTValQueue< T > const & _s );
    explicit bTValQueue( GEInt _c );
             bTValQueue( void );
            ~bTValQueue( void );
};

#include "ge_valqueue.inl"

#endif
