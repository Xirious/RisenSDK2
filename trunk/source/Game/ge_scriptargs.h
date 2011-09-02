#ifndef GE_SCRIPTARGS_H_INCLUDED
#define GE_SCRIPTARGS_H_INCLUDED

struct gSArgsForScriptBase
{
public: virtual ~gSArgsForScriptBase( void );
};

struct gSAIScriptArgs :
    public gSArgsForScriptBase
{
    eCEntityProxy m_Other;
    GEInt         m_iParameter;
    eCEntityProxy m_Self;
public:
    gSAIScriptArgs( eCEntity * a_pSelf, eCEntity * a_pOther );
    gSAIScriptArgs( eCEntity * a_pSelf, eCEntity * a_pOther, GEInt a_iParameter );
};
GE_ASSERT_SIZEOF( gSAIScriptArgs, 0x0018 )

//
// GEBool CON_Xxx( ..., gSConScriptArgs * )
//

enum eSConScriptEvent
{
    eSConScriptEvent_Help,
    eSConScriptEvent_Complete,
    eSConScriptEvent_Execute
};

struct gSConScriptArgs
{
    eSConScriptEvent              m_enumEvent;
    bTObjArray< bCUnicodeString > m_arrParams;
    bCUnicodeString               m_strResult;
};
GE_ASSERT_SIZEOF( gSConScriptArgs, 0x0014 )

#endif
