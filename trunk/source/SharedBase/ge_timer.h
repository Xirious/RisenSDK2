#ifndef GE_TIMER_H_INCLUDED
#define GE_TIMER_H_INCLUDED

class GE_DLLIMPORT bCTimer
{
private:
    GEFloat m_fUnitsPerMillisecond;
    GEU32   m_u32LastTimeStamp;
    GEFloat m_fLastTime;
    GEFloat m_fElapsedMilliseconds;
    GEBool  m_bIsPaused;
            GE_PADDING( 3 )
public:
    static GEU32 GE_STDCALL GetTimeStamp( void );
    static GEU64 GE_STDCALL QueryPerformanceCounter( void );
    static GEU64 GE_STDCALL QueryPerformanceFrequency( void );
public:
    void Adjust( GEFloat );
    void GetLastTime( GEFloat & ) const;
    void GetTime( GEFloat & );
    void GetTimeDifference( GEFloat & ) const;
    void Pause( void );
    void Reset( void );
    void Resume( void );
    void Set( GEFloat );
public:
    bCTimer & operator = ( bCTimer const & );
public:
    bCTimer( bCTimer const & );
    bCTimer( void );
   ~bCTimer( void );
};

#endif
