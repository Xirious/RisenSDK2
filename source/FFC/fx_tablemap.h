#ifndef FX_TABLEMAP_H_INCLUDED
#define FX_TABLEMAP_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual
#pragma warning( disable : 4251 )  // class 'bTPtrArray<>' needs to have dll-interface to be used by clients of class 'CFXTableMap'
                                   // class 'bTValMap<>' needs to have dll-interface to be used by clients of class 'CFXTableMap'

class FF_DLLIMPORT CFXTableMap :
    public IFXTableController
{
protected: virtual FFBool PreTableModify( CFXTable const * );  // [0000].0000
protected:
    bTPtrArray< CFXTableMapItem * >    m_arrItems;        // 0004
    bTValMap< bCUnicodeString, FFInt > m_mapPrefixPaths;  // 0010
protected:
    FFBool            CheckOut( bCString const & );
    FFBool            DeleteItem( FFInt );
    FFInt             FindItemIndexByBinPath( bCString const & ) const;
    FFInt             FindItemIndexByCsvPath( bCString const & ) const;
    CFXTableMapItem * GetItem( FFInt ) const;
    FFBool            IsOrphanedItemIndex( FFInt ) const;
    FFBool            LookupItem( CFXTable const *, bCUnicodeString const &, bCUnicodeString const &, CFXTableItem & ) const;
    FFBool            LookupItem( CFXTable const *, bCUnicodeString const &, CFXTableItem & ) const;
    FFBool            SetValue( CFXTable *, bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const & );
    FFBool            SetValue( CFXTable *, bCUnicodeString const &, bCUnicodeString const & );

public:
    FFBool            CopyKey( bCUnicodeString const &, bCUnicodeString const & );
    void              DeleteAll( void );
    FFBool            DeleteKey( bCUnicodeString const & );
    FFBool            ExportTable( bCUnicodeString const & );
    FFBool            FindNextFreeKey( bCUnicodeString const &, bCUnicodeString & ) const;
    CFXTableMapItem * FindPrefixItem( bCUnicodeString const & ) const;
    CFXTableMapItem * FindPrefixItemByBinPath( bCString const & ) const;
    CFXTableMapItem * FindPrefixItemByCsvPath( bCString const & ) const;
    CFXTable *        FindTable( bCUnicodeString const &, bCUnicodeString & ) const;
    CFXTable *        FindTableByBinPath( bCString const & ) const;
    CFXTable *        FindTableByCsvPath( bCString const & ) const;
    CFXTable *        FindTableByPrefix( bCUnicodeString const & ) const;
    CFXTableMapItem * GetPrefixItem( FFInt ) const;
    FFInt             GetPrefixItemCount( void ) const;
    CFXTable *        GetTable( FFInt ) const;
    FFInt             GetTableCount( void ) const;
    FFBool            HasKey( bCUnicodeString const & ) const;
    FFBool            Import( CFXTable::SRead const * );
    FFBool            ImportTable( bCUnicodeString const &, CFXTable::SRead const * );
    FFBool            InsertKey( bCUnicodeString const & );
    FFBool            LookupItem( bCUnicodeString const &, bCUnicodeString const &, CFXTableItem & ) const;
    FFBool            LookupItem( bCUnicodeString const &, CFXTableItem & ) const;
    FFBool            LookupValue( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString & ) const;
    FFBool            LookupValue( bCUnicodeString const &, bCUnicodeString & ) const;
    FFBool            RegisterPrefixPath( bCUnicodeString const &, bCString const &, bCString const & );
    FFBool            RenameKey( bCUnicodeString const &, bCUnicodeString const & );
    FFBool            SelectColumns( bCUnicodeString const & );
    FFBool            SetValue( bCUnicodeString const &, bCUnicodeString const &, bCUnicodeString const & );
    FFBool            SetValue( bCUnicodeString const &, bCUnicodeString const & );
    FFBool            UnregisterPrefixPath( bCUnicodeString const & );
public:
    CFXTableMap & operator = ( CFXTableMap const & );
public:
    CFXTableMap( CFXTableMap const & );
    CFXTableMap( void );
   ~CFXTableMap( void );
};
GE_ASSERT_SIZEOF( CFXTableMap, 0x0020 )

#pragma warning( pop )

#endif
