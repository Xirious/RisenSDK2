#ifndef GE_MEMORYSTREAM_H_INCLUDED
#define GE_MEMORYSTREAM_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<>' needs to have dll-interface to be used by clients of class 'bCMemoryStream'

class GE_DLLIMPORT bCMemoryStream :
    public bCIOStream
{
public: virtual GEI64    GetSize( void ) const;
public: virtual GEBool   GetPosition( GEI64 & ) const;
public: virtual GEBool   SetPosition( GEI64, bEStreamSeekMode );
public: using bCIStream::Read;
public: virtual GEU32    Read( GELPVoid, GEU32 );
public: virtual         ~bCMemoryStream( void );
public: virtual GEI64    GetPosition( void ) const;
public: virtual GEBool   Seek( GEI64, bEStreamSeekMode );
public: using bCOStream::Write;
public: virtual GEU32    Write( GELPCVoid, GEU32 );
private:
    bTValArray< GEU8 > m_arrBuffer;
    GEI64              m_i64Position;
protected:
    static GEBool GE_STDCALL Decrypt( GELPVoid, GEU32 );
    static GEBool GE_STDCALL Encrypt( GELPVoid, GEU32 );
protected:
    void Invalidate( void );
public:
    GEU8 *       AccessBuffer( GEU32 );
    void         Clear( void );
    GEBool       Decrypt( void );
    void         Destroy( void );
    GEBool       Encrypt( void );
    GEU8 const * GetBuffer( GEU32 ) const;
    void         SetCount( GEU32 );
public:
    bCMemoryStream & operator = ( bCMemoryStream const & );
public:
    bCMemoryStream( bCMemoryStream const & );
    bCMemoryStream( void );
};
GE_ASSERT_SIZEOF( bCMemoryStream, 0x0020 )

#pragma warning( pop )

#endif
