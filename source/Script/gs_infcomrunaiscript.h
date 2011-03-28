#ifndef GS_INFCOMRUNAISCRIPT_H_INCLUDED
#define GS_INFCOMRUNAISCRIPT_H_INCLUDED

class GE_DLLIMPORT InfComRunAIScript
{
public: virtual ~InfComRunAIScript( void );
protected:
    gCInfoCommand * m_pCommand;
public:
    bCString GetAIScriptName( void );
    Entity   GetOther( void );
    GEInt    GetParameter( void );
    Entity   GetSelf( void );
    void     SetCommand( gCInfoCommand * );
public:
    InfComRunAIScript & operator = ( InfComRunAIScript const & );
public:
    InfComRunAIScript( InfComRunAIScript const & );
    InfComRunAIScript( void );
};
GE_ASSERT_SIZEOF( InfComRunAIScript, 0x0008 )

#endif
