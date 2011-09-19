#ifndef GE_INFOCOMMANDSTARTFIXCAMERA_H_INCLUDED
#define GE_INFOCOMMANDSTARTFIXCAMERA_H_INCLUDED

class GE_DLLIMPORT gCInfoCommandStartFixCamera :
    public gCInfoCommand
{
GE_DECLARE_PROPERTY_OBJECT( gCInfoCommandStartFixCamera, gCInfoCommand )
public: virtual void            Destroy( void );
public: virtual                ~gCInfoCommandStartFixCamera( void );
public: virtual gEInfoCommand   GetCommandType( void ) const;
public: virtual eCEntityProxy & GetEntityProxy1( gCRuntimeInfo & );
public: virtual eCEntityProxy & GetEntityProxy2( gCRuntimeInfo & );
public: virtual void            ResetProxies( void );
public: virtual GEBool          Execute( gCRuntimeInfo &, GEBool );
public: virtual GEBool          IsValid( bCString &, gCInfo const & ) const;
public: virtual void            OnAttachedToInfo( gCInfo const & );
public: using  bCObjectRefBase::IsValid;
protected:
    GE_DECLARE_PROPERTY( bCString, m_strCameraTarget,        CameraTarget )
    GE_DECLARE_PROPERTY( bCString, m_strCameraPosition,      CameraPosition )
    GE_DECLARE_PROPERTY( bCVector, m_vecTargetOffset,        TargetOffset )
    GE_DECLARE_PROPERTY( GEFloat,  m_fBestDistance,          BestDistance )
    GE_DECLARE_PROPERTY( GEFloat,  m_fMinDistance,           MinDistance )
    GE_DECLARE_PROPERTY( GEFloat,  m_fMaxDistance,           MaxDistance )
    GE_DECLARE_PROPERTY( GEFloat,  m_fCameraYawAngle,        CameraYawAngle )
    GE_DECLARE_PROPERTY( GEFloat,  m_fCameraPitchAngle,      CameraPitchAngle )
    GE_DECLARE_PROPERTY( GEFloat,  m_fFOV,                   FOV )
    GE_DECLARE_PROPERTY( GEFloat,  m_fFOVChangeSpeed,        FOVChangeSpeed )
    GE_DECLARE_PROPERTY( GEFloat,  m_fMoveSpeedMax,          MoveSpeedMax )
    GE_DECLARE_PROPERTY( GEFloat,  m_fRotationSpeedMax,      RotationSpeedMax )
    GE_DECLARE_PROPERTY( GEFloat,  m_fMoveAcceleration,      MoveAcceleration )
    GE_DECLARE_PROPERTY( GEFloat,  m_fMoveDecceleration,     MoveDecceleration )
    GE_DECLARE_PROPERTY( GEFloat,  m_fRotationAcceleration,  RotationAcceleration )
    GE_DECLARE_PROPERTY( GEFloat,  m_fRotationDecceleration, RotationDecceleration )
    GE_DECLARE_PROPERTY( GEBool,   m_bForceCameraReset,      ForceCameraReset )
    GE_PADDING( 3 )
    eCEntityProxy                  m_EntityProxy1;
    eCEntityProxy                  m_EntityProxy2;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoCommandStartFixCamera, 0x0064 )

#endif
