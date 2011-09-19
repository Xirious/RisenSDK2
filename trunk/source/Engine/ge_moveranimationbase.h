#ifndef GE_MOVERANIMATIONBASE_H_INCLUDED
#define GE_MOVERANIMATIONBASE_H_INCLUDED

enum eEAnimationUpdate
{
    eEAnimationUpdate_None        = 0x00000000,
    eEAnimationUpdate_Translation = 0x00000001,
    eEAnimationUpdate_Rotation    = 0x00000002,
    eEAnimationUpdate_All         = eEAnimationUpdate_Translation | eEAnimationUpdate_Rotation,
    eEAnimationUpdate_ForceDWORD  = GE_FORCE_DWORD
};

enum eEMoverPlayBackMode
{
    eEMoverPlayBackMode_Forward    = 0x00000000,
    eEMoverPlayBackMode_Backward   = 0x00000001,
    eEMoverPlayBackMode_PingPong   = 0x00000002,
    eEMoverPlayBackMode_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'eCMoverAnimationBase'

class GE_DLLIMPORT eCMoverAnimationBase :
    public bCObjectRefBase
{
public:    virtual GEBool            IsAnimationValid( void ) const;
public:    virtual void              GetBoundary( bCBox & );
public:    virtual void              Prefetch( void );
public:    virtual GEBool            UpdateTime( void );
public:    virtual eEAnimationUpdate UpdateMotion( bCVector &, bCQuaternion & );
public:    virtual eEAnimationUpdate GetMotion( GEFloat, bCVector &, bCQuaternion & );
public:    virtual GEFloat           GetEndTime( void ) const;
public:    virtual GEBool            Start( void );
public:    virtual GEBool            Stop( void );
public:    virtual GEBool            Pause( GEBool );
public:    virtual void              OnRenderDebug( void );
public:    virtual void              GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
GE_DECLARE_PROPERTY_OBJECT( eCMoverAnimationBase, bCObjectRefBase )
public:    virtual GEU16             GetVersion( void ) const;
protected: virtual bEResult          Create( void );
protected: virtual void              Destroy( void );
protected: virtual bEResult          PostInitializeProperties( void );
public:    virtual                  ~eCMoverAnimationBase( void );
protected:
    GE_DECLARE_PROPERTY( bCString,            m_strName,          Name )
    GE_DECLARE_ENUMPROP( eEMoverPlayBackMode, m_enumPlayBackMode, PlayBackMode )
    GE_DECLARE_PROPERTY( GEInt,               m_iLoopCount,       LoopCount )
    GE_DECLARE_PROPERTY( GEFloat,             m_fBlendTime,       BlendTime )
    GE_DECLARE_PROPERTY( GEFloat,             m_fTargetWeight,    TargetWeight )
    GE_DECLARE_PROPERTY( GEBool,              m_bBlendAdditive,   BlendAdditive )
    GE_PADDING( 3 )
    GE_DECLARE_PROPERTY( GEFloat,             m_fSpeed,           Speed )
    eCMover_PS *                              m_pMover;
    GEFloat                                   m_fFrameTime;
    GEFloat                                   m_fTime;
    GEBool                                    m_bIsPlaying;
    GEBool                                    m_bIsPaused;
    GE_PADDING1( 2 )
public:
    eCMover_PS * GetMover( void ) const;
    GEFloat      GetTime( void ) const;
    GEBool       HasReachedEnd( void ) const;
    GEBool       IsPaused( void ) const;
    GEBool       IsPlaying( void ) const;
    void         SetTime( GEFloat );
protected:
    void Invalidate( void );
    void SetMover( eCMover_PS * );
};
GE_ASSERT_SIZEOF( eCMoverAnimationBase, 0x0038 )

#pragma warning( pop )

#endif
