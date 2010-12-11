#ifndef FX_TABLEDIFF_H_INCLUDED
#define FX_TABLEDIFF_H_INCLUDED

class CFXTable;  // forward

class CFXTableDiff
{
public:
    enum EType
    {
        EType_AdditionalColumn = 0x00000000,
        EType_MissingColumn    = 0x00000001,
        EType_AdditionalItem   = 0x00000002,
        EType_MissingItem      = 0x00000003,
        EType_FIXME            = 0x00000004,
        EType_ForceDWORD       = FF_FORCE_DWORD
    };
    struct SItem
    {
        EType            m_enuType;    // 0000
        bCUnicodeString  m_strColumn;  // 0004
        bCUnicodeString  m_strItem;    // 0008
        CFXTable const * m_pTable;     // 000C
        FFU32            __FIXME;      // 0010
        // sizeof(CFXTableDiff::SItem)    0014
    };
public:
    bTObjArray< SItem > m_arrItems;  // 0000
    // sizeof(CFXTableDiff)             000C
};

#endif
