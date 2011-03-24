#ifndef GE_QUESTMANAGER_H_INCLUDED
#define GE_QUESTMANAGER_H_INCLUDED

class GE_DLLIMPORT gCQuestManager :
    public eCEngineComponentBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCQuestManager( void );
public:    virtual bEResult                   PostInitialize( void );
public:    virtual bEResult                   Shutdown( void );
public:    virtual eCStatistic *              CreateStatistics( void ) const;
protected: virtual bEResult                   ReadSaveGame( bCIStream & );
protected: virtual bEResult                   WriteSaveGame( bCOStream & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x00D4 - sizeof(eCEngineComponentBase) ];
protected:
    void   AddQuestByType( gCQuest * );
    GEBool ImportOldQuestsFromInis( void );
    void   Invalidate( void );
    void   RegisterQuestByName( gCQuest * );
    void   RemoveQuestByType( gCQuest * );
    void   UnregisterQuestByName( gCQuest * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCQuestManager *           GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool                                           AddInventoryListeners( void );
    GEBool                                           AddQuest( gCQuest *, bCString const & );
    void                                             CheckTriggeredDeliveryEntitiesStatusChecks( void );
    GEBool                                           CloseQuest( bCString const &, GEBool );
    GEBool                                           CloseQuest( gCQuest *, GEBool );
    void                                             CloseQuests( gEQuestType, bCString const & );
    GEBool                                           FailQuest( bCString const & );
    GEBool                                           FailQuest( gCQuest * );
    GEU32                                            GetCurrentChapter( void ) const;
    GEBool                                           GetDeliveryEntitiesStatusCheckTriggered( void );
    gCInfoSystem *                                   GetInfoManager( void );
    gCInfoSystem const *                             GetInfoManager( void ) const;
    gCQuest *                                        GetQuest( bCString const & );
    gCQuest const *                                  GetQuest( bCString const & ) const;
    gCQuest *                                        GetQuestAt( GEInt );
    gCQuest const *                                  GetQuestAt( GEInt ) const;
    GEInt                                            GetQuestCount( gEQuestType ) const;
    GEInt                                            GetQuestCount( void ) const;
    GEInt                                            GetQuestCount_Succeeded( void ) const;
    GEBool                                           GetRetroQuestMessageSystemActivated( void ) const;
    GEBool                                           InsertQuestActor( bCString const &, gCQuestActor const & );
    gCQuest *                                        LoadRawQuest( bCString const &, GEBool );
    GEBool                                           OnEnter( eCEntity const &, bCString const & );
    GEBool                                           OnLeave( eCEntity const &, bCString const & );
    GEBool                                           OnNPCDefeated( eCEntity const & );
    GEBool                                           OnNPCKilled( eCEntity const & );
    GEBool                                           OpenQuest( bCString const & );
    GEBool                                           OpenQuest( gCQuest * );
    bTValMap< bCString, gCQuest * >::bCConstIterator QuestBegin( void ) const;
    bTValMap< bCString, gCQuest * >::bCConstIterator QuestEnd( void ) const;
    GEBool                                           ReadQuests( void );
    GEBool                                           RemoveQuest( bCString const & );
    GEBool                                           RemoveQuest( gCQuest * );
    GEBool                                           RemoveQuestActor( bCString const &, gCQuestActor const & );
    GEBool                                           RenameQuest( bCString const &, bCString const & );
    void                                             ResetQuests( void );
    GEBool                                           RunQuest( bCString const & );
    GEBool                                           RunQuest( gCQuest * );
    void                                             RunTextOutputs( void );
    GEBool                                           SaveRawQuest( bCString const & );
    GEBool                                           SaveRawQuestAs( bCString const &, bCString const & );
    void                                             SetCurrentChapter( GEU32, GEBool );
    void                                             SetDeliveryEntitiesStatusCheckTriggered( GEBool );
    void                                             SetLogTextAddedForQuest( gCQuest * );
    GEBool                                           SucceedQuest( bCString const & );
    GEBool                                           SucceedQuest( gCQuest * );
    void                                             SyncronizeToChapter( GEU32, GEBool );
public:
    gCQuestManager & operator = ( gCQuestManager const & );
public:
    gCQuestManager( gCQuestManager const & );
    gCQuestManager( void );
};
GE_ASSERT_SIZEOF( gCQuestManager, 0x00D4 )

#endif
