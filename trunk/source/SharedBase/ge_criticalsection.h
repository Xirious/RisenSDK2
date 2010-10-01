#ifndef GE_CRITICALSECTION_H_INCLUDED
#define GE_CRITICALSECTION_H_INCLUDED

//FIXME: Seems like Piranha Bytes used a Windows SDK where struct _RTL_CRITICAL_SECTION is packed at byte level.
#pragma pack( push, 1 )

class GE_DLLIMPORT bCCriticalSection
{
private:
    bSCriticalSection m_CriticalSection;
public:
    void   Acquire( void );
    GEU32  GetLockCount( void ) const;
    void   Release( void );
    void   SetSpinCount( GEU32 );
    GEBool TryAcquire( void );
public:
    bCCriticalSection( void );
   ~bCCriticalSection( void );
};

#pragma pack( pop )

#endif
