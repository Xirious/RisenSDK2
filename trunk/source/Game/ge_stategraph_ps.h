#ifndef GE_STATEGRAPH_PS_H_INCLUDED
#define GE_STATEGRAPH_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'gCStateGraph_PS'
                                   // class 'bTRefPropertyArray<T>' needs to have dll-interface to be used by clients of class 'gCStateGraph_PS'
                                   // class 'bTRefPtrArray<T>' needs to have dll-interface to be used by clients of class 'gCStateGraph_PS'
                                   // class 'gCStateGraph_PS::CProcessor' needs to have dll-interface to be used by clients of class 'gCStateGraph_PS'

class GE_DLLIMPORT gCStateGraph_PS :
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
        gCStateGraph_PS * m_pStateGraphPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( gCStateGraph_PS, eCEntityPropertySet )
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual GEBool                                     OnCopyFrom( bCObjectBase const & );
public:    virtual GEBool                                     OnCopyPatchableOnly( bCObjectBase const & );
public:    virtual bEResult                                   PostInitializeProperties( void );
public:    virtual GEBool                                     OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                                           ~gCStateGraph_PS( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual bEResult                                   ReadSaveGame( bCIStream & );
public:    virtual bEResult                                   WriteSaveGame( bCOStream & );
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
public:    virtual void                                       GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected: virtual void                                       OnTrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnUntrigger( eCEntity *, eCEntity * );
protected: virtual void                                       OnTouch( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnUntouch( eCEntity *, eCContactIterator & );
protected: virtual void                                       OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );
public:    virtual GEBool                                     IsClassProcessible( void ) const;
public:    virtual GEBool                                     IsClassProcessingEnabled( void ) const;
public:    virtual void                                       EnableClassProcessing( GEBool );
public:    virtual void                                       EnterProcessingRange( void );
public:    virtual void                                       ExitProcessingRange( void );
public:    virtual void                                       OnRenderDebug( void );
protected: virtual void                                       OnProcess( void );
public:    virtual void                                       OnCacheIn( void );
public:    virtual void                                       OnCacheOut( void );
protected:
    GE_DECLARE_PROPERTY( bTRefPtrArray< gCStateGraphState * >,            m_arrStates,             States )
    GE_DECLARE_PROPERTY( bCString,                                        m_strDefaultState,       DefaultState )
    GE_DECLARE_PROPERTY( bTObjArray< eCEntityProxy >,                     m_arrTriggerTargets,     TriggerTargets )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,                             m_OnEnterState,          OnEnterState )
    GE_DECLARE_PROPERTY( eCScriptProxyScript,                             m_OnExitState,           OnExitState )
    GE_DECLARE_PROPERTY( bTRefPropertyArray< gCStateGraphEventFilter * >, m_arrTriggerEventFilter, TriggerEventFilter )
    GE_DECLARE_PROPERTY( bTRefPropertyArray< gCStateGraphEventFilter * >, m_arrTouchEventFilter,   TouchEventFilter )
    CProcessor                                                            m_Processor;
    char __FIXME[ 0x0080 - 0x0064 ];
public:
    static GEBool GE_STDCALL GetRenderDebug( void );
    static void   GE_STDCALL SetRenderDebug( GEBool );
public:
    GEBool              CanGoToState( bCString const & );
    GEBool              ClearPath( void );
    GEBool              DeleteState( bCString const & );
    gCStateGraphState * GetCurrentState( void ) const;
    gCStateGraphState * GetStateAt( GEInt ) const;
    gCStateGraphState * GetStateByName( bCString const & ) const;
    GEInt               GetStateCount( void ) const;
    GEInt               GetStateIndex( bCString const & ) const;
    GEI32               GetTouchEventCount( void ) const;
    GEI32               GetTriggerEventCount( void ) const;
    GEBool              GoToState( bCString const & );
    GEBool              GoToState( gCStateGraphState * );
    gCStateGraphState * InsertNewState( bCString const & );
    GEBool              IsInState( bCString const & );
    void                SetCurrentState( gCStateGraphState * );
protected:
    static eCPrimitiveStateGraphArrow ms_StateGraphArrow;
    static eCPrimitiveStateGraphLine  ms_StateGraphLine;
    static GEBool                     ms_bRenderDebug;
protected:
    GEBool CallOnEnterScript( void );
    GEBool CallOnExitScript( void );
    GEBool CopyStatesFrom( gCStateGraph_PS const *, GEBool );
    GEBool FindPath( gCStateGraphState *, gCStateGraphState *, GEBool );
    void   Invalidate( void );
};
GE_ASSERT_SIZEOF( gCStateGraph_PS, 0x0080 )

#pragma warning( pop )

#endif
