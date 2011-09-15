#ifndef GE_PREFPATH_PS_H_INCLUDED
#define GE_PREFPATH_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCPrefPath_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCPrefPath_PS'

class GE_DLLIMPORT gCPrefPath_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCPrefPath_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
protected: virtual GEBool            HandleDeprecatedProperty( bCString const &, bCString const &, bCIStream & );
protected: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsReferencedByTemplate( void ) const;
public:    virtual GEBool            IsEntityListener( void ) const;
public:    virtual void              GetBoundary( bCBox &, GEBool );
public:    virtual GEBool            OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_PROPERTY( bTValArray< bCVector >, m_arrPoint,          Point )
    GE_DECLARE_PROPERTY( bTValArray< GEFloat >,  m_arrPointRadius,    PointRadius )
    GE_DECLARE_PROPERTY( GEFloat,                m_fRadius,           Radius )
    GE_DECLARE_PROPERTY( bCVector,               m_vecRadiusOffset,   RadiusOffset )
    GE_DECLARE_PROPERTY( eCEntityProxy,          m_ZoneEntityProxy,   ZoneEntityProxy )
    GE_DECLARE_ENUMPROP( gENavTestResult,        m_enumNavTestResult, NavTestResult )
    gCPrefPath_PSObj *                           m_pPSObject;
    GE_PADDING( 4 )
    bCDateTime                                   m_LastModificationTime;
public:
    void               CreatePSObject( void );
    bCDateTime const & GetLastModificationTime( void ) const;
    gCPrefPath_PSObj * GetPSObject( void ) const;
    GEBool             IsPathIllegal( GEBool ) const;
    GEBool             Test3DPointOnPath( bCVector const & ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCPrefPath_PS, 0x0058 )

#pragma warning( pop )

#endif
