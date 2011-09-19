#ifndef GE_MOVERANIMATIONSKELETAL_H_INCLUDED
#define GE_MOVERANIMATIONSKELETAL_H_INCLUDED

class GE_DLLIMPORT eCMoverAnimationSkeletal :
    public eCMoverAnimationBase
{
GE_DECLARE_PROPERTY_OBJECT( eCMoverAnimationSkeletal, eCMoverAnimationBase )
public:    virtual GEU16    GetVersion( void ) const;
protected: virtual bEResult Create( void );
protected: virtual void     Destroy( void );
protected: virtual bEResult PostInitializeProperties( void );
protected: virtual GEBool   OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual         ~eCMoverAnimationSkeletal( void );
public:    virtual GEBool   IsAnimationValid( void ) const;
public:    virtual void     Prefetch( void );
public:    virtual GEBool   UpdateTime( void );
public:    virtual GEFloat  GetEndTime( void ) const;
public:    virtual void     GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected:
    GE_DECLARE_PROPERTY( bCString, m_strAnimationFileName, AnimationFileName )
    eCMotionResource2 *            m_pResource;
    EMotionFX::MotionInstance *    m_pInstance;
public:
    EMotionFX::ActorInstance const * GetEMFXActor( void ) const;
    EMotionFX::Motion *              GetEMFXMotion( void ) const;
    EMotionFX::MotionInstance *      GetEMFXMotionInstance( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCMoverAnimationSkeletal, 0x0044 )

#endif
