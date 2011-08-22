#ifndef GS_SCRIPTACTIONTIMER_H_INCLUDED
#define GS_SCRIPTACTIONTIMER_H_INCLUDED

class GE_DLLIMPORT ScriptActionTimer
{
protected:
    GEBool m_bTestMode;
public:
    GEInt  ActAmbient( GEBool );
    GEInt  ActBriefly( void );
    GEInt  ActLong( void );
    GEInt  ActShort( void );
    GEInt  CombatWait( void );
    GEInt  DelayTravel( void );
    GEBool GetTestMode( void ) const;
    void   SetTestMode( GEBool );
public:
    ScriptActionTimer & operator = ( ScriptActionTimer const & );
public:
    ScriptActionTimer( void );
   ~ScriptActionTimer( void );
};

GE_C_LINKAGE GE_DLLIMPORT ScriptActionTimer ActionTimer;

#endif
