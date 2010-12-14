#ifndef FX_TABLECOLUMN_H_INLCUDED
#define FX_TABLECOLUMN_H_INCLUDED

class CFXTableColumn
{
    bCUnicodeString            m_strLabel;  // 0000
    bTObjArray< CFXTableItem > m_arrItems;  // 0004
};
GE_ASSERT_SIZEOF( CFXTableColumn, 0x0010 )

#endif
