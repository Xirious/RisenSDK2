#ifndef GE_SPLASH_H_INCLUDED
#define GE_SPLASH_H_INCLUDED

class GE_DLLIMPORT eCSplash
{
public: virtual ~eCSplash( void );
protected:
    HWND     m_hWindow;
    GEU32    m_u32TransparentColor;
    GEInt    m_iWidth;
    GEInt    m_iHeight;
    HGDIOBJ  m_hBitmap;
    bCString m_strClassName;
private:
    GEBool MakeTransparent( void );
    HWND   RegAndCreateWindow( void );
    void   FreeResources( void );
    void   Invalidate( void );
    void   OnPaint( HWND );
public:
    GEBool           SetTransparentColor( GEU32 );
    GEI32 GE_STDCALL WindowProc( HWND, GEUInt, GEUInt, GEI32 );
    GEInt            Close( void );
    GEInt            DoLoop( void );
    GEU32            SetBitmap( HBITMAP );
    GEU32            SetBitmap( bCString const & );
    void             Show( void );
public:
    eCSplash & operator = ( eCSplash const & );
public:
    eCSplash( bCString const &, GEU32 );
    eCSplash( eCSplash const & );
    eCSplash( void );
};
GE_ASSERT_SIZEOF( eCSplash, 0x001C )

#endif
