#ifndef FX_PHYSICALFILEMAPPING_H_INCLUDED
#define FX_PHYSICALFILEMAPPING_H_INCLUDED

class FF_DLLIMPORT CFXPhysicalFileMapping
{
public: virtual ~CFXPhysicalFileMapping( void );  
protected:
    FFLPVoid m_hInterface;  // 0004
public:
    void     Close( void );
    FFLPVoid GetInterface( void ) const;
    FFBool   IsOpen( void ) const;
    FFLPVoid MapView( FFU32, FFU64, FFU32 );
    FFBool   UnmapView( FFLPCVoid );
public:
    CFXPhysicalFileMapping & operator = ( CFXPhysicalFileMapping const & );
public:
    CFXPhysicalFileMapping( CFXPhysicalFileMapping const & );
    CFXPhysicalFileMapping( FFLPVoid = 0 );
};
GE_ASSERT_SIZEOF( CFXPhysicalFileMapping, 0x0008 )

#endif
