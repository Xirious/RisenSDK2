#ifndef GE_MESSAGEADMIN_H_INCLUDED
#define GE_MESSAGEADMIN_H_INCLUDED

enum bEMessageCallbackPriority
{
    bEMessageCallbackPriority_Critical,
    bEMessageCallbackPriority_Normal,
    bEMessageCallbackPriority_Low,
    bEMessageCallbackPriority_Count,
    bEMessageCallbackPriority_ForceDWORD = GE_FORCE_DWORD
};

enum bEMessageFilterTypes
{
    bEMessageFilter_OK,
    bEMessageFilter_Info,
    bEMessageFilter_Warn,
    bEMessageFilter_Fault,
    bEMessageFilter_Fatal,
    bEMessageFilter_ForceDWORD = GE_FORCE_DWORD
};

enum bEMessageTypes
{
    bEMessageType_OK = 1,
    bEMessageType_Info,
    bEMessageType_Warn,
    bEMessageType_Fault,
    bEMessageType_Fatal,
    bEMessageType_ForceDWORD = GE_FORCE_DWORD
};

typedef GEBool (GE_STDCALL * GEFMessageCallback)( bEMessageTypes, GELPCChar, GELPCChar, GEU32, GELPCChar, GEInt, GEInt );

class GE_DLLIMPORT bCMessageAdmin
{
private:
    struct bSMessageCallback
    {
        GEFMessageCallback        m_funcCallback;
        GEU32                     m_u32Parameter;
        bEMessageCallbackPriority m_enuPriority;
    };
private:
    static GEBool ms_bIsInSilentLogMode;
private:
    bTValArray< bSMessageCallback > * m_arrCallbacks;
    bCCriticalSection                 m_CriticalSection;
    GEU32                             m_reserved[ 2 ];
    bEMessageFilterTypes              m_enuFilterType;
private:
    void Create( void );
    void Destroy( void );
    void Invalidate( void );
protected:
    GEBool ExecuteCallbackType( bEMessageCallbackPriority, bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt, GEInt );
    GEInt  LookupCallback( GEFMessageCallback ) const;
public:
    static bCMessageAdmin & GE_STDCALL GetInstance( void );
    static GEBool           GE_STDCALL IsInSilentLogMode( void );
public:
    void                 DisableSilentLogMode( void );
    void                 EnableSilentLogMode( void );
    bEMessageFilterTypes GetFilterType( void ) const;
    GEBool               OnMessage( bEMessageTypes, GELPCChar, GELPCChar, GELPCChar, GEInt, GEInt );
    GEBool               RegisterCallback( GEFMessageCallback, bEMessageCallbackPriority, GEU32 );
    void                 SetFilterType( bEMessageFilterTypes );
    GELPCChar            StripFilename( GELPCChar );
    GEBool               UnregisterCallback( GEFMessageCallback );
public:
    bCMessageAdmin( void );
   ~bCMessageAdmin( void );
};

#endif
