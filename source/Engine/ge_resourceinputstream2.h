#ifndef GE_RESOURCEINPUTSTREAM2_H_INCLUDED
#define GE_RESOURCEINPUTSTREAM2_H_INCLUDED

class GE_DLLIMPORT eCResourceInputStream2 :
    public bCIStream
{
public: virtual GEU32  Read( GELPVoid, GEU32 );
public: virtual GEU32  Read( bCString & );
public: virtual       ~eCResourceInputStream2( void );
public: virtual GEI64  GetPosition( void ) const;
public: virtual GEBool Seek( GEI64, bEStreamSeekMode );
protected:
    CFXVirtualFile        m_VirtualFile;
    CFXVirtualFileMapping m_VirtualFileMapping;
    GELPVoid              m_pBuffer;
    GELPVoid              m_pView;
    GEU32                 m_u32DataOffset;
    GEU32                 m_u32DataSize;
    GEI64                 m_i64Position;
    GEU32                 m_u32DataRevision;
                          GE_PADDING( 4 )
private:
    void        Close( void );
    SFFFileTime GetFileTime( void ) const;
    GEU64       GetSize( void ) const;
    GEBool      Open( bCString const & );
public:
    GELPCVoid GetBuffer( void );
    GEU32     GetDataOffset( void ) const;
    GEU32     GetDataRevision( void ) const;
    GEU32     GetDataSize( void ) const;
    bCString  GetFileExtension( void ) const;
    bCString  GetFileName( void ) const;
    bCString  GetFilePath( void ) const;
    bCString  GetFileTitleA( void ) const;
    bCString  GetPassiveNamePart( void ) const;
    GELPCVoid GetReadPointer( void );
    void      ReleaseBuffer( void );
public:
    eCResourceInputStream2 & operator = ( eCResourceInputStream2 const & );
public:
    eCResourceInputStream2( CFXVirtualFile &, GEU32, GEU32, GEU32 );
    eCResourceInputStream2( eCResourceInputStream2 const & );
    eCResourceInputStream2( void );
};
GE_ASSERT_SIZEOF( eCResourceInputStream2, 0x0040 )

#endif
