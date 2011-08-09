#ifndef GE_SESSION_H_INCLUDED
#define GE_SESSION_H_INCLUDED

enum gESession_State
{
    gESession_State_None          = 0x00000000,
    gESession_State_Movement      = 0x00000001,
    gESession_State_Fight         = 0x00000002,
    gESession_State_Ride_Movement = 0x00000003,
    gESession_State_Ride_Fight    = 0x00000004,
    gESession_State_ItemUse       = 0x00000005,
    gESession_State_Inventory     = 0x00000006,
    gESession_State_Dialog        = 0x00000007,
    gESession_State_Trade         = 0x00000008,
    gESession_State_InteractObj   = 0x00000009,
    gESession_State_Journal       = 0x0000000A,
    gESession_State_Editor        = 0x0000000B,
    gESession_State_ForceDWORD    = GE_FORCE_DWORD
};

enum gESession_StartMode
{
    //FIXME: gESession_StartMode constants.
    gESession_StartMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCSession :
    public eCEngineComponentBase
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;
    public: virtual GEU32 GetAppStateFlags( void ) const;
    public: virtual void  OnProcess( void );
    public: virtual      ~CProcessor( void );
    protected:
        gCSession * m_pgCSession;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual                           ~gCSession( void );
public:    virtual bEResult                   PostInitialize( void );
public:    virtual bEResult                   Shutdown( void );
public:    virtual bEResult                   WorldActivate( void );
public:    virtual bEResult                   WorldDeactivate( void );
public:    virtual void                       Process( void );
public:    virtual eCStatistic *              CreateStatistics( void ) const;
protected: virtual bEResult                   ReadSaveGame( bCIStream & );
protected: virtual bEResult                   WriteSaveGame( bCOStream & );
public:    using                bCObjectBase::CopyFrom;
public:    virtual void                       CopyFrom( gCSession const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x00A8 - sizeof(eCEngineComponentBase) ];

protected:
    void CreatePlayerEntity( void );
    void SetPlayer( eCEntityProxy );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCSession &                GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );

public:
    bTPropertyContainer< gESession_State > &       AccessState( void );
    GEBool                                         CanPlayerMove( void ) const;
    GEBool                                         CopyCheckFailed( void ) const;
    void                                           DumpCacheStats( void );
    void                                           DumpFileSysStats( void );
    void                                           DumpMemStatsAll( void );
    void                                           DumpMemStatsObjects( void );
    void                                           DumpMemStatsResources( void );
    void                                           DumpMemStatsSubSystems( void );
    void                                           DumpStatsAll( void );
    gCSessionCheats &                              GetCheats( void );
    eCDynamicEntity *                              GetControledNPC( void ) const;
    eCEntity const *                               GetEditorEntity( void ) const;
    GEBool                                         GetNoMenu( void ) const;
    eCDynamicEntity *                              GetOriginalPlayer( void ) const;
    eCDynamicEntity *                              GetPlayer( void ) const;
    gECombatMode                                   GetRestorePlayerCombatMode( void ) const;
    gCSessionInfo const &                          GetSessionInfo( void ) const;
    bTPropertyContainer< gESession_State > const & GetState( void ) const;
    eCEntityProxy const &                          GetWorldTorch( void ) const;
    void                                           GotoLoadedPosition( void );
    void                                           GotoStartPosition( void );
    void                                           Invalidate( void );
    GEBool                                         IsGameRunning( void ) const;
    GEBool                                         IsInAdvancedTestMode( void ) const;
    GEBool                                         IsInTestMode( void ) const;
    GEBool                                         IsPaused( void ) const;
    GEBool                                         IsSaveAllowed( void ) const;
    void                                           OnControlEntity( eCEntity * );
    void                                           Pause( void );
    GEI32                                          ProcessWorldTorchTimer( void );
    void                                           ResetWorldTorchTimer( GEI32 );
    void                                           RestoreWorldTorch( void );
    void                                           Resume( void );
    void                                           SetAdvancedTestMode( GEBool );
    void                                           SetEditorPlayer( eCEntity * );
    void                                           SetRestorePlayerCombatMode( gECombatMode );
    void                                           SetState( bTPropertyContainer< gESession_State > const & );
    void                                           SetTestMode( GEBool );
    void                                           SetWorldTorch( eCEntity * );
    eCEntity *                                     SpawnEntity( bCString const &, bCMatrix const *, GEBool );
    void                                           Start( gESession_StartMode );
    void                                           StartControlNPC( eCDynamicEntity * );
    void                                           StartGame( void );
    void                                           Stop( void );
    void                                           StopControlNPC( GEBool );
    void                                           TogglePause( void );
public:
    gCSession & operator = ( gCSession const & );
private:
    gCSession( gCSession const & );
public:
    gCSession( void );
};
GE_ASSERT_SIZEOF( gCSession, 0x00A8 )

#endif
