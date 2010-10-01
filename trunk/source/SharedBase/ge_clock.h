#ifndef GE_CLOCK_H_INCLUDED
#define GE_CLOCK_H_INCLUDED

struct bSClockAdjustment
{
    GEFloat m_fUnitsPerSecond;
    GEU32   m_u32SecondsPerDay;
    GEU32   m_u32DaysPerYear;
};

struct bSTimeAndDate
{
    GEU32   m_u32Year;
    GEU32   m_u32Days;
    GEFloat m_fSeconds;
};

class GE_DLLIMPORT bCClock
{
private:
    bSClockAdjustment m_ClockAdjustment;
    bSTimeAndDate     m_TimeAndDate;
    GEU32             m_u32LastTimeStamp;
    GEFloat           m_fElapsedSeconds;
    GEBool            m_bIsPaused;
                      GE_PADDING( 3 )
public:
    void   Adjust( bSClockAdjustment const & );
    void   GetTimeAndDate( bSTimeAndDate & );
    GEBool IsPaused( void ) const;
    void   Set( bSTimeAndDate const & );
    void   SetPause( GEBool );
public:
    bCClock & operator = ( bCClock const & );
public:
    bCClock( bCClock const & );
    bCClock( void );
   ~bCClock( void );
};

#endif
