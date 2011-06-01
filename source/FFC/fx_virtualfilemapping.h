#ifndef FX_VIRTUALFILEMAPPING_H_INCLUDED
#define FX_VIRTUALFILEMAPPING_H_INCLUDED

class FF_DLLIMPORT CFXVirtualFileMapping
{
public: virtual ~CFXVirtualFileMapping( void );  
protected:
    IFFFileMapping2 * m_pInterface;  // 0004
public:
    void              Close( void );
    IFFFileMapping2 * GetInterface( void ) const;
    FFBool            IsOpen( void ) const;
    FFBool            MapAlignedView( FFU32, FFU64, FFU32, FFLPVoid *, FFLPVoid * );
    FFLPVoid          MapView( FFU32, FFU64, FFU32 );
    FFBool            UnmapView( FFLPCVoid );
public:
    CFXVirtualFileMapping & operator = ( CFXVirtualFileMapping const & );
public:
    CFXVirtualFileMapping( CFXVirtualFileMapping const & );
    CFXVirtualFileMapping( IFFFileMapping2 * = 0 );
};
GE_ASSERT_SIZEOF( CFXVirtualFileMapping, 0x0008 )

#endif
