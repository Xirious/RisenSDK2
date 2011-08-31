#ifndef GE_MOVER_PS_H_INCLUDED
#define GE_MOVER_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTRefPtrArray<T>' needs to have dll-interface to be used by clients of class 'eCMover_PS'
                                   // class 'eCMover_PS::CProcessor' needs to have dll-interface to be used by clients of class 'eCMover_PS'

class GE_DLLIMPORT eCMover_PS :
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
        eCMover_PS * m_pMoverPS;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( eCMover_PS, eCEntityPropertySet )
public:    virtual GEU16             GetVersion( void ) const;
public:    virtual GEBool            OnRead( bCIStream & );
public:    virtual GEBool            OnWrite( bCOStream & );
protected: virtual bEResult          Create( void );
protected: virtual void              Destroy( void );
public:    virtual GEBool            OnCopyFrom( bCObjectBase const & );
public:    virtual GEBool            OnCopyPatchableOnly( bCObjectBase const & );
protected: virtual bEResult          PostInitializeProperties( void );
public:    virtual eEPropertySetType GetPropertySetType( void ) const;
public:    virtual GEBool            IsReferencedByTemplate( void ) const;
public:    virtual void              GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
public:    virtual GEBool            IsClassProcessible( void ) const;
public:    virtual GEBool            IsClassProcessingEnabled( void ) const;
public:    virtual void              EnableClassProcessing( GEBool );
public:    virtual void              EnterProcessingRange( void );
public:    virtual void              ExitProcessingRange( void );
public:    virtual void              OnRenderDebug( void );
public:    virtual void              GetBoundary( bCBox &, GEBool );
public:    virtual void              OnProcess( void );
public:    virtual void              OnPostRead( void );
public:    virtual void              OnUpdatedLocalMatrix( void );
public:    virtual GEBool            OnListenEntityEvent( eSEntityListenerEvent const & );
public:    virtual void              OnPrefetch( bCVector const & );
protected:
    GE_DECLARE_PROPERTY( bCString,          m_strDefaultAnimation, DefaultAnimation )
    CProcessor                              m_Processor;
    bTRefPtrArray< eCMoverAnimationBase * > m_arrAnimations;
    bCMatrix                                m_matBaseMatrix;
    GEBool                                  m_bBaseMatrixUpdateLocked;
    GE_PADDING( 3 )
    eEAnimationUpdate                       m_enumAutoKeyFraming;
    GEInt                                   m_iAutoKeyFrameAnimation;
    GEFloat                                 m_fAutoKeyFrameTime;
    GEInt                                   m_iAnimationsPlaying;
public:
    void                   AddAnimation( eCMoverAnimationBase * );
    eCMoverAnimationBase * GetAnimation( bCString const & ) const;
    eCMoverAnimationBase * GetAnimationAt( GEInt ) const;
    GEInt                  GetAnimationCount( void ) const;
    GEInt                  GetAnimationIndex( bCString const & ) const;
    GEInt                  GetAnimationIndex( eCMoverAnimationBase * ) const;
    GEInt                  GetAutoKeyFrameAnimation( void ) const;
    GEFloat                GetAutoKeyFrameTime( void ) const;
    eEAnimationUpdate      GetAutoKeyFraming( void ) const;
    bCMatrix const &       GetBaseMatrix( void ) const;
    GEBool                 IsAnimationPlaying( bCString const & ) const;
    void                   LockBaseMatrixUpdate( GEBool );
    GEBool                 PauseAnimation( bCString const &, GEBool );
    void                   RemoveAnimation( eCMoverAnimationBase * );
    void                   SetAutoKeyFrameAnimation( GEInt );
    void                   SetAutoKeyFrameTime( GEFloat );
    void                   SetAutoKeyFraming( eEAnimationUpdate );
    void                   SetBaseMatrix( bCMatrix const & );
    GEBool                 StartAnimation( bCString const & );
    void                   StopAll( void );
    GEBool                 StopAnimation( bCString const & );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCMover_PS, 0x0084 )

#pragma warning( pop )

#endif
