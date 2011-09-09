#ifndef GE_LOCSTRING_H_INCLUDED
#define GE_LOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCLocString
{
public: virtual bCString GetPrefix( void ) const;
public: virtual bCString ComposeID( bCString const & ) const;
public: virtual void     Read( bCIStream & );
public: virtual void     Write( bCOStream & ) const;
protected:
    CFXLocString m_LocString;
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, eCLocString & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, eCLocString const & );
public:
    eCLocString( void );
    eCLocString( eCLocString const & );
    eCLocString( bCString const & );
   ~eCLocString( void );
public:
    eCLocString & operator =               ( eCLocString const & );
    GEBool        operator ==              ( eCLocString const & ) const;
    GEBool        operator !=              ( eCLocString const & ) const;
    bCIStream &   operator <<              ( bCIStream & );
    bCOStream &   operator >>              ( bCOStream & ) const;
                  operator bCString        ( void ) const;
                  operator bCUnicodeString ( void ) const;
public:
    GEBool          ExistsID( void ) const;
    GEBool          GenerateID( void );
    bCString        GetID( void ) const;
    bCUnicodeString GetPlainText( bCString const & ) const;
    bCUnicodeString GetPlainText( void ) const;
    bCUnicodeString GetString( bCString const & ) const;
    bCUnicodeString GetString( void ) const;
    bCUnicodeString GetText( bCString const & ) const;
    bCUnicodeString GetText( void ) const;
    GEBool          InsertText( bCString const & );
    GEBool          InsertText( bCUnicodeString const & );
    void            SetID( bCString const & );
    GEBool          SetText( bCString const & );
    GEBool          SetText( bCUnicodeString const & );
protected:
    GEBool          GenerateID( bCString const & );
};
GE_ASSERT_SIZEOF( eCLocString, 0x000C )

#pragma warning( pop )

#endif
