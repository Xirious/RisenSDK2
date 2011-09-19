#ifndef GE_MAPENTRY_H_INCLUDED
#define GE_MAPENTRY_H_INCLUDED

class GE_DLLIMPORT gCMapEntry :
    public bCObjectBase
{
GE_DECLARE_PROPERTY_OBJECT( gCMapEntry, bCObjectBase )
public: virtual ~gCMapEntry( void );
public:
    GE_DECLARE_PROPERTY( eCEntityStringProxy, m_Entity,  Entity )
    GE_DECLARE_PROPERTY( eCGuiBitmapProxy2,   m_Overlay, Overlay )
public:
    gCMapEntry( bCString const &, bCString const & );
public:
    GEBool operator == ( gCMapEntry const & ) const;
};
GE_ASSERT_SIZEOF( gCMapEntry, 0x0010 )

#endif
