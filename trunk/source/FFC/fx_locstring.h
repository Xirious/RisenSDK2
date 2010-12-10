#ifndef FX_LOCSTRING_H_INCLUDED
#define FX_LOCSTRING_H_INCLUDED

class FF_DLLIMPORT CFXLocString :
    public CFXTableItem
{
protected:
    bCUnicodeString m_strKey;  // 0004
    // sizeof(CFXLocString)       0008
protected:
    FFBool IsModified( void ) const;
    void   Resolve( void ) const;
    void   Update( void ) const;
public:
    bCUnicodeString GetKey( void ) const;
    bCUnicodeString GetPlainText( void ) const;
    bCUnicodeString GetPlainText( bCString const & ) const;
    bCUnicodeString GetPlainText( bCUnicodeString const & ) const;
    bCUnicodeString GetText( void ) const;
    bCUnicodeString GetText( bCString const & ) const;
    bCUnicodeString GetText( bCUnicodeString const & ) const;
    FFBool          InsertText( bCString const & );
    FFBool          InsertText( bCUnicodeString const &, bCUnicodeString const & );
    FFBool          InsertText( bCUnicodeString const & );
    FFBool          IsAttached( void ) const;
    FFBool          IsKeyValid( void ) const;
    void            SetKey( bCString const & );
    void            SetKey( bCUnicodeString const & );
    FFBool          SetText( bCString const & );
    FFBool          SetText( bCUnicodeString const & );
    FFBool          SetText( bCUnicodeString const &, bCUnicodeString const & );
public:
                   operator bCString        ( void ) const;
                   operator bCUnicodeString ( void ) const;
    CFXLocString & operator =               ( CFXLocString const & );
public:
    CFXLocString( bCString const & );
    CFXLocString( CFXLocString const & );
    CFXLocString( void );
   ~CFXLocString( void );
};

#endif
