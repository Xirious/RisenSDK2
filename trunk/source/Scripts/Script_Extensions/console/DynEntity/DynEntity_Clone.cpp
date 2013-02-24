#include "DynEntity_Clone.h"

bCUnicodeString CON_DynEntity_Sub::Clone( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;
    gCDynamicLayer * pLayer = GetLayer( pEntity );
    if ( !pLayer )
        return L"$The entity is not part of any dynamic layer.";

    bCMemoryStream streamEntityData;
    pEntity->OnWrite( streamEntityData );
    streamEntityData.Seek( 0, bEStreamSeekMode_Begin );
    eCDynamicEntity * pClone = pLayer->CreateDynamicEntity();
    if ( !pClone || !pClone->OnRead( streamEntityData ) )
        return L"$Failed to clone the entity.";

    bCGuid Guid;
    bCPropertyID Id = pClone->GetID();
    Id.ExtractGuid( Guid );

    strResult = Guid.GetText().GetUnicodeText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &strResult );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return strResult;
}