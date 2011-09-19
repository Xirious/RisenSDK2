#ifndef GE_DYNAMICCOLLISIONCIRCLE_PS_H_INCLUDED
#define GE_DYNAMICCOLLISIONCIRCLE_PS_H_INCLUDED

class GE_DLLIMPORT gCDynamicCollisionCircle_PS :
    public eCEntityPropertySet
{
GE_DECLARE_PROPERTY_OBJECT( gCDynamicCollisionCircle_PS, eCEntityPropertySet )
public: virtual GEU16             GetVersion( void ) const;
public: virtual GEBool            OnRead( bCIStream & );
public: virtual GEBool            OnWrite( bCOStream & );
public: virtual bEResult          Create( void );
public: virtual void              Destroy( void );
public: virtual                  ~gCDynamicCollisionCircle_PS( void );
public: virtual eEPropertySetType GetPropertySetType( void ) const;
public: virtual GEBool            IsEntityListener( void ) const;
public: virtual void              OnEnterProcessingRange( void );
public: virtual void              GetBoundary( bCBox &, GEBool );
public: virtual void              OnPostRead( void );
public: virtual GEBool            OnListenEntityEvent( eSEntityListenerEvent const & );
protected:
    GE_DECLARE_PROPERTY( GEFloat, m_fRadius, Radius )
    char __FIXME[ 0x00C4 - 0x0014 ];
public:
    bTValArray< bCMotion > &       AccessCorrectedPose( void );
    bCMotion &                     AccessLastFramePose( void );
    bCMotion &                     AccessWantedPose( void );
    bCMotion                       CalcAltStandInterPose( gCDynamicCollisionCircle_PS const *, GEInt );
    void                           CalcEvadeForFrontalMeeting( gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &, bCVector const &, GEBool, GEBool, GEBool );
    void                           CalcEvadeForOverhaul( gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &, bCVector const &, GEBool, GEBool );
    void                           CalcEvadeForStandardMeeting( gCDynamicCollisionCircle_PS *, gCDynamicCollisionCircle_PS *, bCVector const &, bCVector const &, GEBool, GEBool );
    void                           CalcMoveInterPose( bCVector const &, gCDynamicCollisionCircle_PS *, bCVector const &, GEBool, GEBool, GEBool );
    void                           CalcNewWantedPose( GEFloat );
    bCMotion                       CalcPreferedStandInterPose( bCVector const &, gCDynamicCollisionCircle_PS const *, eCEntity const *, gCNavigation_PS *, GEBool );
    void                           CreateCollisionCirclePSObject( gCNavZone_PS * );
    void                           DestroyCollisionCirclePSObject( void );
    gCCharacterMovement_PS *       GetCharacterMovement( void ) const;
    bTValArray< bCMotion > const & GetCorrectedPose( void ) const;
    GEFloat                        GetCurrentRadius( void ) const;
    GEBool                         GetDCCEnabled( void ) const;
    GEBool                         GetEnabled( void ) const;
    bCMotion const &               GetLastFramePose( void ) const;
    gCNavigation_PS *              GetNavigation( void ) const;
    bCMotion const &               GetWantedPose( void ) const;
    void                           SetCharacterMovement( gCCharacterMovement_PS * );
    void                           SetCorrectedPose( bTValArray< bCMotion > const & );
    void                           SetDCCEnabled( GEBool );
    void                           SetEnabled( GEBool );
    void                           SetLastFramePose( bCMotion const & );
    void                           SetNavigation( gCNavigation_PS * );
    void                           SetWantedPose( bCMotion const & );
    GEBool                         TestNewInterPose( bCMotion &, GEBool );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCDynamicCollisionCircle_PS, 0x00C4 )

#endif
