#ifndef FX_LOCSTRINGEX_H_INCLUDED
#define FX_LOCSTRINGEX_H_INCLUDED

class FF_DLLIMPORT CFXLocStringEx
{
protected:
    CFXTableItem    m_Item;       // 0000
    bCUnicodeString m_strKey;     // 0004
    bCUnicodeString m_strColunn;  // 0008
protected:
    FFBool IsModified( void ) const;
    void   Resolve( void ) const;
    void   Update( void ) const;
public:
    bCUnicodeString GetColumn( void ) const;
    bCUnicodeString GetKey( void ) const;
    bCUnicodeString GetPlainText( void ) const;
    bCUnicodeString GetText( void ) const;
    FFBool          InsertText( bCString const & );
    FFBool          InsertText( bCUnicodeString const & );
    FFBool          IsAttached( void ) const;
    FFBool          IsKeyValid( void ) const;
    void            SetColumn( bCString const & );
    void            SetColumn( bCUnicodeString const & );
    void            SetKey( bCString const & );
    void            SetKey( bCUnicodeString const & );
    FFBool          SetText( bCString const & );
    FFBool          SetText( bCUnicodeString const & );
public:
                     operator bCString        ( void ) const;
                     operator bCUnicodeString ( void ) const;
    CFXLocStringEx & operator =               ( CFXLocStringEx const & );
public:
    CFXLocStringEx( bCString const & );
    CFXLocStringEx( bCString const &, bCString const & );
    CFXLocStringEx( bCUnicodeString const & );
    CFXLocStringEx( bCUnicodeString const &, bCUnicodeString const & );
    CFXLocStringEx( CFXLocStringEx const & );
    CFXLocStringEx( void );
   ~CFXLocStringEx( void );
};
GE_ASSERT_SIZEOF( CFXLocStringEx, 0x000C )

#endif
