#ifndef GE_DOCOBJECTMAP_H_INCLUDED
#define GE_DOCOBJECTMAP_H_INCLUDED

template< typename T >
class eTDocObjectMap :
    public bTValMap< bCString, T * >
{
public: virtual ~eTDocObjectMap( void );
};

#endif
