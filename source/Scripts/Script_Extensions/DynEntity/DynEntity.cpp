#include "DynEntity.h"

enum { EDynEntity = 867 };

GEInt GE_STDCALL DynEntity( gCScriptProcessingUnit * a_pSPU, GELPVoid a_pSelfEntity, GELPVoid a_pOtherEntity, GEInt a_iArgs )
{
    UNREFERENCED_PARAMETER( a_pSelfEntity );
    UNREFERENCED_PARAMETER( a_pOtherEntity );

    return CmdManagement::HandleCmdCall< EDynEntity >( L"DynEntity", L"A collection of commands dealing with dynamic entities.", L"DynEntity <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< CmdManagement::SubCmdInfo > & CmdManagement::GetSubCmdInfos< EDynEntity >( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< CmdManagement::SubCmdInfo > SubCommands;

#pragma warning( pop )

    if ( SubCommands.GetCount() == 0 )
    {
        CmdManagement::SubCmdInfo Info;

        Info.strName = L"Clone";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::Clone;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Clones a dynamic entity and adds it to the same layer.\n" \
            L"Usage:\n" \
            L"  DynEntity Clone <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"DocumentPS";
        Info.uParamCount = 2;
        Info.pFunction = CON_DynEntity::DocumentPS;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Analizes a property set and saves the result as a .txt file in the main Risen folder.\n" \
            L"Usage:\n" \
            L"  DynEntity DocumentPS <GUID> <Property set name>";
        SubCommands.Add( Info );
        
        Info.strName = L"Dump";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::Dump;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Saves a dynamic entity as a .bin file in the Risen installation folder.\n" \
            L"Usage:\n" \
            L"  DynEntity Dump <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"Edit";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::Edit;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Opens the property editor for the specified dynamic entity, just like the standard 'edit'.\n" \
            L"Usage:\n" \
            L"  DynEntity Edit <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"GetEntityGuid";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::GetEntityGuid;
        Info.pAutoComplete = CON_DynEntity::GetEntityGuidAC;
        Info.strHelpText = L"Returns the dynamic entity's GUID.\n" \
            L"Usage:\n" \
            L"  DynEntity GetEntityGuid <Name>\n" \
            L"Autocompletion (TAB) inserts a template name as parameter.";
        SubCommands.Add( Info );

        Info.strName = L"GetEntityLayer";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::GetEntityLayer;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Returns the name of the dynamic layer that includes the specified entity.\n" \
            L"Usage:\n" \
            L"  DynEntity GetEntityLayer <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"GetEntityName";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::GetEntityName;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Returns the dynamic entity's name.\n" \
            L"Usage:\n" \
            L"  DynEntity GetEntityName <GUID>";
        SubCommands.Add( Info );
        
        Info.strName = L"GetEntitySector";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::GetEntitySector;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Returns the name of the sector that includes the specified entity.\n" \
            L"Usage:\n" \
            L"  DynEntity GetEntitySector <GUID>";
        SubCommands.Add( Info );
        
        Info.strName = L"RecalcExtents";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::RecalcExtents;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Recalculates (with a 10cm padding) the bounding boxes and spheres of a dynamic entity based on the xmsh file referenced in eCMesh_PS.\n" \
            L"Usage:\n" \
            L"  DynEntity RecalcExtents <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"Remove";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::Remove;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Removes a dynamic entity from the current world.\n" \
            L"Usage:\n" \
            L"  DynEntity Remove <GUID>";
        SubCommands.Add( Info );

        Info.strName = L"SetLayer";
        Info.uParamCount = 2;
        Info.pFunction = CON_DynEntity::SetLayer;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Deletes an entity and adds a clone to the specified dynamic layer.\n" \
            L"Usage:\n" \
            L"  DynEntity SetLayer <GUID> <Dynamic layer name without .lrent extension>";
        SubCommands.Add( Info );

        Info.strName = L"Show";
        Info.uParamCount = 1;
        Info.pFunction = CON_DynEntity::Show;
        Info.pAutoComplete = 0;
        Info.strHelpText = L"Shows a dynamic entity using a fiery effect.\n" \
            L"Usage:\n" \
            L"  DynEntity Show <GUID>";
        SubCommands.Add( Info );
    }

    return SubCommands;
}