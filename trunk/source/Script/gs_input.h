#ifndef GS_INPUT_H_INCLUDED
#define GS_INPUT_H_INCLUDED

class GE_DLLIMPORT Input
{
public:
    void                    GameReset( void );
    gEActionKey             GetActionKey( GEU32 );
    bCUnicodeString         GetActionKeyDescription( GEU32 );
    gSActionKeyInfo const & GetActionKeyInfo( gEActionKey );
    gSAction const &        GetCurrentActionEvent( void ) const;
    gSDebugAction const &   GetCurrentDebugEvent( void ) const;
    gEDirection             GetDirectionOfMovementKeys( void ) const;
    GEFloat                 GetKeyPressDuration( gEActionKey ) const;
    GEFloat                 GetKeyReleasedDuration( gEActionKey ) const;
    gEActionKey             GetLastKeyDown( GEFloat & ) const;
    gEActionKey             GetLastKeyUp( GEFloat & ) const;
    bCUnicodeString         GetScanCodeDescription( GEU32 );
    GEBool                  IsKeyPressed( gEActionKey ) const;
    void                    SetActionKeyScript( eCScriptProxyScript const & );
    void                    SetMovementConstraints( GEFloat );
    GEBool                  WasKeyPressedThisFrame( gEActionKey ) const;
private:
    Input( void );  // hide constructor
   ~Input( void );  // hide destructor
private:
    Input & operator = ( Input const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC Input input;

#endif