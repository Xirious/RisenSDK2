#ifndef GE_MEMPOOL_H_INCLUDED
#define GE_MEMPOOL_H_INCLUDED

class GE_DLLIMPORT bCMemPool
{
public:
    GELPVoid Allocate( GEU32 );
    void     Free( GELPVoid );
    GELPVoid Reallocate( GELPVoid, GEU32 );
public:
    bCMemPool & operator = ( bCMemPool const & );
public:
    bCMemPool( void );
   ~bCMemPool( void );
};

#endif
