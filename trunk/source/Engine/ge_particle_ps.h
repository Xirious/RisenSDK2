#ifndef GE_PARTICLE_PS_H_INCLUDED
#define GE_PARTICLE_PS_H_INCLUDED

enum eECoordinateSystem
{
    eECoordinateSystem_Independent,
    eECoordinateSystem_Relative,
    eECoordinateSystem_ForceDWORD = GE_FORCE_DWORD
};

enum eEFacingDirection
{
    eEFacingDirection_FacingCamera,
    eEFacingDirection_AlongMovementFacingCamera,
    eEFacingDirection_SpecifiedNormal,
    eEFacingDirection_AlongMovementFacingNormal,
    eEFacingDirection_PerpendicularToMovement,
    eEFacingDirection_ForceDWORD = GE_FORCE_DWORD
};

enum eELightingStyle
{
    eELightingStyle_Disabled,
    eELightingStyle_Flat,
    eELightingStyle_Particle,
    eELightingStyle_System,
    eELightingStyle_ForceDWORD = GE_FORCE_DWORD
};

enum eELocationShape
{
    eELocationShape_Box,
    eELocationShape_Sphere,
    eELocationShape_Mesh,
    eELocationShape_ForceDWORD = GE_FORCE_DWORD
};

enum eELocationTarget
{
    eELocationTarget_Self,
    eELocationTarget_Parent,
    eELocationTarget_Target,
    eELocationTarget_ForceDWORD = GE_FORCE_DWORD
};

enum eERotationFrom
{
    eERotationFrom_None,
    eERotationFrom_Entity,
    eERotationFrom_Offset,
    eERotationFrom_Normal,
    eERotationFrom_ForceDWORD = GE_FORCE_DWORD
};

enum eETextureDrawStyle
{
    eETextureDrawStyle_Regular,
    eETextureDrawStyle_AlphaBlend,
    eETextureDrawStyle_Modulated,
    eETextureDrawStyle_Translucent,
    eETextureDrawStyle_AlphaModulate,
    eETextureDrawStyle_Darken,
    eETextureDrawStyle_Brighten,
    eETextureDrawStyle_Invisible,
    eETextureDrawStyle_ForceDWORD = GE_FORCE_DWORD
};

enum eEVelocityDirectionFrom
{
    eEVelocityDirectionFrom_None,
    eEVelocityDirectionFrom_StartPositionAndOwner,
    eEVelocityDirectionFrom_OwnerAndStartPosition,
    eEVelocityDirectionFrom_Owner,
    eEVelocityDirectionFrom_World,
    eEVelocityDirectionFrom_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bCImageOrMaterialResourceString' needs to have dll-interface to be used by clients of class 'eCParticle_PS'
                                   // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCParticle_PS'
                                   // class 'eCParticle_PS::CProcessor' needs to have dll-interface to be used by clients of class 'eCParticle_PS'

class GE_DLLIMPORT eCParticle_PS :
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
        eCParticle_PS * m_pParticlePS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( eCParticle_PS, eCEntityPropertySet )
public: virtual GEU16                  GetVersion( void ) const;
public: virtual GEBool                 OnRead( bCIStream & );
public: virtual GEBool                 OnWrite( bCOStream & );
public: virtual bEResult               Create( void );
public: virtual void                   Destroy( void );
public: virtual GEBool                 OnCopyFrom( bCObjectBase const & );
public: virtual bEResult               PostInitializeProperties( void );
public: virtual GEBool                 OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public: virtual GEInt                  GetNativePropertyCount( void ) const;
public: virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;
public: virtual                       ~eCParticle_PS( void );
public: virtual eEPropertySetType      GetPropertySetType( void ) const;
public: virtual GEBool                 IsEditorRelevant( void ) const;
public: virtual GEBool                 IsTriggerable( void ) const;
public: virtual eCRenderContext *      CreateRenderContext( void );
public: virtual void                   GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public: virtual void                   OnTrigger( eCEntity *, eCEntity * );
public: virtual void                   OnUntrigger( eCEntity *, eCEntity * );
public: virtual GEBool                 IsClassProcessible( void ) const;
public: virtual GEBool                 IsClassProcessingEnabled( void ) const;
public: virtual void                   EnableClassProcessing( GEBool );
public: virtual void                   EnterProcessingRange( void );
public: virtual void                   ExitProcessingRange( void );
public: virtual GEBool                 IsAutoKillEnabled( void ) const;
public: virtual void                   Decay( void );
public: virtual void                   GetBoundary( bCBox &, GEBool );
public: virtual void                   OnProcess( void );
public: virtual void                   OnCacheIn( void );
public: virtual void                   OnCacheOut( void );
public: virtual void                   OnPrefetch( bCVector const & );
protected:
    GE_DECLARE_PROPERTY( GEInt,                           m_iMaxNumParticles,            MaxNumParticles )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fParticlesPerSecond,         ParticlesPerSecond )
    GE_DECLARE_PROPERTY( GEBool,                          m_bRespawnDeadParticles,       RespawnDeadParticles )
    GE_DECLARE_PROPERTY( GEBool,                          m_bAutomaticSpawning,          AutomaticSpawning )
    GE_DECLARE_PROPERTY( GEBool,                          m_bAutoReset,                  AutoReset )
    GE_DECLARE_PROPERTY( GEBool,                          m_bEnabled,                    Enabled )
    GE_DECLARE_PROPERTY( bCRange1,                        m_Lifetime,                    Lifetime )
    GE_DECLARE_PROPERTY( bCRange1,                        m_InitialAge,                  InitialAge )
    GE_DECLARE_PROPERTY( bCRange1,                        m_InitialDelay,                InitialDelay )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fTicksPerSecond,             TicksPerSecond )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fSecondsBeforeInactive,      SecondsBeforeInactive )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fRelativeWarmupTime,         RelativeWarmupTime )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fWarmupTicksPerSecond,       WarmupTicksPerSecond )
    GE_DECLARE_ENUMPROP( eELocationShape,                 m_enumStartLocationShape,      StartLocationShape )
    GE_DECLARE_ENUMPROP( eELocationTarget,                m_enumStartLocationTarget,     StartLocationTarget )
    GE_DECLARE_PROPERTY( bCRange3,                        m_StartBoxLocation,            StartBoxLocation )
    GE_DECLARE_PROPERTY( bCRange1,                        m_StartSphereRadius,           StartSphereRadius )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecStartLocationOffset,      StartLocationOffset )
    GE_DECLARE_ENUMPROP( eECoordinateSystem,              m_enumCoordinateSystem,        CoordinateSystem )
    GE_DECLARE_PROPERTY( bCRange3,                        m_StartVelocity,               StartVelocity )
    GE_DECLARE_PROPERTY( bCRange3,                        m_VelocityLoss,                VelocityLoss )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecAcceleration,             Acceleration )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecMaxAbsoluteVelocity,      MaxAbsoluteVelocity )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseVelocityScale,           UseVelocityScale )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fVelocityScaleRepeats,       VelocityScaleRepeats )
    GE_DECLARE_ENUMPROP( eEVelocityDirectionFrom,         m_enumVelocityDirectionFrom,   VelocityDirectionFrom )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fAddVelocityFromOwnerFactor, AddVelocityFromOwnerFactor )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fStiffness,                  Stiffness )
    GE_DECLARE_PROPERTY( eCEntityProxy,                   m_Target,                      Target )
    GE_DECLARE_PROPERTY( GEBool,                          m_bSpinParticles,              SpinParticles )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange3,                        m_StartSpin,                   StartSpin )
    GE_DECLARE_PROPERTY( bCRange3,                        m_SpinsPerSecond,              SpinsPerSecond )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fSpinDirection,              SpinDirection )
    GE_DECLARE_ENUMPROP( eEFacingDirection,               m_enumFacingDirection,         FacingDirection )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecProjectionNormal,         ProjectionNormal )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecRelativeSpinPivot,        RelativeSpinPivot )
    GE_DECLARE_ENUMPROP( eERotationFrom,                  m_enumUseRotationFrom,         UseRotationFrom )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseRevolution,              UseRevolution )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange3,                        m_RevolutionsPerSecond,        RevolutionsPerSecond )
    GE_DECLARE_PROPERTY( bCRange3,                        m_RevolutionCenterOffset,      RevolutionCenterOffset )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseRevolutionScale,         UseRevolutionScale )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fRevolutionScaleRepeats,     RevolutionScaleRepeats )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUniformSize,                UniformSize )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange3,                        m_StartSize,                   StartSize )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseSizeScale,               UseSizeScale )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fSizeScaleRepeats,           SizeScaleRepeats )
    GE_DECLARE_PROPERTY( GEBool,                          m_bStretchToEmitter,           StretchToEmitter )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCImageOrMaterialResourceString, m_strMaterial,                 Material )
    GE_DECLARE_PROPERTY( bCString,                        m_strTexture,                  Texture )
    GE_DECLARE_ENUMPROP( eETextureDrawStyle,              m_enumDrawStyle,               DrawStyle )
    GE_DECLARE_PROPERTY( GEInt,                           m_iNumUSubdivisions,           NumUSubdivisions )
    GE_DECLARE_PROPERTY( GEInt,                           m_iNumVSubdivisions,           NumVSubdivisions )
    GE_DECLARE_PROPERTY( GEInt,                           m_iSubdivisionStart,           SubdivisionStart )
    GE_DECLARE_PROPERTY( GEInt,                           m_iSubdivisionEnd,             SubdivisionEnd )
    GE_DECLARE_PROPERTY( GEBool,                          m_bRandomSubdivision,          RandomSubdivision )
    GE_DECLARE_PROPERTY( GEBool,                          m_bBlendBetweenSubdivisions,   BlendBetweenSubdivisions )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseSubdivisionScale,        UseSubdivisionScale )
    GE_DECLARE_PROPERTY( GEBool,                          m_bSubdivisionRowMajor,        SubdivisionRowMajor )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fSubdivisionScaleRepeats,    SubdivisionScaleRepeats )
    GE_DECLARE_PROPERTY( GEBool,                          m_bFadeIn,                     FadeIn )
    GE_DECLARE_PROPERTY( GEBool,                          m_bFadeOut,                    FadeOut )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fFadeInEndTime,              FadeInEndTime )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fFadeOutStartTime,           FadeOutStartTime )
    GE_DECLARE_PROPERTY( bCFloatAlphaColor,               m_FaceInFactor,                FaceInFactor )
    GE_DECLARE_PROPERTY( bCFloatAlphaColor,               m_FaceOutFactor,               FaceOutFactor )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseColorScale,              UseColorScale )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fColorScaleRepeats,          ColorScaleRepeats )
    GE_DECLARE_PROPERTY( GEBool,                          m_bDisableFogging,             DisableFogging )
    GE_DECLARE_PROPERTY( GEBool,                          m_bAlphaTest,                  AlphaTest )
    GE_DECLARE_PROPERTY( GEU8,                            m_u8AlphaReference,            AlphaReference )
    GE_DECLARE_PROPERTY( GEBool,                          m_bDepthTest,                  DepthTest )
    GE_DECLARE_PROPERTY( GEBool,                          m_bDepthWrite,                 DepthWrite )
    GE_DECLARE_PROPERTY( GEBool,                          m_bInstanced,                  Instanced )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fDepthSortOffset,            DepthSortOffset )
    GE_DECLARE_ENUMPROP( eELightingStyle,                 m_enumLightingStyle,           LightingStyle )
    GE_DECLARE_PROPERTY( GEBool,                          m_bResetOnTrigger,             ResetOnTrigger )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange1,                        m_TriggerNumParticles,         TriggerNumParticles )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fTriggerParticlesPerSecond,  TriggerParticlesPerSecond )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseCollision,               UseCollision )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseMaxCollisions,           UseMaxCollisions )
    GE_PADDING( 2 )
    GE_DECLARE_PROPERTY( bCRange1,                        m_MaxCollisions,               MaxCollisions )
    GE_DECLARE_PROPERTY( bCRange3,                        m_DampingFactor,               DampingFactor )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseRotationDamping,         UseRotationDamping )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange3,                        m_RotationDampingFactor,       RotationDampingFactor )
    GE_DECLARE_PROPERTY( bCVector,                        m_vecExtentMultiplier,         ExtentMultiplier )
    GE_DECLARE_PROPERTY( GEFloat,                         m_fMinSquaredVelocity,         MinSquaredVelocity )
    GE_DECLARE_PROPERTY( GEBool,                          m_bCollideWithCharacters,      CollideWithCharacters )
    GE_DECLARE_PROPERTY( GEBool,                          m_bCollideWithDynamic,         CollideWithDynamic )
    GE_DECLARE_PROPERTY( GEBool,                          m_bCollideWithStatic,          CollideWithStatic )
    GE_DECLARE_PROPERTY( GEBool,                          m_bCollideWithTransparent,     CollideWithTransparent )
    GE_DECLARE_PROPERTY( eCEntityProxy,                   m_SpawnFromOtherEmitter,       SpawnFromOtherEmitter )
    GE_DECLARE_PROPERTY( bCRange1,                        m_SpawnNumParticles,           SpawnNumParticles )
    GE_DECLARE_PROPERTY( GEBool,                          m_bUseSpawnedVelocityScale,    UseSpawnedVelocityScale )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( bCRange3,                        m_SpawnedVelocityScale,        SpawnedVelocityScale )
    GE_DECLARE_PROPERTY( bCRange1,                        m_GlobalSizeScale,             GlobalSizeScale )
    CProcessor                                            m_Processor;
    char __FIXME[ 0x03C4 - 0x02D4 ];
public:
    void                  ApplyDefaults( void );
    GEBool                CreateMaterial( void );
    eCMaterialResource2 * GetMaterialResource( void ) const;
    void                  OnDeviceReset( void );
    void                  Render( GEFloat );
    void                  Reset( void );
protected:
    GEBool ApplyRenderStates( GEFloat, bCMatrix const & );
    void   CalcColor( GEFloat, bCFloatAlphaColor & ) const;
    void   CalcColorFactor( GEFloat, GEFloat, bCFloatAlphaColor & ) const;
    void   CalcExtents( bCBox & ) const;
    void   CalcFrame( GEFloat, GEFloat & ) const;
    void   CalcRevolutionFactor( GEFloat, bCVector & ) const;
    void   CalcSizeFactor( GEFloat, bCVector & ) const;
    void   CalcVelocityFactor( GEFloat, bCVector & ) const;
    void   CopyFromMaster( eCParticle_PS const * );
    GEBool CreateImage( void );
    GEBool CreateVertices( void );
    GEBool CreateVisual( void );
    void   DepthSortParticles( void );
    GEBool DoAutoKill( void );
    void   DoProcessV2( void );
    void   Dump( void ) const;
    GEInt  EmitParticles( GEFloat, GEFloat, GEInt );
    void   GetRandomFrame( GEInt & ) const;
    void   GetRandomSpherePoint( bCVector & ) const;
    void   Initialize( void );
    void   Invalidate( void );
    void   OnCapacityChanged( void );
    void   OnMaterialChanged( void );
    void   OnTextureChanged( void );
    GEInt  ProcessFrame( GEFloat );
    GEInt  ProcessTicks( GEInt, GEFloat );
    GEBool RenderPasses( eCIlluminated_PS * );
    GEBool RenderVertices( GEFloat, eCParticle_PS * );
    void   ResetBuffers( void );
    GEInt  TickParticles( GEFloat );
    GEBool UpdateVertices( void );
};
GE_ASSERT_SIZEOF( eCParticle_PS, 0x03C4 )

#pragma warning( pop )

#endif
