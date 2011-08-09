#ifndef GE_DEBUGOPTIONS_H_INCLUDED
#define GE_DEBUGOPTIONS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4820 )  // padding added after data member

//FIXME: Releated to eCConfigAdmin?
template< typename T >
struct eSDebugOption
{
    bCString m_strKey;
    T        m_Value;
};

#pragma warning( pop )

struct GE_DLLIMPORT eSDebugOptions
{
    eSDebugOption< bCString > LogFilterLevel;
    eSDebugOption< GEBool >   TestMode;
    eSDebugOption< GEBool >   MemoryCorruptionMonitor;
    eSDebugOption< bCString > ObserveMemory;
    eSDebugOption< GEBool >   DisplayEntities;
    eSDebugOption< GEBool >   IgnoreDrawCalls;
    struct eSSnapshots {
        eSDebugOption< bCString > Prefix;
        eSDebugOption< GEU32 >    MaxSnapshots;
    }                         Snapshots;
public:
    static eSDebugOptions & GE_STDCALL GetInstance( void );
public:
    eSDebugOptions( void );
   ~eSDebugOptions( void );
};
GE_ASSERT_SIZEOF( eSDebugOptions, 0x0040 );

#endif
