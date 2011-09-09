#ifndef GE_PSMAP_H_INCLUDED
#define GE_PSMAP_H_INCLUDED

struct eSPSIndexMap
{
    enum EIndex
    {
        EIndex_Invalid = 0xFF
    };

    GEU8 m_u8Count;
    GEU8 m_arrIndices[ eEPropertySetType_Count ];
};
GE_ASSERT_SIZEOF( eSPSIndexMap, 0x006B )

class GE_DLLIMPORT eCPSMap
{
private:
    struct SHash
    {
        GEU32 m_Bitmap[ (eEPropertySetType_Count - 1) / 32 + 1 ];
    };
    GE_ASSERT_SIZEOF( SHash, 0x0010 )
    struct SNode
    {
        SNode *      m_pNext;
        SHash        m_Hash;
        eSPSIndexMap m_IndexMap;
        GE_PADDING( 1 )
    };
    GE_ASSERT_SIZEOF( SNode, 0x0080 )

protected:
    SNode * m_pNode;
public:
    static eCPSMap & GE_STDCALL GetInstance( void );
public:
    eCPSMap( void );
   ~eCPSMap( void );
public:
    eCPSMap & operator = ( eCPSMap const & );
public:
    eSPSIndexMap * GetIndexMap( bTValArray< eCEntityPropertySet * > const & a_arrPropertySets, bCString const & a_strReserved );
private:
    void           BuildHash( bTValArray< eCEntityPropertySet * > const & a_arrPropertySets, SHash & a_Hash ) const;
    void           BuildIndexMap( bTValArray< eCEntityPropertySet * > const & a_arrPropertySets, eSPSIndexMap & a_IndexMap ) const;
    eSPSIndexMap * GetIndexMap( SHash const & a_Hash, bTValArray< eCEntityPropertySet * > const & a_arrPropertySets, bCString const & a_strReserved );
    eSPSIndexMap * InsertAfter( SNode * a_pNode, SHash const & a_Hash, bTValArray< eCEntityPropertySet * > const & a_arrPropertySets, bCString const & a_strReserved );
};
GE_ASSERT_SIZEOF( eCPSMap, 0x0004 )

#endif
