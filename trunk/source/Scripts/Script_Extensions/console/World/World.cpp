#include "World.h"
#include "World_AddLayer.h"
#include "World_AddSector.h"
#include "World_ListLayers.h"
#include "World_ListSectors.h"
#include "World_RemoveLayer.h"
#include "World_RemoveSector.h"
#include "World_Save.h"
#include "World_SaveLayer.h"
#include "World_SaveSector.h"
#include "World_UpdateProcessingRange.h"
#include "../m_commandhandler.h"

GEInt GE_STDCALL CON_World( gCScriptProcessingUnit * a_pSPU, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    return mTCommandHandler< &CON_World >::HandleCommandCall( L"World", L"A collection of commands dealing with the world files, sectors and layers.", L"World <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< mCCommandHandler::SSubCommandDesc > & mTCommandHandler< &CON_World >::GetSubCommandDescs( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< mCCommandHandler::SSubCommandDesc > s_arrSubCommandDescs;

#pragma warning( pop )

    if ( s_arrSubCommandDescs.GetCount() == 0 )
    {
        mCCommandHandler::SSubCommandDesc Desc;

        Desc.m_strName = L"AddLayer";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 2;
        Desc.m_pfuncExecute = CON_World_Sub::AddLayer;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Adds a dynamic layer to the specified sector. The .lrent file is saved in the same directory as the .sec file.\n" \
            L"Usage:\n" \
            L"  World AddLayer <Sector name> <Layer name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"AddSector";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::AddSector;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Adds a sector to the current world. The .sec file is saved in the same directory as the world data file.\n" \
            L"Usage:\n" \
            L"  World AddSector <Sector name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"ListLayers";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::ListLayers;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Shows a list of dynamic layers that belong to the specified sector.\n" \
            L"Usage:\n" \
            L"  World ListLayers <Sector name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"ListSectors";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 0;
        Desc.m_pfuncExecute = CON_World_Sub::ListSectors;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Shows a list of sectors that belong to the current world.\n" \
            L"Usage:\n" \
            L"  World ListSectors";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"RemoveLayer";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::RemoveLayer;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Removes the specified layer from the sector it belongs to.\n" \
            L"Usage:\n" \
            L"  World RemoveLayer <Layer name>";
        s_arrSubCommandDescs.Add( Desc );
        
        Desc.m_strName = L"RemoveSector";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::RemoveSector;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Removes the specified sector from the current world.\n" \
            L"Usage:\n" \
            L"  World RemoveSector <Sector name>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"Save";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 0;
        Desc.m_pfuncExecute = CON_World_Sub::Save;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Saves the current world together with all of it's sectors and dynamic layers.\n" \
            L"Usage:\n" \
            L"  World Save";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"SaveLayer";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::SaveLayer;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Saves the specified dynamic layer (*.lrent) including all modifications that have been made on it's entities.\n" \
            L"Usage:\n" \
            L"  World SaveLayer <Dynamic layer name>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"SaveSector";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_World_Sub::SaveSector;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Saves the specified sector (*.sec) together with all of it's dynamic layers.\n" \
            L"Usage:\n" \
            L"  World SaveSector <Sector name>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"UpdateProcessingRange";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 0;
        Desc.m_pfuncExecute = CON_World_Sub::UpdateProcessingRange;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Updates the processing range. This is sometimes required when executing variable macros, for example before using GetGuid on a freshly spawned entity.\n" \
            L"Usage:\n" \
            L"  World UpdateProcessingRange";
        s_arrSubCommandDescs.Add( Desc );
    }

    return s_arrSubCommandDescs;
}