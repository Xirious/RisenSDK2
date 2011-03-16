#ifndef GE_SCRIPTADMIN_H_INCLUDED
#define GE_SCRIPTADMIN_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'gCScriptAdmin::CProcessor' needs to have dll-interface to be used by clients of class 'gCScriptAdmin'

class GE_DLLIMPORT gCScriptAdmin :
    public eCScriptAdminBase
{
private:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  // [0000].0000
    public: virtual GEU32 GetAppStateFlags( void ) const;    // [0000].0004
    public: virtual void  OnProcess( void );                 // [0000].0008
    public: virtual      ~CProcessor( void );                // [0000].000C
    protected:
        gCScriptAdmin * m_pScriptAdmin;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                                      // [0000].0000
public:    using       eCEngineComponentBase::GetVersion;                                                       // [0000].0004
public:    virtual GEBool                     IsValid( void ) const;                                            // [0000].0008
public:    using                bCObjectBase::Deserialize;                                                      // [0000].000C
public:    using                bCObjectBase::Serialize;                                                        // [0000].0010
public:    using                bCObjectBase::Read;                                                             // [0000].0014
public:    using                bCObjectBase::Write;                                                            // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                                                    // [0000].001C
protected: using                bCObjectBase::OnSerialize;                                                      // [0000].0020
public:    using             bCObjectRefBase::OnRead;                                                           // [0000].0024
public:    using             bCObjectRefBase::OnWrite;                                                          // [0000].0028
public:    virtual bEResult                   Create( void );                                                   // [0000].002C
public:    virtual void                       Destroy( void );                                                  // [0000].0030
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
public:    virtual                           ~gCScriptAdmin( void );                                            // [0000].0070
public:    virtual bEResult                   Initialize( void );                                               // [0000].0074
public:    virtual bEResult                   PostInitialize( void );                                           // [0000].0078
public:    using       eCEngineComponentBase::PreShutdown;                                                      // [0000].007C
public:    virtual bEResult                   Shutdown( void );                                                 // [0000].0080
public:    using       eCEngineComponentBase::OnAppInitialized;                                                 // [0000].0084
public:    using       eCEngineComponentBase::ApplyConfiguration;                                               // [0000].0088
protected: using       eCEngineComponentBase::WorldActivate;                                                    // [0000].008C
protected: using       eCEngineComponentBase::WorldDeactivate;                                                  // [0000].0090
protected: using       eCEngineComponentBase::AfterWorldDeactivate;                                             // [0000].0094
public:    using       eCEngineComponentBase::EngineMessageProc;                                                // [0000].0098
public:    using       eCEngineComponentBase::ResetResources;                                                   // [0000].009C
public:    using       eCEngineComponentBase::RestoreResources;                                                 // [0000].00A0
public:    virtual void                       Process( void );                                                  // [0000].00A4
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
protected: virtual GEInt                      CallScript( gSScript *, eCEntity *, eCEntity *, GEInt );          // [0000].00D0
protected: virtual gSScript *                 RegisterScript( bCString const & );                               // [0000].00D4
protected: virtual GEBool                     UnRegisterScript( gSScript * );                                   // [0000].00D8
public:    virtual GEU32 const                GetProfileLastTicksFirst( void ) const;                           // [0000].00DC
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    CProcessor                  m_Processor;
    gCScriptProcessingUnit      m_ScriptProcessingUnit;
    void *                      __FIXME;
    bTPtrArray< gSScriptDLL * > m_arrScriptDLLs;
    GEU32                       m_u32ProfileLastTicksFirst;
    GEU32                       m_u32ProfileTicks;
protected:
    GEInt                CallScript( bCString const &, eCEntity *, eCEntity *, GEInt );
    GEInt                CallScriptFromScript( bCString const &, GELPVoid, GELPVoid, GEInt );
    GEInt                CallScriptFromScript( gSScript *, GELPVoid, GELPVoid, GEInt );
    GEBool               LoadAllScriptDLLs( void );
    gSScriptAICallback * RegisterScriptAICallback( bCString const & );
    gSScriptAIFunction * RegisterScriptAIFunction( bCString const & );
    gSScriptAIState *    RegisterScriptAIState( bCString const & );
    GEInt                RunScript( bCString const &, gCScriptProcessingUnit * );
    GEInt                RunScript( gSScript *, gCScriptProcessingUnit * );
    GEBool               RunScriptCallback( bCString const &, gCScriptProcessingUnit * );
    GEBool               RunScriptCallback( gSScriptAICallback *, gCScriptProcessingUnit * );
    GEInt                RunScriptFromScript( bCString const &, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
    GEInt                RunScriptFromScript( gSScript *, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
    GEBool               RunScriptFunction( bCString const &, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptFunction( gSScriptAIFunction *, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptState( bCString const &, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptState( gSScriptAIState *, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               UnRegisterScriptAICallback( gSScriptAICallback * );
    GEBool               UnRegisterScriptAIFunction( gSScriptAIFunction * );
    GEBool               UnRegisterScriptAIState( gSScriptAIState * );
    GEBool               UnloadAllScriptDLLs( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                       AddProfileTicks( GEU32 );
    void                       ClearDLLList( void );
    gSScript const *           GetScript( bCString const & ) const;
    gSScriptAICallback const * GetScriptAICallback( bCString const & ) const;
    gSScriptAIFunction const * GetScriptAIFunction( bCString const & ) const;
    gSScriptAIState const *    GetScriptAIState( bCString const & ) const;
    gSScriptDLL const *        GetScriptDLLAt( GEInt ) const;
    GEInt                      GetScriptDLLCount( void ) const;
    GEBool                     IsScriptDLLLoaded( bCString const & ) const;
    GEBool                     LoadScriptDLL( bCString const & );
    GEBool                     UnloadScriptDLL( bCString const & );
private:
    gCScriptAdmin & operator = ( gCScriptAdmin const & );  // not defined
    gCScriptAdmin( gCScriptAdmin const & );                // not defined
public:
    gCScriptAdmin( void );
};
GE_ASSERT_SIZEOF( gCScriptAdmin, 0x0168 )

#pragma warning( pop )

#endif
