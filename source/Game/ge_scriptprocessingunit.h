#ifndef GE_SCRIPTPROCESSINGUNIT_H_INCLUDED
#define GE_SCRIPTPROCESSINGUNIT_H_INCLUDED

class gCScriptAdmin;
class gCScriptRoutine_PS;

struct gScriptRunTimeSingleState
{
    int                     __FIXME_0000;
    gCScriptProxyAIState    m_AIState;
    gCScriptProxyAIFunction m_AIFunction;
    void *                  __FIXME_0014;
    gCScriptProxyAICallback m_AICallback;
    int                     __FIXME_0020;
    eCScriptProxyScript     m_Script;
};
GE_ASSERT_SIZEOF( gScriptRunTimeSingleState, 0x002C )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjStack<>' needs to have dll-interface to be used by clients of class 'gCScriptProcessingUnit'

class GE_DLLIMPORT gCScriptProcessingUnit
{
public:
    enum gEAIInstruction
    {
        //FIXME: gCScriptProcessingUnit::gEAIInstruction constants.
        gEAIInstruction_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual ~gCScriptProcessingUnit( void );  
protected:
    static GEU32 s_u32CalledStateCallbacks;
    static GEU32 s_u32CalledTaskCallbacks;
    static GEU32 s_u32CurrentStateCallbacks;
    static GEU32 s_u32CurrentTaskCallbacks;
    static GEU32 s_u32CurrentTimeStamp;
    static GEU32 s_u32MaxStateCallbacks;
    static GEU32 s_u32MaxTaskCallbacks;
protected:
    void *                                  __FIXME_0004;
    eCEntityProxy                           __FIXME_0008;
    GEBool                                  __FIXME_0010;
                                            GE_PADDING( 3 )
    GEFloat                                 __FIXME_0014;
    GEFloat                                 __FIXME_0018;
    int                                     __FIXME_001C;
    bCVector                                __FIXME_0020;
    bCQuaternion                            __FIXME_002C;
    bCMatrix                                __FIXME_003C;
    bCVector                                __FIXME_007C;
    eCEntityProxy                           __FIXME_0088;
    int                                     __FIXME_0090[ 7 ];
    GEFloat                                 __FIXME_00AC;
    GEFloat                                 __FIXME_00B0;
    GEFloat                                 __FIXME_00B4;
    GEFloat                                 __FIXME_00B8;
    GEBool                                  __FIXME_00BC;
                                            GE_PADDING1( 3 )
    bCString                                __FIXME_00C0;
    int                                     __FIXME_00C4[ 5 ];
    bTObjStack< gScriptRunTimeSingleState > m_stackStates;          // 00D8
    bCString                                __FIXME_00E4;
    eCScriptProxy                           m_TaskCallback;         // 00E8
    int                                     __FIXME_00F0;
    eCEntityProxy                           m_SelfEntity;           // 00F4
    eCEntityProxy                           m_OtherEntity;          // 00FC
    GEInt                                   m_iIntParameter;        // 0104
    GEFloat                                 m_fTaskTicks;           // 0108
    GEFloat                                 m_fStateTicks;          // 010C
    GEBool                                  __FIXME_0110;
                                            GE_PADDING2( 3 )
    bCString                                m_strCaughtTask;        // 0114
    eCAudioChannel *                        m_pAudioChannel;        // 0118
    eCSoundResource2 *                      m_pSoundResource;       // 011C
    gEOutputType                            m_enumOutputType;       // 0120
    eCEntityProxy                           m_WorldMCP;             // 0124
    GEU32                                   m_u32CurrentTimeStamp;  // 012C
protected:
    static void   GE_STDCALL sAICombatMoveItlLoop( gCScriptProcessingUnit * );
    static GEBool GE_STDCALL sAICombatMoveStart( GELPVoid, gCScriptProcessingUnit * );
    static void   GE_STDCALL sAIGotoItlLoop( gCScriptProcessingUnit * );
    static GEBool GE_STDCALL sAIGotoStart( GELPVoid, gCScriptProcessingUnit * );
    static void   GE_STDCALL sAIPlayAniItlLoop( gCScriptProcessingUnit * );
    static GEBool GE_STDCALL sAIPlayAniStart( GELPVoid, gCScriptProcessingUnit * );
    static void   GE_STDCALL sAIPlayInteractAniStart( GELPVoid, gCScriptProcessingUnit * );
    static GEBool GE_STDCALL sIsOutputPlaying( eCGeometryEntity * );
    static GEBool GE_STDCALL sSpecialGoToPlayer( gCScriptProcessingUnit * );
    static void   GE_STDCALL sStandardGotoFwd( gCScriptProcessingUnit * );
    static void   GE_STDCALL sStandardGotoNotFwd( gCScriptProcessingUnit * );
    static GEBool GE_STDCALL sStartOutput( eCGeometryEntity *, bCString const &, gEOutputType );
    static GEBool GE_STDCALL sStopOutput( eCGeometryEntity * );
protected:
    GEBool   CreateSoundAndChannel( void );
    void     DestroySoundAndChannel( void );
    void     GetAniName( bCString &, eCGeometryEntity *, bCString &, bCString, bCString &, GEBool );
    void     RunLocalCallback( gCScriptAdmin *, gCScriptRoutine_PS * );
    void     RunTaskCallback( gCScriptAdmin *, gCScriptRoutine_PS * );
    bEResult SetCurrentAIState( bCString & );
    void     UpdateChannel( void );
    void     UpdateScript( gCScriptAdmin *, gCScriptRoutine_PS * );
    void     UpdateStateTime( gCScriptRoutine_PS * );
    void     UpdateTaskTime( gCScriptRoutine_PS * );
public:
    static GEBool GE_STDCALL sAICombatMoveInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static GEBool GE_STDCALL sAIGotoInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static GEBool GE_STDCALL sAIHUDWaitInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static GEBool GE_STDCALL sAIOutputInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static GEBool GE_STDCALL sAIPlayAniInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static GEBool GE_STDCALL sAIWaitInstr( GELPVoid, gCScriptProcessingUnit *, GEBool );
    static void   GE_STDCALL sSetNewFrame( GEU32 );
public:
    void               AIContinueRoutine( void );
    void               AIFullStop( gEAIInstruction );
    bCString           AIGetLocalCallback( void ) const;
    GEInt              AIGetStatePosition( void );
    GEFloat            AIGetStateTime( void );
    bCString           AIGetTaskCallback( void ) const;
    GEInt              AIGetTaskPosition( void );
    GEFloat            AIGetTaskTime( void );
    void               AISetExitScript( bCString );
    void               AISetLocalCallback( bCString );
    void               AISetState( bCString );
    void               AISetStatePosition( GEInt );
    void               AISetStateTime( GEFloat );
    void               AISetTask( bCString, GEBool );
    void               AISetTaskCallback( bCString );
    void               AISetTaskPosition( GEInt );
    void               AISetTaskTime( GEFloat );
    GEBool             CallAIFunction( gCScriptProxyAIFunction const &, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit *, gSArgsForScriptBase * );
    GEBool             CallAIFunction( gCScriptProxyAIFunction const &, gSArgsForScriptBase * );
    bEResult           DetectDailyRoutineTask( GEBool );
    void               GameReset( void );
    bCString           GetCaughtTask( void );
    GEInt              GetIntParameter( void );
    eCGeometryEntity * GetOtherEntity( void );
    eCGeometryEntity * GetSelfEntity( void );
    eCGeometryEntity * GetTargetEntity( void );
    GEFloat            GetWorldTime( void );
    void               Invalidate( void );
    GEBool             IsOutputPlaying( void ) const;
    void               ProcessExitScript( void );
    bEResult           ProcessScript( void );
    void               SetIntParameter( GEInt );
    void               SetOtherEntity( eCGeometryEntity * );
    void               SetSelfEntity( eCGeometryEntity * );
    GEBool             StartOutput( bCString const &, gEOutputType );
    GEBool             StopOutput( void );
protected:
    gCScriptProcessingUnit const & operator = ( gCScriptProcessingUnit const & );
protected:
    gCScriptProcessingUnit( gCScriptProcessingUnit const & );
public:
    gCScriptProcessingUnit( void );
};
GE_ASSERT_SIZEOF( gCScriptProcessingUnit, 0x0130 )

#pragma warning( pop )

#endif
