#ifndef GE_AREA_STRINGPROPERTY_PS_H_INCLUDED
#define GE_AREA_STRINGPROPERTY_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCArea_StringProperty_PS'

class GE_DLLIMPORT eCArea_StringProperty_PS :
    public eCEntityPropertySet
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~eCArea_StringProperty_PS( void );
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;
public:    virtual GEBool                     IsReferencedByTemplate( void ) const;
protected: virtual GEBool                     IsEntityListener( void ) const;
protected: virtual void                       OnRenderDebug( void );
public:    virtual void                       RenderGizmo( eCCameraBase *, GEInt );
public:    virtual void                       RenderAlphaGizmo( eCCameraBase *, GEInt );
public:    virtual GEBool                     PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );
public:    virtual GEBool                     OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );
protected: virtual void                       GetBoundary( bCBox &, GEBool );
public:    virtual void                       OnPostRead( void );
protected: virtual GEBool                     IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
protected: virtual GEBool                     OnListenEntityEvent( eSEntityListenerEvent const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    static eCPrimitiveWeatherZoneBox ms_BoxPrimitive;
protected:
    bCRange3               m_AreaBox;
    bTObjArray< bCString > m_arrPropertyNameList;
protected:
    void    GetGizmoData( GELPVoid );
    GEFloat GetGizmoScaling( eCCameraBase * );
    void    GetGizmoTrafoSpaceWorldMatrix( eCCameraBase *, bCMatrix & );
    void    Invalidate( void );
    void    SetGizmoData( GELPVoid );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCRange3 &                     AccessAreaBox( void );
    bTObjArray< bCString > &       AccessPropertyNameList( void );
    GEBool                         Contains( bCVector const & );
    bCRange3 const &               GetAreaBox( void ) const;
    GEFloat                        GetDistanceTo( bCVector const & );
    bTObjArray< bCString > const & GetPropertyNameList( void ) const;
    void                           SetAreaBox( bCRange3 const & );
    void                           SetPropertyNameList( bTObjArray< bCString > const & );
public:
    eCArea_StringProperty_PS & operator = ( eCArea_StringProperty_PS const & );
public:
    eCArea_StringProperty_PS( eCArea_StringProperty_PS const & );
    eCArea_StringProperty_PS( void );
};
GE_ASSERT_SIZEOF( eCArea_StringProperty_PS, 0x0034 )

#pragma warning( pop )

#endif
