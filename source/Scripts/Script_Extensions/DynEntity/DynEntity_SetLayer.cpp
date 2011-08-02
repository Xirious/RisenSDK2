#include "DynEntity_SetLayer.h"

bCUnicodeString CON_DynEntity::SetLayer( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;
    bCString strName = pEntity->GetName();

    gCDynamicLayer * pLayer = GetLayer( a_arrParams.GetAt( 2 ).GetAnsiText() );
    if ( !pLayer )
        return L"$Dynamic layer not found.";

    eCDynamicEntity * pTempEntity = pLayer->CreateDynamicEntity();
    if ( !pTempEntity )
        return L"$Failed to create a new entity in the target layer.";

    eCDynamicEntity * pNewEntity = dynamic_cast< eCDynamicEntity * >( gCWorld::GetCurrentWorld()->CreateChildEntityFromTemplate( dynamic_cast< eCEntity *>( pTempEntity->GetParent() ), const_cast< eCTemplateEntity * >( pEntity->GetCreator() ) ) );
    pTempEntity->Kill();
    if ( !pNewEntity )
        return L"$Failed to create a clone of the entity in the target layer.";

    pEntity->SetName( "" );
    pNewEntity->OnCopyFrom( *pEntity );
    pNewEntity->SetName( strName );
    pNewEntity->GetEntityFlags().m_IsTemporary = false;
    pNewEntity->UpdateBoundary();

    pEntity->Kill();

    bCGuid Guid;
    bCPropertyID Id = pNewEntity->GetID();
    Id.ExtractGuid( Guid );

    bCUnicodeString strGuid = Guid.GetText().GetUnicodeText();
    ParamAutoCompletion( &strGuid );
    ParamAutoCompletion( &a_arrParams.GetAt( 2 ) );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( pNewEntity->GetName() + " has been joined to the target layer. New GUID: " + strGuid.GetAnsiText() ).GetUnicodeText();
}