#ifndef GE_SCRIPTADMINBASE_H_INCLUDED
#define GE_SCRIPTADMINBASE_H_INCLUDED

struct eSScriptBase
{
    GEU32                                    m_u32RegisterCounter;
    bTStringObjMap< eSScriptBase >::bSNode * m_pFunctionMapNode;
    bCString                                 m_strSource;
    void *                                   m_pScriptDLL;
    void *                                   m_funcFunction;
};
GE_ASSERT_SIZEOF( eSScriptBase, 0x0014 )

class GE_DLLIMPORT eCScriptAdminBase :
    public eCEngineComponentBase
{
public:    using       eCEngineComponentBase::GetObjectType;                                                    // [0000].0000
public:    using       eCEngineComponentBase::GetVersion;                                                       // [0000].0004
public:    using             bCObjectRefBase::IsValid;                                                          // [0000].0008
public:    using                bCObjectBase::Deserialize;                                                      // [0000].000C
public:    using                bCObjectBase::Serialize;                                                        // [0000].0010
public:    using                bCObjectBase::Read;                                                             // [0000].0014
public:    using                bCObjectBase::Write;                                                            // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                                                    // [0000].001C
protected: using                bCObjectBase::OnSerialize;                                                      // [0000].0020
public:    using             bCObjectRefBase::OnRead;                                                           // [0000].0024
public:    using             bCObjectRefBase::OnWrite;                                                          // [0000].0028
public:    using       eCEngineComponentBase::Create;                                                           // [0000].002C
public:    using       eCEngineComponentBase::Destroy;                                                          // [0000].0030
public:    using                bCObjectBase::CopyFrom;                                                         // [0000].0034
protected: using                bCObjectBase::OnCopyFrom;                                                       // [0000].0038
protected: using                bCObjectBase::OnCopyPatchableOnly;                                              // [0000].003C
public:    using             bCObjectRefBase::AddReference;                                                     // [0000].0040
public:    using             bCObjectRefBase::ReleaseReference;                                                 // [0000].0044
public:    using                bCObjectBase::GetReferenceCount;                                                // [0000].0048
public:    using                bCObjectBase::BindPOType;                                                       // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;                                         // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;                                         // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;                                // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;                                 // [0000].005C
protected: using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;                              // [0000].0060
protected: using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;                               // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;                                           // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                                              // [0000].006C
public:    virtual                           ~eCScriptAdminBase( void );                                        // [0000].0070
public:    using       eCEngineComponentBase::Initialize;                                                       // [0000].0074
public:    using       eCEngineComponentBase::PostInitialize;                                                   // [0000].0078
public:    using       eCEngineComponentBase::PreShutdown;                                                      // [0000].007C
public:    using       eCEngineComponentBase::Shutdown;                                                         // [0000].0080
public:    using       eCEngineComponentBase::OnAppInitialized;                                                 // [0000].0084
public:    using       eCEngineComponentBase::ApplyConfiguration;                                               // [0000].0088
protected: using       eCEngineComponentBase::WorldActivate;                                                    // [0000].008C
protected: using       eCEngineComponentBase::WorldDeactivate;                                                  // [0000].0090
protected: using       eCEngineComponentBase::AfterWorldDeactivate;                                             // [0000].0094
public:    using       eCEngineComponentBase::EngineMessageProc;                                                // [0000].0098
public:    using       eCEngineComponentBase::ResetResources;                                                   // [0000].009C
public:    using       eCEngineComponentBase::RestoreResources;                                                 // [0000].00A0
public:    using       eCEngineComponentBase::Process;                                                          // [0000].00A4
public:    using       eCEngineComponentBase::OnBeginRenderSolid;                                               // [0000].00A8
public:    using       eCEngineComponentBase::OnEndRenderSolid;                                                 // [0000].00AC
public:    using       eCEngineComponentBase::OnBeginRenderAlpha;                                               // [0000].00B0
public:    using       eCEngineComponentBase::OnEndRenderAlpha;                                                 // [0000].00B4
public:    using       eCEngineComponentBase::OnPostRender;                                                     // [0000].00B8
public:    using       eCEngineComponentBase::CreateStatistics;                                                 // [0000].00BC
protected: using       eCEngineComponentBase::OnReadPreLoadData;                                                // [0000].00C0
protected: using       eCEngineComponentBase::OnWritePreLoadData;                                               // [0000].00C4
protected: using       eCEngineComponentBase::ReadSaveGame;                                                     // [0000].00C8
protected: using       eCEngineComponentBase::WriteSaveGame;                                                    // [0000].00CC
protected: virtual GEInt                      CallScript( eSScriptBase *, eCEntity *, eCEntity *, GEInt ) = 0;  // [0000].00D0
public:
    eCScriptAdminBase & operator = ( eCScriptAdminBase const & );
public:
    eCScriptAdminBase( eCScriptAdminBase const & );
    eCScriptAdminBase( void );
};
GE_ASSERT_SIZEOF( eCScriptAdminBase, 0x0010 )

#endif
