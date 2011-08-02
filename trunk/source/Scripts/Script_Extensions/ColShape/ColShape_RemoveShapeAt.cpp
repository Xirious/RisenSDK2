#include "ColShape_RemoveShapeAt.h"

bCUnicodeString CON_ColShape::RemoveShapeAt( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCCollisionShape_PS * CollisionShapePropertySet = dynamic_cast< eCCollisionShape_PS * >( pEntity->GetPropertySet( "eCCollisionShape_PS" ) );
    if ( !CollisionShapePropertySet )
        return ( "$" + pEntity->GetName() + " has no eCCollisionShape_PS." ).GetUnicodeText();

    GEInt Index = atoi( a_arrParams.GetAt( 2 ).GetAnsiText().GetText() );

    if ( static_cast< GEInt >( CollisionShapePropertySet->GetNumShapes() ) <= Index )
    {
        GEChar Buffer[ 20 ];
        _itoa_s( static_cast< GEInt >( CollisionShapePropertySet->GetNumShapes() ), Buffer, 20, 10 );
        return ( "$" + pEntity->GetName() + " has only " + Buffer + " collision shapes." ).GetUnicodeText();
    }

    CollisionShapePropertySet->RemoveShapeAt( Index );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return L"The collision shape has been removed.";
}