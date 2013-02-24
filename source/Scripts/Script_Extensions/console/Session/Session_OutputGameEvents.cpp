#include "Session_OutputGameEvents.h"

bCUnicodeString CON_Session_Sub::OutputGameEvents( bTObjArray< bCUnicodeString > a_arrParams, gCScriptProcessingUnit * )
{
    bCMemoryStream streamOut;
    bTArrayMap< bCString, GEI32 > const & arrGameVars = gCInfoModule::GetInstance().GetSystem()->GetGameVariables();
    for ( GEInt i = 0, ie = arrGameVars.GetCount(); i != ie; ++i )
        streamOut.WriteLine( arrGameVars[ i ].m_Key + bCString::GetFormattedString( " %i", arrGameVars[ i ].m_Value ) + "\r" );

    bCString const strOutFilePath = GetRisenAppdataPath() + "\\GameVariables.txt";
    if ( !ToFile( streamOut, strOutFilePath.GetText() ) )
        return ( "$Could not write to " + strOutFilePath + "." ).GetUnicodeText();
    return ( "Saved a list of all present game variables as " + strOutFilePath + "." ).GetUnicodeText();
}