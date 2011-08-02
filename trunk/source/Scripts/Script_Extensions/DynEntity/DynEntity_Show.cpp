#include "DynEntity_Show.h"

#pragma warning( push )
#pragma warning( disable : 4738 )

bCUnicodeString CON_DynEntity::Show( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    Entity TargetEntity( pEntity );
    
    EffectSystem::StartEffect( "eff_titan_showckwave_01", TargetEntity );
    EffectSystem::StartEffect( "eff_projectile_Frostball_Impact_01", TargetEntity );

    GEFloat fDistance = TargetEntity.GetDistanceTo( Entity::GetPlayer() ) / 100;
    GEChar strDistance[20];
    sprintf_s( strDistance, 20, "%.2f", fDistance );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( "Showed " + pEntity->GetName() + ". Distance to player: " + strDistance + "m" ).GetUnicodeText();
}

#pragma warning( pop )