#ifndef FX_TABLEITEM_H_INCLUDED
#define FX_TABLEITEM_H_INCLUDED

class GE_DLLIMPORT CFXTableItem
{
protected:
    struct SData
    {
        bCUnicodeString m_strText;    // 0000
        GEBool          m_bModified;  // 0004
                        GE_PADDING( 3 )
        GEU32           m_u32Ref;     // 0008
        // sizeof(CFXTableItem::SData)   000C
    };
protected:
    SData * m_pData;     // 0000
    // sizeof(CFXTableItem) 0004
protected:
    void    AddDataRef( void );
    SData * EnsureData( void );
    SData * GetData( void ) const;
    void    ReleaseData( void );
public:
    void            Detach( void );
    bCUnicodeString GetText( void ) const;
    GEBool          IsAttached( void ) const;
    GEBool          IsModified( void ) const;
    void            SetText( bCUnicodeString const & );
public:
    CFXTableItem & operator = ( CFXTableItem const & );
public:
    CFXTableItem( CFXTableItem const & );
    CFXTableItem( void );
   ~CFXTableItem( void );
};

#endif
