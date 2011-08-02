#include "DynEntity_GetEntityGuid.h"

bCUnicodeString CON_DynEntity::GetEntityGuid( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    bTValArray< eCEntity * > arrEntityPointers = Entity::GetEntitiesByName( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !arrEntityPointers.GetCount() )
        return L"$No entity found.";

    if ( arrEntityPointers.GetCount() > 1 )
    {
        GEChar strBuffer[20];
        _itoa_s( arrEntityPointers.GetCount(), strBuffer, 20, 10 );
        strResult = ( bCString( "Found " ) + strBuffer + " entities. The nearest one's GUID: " ).GetUnicodeText();  
    }

    bTObjArray< Entity > arrEntities;
    arrEntities.Reserve( arrEntityPointers.GetCount() );
    for ( GEInt i = 0, ie = arrEntityPointers.GetCount(); i != ie; ++i )
    {
        arrEntities.Add( Entity( arrEntityPointers[i] ) );
    }

    Entity::SortEntityListByDistanceTo( arrEntities, Entity::GetPlayer() );
    bCGuid Guid;
    bCPropertyID Id = arrEntities.GetAt( 0 ).GetInstance()->GetID();
    Id.ExtractGuid( Guid );

    bCUnicodeString strGuid = Guid.GetText().GetUnicodeText();
    strResult += strGuid;
    ParamAutoCompletion( &strGuid );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}

#pragma warning( push )
#pragma warning( disable : 4710 )

bCUnicodeString CON_DynEntity::GetEntityGuidAC( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
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