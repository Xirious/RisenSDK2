#ifndef GS_INFOSYSTEM_H_INCLUDED
#define GS_INFOSYSTEM_H_INCLUDED

class GE_DLLIMPORT InfoSystem
{
public:
    static GEBool                     GE_STDCALL EndInfoSystem( GEBool );
    static GEBool                     GE_STDCALL ExistsGameVariable( bCString const & );
    static InfComAttack &             GE_STDCALL GetCurrentCommandAttack( void );
    static InfComHeal &               GE_STDCALL GetCurrentCommandHeal( void );
    static InfComInfoWait &           GE_STDCALL GetCurrentCommandInfoWait( void );
    static GEBool                     GE_STDCALL GetCurrentCommandIsValid( void );
    static bCString                   GE_STDCALL GetCurrentCommandName( void );
    static InfComPickPocket &         GE_STDCALL GetCurrentCommandPickPocket( void );
    static InfComRunAIScript &        GE_STDCALL GetCurrentCommandRunAIScript( void );
    static InfComSay &                GE_STDCALL GetCurrentCommandSay( void );
    static InfComSayConfirm &         GE_STDCALL GetCurrentCommandSayConfirm( void );
    static InfComSayHoldingPosition & GE_STDCALL GetCurrentCommandSayHoldingPosition( void );
    static InfComSayKeepItUp &        GE_STDCALL GetCurrentCommandSayKeepItUp( void );
    static InfComSaySVM &             GE_STDCALL GetCurrentCommandSaySVM( void );
    static InfComSaySound &           GE_STDCALL GetCurrentCommandSaySound( void );
    static InfComSetSectorStatus &    GE_STDCALL GetCurrentCommandSetSectorStatus( void );
    static InfComSleep &              GE_STDCALL GetCurrentCommandSleep( void );
    static InfComThink &              GE_STDCALL GetCurrentCommandThink( void );
    static gEInfoCommand              GE_STDCALL GetCurrentCommandType( void );
    static InfComUse &                GE_STDCALL GetCurrentCommandUse( void );
    static GEBool                     GE_STDCALL GetCurrentInfoIsComment( void );
    static GEBool                     GE_STDCALL GetGameVariable( bCString const &, GEInt & );
    static Entity                     GE_STDCALL GetNPC( void );
    static GEBool                     GE_STDCALL Give( Entity const &, Entity const &, GEInt, GEU32 );
    static GEBool                     GE_STDCALL HasCommentInfo( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL HasImportantInfo( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL HasInfos( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL HasNewsInfo( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL HasRefuseInfo( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL IsRunning( void );
    static GEBool                     GE_STDCALL OnCommandCompleted( GEBool );
    static GEBool                     GE_STDCALL RemoveGameVariable( bCString const & );
    static void                       GE_STDCALL SetChildMode( GEBool );
    static GEBool                     GE_STDCALL SetGameVariable( bCString const &, GEInt );
    static GEBool                     GE_STDCALL StartComment( Entity const &, Entity const & );
    static GEBool                     GE_STDCALL StartInfoSystem( Entity const &, Entity const & );
protected:
    static InfComAttack             s_InfComAttack;
    static InfComHeal               s_InfComHeal;
    static InfComInfoWait           s_InfComInfoWait;
    static InfComPickPocket         s_InfComPickPocket;
    static InfComRunAIScript        s_InfComRunAIScript;
    static InfComSay                s_InfComSay;
    static InfComSayConfirm         s_InfComSayConfirm;
    static InfComSayHoldingPosition s_InfComSayHoldingPosition;
    static InfComSayKeepItUp        s_InfComSayKeepItUp;
    static InfComSaySVM             s_InfComSaySVM;
    static InfComSaySound           s_InfComSaySound;
    static InfComSetSectorStatus    s_InfComSetSectorStatus;
    static InfComSleep              s_InfComSleep;
    static InfComThink              s_InfComThink;
    static InfComUse                s_InfComUse;
protected:
    static gCInfoCommand * GE_STDCALL GetCurrentCommand(  void  );
private:
    InfoSystem( void );  // hide constructor
   ~InfoSystem( void );  // hide destructor
private:
    InfoSystem & operator = ( InfoSystem const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC InfoSystem IS;

#endif
