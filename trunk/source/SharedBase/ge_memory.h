#ifndef GE_MEMORY_H_INCLUDED
#define GE_MEMORY_H_INCLUDED

//
// malloc
//

inline GELPVoid GE_MALLOC( GEU32 a_u32Size )
{
    return bCMemoryAdmin::GetInstance().Malloc( a_u32Size, 0, 0, 0, 0 );
}

inline GELPVoid GE_REALLOC( GELPVoid a_pBlock, GEU32 a_u32Size )
{
    return bCMemoryAdmin::GetInstance().Realloc( a_pBlock, a_u32Size, 0, 0, 0, 0 );
}

inline void GE_FREE( GELPVoid a_pBlock )
{
    bCMemoryAdmin::GetInstance().Free( a_pBlock );
}

//
// new
//

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
inline void * GE_CCALL operator new( size_t, void * _p )
{
    return _p;
}
inline void GE_CCALL operator delete( void *, void * )
{
    return;
}
#endif

GE_C_LINKAGE GE_DLLIMPORT void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );

#define GE_NEW( T ) new( 0, 0, 0, 0 ) T

//
// delete
//

inline void operator delete( void * a_pObject, GELPCChar, GELPCChar, GELPCChar, GEInt )
{
    bCMemoryAdmin::GetInstance().DeleteObject( a_pObject );
}

template< typename TYPE >
inline void GE_DELETE( TYPE *& a_pObject )
{
    if( a_pObject )
    {
        a_pObject->~TYPE();
        bCMemoryAdmin::GetInstance().DeleteObject( a_pObject );
        a_pObject = 0;
    }
}

//
// new[]
//

template< typename TYPE >
inline void GE_ARR_NEW( TYPE *& a_pArray, GEInt a_iCount )
{
    a_pArray = bCMemoryAdmin::GetInstance().NewObjectArray(
        sizeof( TYPE ) * a_iCount, a_iCount, 0, 0, 0, 0 );
    for( TYPE * a_pIter = a_pArray; a_iCount--; ++a_pIter )
        new( a_pIter ) TYPE;
}

//
// delete[]
//

template< typename TYPE >
inline void GE_ARR_DELETE( TYPE *& a_pArray )
{
    if( a_pArray )
    {
        TYPE * pIter = a_pArray;
        TYPE * pLast = pIter + bCMemoryAdmin::GetInstance().GetArrayBlockCount( a_pArray );
        for( ; pIter < pLast; ++pIter )
            pIter->~TYPE();
        bCMemoryAdmin::GetInstance().DeleteObjectArray( a_pArray );
        a_pArray = 0;
    }
}

#endif
