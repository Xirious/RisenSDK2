#include "DynEntity.h"
#include "DynEntity_Clone.h"
#include "DynEntity_Dump.h"
#include "DynEntity_Edit.h"
#include "DynEntity_GetGuid.h"
#include "DynEntity_GetLayer.h"
#include "DynEntity_GetName.h"
#include "DynEntity_GetSector.h"
#include "DynEntity_LoadFromDump.h"
#include "DynEntity_RecalcExtents.h"
#include "DynEntity_Remove.h"
#include "DynEntity_SetLayer.h"
#include "DynEntity_Show.h"
#include "../m_commandhandler.h"

GEInt GE_STDCALL CON_DynEntity( gCScriptProcessingUnit * a_pSPU, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    return mTCommandHandler< &CON_DynEntity >::HandleCommandCall( L"DynEntity", L"A collection of commands dealing with dynamic entities.", L"DynEntity <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< mCCommandHandler::SSubCommandDesc > & mTCommandHandler< &CON_DynEntity >::GetSubCommandDescs( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< mCCommandHandler::SSubCommandDesc > s_arrSubCommandDescs;

#pragma warning( pop )

    if ( s_arrSubCommandDescs.GetCount() == 0 )
    {
        mCCommandHandler::SSubCommandDesc Desc;

        Desc.m_strName = L"Clone";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::Clone;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Clones a dynamic entity and adds it to the same layer.\n" \
            L"Usage:\n" \
            L"  DynEntity Clone <GUID>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"Dump";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::Dump;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Saves a dynamic entity as a .bin file in %localappdata%\\Risen\\Dumps.\n" \
            L"Usage:\n" \
            L"  DynEntity Dump <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"Edit";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::Edit;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Opens the property editor for the specified dynamic entity, just like the vanilla 'edit' command.\n" \
            L"Usage:\n" \
            L"  DynEntity Edit <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"GetGuid";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::GetGuid;
        Desc.m_pfuncAutoComplete = CON_DynEntity_Sub::GetGuidAC;
        Desc.m_strHelpText = L"Returns the dynamic entity's GUID. The result is stored in #r1.\n" \
            L"Usage:\n" \
            L"  DynEntity GetGuid <Name>\n" \
            L"Autocompletion (TAB) inserts a template name as parameter.";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"GetLayer";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::GetLayer;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Returns the name of the dynamic layer that includes the specified entity. The result is stored in #r1.\n" \
            L"Usage:\n" \
            L"  DynEntity GetLayer <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"GetName";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::GetName;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Returns the dynamic entity's name. The result is stored in #r1.\n" \
            L"Usage:\n" \
            L"  DynEntity GetName <GUID>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"GetSector";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::GetSector;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Returns the name of the sector that includes the specified entity. The result is stored in #r1.\n" \
            L"Usage:\n" \
            L"  DynEntity GetSector <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"LoadFromDump";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 2;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::LoadFromDump;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Loads an entity dump that has been created using 'DynEntity Dump'. Use with caution!\n" \
            L"Usage:\n" \
            L"  DynEntity LoadFromDump <GUID> <Dump name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"RecalcExtents";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::RecalcExtents;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Recalculates (with a 10cm padding) the bounding boxes and spheres of a dynamic entity based on the xmsh file referenced in eCMesh_PS.\n" \
            L"Usage:\n" \
            L"  DynEntity RecalcExtents <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"Remove";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::Remove;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Removes a dynamic entity from the current world.\n" \
            L"Usage:\n" \
            L"  DynEntity Remove <GUID>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"SetLayer";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 2;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::SetLayer;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Removes a dynamic entity from it's original dynamic layer and attaches it to the specified one.\n" \
            L"Usage:\n" \
            L"  DynEntity SetLayer <GUID> <Dynamic layer name without .lrent extension>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"Show";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_DynEntity_Sub::Show;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Shows a dynamic entity using a fiery effect.\n" \
            L"Usage:\n" \
            L"  DynEntity Show <GUID>";
        s_arrSubCommandDescs.Add( Desc );
    }

    return s_arrSubCommandDescs;
}