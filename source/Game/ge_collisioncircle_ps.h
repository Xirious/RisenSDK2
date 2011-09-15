#ifndef GE_COLLISIONCIRCLE_PS_H_INCLUDED
#define GE_COLLISIONCIRCLE_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCCollisionCircle_PS'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCCollisionCircle_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCCollisionCircle_PS'

class GE_DLLIMPORT gCCollisionCircle_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCCollisionCircle_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual bEResult          PostInitializeProperties( void );
public: virtual GEBool            HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
public: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
public: virtual GEBool            IsReferencedByTemplate( void ) const;
public: virtual GEBool            IsEntityListener( void ) const;
public: virtual void              GetBoundary( bCBox &, GEBool );
public: virtual void              OnPostRead( void );
public: virtual GEBool            OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_PROPERTY( GEBool,                      m_bEnabledAsObstacle,   EnabledAsObstacle )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEU32,                       m_u32CircleCount,       CircleCount )
    GE_DECLARE_PROPERTY( GEFloat,                     m_fDefaultRadius,       DefaultRadius )
    GE_DECLARE_PROPERTY( bTValArray< bCVector >,      m_arrOffset,            Offset )
    GE_DECLARE_PROPERTY( bTValArray< GEFloat >,       m_arrRadius,            Radius )
    GE_DECLARE_ENUMPROP( gENavObstacleType,           m_enumType,             Type )
    GE_DECLARE_PROPERTY( bTObjArray< eCEntityProxy >, m_arrZoneEntityProxies, ZoneEntityProxies )
    gCCollisionCircle_PSObj *                         m_pPSObject;
    GE_PADDING1( 4 )
    bCDateTime                                        m_LastModificationTime;
public:
    void                      CreatePSObject( void );
    bCDateTime const &        GetLastModificationTime( void ) const;
    gCCollisionCircle_PSObj * GetPSObject( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCCollisionCircle_PS, 0x0058 )

#pragma warning( pop )

#endif
