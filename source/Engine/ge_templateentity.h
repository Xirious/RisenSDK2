#ifndef GE_TEMPLATEENTITY_H_INCLUDED
#define GE_TEMPLATEENTITY_H_INCLUDED

class GE_DLLIMPORT eCTemplateEntity :
    public eCEntity
{
public:    using                  eCNode::GetObjectType;                                      // [0000].0000
public:    virtual GEU16                  GetVersion( void ) const;                           // [0000].0004
public:    using                  eCNode::IsValid;                                            // [0000].0008
public:    using            bCObjectBase::Deserialize;                                        // [0000].000C
public:    using            bCObjectBase::Serialize;                                          // [0000].0010
public:    using            bCObjectBase::Read;                                               // [0000].0014
public:    using            bCObjectBase::Write;                                              // [0000].0018
protected: using            bCObjectBase::OnDeserialize;                                      // [0000].001C
protected: using            bCObjectBase::OnSerialize;                                        // [0000].0020
protected: virtual GEBool                 OnRead( bCIStream & );                              // [0000].0024
protected: virtual GEBool                 OnWrite( bCOStream & );                             // [0000].0028
public:    using                eCEntity::Create;                                             // [0000].002C
public:    virtual void                   Destroy( void );                                    // [0000].0030
public:    using            bCObjectBase::CopyFrom;                                           // [0000].0034
public:    virtual GEBool                 OnCopyFrom( bCObjectBase const & );                 // [0000].0038
protected: using            bCObjectBase::OnCopyPatchableOnly;                                // [0000].003C
public:    using         bCObjectRefBase::AddReference;                                       // [0000].0040
public:    using                  eCNode::ReleaseReference;                                   // [0000].0044
public:    using            bCObjectBase::GetReferenceCount;                                  // [0000].0048
public:    using            bCObjectBase::BindPOType;                                         // [0000].004C
public:    using            bCObjectBase::PostInitializeProperties;                           // [0000].0050
public:    using            bCObjectBase::HandleDeprecatedProperty;                           // [0000].0054
public:    using            bCObjectBase::NotifyPropertyValueChangedEnterEx;                  // [0000].0058
public:    using            bCObjectBase::NotifyPropertyValueChangedExitEx;                   // [0000].005C
protected: using            bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                // [0000].0060
protected: using            bCObjectBase::OnNotifyPropertyValueChangedExitEx;                 // [0000].0064
public:    using                eCEntity::GetNativePropertyCount;                             // [0000].0068
protected: virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;                 // [0000].006C
protected: virtual                       ~eCTemplateEntity( void );                           // [0000].0070
public:    using                eCEntity::QueryEntity;                                        // [0000].0074
public:    using                  eCNode::QueryGeometryEntity;                                // [0000].0078
public:    using                  eCNode::QueryDynamicEntity;                                 // [0000].007C
public:    virtual eCTemplateEntity *     QueryTemplateEntity( void );                        // [0000].0080
public:    virtual eSEntityID *           GetEntityID( void ) const;                          // [0000].0084
protected: virtual void                   OnReadContent( void );                              // [0000].0088
protected: using                eCEntity::OnParentChanged;                                    // [0000].008C
protected: virtual void                   OnAttachChild( eCNode * );                          // [0000].0090
protected: virtual void                   OnDetachChild( eCNode * );                          // [0000].0094
public:    using                  eCNode::UpdateParentBoundaries;                             // [0000].0098
public:    using                  eCNode::UpdateChildDependencies;                            // [0000].009C
public:    virtual eCTemplateEntity *     DoClone( void ) const;                              // [0000].00A0
public:    virtual bCPropertyID const &   GetID( void ) const;                                // [0000].00A4
public:    using                eCEntity::Enable;                                             // [0000].00A8
public:    using                eCEntity::EnablePicking;                                      // [0000].00AC
public:    using                eCEntity::IsDummy;                                            // [0000].00B0
public:    using                eCEntity::SetCreator;                                         // [0000].00B4
public:    using                eCEntity::GetCreator;                                         // [0000].00B8
public:    virtual bCString const &       GetName( void ) const;                              // [0000].00BC // inline local: static bCString strEmpty;
public:    using                eCEntity::AddPropertySet;                                     // [0000].00C0
public:    using                eCEntity::SetPropertySets;                                    // [0000].00C4
public:    using                eCEntity::RemovePropertySet;                                  // [0000].00C8
public:    using                eCEntity::GetPropertySet;                                     // [0000].00CC
public:    using                eCEntity::Decay;                                              // [0000].00D0
public:    using                eCEntity::IsAutoKillEnabled;                                  // [0000].00D4
public:    virtual void                   CopyEntityPrivateData( eCEntity const &, GEBool );  // [0000].00D8
protected: using                eCEntity::OnPatchWithTemplate;                                // [0000].00DC
protected: using                eCEntity::OnUpdateBoundary;                                   // [0000].00E0
public:    using                eCEntity::Prefetch;                                           // [0000].00E4
public:    using                eCEntity::OnCacheIn;                                          // [0000].00E8
public:    using                eCEntity::OnCacheOut;                                         // [0000].00EC
protected: using                eCEntity::EnterProcessingRange;                               // [0000].00F0
protected: using                eCEntity::ExitProcessingRange;                                // [0000].00F4
public:    using                eCEntity::CacheOut;                                           // [0000].00F8
public:    using                eCEntity::RenderGizmo;                                        // [0000].00FC
public:    using                eCEntity::RenderAlphaGizmo;                                   // [0000].0100
public:    using                eCEntity::PickGizmo;                                          // [0000].0104
public:    using                eCEntity::OnMoveGizmo;                                        // [0000].0108
public:    virtual void                   SetID( bCPropertyID const & );                      // [0000].010C
public:    virtual GEBool                 IsHelperParent( void ) const;                       // [0000].0110
public:    virtual void                   SetName( bCString const & );                        // [0000].0114
protected: virtual bEResult               ReadHeader( bCIStream &, GEU16 &, GEBool );         // [0000].0118
protected: virtual bEResult               ReadContent( bCIStream &, GEU16 );                  // [0000].011C
protected: virtual bEResult               ReadSkipData( bCIStream & );                        // [0000].0120
public:    virtual bEResult               ReadAll( void );                                    // [0000].0124
private:
    GEU8           m_IsHelperParent : 1;     // 0030
    GEU8           m_IsContentLoaded: 1;
    GEU8           m_IsGameRelevant : 1;
                   GE_PADDING( 3 )
    bCPropertyID * m_pRefTemplateID;         // 0034
    void *         m_pNameInfo;              // 0038 // eCEntityNameInfo *
    GEFloat        m_fRenderAlphaValue;      // 003C
    GEFloat        m_fViewRange;             // 0040
    GEU8           m_u8ScaleGridPercentage;  // 0044
                   GE_PADDING1( 3 )
    void *         __FIXME_0048;
    bCVector       m_vecTranslation;         // 004C
    bCQuaternion   m_qatRotation;            // 0058
    eSEntityID *   m_pEntityID;              // 0068
                   GE_PADDING2( 4 )
    // sizeof(eCTemplateEntity)              // 0070
private:
    bEResult ReadTemplateEntityDependency( bCIStream &, bTValArray< eCTemplateEntity * > & );
protected:
    void     DeleteInstances( eCEntity * );
    void     Invalidate( void );
    void     PatchInstances( eCEntity * );
    bEResult WriteHeader( bCOStream & );
public:
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCTemplateEntity * );
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCDynamicEntity *, GEBool );
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCEntity *, GEBool );
    static eCTemplateEntity * GE_STDCALL CreateNewEntity( void );
    static bCString const &   GE_STDCALL GetFileExt( void );
    static GEU32              GE_STDCALL GetMagicCode1( void );
    static GEU32              GE_STDCALL GetMagicCode2( void );
    static eCTemplateEntity * GE_STDCALL Load( bCString const &, GEBool );
public:
    bCBox                    CalculateLocalNode( void ) const;
    bCMatrix                 CalculateWorldMatrix( void ) const;
    void                     DeleteContent( void );
    void                     DeleteInstances( void );
    bCString const           GetFileName( void ) const;
    bCString const           GetFilePath( void ) const;
    GEBool                   GetIsGameRelevant( void ) const;
    eCTemplateEntity const * GetRefTemplate( void ) const;
    bCPropertyID const &     GetRefTemplateID( void ) const;
    GEFloat                  GetRenderAlphaValue( void ) const;
    GEU8                     GetScaleGridPercentage( void ) const;
    GEFloat                  GetViewRange( void ) const;
    GEBool                   IsContentLoaded( void ) const;
    GEBool                   IsMultiTemplate( void ) const;
    GEBool                   IsReadOnly( void ) const;
    GEBool                   IsReferencedTemplateEntity( void ) const;
    GEBool                   IsSingleTemplate( void ) const;
    void                     Kill( void );
    bCDateTime const &       Modified( void );
    bEResult                 PatchEntity( eCEntity *, GEBool, GEBool ) const;
    GEBool                   PatchInstances( void );
    bEResult                 Save( bCString const & );
    bEResult                 Save( void );
    void                     SetAsHelperParent( void );
    void                     SetIsGameRelevant( GEBool );
    void                     SetRefTemplate( eCTemplateEntity const & );
    void                     SetRenderAlphaValue( GEFloat );
    void                     SetScaleGridPercentage( GEU8 );
    void                     SetViewRange( GEFloat );
protected:
    eCTemplateEntity const & operator = ( eCTemplateEntity const & );
protected:
    eCTemplateEntity( eCTemplateEntity const & );
    eCTemplateEntity( void );
};

#endif