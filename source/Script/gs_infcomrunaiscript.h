#ifndef GS_INFCOMRUNAISCRIPT_H_INCLUDED
#define GS_INFCOMRUNAISCRIPT_H_INCLUDED

GS_DECLARE_INFCOM( InfComRunAIScript, gCInfoCommandRunAIScript )
public:
    bCString GetAIScriptName( void );
    Entity   GetOther( void );
    GEInt    GetParameter( void );
    Entity   GetSelf( void );
};

#endif
