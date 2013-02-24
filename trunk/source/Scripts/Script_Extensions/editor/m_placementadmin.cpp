#include "m_placementadmin.h"
#include "m_gizmotranslate.h"
#include "../console/m_consolevaradmin.h"
#include "../m_hook.h"
#include "../m_hacks.h"
#include "../m_utils.h"

#pragma warning( push )
#pragma warning( disable : 4738 )  // storing 32-bit float result in memory, possible loss of performance

namespace
{
    class CRenderContext
    {
    public:
        CRenderContext( void ) :
            m_pGfxMixerAdmin( eCGfxMixerAdmin::GetInstance() )
        {
            m_pGfxMixerAdmin->GetMasterDepthTesting( m_enuMasterCmpFunc );
            m_pGfxMixerAdmin->GetMasterDepthWrite( m_enuMasterDepthWrite );
        }
        CRenderContext( GEU32 a_u32MasterCmpFunc, GEU32 a_u32MasterDepthWrite ) :
            m_pGfxMixerAdmin( eCGfxMixerAdmin::GetInstance() )
        {
            m_pGfxMixerAdmin->GetMasterDepthTesting( m_enuMasterCmpFunc );
            m_pGfxMixerAdmin->GetMasterDepthWrite( m_enuMasterDepthWrite );
            ( *this )( a_u32MasterCmpFunc, a_u32MasterDepthWrite );
        }
        ~CRenderContext( void )
        {
            ( *this )( m_enuMasterCmpFunc, m_enuMasterDepthWrite );
        }
    public:
        eCGfxMixerAdmin * operator () ( GEU32 a_u32MasterCmpFunc, GEU32 a_u32MasterDepthWrite )
        {
            m_pGfxMixerAdmin->SetMasterDepthTesting( static_cast< eCGfxShared::eEMasterCmpFunc >( a_u32MasterCmpFunc ) );
            m_pGfxMixerAdmin->SetMasterDepthWrite( static_cast< eCGfxShared::eEMasterWrite >( a_u32MasterDepthWrite ) );
            return m_pGfxMixerAdmin;
        }
        eCGfxMixerAdmin * operator -> ( void )
        {
            return m_pGfxMixerAdmin;
        }
    private:
        CRenderContext( CRenderContext const & ) {}
    private:
        CRenderContext & operator = ( CRenderContext const & ) {}
    private:
        eCGfxMixerAdmin *            m_pGfxMixerAdmin;
        eCGfxShared::eEMasterCmpFunc m_enuMasterCmpFunc;
        eCGfxShared::eEMasterWrite   m_enuMasterDepthWrite;
    };

    bEResult On_eCFrustumDatabase_Execute_C13( void )
    {
        mCPlacementAdmin::GetInstance().OnRender();
        return ( *mCCallHook::GetOriginalFunctionProxy( &On_eCFrustumDatabase_Execute_C13 ) )();
    }

    mCCallHook s_RenderHook( g_CallHookParams( &eCFrustumDatabase::Execute, &On_eCFrustumDatabase_Execute_C13, GETrue, 0xC13 ) );
}

mCPlacementAdmin * mCPlacementAdmin::s_pInstance = 0;

mCPlacementAdmin & mCPlacementAdmin::GetInstance( void )
{
    if ( !s_pInstance )
        s_pInstance = new mCPlacementAdmin;
    return *s_pInstance;
}

void mCPlacementAdmin::AlignLocalTranslation( GEFloat a_fGridSpacing )
{
    bCVector vecTranslation = m_matLocalTransform.GetTranslation() / a_fGridSpacing;
    for ( GEInt i = 0; i != 3; ++i )
        if ( m_iPrimaryTransformAxis == i || m_iSecondaryTransformAxis == i )
            vecTranslation[ i ] = g_floorf( vecTranslation[ i ] + 0.5f );
    m_matLocalTransform.AccessTranslation() = vecTranslation * a_fGridSpacing;
    m_matLocalTransformBase = m_matLocalTransform;
    UpdateWorldTransform();
}

void mCPlacementAdmin::AttachSecondarySelection( GEBool a_bPreserveTransform )
{
    if ( !GetSecondarySelection() )
        return;
    eCDynamicEntity * pSelectionOld = GetSelection();
    g_swap( m_arrSecondarySelectionBuffer, m_arrSelectionBuffer );
    m_iSelection = m_iSecondarySelection;
    SetSecondarySelectionActive( GEFalse );
    AttachSelection( GETrue );
    if ( a_bPreserveTransform )
    {
        m_matWorldTransform = m_matWorldTransformOld;
        DecomposeWorldTransform();
        return;
    }
    if ( !pSelectionOld )
    {
        DecomposeWorldTransform();
        return;
    }
    if ( m_bFreeMode )
    {
        m_matWorldTransform = m_matWorldTransformOld;
        DecomposeWorldTransform();
        ResetTransform();
        return;
    }
    ResetTransform();
}

void mCPlacementAdmin::ApplyPendingTransform( void )
{
    m_matLocalTransformBase = m_matLocalTransform;
}

void mCPlacementAdmin::ClearSelection( void )
{
    if ( m_bSpawnMode )
        m_iTemplate = -1;
    eCDynamicEntity * pSelection = GetSelection();
    m_arrSelectionBuffer.Clear();
    DecomposeWorldTransform();
    if ( pSelection && !m_bEntityAttached )
        ResetTransform();
    if ( !pSelection || !m_bEntityAttached )
        return;
    DetachEntity();
    if ( m_bOriginalEntityAttached && !m_bSpawnMode )
        pSelection->SetWorldMatrix( m_matWorldTransformOld );
    DeleteEntity( pSelection, m_bOriginalEntityAttached && !m_bSpawnMode );
}

void mCPlacementAdmin::DeleteSecondarySelection( void )
{
    if ( !m_bSecondarySelectionActive )
        return;
    DeleteEntity( GetSecondarySelection(), GETrue );
    SetSecondarySelectionActive( GEFalse );
    SetSecondarySelectionActive( GETrue );
}

void mCPlacementAdmin::DetachClone( void )
{
    eCDynamicEntity * pSelection = GetSelection();
    if ( !m_bEntityAttached || !pSelection )
        return;
    bCMemoryStream streamEntityData;
    pSelection->OnWrite( streamEntityData );
    gCDynamicLayer * pLayer = GetLayer( pSelection );
    if ( !pLayer )
        return;
    eCDynamicEntity * pClone = pLayer->CreateDynamicEntity();
    streamEntityData.Seek( 0, bEStreamSeekMode_Begin );
    pClone->OnRead( streamEntityData );
    m_arrSelectionBuffer[ m_iSelection ] = pClone;
    AttachSelection( GETrue );
    m_bOriginalEntityAttached = GEFalse;
}

void mCPlacementAdmin::DetachEntity( void )
{
    AttachSelection( GEFalse );
    m_arrSelectionBuffer.Clear();
}

void mCPlacementAdmin::Disable( void )
{
    SetSecondarySelectionActive( GEFalse );
    ClearSelection();
    SetHighlightedEntity( 0 );
    m_bEnabled = GEFalse;
}

void mCPlacementAdmin::EditSelection( void )
{
    if ( m_bSpawnMode )
        return;
    Entity Selection( GetSelection() );
    if ( !Selection.GetInstance() )
        return;
    gui2.ShowConsole( GETrue );
    gui2.ShowPropertyEditor( Selection, GETrue );
}

void mCPlacementAdmin::Enable( void )
{
    if ( m_bEnabled )
        return;
    m_iPrimaryTransformAxis = m_iSecondaryTransformAxis = -1;
    m_bEnabled = GETrue;
    ClearSelection();
    SetCurrentEntity( 0 );
    ResetTransform();
    OnProcess();
    if ( m_bSpawnMode )
        OnFilterChanged();
}

void mCPlacementAdmin::GetActiveTransformAxes( GEInt & a_iPrimaryAxis, GEInt & a_iSecondaryAxis )
{
    a_iPrimaryAxis = m_iPrimaryTransformAxis;
    a_iSecondaryAxis = m_iSecondaryTransformAxis;
}

bCMatrix const & mCPlacementAdmin::GetCameraTransform( void ) const
{
    return m_matCameraTransform;
}

bCMatrix const & mCPlacementAdmin::GetTransformationSpace( void ) const
{
    if ( m_bCameraSpace )
        return m_matCameraTransformAdjusted;
    return m_matWorldTransform;
}

GEBool mCPlacementAdmin::IsEnabled( void ) const
{
    return m_bEnabled;
}

GEBool mCPlacementAdmin::IsEntityAttached( void ) const
{
    return m_bEntityAttached;
}

GEBool mCPlacementAdmin::IsInPickMode( void ) const
{
    return m_bEnabled && !m_bSpawnMode;
}

GEBool mCPlacementAdmin::IsInSpawnMode( void ) const
{
    return m_bEnabled && m_bSpawnMode;
}

void mCPlacementAdmin::LockSelection( void )
{
    eCDynamicEntity * pSelection = GetSelection();
    m_arrSelectionBuffer.Clear();
    m_arrSelectionBuffer.Add( pSelection );
    m_iSelection = 0;
}

void mCPlacementAdmin::Move( bCVector a_vecOffset )
{
    if ( m_bCameraSpace )
        a_vecOffset *= m_matCameraTransformAdjusted.GetRotation3();
    else
        a_vecOffset *= m_matWorldTransform.GetRotation3();
    m_matWorldTransform.AccessTranslation() += a_vecOffset;
    DecomposeWorldTransform();
}

void mCPlacementAdmin::OnFilterChanged( void )
{
    if ( !m_bSpawnMode )
        return;
    BuildTemplateArray( m_arrTemplates );
    if ( m_iTemplate < 0 )
        return;
    --m_iTemplate;
    SelectNext( GEFalse );
}

void mCPlacementAdmin::OnProcess( void )
{
    if ( gui2.IsLoading() )
        m_arrDeletedEntities[ 0 ].m_streamData.Clear();
    if ( !m_bEnabled || !world.IsGameRunning() )
    {
        SetHighlightedEntity( 0 );
        return;
    }
    m_matCameraTransform = Entity::GetCameraPose();
    m_matCameraTransformAdjusted = bCMatrix( bCEulerAngles( g_fPI + g_acosf( m_matCameraTransform.GetXAxis().GetNormalized().GetX() ) * ( m_matCameraTransform.GetXAxis().GetZ() < 0.0f ? 1.0f : -1.0f ), 0.0f, 0.0f ), m_matCameraTransform.GetTranslation() );
    UpdateTarget();
    UpdateWorldTransform();
    eCDynamicEntity * pSelection = GetSelection();
    eCDynamicEntity * pSecondarySelection = GetSecondarySelection();
    static eCDynamicEntity * pSelectionOld = 0;
    if ( !m_bSpawnMode && pSelectionOld != pSelection )
    {
        pSelectionOld = pSelection;
        SetCurrentEntity( pSelection );
    }
    else if ( m_bSpawnMode )
        SetCurrentEntity( 0 );
    else if ( pSelection != GetCurrentEntity() )
    {
        if ( !m_bEntityAttached )
        {
            m_arrSelectionBuffer.Clear();
            m_arrSelectionBuffer.AddNew().SetEntity( GetCurrentEntity() );
            m_iSelection = 0;
            pSelectionOld = pSelection = GetSelection();
            if ( pSelection )
                m_matWorldTransform = pSelection->GetWorldMatrix();
            DecomposeWorldTransform();

        }
        SetCurrentEntity( pSelection );
    }
    if ( m_bSpawnMode )
    {
        eCTemplateEntity const * pCreator = pSelection ? pSelection->GetCreator() : 0;
        static eCTemplateEntity const * pCreatorOld = 0;
        if ( pCreatorOld != pCreator )
        {
            pCreatorOld = pCreator;
            SetCurrentTemplate( pCreator );
        }
        else if ( pCreator != GetCurrentTemplate() )
        {
            ClearSelection();
            eCDynamicEntity * pEntity = SpawnTemplate( GetCurrentTemplate(), 0 );
            if ( pEntity )
            {
                m_arrSelectionBuffer.Add( pEntity );
                m_iSelection = 0;
                AttachSelection( GETrue );
            }
            pCreatorOld = pCreator = pEntity ? pEntity->GetCreator() : 0;
            SetCurrentTemplate( pCreator );
        }
    }
    else
        SetCurrentTemplate( 0 );
    if ( pSelection )
        pSelection->SetToWorldMatrix( m_matWorldTransform );
    SetHighlightedEntity( m_bHighlightSelection ? ( pSecondarySelection ? pSecondarySelection : pSelection ) : 0 );
}

void mCPlacementAdmin::OnRender( void )
{
    if ( !m_bEnabled || !world.IsGameRunning() )
        return;
    eCDynamicEntity * pSelection = GetSelection();
    eCDynamicEntity * pSecondarySelection = GetSecondarySelection();
    CRenderContext Context;
    if ( m_bRenderBoundingBoxes )
    {
        if ( pSelection )
            Context( 4, 2 )->DrawBox( pSelection->GetWorldNodeBoundary(), static_cast< GEU32 >( m_bSpawnMode ? EColor_Blue : EColor_Default ), bCMatrix::GetIdentity(), GEFalse, GEFalse, GEFalse );
        if ( pSecondarySelection )
            Context( 4, 2 )->DrawBox( pSecondarySelection->GetWorldNodeBoundary(), static_cast< GEU32 >( m_bSpawnMode ? EColor_Red : EColor_Green ), bCMatrix::GetIdentity(), GEFalse, GEFalse, GEFalse );
    }
    RenderCross( pSecondarySelection ? ( m_bSpawnMode ? EColor_Red : EColor_Green ) : ( m_bSpawnMode ? EColor_Blue : EColor_Default ) );
    if ( pSecondarySelection )
    {
        bCMatrix matGizmo;
        pSecondarySelection->GetGizmoTrafoSpaceWorldMatrix( &eCApplication::GetInstance().GetCurrentCamera(), matGizmo );
        Context( 0, 2 )->DrawLine( matGizmo.GetTranslation(), bCVector( 90.0f, 0, 0 ) * matGizmo, 0xFFFF3F3F, GEFalse, GEFalse );
        Context( 0, 2 )->DrawLine( matGizmo.GetTranslation(), bCVector( 0, 90.0f, 0 ) * matGizmo, 0xFF3FFF3F, GEFalse, GEFalse );
        Context( 0, 2 )->DrawLine( matGizmo.GetTranslation(), bCVector( 0, 0, 90.0f ) * matGizmo, 0xFF3F3FFF, GEFalse, GEFalse );
    }
    RenderGizmo();
}

void mCPlacementAdmin::PickLayer( void )
{
    eCDynamicEntity * pSelection = GetSelection();
    if ( !m_bSpawnMode && pSelection )
        SetCurrentLayer( GetLayer( pSelection ) );
}

void mCPlacementAdmin::ResetPendingTransform( void )
{
    m_matLocalTransform = m_matLocalTransformBase;
    UpdateWorldTransform();
}

void mCPlacementAdmin::ResetRotation( void )
{
    if ( m_bCameraSpace && !m_bEntityAttached && GetSelection() )
        m_matLocalTransform.ModifyRotation( m_matCameraTransformAdjusted.GetRotation3() );
    else
        m_matLocalTransform.SetIdentityRotation();
    m_matLocalTransformBase = m_matLocalTransform;
}

void mCPlacementAdmin::ResetTransform( void )
{
    ResetTranslation();
    ResetRotation();
    UpdateWorldTransform();
}

void mCPlacementAdmin::ResetTranslation( void )
{
    if ( !m_bSpawnMode && !m_bEntityAttached && GetSelection() )
        return;
    GEFloat const fZ = m_bFreeMode ? m_matLocalTransform.AccessTranslation().GetZ() : 0;
    m_matLocalTransform.AccessTranslation() = bCVector( 0, 0, fZ );
    m_matLocalTransformBase = m_matLocalTransform;
}

void mCPlacementAdmin::RestoreOldTransform( void )
{
    if ( m_bSpawnMode || !m_bEntityAttached )
        return;
    m_matWorldTransform = m_matWorldTransformOld;
    DecomposeWorldTransform();
    m_matLocalTransformBase = m_matLocalTransform;
    OnProcess();
}

void mCPlacementAdmin::Rotate( GEFloat a_fAngle )
{
    if ( m_iPrimaryTransformAxis < 0 )
        return;
    if ( m_bCameraSpace )
    {
        bCVector const vecTranslation = m_matWorldTransform.GetTranslation();
        if ( m_iPrimaryTransformAxis == 0 )
            m_matWorldTransform.Rotate( bCAxisAngle( m_matCameraTransformAdjusted.GetXAxis(), a_fAngle ) );
        else if ( m_iPrimaryTransformAxis == 1 )
            m_matWorldTransform.Rotate( bCAxisAngle( m_matCameraTransformAdjusted.GetYAxis(), a_fAngle ) );
        else if ( m_iPrimaryTransformAxis == 2 )
            m_matWorldTransform.Rotate( bCAxisAngle( m_matCameraTransformAdjusted.GetZAxis(), a_fAngle ) );
        m_matWorldTransform.AccessTranslation() = vecTranslation;
    }
    else
    {
        if ( m_iPrimaryTransformAxis == 0 )
            m_matWorldTransform.RotateLocalAxisX( a_fAngle );
        else if ( m_iPrimaryTransformAxis == 1 )
            m_matWorldTransform.RotateLocalAxisY( a_fAngle );
        else if ( m_iPrimaryTransformAxis == 2 )
            m_matWorldTransform.RotateLocalAxisZ( a_fAngle );
    }
    DecomposeWorldTransform();
}

void mCPlacementAdmin::SelectEntity( void )
{
    if ( m_bSpawnMode )
        return;
    AttachSelection( GEFalse );
    BuildEntityArray( m_arrSelectionBuffer, ( ( !m_bEntityAttached && GetSelection() ) ? m_vecTarget : m_matWorldTransform.GetTranslation() ) );
    m_iSelection = -1;
    SelectNext( GEFalse );
}

void mCPlacementAdmin::SelectNext( GEBool a_bReverse )
{
    eCDynamicEntity * pSelection = GetSelection();
    if ( m_bSecondarySelectionActive )
    {
        GEInt const iSecondarySelectionOld = m_iSecondarySelection;
        SelectNextEntityOnScreen( m_arrSecondarySelectionBuffer, m_iSecondarySelection, a_bReverse );
        if ( m_bEntityAttached && iSecondarySelectionOld != m_iSecondarySelection && pSelection && pSelection == GetSecondarySelection() )
        {
            SelectNext( a_bReverse );
            if ( pSelection == GetSecondarySelection() )
                m_iSecondarySelection = iSecondarySelectionOld;
        }
        return;
    }
    if ( m_bSpawnMode )
    {
        GEInt const iTemplateCount = m_arrTemplates.GetCount();
        if ( !iTemplateCount )
            return;
        m_iTemplate = m_iTemplate < 0 ? ( a_bReverse ? 0 : -1 ) : m_iTemplate;
        GEInt iTemplate = m_iTemplate = ( m_iTemplate + ( a_bReverse ? -1 : 1 ) + iTemplateCount ) % iTemplateCount;
        eCDynamicEntity * pEntity = SpawnTemplate( GetTemplate(), 0 );
        ClearSelection();
        m_iTemplate = iTemplate;
        if ( !pEntity )
            return;
        m_arrSelectionBuffer.Add( pEntity );
        m_iSelection = 0;
        AttachSelection( GETrue );
        return;
    }
    else if ( m_bEntityAttached )
        return;
    if ( !SelectNextEntityOnScreen( m_arrSelectionBuffer, m_iSelection, a_bReverse ) )
        return;
    pSelection = GetSelection();
    if ( pSelection )
        m_matWorldTransform = pSelection->GetWorldMatrix();
    DecomposeWorldTransform();
}

void mCPlacementAdmin::SetActiveTransformAxes( GEInt a_iPrimaryAxis, GEInt a_iSecondaryAxis )
{
    m_iPrimaryTransformAxis = a_iPrimaryAxis;
    m_iSecondaryTransformAxis = a_iSecondaryAxis;
}

void mCPlacementAdmin::SetSecondarySelectionActive( GEBool a_bActive )
{
    if ( m_bSecondarySelectionActive == a_bActive )
        return;
    m_bSecondarySelectionActive = a_bActive;
    if ( !a_bActive )
    {
        m_arrSecondarySelectionBuffer.Clear();
        return;
    }
    if ( m_arrSecondarySelectionBuffer.GetCount() )
        return;
    BuildEntityArray( m_arrSecondarySelectionBuffer, ( ( !m_bEntityAttached && GetSelection() ) ? m_vecTarget : m_matWorldTransform.GetTranslation() ) );
    m_iSecondarySelection = -1;
    SelectNext( GEFalse );
}

void mCPlacementAdmin::SpawnSelectedTemplate( GEBool a_bRandomYRotation )
{
    eCDynamicEntity * pSelection = GetSelection();
    eCDynamicEntity * pResult = SpawnTemplate( pSelection ? pSelection->GetCreator() : 0, GetCurrentLayer() );
    if ( !pResult || !a_bRandomYRotation )
        return;
    bCMatrix matWorld = pResult->GetWorldMatrix();
    matWorld.RotateLocalAxisY( bCRandom::GetRandom().FRand48( 0, g_fPI * 2 ) );
    pResult->SetWorldMatrix( matWorld );
}

void mCPlacementAdmin::ToggleLocalSpaceCameraSpace( void )
{
    if ( !m_bEnabled )
        return;
    m_bCameraSpace = !m_bCameraSpace;
    DecomposeWorldTransform();
    ApplyPendingTransform();
}

void mCPlacementAdmin::TogglePickSpawn( void )
{
    if ( !m_bEnabled )
        return;
    SetSecondarySelectionActive( GEFalse );
    ClearSelection();
    m_bSpawnMode = !m_bSpawnMode;
    if ( m_bSpawnMode )
        OnFilterChanged();
}

void mCPlacementAdmin::ToggleRenderMode( void )
{
    if ( !m_bEnabled )
        return;
    m_bRenderBoundingBoxes = !m_bRenderBoundingBoxes;
    if ( m_bRenderBoundingBoxes )
        m_bHighlightSelection = !m_bHighlightSelection;
}

void mCPlacementAdmin::ToggleTraceFree( void )
{
    if ( !m_bEnabled )
        return;
    m_bFreeMode = !m_bFreeMode;
    UpdateTarget();
    DecomposeWorldTransform();
    ApplyPendingTransform();
}

void mCPlacementAdmin::ToggleStaticColLevelCol( void )
{
    if ( m_bEnabled )
        m_bLevelColTraceMode = !m_bLevelColTraceMode;
}

void mCPlacementAdmin::UndeleteEntity( void )
{
    if ( !( *m_arrDeletedEntities ).m_streamData.GetSize() )
        return;
    eCEntityProxy ParentProxy;
    ParentProxy.SetEntity( ( *m_arrDeletedEntities ).m_ParentID );
    eCDynamicEntity * pParent = ParentProxy.IsEntityIDValid() ? ParentProxy.GetDynamicEntity() : 0;
    gCDynamicLayer * pLayer = GetLayer( pParent );
    if ( pParent && pLayer )
    {
        eCDynamicEntity * pRestored = pLayer->CreateDynamicEntity();
        if ( pRestored->GetParent() != pParent )
        {
            pRestored->AddReference();
            pRestored->RemoveFromParent();
            pParent->AttachChild( pRestored );
            pRestored->ReleaseReference();
        }
        ( *m_arrDeletedEntities ).m_streamData.Seek( 0, bEStreamSeekMode_Begin );
        pRestored->OnRead( ( *m_arrDeletedEntities ).m_streamData );
    }
    ( *m_arrDeletedEntities ).m_streamData.Clear();
    for ( GEInt i = 1, ie = sizeof( m_arrDeletedEntities ) / sizeof( *m_arrDeletedEntities ); i < ie; ++i )
        g_swap( m_arrDeletedEntities[ i ], m_arrDeletedEntities[ i - 1 ] );
}

#pragma warning( push )
#pragma warning( disable : 4355 )  // 'this' : used in base member initializer list 

mCPlacementAdmin::mCPlacementAdmin( void ) :
    m_Processor( this ),
    m_iTemplate( 0 ),
    m_bEnabled( GEFalse ),
    m_bSpawnMode( GEFalse ),
    m_bEntityAttached( GEFalse ),
    m_bLevelColTraceMode( GEFalse ),
    m_bFreeMode( GEFalse ),
    m_bCameraSpace( GEFalse ),
    m_bRenderBoundingBoxes( GETrue ),
    m_bHighlightSelection( GETrue ),
    m_bSecondarySelectionActive( GEFalse )
{
    m_matLocalTransform = m_matLocalTransformBase = m_matWorldTransform = bCMatrix::GetIdentity();
}

#pragma warning( pop )

mCPlacementAdmin::~mCPlacementAdmin( void )
{
    Disable();
    m_arrSelectionBuffer.Clear();
    m_arrSecondarySelectionBuffer.Clear();
    m_arrTemplates.Clear();
}

namespace
{
    bCVector * s_pPosition = 0;

    GEInt GE_CCALL CompareEntities( GELPCVoid a_pEntityProxy1, GELPCVoid a_pEntityProxy2 )
    {
        eCDynamicEntity const * pEntity1 = static_cast< eCEntityProxy const * >( a_pEntityProxy1 )->GetDynamicEntity();
        eCDynamicEntity const * pEntity2 = static_cast< eCEntityProxy const * >( a_pEntityProxy2 )->GetDynamicEntity();
        if ( !pEntity1 || !pEntity2 )
            return 0;
        GEFloat fDifference = ( pEntity1->GetWorldPosition() - *s_pPosition ).GetMagnitude() - ( pEntity2->GetWorldPosition() - *s_pPosition ).GetMagnitude();
        return fDifference == 0.0f ? 0 : ( fDifference < 0 ? -1 : 1 );
    }

    GEInt GE_CCALL CompareTemplateEntityNames( GELPCVoid a_pEntityPtr1, GELPCVoid a_pEntityPtr2 )
    {
        eCTemplateEntity * pEntity1 = *static_cast< eCTemplateEntity * const * >( a_pEntityPtr1 );
        eCTemplateEntity * pEntity2 = *static_cast< eCTemplateEntity * const * >( a_pEntityPtr2 );
        return pEntity1->GetName().CompareNoCase( pEntity2->GetName() );
    }

    void AddChildrenRecursive( eCNode * a_pNode, bTValArray< eCDynamicEntity * > & a_arrEntities )
    {
        if ( !a_pNode )
            return;
        if ( a_arrEntities.GetCapacity() == a_arrEntities.GetCount() )
            a_arrEntities.Reserve( a_arrEntities.GetCount() * 2 );
        for ( a_pNode = a_pNode->GetFirstChild(); a_pNode; a_pNode = a_pNode->GetNextNeighbour() )
        {
            eCEntity * pEntity = static_cast< eCEntity * >( static_cast< GELPVoid >( a_pNode ) );
            eCDynamicEntity * pDynamicEntity = 0;
            if ( pEntity->GetEntityFlags().m_InProcessingRange && !pEntity->GetEntityFlags().m_Killed )
                pDynamicEntity = dynamic_cast< eCDynamicEntity * >( a_pNode );
            if ( pDynamicEntity )
                a_arrEntities.Add( pDynamicEntity );
            if ( a_pNode->GetFirstChild() )
                AddChildrenRecursive( a_pNode, a_arrEntities );
        }
    }
}

void mCPlacementAdmin::BuildEntityArray( CEntityArray & a_arrEntities, bCVector a_vecPosition )
{
    a_arrEntities.Clear();
    bTValArray< eCDynamicEntity * > arrEntitiesInProcessingRange( 1000 );
    for ( GEInt i = gCWorld::GetCurrentWorld()->GetSectorCount(); i--; )
    {
        gCSector * pSector = gCWorld::GetCurrentWorld()->GetSectorAt( i );
        for ( GEInt j = pSector->GetDynamicLayerCount(); pSector->IsEnabled() && j--; )
            AddChildrenRecursive( pSector->GetDynamicLayerAt( j )->GetContext().GetGraph(), arrEntitiesInProcessingRange );
    }
    a_arrEntities.Reserve( arrEntitiesInProcessingRange.GetCount() );
    for ( GEInt i = arrEntitiesInProcessingRange.GetCount(); i--; a_arrEntities.Add( arrEntitiesInProcessingRange[ i ] ) );
    s_pPosition = &a_vecPosition;
    qsort( a_arrEntities.AccessArray(), static_cast< size_t >( a_arrEntities.GetCount() ), sizeof( *a_arrEntities.GetArray() ), &CompareEntities );
}

void mCPlacementAdmin::BuildTemplateArray( CEntityArray & a_arrEntities )
{
    a_arrEntities.Clear();
    eCSceneAdmin * pSceneAdmin = dynamic_cast< eCSceneAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCSceneAdmin" ) );
    if ( !pSceneAdmin )
        return;
    bTPtrArray< eCTemplateEntity * > arrTemplates;
    pSceneAdmin->GetTemplateEntities( arrTemplates, GEFalse, GEFalse, GEFalse, GEFalse, GETrue );
    qsort( arrTemplates.AccessArray(), static_cast< size_t >( arrTemplates.GetCount() ), sizeof( *arrTemplates.GetArray() ), &CompareTemplateEntityNames );
    a_arrEntities.Reserve( arrTemplates.GetCount() );
    for ( GEInt i = arrTemplates.GetCount(); i--; a_arrEntities.Add( arrTemplates[ i ] ) );
}

eCDynamicEntity * mCPlacementAdmin::GetCurrentEntity( void )
{
    bCUnicodeString strEntityGuid = mCConsoleVarAdmin::GetInstance().GetVariable( "e" ).GetUnicodeText();
    return GetDynamicEntity( strEntityGuid, strEntityGuid );
}

gCDynamicLayer * mCPlacementAdmin::GetCurrentLayer( void )
{
    return GetLayer( mCConsoleVarAdmin::GetInstance().GetVariable( "l" ) );
}

eCTemplateEntity * mCPlacementAdmin::GetCurrentTemplate( void )
{
    eCTemplateEntityProxy CurrentTemplateProxy = Template( mCConsoleVarAdmin::GetInstance().GetVariable( "t" ).GetText() );
    return CurrentTemplateProxy.GetEntity();
}

GEBool mCPlacementAdmin::SelectNextEntityOnScreen( CEntityArray const & a_arrEntities, GEInt & a_iIndex, GEBool a_bBackwards )
{
    GEInt iIndex = ( a_iIndex < 0 ? -1 : ( a_iIndex >= a_arrEntities.GetCount() ? a_arrEntities.GetCount() : a_iIndex ) ) + ( a_bBackwards ? -1 : 1 );
    if ( iIndex < 0 || iIndex >= a_arrEntities.GetCount() )
        return GEFalse;
    eCCameraBase const & Camera = eCApplication::GetInstance().GetCurrentCamera();
    bCRect rectScreen = Camera.GetScreen();
    for ( GEInt ie = a_bBackwards ? -1 : a_arrEntities.GetCount(); iIndex != ie; iIndex = a_bBackwards ? iIndex - 1 : iIndex + 1 )
    {
        eCDynamicEntity const * pEntity = a_arrEntities[ iIndex ].GetDynamicEntity();
        bCVector vecPos = pEntity ? pEntity->GetWorldPosition() : bCVector( g_fPosInfinity, g_fPosInfinity, g_fPosInfinity );
        Camera.WorldToScreen( vecPos );
        if ( rectScreen.Contains( bCPoint( static_cast< GEInt >( vecPos.GetX() + 0.5f ), static_cast< GEInt >( vecPos.GetY() + 0.5f ) ) ) )
            return a_iIndex = iIndex, GETrue;
    }
    return GEFalse;
}

void mCPlacementAdmin::SetCurrentEntity( eCDynamicEntity const * a_pEntity )
{
    bCString strCurrentEntityGuid = "<invalid>";
    if ( a_pEntity )
    {
        bCGuid Guid;
        a_pEntity->GetEntityID()->m_pID->ExtractGuid( Guid );
        strCurrentEntityGuid = Guid.GetText();
    }
    mCConsoleVarAdmin::GetInstance().SetVariable( "e", strCurrentEntityGuid );
}

void mCPlacementAdmin::SetCurrentLayer( gCDynamicLayer const * a_pLayer )
{
    bCString strCurrentLayer = "<invalid>";
    if ( a_pLayer )
        strCurrentLayer = a_pLayer->GetFileBaseName();
    mCConsoleVarAdmin::GetInstance().SetVariable( "l", strCurrentLayer );
}

void mCPlacementAdmin::SetCurrentTemplate( eCTemplateEntity const * a_pTemplate )
{
    bCString strCurrentTemplate = "<invalid>";
    if ( a_pTemplate )
        strCurrentTemplate = a_pTemplate->GetName();
    mCConsoleVarAdmin::GetInstance().SetVariable( "t", strCurrentTemplate );
}

void mCPlacementAdmin::AttachSelection( GEBool a_bAttached )
{
#pragma warning( push )
#pragma warning( disable : 4640 )
    static eCEntityProxy s_AttachedEntity;
#pragma warning( pop )
    static GEBool s_bIgnoredByTraceRay;
    eCDynamicEntity * pAttachedEntity = s_AttachedEntity.GetDynamicEntity();
    if ( pAttachedEntity )
    {
        eCCollisionShape_PS * pColShape = dynamic_cast< eCCollisionShape_PS * >( pAttachedEntity->GetPropertySet( eEPropertySetType_CollisionShape ) );
        if ( pColShape )
            pColShape->AccessIgnoredByTraceRay() = s_bIgnoredByTraceRay;
        s_AttachedEntity.SetEntity( 0 );
    }
    m_bEntityAttached = GEFalse;
    if ( a_bAttached )
    {
        s_AttachedEntity.SetEntity( GetSelection() );
        pAttachedEntity = s_AttachedEntity.GetDynamicEntity();
        if ( !pAttachedEntity )
            return;
        eCCollisionShape_PS * pColShape = dynamic_cast< eCCollisionShape_PS * >( pAttachedEntity->GetPropertySet( eEPropertySetType_CollisionShape ) );
        if ( pColShape )
        {
            s_bIgnoredByTraceRay = pColShape->GetIgnoredByTraceRay();
            pColShape->AccessIgnoredByTraceRay() = GETrue;
        }
        if ( !m_bSpawnMode )
            m_matWorldTransformOld = pAttachedEntity->GetWorldMatrix();
        m_bEntityAttached = m_bOriginalEntityAttached = GETrue;
    }
}

void mCPlacementAdmin::DecomposeWorldTransform( void )
{
    m_matLocalTransform = m_matWorldTransform;
    if ( !m_bSpawnMode && !m_bEntityAttached && GetSelection() )
        return;
    if ( !m_bFreeMode )
    {
        m_matLocalTransform.AccessTranslation() -= m_vecTarget - m_matCameraTransformAdjusted.GetTranslation();
        m_matLocalTransform.AccessTranslation() /= m_matCameraTransformAdjusted;
    }
    else
        m_matLocalTransform.AccessTranslation() *= m_matCameraTransform.GetInverted();
    if ( m_bCameraSpace )
        m_matLocalTransform.ModifyRotation( m_matCameraTransformAdjusted.GetRotation3().GetInverted() * m_matLocalTransform.GetRotation3() );
}

void mCPlacementAdmin::DeleteEntity( eCDynamicEntity * a_pEntity, GEBool a_bUndeleteEnabled )
{
    if ( !a_pEntity )
        return;
    if ( !a_bUndeleteEnabled )
    {
        a_pEntity->Kill();
        return;
    }
    eCDynamicEntity * pParent = dynamic_cast< eCDynamicEntity * >( a_pEntity->GetParent() );
    if ( !pParent )
        return;
    for ( GEInt i = sizeof( m_arrDeletedEntities ) / sizeof( *m_arrDeletedEntities ) - 1; i > 0; --i )
        g_swap( m_arrDeletedEntities[ i ], m_arrDeletedEntities[ i - 1 ] );
    ( *m_arrDeletedEntities ).m_ParentID = *pParent->GetEntityID()->m_pID;
    ( *m_arrDeletedEntities ).m_streamData.Clear();
    a_pEntity->OnWrite( ( *m_arrDeletedEntities ).m_streamData );
    a_pEntity->Kill();
}

eCDynamicEntity * mCPlacementAdmin::GetSelection( void )
{
    if ( m_iSelection < 0 || m_iSelection >= m_arrSelectionBuffer.GetCount() )
        return 0;
    eCDynamicEntity * pResult = m_arrSelectionBuffer[ m_iSelection ].GetDynamicEntity();
    if ( pResult && !pResult->GetEntityFlags().m_Killed )
        return pResult;
    DetachEntity();
    m_arrSelectionBuffer.Clear();
    return 0;
}

eCDynamicEntity * mCPlacementAdmin::GetSecondarySelection( void )
{
    if ( m_iSecondarySelection < 0 || m_iSecondarySelection >= m_arrSecondarySelectionBuffer.GetCount() )
        return 0;
    eCDynamicEntity * pResult = m_arrSecondarySelectionBuffer[ m_iSecondarySelection ].GetDynamicEntity();
    if ( pResult && !pResult->GetEntityFlags().m_Killed )
        return pResult;
    SetSecondarySelectionActive( GEFalse );
    return 0;
}

eCTemplateEntity * mCPlacementAdmin::GetTemplate( void )
{
    if ( m_iTemplate >= 0 && m_iTemplate < m_arrTemplates.GetCount() )
        return m_arrTemplates[ m_iTemplate ].GetTemplateEntity();
    return 0;
}

void mCPlacementAdmin::RenderCross( EColor a_enuColor )
{
    CRenderContext Context;
    GEBool const bRenderInner = !m_bFreeMode;
    GEBool const bRenderOuter = !GetSelection();
    bCVector const vecInnerCenter = m_vecTarget;
    bCVector const vecOuterCenter = m_matWorldTransform.GetTranslation();
    bTValArray< bCVector > arrLineVerts( 18 );
    for ( GEInt i = 0; bRenderInner && i != 6; ++i )
    {
        bCVector & vecBack = arrLineVerts.AddNew();
        vecBack[ i / 2 ] += ( i & 1 ) ? 10.0f : -10.0f;
        if ( m_bCameraSpace )
            vecBack = vecBack * m_matCameraTransformAdjusted - m_matCameraTransformAdjusted.GetTranslation();
        vecBack += vecInnerCenter;
    }
    for ( GEInt i = 0; bRenderOuter && i != 12; ++i )
    {
        bCVector & vecBack = arrLineVerts.AddNew();
        vecBack[ i / 4 ] += ( i & 1 ) ? ( ( i & 2 ) ? 10.0f : -10.0f ) : ( ( i & 2 ) ? 30.0f : -30.0f );
        vecBack = vecBack * m_matWorldTransform - m_matWorldTransform.GetTranslation();
        vecBack += vecOuterCenter;
    }
    Context( 4, 2 )->DrawLineList( arrLineVerts, a_enuColor, GEFalse, GEFalse );
    Context( 0, 2 )->DrawLineList( arrLineVerts, *reinterpret_cast< GEU32 * >( &a_enuColor ) & 0x4FFFFFFF, GEFalse, GEFalse );
}

void mCPlacementAdmin::RenderGizmo( void )
{

    GEBool bAxisHighlighted[ 3 ] = { ( m_iPrimaryTransformAxis == 0 || m_iSecondaryTransformAxis == 0 ),
                                     ( m_iPrimaryTransformAxis == 1 || m_iSecondaryTransformAxis == 1 ),
                                     ( m_iPrimaryTransformAxis == 2 || m_iSecondaryTransformAxis == 2 ) };
    CRenderContext Context( 0, 2 );
    bCQuaternion quatCameraRotation( m_matCameraTransformAdjusted.GetRotation3() );
    mCGizmoTranslate::RenderOnEntity( GetSelection(), 0.8f, m_bCameraSpace ? &quatCameraRotation : 0, bAxisHighlighted );
}

void mCPlacementAdmin::SetHighlightedEntity( eCDynamicEntity * a_pEntity )
{
#pragma warning( push )
#pragma warning( disable : 4640 )
    static eCEntityProxy s_HighlightedEntity;
#pragma warning( pop )
    eCDynamicEntity * pEntityOld = s_HighlightedEntity.GetDynamicEntity();
    if ( pEntityOld == a_pEntity && ( !pEntityOld || pEntityOld->GetEntityFlags().m_IsHighlighted ) )
        return;
    if ( pEntityOld )
        pEntityOld->GetEntityFlags().m_IsHighlighted = GEFalse;
    s_HighlightedEntity.SetEntity( a_pEntity );
    if ( a_pEntity )
        a_pEntity->GetEntityFlags().m_IsHighlighted = GETrue;
}

eCDynamicEntity * mCPlacementAdmin::SpawnTemplate( eCTemplateEntity const * a_pTemplate, gCDynamicLayer * a_pLayer )
{
    if ( !a_pTemplate )
        return 0;
    eCDynamicEntity * pEntity = dynamic_cast< eCDynamicEntity * >( gCSession::GetInstance().SpawnEntity( a_pTemplate->GetName(), &m_matWorldTransform, GEFalse ) );
    if ( pEntity && a_pLayer )
        SetEntityLayer( pEntity, a_pLayer );
    return pEntity;
}

void mCPlacementAdmin::UpdateTarget( void )
{
    if ( m_bFreeMode )
    {
        m_vecTarget = m_matCameraTransform.GetTranslation();
        return;
    }
    bCVector const vecRayOrigin = Entity::GetCameraPose().GetTranslation();
    bCVector const vecRayDirection = bCVector( Entity::GetCameraPose().GetZAxis() ).Normalize() * 100000.0f;
    GEBool bResult = eCPhysicsScene::GetInstance().TraceRayNearestHit( vecRayOrigin, vecRayDirection, static_cast< eCGeometryEntity * >( Entity::GetPlayer().GetInstance() ), m_bLevelColTraceMode ? 0x100A1U : 0xA1U, 0, eEPropertySetType_Unknown, static_cast< eEShapeGroup >( 0 ) );
    eCPhysicQueryReport & PhysicQueryReport = eCPhysicsScene::GetInstance().GetQueryReport();
    if ( bResult && PhysicQueryReport.m_bValid )
        m_vecTarget = PhysicQueryReport.m_vecVector;
}

void mCPlacementAdmin::UpdateWorldTransform( void )
{
    m_matWorldTransform = m_matLocalTransform; 
    if ( !m_bSpawnMode && !m_bEntityAttached && GetSelection() )
        return;
    if ( !m_bFreeMode )
    {
        m_matWorldTransform.AccessTranslation() *= m_matCameraTransformAdjusted;
        m_matWorldTransform.AccessTranslation() += m_vecTarget - m_matCameraTransformAdjusted.GetTranslation();
    }
    else
        m_matWorldTransform.AccessTranslation() *= m_matCameraTransform;
    if ( m_bCameraSpace )
        m_matWorldTransform.ModifyRotation( m_matCameraTransformAdjusted.GetRotation3() * m_matWorldTransform.GetRotation3() );
}

GEU8 mCPlacementAdmin::CProcessor::GetProcessingIndex( void ) const
{
    return 0xFE;
}

GEU32 mCPlacementAdmin::CProcessor::GetAppStateFlags( void ) const
{
    return 0x10;
}

void mCPlacementAdmin::CProcessor::OnProcess( void )
{
    m_pPlacementAdmin->OnProcess();
}

mCPlacementAdmin::CProcessor::~CProcessor( void )
{
    if ( m_pPlacementAdmin )
        eCProcessor::GetInstance().Unregister( this );
    m_pPlacementAdmin = 0;
}

mCPlacementAdmin::CProcessor::CProcessor( mCPlacementAdmin * a_pPlacementAdmin ) :
    m_pPlacementAdmin( a_pPlacementAdmin )
{
    if ( m_pPlacementAdmin )
        eCProcessor::GetInstance().Register( this );
}

#pragma warning( pop )