#ifndef GE_STRING_H_INCLUDED
#define GE_STRING_H_INCLUDED

class GE_DLLIMPORT bCString
{
protected:
    struct bSStringData
    {
        GEU32 m_u32Length;
        GEU32 m_u32RefCount;
        GELPChar GetText( void );
    };
protected:
    GELPChar m_pcText;
protected:
    static GEInt GE_STDCALL Decrement( bSStringData * );
    static void  GE_STDCALL FreeData( bSStringData * );
    static void  GE_STDCALL Increment( bSStringData * );
    static void  GE_STDCALL Release( bSStringData * );
protected:
    void           Alloc( GEInt );
    void           ConcatCopy( GELPCChar, GEInt, GELPCChar, GEInt );
    void           ConcatInPlace( GELPCChar, GEInt );
    void           CopyBeforeWrite( void );
    void           CopyUnicode( GELPCUnicodeChar, GEInt );
    bSStringData * GetData( void ) const;
    int            GetRefCount( void ) const;
    void           Realloc( GEInt );
    void           Release( void );
public:
    static bCString GetFormattedString( GELPCChar, ... );
public:
    void            Clear( void );
    GEInt           Compare( bCString const & ) const;
    GEInt           Compare( GELPCChar ) const;
    GEBool          CompareFast( bCString const & ) const;
    GEInt           CompareNoCase( bCString const & ) const;
    GEInt           CompareNoCase( GELPCChar ) const;
    GEBool          CompareNoCaseFast( bCString const & ) const;
    GEBool          Contains( GEChar, GEInt ) const;
    GEBool          Contains( GELPCChar, GEInt ) const;
    GEBool          ContainsOneOf( GELPCChar, GEInt ) const;
    GEInt           CountWords( bCString const & ) const;
    GEInt           Delete( GEInt, GEInt );
    GEInt           Find( GEChar, GEInt, GEBool ) const;
    GEInt           Find( GELPCChar, GEInt, GEBool ) const;
    GEInt           FindNoCase( GELPCChar, GEInt ) const;
    GEInt           FindNoiseChar( GEInt, GEBool ) const;
    GEInt           FindNumericalChar( GEInt, GEBool ) const;
    GEInt           FindOneOf( GELPCChar, GEInt ) const;
    GEBool          Format( GELPCChar, ... );
    void            FreeExtra( void );
    GEInt           GetAllocLength( void ) const;
    GEChar          GetAt( GEInt, GEBool ) const;
    GEBool          GetBool( void ) const;
    GELPChar        GetBuffer( GEInt );
    GELPChar        GetBufferSetLength( GEInt );
    GEDouble        GetDouble( GEInt ) const;
    GEFloat         GetFloat( GEInt ) const;
    GEI64           GetI64( GEInt ) const;
    GEInt           GetInteger( GEInt, GEBool ) const;
    GEInt           GetLength( void ) const;
    GELPCChar       GetText( void ) const;
    bCUnicodeString GetUnicodeText( void ) const;
    GEInt           GetWord( GEInt, bCString const &, bCString &, GEBool, GEBool ) const;
    GEInt           Insert( GEInt, bCString const & );
    GEInt           Insert( GEInt, GEChar );
    GEInt           Insert( GEInt, GELPCChar );
    GEBool          IsEmpty( void ) const;
    bCString        Left( GEInt ) const;
    GELPChar        LockBuffer( void );
    bCString &      MakeLower( void );
    void            MakeReverse( void );
    bCString &      MakeUpper( void );
    bCString        Mid( GEInt ) const;
    bCString        Mid( GEInt, GEInt ) const;
    void            ReleaseBuffer( GEInt );
    GEInt           Remove( bCString const & );
    GEInt           Remove( GEChar );
    GEInt           Remove( GELPCChar );
    GEInt           Replace( GEChar, GEChar);
    GEInt           Replace( GELPCChar, GELPCChar );
    GEInt           ReverseFind( GEChar ) const;
    GEInt           ReverseFind( GEChar, GEInt ) const;
    GEInt           ReverseFind( GELPCChar ) const;
    GEInt           ReverseFind( GELPCChar, GEInt ) const;
    GEInt           ReverseFindOneOf( GELPCChar ) const;
    GEInt           ReverseFindOneOf( GELPCChar, GEInt) const;
    bCString        Right( GEInt ) const;
    GEInt           Scan( GELPCChar, ... ) const;
    void            SetAt( GEInt, GEChar );
    void            SetText( bCString const & );
    void            SetText( bCString const &, GEInt );
    void            SetText( GEChar, GEInt );
    void            SetText( GELPCChar );
    void            SetText( GELPCChar, GEInt );
    void            SetUnicodeText( bCUnicodeString const & );
    void            SetUnicodeText( bCUnicodeString const &, GEInt );
    void            SetUnicodeText( GELPCUnicodeChar, GEInt );
    void            SetUnicodeText( GELPCUnicodeChar );
    bCString        SpanExcluding( GELPCChar ) const;
    bCString        SpanIncluding( GELPCChar ) const;
    void            ToLower( void );
    void            ToUpper( void );
    void            Trim( GEChar );
    void            Trim( GELPCChar );
    void            Trim( void );
    void            Trim( GEBool, GEBool );
    void            TrimLeft( GEChar );
    void            TrimLeft( GELPCChar );
    void            TrimLeft( void );
    void            TrimRight( GEChar );
    void            TrimRight( GELPCChar );
    void            TrimRight( void );
    void            UnlockBuffer( void );
public:
    bCString & operator =         ( bCString const & );
    bCString & operator =         ( GEChar );
    bCString & operator =         ( GELPCChar );
    GEBool     operator ==        ( bCString const & ) const;
    GEBool     operator ==        ( GELPCChar ) const;
    GEBool     operator !=        ( bCString const & ) const;
    GEBool     operator !=        ( GELPCChar ) const;
    GEChar &   operator []        ( GEInt );
    GEChar     operator []        ( GEInt ) const;
    bCString   operator +         ( bCString const & ) const;
    bCString   operator +         ( GEChar ) const;
    bCString   operator +         ( GELPCChar ) const;
    GEBool     operator <         ( bCString const & ) const;
    GEBool     operator <         ( GELPCChar ) const;
    GEBool     operator <=        ( bCString const & ) const;
    GEBool     operator <=        ( GELPCChar ) const;
    GEBool     operator >         ( bCString const & ) const;
    GEBool     operator >         ( GELPCChar ) const;
    GEBool     operator >=        ( bCString const & ) const;
    GEBool     operator >=        ( GELPCChar ) const;
    bCString & operator +=        ( bCString const & );
    bCString & operator +=        ( GEChar );
    bCString & operator +=        ( GELPCChar );
               operator GELPCChar ( void ) const;
public:
    explicit bCString( bCString const &, GEInt );
    explicit bCString( bCUnicodeString const & );
    explicit bCString( GEChar, GEInt );
    explicit bCString( GEFloat, GEInt );
    explicit bCString( GELPCChar, GEInt );
             bCString( GELPCChar );
             bCString( bCString const & );
             bCString( void );
            ~bCString( void );
public:
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator == ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator != ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT bCString GE_STDCALL operator +  ( GEChar, bCString const & );
    friend GE_DLLIMPORT bCString GE_STDCALL operator +  ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator <  ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator <= ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator >  ( GELPCChar, bCString const & );
    friend GE_DLLIMPORT GEBool   GE_STDCALL operator >= ( GELPCChar, bCString const & );
};

GE_DLLIMPORT_EXTC bCString g_strDefault;

#endif
