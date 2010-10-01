#ifndef FF_UNKNOWN_H_INCLUDED
#define FF_UNKNOWN_H_INCLUDED

FF_DECLARE_INTERFACE( IFFUnknown, "69F9C657-E25E-458F-B995-294B2D9A5529" )
{
public:
    /* [0000].0000 */ virtual FFU32 AddRef( void ) = 0;
    /* [0000].0004 */ virtual FFU32 Release( void ) = 0;
    /* [0000].0008 */ virtual FFU32 QueryInterface( FFGUID const & a_guidID, FFLPVoid * a_ppObject ) = 0;
    template< typename T >
    T * QueryInterface( void );
};

#include "ff_unknown.inl"

#endif
