#ifndef GE_SCRIPTROUTINE_PS_H_INCLUDED
#define GE_SCRIPTROUTINE_PS_H_INCLUDED

enum gEAIMode
{
    gEAIMode_None       = 0x00000000,
    gEAIMode_Sender     = 0x00000001,
    gEAIMode_Routine    = 0x00000002,
    gEAIMode_Sleep      = 0x00000003,
    gEAIMode_Observe    = 0x00000004,
    gEAIMode_Talk       = 0x00000005,
    gEAIMode_GotoBody   = 0x00000006,
    gEAIMode_Watch      = 0x00000007,
    gEAIMode_Avoid      = 0x00000008,
    gEAIMode_Threaten   = 0x00000009,
    gEAIMode_Attack     = 0x0000000A,
    gEAIMode_Down       = 0x0000000B,
    gEAIMode_Dead       = 0x0000000C,
    gEAIMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEAmbientAction
{
    gEAmbientAction_Ambient,
    gEAmbientAction_Listen,
    gEAmbientAction_EMPTY,
    gEAmbientAction_Count,
    gEAmbientAction_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA bCString const g_pstrAmbientActionString[ gEAmbientAction_Count ];

enum gEAniState
{
    gEAniState_Dummy0,
    gEAniState_Dummy1,
    gEAniState_Stand,
    gEAniState_Sneak,
    gEAniState_Attack,
    gEAniState_Parade,
    gEAniState_Kneel,
    gEAniState_SitGround,
    gEAniState_SitStool,
    gEAniState_SitBench,
    gEAniState_SitThrone,
    gEAniState_SleepBed,
    gEAniState_SleepGround,
    gEAniState_SitBathtub,
    gEAniState_Down,
    gEAniState_DownBack,
    gEAniState_Dead,
    gEAniState_DeadBack,
    gEAniState_Finished,
    gEAniState_FinishedBack,
    gEAniState_TalkStand,
    gEAniState_TalkSitGround,
    gEAniState_TalkSitStool,
    gEAniState_TalkSitBench,
    gEAniState_TalkSitThrone,
    gEAniState_Wade,
    gEAniState_Swim,
    gEAniState_Dive,
    gEAniState_Stumble,
    gEAniState_Levitate,
    gEAniState_Count,
    gEAniState_ForceDWORD    = GE_FORCE_DWORD
};

GE_DLLIMPORT_DATA bCString const g_pstrAniStateString[ gEAniState_Count ];

enum gEHitDirection
{
    gEHitDirection_Left       = 0x00000000,
    gEHitDirection_Right      = 0x00000001,
    gEHitDirection_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<>' needs to have dll-interface to be used by clients of class 'gCScriptRoutine_PS'
                                   // class 'gCScriptRoutine_PS::CProcessor' needs to have dll-interface to be used by clients of class 'gCScriptRoutine_PS'

class GE_DLLIMPORT gCScriptRoutine_PS :
    public eCEntityPropertySet
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
        gCScriptRoutine_PS * m_pScriptRoutinePS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCScriptRoutine_PS( void );
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;
public:    virtual GEBool                     IsReferencedByTemplate( void ) const;
public:    virtual bEResult                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                   WriteSaveGame( bCOStream & );
public:    virtual eEPSSaveGameRelevance      GetSaveGameRelevance( void ) const;
public:    virtual void                       OnSaveGameEntityPostRead( void );
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual GEBool                     IsClassProcessible( void ) const;
public:    virtual GEBool                     IsClassProcessingEnabled( void ) const;
public:    virtual void                       EnableClassProcessing( GEBool );
public:    virtual void                       EnterProcessingRange( void );
public:    virtual void                       ExitProcessingRange( void );
protected: virtual void                       OnRenderDebug( void );
public:    virtual void                       OnProcess( void );
public:    virtual void                       OnPostRead( void );
public:    virtual void                       OnPostCopy( eCEntityPropertySet const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCScriptProxyScript                     m_Routine;
    bCString                                m_strCurrentTask;
    GEFloat                                 m_fTaskTime;
    GEI32                                   m_i32TaskPosition;
    GEFloat                                 m_fStateTime;
    GEI32                                   m_i32StatePosition;
    GEI32                                   m_i32CommandTime;
    GEBool                                  m_bLockAIInterrupt;
    GEBool                                  m_bLockAIResult;
                                            GE_PADDING( 2 )
    GEI32                                   m_i32AIDelay;
    bCString                                m_strLastTask;
    bCString                                m_strCurrentState;
    GEI32                                   m_i32CurrentBreakBlock;
    bTPropertyContainer< gEAniState >       m_enumAniState;
    bTPropertyContainer< gEAniState >       m_enumFallbackAniState;
    bCString                                m_strActionString;
    eCEntityProxy                           m_ActionTarget;
    bTPropertyContainer< gEAmbientAction >  m_enumAmbientAction;
    bTPropertyContainer< gEAIMode>          m_enumAIMode;
    bTPropertyContainer< gEAIMode >         m_enumAccessLastAIMode;
    GEFloat                                 m_fEndAttackTimestamp;
    bTPropertyContainer< gEHitDirection >   m_enumHitDirection;
    GEBool                                  m_bRoutineChanged;
                                            GE_PADDING1( 3 )
    CProcessor                              m_Processor;
    gCScriptProcessingUnit                  m_SPU;
    GEBool                                  m_bIsDebuggingEnabled;
                                            GE_PADDING2( 3 )
protected:
    void GameReset( void );
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                                           AIContinueRoutine( void );
    void                                           AIFullStop( void );
    bCString                                       AIGetLocalCallback( void ) const;
    bCString                                       AIGetTaskCallback( void ) const;
    void                                           AISetLocalCallback( bCString const & );
    void                                           AISetState( bCString const & );
    void                                           AISetStateTime( GEFloat );
    void                                           AISetTask( bCString const & );
    void                                           AISetTaskCallback( bCString const & );
    void                                           AISetTaskTime( GEFloat );
    void                                           AIStopCombatMove( void );
    void                                           AIStopGoto( GEBool );
    void                                           AIStopOutput( void );
    void                                           AIStopPlayAnimation( void );
    void                                           AIStopWait( void );
    GEI32 &                                        AccessAIDelay( void );
    bTPropertyContainer< gEAIMode > &              AccessAIMode( void );
    bCString &                                     AccessActionString( void );
    eCEntityProxy &                                AccessActionTarget( void );
    bTPropertyContainer< gEAmbientAction > &       AccessAmbientAction( void );
    bTPropertyContainer< gEAniState > &            AccessAniState( void );
    GEI32 &                                        AccessCommandTime( void );
    GEI32 &                                        AccessCurrentBreakBlock( void );
    bCString &                                     AccessCurrentState( void );
    bCString &                                     AccessCurrentTask( void );
    GEFloat &                                      AccessEndAttackTimestamp( void );
    bTPropertyContainer< gEAniState > &            AccessFallbackAniState( void );
    bTPropertyContainer< gEHitDirection > &        AccessHitDirection( void );
    bTPropertyContainer< gEAIMode > &              AccessLastAIMode( void );
    bCString &                                     AccessLastTask( void );
    GEBool &                                       AccessLockAIInterrupt( void );
    GEBool &                                       AccessLockAIResult( void );
    eCScriptProxyScript &                          AccessRoutine( void );
    GEBool &                                       AccessRoutineChanged( void );
    GEI32 &                                        AccessStatePosition( void );
    GEFloat &                                      AccessStateTime( void );
    GEI32 &                                        AccessTaskPosition( void );
    GEFloat &                                      AccessTaskTime( void );
    void                                           EnableDebugging( GEBool );
    GEI32 const &                                  GetAIDelay( void ) const;
    bTPropertyContainer< gEAIMode > const &        GetAIMode( void ) const;
    bCString const &                               GetActionString( void ) const;
    eCEntityProxy const &                          GetActionTarget( void ) const;
    bTPropertyContainer< gEAmbientAction > const & GetAmbientAction( void ) const;
    bTPropertyContainer< gEAniState > const &      GetAniState( void ) const;
    GEI32 const &                                  GetCommandTime( void ) const;
    GEI32 const &                                  GetCurrentBreakBlock( void ) const;
    bCString const &                               GetCurrentState( void ) const;
    bCString const &                               GetCurrentTask( void ) const;
    GEFloat const &                                GetEndAttackTimestamp( void ) const;
    bTPropertyContainer< gEAniState > const &      GetFallbackAniState( void ) const;
    bTPropertyContainer< gEHitDirection > const &  GetHitDirection( void ) const;
    bTPropertyContainer< gEAIMode > const &        GetLastAIMode( void ) const;
    bCString const &                               GetLastTask( void ) const;
    GEBool const &                                 GetLockAIInterrupt( void ) const;
    GEBool const &                                 GetLockAIResult( void ) const;
    eCScriptProxyScript const &                    GetRoutine( void ) const;
    GEBool const &                                 GetRoutineChanged( void ) const;
    gCScriptProcessingUnit &                       GetSPU( void );
    GEI32 const &                                  GetStatePosition( void ) const;
    GEFloat const &                                GetStateTime( void ) const;
    GEI32 const &                                  GetTaskPosition( void ) const;
    GEFloat const &                                GetTaskTime( void ) const;
    GEBool                                         IsDebuggingEnabled( void ) const;
    GEBool                                         IsOutputPlaying( void ) const;
    void                                           SetAIDelay( GEI32 const & );
    void                                           SetAIMode( bTPropertyContainer< gEAIMode > const & );
    void                                           SetActionString( bCString const & );
    void                                           SetActionTarget( eCEntityProxy const & );
    void                                           SetAmbientAction( bTPropertyContainer< gEAmbientAction > const & );
    void                                           SetAniState( bTPropertyContainer< gEAniState > const & );
    void                                           SetCommandTime( GEI32 const & );
    void                                           SetCurrentBreakBlock( GEI32 const & );
    void                                           SetCurrentState( bCString const & );
    void                                           SetCurrentTask( bCString const & );
    void                                           SetEndAttackTimestamp( GEFloat const & );
    void                                           SetFallbackAniState( bTPropertyContainer< gEAniState > const & );
    void                                           SetHitDirection( bTPropertyContainer< gEHitDirection > const & );
    void                                           SetLastAIMode( bTPropertyContainer< gEAIMode > const & );
    void                                           SetLastTask( bCString const & );
    void                                           SetLockAIInterrupt( GEBool const & );
    void                                           SetLockAIResult( GEBool const & );
    void                                           SetRoutine( eCScriptProxyScript const & );
    void                                           SetRoutineChanged( GEBool const & );
    void                                           SetStatePosition( GEI32 const & );
    void                                           SetStateTime( GEFloat const & );
    void                                           SetTaskPosition( GEI32 const & );
    void                                           SetTaskTime( GEFloat const & );
    GEBool                                         StartOutput( bCString const &, gEOutputType );
    GEBool                                         StopOutput( void );
private:
    gCScriptRoutine_PS & operator = ( gCScriptRoutine_PS const & );  // not defined
public:
    gCScriptRoutine_PS( gCScriptRoutine_PS const & );
    gCScriptRoutine_PS( void );
};
GE_ASSERT_SIZEOF( gCScriptRoutine_PS, 0x01CC )

#pragma warning( pop )

#endif
