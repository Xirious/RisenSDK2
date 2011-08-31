#ifndef GE_MAPLOCSTRING_H_INCLUDED
#define GE_MAPLOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCMapLocString :
    public eCLocString
{
// eCLocString
public: virtual bCString GetPrefix( void ) const;
public:
    gCMapLocString( void );
    gCMapLocString( gCMapLocString const & );
   ~gCMapLocString( void );
public:
    gCMapLocString & operator = ( gCMapLocString const & );
};
GE_ASSERT_SIZEOF( gCMapLocString, 0x000C )

#pragma warning( pop )

#endif
