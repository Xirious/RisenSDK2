#ifndef GE_ENGINECOMPONENTBASE_H_INCLUDED
#define GE_ENGINECOMPONENTBASE_H_INCLUDED

enum eEEngineMessage
{
    eEEngineMessage_WorldActivate        = 0x00000000,
    eEEngineMessage_WorldDeactivate      = 0x00000001,
    eEEngineMessage_AfterWorldDeactivate = 0x00000002,
    //FIXME: eEEngineMessage constants.
    eEEngineMessage_Initialize           = 0x00000012,
    eEEngineMessage_PostInitialize       = 0x00000013,
    eEEngineMessage_OnAppInitialized     = 0x00000014,
    eEEngineMessage_PreShutdown          = 0x00000015,
    eEEngineMessage_Shutdown             = 0x00000016,
    eEEngineMessage_ForceDWORD           = GE_FORCE_DWORD
};

struct eSEngineMessage
{
    eEEngineMessage m_enumEngineMessage;
    void *          m_EngineMessageData;
};

class GE_DLLIMPORT eCEngineComponentBase :
    public bCObjectRefBase
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;             // [0000].0000
public:    virtual GEU16                      GetVersion( void ) const;                // [0000].0004
public:    using             bCObjectRefBase::IsValid;                                 // [0000].0008
public:    using                bCObjectBase::Deserialize;                             // [0000].000C
public:    using                bCObjectBase::Serialize;                               // [0000].0010
public:    using                bCObjectBase::Read;                                    // [0000].0014
public:    using                bCObjectBase::Write;                                   // [0000].0018
protected: using                bCObjectBase::OnDeserialize;                           // [0000].001C
protected: using                bCObjectBase::OnSerialize;                             // [0000].0020
public:    using             bCObjectRefBase::OnRead;                                  // [0000].0024
public:    using             bCObjectRefBase::OnWrite;                                 // [0000].0028
public:    virtual bEResult                   Create( void );                          // [0000].002C
public:    virtual void                       Destroy( void );                         // [0000].0030
public:    using                bCObjectBase::CopyFrom;                                // [0000].0034
protected: using                bCObjectBase::OnCopyFrom;                              // [0000].0038
protected: using                bCObjectBase::OnCopyPatchableOnly;                     // [0000].003C
public:    using             bCObjectRefBase::AddReference;                            // [0000].0040
public:    using             bCObjectRefBase::ReleaseReference;                        // [0000].0044
public:    using                bCObjectBase::GetReferenceCount;                       // [0000].0048
public:    using                bCObjectBase::BindPOType;                              // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;                // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;                // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;       // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;        // [0000].005C
protected: using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;     // [0000].0060
protected: using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;      // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;                  // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                     // [0000].006C
public:    virtual                           ~eCEngineComponentBase( void );           // [0000].0070
public:    virtual bEResult                   Initialize( void );                      // [0000].0074
public:    virtual bEResult                   PostInitialize( void );                  // [0000].0078
public:    virtual bEResult                   PreShutdown( void );                     // [0000].007C
public:    virtual bEResult                   Shutdown( void );                        // [0000].0080
public:    virtual void                       OnAppInitialized( void );                // [0000].0084
public:    virtual void                       ApplyConfiguration( void );              // [0000].0088
protected: virtual bEResult                   WorldActivate( void );                   // [0000].008C
protected: virtual bEResult                   WorldDeactivate( void );                 // [0000].0090
protected: virtual bEResult                   AfterWorldDeactivate( void );            // [0000].0094
public:    virtual void                       EngineMessageProc( eSEngineMessage & );  // [0000].0098
public:    virtual bEResult                   ResetResources( GEBool );                // [0000].009C
public:    virtual bEResult                   RestoreResources( GEBool );              // [0000].00A0
public:    virtual void                       Process( void );                         // [0000].00A4
public:    virtual void                       OnBeginRenderSolid( void );              // [0000].00A8
public:    virtual void                       OnEndRenderSolid( void );                // [0000].00AC
public:    virtual void                       OnBeginRenderAlpha( void );              // [0000].00B0
public:    virtual void                       OnEndRenderAlpha( void );                // [0000].00B4
public:    virtual void                       OnPostRender( void );                    // [0000].00B8
public:    virtual eCStatistic *              CreateStatistics( void ) const;          // [0000].00BC
protected: virtual bEResult                   OnReadPreLoadData( bCIStream & );        // [0000].00C0
protected: virtual bEResult                   OnWritePreLoadData( bCOStream & );       // [0000].00C4
protected: virtual bEResult                   ReadSaveGame( bCIStream & );             // [0000].00C8
protected: virtual bEResult                   WriteSaveGame( bCOStream & );            // [0000].00CC
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    GEBool m_bEnabled;
    GEU8   __FIXME;
           GE_PADDING( 2 )
    GEInt  m_iModuleLevel;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void   Enable( GEBool );
    GEInt  GetModuleLevel( void ) const;
    GEBool IsEnabled( void ) const;
    void   OnProcess( void );
public:
    eCEngineComponentBase & operator = ( eCEngineComponentBase const & );
public:
    eCEngineComponentBase( eCEngineComponentBase const & );
    eCEngineComponentBase( void );
};
GE_ASSERT_SIZEOF( eCEngineComponentBase, 0x0010 )

#endif

