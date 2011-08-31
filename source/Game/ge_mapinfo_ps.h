#ifndef GE_MAPINFO_PS_H_INCLUDED
#define GE_MAPINFO_PS_H_INCLUDED

class GE_DLLIMPORT gCMapInfo_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCMapInfo_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual bEResult          PostInitializeProperties( void );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
protected:
    GE_DECLARE_PROPERTY( eCGuiBitmapProxy2, m_MapImage,      MapImage )
    GE_DECLARE_PROPERTY( eCLocString,       m_locToolTip,    ToolTip )
    GE_DECLARE_PROPERTY( GEBool,            m_bCalcRotation, CalcRotation )
    GE_PADDING( 3 )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCMapInfo_PS, 0x0024 )

#endif
