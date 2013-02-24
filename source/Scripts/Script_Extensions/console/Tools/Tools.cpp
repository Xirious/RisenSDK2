#include "Tools.h"
#include "Tools_CamSensitivity.h"
#include "Tools_GetPhysicalFilePath.h"
#include "Tools_Test1.h"
#include "../m_commandhandler.h"

GEInt GE_STDCALL CON_Tools( gCScriptProcessingUnit * a_pSPU, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    return mTCommandHandler< &CON_Tools >::HandleCommandCall( L"Tools", L"A collection of general commands.", L"Tools <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< mCCommandHandler::SSubCommandDesc > & mTCommandHandler< &CON_Tools >::GetSubCommandDescs( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< mCCommandHandler::SSubCommandDesc > s_arrSubCommandDescs;

#pragma warning( pop )

    if ( s_arrSubCommandDescs.GetCount() == 0 )
    {
        mCCommandHandler::SSubCommandDesc Desc;

        Desc.m_strName = L"FreeCamSensitivity";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_Tools_Sub::FreeCamSensitivity;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Sets the mouse sensitivity for the free fly camera to the given floatig point value.\n" \
            L"Usage:\n" \
            L"  Tools FreeCamSensitivity <Factor>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"GetPhysicalFilePath";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_Tools_Sub::GetPhysicalFilePath;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Returns the physical file path for the specified file name. The result is stored in #r1.\n" \
            L"Usage:\n" \
            L"  Tools GetPhysicalFilePath <File name>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"PlayerCamSensitivity";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_Tools_Sub::PlayerCamSensitivity;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Sets the mouse sensitivity for the player camera to the given floatig point value.\n" \
            L"Usage:\n" \
            L"  Tools PlayerCamSensitivity <Factor>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"Test1";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 0;
        Desc.m_pfuncExecute = CON_Tools_Sub::Test1;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Some test command.\n" \
            L"Usage:\n" \
            L"  Tools Test1";
        s_arrSubCommandDescs.Add( Desc );
    }

    return s_arrSubCommandDescs;
}