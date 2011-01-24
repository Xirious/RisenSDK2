#ifndef GE_GCMEMGENERATION_H_INCLUDED
#define GE_GCMEMGENERATION_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPtrArray<>' needs to have dll-interface to be used by clients of class 'bCGCMemGeneration'

class GE_DLLIMPORT bCGCMemGeneration
{
public:
    struct bSGCRootDesc
    {
        GELPVoid m_pBuffer;
        GEU16    m_u16GenerationNumber;
        GEU16    m_u16DescriptionIndex;
        GEU16    m_u16BufferSize;
                 GE_PADDING( 2 )
    };
private:
    GEU16                        m_u16GenerationNumber;
                                 GE_PADDING( 2 )
    bTPtrArray< bSGCRootDesc * > m_arrDescriptions;
    GELPVoid                     m_pHeap;
    GELPVoid                     m_pNext;
    GEU8                         m_arrHeap[ 20000 ];
public:
    bSGCRootDesc * Allocate( GEU16 );
    void           CopyBuffer( bSGCRootDesc * & );
    GEU16          GetGenerationNumber( void ) const;
    GEU32          GetRemainingMemory( void ) const;
    GEU32          GetTotalMemory( void ) const;
public:
    bCGCMemGeneration & operator = ( bCGCMemGeneration const & );
public:
    bCGCMemGeneration( bCGCMemGeneration const & );
    bCGCMemGeneration( GEU16 = 0 );
   ~bCGCMemGeneration( void );
};

#pragma warning( pop )

#endif
