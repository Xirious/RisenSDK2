#include "ColShape_AddBox.h"

bCUnicodeString CON_ColShape_Sub::AddBox( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * pCollisionShapePS = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !pCollisionShapePS )
        return ( "$" + pEntity->GetName() + " has no CollisionShape property set." ).GetUnicodeText();

    bCVector vecCenter;
    if ( !GetVectorFromText( vecCenter, a_arrParams.GetAt( 2 ).GetAnsiText() ) )
        return L"$Invalid center specified.";
    bCVector vecExtent;
    if ( !GetVectorFromText( vecExtent, a_arrParams.GetAt( 3 ).GetAnsiText() ) )
        return L"$Invalid extent specified.";

    bCOrientedBox obBox;
    obBox.SetCenter( vecCenter );
    obBox.SetExtent( vecExtent );
    obBox.SetOrientation( pEntity->GetWorldRotation().GetMatrix3().GetInverted() );

    eCCollisionShape * pShape = dynamic_cast< eCCollisionShape * >( eCCollisionShape::CreateObject() );
    pShape->BindPOType();
    pShape->AccessGroup().AccessValue() = eEShapeGroup_Static;
    pShape->AccessShapeType().AccessValue() = eECollisionShapeType_Box;
    pShape->SetShape( obBox );

    if ( !pCollisionShapePS->AddShape( pShape ) )
        return pShape->ReleaseReference(), L"$Failed to add the collision box.";
    pShape->ReleaseReference();

    pEntity->Enable( GEFalse );
    pEntity->Enable( GETrue );
    
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return L"A collision box has been added to " + pEntity->GetName().GetUnicodeText() + L".";
}