#ifndef GE_THREADEX_H_INCLUDED
#define GE_THREADEX_H_INCLUDED

class GE_DLLIMPORT bCThreadEx :
    public bCThread
{
public:  virtual     ~bCThreadEx( void );
private: virtual void Execute( void ) = 0;  //FIXME: bCThreadEx::Execute prototype.
protected:
    bCCriticalSection m_CriticalSection;
    GEBool            m_bStarted;
                      GE_PADDING( 3 )
protected:
    static GEBool ms_bEnableThreads;
protected:
    static GEU32 GE_STDCALL ThreadFunc( GELPVoid );
public:
    static void GE_STDCALL EnableThreads( GEBool );
public:
    GEBool EndThread( void );
    void   SleepThread( GEU32 );
    GEBool StartThread( void );
    void   WaitIfThreadFinished( void );
public:
    bCThreadEx( void );
};

#endif
