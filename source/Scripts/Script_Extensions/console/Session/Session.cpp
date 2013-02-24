#include "Session.h"
#include "Session_ClearGameEvent.h"
#include "Session_OutputGameEvents.h"
#include "Session_SetGameEvent.h"
#include "../m_commandhandler.h"

GEInt GE_STDCALL CON_Session( gCScriptProcessingUnit * a_pSPU, GELPVoid, GELPVoid, GEInt a_iArgs )
{
    return mTCommandHandler< &CON_Session >::HandleCommandCall( L"Session", L"A collection of commands linked to the current game session.", L"Session <Command> <Arguments>", a_pSPU, a_iArgs );
}

template<>
const bTObjArray< mCCommandHandler::SSubCommandDesc > & mTCommandHandler< &CON_Session >::GetSubCommandDescs( void )
{
#pragma warning( push )
#pragma warning( disable : 4640 )

    static bTObjArray< mCCommandHandler::SSubCommandDesc > s_arrSubCommandDescs;

#pragma warning( pop )

    if ( s_arrSubCommandDescs.GetCount() == 0 )
    {
        mCCommandHandler::SSubCommandDesc Desc;

        Desc.m_strName = L"ClearGameEvent";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_Session_Sub::ClearGameEvent;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Clears the specified game event.\n" \
            L"Usage:\n" \
            L"  Session ClearGameEvent <GameEvent name>";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"OutputGameEvents";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 0;
        Desc.m_pfuncExecute = CON_Session_Sub::OutputGameEvents;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Displays a list of all game variables present.\n" \
            L"Usage:\n" \
            L"  Session OutputGameEvents";
        s_arrSubCommandDescs.Add( Desc );

        Desc.m_strName = L"SetGameEvent";
        Desc.m_iParameterCountMin = Desc.m_iParameterCountMax = 1;
        Desc.m_pfuncExecute = CON_Session_Sub::SetGameEvent;
        Desc.m_pfuncAutoComplete = 0;
        Desc.m_strHelpText = L"Sets the specified game event (custom game events allowed).\n" \
            L"Usage:\n" \
            L"  Session SetGameEvent <GameEvent name>";
        s_arrSubCommandDescs.Add( Desc );
    }

    return s_arrSubCommandDescs;
}