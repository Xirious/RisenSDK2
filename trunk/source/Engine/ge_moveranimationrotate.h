#ifndef GE_MOVERANIMATIONROTATE_H_INCLUDED
#define GE_MOVERANIMATIONROTATE_H_INCLUDED

class GE_DLLIMPORT eCMoverAnimationRotate :
    public eCMoverAnimationBase
{
GE_DECLARE_PROPERTY_OBJECT( eCMoverAnimationRotate, eCMoverAnimationBase )
public:    virtual GEU16             GetVersion( void ) const;
protected: virtual bEResult          Create( void );
protected: virtual void              Destroy( void );
protected: virtual bEResult          PostInitializeProperties( void );
public:    virtual GEBool            IsAnimationValid( void ) const;
public:    virtual void              GetBoundary( bCBox & );
public:    virtual eEAnimationUpdate GetMotion( GEFloat, bCVector &, bCQuaternion & );
public:    virtual GEFloat           GetEndTime( void ) const;
protected:
    GE_DECLARE_PROPERTY( bCEulerAngles, m_Axis,    Axis )
    GE_DECLARE_PROPERTY( GEFloat,       m_fLength, Length )
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCMoverAnimationRotate, 0x0048 )

#endif
