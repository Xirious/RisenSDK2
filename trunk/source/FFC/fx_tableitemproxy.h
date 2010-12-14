#ifndef FX_TABLEITEMPROXY_H_INCLUDED
#define FX_TABLEITEMPROXY_H_INCLUDED

class FF_DLLIMPORT CFXTableItemProxy
{
protected:
    CFXTableItem     m_Item;    // 0000
    CFXTable const * m_pTable;  // 0004
    bCUnicodeString  m_strKey;  // 0008
protected:
    FFBool IsModified( void ) const;
    void   Resolve( void ) const;
    void   Update( void ) const;
public:
    bCUnicodeString GetKey( void ) const;
    bCUnicodeString GetText( void ) const;
public:
                        operator bCString        ( void ) const;
                        operator bCUnicodeString ( void ) const;
    CFXTableItemProxy & operator =               ( CFXTableItemProxy const & );
public:
    CFXTableItemProxy( CFXTable const *, bCString const & );
    CFXTableItemProxy( CFXTableItemProxy const & );
   ~CFXTableItemProxy( void );
};
GE_ASSERT_SIZEOF( CFXTableItemProxy, 0x000C )

#endif
