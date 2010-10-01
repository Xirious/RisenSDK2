#ifndef GE_CLASSNAME_H_INCLUDED
#define GE_CLASSNAME_H_INCLUDED

template< typename T >
class bTClassName :
    public bCClassNameBase
{
public:
    static bCString const & GetName( void );
};

#include "ge_classname.inl"

#endif
