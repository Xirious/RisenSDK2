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
    GEI64   m_i64PropertySet;     // 0000 // eCEntityPropertySet *
    eEEvent m_enuEvent;           // 0008
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
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                                                                                   // [0000].0000
public:    virtual GEU16                      GetVersion( void ) const;                                                                                      // [0000].0004
public:    using             bCObjectRefBase::IsValid;                                                                                                       // [0000].0008
public:    using                bCObjectBase::Deserialize;                                                                                                   // [0000].000C
public:    using                bCObjectBase::Serialize;                                                                                                     // [0000].0010
public:    using                bCObjectBase::Read;                                                                                                          // [0000].0014
public:    using                bCObjectBase::Write;                                                                                                         // [0000].0018
public:    using                bCObjectBase::OnDeserialize;                                                                                                 // [0000].001C
public:    using                bCObjectBase::OnSerialize;                                                                                                   // [0000].0020
public:    virtual GEBool                     OnRead( bCIStream & );                                                                                         // [0000].0024
public:    virtual GEBool                     OnWrite( bCOStream & );                                                                                        // [0000].0028
public:    virtual bEResult                   Create( void );                                                                                                // [0000].002C
public:    virtual void                       Destroy( void );                                                                                               // [0000].0030
public:    using                bCObjectBase::CopyFrom;                                                                                                      // [0000].0034
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );                                                                            // [0000].0038
public:    using                bCObjectBase::OnCopyPatchableOnly;                                                                                           // [0000].003C
public:    using             bCObjectRefBase::AddReference;                                                                                                  // [0000].0040
public:    using             bCObjectRefBase::ReleaseReference;                                                                                              // [0000].0044
public:    using                bCObjectBase::GetReferenceCount;                                                                                             // [0000].0048
public:    using                bCObjectBase::BindPOType;                                                                                                    // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;                                                                                      // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;                                                                                      // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;                                                                             // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;                                                                              // [0000].005C
public:    using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                                                                           // [0000].0060
public:    using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;                                                                            // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;                                                                                        // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                                                                                           // [0000].006C
public:    virtual                           ~eCEntityPropertySet( void );                                                                                   // [0000].0070
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;                                                                              // [0000].0074
public:    virtual bCString const &           GetPropertySetClassName( void ) const;                                                                         // [0000].0078
public:    virtual eCEntity *                 GetEntity( void );                                                                                             // [0000].007C
public:    virtual eCEntity const *           GetEntity( void ) const;                                                                                       // [0000].0080
public:    virtual GEBool                     CanBePaused( void ) const;                                                                                     // [0000].0084
public:    virtual GEBool                     IsReferencedByTemplate( void ) const;                                                                          // [0000].0088
public:    virtual GEBool                     IsPersistable( void ) const;                                                                                   // [0000].008C
public:    virtual GEBool                     IsCopyable( void ) const;                                                                                      // [0000].0090
public:    virtual GEBool                     IsVisual( void ) const;                                                                                        // [0000].0094
public:    virtual GEBool                     IsEntityListener( void ) const;                                                                                // [0000].0098
public:    virtual GEBool                     IsPhysicRelevant( void ) const;                                                                                // [0000].009C
public:    virtual GEBool                     IsEditorRelevant( void ) const;                                                                                // [0000].00A0
public:    virtual GEBool                     IsTriggerable( void ) const;                                                                                   // [0000].00A4
public:    virtual eCRenderContext *          CreateRenderContext( void );                                                                                   // [0000].00A8
public:    virtual GEBool                     SupportsRenderDebugOutput( void ) const;                                                                       // [0000].00AC
public:    virtual bEResult                   ReadSaveGame( bCIStream & );                                                                                   // [0000].00B0
public:    virtual bEResult                   WriteSaveGame( bCOStream & );                                                                                  // [0000].00B4
public:    virtual eEPSSaveGameRelevance      GetSaveGameRelevance( void ) const;                                                                            // [0000].00B8
public:    virtual void                       OnSaveGameEntityPostRead( void );                                                                              // [0000].00BC
public:    virtual void                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );  // [0000].00C0
public:    virtual eCEntityPropertySet *      Clone( eCEntity * ) const;                                                                                     // [0000].00C4
public:    virtual void                       SetEntity( eCEntity * );                                                                                       // [0000].00C8
protected: virtual void                       OnTrigger( eCEntity *, eCEntity * );                                                                           // [0000].00CC
protected: virtual void                       OnUntrigger( eCEntity *, eCEntity * );                                                                         // [0000].00D0
protected: virtual void                       OnTouch( eCEntity *, eCContactIterator & );                                                                    // [0000].00D4
protected: virtual void                       OnIntersect( eCEntity *, eCContactIterator & );                                                                // [0000].00D8
protected: virtual void                       OnUntouch( eCEntity *, eCContactIterator & );                                                                  // [0000].00DC
protected: virtual void                       OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );                                         // [0000].00E0
public:    virtual GEBool                     IsClassProcessible( void ) const;                                                                              // [0000].00E4
public:    virtual GEBool                     IsClassProcessingEnabled( void ) const;                                                                        // [0000].00E8
public:    virtual void                       EnableClassProcessing( GEBool );                                                                               // [0000].00EC
public:    virtual void                       EnterProcessingRange( void );                                                                                  // [0000].00F0
public:    virtual void                       ExitProcessingRange( void );                                                                                   // [0000].00F4
protected: virtual void                       OnEnterProcessingRange( void );                                                                                // [0000].00F8
protected: virtual void                       OnExitProcessingRange( void );                                                                                 // [0000].00FC
public:    virtual GEBool                     IsAutoKillEnabled( void ) const;                                                                               // [0000].0100
public:    virtual eEDecayState               GetDecayState( void ) const;                                                                                   // [0000].0104
public:    virtual void                       Decay( void );                                                                                                 // [0000].0108
public:    virtual void                       OnRenderDebug( void );                                                                                         // [0000].010C
public:    virtual void                       RenderGizmo( eCCameraBase *, GEInt );                                                                          // [0000].0110
public:    virtual void                       RenderAlphaGizmo( eCCameraBase *, GEInt );                                                                     // [0000].0114
public:    virtual GEBool                     PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );                                                // [0000].0118
public:    virtual GEBool                     OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );                       // [0000].011C
public:    virtual void                       GetBoundary( bCBox &, GEBool );                                                                                // [0000].0120
public:    virtual void                       OnProcess( void );                                                                                             // [0000].0124
public:    virtual void                       OnPostRead( void );                                                                                            // [0000].0128
public:    virtual void                       OnPostCopy( eCEntityPropertySet const & );                                                                     // [0000].012C
public:    virtual GEBool                     IntersectsRay( eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc * * ) const;                         // [0000].0130
public:    virtual GEBool                     IntersectsVolume( bCVolume &, bCMatrix const &, bTValArray< bCTriangle > *, GEBool ) const;                    // [0000].0134
protected: virtual void                       OnUpdateInternals( void );                                                                                     // [0000].0138
protected: virtual void                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );                                                    // [0000].013C
protected: virtual void                       OnUpdatedLocalMatrix( void );                                                                                  // [0000].0140
protected: virtual void                       OnUpdatedWorldTreeBoundary( void );                                                                            // [0000].0144
protected: virtual GEBool                     OnListenEntityEvent( eSEntityListenerEvent const & );                                                          // [0000].0148
protected: virtual void                       OnCacheIn( void );                                                                                             // [0000].014C
protected: virtual void                       OnCacheOut( void );                                                                                            // [0000].0150
protected: virtual void                       OnPrefetch( bCVector const & );                                                                                // [0000].0154
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    eCEntity * m_pEntity;                      // 0008
    GEU8       m_IsRenderingEnabled      : 1;  // 000C // GEBool
    GEU8       m_DecayState              : 3;  // 000C // eEDecayState
    GEU8       m_IsTemplateEntityAttached: 1;  // 000C // GEBool
               GE_PADDING( 3 )
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                     EnableRendering( GEBool );
    eCGeometryEntity *       GetGeometryEntity( void );
    eCGeometryEntity const * GetGeometryEntity( void ) const;
    eCTemplateEntity *       GetTemplateEntity( void );
    eCTemplateEntity const * GetTemplateEntity( void ) const;
    GEBool                   IsRenderingEnabled( void ) const;
    GEBool                   IsTemplateEntityAttached( void ) const;
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    eCEntityPropertySet & operator = ( eCEntityPropertySet const & );
public:
    eCEntityPropertySet( eCEntityPropertySet const & );
    eCEntityPropertySet( void );
};
GE_ASSERT_SIZEOF( eCEntityPropertySet, 0x0010 )

#endif
