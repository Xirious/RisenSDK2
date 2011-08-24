#ifndef GE_EFFECT_PS_H_INCLUDED
#define GE_EFFECT_PS_H_INCLUDED

enum gEEffectDecayMode
{
    gEEffectDecayMode_Decay      = 0x00000000,
    gEEffectDecayMode_Kill       = 0x00000001,
    gEEffectDecayMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEEffectLoopMode
{
    gEEffectLoopMode_Once       = 0x00000000,
    gEEffectLoopMode_Loop       = 0x00000001,
    gEEffectLoopMode_Repeat     = 0x00000002,
    gEEffectLoopMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEEffectQuality
{
    gEEffectQuality_Low,
    gEEffectQuality_Medium,
    gEEffectQuality_High,
    gEEffectQuality_Count,
    gEEffectQuality_ForceDWORD = GE_FORCE_DWORD
};

GE_CPP_LINKAGE GE_DLLIMPORT GELPCChar const g_ppszEffectQualities[ gEEffectQuality_Count ];

enum gEEffectStopMode
{
    gEEffectStopMode_Decay      = 0x00000000,
    gEEffectStopMode_Disable    = 0x00000001,
    gEEffectStopMode_Kill       = 0x00000002,
    gEEffectStopMode_ForceDWORD = GE_FORCE_DWORD
};

enum gEEffectTargetMode
{
    gEEffectTargetMode_Self       = 0x00000000,
    gEEffectTargetMode_Parent     = 0x00000001,
    gEEffectTargetMode_Script     = 0x00000002,
    gEEffectTargetMode_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCEffect_PS :
    public eCEntityPropertySet
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCEffect_PS * m_pEffectPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                                   PostInitializeProperties( void );
public:    virtual                                           ~gCEffect_PS( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual GEBool                                     IsEditorRelevant( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                                       OnTrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnUntrigger( eCEntity *, eCEntity * );
public:    virtual GEBool                                     IsClassProcessible( void ) const;
public:    virtual GEBool                                     IsClassProcessingEnabled( void ) const;
public:    virtual void                                       EnableClassProcessing( GEBool );
public:    virtual void                                       EnterProcessingRange( void );
public:    virtual void                                       ExitProcessingRange( void );
public:    virtual void                                       OnEnterProcessingRange( void );
public:    virtual void                                       OnExitProcessingRange( void );
public:    virtual GEBool                                     IsAutoKillEnabled( void ) const;
public:    virtual void                                       Decay( void );
public:    virtual void                                       GetBoundary( bCBox &, GEBool );
public:    virtual void                                       OnProcess( void );
public:    virtual void                                       OnCacheOut( void );
public:    virtual void                                       OnPrefetch( bCVector const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    char __FIXME[ 0x00A0 - sizeof(eCEntityPropertySet) ];
protected:
    void ApplyDefaults( void );
    void CreateEffect( void );
    void DestroyEffect( GEBool );
    void Invalidate( void );
    void Reset( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEEffectDecayMode > &        AccessDecayMode( void );
    bCString &                                        AccessEffect( void );
    bCString &                                        AccessEffectHigh( void );
    bCString &                                        AccessEffectMedium( void );
    GEBool &                                          AccessEnabled( void );
    bTPropertyContainer< gEEffectLoopMode > &         AccessLoopMode( void );
    bCRange1 &                                        AccessMaxNumRepeats( void );
    bCVector &                                        AccessOffset( void );
    bCRange1 &                                        AccessRepeatProbability( void );
    bCRange1 &                                        AccessSecondsBetweenRepeats( void );
    GEBool &                                          AccessStatic( void );
    bTPropertyContainer< gEEffectStopMode > &         AccessStopMode( void );
    bTPropertyContainer< gEEffectTargetMode > &       AccessTargetMode( void );
    eCScriptProxyScript &                             AccessTargetScript( void );
    GEBool &                                          AccessUseMaxRepeats( void );
    bTPropertyContainer< gEEffectDecayMode > const &  GetDecayMode( void ) const;
    bCString const &                                  GetEffect( void ) const;
    bCString const &                                  GetEffectHigh( void ) const;
    bCString const &                                  GetEffectMedium( void ) const;
    bCString                                          GetEffectiveEffect( gEEffectQuality ) const;
    GEBool const &                                    GetEnabled( void ) const;
    bTPropertyContainer< gEEffectLoopMode > const &   GetLoopMode( void ) const;
    bCRange1 const &                                  GetMaxNumRepeats( void ) const;
    bCVector const &                                  GetOffset( void ) const;
    bCRange1 const &                                  GetRepeatProbability( void ) const;
    bCRange1 const &                                  GetSecondsBetweenRepeats( void ) const;
    GEBool const &                                    GetStatic( void ) const;
    bTPropertyContainer< gEEffectStopMode > const &   GetStopMode( void ) const;
    bTPropertyContainer< gEEffectTargetMode > const & GetTargetMode( void ) const;
    eCScriptProxyScript const &                       GetTargetScript( void ) const;
    GEBool const &                                    GetUseMaxRepeats( void ) const;
    GEBool                                            IsRuntimeEffectStarted( bCString const & );
    void                                              SetDecayMode( bTPropertyContainer< gEEffectDecayMode > const & );
    void                                              SetEffect( bCString const & );
    void                                              SetEffectHigh( bCString const & );
    void                                              SetEffectMedium( bCString const & );
    void                                              SetEnabled( GEBool const & );
    void                                              SetLoopMode( bTPropertyContainer< gEEffectLoopMode > const & );
    void                                              SetMaxNumRepeats( bCRange1 const & );
    void                                              SetOffset( bCVector const & );
    void                                              SetRepeatProbability( bCRange1 const & );
    void                                              SetSecondsBetweenRepeats( bCRange1 const & );
    void                                              SetStatic( GEBool const & );
    void                                              SetStopMode( bTPropertyContainer< gEEffectStopMode > const & );
    void                                              SetTargetMode( bTPropertyContainer< gEEffectTargetMode > const & );
    void                                              SetTargetScript( eCScriptProxyScript const & );
    void                                              SetUseMaxRepeats( GEBool const & );
    void                                              Start( void );
    GEBool                                            StartEffect( bCString const &, GEBool );
    GEBool                                            StartRuntimeEffect( bCString const &, bCVector * );
    void                                              Stop( void );
    GEBool                                            StopAllRuntimeEffects( GEBool );
    GEBool                                            StopRuntimeEffect( bCString const &, GEBool );
public:
    gCEffect_PS & operator = ( gCEffect_PS const & );
public:
    gCEffect_PS( gCEffect_PS const & );
    gCEffect_PS( void );
};
GE_ASSERT_SIZEOF( gCEffect_PS, 0x00A0 )

#endif
