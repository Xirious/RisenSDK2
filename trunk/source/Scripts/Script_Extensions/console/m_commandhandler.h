#ifndef M_COMMANDHANDLER_H_INCLUDED
#define M_COMMANDHANDLER_H_INCLUDED

#include "m_consolevaradmin.h"
#include "../m_utils.h"

struct SArgs
{
    enum EReason
    {
        EReason_Help,
        EReason_AutoComplete,
        EReason_Execute
    }                             m_enuReason;
    bTObjArray< bCUnicodeString > m_arrParams;
    bCUnicodeString               m_strResult;
};

class mCCommandHandler
{
public:
    typedef bCUnicodeString( GE_STDCALL * MFSubCommand )( bTObjArray< bCUnicodeString >, gCScriptProcessingUnit * );
    struct SSubCommandDesc;
public:
    static bCUnicodeString         RegisterOrAutoCompleteParameter( bCUnicodeString const * a_strParameterToRegister = 0 );
    static GEBool                  ParseParameters( bTObjArray< bCUnicodeString > & a_arrParams, bCUnicodeString & a_strError );
    static bCUnicodeString const & PushResult( bCUnicodeString const & a_strResult );
};

struct mCCommandHandler::SSubCommandDesc
{
    bCUnicodeString m_strName;
    bCUnicodeString m_strHelpText;
    GEInt           m_iParameterCountMin;
    GEInt           m_iParameterCountMax;
    MFSubCommand    m_pfuncAutoComplete;
    MFSubCommand    m_pfuncExecute;
};

template< gFScript x >
class mTCommandHandler :
    public mCCommandHandler
{
public:
    static void                                  AutoCompleteSubCommandName( bCUnicodeString & a_strName );
    static SSubCommandDesc const *               FindSubCommandDesc( bCUnicodeString const & a_strName );
    static bCUnicodeString                       GetCommandHelpText( bCUnicodeString const & a_strDescription, bCUnicodeString const & a_strUsage );
    static bTObjArray< SSubCommandDesc > const & GetSubCommandDescs( void );
    static bCUnicodeString                       GetSubCommandHelpText( bCUnicodeString const & a_strName );
    static GEInt                                 HandleCommandCall( bCUnicodeString const & a_strName, bCUnicodeString const & a_strDescription, bCUnicodeString const & a_strUsage, gCScriptProcessingUnit * a_pSPU, GEInt a_iArgs );
};

#include "m_commandhandler.inl"

#endif