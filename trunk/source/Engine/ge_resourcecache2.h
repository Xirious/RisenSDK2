#ifndef GE_RESOURCECACHE2_H_INCLUDED
#define GE_RESOURCECACHE2_H_INCLUDED

struct eSResourceCache
{
    //FIXME: eSResourceCache members.
};

class GE_DLLIMPORT eCResourceCache2
{
private:
    struct SCompiledFile
    {
        //FIXME: eCResourceCache2::SCompiledFile members.
    };
    struct SFetchedResource
    {
        //FIXME: eCResourceCache2::SFetchedResource members.
    };
    struct SStats
    {
        GEUInt m_uInUseResources;
        GEUInt m_uLoadedResources;
        GEUInt m_uUnloadedResources;
        GEUInt m_uPendingResources;
        GEUInt m_uFailedResources;
        GEUInt m_uInvalidResources;
        GEUInt m_uTotalResources;
        GEUInt m_uInUseData;
        GEUInt m_uLoadedData;
        GEUInt m_uPendigData;
        GEUInt m_uTotalData;
        GEUInt m_uTotalOverhead;
        GEUInt m_uMinIndex;
        GEUInt m_uMaxIndex;
        GEUInt m_uMinResources;
        GEUInt m_uMaxResources;
    };
    GE_ASSERT_SIZEOF( SStats, 0x0040 )
protected:
    char __FIXME[ 0x0254 ];
private:
    static void GE_STDCALL AsyncLoadHandler( IFFFileStream2 *, GELPVoid, bCString const & );
private:
    void          CacheResource( eCResource2 * );
    void          CollectStatistics( eCResourceCache2::SStats & ) const;
    eCStatistic * CreateStatistics( void ) const;
    void          Dump( eCArchiveFile & );
    void          Dump( GEInt );
    void          DumpCache( GEInt );
    void          DumpHash( GEInt );
    void          DumpQueue( GEInt );
    void          DumpStates( GEInt );
    eCResource2 * FindResourceA( bCString const & ) const;
    GEUInt        FlushBytes( GEUInt );
    GEUInt        FlushResource( eCResource2 * );
    eCResource2 * GetResource( bCString const &, eCResourceCache2 * ) const;
    GEBool        ImportResource( eCResource2 * );
    void          InitResource( IFFFileSystemNode2 * );
    GEBool        IsHeaderDirty( void ) const;
    void          LoadData( eCResource2 *, CFXVirtualFile & );
    void          LoadData( eCResource2 *, bCString const & );
    void          LoadQueuedData( void );
    void          LoadResource( eCResource2 * );
    void          LoadResources( eCResourceCache2::SCompiledFile & );
    void          LoadResources( void );
    void          OnAsyncLoad( eCResource2 *, IFFFileStream2 *, bCString const & );
    void          QueueData( eCResource2 *, eEResourceLoadMode );
    void          RegisterResource( eCResource2 * );
    void          SaveResources( eCResourceCache2::SCompiledFile &, bTValArray< eCResourceCache2::SFetchedResource > & );
    void          SaveResources( GEBool );
    eCResource2 * SpawnResource( bCString const & );
    eCResource2 * SpawnResource( void );
    void          UnregisterResource( eCResource2 * );
    void          UpdatePrefetchData( void );
    void          VerifyResources( void );
public:
    void            Create( eSResourceCache const & );
    eCResource2 *   CreateResource( void );
    void            Destroy( void );
    void            Flush( void );
    GEInt           GetHardLimit( void ) const;
    GEInt           GetSoftLimit( void ) const;
    GEBool          IsCompiledExt( bCString const & ) const;
    GEBool          IsKnownExt( bCString const & ) const;
    GEBool          IsRawExt( bCString const & ) const;
    eEResourceState PrefetchData( eCResource2 *, GEInt, eCResource2::eFPrefetchCallback, eEResourceLoadMode );
    void            Process( void );
    void            ReleaseResource( eCResource2 * );
    void            ReloadResource( eCResource2 * );
    eEResourceState RequestData( eCResource2 *, eEResourceLoadMode );
    eCResource2 *   RequestResource( bCString const & );
    void            SetLimits( GEUInt, GEUInt );
public:
    eCResourceCache2( void );
   ~eCResourceCache2( void );
};
GE_ASSERT_SIZEOF( eCResourceCache2, 0x0254 )

#endif
