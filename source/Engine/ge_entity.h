#ifndef GE_ENTITY_H_INCLUDED
#define GE_ENTITY_H_INCLUDED

struct eSEntityFlags
{
    GEU32 m_Locked            : 1;  // 00000001 0
    GEU32 m_RenderingEnabled  : 1;  // 00000002 1
    GEU32 m_Enabled           : 1;  // 00000004 2
    GEU32 m_Killed            : 1;  // 00000008 3
    GEU32 m_InProcessingRange : 1;  // 00000010 4
    GEU32 m_CachedIn          : 1;  // 00000020 5
    GEU32 m_EventsEnabled     : 1;  // 00000040 6
    GEU32 m_PickingEnabled    : 1;  // 00000080 7
    GEU32 m_CollisionEnabled  : 1;  // 00000100 8
    GEU32 __FIXME_9           : 1;  // 00000200 9
    GEU32 m_InsertType        : 4;  // 00003C00 10..13 // eCEntity::eEInsertType
    GEU32 __FIXME_14          : 1;  // 00004000 14
    GEU32 __FIXME_15          : 1;  // 00008000 15
    GEU32 __FIXME_16          : 1;  // 00010000 16
    GEU32 m_IsDynamic         : 1;  // 00020000 17
    GEU32 __FIXME_18          : 1;  // 00040000 18
    GEU32 m_IsSaveGameRelevant: 1;  // 00080000 19
    GEU32 m_IsTemporary       : 1;  // 00100000 20
    GEU32 __FIXME_21          : 1;  // 00200000 21
    GEU32 __FIXME_22          : 1;  // 00400000 22
    GEU32 __FIXME_23          : 1;  // 00800000 23
    GEU32 __FIXME             : 8;  // FF000000 24..31
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTRefPtrArray<>' needs to have dll-interface to be used by clients of class 'eCEntity'

class GE_DLLIMPORT eCEntity :
    public eCNode
{
public:
    enum eEInsertType
    {
        eEInsertType_None       = 0x00000000,
        eEInsertType_Floor      = 0x00000001,
        eEInsertType_Ground     = 0x00000002,
        eEInsertType_Tree       = 0x00000003,
        eEInsertType_Wall       = 0x00000004,
        eEInsertType_Arrow      = 0x00000005,
        eEInsertType_Manual     = 0x00000006,
        eEInsertType_ForceDWORD = GE_FORCE_DWORD
    };
public:    using                    eCNode::GetObjectType;                                                                            // [0000].0000
public:    virtual GEU16                    GetVersion( void ) const;                                                                 // [0000].0004
public:    using                    eCNode::IsValid;                                                                                  // [0000].0008
public:    using              bCObjectBase::Deserialize;                                                                              // [0000].000C
public:    using              bCObjectBase::Serialize;                                                                                // [0000].0010
public:    using              bCObjectBase::Read;                                                                                     // [0000].0014
public:    using              bCObjectBase::Write;                                                                                    // [0000].0018
public:    using              bCObjectBase::OnDeserialize;                                                                            // [0000].001C
public:    using              bCObjectBase::OnSerialize;                                                                              // [0000].0020
public:    virtual GEBool                   OnRead( bCIStream & );                                                                    // [0000].0024
public:    virtual GEBool                   OnWrite( bCOStream & );                                                                   // [0000].0028
public:    virtual bEResult                 Create( void );                                                                           // [0000].002C
public:    virtual void                     Destroy( void );                                                                          // [0000].0030
public:    using              bCObjectBase::CopyFrom;                                                                                 // [0000].0034
public:    virtual GEBool                   OnCopyFrom( bCObjectBase const & );                                                       // [0000].0038
public:    using              bCObjectBase::OnCopyPatchableOnly;                                                                      // [0000].003C
public:    using           bCObjectRefBase::AddReference;                                                                             // [0000].0040
public:    using                    eCNode::ReleaseReference;                                                                         // [0000].0044
public:    using              bCObjectBase::GetReferenceCount;                                                                        // [0000].0048
public:    using              bCObjectBase::BindPOType;                                                                               // [0000].004C
public:    using              bCObjectBase::PostInitializeProperties;                                                                 // [0000].0050
public:    using              bCObjectBase::HandleDeprecatedProperty;                                                                 // [0000].0054
public:    using              bCObjectBase::NotifyPropertyValueChangedEnterEx;                                                        // [0000].0058
public:    using              bCObjectBase::NotifyPropertyValueChangedExitEx;                                                         // [0000].005C
public:    using              bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                                                      // [0000].0060
public:    using              bCObjectBase::OnNotifyPropertyValueChangedExitEx;                                                       // [0000].0064
public:    virtual GEInt                    GetNativePropertyCount( void ) const;                                                     // [0000].0068
public:    virtual bCPropertyConverterPtr   GetNativePropertyAt( GEInt ) const;                                                       // [0000].006C
protected: virtual                         ~eCEntity( void );                                                                         // [0000].0070
public:    virtual eCEntity *               QueryEntity( void );                                                                      // [0000].0074
public:    using                    eCNode::QueryGeometryEntity;                                                                      // [0000].0078
public:    using                    eCNode::QueryDynamicEntity;                                                                       // [0000].007C
public:    using                    eCNode::QueryTemplateEntity;                                                                      // [0000].0080
public:    using                    eCNode::GetEntityID;                                                                              // [0000].0084
public:    using                    eCNode::OnReadContent;                                                                            // [0000].0088
protected: virtual void                     OnParentChanged( eCNode * );                                                              // [0000].008C
protected: virtual void                     OnAttachChild( eCNode * );                                                                // [0000].0090
protected: virtual void                     OnDetachChild( eCNode * );                                                                // [0000].0094
public:    using                    eCNode::UpdateParentBoundaries;                                                                   // [0000].0098
public:    using                    eCNode::UpdateChildDependencies;                                                                  // [0000].009C
public:    using                    eCNode::DoClone;                                                                                  // [0000].00A0
public:    virtual bCPropertyID const &     GetID( void ) const;                                                                      // [0000].00A4
public:    virtual void                     Enable( GEBool );                                                                         // [0000].00A8
public:    virtual void                     EnablePicking( GEBool, GEBool );                                                          // [0000].00AC
public:    virtual GEBool                   IsDummy( void ) const;                                                                    // [0000].00B0
public:    virtual void                     SetCreator( eCTemplateEntity * );                                                         // [0000].00B4
public:    virtual eCTemplateEntity const * GetCreator( void ) const;                                                                 // [0000].00B8
public:    virtual bCString const &         GetName( void ) const;                                                                    // [0000].00BC
public:    virtual GEBool                   AddPropertySet( eCEntityPropertySet * );                                                  // [0000].00C0
public:    virtual GEBool                   SetPropertySets( bTRefPtrArray< eCEntityPropertySet * > const & );                        // [0000].00C4
public:    virtual GEBool                   RemovePropertySet( bCString const & );                                                    // [0000].00C8
public:    virtual eCEntityPropertySet *    GetPropertySet( eEPropertySetType );                                                      // [0000].00CC
public:    virtual void                     Decay( void );                                                                            // [0000].00D0
public:    virtual GEBool                   IsAutoKillEnabled( void ) const;                                                          // [0000].00D4
protected: virtual void                     CopyEntityPrivateData( eCEntity const &, GEBool );                                        // [0000].00D8
protected: virtual GEBool                   OnPatchWithTemplate( eCTemplateEntity const &, GEBool, GEBool );                          // [0000].00DC
protected: virtual void                     OnUpdateBoundary( void );                                                                 // [0000].00E0
public:    virtual void                     Prefetch( bCVector const &, GEBool );                                                     // [0000].00E4
public:    virtual void                     OnCacheIn( void );                                                                        // [0000].00E8
public:    virtual void                     OnCacheOut( void );                                                                       // [0000].00EC
protected: virtual void                     EnterProcessingRange( void );                                                             // [0000].00F0
protected: virtual void                     ExitProcessingRange( void );                                                              // [0000].00F4
public:    virtual void                     CacheOut( void );                                                                         // [0000].00F8
public:    virtual void                     RenderGizmo( eCCameraBase *, GEInt );                                                     // [0000].00FC
public:    virtual void                     RenderAlphaGizmo( eCCameraBase *, GEInt );                                                // [0000].0100
public:    virtual GEBool                   PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );                           // [0000].0104
public:    virtual GEBool                   OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );  // [0000].0108
private:
    eSEntityFlags                          m_EntityFlags;               // 0014
    GEU8 (*                                m_pPSIndexMap) [ 0x80 ];     // 0018 // eSPSIndexMap *
    bTRefPtrArray< eCEntityPropertySet * > m_arrPropertySet;            // 001C
    bCDateTime                             m_DataChangedTimeStamp;      // 0028
    // sizeof(eCEntity)                                                 // 0030
protected:
    static GEInt GE_CDECL ComparePropertySets( GELPCVoid, GELPCVoid );
protected:
    void Invalidate( void );
    void KillIntern( void );
    void SendListenerEvent( eSEntityListenerEvent const &, GEBool );
    void SortPropertySets( void );
public:
    static void GE_STDCALL RemapEntityProxies( bTValMap< eCEntity *, eCEntity * > const &, GEBool, GEBool );
    static void GE_STDCALL RemapEntityProxiesRecursive( bCPropertyConverterPtr, bCPropertyConverterPtr, bTValMap< eCEntity *, eCEntity * > const &, GEBool, GEBool );
public:
    GEBool                      CreateFromTemplate( bCPropertyID const & );
    GEBool                      CreateFromTemplate( eCTemplateEntity const & );
    void                        EnableRendering( GEBool );
    bCDateTime const &          GetDataChangedTimeStamp( void ) const;
    eSEntityFlags &             GetEntityFlags( void );
    eSEntityFlags const &       GetEntityFlags( void ) const;
    eEInsertType                GetInsertType( void ) const;
    eCEntityPropertySet *       GetPropertySet( bCString const & );
    eCEntityPropertySet const * GetPropertySet( bCString const & ) const;
    eCEntityPropertySet const * GetPropertySet( eEPropertySetType ) const;
    eCEntityPropertySet *       GetPropertySetAt( GEInt );
    eCEntityPropertySet const * GetPropertySetAt( GEInt ) const;
    GEInt                       GetPropertySetCount( void ) const;
    GEInt                       GetPropertySetIndex( eCEntityPropertySet const * ) const;
    bCPropertyID const &        GetTemplateID( void ) const;
    GEBool                      HasPropertySet( bCString const & ) const;
    GEBool                      HasPropertySet( eEPropertySetType ) const;
    GEBool                      HasVisual( void ) const;
    GEBool                      IsPhysicRelevant( void ) const;
    GEBool                      IsSaveGameRelevant( void ) const;
    GEBool                      IsTriggerable( void ) const;
    GEBool                      IsValidPropertySetIndex( GEInt ) const;
    void                        Kill( void );
    void                        Lock( GEBool );
    GEBool                      PatchWithTemplate( bCPropertyID const &, GEBool );
    GEBool                      PatchWithTemplate( bCString const &, GEBool );
    GEBool                      PatchWithTemplate( eCTemplateEntity const &, GEBool );
    void                        PostRead( GEBool );
    void                        RemoveAllPropertySets( void );
    GEBool                      RemovePropertySet( eCEntityPropertySet * );
    GEBool                      RemovePropertySetAt( GEInt );
    void                        SetInsertType( eEInsertType );
    GEBool                      SetPropertySet( eCEntityPropertySet * );
    void                        SetSaveGameRelevant( GEBool );
    void                        SetTemporary( void );
    void                        UpdateAll( GEBool );
    void                        UpdateBoundary( void );
protected:
    eCEntity const & operator = ( eCEntity const & );
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static GELPChar s_carrAllocBuffer;
protected:
    eCEntity( eCEntity const & );
    eCEntity( void );
};

#endif
