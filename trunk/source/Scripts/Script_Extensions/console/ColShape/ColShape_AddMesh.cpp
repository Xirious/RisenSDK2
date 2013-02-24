#include "ColShape_AddMesh.h"

bCUnicodeString CON_ColShape_Sub::AddMesh( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * pCollisionShapePS = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !pCollisionShapePS )
        return ( "$" + pEntity->GetName() + " has no CollisionShape property set." ).GetUnicodeText();
    if ( pCollisionShapePS->AddShape( a_arrParams.AccessAt( 2 ).GetAnsiText(), GEFalse ) == bEResult_False )
        return L"$Failed to add " + a_arrParams.AccessAt( 2 ) + L" as a collision mesh.";

    pEntity->Enable( GEFalse );
    pEntity->Enable( GETrue );
    
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 2 ) );
    return L"The collision mesh has been added to " + pEntity->GetName().GetUnicodeText() + L".";
}