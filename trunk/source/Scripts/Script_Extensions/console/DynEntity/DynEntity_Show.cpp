#include "DynEntity_Show.h"
#include <stdio.h>

#pragma warning( push )
#pragma warning( disable : 4738 )  // storing 32-bit float result in memory, possible loss of performance

bCUnicodeString CON_DynEntity_Sub::Show( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    Entity Target( pEntity );
    EffectSystem::StartEffect( "eff_titan_showckwave_01", Target );
    EffectSystem::StartEffect( "eff_projectile_Frostball_Impact_01", Target );
    GEFloat const fDistance = Target.GetDistanceTo( Entity::GetPlayer() ) / 100;

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return bCString::GetFormattedString( "Showed %s. Distance to player: %.2fm.", pEntity->GetName().GetText(), fDistance ).GetUnicodeText();
}

#pragma warning( pop )