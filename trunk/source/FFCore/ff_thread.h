#ifndef FF_THREAD_H_INCLUDED
#define FF_THREAD_H_INCLUDED

class FF_DLLIMPORT CFFThread
{
    public:    virtual FFBool InitInstance( void );
    public:    virtual FFInt  ExitInstance( void );
    public:    virtual FFInt  Run( void );
    protected: virtual void   OnInit( void );
    protected: virtual void   OnRun( void );
    protected: virtual void   OnExit( void );
    protected: virtual void   OnDelete( void );
    public:    virtual       ~CFFThread( void );
private:
    /* 0004 */ FFLPVoid m_hThread;
    /* 0008 */ FFU32    m_u32ThreadId;
    /* 000C */ FFBool   m_bAutoDelete;
                        FF_PADDING( 3 )
    // 0010 // sizeof(CFFThread)
protected:
    void Delete( void );
public:
    FFBool CreateThread( FFBool a_bCreateSuspended, FFU32 u_32StackSize );
    FFInt  GetThreadPriority( void ) const;
    FFBool IsThreadActive( void ) const;
    FFU32  ResumeThread( void );
    void   SetAutoDelete( FFBool a_bAutoDelete);
    FFBool SetThreadPriority( FFInt a_iPriority );
    FFU32  SuspendThread( void );
public:
    CFFThread & operator = ( CFFThread const & a_Source );
public:
    CFFThread( CFFThread const & a_Source );
    CFFThread( void );
};

#endif
