#include "DynEntity_Clone.h"

bCUnicodeString CON_DynEntity::Clone( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;
    bCString strName = pEntity->GetName();

    gCDynamicLayer * pLayer = GetLayer( pEntity );
    if ( !pLayer )
        return L"$The entity isn't part of any dynamic layer.";

    //eCDynamicEntity * pClone = dynamic_cast< eCDynamicEntity * >( gCWorld::GetCurrentWorld()->CreateChildEntityFromTemplate( dynamic_cast< eCEntity *>( pEntity->GetParent() ), eCTemplateEntity::CreateEntityCopy( pEntity, true ) ) );  

    eCDynamicEntity * pClone = dynamic_cast< eCDynamicEntity * >( gCWorld::GetCurrentWorld()->CreateChildEntityFromTemplate( dynamic_cast< eCEntity *>( pEntity->GetParent() ), const_cast< eCTemplateEntity * >( pEntity->GetCreator() ) ) );
    if ( !pClone )
        return L"$Failed to clone the entity.";

    pEntity->SetName( "" );
    pClone->OnCopyFrom( *pEntity );
    pEntity->SetName( strName );
    pClone->SetName( strName );
    pClone->GetEntityFlags().m_IsTemporary = false;
    pClone->UpdateBoundary();

    bCGuid Guid;
    bCPropertyID Id = pClone->GetID();
    Id.ExtractGuid( Guid );

    strResult = Guid.GetText().GetUnicodeText();
    ParamAutoCompletion( &strResult );
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return strResult;
}