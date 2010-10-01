#ifndef GE_CLASSNAMEBASE_H_INCLUDED
#define GE_CLASSNAMEBASE_H_INCLUDED

class GE_DLLIMPORT bCClassNameBase
{
public:
    static bCString GE_STDCALL UnMangle( GELPCChar );
public:
    bCClassNameBase & operator = ( bCClassNameBase const & );
};

#endif
