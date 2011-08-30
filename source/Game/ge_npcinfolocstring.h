#ifndef GE_NPCINFOLOCSTRING_H_INCLUDED
#define GE_NPCINFOLOCSTRING_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT gCNPCInfoLocString :
    public eCLocString
{
public: virtual bCString GetPrefix( void ) const;
public:
    gCNPCInfoLocString( void );
    gCNPCInfoLocString( gCNPCInfoLocString const & );
   ~gCNPCInfoLocString( void );
public:
    gCNPCInfoLocString & operator = ( gCNPCInfoLocString const & );
};
GE_ASSERT_SIZEOF( gCNPCInfoLocString, 0x000C )

#pragma warning( pop )

#endif
