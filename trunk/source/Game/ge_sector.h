#ifndef GE_SECTOR_H_INCLUDED
#define GE_SECTOR_H_INCLUDED

class GE_DLLIMPORT gCSector :
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
public:    virtual GEInt                      GetNativePropertyCount( void ) const;
public:    virtual bCPropertyConverterPtr     GetNativePropertyAt( GEInt ) const;
public:    virtual                           ~gCSector( void );
public:    virtual GEBool                     IsDataAvailable( void ) const;
public:    virtual bCString                   GetFileExt( void ) const;
public:    virtual bCString                   GetFileType( void ) const;
public:    virtual bCString                   GetDataFileExt( void ) const;
public:    virtual GEU16                      GetFileVersion( void ) const;
protected: virtual GEBool                     DoAfterLoadData( void );
protected: virtual GEBool                     OnReleaseData( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    static GEBool         ms_bEnableLayerActivation;
    static GEBool         ms_bStaticLayerSpeedUp;
    static bCString const ms_strDynamicEntitySector;
protected:
    char __FIXME[ 0x0028 - sizeof(eCProcessibleElement) ];
protected:
    static void GE_STDCALL CopyFileToBackup( bCString const &, bCString const &, bTObjArray< bCString > & );
protected:
    GEBool                         ContainsEntity( eCEntity const *, eCEntity const & ) const;
    void                           Invalidate( void );
    GEBool                         OnEnable( GEBool );
    eCProcessibleElement::eEResult RemoveDynamicLayerInternal( gCDynamicLayer * );
    void                           SetWorld( gCWorld const * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static void                       GE_STDCALL EnableSectorActivation( GEBool );
    static void                       GE_STDCALL EnableSectorSpeedup( GEBool );
    static void                       GE_STDCALL GetFileExt( bCString & );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool &                                  AccessDemoRelevant( void );
    GEBool &                                  AccessEnabledOnStartup( void );
    bTRefPtrArray< gCDynamicLayer * > &       AccessEntityLayers( void );
    GEBool &                                  AccessSaveGameRelevant( void );
    GEBool                                    BackupFiles( bCString const &, GEInt, GEBool, GEBool, bTObjArray< bCString > & );
    GEBool                                    BackupFilesExists( bCString const &, GEInt );
    void                                      CollectContexts( bTValArray< eCContextBase * > & ) const;
//  void                                      CollectSaveGameConflicts( bTValArray< gSSaveGameConflict > & ) const;
    GEBool                                    ContainsEntity( eCEntity const & ) const;
    eCProcessibleElement::eEResult            Create( gCWorld &, bCString const &, bCString const & );
    void                                      Enable( GEBool );
    GEBool                                    EnumEntities( GEFEnumEntitiesCallback, GELPVoid ) const;
    GEBool const &                            GetDemoRelevant( void ) const;
    gCDynamicLayer *                          GetDynamicLayer( bCString const & );
    gCDynamicLayer const *                    GetDynamicLayer( bCString const & ) const;
    gCDynamicLayer *                          GetDynamicLayerAt( GEInt );
    gCDynamicLayer const *                    GetDynamicLayerAt( GEInt ) const;
    GEInt                                     GetDynamicLayerCount( void ) const;
    GEInt                                     GetDynamicLayerIndex( bCString const & ) const;
    GEBool const &                            GetEnabledOnStartup( void ) const;
    bTRefPtrArray< gCDynamicLayer * > const & GetEntityLayers( void ) const;
    eCEntity *                                GetFirstEntity( eCTemplateEntity const * ) const;
    eCEntity *                                GetNextEntity( eCEntity * ) const;
    GEBool const &                            GetSaveGameRelevant( void ) const;
    gCWorld &                                 GetWorld( void );
    gCWorld const &                           GetWorld( void ) const;
    gCDynamicLayer *                          ImportDynamicLayer( eCArchiveFile & );
    gCDynamicLayer *                          ImportDynamicLayer( bCString const & );
    eCProcessibleElement::eEResult            InsertDynamicLayer( gCDynamicLayer * );
    gCDynamicLayer *                          InsertNewDynamicLayer( bCString const &, gEEntityType );
    GEBool                                    IsEnabled( void ) const;
    GEBool                                    IsReadOnly( void ) const;
    GEBool                                    IsSysSector( void ) const;
    void                                      ReadSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32 > const &, GEI64 );
    void                                      Reload( void );
    GEBool                                    RemoveAll( void );
    eCProcessibleElement::eEResult            RemoveDynamicLayer( gCDynamicLayer * );
    GEBool                                    RestoreFiles( bCString const & );
    void                                      SetDemoRelevant( GEBool const & );
    void                                      SetEnabledOnStartup( GEBool const & );
    void                                      SetEntityLayers( bTRefPtrArray< gCDynamicLayer * > const & );
    void                                      SetSaveGameRelevant( GEBool const & );
    void                                      Unload( void );
    void                                      WriteSaveGame( eCArchiveFile &, bTObjMap< bCString, GEU32> &, GEI64 ) const;
public:
    gCSector & operator = ( gCSector const & );
public:
    gCSector( gCSector const & );
    gCSector( void );
};
GE_ASSERT_SIZEOF( gCSector, 0x0028 )

#endif
