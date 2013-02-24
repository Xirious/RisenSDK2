#include "Tools_GetPhysicalFilePath.h"

bCUnicodeString CON_Tools_Sub::GetPhysicalFilePath( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    eCArchiveFile File = eCArchiveManager::GetInstance().GetFile( a_arrParams.GetAt( 1 ).GetAnsiText() );
    if ( !File.Exists() )
        return L"$Could not find the file.";
    if ( !File.IsPhysical() )
        return L"$The file is not physical.";

    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );
    return mCCommandHandler::PushResult( File.GetPhysicalFilePath().GetUnicodeText() );
}