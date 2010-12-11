#ifndef FX_TABLE_H_INCLUDED
#define FX_TABLE_H_INCLUDED

class IFXTableController
{
public: virtual FFBool RequestCheckout( CFXTable * ) = 0;  // [0000].0000
protected:
    // sizeof(IFXTableController) 0004
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValMap<>' needs to have dll-interface to be used by clients of class 'CFXTable'
                                   // class 'bTPtrArray<>' needs to have dll-interface to be used by clients of class 'CFXTable'

class FF_DLLIMPORT CFXTable
{
protected:
    struct SReadFilter
    {
        bCUnicodeString m_strColumn;
        FFI32           m_iMaxItems;
        // sizeof(CFXTable::SReadFilter) 0008
    };
public:
    enum EEncoding
    {
        EEncoding_Ascii      = 0x00000000,
        EEncoding_Unicode    = 0x00000001,
        EEncoding_ForceDWORD = FF_FORCE_DWORD
    };
    struct SBinaryHeader
    {
        FFU32       m_u32Revision;   // 0000
        FFU16       m_u16Version1;   // 0004
        FFU16       m_u16Version2;   // 0006
        SFFFileTime m_RawTimeStamp;  // 0008
        // sizeof(SBinaryHeader)        0010
    };
    struct SRead
    {
        bCUnicodeString m_strColumn;  // 0000
        // sizeof(CFXTable::SRead)       0004
    };
    struct SWrite
    {
        SFFFileTime m_RawTimeStamp;  // 0000
        // sizeof(CFXTable::SWrite)     0008
    };
public: virtual ~CFXTable( void );  // [0000].0000
protected:
    bTValMap< bCUnicodeString, FFInt > m_mapRows;          // 0004
    bTValMap< bCUnicodeString, FFInt > m_mapColumns;       // 0014
    bTPtrArray< CFXTableColumn * >     m_arrColumns;       // 0024
    FFU32                              m_iSelectedColumn;  // 0030
    FFBool                             m_bModified;        // 0034
                                       FF_PADDING( 3 )
    IFXTableController *               m_pController;      // 0038
    // sizeof(CFXTable)                                       003C
protected:
    FFBool           AppendAsciiCsv( CFXIOStream &, SReadFilter & );
    FFBool           AppendCsv( CFXIOStream &, SReadFilter & );
    void             AppendLine( bCString const &, SReadFilter const & );
    void             AppendLine( bCUnicodeString const &, SReadFilter const & );
    FFBool           AppendUnicodeCsv( CFXIOStream &, SReadFilter & );
    void             ApplyDiffs( CFXTableDiff const & );
    CFXTableColumn * EnsureKeyColumn( void );
    void             FindDiffs( CFXTable const &, CFXTableDiff & ) const;
    CFXTableColumn * GetColumn( FFInt ) const;
    FFBool           InitFromLine( bCString const &, SReadFilter & );
    FFBool           InitFromLine( bCUnicodeString const &, SReadFilter & );
    FFBool           Read( CFXIOStream &, SReadFilter & );
    FFBool           ReadBinary( CFXIOStream &, SReadFilter & );
    FFBool           ReadBinaryHeader( CFXIOStream &, SBinaryHeader & );
    FFBool           ReadCsv( CFXIOStream &, SReadFilter & );
    FFBool           RequestCheckOut( void );
    FFBool           WriteAsciiCsv( CFXIOStream & );
    FFBool           WriteBinary( CFXIOStream &, SBinaryHeader const & );
    FFBool           WriteUnicodeCsv( CFXIOStream & );
public:
    FFInt  AddColumn( bCUnicodeString const & );
    FFInt  CopyKey( CFXTable const *, FFInt, FFBool );
    FFBool CopyRow( FFInt, FFInt );
    void   DeleteAll( void );
    FFBool DeleteColumn( FFInt );
    FFBool DeleteKey( bCUnicodeString const & );
    FFBool DeleteRow( FFInt );
    FFInt  FindColumnIndex( bCUnicodeString const & ) const;
    FFBool FindNextFreeKey( bCUnicodeString const &, bCUnicodeString & ) const;
    FFInt  FindRowIndex( bCUnicodeString const & ) const;
    FFInt  GetColumnCount( void ) const;
    FFBool GetColumnLabel( FFInt, bCUnicodeString & ) const;
    FFBool GetKey( FFInt, bCUnicodeString & ) const;
    FFInt  GetKeyCount( void ) const;
    FFInt  GetSelectedColumn( void ) const;
    FFInt  InsertKey( bCUnicodeString const & );
    FFBool IsModified( void ) const;
    FFBool LookupItem( FFInt, CFXTableItem & ) const;
    FFBool LookupItem( FFInt, FFInt, CFXTableItem & ) const;
    FFBool LookupValue( FFInt, bCUnicodeString & ) const;
    FFBool LookupValue( FFInt, FFInt, bCUnicodeString & ) const;
    FFInt  Merge( CFXTable const &, CFXTable const & );
    FFInt  MoveKey( CFXTable *, FFInt, FFBool );
    FFBool Read( bCString const &, SRead const * );
    FFBool ReadBinary( bCString const &, SRead const * );
    FFBool ReadBinaryHeader( bCString const &, SBinaryHeader & );
    FFBool ReadCsv( bCString const &, SRead const * );
    FFBool RegisterController( IFXTableController * );
    FFBool RenameKey( FFInt, bCUnicodeString const & );
    FFBool SelectColumn( FFInt );
    FFBool SetValue( FFInt, bCUnicodeString const & );
    FFBool SetValue( FFInt, FFInt, bCUnicodeString const & );
    void   Sort( void );
    FFBool WriteBinary( bCString const &, SWrite const * );
    FFBool WriteCsv( bCString const &, EEncoding );
public:
    CFXTable & operator = ( CFXTable const & );
public:
    CFXTable( CFXTable const & );
    CFXTable( void );
};

#pragma warning( pop )

#endif
