#ifndef FF_FILEMAPPING2_H_INCLUDED
#define FF_FILEMAPPING2_H_INCLUDED

FF_DECLARE_INTERFACE( IFFFileMapping2, "1ED7F719-9F43-40A9-80F9-696205CDBB32" ) :
    virtual public IFFUnknown
{
public: virtual FFBool    MapAlignedView( FFU32, FFU64, FFU32, FFLPVoid *, FFLPVoid * ) = 0;  
public: virtual FFLPVoid  MapView( FFU32, FFU64, FFU32 )                                = 0;  
public: virtual FFBool    UnmapView( FFLPCVoid )                                        = 0;  
};
GE_ASSERT_SIZEOF( IFFFileMapping2, 0x000C )

#endif
