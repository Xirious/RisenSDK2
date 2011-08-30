#ifndef GE_INFO_H_INCLUDED
#define GE_INFO_H_INCLUDED

enum gEInfoCommand
{
    gEInfoCommand_None                   = -1,
    gEInfoCommand_AddLogText             = 0x00000000,
    gEInfoCommand_Attack                 = 0x00000001,
    gEInfoCommand_Back                   = 0x00000002,
    gEInfoCommand_BoostAttribs           = 0x00000003,
    gEInfoCommand_ClearGameEvent         = 0x00000004,
    gEInfoCommand_CloseQuest             = 0x00000005,
    gEInfoCommand_CreateItem             = 0x00000006,
    gEInfoCommand_Description            = 0x00000007,
    gEInfoCommand_DestroyItem            = 0x00000008,
    gEInfoCommand_DoLoot                 = 0x00000009,
    gEInfoCommand_DoTrade                = 0x0000000A,
    gEInfoCommand_End                    = 0x0000000B,
    gEInfoCommand_EndGame                = 0x0000000C,
    gEInfoCommand_FullStop               = 0x0000000D,
    gEInfoCommand_Give                   = 0x0000000E,
    gEInfoCommand_GiveXP                 = 0x0000000F,
    gEInfoCommand_Heal                   = 0x00000010,
    gEInfoCommand_InfoWait               = 0x00000011,
    gEInfoCommand_KillNPC                = 0x00000012,
    gEInfoCommand_AddNPCInfo             = 0x00000013,
    gEInfoCommand_RemoveNPCInfo          = 0x00000014,
    gEInfoCommand_MoveTo                 = 0x00000015,
    gEInfoCommand_PickPocket             = 0x00000016,
    gEInfoCommand_PlayMusic              = 0x00000017,
    gEInfoCommand_RemoveNPC              = 0x00000018,
    gEInfoCommand_RunQuest               = 0x00000019,
    gEInfoCommand_RunScript              = 0x0000001A,
    gEInfoCommand_Say                    = 0x0000001B,
    gEInfoCommand_SayConfirm             = 0x0000001C,
    gEInfoCommand_SayHoldingPosition     = 0x0000001D,
    gEInfoCommand_SayKeepItUp            = 0x0000001E,
    gEInfoCommand_SaySound               = 0x0000001F,
    gEInfoCommand_SaySVM                 = 0x00000020,
    gEInfoCommand_SetGameEvent           = 0x00000021,
    gEInfoCommand_SetGuardStatus         = 0x00000022,
    gEInfoCommand_SetMobEnabled          = 0x00000023,
//  gEInfoCommand_00000024
    gEInfoCommand_SetPartyEnabled        = 0x00000025,
    gEInfoCommand_SetRelaxingPoint       = 0x00000026,
    gEInfoCommand_SetRoutine             = 0x00000027,
    gEInfoCommand_SetSlaveryEnabled      = 0x00000028,
    gEInfoCommand_SetSleepingPoint       = 0x00000029,
    gEInfoCommand_SetSectorStatus        = 0x0000002A,
    gEInfoCommand_SetTeachEnabled        = 0x0000002B,
    gEInfoCommand_SetTradeEnabled        = 0x0000002C,
    gEInfoCommand_SetWorkingPoint        = 0x0000002D,
    gEInfoCommand_ShowPicture            = 0x0000002E,
    gEInfoCommand_ShowSubtitle           = 0x0000002F,
    gEInfoCommand_Sleep                  = 0x00000030,
    gEInfoCommand_StartEffect            = 0x00000031,
    gEInfoCommand_SucceedQuest           = 0x00000032,
    gEInfoCommand_Use                    = 0x00000033,
    gEInfoCommand_Wear                   = 0x00000034,
    gEInfoCommand_TeleportNPC            = 0x00000035,
    gEInfoCommand_Think                  = 0x00000036,
    gEInfoCommand_Trigger                = 0x00000037,
    gEInfoCommand_RunInfo                = 0x00000038,
    gEInfoCommand_StartFixCamera         = 0x00000039,
    gEInfoCommand_StopFixCamera          = 0x0000003A,
    gEInfoCommand_Teach                  = 0x0000003C,
//  gEInfoCommand_0000003D
    gEInfoCommand_AddQuestActor          = 0x0000003E,
    gEInfoCommand_RemoveQuestActor       = 0x0000003F,
    gEInfoCommand_RunAIScript            = 0x00000040,
    gEInfoCommand_AddInfoSystemEndScript = 0x00000041,
    gEInfoCommand_StartTutorial          = 0x00000042,
    gEInfoCommand_ForceDWORD             = GE_FORCE_DWORD
};

enum gEInfoCondType
{
    gEInfoCondType_Crime          = 0x00000000,
    gEInfoCondType_Duel           = 0x00000001,
    gEInfoCondType_Hello          = 0x00000002,
    gEInfoCondType_General        = 0x00000003,
    gEInfoCondType_Overtime       = 0x00000004,
    gEInfoCondType_Open           = 0x00000005,
    gEInfoCondType_Activator      = 0x00000006,
    gEInfoCondType_Running        = 0x00000007,
    gEInfoCondType_Delivery       = 0x00000008,
    gEInfoCondType_PartDelivery   = 0x00000009,
    gEInfoCondType_Success        = 0x0000000A,
    gEInfoCondType_DoCancel       = 0x0000000B,
    gEInfoCondType_Failed         = 0x0000000C,
    gEInfoCondType_Cancelled      = 0x0000000D,
    gEInfoCondType_Join           = 0x0000000E,
    gEInfoCondType_Dismiss        = 0x0000000F,
//  gEInfoCondType_00000010
    gEInfoCondType_Trade          = 0x00000011,
    gEInfoCondType_PickPocket     = 0x00000012,
    gEInfoCondType_Ready          = 0x00000013,
    gEInfoCondType_Lost           = 0x00000014,
    gEInfoCondType_Reactivator    = 0x00000015,
    gEInfoCondType_Won            = 0x00000016,
    gEInfoCondType_MasterThief    = 0x00000017,
//  gEInfoCondType_00000018
//  gEInfoCondType_00000019
    gEInfoCondType_FirstWarn      = 0x0000001A,
    gEInfoCondType_SecondWarn     = 0x0000001B,
    gEInfoCondType_MobJoin        = 0x0000001C,
    gEInfoCondType_SlaveJoin      = 0x0000001D,
    gEInfoCondType_LongTimeNoSee  = 0x0000001E,
//  gEInfoCondType_0000001F
    gEInfoCondType_PoliticalCrime = 0x00000020,
    gEInfoCondType_MobDismiss     = 0x00000021,
    gEInfoCondType_Wait           = 0x00000022,
    gEInfoCondType_Heal           = 0x00000023,
    gEInfoCondType_NothingToSay   = 0x00000032,
    gEInfoCondType_End            = 0x00000033,
    gEInfoCondType_Back           = 0x00000034,
    gEInfoCondType_NotYetFinished = 0x00000035,
    gEInfoCondType_Finished       = 0x00000036,
    gEInfoCondType_ForceDWORD     = GE_FORCE_DWORD
};

enum gEInfoGesture
{
    gEInfoGesture_Ambient    = 0x00000000,
    gEInfoGesture_Me         = 0x00000001,
    gEInfoGesture_You        = 0x00000002,
    gEInfoGesture_Threaten   = 0x00000003,
    gEInfoGesture_Yes        = 0x00000004,
    gEInfoGesture_No         = 0x00000005,
    gEInfoGesture_All        = 0x00000006,
    gEInfoGesture_Back       = 0x00000007,
    gEInfoGesture_Tell       = 0x00000008,
    gEInfoGesture_Admonish   = 0x00000009,
    gEInfoGesture_Secret     = 0x0000000A,
    gEInfoGesture_Recall     = 0x0000000B,
    gEInfoGesture_YouAndMe   = 0x0000000C,
    gEInfoGesture_ForceDWORD = GE_FORCE_DWORD
};

enum gEInfoLocation
{
    gEInfoLocation_Main       = 0x00000000,
    gEInfoLocation_Harbor     = 0x00000001,
    gEInfoLocation_Monastery  = 0x00000002,
    gEInfoLocation_Don        = 0x00000003,
    gEInfoLocation_ForceDWORD = GE_FORCE_DWORD
};

enum gEInfoNPCStatus
{
    gEInfoNPCStatus_Alive             = 0x00000000,
    gEInfoNPCStatus_UnHarmed          = 0x00000001,
    gEInfoNPCStatus_Defeated          = 0x00000002,
    gEInfoNPCStatus_Dead              = 0x00000003,
    gEInfoNPCStatus_TalkedToPlayer    = 0x00000004,
    gEInfoNPCStatus_NotTalkedToPlayer = 0x00000005,
    gEInfoNPCStatus_ForceDWORD        = GE_FORCE_DWORD
};

enum gEInfoNPCType
{
    gEInfoNPCType_Vendor     = 0x00000000,
    gEInfoNPCType_Teacher    = 0x00000001,
    gEInfoNPCType_VIP        = 0x00000002,
    gEInfoNPCType_ForceDWORD = GE_FORCE_DWORD
};

enum gEInfoType
{
    gEInfoType_Refuse     = 0x00000000,
    gEInfoType_Important  = 0x00000001,
    gEInfoType_News       = 0x00000002,
    gEInfoType_Info       = 0x00000003,
    gEInfoType_Parent     = 0x00000004,
    gEInfoType_Comment    = 0x00000005,
    gEInfoType_ForceDWORD = GE_FORCE_DWORD
};

struct SDialogDescription
{
    eCGuiBitmapProxy2 m_SkillImage;
    bCUnicodeString   m_strLevel;
    bCUnicodeString   m_strSkillDesc;
    bCUnicodeString   m_strSkillTag;
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCInfo'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCInfo'

class GE_DLLIMPORT gCInfo :
    public eCDocObject
{
public: virtual bEResult               ReadRuntimeData( bCIStream & );
public: virtual bEResult               WriteRuntimeData( bCOStream & );
GE_DECLARE_PROPERTY_OBJECT( gCInfo, eCDocObject )
public: virtual GEU16                  GetVersion( void ) const;
public: virtual GEBool                 OnDeserialize( bCXMLParserNode * );
public: virtual GEBool                 OnSerialize( bCXMLParserNode * );
public: virtual GEBool                 OnRead( bCIStream & );
public: virtual GEBool                 OnWrite( bCOStream & );
public: virtual bEResult               Create( void );
public: virtual void                   Destroy( void );
public: virtual GEBool                 OnCopyFrom( bCObjectBase const & );
public: virtual bEResult               PostInitializeProperties( void );
public: virtual GEInt                  GetNativePropertyCount( void ) const;
public: virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;
public: virtual bCString               GetRawExt( void ) const;
public: virtual bCString               GetRawPath( void ) const;
protected:
    GE_DECLARE_PROPERTY( bCString,       m_strName,                  Name )
    GE_DECLARE_PROPERTY( GEI32,          m_i32MainSortID,            MainSortID )
    GE_DECLARE_PROPERTY( GEU32,          m_u32SortID,                SortID )
    GE_DECLARE_PROPERTY( bCString,       m_strOwner,                 Owner )
    GE_DECLARE_PROPERTY( GEBool,         m_bInfoGiven,               InfoGiven )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCString,       m_strParent,                Parent )
    GE_DECLARE_PROPERTY( bCString,       m_strQuest,                 Quest )
    GE_DECLARE_ENUMPROP( gEInfoCondType, m_enumConditionType,        ConditionType )
    GE_DECLARE_ENUMPROP( gEInfoType,     m_enumType,                 Type )
    GE_DECLARE_PROPERTY( GEI32,          m_i32GoldCost,              GoldCost )
    GE_DECLARE_PROPERTY( GEI32,          m_i32LearnPointCost,        LearnPointCost )
    GE_DECLARE_PROPERTY( GEBool,         m_bClearChildren,           ClearChildren )
    GE_DECLARE_PROPERTY( GEBool,         m_bPermanent,               Permanent )
    GE_PADDING1( 2 )
    GE_DECLARE_PROPERTY( bCString,       m_strFolder,                Folder )
    GE_DECLARE_PROPERTY( GEInt,          m_iCurrentInfoCommandIndex, CurrentInfoCommandIndex )
    GE_DECLARE_PROPERTY( GEBool,         m_bInfoIsRunning,           InfoIsRunnig )
    GE_PADDING2( 3 )
    GE_DECLARE_PROPERTY( GEI32,          m_i32StartChapter,          StartChapter )
    GE_DECLARE_PROPERTY( GEI32,          m_i32EndChapter,            EndChapter )
    bTValArray< gCInfoCommand * >        m_arrComSeqItems;
    bTValArray< gCInfoCondition * >      m_arrCondSeqItems;
    gCRuntimeInfo *                      m_pRuntimeInfo;
    gCInfo *                             m_pParentInfo;
    bTValArray< gCInfo * >               m_arrChildInfos;
public:
    static bCString          GE_STDCALL GetClassRawExt( void );
    static bCString          GE_STDCALL GetClassRawPath( void );
    static gCNPC_PS *        GE_STDCALL GetNPC( bCPropertyID const & );
    static gCNPC_PS *        GE_STDCALL GetNPC( bCString const & );
    static eCDynamicEntity * GE_STDCALL GetPlayer( void );
    static bCString          GE_STDCALL GetRawFileExtension( void );
    static gCInfo *          GE_STDCALL LoadBinary( bCIStream & );
    static gCInfo *          GE_STDCALL LoadRaw( bCString const & );
    static bCString          GE_STDCALL NPCstatusToString( gEInfoNPCStatus );
    static gEInfoNPCStatus   GE_STDCALL StringToNPCstatus( bCString const & );
public:
    void                           AddChildInfo( gCInfo * );
    GEBool                         AreConditionsFulfilled( void );
    void                           CreateRuntimeInfo( GEBool );
    GEBool                         ExchangeComSeqItems( GEInt, GEInt );
    GEBool                         ExchangeCondSeqItems( GEInt, GEInt );
    bTValArray< gCInfo * > const & GetChildInfos( void ) const;
    gCInfoCommand *                GetComSeqItem( GEInt ) const;
    GEInt                          GetComSeqItemCount( void ) const;
    GEInt                          GetComSeqItemIndex( gCInfoCommand * ) const;
    gCInfoCondition *              GetCondSeqItem( GEInt ) const;
    GEInt                          GetCondSeqItemCount( void ) const;
    GEInt                          GetCondSeqItemIndex( gCInfoCondition * ) const;
    GEInt                          GetCurrentGoldCost( void ) const;
    bCUnicodeString                GetDialogDescription( SDialogDescription * ) const;
    GEFloat                        GetDistOwnerToEntity( bCPropertyID const & ) const;
    GEFloat                        GetDistOwnerToEntity( bCString const & ) const;
    GEFloat                        GetDistOwnerToEntity( eCEntity const & ) const;
    eCEntity *                     GetEntityByKeyword( bCString const & ) const;
    eCEntity *                     GetEntityByName( bCString const & ) const;
    gCInfo *                       GetParentInfo( void ) const;
    eCEntity *                     GetTemplateEntityByKeyword( bCString const & ) const;
    bCUnicodeString                GetTitle( void ) const;
    GEInt                          InsertComSeqItem( gCInfoCommand * );
    GEInt                          InsertComSeqItem( bCString );
    GEInt                          InsertComSeqItem( gEInfoCommand );
    GEInt                          InsertCondSeqItem( gCInfoCondition * );
    GEBool                         IsAvailable( void );
    GEBool                         IsChildInfo( void ) const;
    GEBool                         IsDead( eCEntity * ) const;
    GEBool                         IsOwnerPlayer( void ) const;
    GEBool                         IsValidComSeq( bCString &, gCInfo const & ) const;
    GEBool                         IsValidComSeqIndex( GEInt ) const;
    GEBool                         IsValidCondSeq( bCString &, gCInfo const & ) const;
    GEBool                         IsValidCondSeqIndex( GEInt ) const;
    GEBool                         IsValidEntityKeyword( bCString const & ) const;
    void                           ReadCompiledComSeq( bCIStream & );
    void                           ReadCompiledCondSeq( bCIStream & );
    void                           RefreshParentChildInfos( void );
    void                           RemoveAllComSeqItems( void );
    void                           RemoveAllCondSeqItems( void );
    void                           RemoveChildInfo( gCInfo * );
    GEBool                         RemoveComSeqItem( GEInt );
    GEBool                         RemoveComSeqItem( gCInfoCommand * );
    GEBool                         RemoveCondSeqItem( GEInt );
    GEBool                         RemoveCondSeqItem( gCInfoCondition * );
    void                           ResetRuntimeInfo( void );
    void                           SetComSeqItemCount( GEInt );
    GEBool                         SetComSeqItemIndex( gCInfoCommand *, GEInt );
    void                           SetCondSeqItemCount( GEInt );
    GEBool                         SetCondSeqItemIndex( gCInfoCondition *, GEInt );
    GEBool                         StartRuntimeInfo( void );
    GEBool                         UpdateTable( CFXTable &, bTObjMap< bCString, GEInt> &, GEInt &, GEInt & ) const;
    bCString                       Validate( void ) const;
    void                           WriteCompiledComSeq( bCOStream & ) const;
    void                           WriteCompiledCondSeq( bCOStream & ) const;
protected:
    void          DestroyComSeq( void );
    void          DestroyCondSeq( void );
    void          DestroyRuntimeInfo( void );
    gEInfoCommand GetComSeqCommand( bCString const & );
    void          Invalidate( void );
    void          InvalidateComSeq( void );
    void          InvalidateCondSeq( void );
};
GE_ASSERT_SIZEOF( gCInfo, 0x0084 )

#pragma warning( pop )

#endif
