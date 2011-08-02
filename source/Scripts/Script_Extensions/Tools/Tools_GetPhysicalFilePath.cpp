#include "Tools_GetPhysicalFilePath.h"

bCUnicodeString CON_Tools::GetPhysicalFilePath( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * a_pSPU )
{
    UNREFERENCED_PARAMETER( a_pSPU );
    
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !File.Exists() )
        return L"$Could not find the file.";
    if ( !File.IsPhysical() )
        return L"$The file is not physical.";

    ParamAutoCompletion( &a_arrParams.GetAt( 1 ) );
    return File.GetPhysicalFilePath().GetUnicodeText();
}