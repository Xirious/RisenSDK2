#include "Session_ClearGameEvent.h"

bCUnicodeString CON_Session_Sub::ClearGameEvent( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString const strGameVariableName = a_arrParams.GetAt( 1 ).GetAnsiText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );

    gCInfoSystem & InfoSystem = *gCInfoModule::GetInstance().GetSystem();
    if ( !InfoSystem.GameVariableExists( strGameVariableName ) )
        return L"$The game variable '" + a_arrParams.GetAt( 1 ) + L"' doesn't exist.";

    InfoSystem.RemoveGameVariable( strGameVariableName );
    return L"The game variable '" + a_arrParams.GetAt( 1 ) + L"' has been removed.";
}