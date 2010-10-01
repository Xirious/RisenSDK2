#ifndef GE_ERRORADMIN_H_INCLUDED
#define GE_ERRORADMIN_H_INCLUDED

enum bEErrorPositionHandling
{
    bEErrorCallbackType_Pre,
    bEErrorCallbackType_Post,
    bEErrorCallbackType_Count,
    bEErrorCallbackType_ForceDWORD = GE_FORCE_DWORD
};

enum bEErrorType
{
    bEErrorType_Exception,
    bEErrorType_Fatal,
    bEErrorType_Fault,
    bEErrorType_ForceDWORD = GE_FORCE_DWORD
};

typedef GEBool (GE_STDCALL * GEFErrorCallback)( bEErrorType, GEU32 );

class GE_DLLIMPORT bCErrorAdmin
{
private:
    struct bSErrorCallback
    {
        GEFErrorCallback m_funcCallback;
        GEU32            m_u32Parameter;
    };
    struct bSErrorHistoryEntry
    {
        GEChar m_carrText[ 250 ];
    };
private:
    GEU32                             m_u32LockCount;
    GEBool                            m_bIsInPanicState;
    GEBool                            m_bIsInSilentMode;
    bCCriticalSection                 m_CriticalSection;
                                      GE_PADDING( 2 )
    bTValQueue< bSErrorHistoryEntry > * m_pqueHistory;
    bTValArray< bSErrorCallback >     * m_parrCallbacks[ bEErrorCallbackType_Count ];
protected:
    void  Destroy( void );
    void  ExecuteErrorCallbacks( bEErrorPositionHandling, bEErrorType );
    void  Invalidate( void );
    GEInt LookupCallback( bEErrorPositionHandling, GEFErrorCallback ) const;
    void  PrintHistoryEntries( void );
    void  PrintMemoryDumpStats( void );
    void  PrintMessage( bCEngineDialogs::bEGE3DialogsLogMessageType, GELPCChar, GEBool );
protected:
    bCErrorAdmin const & operator = ( bCErrorAdmin const & );
public:
    static bCErrorAdmin & GE_STDCALL GetInstance( void );
public:
    void   AddHistoryEntry( GELPCChar );
    void   CallError( GEBool, GELPCChar, GELPCChar, GELPCChar, GEInt );
    void   CallFatalError( GELPCChar, GELPCChar, GELPCChar, GEInt );
    void   CallFatalError( GELPCChar, GELPCChar, GEInt );
    void   CallFaultError( GELPCChar, GELPCChar, GELPCChar, GEInt );
    void   CallFaultError( GELPCChar, GELPCChar, GEInt );
    void   Create( void );
    void   DebugBreak( void );
    void   ForcePanicState( void );
    GEInt  HandleCrash( GEU32, bSExceptionPointers * );
    GEBool IsDebuggerPresent( void ) const;
    GEBool IsInPanicState( void ) const;
    GEBool IsInSilentMode( void ) const;
    GEBool IsLocked( void ) const;
    void   LockSystem( void );
    GEBool RegisterCallback( GEFErrorCallback, bEErrorPositionHandling, GEU32 );
    void   SetSilentMode( GEBool );
    void   TraceF( GELPChar, ... );
    void   UnlockSystem( void );
    GEBool UnregisterCallback( GEFErrorCallback );
protected:
    bCErrorAdmin( bCErrorAdmin const & );
    bCErrorAdmin( void );
public:
   ~bCErrorAdmin( void );
};

#endif
