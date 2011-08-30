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
private:
    ScriptActionTimer( void );  // hide constructor
   ~ScriptActionTimer( void );  // hide destructor
private:
    ScriptActionTimer & operator = ( ScriptActionTimer const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC ScriptActionTimer ActionTimer;

#endif
