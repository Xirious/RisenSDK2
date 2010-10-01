#ifndef GE_THREAD_H_INCLUDED
#define GE_THREAD_H_INCLUDED

typedef GEU32 (GE_STDCALL * bFThreadStartRoutine)( GELPVoid );

class GE_DLLIMPORT bCThread
{
public:
    enum bEThreadPriority
    {
        bEThreadPriority_Idle         = -15,
        bEThreadPriority_Lowest       = -2,
        bEThreadPriority_BelowNormal  = -1,
        bEThreadPriority_Normal       = 0,
        bEThreadPriority_AboveNormal  = 1,
        bEThreadPriority_Highest      = 2,
        bEThreadPriority_TimeCritical = 15,
        bEThreadPriority_ForceDWORD = GE_FORCE_DWORD
    };
    struct GE_DLLIMPORT bSThreadContext
    {
        GELPVoid m_pParameter;
        GELPVoid m_pData;
    public:
        bSThreadContext & operator = ( bSThreadContext const & );
    public:
        bSThreadContext( void );
    };
public: virtual bCThread::~bCThread( void );
private:
    GELPVoid m_pHandle;
protected:
    bSThreadContext m_Context;
public:
    GEBool   Create( bSThreadContext const &, bFThreadStartRoutine );
    void     Destroy( void );
    GELPVoid GetHandle( void ) const;
    GEBool   IsValid( void ) const;
    void     SetPriority( bEThreadPriority );
public:
    bCThread & operator = ( bCThread const & );
public:
    bCThread( bCThread const & );
    bCThread( void );
};

#endif
