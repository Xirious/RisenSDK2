#ifndef GE_ARRAYMAP_H_INCLUDED
#define GE_ARRAYMAP_H_INCLUDED

template< typename K, typename T >
struct bSArrayMapPair
{
    K m_Key;
    T m_Value;
};

#pragma warning( push )
#pragma warning( disable : 4626 )  // assignment operator could not be generated because a base class assignment operator is inaccessible

//FIXME: bTArrayMap should support write access
// (like bTObjArray), sorting, and array access.
template< typename K, typename T >
class bTArrayMap :
    public bTArrayBase< bSArrayMapPair< K, T > >
{
protected:
    GEBool m_bUnsorted;
           GE_PADDING( 3 )
};

#pragma warning( pop )

#include "ge_arraymap.inl"

#endif
