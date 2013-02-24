#ifndef GE_GIZMOBASE_H_INCLUDED
#define GE_GIZMOBASE_H_INCLUDED

enum eEGizmoType
{
	eEGizmoType_Undefined,
	eEGizmoType_TranslateAndScale,
	eEGizmoType_TranslateAndScaleBox,
	eEGizmoType_TranslateAndScaleSphere,
	eEGizmoType_Transform,
	eEGizmoType_TransformOBB,
	eEGizmoType_TransformOBBCollisionShape,
	eEGizmoType_TransformCapsule,
	eEGizmoType_TransformCapsuleCollisionShape,
	eEGizmoType_TransformSphere,
	eEGizmoType_TransformSphereCollisionShape,
	eEGizmoType_Count
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'eCGizmoBase'

class GE_DLLIMPORT eCGizmoBase
{
public:    virtual GEBool        Pick( bCMatrix const &, eSRayIntersectionDesc &, eSGizmoPickInfo * );
public:    virtual GEBool        OnMove( bCMatrix const &, eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat );
public:    virtual void          Render( bCMatrix const & );
public:    virtual void          RenderAlpha( bCMatrix const & );
public:    virtual void          RenderShape( bCMatrix const & );
public:    virtual void          Destroy( void );
public:    virtual GEBool        Create( void );
public:    virtual eCGizmoBase * Clone( void );
protected: virtual              ~eCGizmoBase( void );
public:
    static void                         GE_STDCALL EnableGizmoForEntity( GEBool );
    static void                         GE_STDCALL EnableGizmoForPropertySet( eEPropertySetType, GEBool );
    static void                         GE_STDCALL EnableGizmoForPropertySets( GEBool );
    static bTValArray< GEBool > const & GE_STDCALL GetGizmoForPropertySetEnabled( void );
    static eCGizmoBase *                GE_STDCALL GetInstance( eEGizmoType );
    static GEInt                        GE_STDCALL GetLastHelperIndex( void );
    static GEInt                        GE_STDCALL GetMouseDeltaX( void );
    static eETransformSpace             GE_STDCALL GetTransformSpace( void );
    static void                         GE_STDCALL InitializeGizmoForPropertySet( void );
    static GEBool                       GE_STDCALL IsApplyToTemplateEnabled( void );
    static GEBool                       GE_STDCALL IsGizmoForEntityEnabled( void );
    static GEBool                       GE_STDCALL IsGizmoForPropertySetEnabled( eEPropertySetType );
    static GEBool                       GE_STDCALL IsGizmoForPropertySetsEnabled( void );
    static void                         GE_STDCALL SetApplyToTemplateEnabled( GEBool );
    static void                         GE_STDCALL SetLastHelperIndex( GEInt );
    static void                         GE_STDCALL SetMouseDeltaX( GEInt );
    static void                         GE_STDCALL SetTransformSpace( eETransformSpace );
public:
    eCGizmoBase( eCGizmoBase const & );
public:
    eCGizmoBase & operator = ( eCGizmoBase const & );
protected:
    static bTValArray< GEBool > s_arrGizmoForPropertySetEnabled;
    static GEBool               s_bApplyToTemplateEnabled;
    static GEBool               s_bGizmoForEntityEnabled;
    static GEBool               s_bGizmoForPropertySetsEnabled;
    static eETransformSpace     s_eTransformSpace;
    static GEInt                s_iLastHelperIndex;
    static GEInt                s_iMouseDeltaX;
protected:
    eCGizmoBase( void );
protected:
    void Invalidate( void );
protected:
    bTValArray< eCIteratorPrimitive * > m_arrIteratorPrimitives;
};
GE_ASSERT_SIZEOF( eCGizmoBase, 0x0010 );

#pragma warning( pop )

#endif
