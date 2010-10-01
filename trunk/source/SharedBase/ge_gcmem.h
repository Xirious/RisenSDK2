#ifndef GE_GCMEM_H_INCLUDED
#define GE_GCMEM_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<>' needs to have dll-interface to be used by clients of class 'bCGCMem'

class GE_DLLIMPORT bCGCMem
{
private:
    bTPtrArray< bCGCMemGeneration * > m_arrGenerations;
    GEU32                             m_u32TotalBytesAllocated;
protected:
    void Collect( bTPtrArray< bCGCMemGeneration * > & );
    void SetTotalBytesAllocated( GEU32 );
public:
    static bCGCMem & GE_STDCALL GetInstance( void );
public:
    void                              Collect( void );
    bCGCMemGeneration::bSGCRootDesc * GCNew( GEU32 );
    GEInt                             GetGenerationCount( void ) const;
    GEInt                             GetMaxGeneration( void ) const;
    GEU32                             GetTotalBytesAllocated( void ) const;
public:
    bCGCMem( void );
   ~bCGCMem( void );
};

#pragma warning( pop )

#endif
