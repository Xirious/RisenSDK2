#ifndef GE_ENTITYPROPERTYSET_H_INCLUDED
#define GE_ENTITYPROPERTYSET_H_INCLUDED

struct eSEntityListenerEvent
{
    enum eEEvent
    {
        eEEvent_ParentChanged     = 0x00000000,
        eEEvent_AttachChild       = 0x00000001,
        eEEvent_DetachChild       = 0x00000002,
        eEEvent_AddPropertySet    = 0x00000003,
        eEEvent_RemovePropertySet = 0x00000004,
        eEEvent_SetName           = 0x00000005,
        eEEvent_PortalRoomChanged = 0x00000006,
        eEEvent_ForceDWORD        = GE_FORCE_DWORD
    };
    GEI64   m_i64PropertySet;  // eCEntityPropertySet *
    eEEvent m_enumEvent;
            GE_PADDING( 4 )
};
GE_ASSERT_SIZEOF( eSEntityListenerEvent, 0x0010 )

class GE_DLLIMPORT eCEntityPropertySet :
    public bCObjectRefBase
{
public:
    enum eEPSSaveGameRelevance
    {
        //FIXME: eCEntityPropertySet::eEPSSaveGameRelevance constants.
        eEPSSaveGameRelevance_ForceDWORD = GE_FORCE_DWORD
    };

public:    virtual eEPropertySetType     GetPropertySetType( void ) const;
public:    virtual bCString const &      GetPropertySetClassName( void ) const;
public:    virtual eCEntity const *      GetEntity( void ) const;
public:    virtual eCEntity *            GetEntity( void );
public:    virtual GEBool                CanBePaused( void ) const;
public:    virtual GEBool                IsReferencedByTemplate( void ) const;
public:    virtual GEBool                IsPersistable( void ) const;
public:    virtual GEBool                IsCopyable( void ) const;
public:    virtual GEBool                IsVisual( void ) const;
public:    virtual GEBool                IsEntityListener( void ) const;
public:    virtual GEBool                IsPhysicRelevant( void ) const;
public:    virtual GEBool                IsEditorRelevant( void ) const;
public:    virtual GEBool                IsTriggerable( void ) const;
public:    virtual eCRenderContext *     CreateRenderContext( void );
public:    virtual GEBool                SupportsRenderDebugOutput( void ) const;
public:    virtual bEResult              ReadSaveGame( bCIStream & );
public:    virtual bEResult              WriteSaveGame( bCOStream & );
public:    virtual eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                  OnSaveGameEntityPostRead( void );
public:    virtual void                  GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual eCEntityPropertySet * Clone( eCEntity * ) const;
public:    virtual void                  SetEntity( eCEntity * );
protected: virtual void                  OnTrigger( eCEntity *, eCEntity * );
protected: virtual void                  OnUntrigger( eCEntity *, eCEntity * );
protected: virtual void                  OnTouch( eCEntity *, eCContactIterator & );
protected: virtual void                  OnIntersect( eCEntity *, eCContactIterator & );
protected: virtual void                  OnUntouch( eCEntity *, eCContactIterator & );
protected: virtual void                  OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
public:    virtual GEBool                IsClassProcessible( void ) const;
public:    virtual GEBool                IsClassProcessingEnabled( void ) const;
public:    virtual void                  EnableClassProcessing( GEBool );
public:    virtual void                  EnterProcessingRange( void );
public:    virtual void                  ExitProcessingRange( void );
protected: virtual void                  OnEnterProcessingRange( void );
protected: virtual void                  OnExitProcessingRange( void );
public:    virtual GEBool                IsAutoKillEnabled( void ) const;
public:    virtual eEDecayState          GetDecayState( void ) const;
public:    virtual void                  Decay( void );
public:    virtual void                  OnRenderDebug( void );
public:    virtual void                  RenderGizmo( eCCameraBase *, GEInt );
public:    virtual void                  RenderAlphaGizmo( eCCameraBase *, GEInt );
public:    virtual GEBool                PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );
public:    virtual GEBool                OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );
public:    virtual void                  GetBoundary( bCBox &, GEBool );
public:    virtual void                  OnProcess( void );
public:    virtual void                  OnPostRead( void );
public:    virtual void                  OnPostCopy( eCEntityPropertySet const & );
public:    virtual GEBool                IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;
public:    virtual GEBool                IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray< bCTriangle > *, GEBool ) const;
protected: virtual void                  OnUpdateInternals( void );
protected: virtual void                  OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected: virtual void                  OnUpdatedLocalMatrix( void );
protected: virtual void                  OnUpdatedWorldTreeBoundary( void );
protected: virtual GEBool                OnListenEntityEvent( eSEntityListenerEvent const & );
protected: virtual void                  OnCacheIn( void );
protected: virtual void                  OnCacheOut( void );
protected: virtual void                  OnPrefetch( bCVector const & );
GE_DECLARE_PROPERTY_OBJECT( eCEntityPropertySet, bCObjectRefBase )
public:    virtual GEU16                 GetVersion( void ) const;
public:    virtual GEBool                OnRead( bCIStream & );
public:    virtual GEBool                OnWrite( bCOStream & );
public:    virtual bEResult              Create( void );
public:    virtual void                  Destroy( void );
public:    virtual GEBool                OnCopyFrom( bCObjectBase const & );
protected:
    eCEntity * m_pEntity;
    GEU8       m_IsRenderingEnabled      : 1;  // GEBool
    GEU8       m_DecayState              : 3;  // eEDecayState
    GEU8       m_IsTemplateEntityAttached: 1;  // GEBool
               GE_PADDING( 3 )
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    void                     EnableRendering( GEBool );
    eCGeometryEntity *       GetGeometryEntity( void );
    eCGeometryEntity const * GetGeometryEntity( void ) const;
    eCTemplateEntity *       GetTemplateEntity( void );
    eCTemplateEntity const * GetTemplateEntity( void ) const;
    GEBool                   IsRenderingEnabled( void ) const;
    GEBool                   IsTemplateEntityAttached( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCEntityPropertySet, 0x0010 )

#endif
