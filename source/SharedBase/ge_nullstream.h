#ifndef GE_NULLSTREAM_H_INCLUDED
#define GE_NULLSTREAM_H_INCLUDED

#pragma warning( push )

class GE_DLLIMPORT bCNullStream :
    public bCIOStream
{
protected: using bCIStream::Read;
protected: virtual GEU32    Read( GELPVoid, GEU32 );
public:    virtual         ~bCNullStream( void );
public:    virtual GEI64    GetPosition( void ) const;
public:    virtual GEBool   Seek( GEI64, bEStreamSeekMode );
protected: using bCOStream::Write;
protected: virtual GEU32    Write( GELPCVoid, GEU32 );
private:
    GEU32    m_u32BytesWritten;
    GELPVoid m_pBuffer;
    GEU32    m_u32Size;
protected:
    void ReallocBuffer( GEU32 );
public:
    void  Clear( void );
    GEU32 GetBytesWritten( void );
public:
    bCNullStream & operator = ( bCNullStream const & );
public:
    bCNullStream( bCNullStream const & );
    bCNullStream( void );
};
GE_ASSERT_SIZEOF( bCNullStream, 0x0018 )

#endif
