#ifndef GE_NEGZONE_PS_H_INCLUDED
#define GE_NEGZONE_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCNegZone_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCNegZone_PS'

class GE_DLLIMPORT gCNegZone_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCNegZone_PS, eCEntityPropertySet )
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
    GE_DECLARE_PROPERTY( GEFloat,                m_fRadius,           Radius )
    GE_DECLARE_PROPERTY( bCVector,               m_vecRadiusOffset,   RadiusOffset )
    GE_DECLARE_PROPERTY( GEBool,                 m_bZoneIsCCW,        ZoneIsCCW )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( eCEntityProxy,          m_ZoneEntityProxy,   ZoneEntityProxy )
    GE_DECLARE_ENUMPROP( gENavTestResult,        m_enumNavTestResult, NavTestResult )
    gCNegZone_PSObj *                            m_pPSObject;
    GE_PADDING1( 4 )
    bCDateTime                                   m_LastModificationTime;
public:
    bEResult           AddLeftAndRightAngle( bCVector &, bCVector &, GEFloat &, GEFloat & );
    void               CreatePSObject( void );
    bEResult           GetAngleSums( GEFloat &, GEFloat & );
    bCDateTime const & GetLastModificationTime( void ) const;
    gCNegZone_PSObj *  GetPSObject( void ) const;
    GEBool             IsZoneIllegal( GEBool ) const;
    void               OnStakesChanged( void );
    GEBool             Test3DPointInZone( bCVector const &, GEBool );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCNegZone_PS, 0x0050 )

#pragma warning( pop )

#endif
