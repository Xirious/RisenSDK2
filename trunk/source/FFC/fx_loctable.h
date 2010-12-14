#ifndef FX_LOCTABLE_H_INCLUDED
#define FX_LOCTABLE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class FF_DLLIMPORT CFXLocTable :
    public CFXTableMap
{
protected: using CFXTableMap::PreTableModify;  // [0000].0000
public:
    static CFXLocTable & FF_STDCALL GetInstance( void );
private:
    CFXLocTable & operator = ( CFXLocTable const & );
private:
    CFXLocTable( CFXLocTable const & );
    CFXLocTable( void );
public:
   ~CFXLocTable( void );
};
GE_ASSERT_SIZEOF( CFXLocTable, 0x0020 )

#pragma warning( pop )

#endif
