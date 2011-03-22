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
protected:
    GEBool          GenerateID( bCString const & );
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
public:
                  operator bCString        ( void ) const;
                  operator bCUnicodeString ( void ) const;
    GEBool        operator ==              ( eCLocString const & ) const;
    GEBool        operator !=              ( eCLocString const & ) const;
    bCIStream &   operator <<              ( bCIStream & );
    bCOStream &   operator >>              ( bCOStream & ) const;
    eCLocString & operator =               ( eCLocString const & );

public:
    eCLocString( bCString const & );
    eCLocString( eCLocString const & );
    eCLocString( void );
   ~eCLocString( void );
};
GE_ASSERT_SIZEOF( eCLocString, 0x000C )

#pragma warning( pop )

#endif
