#ifndef GE_MD5_H_INCLUDED
#define GE_MD5_H_INCLUDED

class GE_DLLIMPORT bCMd5
{
public:
    typedef bCPropertyID::bSCore bSDigest;
private:
    GEU32  m_u32Size[ 2 ];
    GEU32  m_u32ABCD[ 4 ];
    GEU8   m_u8Chunk[ 64 ];
    GEBool m_bIsInProcess;
           GE_PADDING( 3 )
private:
    void Process( GEU8 const [ 64 ] );
protected:
    void Invalidate( void );
public:
    void   Append( GELPCVoid, GEU32 );
    GEBool Create( void );
    void   Destroy( void );
    void   Finish( bSDigest & );
    void   Finish( void );
    void   GetDigest8( bSDigest & ) const;
    void   GetDigest16( bSDigest & ) const;
    void   GetDigest32( bSDigest & ) const;
public:
    bCMd5( void );
   ~bCMd5( void );
};

#endif
