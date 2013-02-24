#include "Tools_CamSensitivity.h"
#include "../../m_hook.h"
#include "../../m_hacks.h"

namespace
{
    bCString s_strFreeCamFactor;
    bCString s_strPlayerCamFactor;
    GEDouble s_dFreeCamFactor = ( CConfigAdminAccessor::GetLayerValueString( eECfgLayer_Options, "/Input/Mouse/FreeCamFactor", s_strFreeCamFactor, "1.0" ), s_strFreeCamFactor.GetDouble( 0 ) );
    GEDouble s_dPlayerCamFactor = ( CConfigAdminAccessor::GetLayerValueString( eECfgLayer_Options, "/Input/Mouse/PlayerCamFactor", s_strPlayerCamFactor, "1.0" ), s_strPlayerCamFactor.GetDouble( 0 ) );

    GEInt OnAction( gSAction & a_argAction )
    {
        gCCameraAdmin * pCameraAdmin = static_cast< gCCameraAdmin * >( mCCallHook::GetSelf() );
        a_argAction.m_fAmplitude *= static_cast< GEFloat >( pCameraAdmin->IsExternalCamera() ? s_dFreeCamFactor : s_dPlayerCamFactor );
        return ( *mCCallHook::GetOriginalFunctionProxy( &OnAction ) )( a_argAction );
    }

    mCCallHook s_CameraActionHook( g_CallHookParams( &gCCameraAdmin::OnAction, &OnAction, GEFalse, 0 ) );
}

bCUnicodeString CON_Tools_Sub::FreeCamSensitivity( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    GEDouble dFactor = a_arrParams[ 1 ].GetDouble();
    if ( dFactor < 0.01 || dFactor > 10.0 )
        return L"$Invalid factor.";
    s_dFreeCamFactor = dFactor;
    CConfigAdminAccessor::SetLayerValueString( eECfgLayer_Options, "/Input/Mouse/FreeCamFactor", bCString::GetFormattedString( "%f", dFactor ) );
    return L"Ok.";
}

bCUnicodeString CON_Tools_Sub::PlayerCamSensitivity( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    GEDouble dFactor = a_arrParams[ 1 ].GetDouble();
    if ( dFactor < 0.01 || dFactor > 10.0 )
        return L"$Invalid factor.";
    s_dPlayerCamFactor = dFactor;
    CConfigAdminAccessor::SetLayerValueString( eECfgLayer_Options, "/Input/Mouse/PlayerCamFactor", bCString::GetFormattedString( "%f", dFactor ) );
    return L"Ok.";
}