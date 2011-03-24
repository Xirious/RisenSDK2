#ifndef GE_QUEST_H_INCLUDED
#define GE_QUEST_H_INCLUDED

class gCQuestManager;

enum gEQuestStatus
{
    gEQuestStatus_Open       = 0x00000000,
    gEQuestStatus_Running    = 0x00000001,
    gEQuestStatus_Success    = 0x00000002,
    gEQuestStatus_Failed     = 0x00000003,
    gEQuestStatus_Obsolete   = 0x00000004,
    gEQuestStatus_Cancelled  = 0x00000005,
    gEQuestStatus_Lost       = 0x00000006,
    gEQuestStatus_Won        = 0x00000007,
    gEQuestStatus_ForceDWORD = GE_FORCE_DWORD
};

enum gEQuestType
{
    gEQuestType_HasItems   = 0x00000000,
    gEQuestType_Report     = 0x00000001,
    gEQuestType_Kill       = 0x00000002,
    gEQuestType_Defeat     = 0x00000003,
    gEQuestType_DriveAway  = 0x00000004,
    gEQuestType_Arena      = 0x00000005,
    gEQuestType_BringNpc   = 0x00000006,
    gEQuestType_FollowNpc  = 0x00000007,
    gEQuestType_EnterArea  = 0x00000008,
    gEQuestType_Plunder    = 0x0000000B,
    gEQuestType_Sparring   = 0x0000000C,
    gEQuestType_Duel       = 0x0000000D,
    gEQuestType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCQuest :
    public eCDocObject
{
public:
    struct gSDeliveryEntity
    {
        bCString m_strEntity;
        GEU32    m_u32Amount;
        GEU32    m_u32Delivered;
        GEU32    __FIXME;
    };
    GE_ASSERT_SIZEOF( gSDeliveryEntity, 0x0010 )
    struct SLogEntry
    {
        eCLocString __FIXME_0000;
        eCLocString __FIXME_000C;
    };
    GE_ASSERT_SIZEOF( SLogEntry, 0x0018 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual GEBool                     OnNotifyPropertyValueChangedEnterEx( GELPCChar, GEBool );
public: virtual GEBool                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual                           ~gCQuest( void );
public: virtual bCString                   GetRawExt( void ) const;
public: virtual bCString                   GetRawPath( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x00E8 - sizeof(eCDocObject) ];
protected:
    eCEntity *             GetEntity( bCPropertyID const & ) const;
    eCEntity *             GetEntity( bCString const & ) const;
    gCInfoSystem *         GetInfoManager( void );
    gCInfoSystem const *   GetInfoManager( void ) const;
    gCInventory_PS *       GetInventory( bCPropertyID const & ) const;
    gCInventory_PS *       GetInventory( bCString const & ) const;
    gCNPC_PS *             GetNPC( bCPropertyID const & ) const;
    gCNPC_PS *             GetNPC( bCString const & ) const;
    bCPropertyID const &   GetPropertyIDFromString( bCString const & ) const;
    gCQuestManager *       GetQuestManager( void );
    gCQuestManager const * GetQuestManager( void ) const;
    void                   Invalidate( void );
    GEBool                 IsDead( bCPropertyID const & ) const;
    GEBool                 IsDead( bCString const & ) const;
    GEBool                 IsDead( eCEntity * ) const;
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCString                   GE_STDCALL GetClassRawExt( void );
    static bCString                   GE_STDCALL GetClassRawPath( void );
    static bCString                   GE_STDCALL GetRawFileExtension( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static gCQuest *                  GE_STDCALL LoadBinary( bCIStream & );
    static gCQuest *                  GE_STDCALL LoadRaw( bCString const & );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEU32 &                                         AccessActivationTime_Day( void );
    GEU32 &                                         AccessActivationTime_Hour( void );
    GEU32 &                                         AccessActivationTime_Year( void );
    bTObjArray< gCQuestActor > &                    AccessActors( void );
    eCScriptProxyScript &                           AccessCancelledQuestScript( void );
    bTObjArray< gSDeliveryEntity > &                AccessDeliveryEntities( void );
    bCString &                                      AccessDestinationEntity( void );
    GEI32 &                                         AccessEndChapter( void );
    GEU32 &                                         AccessExperiencePoints( void );
    eCScriptProxyScript &                           AccessFailedQuestScript( void );
    bTObjArray< bCString > &                        AccessFinishedQuests( void );
    bTPropertyContainer< gEWalkMode > &             AccessGuideWalkMode( void );
    bTPropertyContainer< gEInfoLocation > &         AccessLocationInfo( void );
    bTObjArray< SLogEntry > &                       AccessLogText( void );
    gCQuestLocString &                              AccessLogTopic( void );
    eCScriptProxyScript &                           AccessLostQuestScript( void );
    bTObjArray< gCModifySkill > &                   AccessModifySkillsSuccess( void );
    eCScriptProxyScript &                           AccessObsoleteQuestScript( void );
    eCGuiBitmapProxy2 &                             AccessOverlayClient( void );
    eCGuiBitmapProxy2 &                             AccessOverlayTarget( void );
    eCScriptProxyScript &                           AccessRunningQuestScript( void );
    GEU32 &                                         AccessRunningTimeDays( void );
    GEU32 &                                         AccessRunningTimeHours( void );
    GEU32 &                                         AccessRunningTimeYears( void );
    GEBool &                                        AccessSilent( void );
    GEI32 &                                         AccessStartChapter( void );
    bTPropertyContainer< gEQuestStatus > &          AccessStatus( void );
    eCScriptProxyScript &                           AccessSucceededQuestScript( void );
    bTPropertyContainer< gEQuestType > &            AccessType( void );
    eCScriptProxyScript &                           AccessWonQuestScript( void );
    GEBool                                          AddInventoryListener( void );
    GEBool                                          AreFinishedQuestsFinished( void ) const;
    GEBool                                          AreInfosForFinishedQuestsAvailable( void ) const;
    void                                            CheckDeliveryEntitiesStatus( void );
    GEU32 const &                                   GetActivationTime_Day( void ) const;
    GEU32 const &                                   GetActivationTime_Hour( void ) const;
    GEU32 const &                                   GetActivationTime_Year( void ) const;
    bCString                                        GetActorOverlay( GEInt ) const;
    bTObjArray< gCQuestActor > const &              GetActors( void ) const;
    eCScriptProxyScript const &                     GetCancelledQuestScript( void ) const;
    bTObjArray< gSDeliveryEntity > const &          GetDeliveryEntities( void ) const;
    GEBool                                          GetDeliveryEntitiesStatusCheckTriggered( void ) const;
    bCString const &                                GetDestinationEntity( void ) const;
    GEI32 const &                                   GetEndChapter( void ) const;
    eCEntity *                                      GetEntityByKeyword( bCString const & ) const;
    GEU32 const &                                   GetExperiencePoints( void ) const;
    eCScriptProxyScript const &                     GetFailedQuestScript( void ) const;
    bTObjArray< bCString > const &                  GetFinishedQuests( void ) const;
    bTPropertyContainer< gEWalkMode > const &       GetGuideWalkMode( void ) const;
    bCString                                        GetIconName( void ) const;
    bTPropertyContainer< gEInfoLocation > const &   GetLocationInfo( void ) const;
    bTObjArray< SLogEntry> const &                  GetLogText( void ) const;
    gCQuestLocString const &                        GetLogTopic( void ) const;
    eCScriptProxyScript const &                     GetLostQuestScript( void ) const;
    bTObjArray< gCModifySkill > const &             GetModifySkillsSuccess( void ) const;
    bCString                                        GetName( void ) const;
    eCScriptProxyScript const &                     GetObsoleteQuestScript( void ) const;
    eCGuiBitmapProxy2 const &                       GetOverlayClient( void ) const;
    eCGuiBitmapProxy2 const &                       GetOverlayTarget( void ) const;
    GEInt                                           GetQuestProgress( GEInt *, GEInt * ) const;
    eCScriptProxyScript const &                     GetRunningQuestScript( void ) const;
    GEU32 const &                                   GetRunningTimeDays( void ) const;
    GEU32 const &                                   GetRunningTimeHours( void ) const;
    GEU32 const &                                   GetRunningTimeYears( void ) const;
    GEBool const &                                  GetSilent( void ) const;
    GEI32 const &                                   GetStartChapter( void ) const;
    bTPropertyContainer< gEQuestStatus > const &    GetStatus( void ) const;
    eCScriptProxyScript const &                     GetSucceededQuestScript( void ) const;
    eCTemplateEntity *                              GetTemplateEntityByKeyword( bCString const & ) const;
    bTPropertyContainer< gEQuestType > const &      GetType( void ) const;
    eCScriptProxyScript const &                     GetWonQuestScript( void ) const;
    GEBool                                          HasNPCallRequiredItems( bCPropertyID const & );
    GEBool                                          HasNPCpartOfRequiredItems( bCPropertyID const & );
    GEBool                                          HaveNPCsAllRequiredItems( bCPropertyID const &, bCPropertyID const & );
    GEBool                                          ImportOldData( bCString const &, bCString & );
    GEBool                                          IsEntityDeliveryEntity( bCString const & ) const;
    GEBool                                          IsEqualEntity( bCString const &, bCString const & ) const;
    GEBool                                          IsEqualEntity( eCEntity const &, bCString const & ) const;
    GEBool                                          IsFinished( void ) const;
    GEBool                                          IsInChapterRange( void ) const;
    GEBool                                          IsInFinalState( void ) const;
    GEBool                                          IsOvertime( void ) const;
    GEBool                                          IsSucceeded( void ) const;
    GEBool                                          IsValidEntityKeyword( bCString const & ) const;
    void                                            OnEnter( eCEntity const &, bCString const & );
    void                                            OnInventoryStackChange( gCInventoryStack const * );
    void                                            OnLeave( eCEntity const &, bCString const & );
    void                                            OnNPCDefeated( eCEntity const & );
    void                                            OnNPCKilled( eCEntity const & );
    bEResult                                        ReadRuntimeData( bCIStream & );
    GEBool                                          RemoveInventoryListener( void );
    void                                            Reset( void );
    void                                            SetActivationTime_Day( GEU32 const & );
    void                                            SetActivationTime_Hour( GEU32 const & );
    void                                            SetActivationTime_Year( GEU32 const & );
    void                                            SetActors( bTObjArray< gCQuestActor > const & );
    GEBool                                          SetCancelled( void );
    void                                            SetCancelledQuestScript( eCScriptProxyScript const & );
    void                                            SetDeliveryEntities( bTObjArray< gSDeliveryEntity > const & );
    void                                            SetDeliveryEntitiesStatusCheckTriggered( GEBool );
    void                                            SetDestinationEntity( bCString const & );
    void                                            SetEndChapter( GEI32 const & );
    void                                            SetExperiencePoints( GEU32 const & );
    GEBool                                          SetFailed( void );
    void                                            SetFailedQuestScript( eCScriptProxyScript const & );
    void                                            SetFinishedQuests( bTObjArray< bCString > const & );
    void                                            SetGuideWalkMode( bTPropertyContainer< gEWalkMode > const & );
    void                                            SetLocationInfo( bTPropertyContainer< gEInfoLocation > const & );
    void                                            SetLogText( bTObjArray< SLogEntry > const & );
    void                                            SetLogTopic( gCQuestLocString const & );
    void                                            SetLostQuestScript( eCScriptProxyScript const & );
    void                                            SetModifySkillsSuccess( bTObjArray< gCModifySkill > const & );
    void                                            SetObsoleteQuestScript( eCScriptProxyScript const & );
    void                                            SetOverlayClient( eCGuiBitmapProxy2 const & );
    void                                            SetOverlayTarget( eCGuiBitmapProxy2 const & );
    void                                            SetRunningQuestScript( eCScriptProxyScript const & );
    void                                            SetRunningTimeDays( GEU32 const & );
    void                                            SetRunningTimeHours( GEU32 const & );
    void                                            SetRunningTimeYears( GEU32 const & );
    void                                            SetSilent( GEBool const & );
    void                                            SetStartChapter( GEI32 const & );
    void                                            SetStatus( bTPropertyContainer< gEQuestStatus > const & );
    GEBool                                          SetStatus( gEQuestStatus const &, GEBool, GEBool );
    void                                            SetSucceededQuestScript( eCScriptProxyScript const & );
    void                                            SetType( bTPropertyContainer< gEQuestType > const & );
    void                                            SetWonQuestScript( eCScriptProxyScript const & );
    bCString                                        Validate( void ) const;
    bEResult                                        WriteRuntimeData( bCOStream & );
public:
    gCQuest & operator = ( gCQuest const & );
public:
    gCQuest( gCQuest const & );
    gCQuest( void );
};
GE_ASSERT_SIZEOF( gCQuest, 0x00E8 )

#endif
