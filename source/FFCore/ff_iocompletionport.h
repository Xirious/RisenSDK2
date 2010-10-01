#ifndef FF_IOCOMPLETIONPORT_H_INCLUDED
#define FF_IOCOMPLETIONPORT_H_INCLUDED

class FF_DLLIMPORT CFFIoCompletionPort
{
private:
    /* 0000 */ FFLPVoid m_hCompletionPort;
    // 0004 // sizeof(CFFIoCompletionPort)
public:
    FFBool Close( void );
    FFBool Create( FFLPVoid a_hFileHandle, FFLPVoid a_pCompletionKey, FFU32 a_u32NumberOfConcurrentThreads );
    FFBool GetQueuedStatus( FFU32 & a_u32NumberOfBytesTransferred, FFLPVoid * a_ppCompletionKey, SFFOverlapped * * a_ppOverlapped, FFU32 a_u32Milliseconds ) const;
    FFBool PostQueuedStatus( FFU32 a_u32NumberOfBytesTransferred, FFLPVoid a_pCompletionKey, SFFOverlapped * a_pOverlapped );
public:
    CFFIoCompletionPort & operator = ( CFFIoCompletionPort const & a_Source );
public:
    CFFIoCompletionPort( void );
   ~CFFIoCompletionPort( void );
};

#endif
