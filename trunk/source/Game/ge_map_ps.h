#ifndef GE_MAP_PS_H_INCLUDED
#define GE_MAP_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCMap_PS'

class GE_DLLIMPORT gCMap_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCMap_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual bEResult          PostInitializeProperties( void );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
protected:
    GE_DECLARE_PROPERTY( bTObjArray< gCMapEntry >, m_arrMarker,          Marker )
    GE_DECLARE_PROPERTY( eCLocString,              m_locTitle,           Title )
    GE_DECLARE_PROPERTY( eCGuiBitmapProxy2,        m_Image,              Image )
    GE_DECLARE_PROPERTY( eCGuiBitmapProxy2,        m_DefaultMarkerImage, DefaultMarkerImage )
    GE_DECLARE_PROPERTY( bCVector2,                m_vecMapTopLeft,      MapTopLeft )
    GE_DECLARE_PROPERTY( bCVector2,                m_vecMapBottomRight,  MapBottomRight )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,      m_CanUse,             CanUse )
    GE_DECLARE_PROPERTY( GEU32,                    m_u32Priority,        Priority )
public:
    GEBool          CalcMarkerData( GEInt, GEFloat &, GEFloat &, GEFloat & ) const;
    GEBool          CanUse( void ) const;
    GEBool          ContainsContent( void ) const;
    GEBool          ContainsEntity( GEInt ) const;
    GEBool          ContainsEntity( bCString const & ) const;
    GEBool          ContainsEntity( bTObjArray< gCMapEntry > const & ) const;
    GEBool          ContainsQuest( bCString const & ) const;
    GEFloat         GetImageAspectRatio( void ) const;
    bCUnicodeString GetInfo( GEFloat, GEFloat, bCRect const & ) const;
    GEInt           GetMarkerCount( void ) const;
    GEBool          GetMarkerEntity( GEInt, eCEntity * * ) const;
    GEBool          GetMarkerImage( GEInt, eCDeferredGuiBitmap2 * *, eCDeferredGuiBitmap2 * * ) const;
    bCUnicodeString GetMarkerInfo( GEInt ) const;
    GEFloat         GetWorldAspectRatio( void ) const;
    GEI32           GetWorldSize( void ) const;
    GEBool          InsertEntity( bCString const &, bCString const & );
    GEBool          InsertQuest( bCString const & );
    GEBool          RemoveEntity( bCString const &, bCString const & );
    GEBool          RemoveQuest( bCString const & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCMap_PS, 0x004C )

#pragma warning( pop )

#endif
