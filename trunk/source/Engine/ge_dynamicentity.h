#ifndef GE_DYNAMICENTITY_H_INCLUDED
#define GE_DYNAMICENTITY_H_INCLUDED

class GE_DLLIMPORT eCDynamicEntity :
    public eCGeometryEntity
{
private:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  // [0000].0000
    public: virtual GEU32 GetAppStateFlags( void ) const;    // [0000].0004
    public: virtual void  OnProcess( void );                 // [0000].0008
    public: virtual      ~CProcessor( void );                // [0000].000C
    private:
        eCDynamicEntity * m_pEntity;       // 000C
        //sizeof(eCDynamicEntity::CProcessor) 0010
    };
public:    using                    eCNode::GetObjectType;                                                          // [0000].0000
public:    virtual GEU16                    GetVersion( void ) const;                                               // [0000].0004
public:    using                    eCNode::IsValid;                                                                // [0000].0008
public:    using              bCObjectBase::Deserialize;                                                            // [0000].000C
public:    using              bCObjectBase::Serialize;                                                              // [0000].0010
public:    using              bCObjectBase::Read;                                                                   // [0000].0014
public:    using              bCObjectBase::Write;                                                                  // [0000].0018
protected: using              bCObjectBase::OnDeserialize;                                                          // [0000].001C
protected: using              bCObjectBase::OnSerialize;                                                            // [0000].0020
public:    virtual GEBool                   OnRead( bCIStream & );                                                  // [0000].0024
public:    virtual GEBool                   OnWrite( bCOStream & );                                                 // [0000].0028
public:    virtual bEResult                 Create( void );                                                         // [0000].002C
public:    virtual void                     Destroy( void );                                                        // [0000].0030
public:    using              bCObjectBase::CopyFrom;                                                               // [0000].0034
public:    virtual GEBool                   OnCopyFrom( bCObjectBase const & );                                     // [0000].0038
protected: using              bCObjectBase::OnCopyPatchableOnly;                                                    // [0000].003C
public:    using           bCObjectRefBase::AddReference;                                                           // [0000].0040
public:    using                    eCNode::ReleaseReference;                                                       // [0000].0044
public:    using              bCObjectBase::GetReferenceCount;                                                      // [0000].0048
public:    using              bCObjectBase::BindPOType;                                                             // [0000].004C
public:    using              bCObjectBase::PostInitializeProperties;                                               // [0000].0050
public:    using              bCObjectBase::HandleDeprecatedProperty;                                               // [0000].0054
public:    using              bCObjectBase::NotifyPropertyValueChangedEnterEx;                                      // [0000].0058
public:    using              bCObjectBase::NotifyPropertyValueChangedExitEx;                                       // [0000].005C
protected: using              bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                                    // [0000].0060
protected: using              bCObjectBase::OnNotifyPropertyValueChangedExitEx;                                     // [0000].0064
public:    using                  eCEntity::GetNativePropertyCount;                                                 // [0000].0068
public:    virtual bCPropertyConverterPtr   GetNativePropertyAt( GEInt ) const;                                     // [0000].006C
protected: virtual                         ~eCDynamicEntity( void );                                                // [0000].0070
public:    using                  eCEntity::QueryEntity;                                                            // [0000].0074
public:    using          eCGeometryEntity::QueryGeometryEntity;                                                    // [0000].0078
public:    virtual eCDynamicEntity *        QueryDynamicEntity( void );                                             // [0000].007C
public:    using                    eCNode::QueryTemplateEntity;                                                    // [0000].0080
public:    virtual eSEntityID *             GetEntityID( void ) const;                                              // [0000].0084
protected: using                    eCNode::OnReadContent;                                                          // [0000].0088
protected: using                  eCEntity::OnParentChanged;                                                        // [0000].008C
//FIXME: OnAttach/OnDetachChild hidden in eCDynamicEntity
//private: using          eCGeometryEntity::OnAttachChild;                                                          // [0000].0090
//private: using          eCGeometryEntity::OnDetachChild;                                                          // [0000].0094
protected: virtual void                     UpdateParentBoundaries( void );                                         // [0000].0098
protected: virtual void                     UpdateChildDependencies( void );                                        // [0000].009C
protected: virtual eCDynamicEntity *        DoClone( void ) const;                                                  // [0000].00A0
public:    virtual bCPropertyID const &     GetID( void ) const;                                                    // [0000].00A4
public:    using          eCGeometryEntity::Enable;                                                                 // [0000].00A8
public:    using                  eCEntity::EnablePicking;                                                          // [0000].00AC
public:    virtual GEBool                   IsDummy( void ) const;                                                  // [0000].00B0
public:    virtual void                     SetCreator( eCTemplateEntity * );                                       // [0000].00B4
public:    virtual eCTemplateEntity const * GetCreator( void ) const;                                               // [0000].00B8
public:    virtual bCString const &         GetName( void ) const;                                                  // [0000].00BC // inline local: static bCString strEmpty;
public:    using                  eCEntity::AddPropertySet;                                                         // [0000].00C0
public:    using                  eCEntity::SetPropertySets;                                                        // [0000].00C4
public:    using                  eCEntity::RemovePropertySet;                                                      // [0000].00C8
public:    using                  eCEntity::GetPropertySet;                                                         // [0000].00CC
public:    virtual void                     Decay( void );                                                          // [0000].00D0
public:    virtual GEBool                   IsAutoKillEnabled( void ) const;                                        // [0000].00D4
public:    virtual void                     CopyEntityPrivateData( eCEntity const &, GEBool );                      // [0000].00D8
protected: using                  eCEntity::OnPatchWithTemplate;                                                    // [0000].00DC
protected: virtual void                     OnUpdateBoundary( void );                                               // [0000].00E0
public:    using                  eCEntity::Prefetch;                                                               // [0000].00E4
protected: using          eCGeometryEntity::OnCacheIn;                                                              // [0000].00E8
protected: using          eCGeometryEntity::OnCacheOut;                                                             // [0000].00EC
protected: virtual void                     EnterProcessingRange( void );                                           // [0000].00F0
protected: virtual void                     ExitProcessingRange( void );                                            // [0000].00F4
public:    using          eCGeometryEntity::CacheOut;                                                               // [0000].00F8
public:    using          eCGeometryEntity::RenderGizmo;                                                            // [0000].00FC
public:    using          eCGeometryEntity::RenderAlphaGizmo;                                                       // [0000].0100
public:    using          eCGeometryEntity::PickGizmo;                                                              // [0000].0104
public:    using          eCGeometryEntity::OnMoveGizmo;                                                            // [0000].0108
public:    virtual void                     SetName( bCString const & );                                            // [0000].010C
public:    virtual GEBool                   HasCreator( void ) const;                                               // [0000].0110
protected: using          eCGeometryEntity::OnPortalRoomChanged;                                                    // [0000].0114
protected: virtual void                     OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );             // [0000].0118
protected: virtual void                     OnUpdatedWorldTreeBoundary( void );                                     // [0000].011C
public:    virtual void                     SetLocalMatrix( bCMatrix const & );                                     // [0000].0120
public:    virtual void                     SetWorldTreeBoundary( bCBox const & );                                  // [0000].0124
public:    virtual bCMatrix const &         GetLocalMatrix( void ) const;                                           // [0000].0128
public:    virtual bCBox const &            GetLocalNodeBoundary( void ) const;                                     // [0000].012C
public:    virtual bCBox const &            GetWorldNodeBoundary( void ) const;                                     // [0000].0130
public:    virtual bCSphere const &         GetWorldNodeSphere( void ) const;                                       // [0000].0134
public:    using          eCGeometryEntity::QueryLightSet;                                                          // [0000].0138
public:    virtual void                     SetID( bCPropertyID const & );                                          // [0000].013C
public:    virtual void                     OnTrigger( eCEntity *, eCEntity * );                                    // [0000].0140
public:    virtual void                     OnUntrigger( eCEntity *, eCEntity * );                                  // [0000].0144
public:    virtual void                     OnTouch( eCEntity *, eCContactIterator & );                             // [0000].0148
public:    virtual void                     OnIntersect( eCEntity *, eCContactIterator & );                         // [0000].014C
public:    virtual void                     OnUntouch( eCEntity *, eCContactIterator & );                           // [0000].0150
public:    virtual void                     OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );  // [0000].0154
protected: virtual void                     OnProcess( void );                                                      // [0000].0158
public:    virtual void                     Render( GEI16 );                                                        // [0000].015C
public:    virtual void                     SetLocalNodeBoundary( bCBox const & );                                  // [0000].0160
public:    virtual void                     SetWorldNodeBoundary( bCBox const & );                                  // [0000].0164
protected: virtual void                     OnUpdatedLocalMatrix( void );                                           // [0000].0168
protected: virtual void                     DoSaveGameEntityPostRead( void );                                       // [0000].016C
protected: virtual void                     UpdateChildBoundaries( void );                                          // [0000].0170
private:
    CProcessor    m_Processor;                   // 00D0
    bCMatrix      m_matLocalMatrix;              // 00E0
    bCBox         m_boxWorldNodeBoundary;        // 0120
    bCSphere      m_sphWorldNodeSphere;          // 0138
    bCBox         m_boxLocalNodeBoundary;        // 0148
    void *        m_pNameInfo;                   // 0160 // eCEntityNameInfo *
    eSEntityID *  m_pEntityID;                   // 0164
    eCEntityProxy m_Creator;                     // 0168
    GEU16         m_bIsNativeSaveGameEntity: 1;  // 0170
    GEU16         __FIXME_0170_0002        : 1;
    GEU16         __FIXME_0170_0004        : 1;
    GEU16         m_u16VisualizedTransAxes : 4;
    GEU16         m_u16VisualizedRotAxes   : 6;
    GEU16         m_bIsInOnTrigger         : 1;
    GEU16         m_bIsInOnUntrigger       : 1;
                  GE_PADDING( 6 )
    // sizeof(eCDynamicEntity)                      0178
protected:
    void Invalidate( void );
public:
    bCPropertyID const & GetCreatorID( void ) const;
    GEU16                GetVisualizedRotAxes( void ) const;
    GEU16                GetVisualizedTransAxes( void ) const;
    GEBool               IsNativeSaveGameEntity( void ) const;
    bEResult             ReadSaveGame( bCIStream & );
    bEResult             SetMeshVisual( bCString const &, GEBool );
    void                 SetVisualizedRotAxes( GEU16 );
    void                 SetVisualizedTransAxes( GEU16 );
    bEResult             WriteSaveGame( bCOStream & );
protected:
    eCDynamicEntity const & operator = ( eCDynamicEntity const & );
protected:
    eCDynamicEntity( eCDynamicEntity const & );
    eCDynamicEntity( void );
};

#endif
