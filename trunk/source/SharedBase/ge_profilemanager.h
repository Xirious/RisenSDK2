#ifndef GE_PROFILEMANAGER_H_INCLUDED
#define GE_PROFILEMANAGER_H_INCLUDED

class GE_DLLIMPORT bCProfileManager
{
private:
    static bCProfileNode   ms_Root;
    static GEBool          ms_bEnableProfilingNextFrame;
    static GEBool          ms_bProfilingEnabled;
    static GEBool          ms_bResetOnNextFrame;
    static GEI64           ms_i64LastFrameTimeStamp;
    static GEI64           ms_i64LastTiming;
    static GEInt           ms_iFrameCounter;
    static GEInt           ms_iQueueLength;
    static bCProfileNode * ms_pCurrentNode;
protected:
    static bCProfileNode * GE_STDCALL GetAbsoluteNode( GELPCChar );
public:
    static void            GE_STDCALL EnableProfiling( GEBool );
    static GEInt           GE_STDCALL GetFrameCount( void );
    static GEI64           GE_STDCALL GetLastTiming( void );
    static GEInt           GE_STDCALL GetQueueLength( void );
    static bCProfileNode * GE_STDCALL GetRootNode( void );
    static GEFloat         GE_STDCALL GetTimeStamp( void );
    static GEBool          GE_STDCALL IsProfilingEnabled( void );
    static void            GE_STDCALL NextFrame( void );
    static void            GE_STDCALL PrepareStats( void );
    static void            GE_STDCALL ResetOnNextFrame( void );
    static void            GE_STDCALL SetLastTiming( GEI64 );
    static void            GE_STDCALL SetQueueLength( GEInt );
    static void            GE_STDCALL StartProfile( GELPCChar );
    static void            GE_STDCALL StartProfileAbsolute( GELPCChar );
    static void            GE_STDCALL StopProfile( GEFloat );
    static void            GE_STDCALL StopProfile( void );
    static void            GE_STDCALL StopProfileAbsolute( GELPCChar );
public:
    bCProfileManager & operator = ( bCProfileManager const & );
};

#endif
