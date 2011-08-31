#ifndef GE_MOVERANIMATIONFILE_H_INCLUDED
#define GE_MOVERANIMATIONFILE_H_INCLUDED

class GE_DLLIMPORT eCMoverAnimationFile :
    public eCMoverAnimationBase
{
GE_DECLARE_PROPERTY_OBJECT( eCMoverAnimationFile, eCMoverAnimationBase )
public:    virtual GEU16             GetVersion( void ) const;
protected: virtual bEResult          Create( void );
protected: virtual void              Destroy( void );
protected: virtual bEResult          PostInitializeProperties( void );
protected: virtual GEBool            OnNotifyPropertyValueChangedExitEx( GELPCChar, GEBool );
public:    virtual GEBool            IsAnimationValid( void ) const;
public:    virtual void              Prefetch( void );
public:    virtual eEAnimationUpdate GetMotion( GEFloat, bCVector &, bCQuaternion & );
public:    virtual GEFloat           GetEndTime( void ) const;
public:    virtual void              GetDependencies( bTObjArray< bCString > &, bTObjArray< bCString > &, bTObjArray< eCTemplateEntityProxy > & );
protected:
    GE_DECLARE_PROPERTY( bCString, m_strAnimationFileName, AnimationFileName )
    GE_DECLARE_PROPERTY( bCString, m_strTrackName,         TrackName )
    eCMotionResource2 *            m_pResource;
    GEInt                          m_iTrack;
public:
    EMotionFX::SkeletalSubMotion * GetEMFXMotion( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCMoverAnimationFile, 0x0048 )

#endif
