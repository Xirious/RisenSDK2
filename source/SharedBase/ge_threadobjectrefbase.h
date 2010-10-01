#ifndef GE_THREADOBJECTREFBASE_H_INCLUDED
#define GE_THREADOBJECTREFBASE_H_INCLUDED

class GE_DLLIMPORT bCThreadObjectRefBase :
    public bCObjectRefBase,
    public bCThreadEx
{
public: virtual ~bCThreadObjectRefBase( void );

public:
    bCCriticalSection & GetCriticalSection( void );
    void                ReleaseOwnership( void );
    GEBool              TryToGetOwnership( void );
public:
    bCThreadObjectRefBase( void );
};

#endif