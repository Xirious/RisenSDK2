#ifndef FX_LOCSTRING_H_INCLUDED
#define FX_LOCSTRING_H_INCLUDED

class GE_DLLIMPORT CFXLocString :
    public CFXTableItem
{
protected:
    bCUnicodeString m_strKey;  // 0004
    // sizeof(CFXLocString)       0008
protected:
    GEBool IsModified( void ) const;
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
    GEBool          InsertText( bCString const & );
    GEBool          InsertText( bCUnicodeString const &, bCUnicodeString const & );
    GEBool          InsertText( bCUnicodeString const & );
    GEBool          IsAttached( void ) const;
    GEBool          IsKeyValid( void ) const;
    void            SetKey( bCString const & );
    void            SetKey( bCUnicodeString const & );
    GEBool          SetText( bCString const & );
    GEBool          SetText( bCUnicodeString const & );
    GEBool          SetText( bCUnicodeString const &, bCUnicodeString const & );
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
