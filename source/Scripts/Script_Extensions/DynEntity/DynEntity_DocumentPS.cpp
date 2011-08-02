#include "DynEntity_DocumentPS.h"

#include "..\_classes\gm_trackingstream.h"

bCUnicodeString CON_DynEntity::DocumentPS( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    eCEntityPropertySet * pPropertySet = pEntity->GetPropertySet( a_arrParams.GetAt( 2 ).GetAnsiText() );
    if ( !pPropertySet )
        return ( L"$" + pEntity->GetName().GetUnicodeText() + L" has no property set named \"" + a_arrParams.GetAt( 2 ) + L"\"." );
    
    mCTrackingStream TrackingStream;
    if ( !pPropertySet->OnWrite( TrackingStream ) )
        return ( L"$Failed to write " + pEntity->GetName().GetUnicodeText() + L"." + a_arrParams.GetAt( 2 ) + L"." );

    ToFile( TrackingStream, ( GetRisenPath() + "DocumentPS_Dat.bin" ) );

    bCMemoryStream DocumentationStream;
    TrackingStream.GenerateDataDocumentation( ( pEntity->GetName() + "." + pPropertySet->GetClassName() ), DocumentationStream );
    ToFile( DocumentationStream, ( GetRisenPath() + "DocumentPS_Doc.bin" ) );
    
    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    ParamAutoCompletion( &a_arrParams.GetAt( 2 ) );
    return ( L"Analized " + pEntity->GetName().GetUnicodeText() + L"." + a_arrParams.GetAt( 2 ) + L"." );
}