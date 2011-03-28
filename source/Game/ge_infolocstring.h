#ifndef GE_INFOLOCSTRING_H_INCLUDED
#define GE_INFOLOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCInfoLocString :
    public eCLocString
{
public: virtual bCString GetPrefix( void ) const;
public: virtual bCString ComposeID( bCString const & ) const;
public:
    bCUnicodeString GetStageDirection( void ) const;
    void            SetStageDirection( bCUnicodeString const & );
public:
    gCInfoLocString & operator = ( gCInfoLocString const & );
public:
    gCInfoLocString( gCInfoLocString const & );
    gCInfoLocString( void );
   ~gCInfoLocString( void );
};
GE_ASSERT_SIZEOF( gCInfoLocString, 0x000C )

#pragma warning( pop )

#endif
