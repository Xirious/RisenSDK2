#ifndef GE_ARCHIVEFILE_H_INCLUDED
#define GE_ARCHIVEFILE_H_INCLUDED

class GE_DLLIMPORT eCArchiveFile :
    public bCIOStream
{
public:
    enum bEArchiveFileAccessMode
    {
        bEArchiveFileAccessMode_Read,
        bEArchiveFileAccessMode_Write,
        bEArchiveFileAccessMode_ReadWrite,
        bEArchiveFileAccessMode_ForceDWORD = GE_FORCE_DWORD
    };
/* [0000].0000 */ public: virtual GEU32  Read( bCString & );
/* [0000].0004 */ public: virtual GEU32  Read( GELPVoid, GEU32 );
/* [0000].0008 */ public: virtual       ~eCArchiveFile( void );
/* [0000].000C */ public: virtual GEI64  GetPosition( void ) const;
/* [0000].0010 */ public: virtual GEBool Seek( GEI64, bEStreamSeekMode );
/* [0008].0000 */ public: virtual GEU32  Write( bCString const & );
/* [0008].0004 */ public: virtual GEU32  Write( GELPCVoid, GEU32 );
// [0008].0008 // public: virtual       ~eCArchiveFile( void );
private:
    // 0000 // eCArchiveFile::`vftable'{for `bCIStream'}
    // 0004 // bCIStream members
    // 0008 // eCArchiveFile::`vftable'{for `bCOStream'}
    /* 000C */ char __FIXME_000C[ 0x0028 - 0x000C ];
    // 0028 // sizeof(eCArchiveFile)

protected:
    void PreClose( void );
public:
    void             Clear( void );
    void             Close( void );
    void             Create( bCString const & );
    void             Destroy( void );
    GEBool           Exists( void ) const;
    GEU32            GetAttributes( void ) const;
    bCString         GetFileBaseName( void ) const;
    void             GetFileBaseName( bCString & ) const;
    bCString         GetFileDir( void ) const;
    bCString         GetFileExtension( void ) const;
    void             GetFileExtension( bCString & ) const;
    bCString         GetFileName( void ) const;
    void             GetFileName( bCString & ) const;
    bCString         GetFilePath( void ) const;
    void             GetFilePath( bCString & ) const;
    GEU64            GetFileSize( void ) const;
    bCDateTime       GetFileTime( void ) const;
    bCString         GetFileTitleA( void ) const;
//  IFFFileStream2 * GetHandle( void );
    GEBool           GetModificationTime( bCDateTime & ) const;
    bCString         GetPhysicalFilePath( void ) const;
    GEBool           GetPhysicalPath( bCString & ) const;
    bCString         GetPhysicalRootPath( void ) const;
    bCString         GetRootPath( void ) const;
    void             GetRootPath( bCString & ) const;
    GEU16            GetVersion( void ) const;
    bCString         GetVirtualFilePath( void ) const;
    bCString         GetVirtualRootPath( void ) const;
    GEBool           IsArchived( void ) const;
    GEBool           IsCached( void ) const;
    GEBool           IsCompressed( void ) const;
    GEBool           IsDeleted( void ) const;
    GEBool           IsEncrypted( void ) const;
    GEBool           IsHidden( void ) const;
    GEBool           IsInLegacyMode( void ) const;
    GEBool           IsOpen( void ) const;
    GEBool           IsOpenForWrite( void ) const;
    GEBool           IsPacked( void ) const;
    GEBool           IsPhysical( void ) const;
    GEBool           IsReadOnly( void ) const;
    GEBool           IsSystem( void ) const;
    GEBool           IsTemporary( void ) const;
    GEBool           IsValid( void ) const;
    GEBool           IsVirtual( void ) const;
    GEBool           MatchesMask( GEU32 ) const;
    GEBool           Open( bEArchiveFileAccessMode, GEBool );
//  GEBool           OpenFromHandle( IFFFileStream2 *, GEBool );
//  GEBool           OpenLazy( SFFAsynFileReadDesc *, bEArchiveFileAccessMode );
    void             PostOpen( GEBool );
    void             SetReadOnly( GEBool );
public:
    eCArchiveFile & operator = ( eCArchiveFile const & );
public:
    eCArchiveFile( eCArchiveFile const & );
    eCArchiveFile( void );
};

#endif
