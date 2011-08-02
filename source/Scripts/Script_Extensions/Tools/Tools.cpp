#include "Tools.h"

enum { ETools = 457 };

GEInt GE_STDCALL Tools( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    UNREFERENCED_PARAMETER( a_pSelfEntity );
    UNREFERENCED_PARAMETER( a_pOtherEntity );

    return CmdManagement::HandleCmdCall< ETools >( L"Tools", L"A collection of general commands.", L"Tools <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< CmdManagement::SubCmdInfo > & CmdManagement::GetSubCmdInfos< ETools >( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< CmdManagement::SubCmdInfo > SubCommands;

#pragma warning( pop )

    if ( SubCommands.GetCount() == 0 )
    {
        CmdManagement::SubCmdInfo Info;

        Info.strName = L"GetClipboardText";
        Info.uParamCount = 0;
        Info.pFunction = CON_Tools::GetClipboardText;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Displays clipboard text if available.\n" \
            L"Usage:\n" \
            L"  Tools GetClipboardText";
        SubCommands.Add( Info );

        Info.strName = L"GetPhysicalFilePath";
        Info.uParamCount = 1;
        Info.pFunction = CON_Tools::GetPhysicalFilePath;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Returns the physical file path for the specified file name.\n" \
            L"Usage:\n" \
            L"  Tools GetPhysicalFilePath <File name>";
        SubCommands.Add( Info );

        Info.strName = L"SetClipboardText";
        Info.uParamCount = 1;
        Info.pFunction = CON_Tools::SetClipboardText;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Copys given text (that doesn't contain spaces) to the clipboard.\n" \
            L"Usage:\n" \
            L"  Tools SetClipboardText <Text>";
        SubCommands.Add( Info );
    }

    return SubCommands;
}