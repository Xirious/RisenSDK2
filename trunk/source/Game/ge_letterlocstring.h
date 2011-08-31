#ifndef GE_LETTERLOCSTRING_H_INCLUDED
#define GE_LETTERLOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCLetterLocString :
    public eCLocString
{
// eCLocString
public: virtual bCString GetPrefix( void ) const;
public:
    gCLetterLocString( void );
    gCLetterLocString( gCLetterLocString const & );
   ~gCLetterLocString( void );
public:
    gCLetterLocString & operator = ( gCLetterLocString const & );
};
GE_ASSERT_SIZEOF( gCLetterLocString, 0x000C )

#pragma warning( pop )

#endif
