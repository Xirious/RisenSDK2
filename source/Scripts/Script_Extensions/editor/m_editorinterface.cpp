#include "m_editorinterface.h"
#include "../m_utils.h"

mCEditorInterface mCEditorInterface::s_Instance;

void mCEditorInterface::Enable( void )
{
    m_bEnabled = GETrue;
    for ( GEU32 u = sizeof( m_arrKeyHandles ) / sizeof( *m_arrKeyHandles ); u--; m_arrKeyHandles[ u ]->HideInputFromGame() );
    m_PlacementAdmin.Enable();
}

void mCEditorInterface::Disable( void )
{
    m_bEnabled = GEFalse;
    for ( GEU32 u = sizeof( m_arrKeyHandles ) / sizeof( *m_arrKeyHandles ); u--; m_arrKeyHandles[ u ]->StopHideInputFromGame() );
    m_arrKeyHandles[ 13 ]->HideInputFromGame();
    m_AnalogHandle.StopHideInputFromGame();
    m_PlacementAdmin.Disable();
}

GEBool mCEditorInterface::IsEnabled( void ) const
{
    return m_bEnabled;
}

void mCEditorInterface::OnProcess( void )
{
    if ( gui2.IsBrowsing() )
        Disable();
    if ( !m_bEnabled )
    {
        m_arrKeyHandles[ 13 ]->StopHideInputFromGame();
        return;
    }
    if ( !gui2.IsConsoleVisible() )
        HandleAnalogInput();
}

#pragma warning( push )
#pragma warning( disable : 4355 )  // 'this' : used in base member initializer list 

mCEditorInterface::mCEditorInterface( void ) :
    m_Processor( this ),
    m_PlacementAdmin( mCPlacementAdmin::GetInstance() )
{
    m_arrKeyHandles[  0 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Mouse_ButtonLeft );
    m_arrKeyHandles[  1 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Mouse_ButtonMiddle );
    m_arrKeyHandles[  2 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Mouse_ButtonRight );
    m_arrKeyHandles[  3 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Mouse_WheelUp );
    m_arrKeyHandles[  4 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Mouse_WheelDown );
    m_arrKeyHandles[  5 ] = new mCInputAdmin::CKeyHandle( eEScanCode_HOME );
    m_arrKeyHandles[  6 ] = new mCInputAdmin::CKeyHandle( eEScanCode_PAGE_UP );
    m_arrKeyHandles[  7 ] = new mCInputAdmin::CKeyHandle( eEScanCode_PAGE_DOWN );
    m_arrKeyHandles[  8 ] = new mCInputAdmin::CKeyHandle( eEScanCode_SMALLER );
    m_arrKeyHandles[  9 ] = new mCInputAdmin::CKeyHandle( eEScanCode_Y );
    m_arrKeyHandles[ 10 ] = new mCInputAdmin::CKeyHandle( eEScanCode_X );
    m_arrKeyHandles[ 11 ] = new mCInputAdmin::CKeyHandle( eEScanCode_CTRL_L );
    m_arrKeyHandles[ 12 ] = new mCInputAdmin::CKeyHandle( eEScanCode_ALT_L );
    m_arrKeyHandles[ 13 ] = new mCInputAdmin::CKeyHandle( eEScanCode_SPACE );

    for ( GEInt i = 0; i != sizeof( m_arrKeyHandles ) / sizeof( *m_arrKeyHandles ); ++i )
        m_arrKeyHandles[ i ]->SetKeyEventCallback( &OnKeyEvent );
}

#pragma warning( pop )

mCEditorInterface::~mCEditorInterface( void )
{
    for ( GEU32 u = sizeof( m_arrKeyHandles ) / sizeof( *m_arrKeyHandles ); u--; delete m_arrKeyHandles[ u ] );
}

void mCEditorInterface::OnKeyEvent( eEScanCode a_enuScanCode, GEBool a_bState )
{
    mCEditorInterface & Instance = s_Instance;
    mCPlacementAdmin & PlacementAdmin = Instance.m_PlacementAdmin;
    if ( a_enuScanCode == eEScanCode_SPACE && mCInputAdmin::GetRawKeyState( eEScanCode_CTRL_L ) && mCInputAdmin::GetRawKeyState( eEScanCode_ALT_L ) )
    {
        if ( a_bState && Instance.IsEnabled() )
            Instance.Disable();
        else if ( a_bState && !Instance.IsEnabled() )
            Instance.Enable();
        return;
    }
    if ( !Instance.IsEnabled() || !PlacementAdmin.IsEnabled() || gui2.IsConsoleVisible() )
        return;
    GEBool const bS      = mCInputAdmin::GetRawKeyState( eEScanCode_SMALLER ),
                 bY      = mCInputAdmin::GetRawKeyState( eEScanCode_Y ),
                 bX      = mCInputAdmin::GetRawKeyState( eEScanCode_X ),
                 bMouseL = mCInputAdmin::GetRawKeyState( eEScanCode_Mouse_ButtonLeft ),
                 bMouseM = mCInputAdmin::GetRawKeyState( eEScanCode_Mouse_ButtonMiddle ),
                 bMouseR = mCInputAdmin::GetRawKeyState( eEScanCode_Mouse_ButtonRight );
    if ( a_enuScanCode == eEScanCode_ALT_L || a_enuScanCode == eEScanCode_SMALLER || a_enuScanCode == eEScanCode_Y || a_enuScanCode == eEScanCode_X )
    {
        Instance.HandleAnalogInput();
        PlacementAdmin.ApplyPendingTransform();
        Instance.m_bAlt = mCInputAdmin::GetRawKeyState( eEScanCode_ALT_L );
        Instance.PickTransformAxes();
    }
    GEBool const bCtrl = Instance.m_bCtrl = mCInputAdmin::GetRawKeyState( eEScanCode_CTRL_L );
    GEBool const bAlt = Instance.m_bAlt = mCInputAdmin::GetRawKeyState( eEScanCode_ALT_L );
    PlacementAdmin.SetSecondarySelectionActive( bCtrl && ( PlacementAdmin.IsInPickMode() ? !PlacementAdmin.IsEntityAttached() : !bAlt ) && !bS && !bY && !bX );
    if ( !a_bState )
    {
        if ( !bS && !bY && !bX && !bMouseL && !bMouseM && !bMouseR )
            Instance.m_AnalogHandle.StopHideInputFromGame();
        return;
    }
    if ( bS || bY || bX || bMouseL || bMouseM || bMouseR )
        Instance.m_AnalogHandle.HideInputFromGame();

#pragma warning( push )
#pragma warning( disable : 4061 )  // enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label

    if ( bS || bY || bX )
    {
        switch ( a_enuScanCode )
        {
        case eEScanCode_Mouse_ButtonLeft:
            if ( bAlt )
                PlacementAdmin.Rotate( bCtrl ? g_fPI / 12 : g_fPI / 2 );
            else
                PlacementAdmin.AlignLocalTranslation( bCtrl ? 10.0f : 100.0f );
            return;
        case eEScanCode_Mouse_ButtonMiddle:
            if ( bAlt )
                PlacementAdmin.Rotate( bCRandom::GetRandom().FRand48( 0, g_fPI * 2 ) );
            else
                Instance.m_AnalogHandle.Emulate2DInput( bCRandom::GetRandom().FRand48( ( bCtrl ? -50.0f : -200.0f ), ( bCtrl ? 50.0f : 200.0f ) ), bCRandom::GetRandom().FRand48( ( bCtrl ? -50.0f : -200.0f ), ( bCtrl ? 50.0f : 200.0f ) ) );
            return;
        case eEScanCode_Mouse_ButtonRight:
            PlacementAdmin.ResetPendingTransform();
            return;
        default:
            return;
        }
    }

    switch ( a_enuScanCode )
    {
    case eEScanCode_Mouse_ButtonLeft:
        if ( PlacementAdmin.IsInPickMode() )
        {
            if ( PlacementAdmin.IsEntityAttached() )
            {
                if ( bCtrl && bAlt )
                    PlacementAdmin.RestoreOldTransform(), PlacementAdmin.DetachEntity();
                else if ( bCtrl )
                    PlacementAdmin.DetachClone();
                else if ( bAlt )
                    return;
                else
                    PlacementAdmin.DetachEntity();
            }
            else
            {
                if ( bCtrl && bAlt )
                    PlacementAdmin.AttachSecondarySelection( GEFalse );
                else if ( bCtrl )
                    PlacementAdmin.AttachSecondarySelection( GETrue );
                else if ( bAlt )
                    PlacementAdmin.SelectEntity();
                else
                    PlacementAdmin.SelectEntity();
            }
        }
        else
        {
            if ( bCtrl && bAlt )
                PlacementAdmin.UndeleteEntity();
            else if ( bCtrl )
                PlacementAdmin.DeleteSecondarySelection();
            else if ( bAlt )
                PlacementAdmin.SpawnSelectedTemplate( GETrue );
            else
                PlacementAdmin.SpawnSelectedTemplate( GEFalse );
        }
        return;
    case eEScanCode_Mouse_ButtonMiddle:
        if ( bCtrl && bAlt )
            PlacementAdmin.ToggleStaticColLevelCol();
        else if ( bCtrl )
            PlacementAdmin.ToggleTraceFree();
        else if ( bAlt )
            PlacementAdmin.ToggleRenderMode();
        else
            PlacementAdmin.ToggleLocalSpaceCameraSpace();
        return;
    case eEScanCode_Mouse_ButtonRight:
        if ( bCtrl && bAlt )
            PlacementAdmin.ClearSelection();
        else if ( bCtrl )
            PlacementAdmin.ResetTranslation();
        else if ( bAlt )
            PlacementAdmin.ResetRotation();
        else
            PlacementAdmin.ResetTransform();
        return;
    case eEScanCode_Mouse_WheelUp:
    case eEScanCode_PAGE_UP:
        PlacementAdmin.SelectNext( GEFalse );
        return;
    case eEScanCode_Mouse_WheelDown:
    case eEScanCode_PAGE_DOWN:
        PlacementAdmin.SelectNext( GETrue );
        return;
    case eEScanCode_SPACE:
        if ( bCtrl && !bAlt )
            PlacementAdmin.TogglePickSpawn();
        else if ( !bCtrl && bAlt )
            PlacementAdmin.PickLayer();
        else if ( !bCtrl && !bAlt )
            PlacementAdmin.EditSelection();
        return;
    default:
        return;
    }

#pragma warning( pop )
}

GEBool mCEditorInterface::AlignAnalogInput( bCVector & a_vecInput ) const
{
    GEInt iAxes[ 2 ];
    m_PlacementAdmin.GetActiveTransformAxes( iAxes[ 0 ], iAxes[ 1 ] );
    if ( iAxes[ 0 ] == -1 )
        return GEFalse;
    bCMatrix const & matTransformSpace = m_PlacementAdmin.GetTransformationSpace();
    bCMatrix matCameraRotationInverse = m_PlacementAdmin.GetCameraTransform().GetInverted().GetRotation();
    bCVector vecAxis1 = ( iAxes[ 0 ] == 0 ? matTransformSpace.GetXAxis() : ( iAxes[ 0 ] == 1 ? matTransformSpace.GetYAxis() : matTransformSpace.GetZAxis() ) ) * matCameraRotationInverse;
    bCVector vecAxis2 = ( iAxes[ 1 ] == 0 ? matTransformSpace.GetXAxis() : ( iAxes[ 1 ] == 1 ? matTransformSpace.GetYAxis() : matTransformSpace.GetZAxis() ) ) * matCameraRotationInverse;
    vecAxis1[ 2 ] = vecAxis2[ 2 ] = 0;
    vecAxis1[ 1 ] += 1e-8f; vecAxis2[ 1 ] += 1e-8f;
    GEFloat fAngle;
    if ( iAxes[ 1 ] != -1 )
    {
        bCVector const vecSum = vecAxis1.GetNormalized() + vecAxis2.GetNormalized();
        fAngle = vecSum.GetAngleRad( bCVector( 1.0f, 1.0f, 0.0f ) ) * ( vecSum.GetY() > vecSum.GetX() ? -1 : 1 );
    }
    else
        fAngle = vecAxis1.GetAngleRad( bCVector( 1.0f, 0.0f, 0.0f ) ) * ( vecAxis1.GetY() > 0 ? -1 : 1 );
    a_vecInput.AccessY() *= -1;
    bCQuaternion quatInputRotation = bCQuaternion( 0, 0, 0, 1 ).GetRotatedAxisZ( fAngle );
    a_vecInput *= bCMatrix3( quatInputRotation );
    bCVector vecResult( 0, 0, 0 );
    if ( iAxes[ 1 ] != -1 )
    {
        if ( bCVector::CrossProduct( vecAxis1, vecAxis2 ).GetZ() < 0 )
            g_swap( a_vecInput[ 0 ], a_vecInput[ 1 ] );
        vecResult[ iAxes[ 1 ] ] = a_vecInput[ 1 ];
    }
    vecResult[ iAxes[ 0 ] ] = a_vecInput[ 0 ];
    a_vecInput = vecResult;
    return GETrue;
}

void mCEditorInterface::HandleAnalogInput( void )
{
    bCVector vecInput = m_AnalogHandle.Get3D();
    m_AnalogHandle.ResetXY();
    if ( m_bAlt )
        m_PlacementAdmin.Rotate( vecInput[ 1 ] / ( m_bCtrl ? 500.0f : 100.0f ) );
    else if ( AlignAnalogInput( vecInput ) )
        m_PlacementAdmin.Move( vecInput * ( m_bCtrl ? 0.3f : 1.5f ) );
}

void mCEditorInterface::PickTransformAxes( void )
{
    GEBool bAxes[ 3 ] = { mCInputAdmin::GetRawKeyState( eEScanCode_X ),
                          mCInputAdmin::GetRawKeyState( eEScanCode_Y ),
                          mCInputAdmin::GetRawKeyState( eEScanCode_SMALLER ) };
    GEInt iAxes[ 2 ] = { -1, -1 };
    for ( GEInt i = 0, j = 0, je = ( m_bAlt ? 1 : 2 ); j != je && i != 3; ++i )
        if ( bAxes[ i ] )
            iAxes[ j++ ] = i;
    m_PlacementAdmin.SetActiveTransformAxes( iAxes[ 0 ], iAxes[ 1 ] );
}

GEU8 mCEditorInterface::CProcessor::GetProcessingIndex( void ) const
{
    return 4;
}

GEU32 mCEditorInterface::CProcessor::GetAppStateFlags( void ) const
{
    return 0x10;
}

void mCEditorInterface::CProcessor::OnProcess( void )
{
    m_pEditorInterface->OnProcess();
}

mCEditorInterface::CProcessor::~CProcessor( void )
{
    if ( m_pEditorInterface )
        eCProcessor::GetInstance().Unregister( this );
    m_pEditorInterface = 0;
}

mCEditorInterface::CProcessor::CProcessor( mCEditorInterface * a_pEditorInterface ) :
    m_pEditorInterface( a_pEditorInterface )
{
    if ( m_pEditorInterface )
        eCProcessor::GetInstance().Register( this );
}