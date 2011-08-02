#include "ColShape_AddMesh.h"

bCUnicodeString CON_ColShape::AddMesh( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * CollisionShapePropertySet = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !CollisionShapePropertySet )
        return ( "$" + pEntity->GetName() + " has no eCCollisionShape_PS." ).GetUnicodeText();

    if ( CollisionShapePropertySet->AddShape( a_arrParams.AccessAt( 2 ).GetAnsiText(), false ) == bEResult_False )  // Bool parameter: a_bIsConvex.
        return L"$Failed to add " + a_arrParams.AccessAt( 2 ) + L" as a collision mesh.";

    GetLayer( pEntity );  // For updating the entity.
    
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    ParamAutoCompletion( &a_arrParams.GetAt( 2 ) );
    return L"The collision mesh has been added to " + pEntity->GetName().GetUnicodeText() + L".";
}