#ifndef GE_DATETIME_H_INCLUDED
#define GE_DATETIME_H_INCLUDED

typedef struct tagUI_FILETIME {
    union
    {
        GEU64      m_u64DateTime;
        bSFileTime m_FileTime;
    };
    GEU64 GetDateTime( void ) const;
} bSUIFileTime;

class GE_DLLIMPORT bCDateTime
{
private:
    GEU64 m_u64DateTime;
protected:
    void Clear( void );
    void Init( void );
public:
    GEU64 & AccessDateTime( void );
    void    Add( bCDateTime const & );
    void    CopyFrom( bCDateTime const & );
    void    CopyTo( bCDateTime & ) const;
    void    GetDateString( bCString & ) const;
    void    GetDateStringW( bCUnicodeString & ) const;
    void    GetDateTime( GEU64 & ) const;
    GEU64   GetDateTime( void ) const;
    void    GetShortDateString( bCString & ) const;
    void    GetTimeString( bCString & ) const;
    void    SetDateTime( GEU64 );
    void    SetDateTime( bSUIFileTime const & );
    void    Sub( bCDateTime const & );
    void    Update( void );
public:
    bCDateTime const & operator =                  ( bSUIFileTime const & );
    bCDateTime const & operator =                  ( bCDateTime const & );
    bCDateTime const & operator +=                 ( bCDateTime const & );
    bCDateTime const & operator -=                 ( bCDateTime const & );
    bCDateTime         operator +                  ( bCDateTime const & ) const;
    bCDateTime         operator -                  ( bCDateTime const & ) const;
    GEBool             operator !=                 ( bCDateTime const & ) const;
    GEBool             operator <                  ( bCDateTime const & ) const;
    GEBool             operator <=                 ( bCDateTime const & ) const;
    GEBool             operator ==                 ( bCDateTime const & ) const;
    GEBool             operator >                  ( bCDateTime const & ) const;
    GEBool             operator >=                 ( bCDateTime const & ) const;
                       operator bSUIFileTime const ( void ) const;
                       operator bSUIFileTime       ( void );
public:
    explicit bCDateTime( GEU64 );
    explicit bCDateTime( bSUIFileTime const & );
             bCDateTime( bCDateTime const & );
             bCDateTime( void );
            ~bCDateTime( void );
};

#endif
