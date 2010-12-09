#ifndef GE_UNICODESTRING_H_INCLUDED
#define GE_UNICODESTRING_H_INCLUDED

class GE_DLLIMPORT bCUnicodeString
{
protected:
    struct bSUnicodeStringData
    {
        GEInt m_iRefCount;
        GEInt m_iLength;
        GEInt m_iAllocLength;
        GELPUnicodeChar GetText( void );
    };
protected:
    GELPUnicodeChar m_pwText;
protected:
    static GEInt GE_STDCALL Decrement( bSUnicodeStringData * );
    static void  GE_STDCALL FreeData( bSUnicodeStringData * );
    static void  GE_STDCALL Increment( bSUnicodeStringData * );
    static void  GE_STDCALL Release( bSUnicodeStringData * );
protected:
    void                  Alloc( GEInt );
    void                  ConcatCopy( GELPCUnicodeChar, GEInt, GELPCUnicodeChar, GEInt );
    void                  ConcatInPlace( GELPCUnicodeChar, GEInt );
    void                  CopyAnsi( GELPCChar, GEInt );
    void                  CopyBeforeWrite( void );
    bSUnicodeStringData * GetData( void ) const;
    GEInt                 GetRefCount( void ) const;
    void                  Realloc( GEInt );
    void                  Release( void );
public:
    static bCUnicodeString GetFormattedString( GELPCUnicodeChar, ... );
public:
    void             Clear( void );
    GEInt            Compare( bCUnicodeString const & ) const;
    GEInt            Compare( GELPCUnicodeChar ) const;
    GEInt            CompareNoCase( bCUnicodeString const & ) const;
    GEInt            CompareNoCase( GELPCUnicodeChar ) const;
    GEBool           Contains( GELPCUnicodeChar, GEInt ) const;
    GEBool           Contains( GEUnicodeChar, GEInt ) const;
    GEBool           ContainsOneOf( GELPCUnicodeChar, GEInt ) const;
    GEInt            CountWords( bCUnicodeString const & ) const;
    GEInt            Delete( GEInt, GEInt );
    GEInt            Find( GELPCUnicodeChar, GEInt ) const;
    GEInt            Find( GEUnicodeChar, GEInt ) const;
    GEInt            FindOneOf( GELPCUnicodeChar, GEInt ) const;
    void             Format( GELPCUnicodeChar, ... );
    void             FreeExtra( void );
    GEInt            GetAllocLength( void ) const;
    bCString         GetAnsiText( void ) const;
    bCString         GetAsHexCodedString( void ) const;
    GEUnicodeChar    GetAt( GEInt ) const;
    GEBool           GetBool( void ) const;
    GELPUnicodeChar  GetBuffer( GEInt );
    GELPUnicodeChar  GetBufferSetLength( GEInt );
    GEDouble         GetDouble( void ) const;
    GEFloat          GetFloat( void ) const;
    GEInt            GetInteger( void ) const;
    GEInt            GetLength( void ) const;
    GELPUnicodeChar  GetText( void );
    GELPCUnicodeChar GetText( void ) const;
    GEInt            GetWord( GEInt, bCUnicodeString const &, bCUnicodeString &, GEBool, GEBool ) const;
    GEInt            Insert( GEInt, bCUnicodeString const & );
    GEInt            Insert( GEInt, GELPCUnicodeChar );
    GEInt            Insert( GEInt, GEUnicodeChar );
    GEBool           IsAnsiText( void ) const;
    GEBool           IsEmpty( void ) const;
    bCUnicodeString  Left( GEInt ) const;
    GELPUnicodeChar  LockBuffer( void );
    void             MakeLower( void );
    void             MakeReverse( void );
    void             MakeUpper( void );
    bCUnicodeString  Mid( GEInt ) const;
    bCUnicodeString  Mid( GEInt, GEInt ) const;
    void             ReleaseBuffer( GEInt );
    GEInt            Remove( GELPCUnicodeChar);
    GEInt            Remove( GEUnicodeChar );
    GEInt            Replace( GELPCUnicodeChar, GELPCUnicodeChar );
    GEInt            Replace( GEUnicodeChar, GEUnicodeChar );
    GEInt            ReverseFind( GELPCUnicodeChar ) const;
    GEInt            ReverseFind( GELPCUnicodeChar, GEInt ) const;
    GEInt            ReverseFind( GEUnicodeChar ) const;
    GEInt            ReverseFind( GEUnicodeChar, GEInt ) const;
    GEInt            ReverseFindOneOf( GELPCUnicodeChar ) const;
    GEInt            ReverseFindOneOf( GELPCUnicodeChar, GEInt ) const;
    bCUnicodeString  Right( GEInt ) const;
    void             SetAnsiText( bCString const & );
    void             SetAnsiText( bCString const &, GEInt );
    void             SetAnsiText( GELPCChar );
    void             SetAnsiText( GELPCChar, GEInt );
    void             SetAt( GEInt, GEUnicodeChar );
    GEBool           SetFromHexCodedString( bCString const & );
    void             SetText(bCUnicodeString const & );
    void             SetText(bCUnicodeString const &, GEInt );
    void             SetText( GELPCUnicodeChar );
    void             SetText( GELPCUnicodeChar, GEInt );
    void             SetText( GEUnicodeChar, GEInt );
    bCUnicodeString  SpanExcluding( GELPCUnicodeChar ) const;
    bCUnicodeString  SpanIncluding( GELPCUnicodeChar ) const;
    GEU32            Split( bCUnicodeString &, bTObjArray< bCUnicodeString > * );
    void             ToLower( void );
    void             ToUpper( void );
    void             Trim( GELPCUnicodeChar );
    void             Trim( void );
    void             Trim( GEBool, GEBool );
    void             Trim( GEUnicodeChar );
    void             TrimLeft( GELPCUnicodeChar );
    void             TrimLeft( void );
    void             TrimLeft( GEUnicodeChar );
    void             TrimRight( GELPCUnicodeChar );
    void             TrimRight( void );
    void             TrimRight( GEUnicodeChar );
    void             UnlockBuffer( void );
public:
    bCUnicodeString & operator =                ( bCUnicodeString const & );
    bCUnicodeString & operator =                ( GELPCChar );
    bCUnicodeString & operator =                ( GELPCUnicodeChar );
    bCUnicodeString & operator =                ( GEUnicodeChar );
    GEBool            operator ==               ( bCUnicodeString const & ) const;
    GEBool            operator ==               ( GELPCUnicodeChar ) const;
    GEBool            operator !=               ( bCUnicodeString const & ) const;
    GEBool            operator !=               ( GELPCUnicodeChar ) const;
    GEUnicodeChar &   operator []               ( GEInt );
    GEUnicodeChar     operator []               ( GEInt ) const;
    bCUnicodeString   operator +                ( bCUnicodeString const & ) const;
    bCUnicodeString   operator +                ( GELPCUnicodeChar ) const;
    bCUnicodeString   operator +                ( GEUnicodeChar ) const;
    GEBool            operator <                ( bCUnicodeString const & ) const;
    GEBool            operator <                ( GELPCUnicodeChar ) const;
    GEBool            operator <=               ( bCUnicodeString const & ) const;
    GEBool            operator <=               ( GELPCUnicodeChar ) const;
    GEBool            operator >                ( bCUnicodeString const & ) const;
    GEBool            operator >                ( GELPCUnicodeChar ) const;
    GEBool            operator >=               ( bCUnicodeString const & ) const;
    GEBool            operator >=               ( GELPCUnicodeChar ) const;
    bCUnicodeString & operator +=               ( bCUnicodeString const & );
    bCUnicodeString & operator +=               ( GELPCUnicodeChar );
    bCUnicodeString & operator +=               ( GEUnicodeChar );
                      operator GELPUnicodeChar  ( void );
                      operator GELPCUnicodeChar ( void ) const;
public:
    explicit bCUnicodeString( bCUnicodeString const &, GEInt );
    explicit bCUnicodeString( GEInt );
    explicit bCUnicodeString( GEI32 );
    explicit bCUnicodeString( GEU32 );
    explicit bCUnicodeString( GEFloat, GEInt );
    explicit bCUnicodeString( GELPCChar );
    explicit bCUnicodeString( GELPCChar, GEInt );
    explicit bCUnicodeString( GELPCUnicodeChar, GEInt );
    explicit bCUnicodeString( GEUnicodeChar, GEInt );
             bCUnicodeString( GELPCUnicodeChar );
             bCUnicodeString( bCUnicodeString const & );
             bCUnicodeString( void );
            ~bCUnicodeString( void );
public:
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator == ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator != ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT bCUnicodeString GE_STDCALL operator +  ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT bCUnicodeString GE_STDCALL operator +  ( GEUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator <  ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator <= ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator >  ( GELPCUnicodeChar, bCUnicodeString const & );
    friend GE_DLLIMPORT GEBool          GE_STDCALL operator >= ( GELPCUnicodeChar, bCUnicodeString const & );
};

#endif
