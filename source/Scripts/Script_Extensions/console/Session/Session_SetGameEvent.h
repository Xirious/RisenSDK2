#ifndef SESSION_SETGAMEEVENT_H_INCLUDED
#define SESSION_SETGAMEEVENT_H_INCLUDED

#include "../m_commandhandler.h"

namespace CON_Session_Sub
{
    bCUnicodeString SetGameEvent( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * );
}

#endif