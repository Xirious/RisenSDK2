#ifndef FF_THREAD_H_INCLUDED
#define FF_THREAD_H_INCLUDED

class FF_DLLIMPORT CFFThread
{
/* [0000].0000 */ public:    virtual FFBool InitInstance( void );
/* [0000].0004 */ public:    virtual FFInt  ExitInstance( void );
/* [0000].0008 */ public:    virtual FFInt  Run( void );
/* [0000].000C */ protected: virtual void   OnInit( void );
/* [0000].0010 */ protected: virtual void   OnRun( void );
/* [0000].0014 */ protected: virtual void   OnExit( void );
/* [0000].0018 */ protected: virtual void   OnDelete( void );
/* [0000].001C */ public:    virtual       ~CFFThread( void );
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
