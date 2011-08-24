#ifndef FX_VIRTUALFILESTREAM_H_INCLUDED
#define FX_VIRTUALFILESTREAM_H_INCLUDED

class FF_DLLIMPORT CFXVirtualFileStream :
    public CFXIOStream
{
public: virtual FFU32  Read( FFLPVoid, FFU32 ) const;
public: virtual FFU32  Write( FFLPCVoid, FFU32 );
public: virtual FFBool GetPosition( FFI64 & ) const;
public: virtual FFBool SetPosition( FFI64, EFFFileSeek );
public: virtual       ~CFXVirtualFileStream( void );
protected:
    IFFFileStream2 * m_pInterface;
public:
    void                  Close( void );
    FFBool                Create( bCString const &, EFFFileCreate, EFFFileAccess, FFU32, FFU32, SFFAsynFileReadDesc * );
    CFXVirtualFileMapping CreateMapping( EFFFileMapProtection, FFU64 );
    FFBool                GetFileInformation( SFFFileData & ) const;
    IFFFileStream2 *      GetInterface( void ) const;
    FFBool                IsOpen( void ) const;
    FFBool                IsReady( void ) const;
public:
    CFXVirtualFileStream & operator = ( CFXVirtualFileStream const & );
public:
    CFXVirtualFileStream( CFXVirtualFileStream const & );
    CFXVirtualFileStream( IFFFileStream2 * = 0 );
};
GE_ASSERT_SIZEOF( CFXVirtualFileStream, 0x0008 );

#endif
