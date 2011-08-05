#ifndef GE_WORLD_H_INCLUDED
#define GE_WORLD_H_INCLUDED

class GE_DLLIMPORT gCWorld :
    public eCProcessibleElement
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    using        eCProcessibleElement::Create;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCWorld( void );
public:    virtual GEBool                     IsActive( void );
public:    virtual GEBool                     IsDataAvailable( void ) const;
public:    virtual bCString                   GetFileExt( void ) const;
public:    virtual bCString                   GetFileType( void ) const;
public:    virtual bCString                   GetDataFileExt( void ) const;
public:    virtual GEU16                      GetFileVersion( void ) const;
protected: virtual GEBool                     OnReleaseData( void );
public:    virtual GEBool                     Activate( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x0070 -sizeof(eCProcessibleElement) ];
protected:
    gCDynamicLayer *               CreateSystemLayer( bCString const * );
    gCSector *                     CreateSystemSector( void );
    gCDynamicLayer *               CreateSystemTempLayer( void );
    GEBool                         CreateWorldMCP( void );
    void                           DoAfterWorldActivate( void );
    void                           Invalidate( void );
    GEBool                         OnLoadDynamicContext( bCIStream &, gCDynamicLayer &, GEBool );
    eCProcessibleElement::eEResult RemoveSectorInternal( gCSector * );
    void                           SetProject( gCProject * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCWorld *                  GE_STDCALL GetCurrentWorld( void );
    static void                       GE_STDCALL GetFileExt( bCString & );
    static bCString                   GE_STDCALL GetPlayerCameraName( void );
    static bCString                   GE_STDCALL GetPlayerName( void );
    static gCSector *                 GE_STDCALL GetSectorForEntity( eCEntity const * );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                           AddToRemovedNativeEntityList( eCEntity * );
    GEBool                         BackupFiles( bCString const &, GEInt, GEBool, GEBool, GEBool );
    GEBool                         BackupFilesExists( bCString const &, GEInt, bCDateTime * );
    eCProcessibleElement::eEResult ClearSystemSector( void );
//  void                           CollectSaveGameConflicts( bTValArray< gSSaveGameConflict > &) const;
    eCProcessibleElement::eEResult Create( gCProject &, bCString const & );
    eCEntity *                     CreateChildEntity( eCEntity * );
    eCEntity *                     CreateChildEntityFromTemplate( eCEntity *, eCTemplateEntity * );
    eCDynamicEntity *              CreateDynamicEntity( bTObjArray< bCString > const & );
    eCDynamicEntity *              CreateDynamicEntity( bCString const & );
    eCDynamicEntity *              CreateDynamicEntity( void );
    eCDynamicEntity *              CreateTempDynamicEntity( bTObjArray< bCString > const & );
    eCDynamicEntity *              CreateTempDynamicEntity( bCString const & );
    eCDynamicEntity *              CreateTempDynamicEntity( void );
    GEBool                         DestroyDynamicEntity( eCDynamicEntity * );
    GEBool                         DestroyTempDynamicEntity( eCDynamicEntity * );
    void                           DoLoadLocalConfiguration( void );
    void                           DoSaveLocalConfiguration( void ) const;
    GEBool                         EnableSectorFolder( bCString const &, GEBool );
    void                           EnumEntities( GEBool (GE_STDCALL *)(eCEntity *, GELPVoid), GELPVoid, GEU32 ) const;
    bCString const &               GetActiveSector( void ) const;
    eCEntity *                     GetFirstEntity( eCTemplateEntity const * ) const;
    eCEntity *                     GetNextEntity( eCEntity * ) const;
    gCProject &                    GetProject( void );
    gCProject const &              GetProject( void ) const;
    gCSector *                     GetSector( bCString const & );
    gCSector const *               GetSector( bCString const & ) const;
    gCSector *                     GetSectorAt( GEInt );
    gCSector const *               GetSectorAt( GEInt ) const;
    GEInt                          GetSectorCount( void ) const;
    GEInt                          GetSectorIndex( bCString const & ) const;
    gCDynamicLayer &               GetSystemLayer( void );
    gCSector &                     GetSystemSector( void );
    gCDynamicLayer &               GetSystemTempLayer( void );
    eCDynamicEntity *              GetWorldEntity( void );
    eCDynamicEntity const *        GetWorldEntity( void ) const;
    GEBool                         GetWorldFiles( bTObjArray< bCString > & ) const;
    void                           GetWorldVersion( GEU32 &, GEU32 &, GEU32 &, GEU32 & );
    GEBool                         HasSystemLayers( void ) const;
    GEBool                         HasSystemSector( void ) const;
    gCSector *                     ImportSector( bCString const &, GEBool );
    gCSector *                     InsertNewSector( bCString const &, bCString const & );
    eCProcessibleElement::eEResult InsertSector( gCSector * );
    GEBool                         IsSectorFolderEnabled( bCString const & ) const;
    GEBool                         ReadSaveGame( eCArchiveFile & );
    void                           Reload( void );
    void                           RemoveAll( void );
    eCProcessibleElement::eEResult RemoveSector( gCSector * );
    GEBool                         Restart( void );
    GEBool                         RestoreFiles( bCString const & );
    void                           SetActiveSector( bCString const & );
    eCDynamicEntity *              Spawn( eCTemplateEntity *, eCGeometryEntity *, bCString const &, bCMatrix const * );
    GEBool                         WriteSaveGame( eCArchiveFile & ) const;
public:
    gCWorld & operator = ( gCWorld const & );
public:
    gCWorld( gCWorld const & );
    gCWorld( void );
};
GE_ASSERT_SIZEOF( gCWorld, 0x0070 );

#endif
