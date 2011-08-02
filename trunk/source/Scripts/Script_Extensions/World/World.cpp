#include "World.h"

enum { EWorld = 925 };

GEInt GE_STDCALL World( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    UNREFERENCED_PARAMETER( a_pSelfEntity );
    UNREFERENCED_PARAMETER( a_pOtherEntity );

    return CmdManagement::HandleCmdCall< EWorld >( L"World", L"A collection of commands dealing with the world files, sectors and layers.", L"World <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< CmdManagement::SubCmdInfo > & CmdManagement::GetSubCmdInfos< EWorld >( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< CmdManagement::SubCmdInfo > SubCommands;

#pragma warning( pop )

    if ( SubCommands.GetCount() == 0 )
    {
        CmdManagement::SubCmdInfo Info;

        Info.strName = L"AddLayer";
        Info.uParamCount = 2;
        Info.pFunction = CON_World::AddLayer;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Adds a dynamic layer to the specified sector. The .lrent file is saved in the same directory as the .sec file.\n" \
            L"Usage:\n" \
            L"  World AddLayer <Sector name> <Layer name>";
        SubCommands.Add( Info );
        
        Info.strName = L"AddSector";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::AddSector;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Adds a sector to the current world. The .sec file is saved in the same directory as the world data file.\n" \
            L"Usage:\n" \
            L"  World AddSector <Sector name>";
        SubCommands.Add( Info );
        
        Info.strName = L"ListLayers";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::ListLayers;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Shows a list of dynamic layers that belong to the specified sector.\n" \
            L"Usage:\n" \
            L"  World ListLayers <Sector name>";
        SubCommands.Add( Info );
        
        Info.strName = L"ListSectors";
        Info.uParamCount = 0;
        Info.pFunction = CON_World::ListSectors;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Shows a list of sectors that belong to the current world.\n" \
            L"Usage:\n" \
            L"  World ListSectors";
        SubCommands.Add( Info );

        Info.strName = L"RemoveLayer";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::RemoveLayer;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Removes the specified layer from the sector it belongs to.\n" \
            L"Usage:\n" \
            L"  World RemoveLayer <Layer name>";
        SubCommands.Add( Info );
        
        Info.strName = L"RemoveSector";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::RemoveSector;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Removes the specified sector from the current world.\n" \
            L"Usage:\n" \
            L"  World RemoveSector <Sector name>";
        SubCommands.Add( Info );

        Info.strName = L"Save";
        Info.uParamCount = 0;
        Info.pFunction = CON_World::Save;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Saves the current world together with all of it's sectors and dynamic layers.\n" \
            L"Usage:\n" \
            L"  World Save";
        SubCommands.Add( Info );

        Info.strName = L"SaveLayer";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::SaveLayer;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Saves the specified dynamic layer (*.lrent) including all modifications that have been made on it's entities.\n" \
            L"Usage:\n" \
            L"  World SaveLayer <Dynamic layer name>";
        SubCommands.Add( Info );

        Info.strName = L"SaveSector";
        Info.uParamCount = 1;
        Info.pFunction = CON_World::SaveSector;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Saves the specified sector (*.sec) together with all of it's dynamic layers.\n" \
            L"Usage:\n" \
            L"  World SaveSector <Sector name>";
        SubCommands.Add( Info );
    }

    return SubCommands;
}