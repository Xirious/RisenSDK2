#include "DynEntity_Dump.h"

bCUnicodeString CON_DynEntity::Dump( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );

    bCUnicodeString strResult;
    eCDynamicEntity * pEntity = GetDynamicEntity( a_arrParams.GetAt( 1 ), strResult );
    if ( !pEntity )
        return L"$" + strResult;

    bCMemoryStream OutStream;
    if ( !pEntity->OnWrite( OutStream ) )
        return ( L"$Failed to dump " + pEntity->GetName().GetUnicodeText() + L"." );

    bCString strOutFilePath = GetRisenPath() + pEntity->GetName() + ".bin" ;
    if ( !ToFile( OutStream, strOutFilePath.GetText() ) )
        return ( L"$Could not write to " + strOutFilePath.GetUnicodeText() + L"." );

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return ( "Saved " + pEntity->GetName() + " as " + strOutFilePath + ".").GetUnicodeText();
}