#ifndef FX_IOSTATISTICS_H_INCLUDED
#define FX_IOSTATISTICS_H_INCLUDED

class FF_DLLIMPORT CFXIOStatistics
{
public: virtual ~CFXIOStatistics( void );  
protected:
    // sizeof(CFXIOStatistics) 0004
public:
    static FFBool FF_STDCALL WriteStatistics( bCString const &, bCString const & );
public:
    CFXIOStatistics & operator = ( CFXIOStatistics const & );
public:
    CFXIOStatistics( CFXIOStatistics const & );
    CFXIOStatistics( void );
};

#endif
