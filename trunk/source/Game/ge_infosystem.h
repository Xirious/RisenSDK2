#ifndef GE_INFOSYSTEM_H_INCLUDED
#define GE_INFOSYSTEM_H_INCLUDED

struct gSNPCInfo
{
    eCEntityProxy      m_Entity;
    gEInfoLocation     m_enumLocation;
    gEInfoNPCType      m_enumNPCType;
    gCNPCInfoLocString m_locNPCInfo;
};
GE_ASSERT_SIZEOF( gSNPCInfo, 0x001C )

class GE_DLLIMPORT gCInfoSystem
{
public:
    typedef void (GE_STDCALL * gFInfoParentChangedCallback)( gCInfo *, gCInfo *, gCInfo * );
    struct gSInfoSytemEndScript
    {
        eCScriptProxyScript m_Script;
        bCString            m_strSelf;
        bCString            m_strOther;
        GEInt               m_iParam;
    };
    GE_ASSERT_SIZEOF( gSInfoSytemEndScript, 0x0014 )

public: virtual bEResult ReadSaveGame( bCIStream & );
public: virtual bEResult WriteSaveGame( bCOStream & );
public: virtual         ~gCInfoSystem( void );
protected:
    char __FIXME[ 0x0074 - sizeof(void *) ];
public:
    static GEBool GE_STDCALL Give( bCPropertyID const &, bCPropertyID const &, bCPropertyID const &, GEU32 const & );
    static GEBool GE_STDCALL Give( eCEntity *, eCEntity *, bCPropertyID const &, GEU32 );
    static GEBool GE_STDCALL Give( eCEntity *, eCEntity *, GEInt, GEInt );
    static GEBool GE_STDCALL Give( eCEntity *, eCEntity *, eCTemplateEntity const *, GEU32 );
    static void   GE_STDCALL RemoveDuplicatedInfos( bTValArray< gCInfo * > &, gEInfoCondType );
    static void   GE_STDCALL RemoveDuplicatedInfos( bTValArray< gCRuntimeInfo * > &, gEInfoCondType );
    static void   GE_STDCALL SortInfos( GEInt, bTValArray< gCInfo * > & );
    static void   GE_STDCALL SortInfos( GEInt, bTValArray< gCRuntimeInfo * > & );
    static GEInt  GE_CCALL   __SortInfosCbk( GELPCVoid, GELPCVoid );
    static GEInt  GE_CCALL   __SortInfosCbk_RuntimeInfo( GELPCVoid, GELPCVoid );
public:
    gCInfoSystem( void );
    gCInfoSystem( gCInfoSystem const & );
public:
    gCInfoSystem & operator = ( gCInfoSystem const & );
public:
    GEBool                                AddInfoSystemEndScript( gSInfoSytemEndScript & );
    void                                  AddNPCInfo( gSNPCInfo const & );
    GEBool                                AreChildInfosAvailable( gCInfo const & );
    void                                  ClearGameVariables( void );
    gCInfo *                              CreateInfo( bCString const & );
    GELPVoid                              CreateInfo( gCInfo const & );
    GEBool                                EnableInfoProcessing( GELPVoid, GEBool );
    void                                  EndInfoSystem( gCInfo *, GEBool );
    GEBool                                ExecuteDialogInfo( gCInfo * );
    GEBool                                ForceAsNextInfo( bCString const & );
    GEBool                                GameVariableExists( bCString const & ) const;
    eTDocObjectMap< gCInfo > &            GetAllInfos( void );
    gCInfo *                              GetAvailableInfo( GEInt );
    GEInt                                 GetAvailableInfoCount( void );
    gCRuntimeInfo *                       GetCurrentInfo( void );
    eCEntity *                            GetCurrentOther( void );
    eCEntity *                            GetCurrentSelf( void );
    eCEntity *                            GetDialogPartner1( void ) const;
    eCEntity *                            GetDialogPartner2( void ) const;
    eCEntity *                            GetDialogPartnerNPC( void ) const;
    GEBool                                GetGameVariable( bCString const &, GEInt & ) const;
    bTArrayMap< bCString, GEI32 > const & GetGameVariables( void ) const;
    GEU32                                 GetHighestSortID( void ) const;
    gCInfo *                              GetInfoPS( bCString const & );
    gCInfo const *                        GetInfoPS( bCString const & ) const;
    gSNPCInfo const &                     GetNPCInfo( GEInt ) const;
    GEUInt                                GetNPCInfoCount( void ) const;
    gCQuestManager *                      GetQuestManager( void );
    gCQuestManager const *                GetQuestManager( void ) const;
    bTValArray< gCRuntimeInfo * > const & GetRunningInfos( void ) const;
    GEBool                                HasCommentInfo( eCEntity * );
    GEBool                                HasImportantInfo( eCEntity * );
    GEBool                                HasInfos( eCEntity * );
    GEBool                                HasNewsInfo( eCEntity * );
    GEBool                                HasRefuseInfo( eCEntity * );
    GEBool                                IsDialogInfo( gCInfo const & ) const;
    GEBool                                IsParentInfoAvailable( gCInfo & ) const;
    GEBool                                IsRunning( void );
    GEBool                                IsSuccessOrFailedInfoAvailable( gCQuest const & ) const;
    GEBool                                IsValid( GELPVoid, bCString & ) const;
    GEBool                                Load( void );
    gCInfo *                              LoadRawInfo( bCString const &, GEBool );
    void                                  NotifyParentChanged( gCInfo *, gCInfo *, gCInfo * );
    void                                  OnEndInfoSystem( void );
    void                                  OnInfoFinished( gCRuntimeInfo const * );
    void                                  OnInfoStarted( bCString const & );
    GEBool                                OnNPCKilled( eCEntity const & );
    void                                  Process( void );
    GEBool                                ProcessInfo( GELPVoid );
    GEBool                                ProcessInfoSystemEndScriptList( void );
    void                                  RefreshParentChildInfos( void );
    GEBool                                ReloadRawInfos( void );
    GEBool                                RemoveGameVariable( bCString const & );
    GEBool                                RemoveInfo( bCString const & );
    void                                  RemoveNPCInfo( gSNPCInfo const & );
    GEBool                                Reset( void );
    GEBool                                ResetInfoSystemEndScriptList( void );
    GEBool                                SaveRawInfo( bCString const & ) const;
    GEBool                                SaveRawInfoAs( bCString const &, bCString const & ) const;
    void                                  SetChildMode( GEBool );
    GEBool                                SetGameVariable( bCString const &, GEInt );
    void                                  SetInfoParentChangedCallback( gFInfoParentChangedCallback );
    GEBool                                StartComment( eCEntity * );
    GEBool                                StartInfoSystem( eCEntity &, eCEntity & );
    GEBool                                StopInfo( GELPVoid );
    GEBool                                SwapInfos( bCString const &, bCString const & );
    void                                  SyncronizeToChapter( GEU32 );
    GEBool                                UpdateTable( void );
protected:
    GEBool                          AreOnlyEndInfosAvailable( void ) const;
    void                            BuildMapInfosByOwners( void );
    void                            DeleteRunningInfos( void );
    void                            Destroy( void );
    bTValArray< gCRuntimeInfo * > & GetChildInfoList( bTValArray< gCRuntimeInfo * > &, gCInfo & );
    gCInfo *                        GetInfo( bCString const & );
    bTValArray< gCRuntimeInfo * > & GetInfoList( bTValArray< gCRuntimeInfo * > &, bCString const &, bCString const &, GEBool, GEBool, GEBool, GEBool );
    void                            HideDialogManager( void );
    void                            Invalidate( void );
    GEBool                          LoadInfos( GEBool );
    void                            ShowDialogManager( void );
};
GE_ASSERT_SIZEOF( gCInfoSystem, 0x0074 )

#endif
