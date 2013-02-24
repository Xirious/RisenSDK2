#include "World_UpdateProcessingRange.h"
#include "../../m_hacks.h"

bCUnicodeString CON_World_Sub::UpdateProcessingRange( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    eCSceneAdmin * pSceneAdmin = dynamic_cast< eCSceneAdmin * >( eCModuleAdmin::GetInstance().FindModule( "eCSceneAdmin" ) );
    if ( pSceneAdmin )
        pSceneAdmin->GetAccessToEntityAdmin().OnProcess();
    return L"Ok.";
}