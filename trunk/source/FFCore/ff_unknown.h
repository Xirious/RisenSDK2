#ifndef FF_UNKNOWN_H_INCLUDED
#define FF_UNKNOWN_H_INCLUDED

FF_DECLARE_INTERFACE( IFFUnknown, "69F9C657-E25E-458F-B995-294B2D9A5529" )
{
public: virtual FFU32 AddRef( void )                                                   = 0;  
public: virtual FFU32 Release( void )                                                  = 0;  
public: virtual FFU32 QueryInterface( FFGUID const & a_guidID, FFLPVoid * a_ppObject ) = 0;  
public:
    template< typename T >
    T * QueryInterface( void );
};
GE_ASSERT_SIZEOF( IFFUnknown, 0x0004 )

#include "ff_unknown.inl"

#endif
