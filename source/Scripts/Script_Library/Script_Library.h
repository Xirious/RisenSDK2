#include "Engine.h"

//FIXME: Hacks and temporary definition that are required to get Script_Library running.

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

#define bTObjStack bTObjArray

#define eCGeometryEntity void

#define eSScriptBase void

class GE_DLLIMPORT eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );
protected: virtual void           ReleaseScript( eSScriptBase * );
private:
    eSScriptBase * m_pScript;
protected:
    GEBool   Compare( eCScriptProxy const & ) const;
    bEResult CopyFrom( eCScriptProxy const & );
    bEResult Create( void );
    void     Destroy( void );
    void     Invalidate( void );
public:
    void                 Clear( void );
    eSScriptBase *       GetScript( void );
    eSScriptBase const * GetScript( void ) const;
    bCString const &     GetScriptName( void ) const;
    GEU16                GetVersion( void ) const;
    GEBool               IsScriptValid( void ) const;
    GEBool               IsValid( void ) const;
    bEResult             Read( bCIStream & );
    void                 SetScript( bCString const & );
    void                 SetScript( eSScriptBase * );
    bEResult             Write( bCOStream & ) const;
public:
                          operator bCString const & ( void ) const;
    eCScriptProxy const & operator =                ( bCString const & );
    GEBool                operator ==               ( eCScriptProxy const & ) const;
    GEBool                operator !=               ( eCScriptProxy const & ) const;
    bCIStream &           operator <<               ( bCIStream & );
    bCOStream &           operator >>               ( bCOStream & ) const;
    eCScriptProxy const & operator =                ( eCScriptProxy const & );
public:
    eCScriptProxy( eCScriptProxy const & );
    eCScriptProxy( void );
   ~eCScriptProxy( void );
};

enum gEOutputType
{
    gEOutputType_ForceDWORD = GE_FORCE_DWORD
};

struct gScriptRunTimeSingleState
{
    GEU32 __FIXME_0000[ 0x002C / sizeof(GEU32) ];
};

#define gCScriptAdmin void

#define gCScriptRoutine_PS void

#define gSArgsForScriptBase void

class GE_DLLIMPORT gCScriptProxyAIFunction :
    public eCScriptProxy
{
protected:
    virtual eSScriptBase * QueryScript( bCString const & );
    virtual void           ReleaseScript( eSScriptBase * );
public:
    gCScriptProxyAIFunction & operator = ( gCScriptProxyAIFunction const & );
public:
    gCScriptProxyAIFunction( bCString const & );
    gCScriptProxyAIFunction( eSScriptBase * );
    gCScriptProxyAIFunction( gCScriptProxyAIFunction const & );
    gCScriptProxyAIFunction( void );
   ~gCScriptProxyAIFunction( void );
};

class GE_DLLIMPORT gCScriptProcessingUnit
{
public:
    enum gEAIInstruction
    {
        gEAIInstruction_ForceDWORD = GE_FORCE_DWORD
    };
public: virtual ~gCScriptProcessingUnit( void );
private:
    GEU32 __FIXME_0000[ 0x0130 / sizeof(GEU32) - sizeof(GELPVoid) ];
protected:
    static GEU32 s_u32CalledStateCallbacks;
    static GEU32 s_u32CalledTaskCallbacks;
    static GEU32 s_u32CurrentStateCallbacks;
    static GEU32 s_u32CurrentTaskCallbacks;
    static GEU32 s_u32CurrentTimeStamp;
    static GEU32 s_u32MaxStateCallbacks;
    static GEU32 s_u32MaxTaskCallbacks;
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

typedef GEBool ( GE_STDCALL * gFScriptAIState)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );

struct gSScriptAIState
{
	bCString        m_strName;
	bCString        m_strSource;
	gFScriptAIState m_funcScriptAIState;
    gSScriptAIState( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIState a_funcScriptAIState ) :
        m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAIState( a_funcScriptAIState )
    {
    }
    gSScriptAIState( void )
    {
    }
};

typedef GEBool (GE_STDCALL * gFScriptAIFunction)( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );

struct gSScriptAIFunction
{
	bCString           m_strName;
	bCString           m_strSource;
	gFScriptAIFunction m_funcScriptAIFunction;
    gSScriptAIFunction( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAIFunction a_funcScriptAIFunction ) :
        m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAIFunction( a_funcScriptAIFunction )
    {
    }
    gSScriptAIFunction( void )
    {
    }
};

typedef GEBool (GE_STDCALL * gFScriptAICallback)( gCScriptProcessingUnit * );

struct gSScriptAICallback
{
	bCString           m_strName;
	bCString           m_strSource;
	gFScriptAICallback m_funcScriptAICallback;
    gSScriptAICallback( GELPCChar a_pcName, GELPCChar a_pcSource, gFScriptAICallback a_funcScriptAICallback ) :
        m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScriptAICallback( a_funcScriptAICallback )
    {
    }
    gSScriptAICallback( void )
    {
    }
};

typedef GEInt (GE_STDCALL * gFScript)( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );

struct gSScript
{
	bCString m_strName;
	bCString m_strSource;
	gFScript m_funcScript;
    __forceinline gSScript( GELPCChar a_pcName, GELPCChar a_pcSource, gFScript a_funcScript ) :
        m_strName( a_pcName ), m_strSource( a_pcSource ), m_funcScript( a_funcScript )
    {
    }
    __forceinline gSScript( void )
    {
    }
};

struct gSScriptFunctions {
	bTObjArray< gSScriptAIState >    m_arrScriptAIStates;
    bTObjArray< gSScriptAIFunction > m_arrScriptAIFunction;
    bTObjArray< gSScriptAICallback > m_arrScriptAICallbacks;
    bTObjArray< gSScript >           m_arrScripts;
    __forceinline gSScriptFunctions( void )
    {
    }
    __forceinline ~gSScriptFunctions( void )
    {
    }
};

#pragma warning( pop )
