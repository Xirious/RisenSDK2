#include "Session_SetGameEvent.h"

bCUnicodeString CON_Session_Sub::SetGameEvent( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCString const strGameVariableName = a_arrParams.GetAt( 1 ).GetAnsiText();
    mCCommandHandler::RegisterOrAutoCompleteParameter( &a_arrParams.GetAt( 1 ) );

    gCInfoSystem & InfoSystem = *gCInfoModule::GetInstance().GetSystem();
    if ( InfoSystem.GameVariableExists( strGameVariableName ) )
        return L"$The game variable '" + a_arrParams.GetAt( 1 ) + L"' already exists.";

    InfoSystem.SetGameVariable( strGameVariableName, 0 );
    return L"The game variable '" + a_arrParams.GetAt( 1 ) + L"' has been set.";
}