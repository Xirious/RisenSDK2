#include "ColShape_RemoveShapeAt.h"

bCUnicodeString CON_ColShape_Sub::RemoveShapeAt( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * pCollisionShapePS = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !pCollisionShapePS )
        return ( "$" + pEntity->GetName() + " has no CollisionShape property set." ).GetUnicodeText();

    GEInt iIndex = atoi( a_arrParams.GetAt( 2 ).GetAnsiText().GetText() );
    if ( static_cast< GEInt >( pCollisionShapePS->GetNumShapes() ) <= iIndex )
        return bCString::GetFormattedString( "$%s has only %i collision shapes.", pEntity->GetName().GetText(), pCollisionShapePS->GetNumShapes() ).GetUnicodeText();

    pCollisionShapePS->RemoveShapeAt( iIndex );
    pEntity->Enable( GEFalse );
    pEntity->Enable( GETrue );

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return L"The collision shape has been removed.";
}