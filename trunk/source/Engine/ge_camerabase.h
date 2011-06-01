#ifndef GE_CAMERABASE_H_INCLUDED
#define GE_CAMERABASE_H_INCLUDED

enum eECamUpdate
{
    eECamUpdate_None       = 0,
    eECamUpdate_Viewport   = 0x00000001,
    eECamUpdate_Projection = 0x00000002,
    eECamUpdate_All        = eECamUpdate_Viewport | eECamUpdate_Projection,
    eECamUpdate_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT eCCameraBase :
    public bCObjectRefBase
{
public: virtual bEResult                   Init( HWND, GEFloat, GEFloat, GEFloat );
public: virtual bEResult                   Init( bCRect const &, GEFloat, GEFloat, GEFloat );
public: virtual bEResult                   Create( GEBool );
public: virtual void                       UpdateViewport( GEBool );
public: virtual void                       UpdateProjection( GEBool );
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual GEU16                      GetVersion( void ) const;
public: virtual GEBool                     IsValid( void ) const;
public: virtual GEBool                     OnRead( bCIStream & );
public: virtual GEBool                     OnWrite( bCOStream & );
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public: virtual GEU32                      AddReference( void );
public: virtual GEU32                      ReleaseReference( void );
public: virtual bEResult                   PostInitializeProperties( void );
public: virtual                           ~eCCameraBase( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bCMatrix          m_matViewMatrix;
    bCMatrix          m_matProjectionMatrix;
    bCVector          m_vecPosition;
    bCVector          m_vecRotation;
    bCVector          m_vecScale;
    bCVector2         m_vec2ClipProjection;
    bCVector2         m_vec2ClipDepth;
    bCRect            m_rectScreen;
    GEFloat           m_fFieldOfView;
    GEFloat           m_fAspectRatio;
    GEBool            m_bPerspective;
                      GE_PADDING( 3 )
    GEFloat           m_fDepthBias;
    bCVector          m_vecFocalRange;
    HWND              m_hWindow;
    eCFrustumDatabase m_FrustumDatabase;
    bCMatrix          m_matAudioListenerSpace;
    bCMatrix          m_matAudioReverbSpace;
    eCGfxCamera *     m_pGfxCamera;
protected:
    void CalcProjectionMatrix( void );
    void CalcViewMatrix( void );
    void CopyTo( eCCameraBase & ) const;
    void InitializeCamera( void );
    void Invalidate( void );
    void Update( eECamUpdate );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEFloat &                 AccessAspectRatio( void );
    bCVector2 &               AccessClipDepth( void );
    bCVector2 &               AccessClipProjection( void );
    GEFloat &                 AccessDepthBias( void );
    GEFloat &                 AccessFieldOfView( void );
    bCVector &                AccessFocalRange( void );
    GEBool &                  AccessPerspective( void );
    bCVector &                AccessPosition( void );
    bCMatrix &                AccessProjectionMatrix( void );
    bCVector &                AccessRotation( void );
    bCVector &                AccessScale( void );
    bCRect &                  AccessScreen( void );
    bCMatrix &                AccessViewMatrix( void );
    void                      Execute( eCFrustumDatabase::eSRenderTargetDesc * );
    void                      ExecuteGfxCamera( void );
    GEFloat const &           GetAspectRatio( void ) const;
    bCMatrix const &          GetAudioListenerSpace( void ) const;
    bCMatrix const &          GetAudioReverbSpace( void ) const;
    bCVector2 const &         GetClipDepth( void ) const;
    bCVector2 const &         GetClipProjection( void ) const;
    GEFloat const &           GetDepthBias( void ) const;
    GEFloat const &           GetFieldOfView( void ) const;
    bCVector const &          GetFocalRange( void ) const;
    eCFrustumDatabase const & GetFrustumDatabase( void ) const;
    eCFrustumDatabase &       GetFrustumDatabase( void );
    GEBool const &            GetPerspective( void ) const;
    bCVector const &          GetPosition( void ) const;
    bCMatrix const &          GetProjectionMatrix( void ) const;
    bCVector const &          GetRotation( void ) const;
    bCVector const &          GetScale( void ) const;
    bCRect const &            GetScreen( void ) const;
    bCMatrix                  GetScreenToWorldMatrix( void ) const;
    bCMatrix const &          GetViewMatrix( void ) const;
    bCMatrix                  GetWorldToScreenMatrix( void ) const;
    void                      GetZAxis( bCVector & ) const;
    void                      GoToEntity( eCEntity const & );
    GEBool                    IsOrthogonal( void ) const;
    void                      LookAt( bCVector const & );
    void                      Move( bCVector const & );
    void                      MoveForward( GEFloat, GEBool );
    void                      MoveHeight( GEFloat );
    void                      MoveLocal( bCVector const & );
    void                      MoveSideways( GEFloat );
    void                      PointToRay( bCPoint const &, bCRay & ) const;
    void                      PointToRay( bCPoint const &, bCUnitedRay & ) const;
    void                      RectToBox( bCRect const &, bCBox & ) const;
    bCFrustum                 RectToFrustum( bCRect const & ) const;
    void                      RectToFrustum( bCRect const &, bCFrustum & ) const;
    void                      Render( eCFrustumDatabase::eSRenderTargetDesc * );
    void                      RenderEntity( eCGeometryEntity * );
    void                      RenderShadowMap( eCShadowMapBase * );
    void                      Roll( GEFloat );
    void                      RotateAngularAbs( bCVector const & );
    void                      RotateAngularRel( bCVector const & );
    void                      RotateHeigth( GEFloat );
    void                      RotateSideways( GEFloat );
    void                      ScreenToView( bCVector & ) const;
    void                      ScreenToWorld( bCVector & ) const;
    void                      SetAspectRatio( GEFloat const & );
    void                      SetAudioListenerSpace( bCMatrix const & );
    void                      SetAudioReverbSpace( bCMatrix const & );
    void                      SetClipDepth( bCVector2 const & );
    void                      SetClipProjection( bCVector2 const & );
    void                      SetDepthBias( GEFloat const & );
    void                      SetFieldOfView( GEFloat const & );
    void                      SetFocalRange( bCVector const & );
    void                      SetPerspective( GEBool const & );
    void                      SetPosition( bCVector const & );
    void                      SetProjectionMatrix( bCMatrix const & );
    void                      SetRotation( bCVector const & );
    void                      SetScale( bCVector const & );
    void                      SetScreen( bCRect const & );
    void                      SetViewMatrix( bCMatrix const & );
    void                      TogglePerspectiveOrthogonal( void );
    void                      Update( void );
    void                      UpdateInitialValuesFromApp( void );
    void                      ViewToScreen( bCVector & ) const;
    void                      WorldToScreen( bCVector & ) const;
public:
    bCIStream &    operator << ( bCIStream & );
    bCOStream &    operator >> ( bCOStream & );
    eCCameraBase & operator =  ( eCCameraBase const & );
public:
    eCCameraBase( eCCameraBase const & );
    eCCameraBase( void );
};
GE_ASSERT_SIZEOF( eCCameraBase, 0x0C8C )

#endif
