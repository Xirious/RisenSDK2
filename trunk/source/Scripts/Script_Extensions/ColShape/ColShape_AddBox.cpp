#include "ColShape_AddBox.h"

bCUnicodeString CON_ColShape::AddBox( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * CollisionShapePropertySet = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !CollisionShapePropertySet )
        return ( "$" + pEntity->GetName() + " has no eCCollisionShape_PS." ).GetUnicodeText();

    bCVector vecCenter;
    if ( !GetVectorFromText( vecCenter, a_arrParams.GetAt( 2 ).GetAnsiText() ) )
        return L"$Invalid center specified.";
    bCVector vecExtent;
    if ( !GetVectorFromText( vecExtent, a_arrParams.GetAt( 3 ).GetAnsiText() ) )
        return L"$Invalid extent specified.";

    bCOrientedBox Box;
    Box.SetCenter( vecCenter );
    Box.SetExtent( vecExtent );
    Box.SetOrientation( pEntity->GetWorldRotation().GetMatrix3().GetInverted() );

    eCCollisionShape * pShape = new( 0, 0, 0, -1 ) eCCollisionShape();
    pShape->BindPOType();
    pShape->AccessGroup().AccessValue() = eEShapeGroup_Static;
    pShape->AccessShapeType().AccessValue() = eECollisionShapeType_Box;
    pShape->SetShape( Box );

    if ( !CollisionShapePropertySet->AddShape( pShape ) )
        return L"$Failed to add the collision box.";

    GetLayer( pEntity );  // For updating the entity.
    
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return L"A collision box has been added to " + pEntity->GetName().GetUnicodeText() + L".";
}