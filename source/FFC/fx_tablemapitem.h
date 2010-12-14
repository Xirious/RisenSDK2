#ifndef FX_TABLEMAPITEM_H_INCLUDED
#define FX_TABLEMAPITEM_H_INCLUDED

class FF_DLLIMPORT CFXTableMapItem
{
protected:
    bCString m_strCsvPath;  // 0000
    bCString m_strBinPath;  // 0004
    CFXTable m_Table;       // 0008
protected:
    FFBool CanReadBinary( void );
    FFBool GetCsvModTime( SFFFileTime & );
    FFBool ReadBinary( CFXTable::SRead const * );
    FFBool ReadCsv( CFXTable::SRead const * );
    FFBool ReadHeader( CFXTable::SBinaryHeader & );
    FFBool WriteBinary( void );
    FFBool WriteCsv( void );
public:
    FFBool Export( void );
    FFBool Import( CFXTable::SRead const * );
public:
    CFXTableMapItem & operator = ( CFXTableMapItem const & );
public:
    CFXTableMapItem( CFXTableMapItem const & );
    CFXTableMapItem( void );
   ~CFXTableMapItem( void );
};
GE_ASSERT_SIZEOF( CFXTableMapItem, 0x0044 )

#endif
