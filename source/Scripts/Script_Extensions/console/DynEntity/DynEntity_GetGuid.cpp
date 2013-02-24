#include "DynEntity_GetGuid.h"

bCUnicodeString CON_DynEntity_Sub::GetGuid( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    bTValArray< eCEntity * > arrEntityPointers = Entity::GetEntitiesByName( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !arrEntityPointers.GetCount() )
        return L"$No entity found.";

    if ( arrEntityPointers.GetCount() > 1 )
        strResult = bCUnicodeString::GetFormattedString( L"Found %i entities. The nearest one's GUID: ", arrEntityPointers.GetCount() );
    bTObjArray< Entity > arrEntities;
    arrEntities.Reserve( arrEntityPointers.GetCount() );
    for ( GEInt i = 0, ie = arrEntityPointers.GetCount(); i != ie; ++i )
        arrEntities.Add( Entity( arrEntityPointers[ i ] ) );

    Entity::SortEntityListByDistanceTo( arrEntities, Entity::GetPlayer() );
    bCGuid Guid;
    bCPropertyID Id = arrEntities.GetAt( 0 ).GetInstance()->GetID();
    Id.ExtractGuid( Guid );

    bCUnicodeString strGuid = Guid.GetText().GetUnicodeText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &strGuid );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return strResult + mCCommandHandler::PushResult( strGuid );
}

#pragma warning( push )
#pragma warning( disable : 4710 )

bCUnicodeString CON_DynEntity_Sub::GetGuidAC( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    eCScriptFunctionMap & ScriptFunctionMap = eCScriptFunctionMap::GetInstance();
    eSScriptBase * pScript = const_cast< eSScriptBase * >( ScriptFunctionMap.GetScript( "CON_spawn" ) );
    if ( !pScript )
        return L"";
    gFScript funcScriptFunction = reinterpret_cast< gFScript >( pScript->m_funcFunction );

    SArgs Args;
    Args.m_enuReason = SArgs::EReason_AutoComplete;
    Args.m_arrParams.Add( a_arrParams.GetAt( 1 ) );

    if ( !( *funcScriptFunction )( a_pSPU, 0, 0, reinterpret_cast< GEInt >( &Args ) ) )
        return L"";
    return Args.m_arrParams.GetAt( 0 );
}

#pragma warning( pop )