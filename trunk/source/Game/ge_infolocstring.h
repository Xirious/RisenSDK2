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
    gCInfoLocString( void );
    gCInfoLocString( gCInfoLocString const & );
   ~gCInfoLocString( void );
public:
    gCInfoLocString & operator = ( gCInfoLocString const & );
public:
    bCUnicodeString GetStageDirection( void ) const;
    void            SetStageDirection( bCUnicodeString const & );
};
GE_ASSERT_SIZEOF( gCInfoLocString, 0x000C )

#pragma warning( pop )

#endif
