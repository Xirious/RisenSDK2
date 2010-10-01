#ifndef GE_MEMORYADMIN_H_INCLUDED
#define GE_MEMORYADMIN_H_INCLUDED

enum bECheckPtr
{
    bECheckPtr_Valid,
    bECheckPtr_Invalid,
    bECheckPtr_Corrupted,
    bECheckPtr_Disabled,
    bECheckPtr_Null,
    bECheckPtr_ForceDWORD = GE_FORCE_DWORD
};

enum bEMemoryAllocationType
{
    bEMemoryAllocationType_Malloc,
    bEMemoryAllocationType_Calloc,
    bEMemoryAllocationType_New,
    bEMemoryAllocationType_NewArray,
    bEMemoryAllocationType_Realloc,
    bEMemoryAllocationType_Delete,
    bEMemoryAllocationType_DeleteArray,
    bEMemoryAllocationType_Free,
    bEMemoryAllocationType_Max,
    bEMemoryAllocationType_ForceDWORD = GE_FORCE_DWORD
};

//FIXME: bSAllocationSummery should be verified at runtime.
struct bSAllocationSummery
{
    GEU32                 m_u32PtrSizeCurrent;
    GEU32                 m_u32HeapSizeCurrent;
    GEU32                 m_u32PtrSizePeak;
    GEU32                 m_u32Unknown1;
    GEU32                 m_u32Unknown2;
    GEU32                 m_u32Unknown3;
    GEChar                m_carrFileName[ 255 ];
    GEChar                m_carrObjectName[ 255 ];
    GEChar                m_carrContructor[ 255 ];
                          GE_PADDING( 3 )
    GEU32                 m_u32SourceLine;
    bEMemorySubSystem     m_enuSubSystem;
    GEU32                 m_u32SmallBlockCount;
    GEU32                 m_u32MediumBlockCount;
    GEU32                 m_u32LargeBlockCount;
    bSAllocationSummery * m_pNext;
};

//FIXME: bSAllocationItem should be verified at runtime.
struct bSAllocationItem
{
    GEU32                  m_u32HeapSize;
    GEU32                  m_u32PtrSize;
    GELPVoid               m_pHeapAddress;
    GELPVoid               m_pPtrAddress;
    bEMemoryAllocationType m_enuAllocType;
    GEU32                  m_u32AllocID;
    bSAllocationSummery *  m_pSummery;
    bSAllocationItem *     m_pNext;
    bSAllocationItem *     m_pPrev;
};

//FIXME: bSMemoryStatistics should be verified at runtime.
struct bSMemoryStatistics
{
    GEU32 m_u32CurrentMemory;
    GEU32 m_u32CurrentHeap;
    GEU32 m_u32CurrentElements;
    GEU32 m_u32PeakMemory;
    GEU32 m_u32PeakHeap;
    GEU32 m_u32PeakElements;
    GEU32 m_u32AccumulatedMemory;
    GEU32 m_u32AccumulatedHeap;
    GEU32 m_u32AccumulatedElements;
    GEU32 m_u32TotalMemory;
    GEU32 m_u32TotalElements;
};

typedef GEBool (GE_STDCALL * GEFMemoryCallback)( GELPCChar, bSAllocationItem const * );

class GE_DLLIMPORT bCMemoryAdmin
{
private:
    static GEBool ms_bInitialized;
private:
    GEU32                  m_u32AllocationCount;
    GEU32                  m_u32MemoryPoolDescCount;
    bSAllocationItem *     m_pMemoryPoolDesc;
    bSAllocationItem **    m_ppMemoryPoolDescList;
    bSMemoryStatistics     m_Statistics[ bEMemorySubSystem_Count ];
    GEBool                 m_bWipeAll;
    GEBool                 m_bAllocationReport;
    GEBool                 m_bHeapProfilerActive;
    GEBool                 m_bMemoryLeakReport;
    bCMemPool *            m_pMemPool;
    bCCriticalSection      m_CriticalSection;
    bCMemorySubSystemStack m_MemorySubSystemStack;
protected:
    GELPVoid AllocatePure( GELPCChar const, GEInt, GELPCChar const, GELPCChar, bEMemoryAllocationType, GEU32 );
    GEU32    CalculateHeapSize( GEU32 ) const;
    GELPVoid CalculatePtrAddress( GELPCVoid ) const;
    GEU32    CalculatePtrSize( GEU32 ) const;
    void     Create( void );
    GEBool   CreateNewMemoryPoolDescriptor( void );
    void     FreePure( GELPVoid );
    void     Invalidate( void );
    GELPVoid ReallocPure( GELPCChar, GEInt, GELPCChar, GELPCChar, bEMemoryAllocationType, GEU32, GELPVoid );
    void     WipeWithPattern( bSAllocationItem const &, GEU32, GEU32 );
public:
    static bCMemoryAdmin & GE_STDCALL GetInstance( void );
    static GEBool          GE_STDCALL IsMemoryAdminInitialized( void );
public:
    bECheckPtr               CheckMemoryBlock( GELPVoid ) const;
    GEBool                   CollectItemSummary( GEFMemoryCallback ) const;
    GEBool                   CollectItemSummaryDiff( GEFMemoryCallback ) const;
    void                     DeleteObject( GELPVoid );
    void                     DeleteObjectArray( GELPVoid );
    void                     Destroy( void );
    void                     DumpAllocationItem( GEFMemoryCallback, bSAllocationItem const & ) const;
    void                     DumpGrowSize( void );
    void                     DumpHeapStatistics( GEFMemoryCallback ) const;
    void                     DumpLeakReport( GEFMemoryCallback );
    void                     DumpStatisticsByItem( GEFMemoryCallback ) const;
    void                     DumpStatisticsBySubSystem( GEFMemoryCallback ) const;
    void                     EnableAllocationReport( GEBool );
    void                     EnableMemoryLeakReport( GEBool );
    bSAllocationItem *       FindAllocationItem( GELPCVoid ) const;
    void                     Free( GELPVoid );
    bSAllocationSummery *    GetAllocationSummery( GEU32 ) const;
    GEU32                    GetAllocationSummeryHashSize( void ) const;
    GEInt                    GetArrayBlockCount( GELPVoid ) const;
    bSMemoryStatistics       GetMemoryStatistics( bEMemorySubSystem ) const;
    bCMemorySubSystemStack & GetMemorySubSystemStack( void );
    GEInt                    GetSummeryFootprintGrowTopTen( bSAllocationSummery *, GEInt );
    GEInt                    GetSummeryFootprintTopTen( bSAllocationSummery *, GEInt );
    GEInt                    GetSummeryFreeListAllocTopTen( bSAllocationSummery *, GEInt, GEInt & );
    GEInt                    GetSummeryHeapAllocTopTen( bSAllocationSummery *, GEInt, GEInt & );
    GEInt                    GetSummeryItemCountGrowTopTen( bSAllocationSummery *, GEInt );
    GEInt                    GetSummeryItemCountTopTen( bSAllocationSummery *, GEInt );
    GEInt                    GetSummeryMaxFootprintTopTen( bSAllocationSummery *, GEInt );
    GEInt                    GetSummeryObservedTopTen( bSAllocationSummery *, GEInt, GELPCChar );
    GEInt                    GetSummerySmallAllocTopTen( bSAllocationSummery *, GEInt, GEInt & );
    GEU64                    GetTotalNumAllocatedBytes( void );
    GEBool                   IsPoolValid( void ) const;
    void                     MakeSummeryItemGrowSnapshot( void );
    GELPVoid                 Malloc( GEU32, GELPCChar, GELPCChar, GELPCChar, GEInt );
    GELPVoid                 NewObject( GEU32, GELPCChar, GELPCChar, GELPCChar, GEInt );
    GELPVoid                 NewObjectArray( GEU32, GEInt, GELPCChar, GELPCChar, GELPCChar, GEInt );
    GELPVoid                 Realloc( GELPVoid, GEU32, GELPCChar, GELPCChar, GELPCChar, GEInt );
    void                     ResetGrowSizeAndCount( bEMemorySubSystem );
    GEBool                   ValidateAllAllocationItems( GEFMemoryCallback ) const;
    GEBool                   ValidateAllocationItem( GEFMemoryCallback, bSAllocationItem const & ) const;
public:
    bCMemoryAdmin( GEBool );
    bCMemoryAdmin( void );
   ~bCMemoryAdmin( void );
};

#endif
