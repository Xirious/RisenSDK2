#ifndef GE_RESOURCE2_H_INCLUDED
#define GE_RESOURCE2_H_INCLUDED

enum eEResourceFileState
{
    eEResourceFileState_Ok                   = 0x00000000,
    eEResourceFileState_RawFileMissing       = 0x00000001,
    eEResourceFileState_CompiledFileMissing  = 0x00000002,
    eEResourceFileState_CompiledFileInvalid  = 0x00000003,
    eEResourceFileState_CompiledFileOutdated = 0x00000004,
    eEResourceFileState_VersionMismatch      = 0x00000005,
    eEResourceFileState_RevisionMismatch     = 0x00000006,
    eEResourceFileState_Invalid              = 0x00000007,
    eEResourceFileState_ForceDWORD           = GE_FORCE_DWORD
};

enum eEResourceLoadMode
{
    eEResourceLoadMode_Direct     = 0x00000000,
    eEResourceLoadMode_Lazy       = 0x00000001,
    eEResourceLoadMode_ForceDWORD = GE_FORCE_DWORD
};

enum eEResourceState
{
    eEResourceState_Failed     = 0x00000000,
    eEResourceState_Unloaded   = 0x00000001,
    eEResourceState_Pending    = 0x00000002,
    eEResourceState_Loaded     = 0x00000003,
    eEResourceState_Static     = 0x00000004,
    eEResourceState_Invalid    = 0x00000005,
    eEResourceState_ForceDWORD = GE_FORCE_DWORD
};

enum eEResourceType
{
    eEResourceType_Image,
    eEResourceType_Material,
    eEResourceType_Mesh,
    eEResourceType_Motion,
    eEResourceType_MotionActor,
    eEResourceType_Sound,
    eEResourceType_SpeedTree,
    eEResourceType_CollisionMesh,
    eEResourceType_Count,
    eEResourceType_ForceDWORD    = GE_FORCE_DWORD
};

//NOTE: g_ppszResourceTypes isn't const, but it shouldn't be modified.
GE_DLLIMPORT_EXTC GELPCChar const g_ppszResourceTypes[ eEResourceType_Count ];

struct eSResourceFileHeader
{
    GEU32       m_u32Version;
    GEU32       m_u32Revision;
    GEU32       m_u32ObjectOffset;
    GEU32       m_u32ObjectSize;
    GEU32       m_u32DataOffset;
    GEU32       m_u32DataSize;
    SFFFileTime m_RawTime;
    GEChar      m_pcRawExt[ 8 ];
};
GE_ASSERT_SIZEOF( eSResourceFileHeader, 0x0028 )

class GE_DLLIMPORT eCResource2 :
    public bCObjectBase
{
public:
    typedef void (GE_STDCALL * eFPrefetchCallback)( eCResource2 *, GEInt );
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
protected: virtual GEU32                      AddReference( void );
protected: virtual GEU32                      ReleaseReference( void );
public:    virtual                           ~eCResource2( void );
public:    virtual bCString                   GetCompiledExt( void ) const;
protected: virtual void                       OnCalculateFootprint( GEUInt &, GEUInt & ) const;
public:    virtual eCImageResource2 *         QueryImage( void );
public:    virtual eCMaterialResource2 *      QueryMaterial( void );
public:    virtual eCMeshResource2 *          QueryMesh( void );
public:    virtual eCMotionResource2 *        QueryMotion( void );
public:    virtual eCMotionActorResource2 *   QueryMotionActor( void );
public:    virtual eCSoundResource2 *         QuerySound( void );
public:    virtual eCSpeedTreeResource2 *     QuerySpeedTree( void );
public:    virtual eCCollisionMeshResource2 * QueryCollisionMesh( void );
protected: virtual GEU32                      GetDataRevision( void ) const;
protected: virtual GEBool                     OnImportData( eCResourceInputStream2 &, eCResourceOutputStream2 & );
protected: virtual GEBool                     OnLoadData( eCResourceInputStream2 & );
protected: virtual void                       OnSaveData( eCResourceOutputStream2 & );
protected: virtual void                       OnPrefetchData( GEInt );
protected: virtual void                       OnUnloadData( void );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCResource2 *      m_pCacheNext;
    eCResource2 *      m_pCache1;
    eCResource2 *      m_pCache2;
    GEUInt             m_uCacheFrame;
    GEUInt             m_uLockCount;
    GEUInt             m_uDataSize;
    GEUInt             m_uCachedSize;
    eCResourceCache2 * m_pCache;
    eEResourceState    m_enumResourceState;
    bCString           m_strFileTitle;
    SFFFileTime        m_RawTime;
    SFFFileTime        m_CompiledTime;
private:
    static eCResource2 * GE_STDCALL CreateResource( eEResourceType );
    static eCResource2 * GE_STDCALL GetResource( eEResourceType, bCString const & );
private:
    eEResourceFileState GetFileState( void ) const;
    GEBool              Import( bCString const & );
    GEBool              ImportData( eCResourceInputStream2 &, eCResourceOutputStream2 & );
    eEResourceFileState Load( GEBool );
    eEResourceFileState LoadData( CFXVirtualFile &, GEBool );
    GEBool              LoadData( eCResourceInputStream2 & );
    GEBool              Save( bCString const &, bCString const &, SFFFileTime const &, eCResourceOutputStream2 & );
    GEBool              SaveAs( bCString const &, GEBool );
    void                SaveData( eCResourceOutputStream2 & );
    void                UnloadData( void );
    void                UpdateCompiledTime( void );
public:
    static eCCollisionMeshResource2 * GE_STDCALL CreateCollisionMesh( void );
    static eCImageResource2 *         GE_STDCALL CreateImage( void );
    static eCMaterialResource2 *      GE_STDCALL CreateMaterial( void );
    static eCMeshResource2 *          GE_STDCALL CreateMesh( void );
    static eCMotionResource2 *        GE_STDCALL CreateMotion( void );
    static eCMotionActorResource2 *   GE_STDCALL CreateMotionActor( void );
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static eCSoundResource2 *         GE_STDCALL CreateSound( void );
    static eCSpeedTreeResource2 *     GE_STDCALL CreateSpeedTree( void );
    static eCCollisionMeshResource2 * GE_STDCALL GetCollisionMesh( bCString const & );
    static eCImageResource2 *         GE_STDCALL GetImage( bCString const & );
    static eCMaterialResource2 *      GE_STDCALL GetMaterial( bCString const & );
    static eCMeshResource2 *          GE_STDCALL GetMesh( bCString const & );
    static eCMotionResource2 *        GE_STDCALL GetMotion( bCString const & );
    static eCMotionActorResource2 *   GE_STDCALL GetMotionActor( bCString const & );
    static eCResource2 *              GE_STDCALL GetResource( bCString const & );
    static eCSoundResource2 *         GE_STDCALL GetSound( bCString const & );
    static eCSpeedTreeResource2 *     GE_STDCALL GetSpeedTree( bCString const & );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static eCCollisionMeshResource2 * GE_STDCALL LoadCollisionMesh( bCString const &, eEResourceLoadMode );
    static eCImageResource2 *         GE_STDCALL LoadImageA( bCString const &, eEResourceLoadMode );
    static eCMaterialResource2 *      GE_STDCALL LoadMaterial( bCString const &, eEResourceLoadMode );
    static eCMeshResource2 *          GE_STDCALL LoadMesh( bCString const &, eEResourceLoadMode );
    static eCMotionResource2 *        GE_STDCALL LoadMotion( bCString const &, eEResourceLoadMode );
    static eCMotionActorResource2 *   GE_STDCALL LoadMotionActor( bCString const &, eEResourceLoadMode );
    static eCSoundResource2 *         GE_STDCALL LoadSound( bCString const &, eEResourceLoadMode );
    static eCSpeedTreeResource2 *     GE_STDCALL LoadSpeedTree( bCString const &, eEResourceLoadMode );
    static eEResourceState            GE_STDCALL PrefetchResource( bCString const &, GEInt, eEResourceLoadMode, eFPrefetchCallback );
    static void                       GE_STDCALL ReleaseResource( eCResource2 * );
    static eCResource2 *              GE_STDCALL ReloadResource( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void            CalculateFootprint( GEUInt &, GEUInt & ) const;
    GEBool          Exists( void ) const;
    GEUInt          GetCacheFrame( void ) const;
    bCString        GetFileName( void ) const;
    bCString        GetFilePath( void ) const;
    bCString        GetFileTitleA( void ) const;
    bCString        GetPassiveName( void ) const;
    eEResourceState GetResourceState( void ) const;
    GEBool          IsDataLoaded( void ) const;
    GEBool          IsDataPending( void ) const;
    GEBool          IsDataUnloaded( void ) const;
    GEBool          IsLocked( void ) const;
    GEBool          IsStatic( void ) const;
    GEUInt          Lock( void );
    eEResourceState PrefetchData( GEInt, eFPrefetchCallback, eEResourceLoadMode );
    void            Reload( void );
    eEResourceState RequestData( eEResourceLoadMode );
    GEBool          Save( void );
    GEBool          SaveCopyAs( bCString const & );
    GEUInt          Unlock( void );
public:
    eCResource2 & operator = ( eCResource2 const & );
public:
    eCResource2( void );
};
GE_ASSERT_SIZEOF( eCResource2, 0x003C )

#endif
