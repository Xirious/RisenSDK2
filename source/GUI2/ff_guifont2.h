#ifndef FF_GUIFONT2_H_INCLUDED
#define FF_GUIFONT2_H_INCLUDED

FF_DECLARE_INTERFACE( IFFGuiFont2, "{4BB61C96-D3FB-4DD4-9ADA-68271D74300F}" ) :
    virtual public IFFUnknown
{
public: virtual bCString        GetFontNameA( void ) const = 0;  
public: virtual bCUnicodeString GetFontNameW( void ) const = 0;  
protected:
    // sizeof(IFFGuiFont2) 000C
};

#endif
