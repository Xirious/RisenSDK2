#ifndef GE_QUESTLOCSTRING_H_INCLUDED
#define GE_QUESTLOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCQuestLocString :
    public eCLocString
{
public: virtual bCString GetPrefix( void ) const;
public:
    gCQuestLocString & operator = ( gCQuestLocString const & );
public:
    gCQuestLocString( gCQuestLocString const & );
    gCQuestLocString( void );
   ~gCQuestLocString( void );
};
GE_ASSERT_SIZEOF( gCQuestLocString, 0x000C )

#pragma warning( pop )

#endif