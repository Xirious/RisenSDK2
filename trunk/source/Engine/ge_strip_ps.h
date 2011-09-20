#ifndef GE_STRIP_PS_H_INCLUDED
#define GE_STRIP_PS_H_INCLUDED

enum eEStripSpawning
{
    eEStripSpawning_Continuous,
    eEStripSpawning_Movement,
    eEStripSpawning_Timed,
    eEStripSpawning_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCStrip_PS'
                                   // class 'eCStrip_PS::CProcessor' needs to have dll-interface to be used by clients of class 'eCStrip_PS'

class GE_DLLIMPORT eCStrip_PS :
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
        eCStrip_PS * m_pStripPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( eCStrip_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
public:    virtual bEResult          Create( void );
public:    virtual void              Destroy( void );
public:    virtual GEBool            OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult          PostInitializeProperties( void );
public:    virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual                  ~eCStrip_PS( void );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsVisual( void ) const;
public:    virtual GEBool            IsEditorRelevant( void ) const;
public:    virtual eCRenderContext * CreateRenderContext( void );
public:    virtual void              GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual GEBool            IsClassProcessible( void ) const;
public:    virtual GEBool            IsClassProcessingEnabled( void ) const;
public:    virtual void              EnableClassProcessing( GEBool );
public:    virtual void              EnterProcessingRange( void );
public:    virtual void              ExitProcessingRange( void );
public:    virtual void              OnEnterProcessingRange( void );
public:    virtual void              OnExitProcessingRange( void );
public:    virtual void              GetBoundary( bCBox &, GEBool );
public:    virtual void              OnProcess( void );
public:    virtual void              OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
protected:
    GE_DECLARE_PROPERTY( bCFloatColor,    m_StartColor,         StartColor )
    GE_DECLARE_PROPERTY( GEFloat,         m_fStartAlpha,        StartAlpha )
    GE_DECLARE_PROPERTY( bCFloatColor,    m_EndColor,           EndColor )
    GE_DECLARE_PROPERTY( GEFloat,         m_fEndAlpha,          EndAlpha )
    GE_DECLARE_PROPERTY( bCVector,        m_vecOffsetLeft,      OffsetLeft )
    GE_DECLARE_PROPERTY( bCVector,        m_vecOffsetRight,     OffsetRight )
    GE_DECLARE_PROPERTY( GEFloat,         m_fSegmentsPerSecond, SegmentsPerSecond )
    GE_DECLARE_PROPERTY( GEFloat,         m_fSegmentLifeTime,   SegmentLifeTime )
    GE_DECLARE_PROPERTY( GEInt,           m_iMaxSegmentCount,   MaxSegmentCount )
    GE_DECLARE_PROPERTY( GEFloat,         m_fSegmentLenght,     SegmentLenght )
    GE_DECLARE_ENUMPROP( eEStripSpawning, m_enumSpawnMode,      SpawnMode )
    GE_DECLARE_PROPERTY( bCString,        m_strMaterial,        Material )
    GE_DECLARE_PROPERTY( GEBool,          m_bEnabled,           Enabled )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEInt,           m_iMaterialSwitch,    MaterialSwitch )
    GE_DECLARE_PROPERTY( GEFloat,         m_fFadeOutInSec,      FadeOutInSec )
    GE_DECLARE_PROPERTY( GEFloat,         m_fOpacity,           Opacity )
    GE_DECLARE_PROPERTY( GEFloat,         m_fVelocityLeft,      VelocityLeft )
    GE_DECLARE_PROPERTY( GEFloat,         m_fVelocityRight,     VelocityRight )
    CProcessor                            m_Processor;
    char __FIXME[ 0x00DC - 0x0094 ];
public:
    eCMaterialResource2 * GetMaterialResource( void ) const;
    void                  OnDeviceReset( void );
    void                  Render( GEFloat );
protected:
    void   CalculateExtents( bCBox & );
    GEBool CreateVertices( void );
    GEBool CreateVisual( void );
    void   Initialize( void );
    void   Invalidate( void );
    void   OnCapacityChanged( void );
    void   OnMaterialChanged( void );
    void   OnProcess( GEFloat, bCMatrix const & );
    void   OnTransform( bCMatrix const & );
    void   PushSegment( bCMatrix const & );
    void   RenderVertices( GEFloat );
    void   Reset( void );
    GEBool UpdateVertices( void );
};
GE_ASSERT_SIZEOF( eCStrip_PS, 0x00DC )

#pragma warning( pop )

#endif
