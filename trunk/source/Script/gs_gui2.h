#ifndef GS_GUI2_H_INCLUDED
#define GS_GUI2_H_INCLUDED

class GE_DLLIMPORT GUI2
{
protected:
    GEBool m_bLogMessagesEnabled;
public:
    GEBool     AcceptResolution( void );
    GEBool     ApplyResolution( void );
    GEBool     CanContinue( void );
    void       ClearGameLog( void );
    GEBool     Close( gEHudPage );
    void       Continue( void );
    GEBool     DoModal( bCString, GEInt &, GELPVoid );
    GEBool     GetEnableLogMessages( void ) const;
    gEHudMode  GetMode( void ) const;
    GEInt      GetNumRefreshRates( GEInt );
    GEInt      GetNumResolutions( void );
    gEPageMode GetPageMode( void ) const;
    GEInt      GetPendingRefreshRate( void );
    GEInt      GetPendingResolution( void );
    GEU32      GetRefreshRate( GEInt, GEInt );
    bCPoint    GetResolution( GEInt );
    GEInt      GetSliderThreshold( void ) const;
    void       Init( void );
    GEBool     IsBrowsing( void ) const;
    GEBool     IsBrowsingCraftSelect( void );
    GEBool     IsBrowsingGame( void ) const;
    GEBool     IsBrowsingItemSelect( void );
    GEBool     IsBrowsingLoot( void );
    GEBool     IsBrowsingMap( void ) const;
    GEBool     IsBrowsingMenu( void ) const;
    GEBool     IsBrowsingPickpocket( void );
    GEBool     IsConsoleVisible( void ) const;
    GEBool     IsEditing( void ) const;
    GEBool     IsLoading( void ) const;
    GEBool     IsVisible( gEHudPage ) const;
    GEInt      ModalAcceptResolution( void );
    GEInt      ModalClosePage( gEHudPage );
    GEInt      ModalDelete( bCUnicodeString );
    GEInt      ModalLoad( bCUnicodeString );
    GEInt      ModalNewGame( void );
    GEInt      ModalOverride( bCUnicodeString );
    GEInt      ModalQuitGame( void );
    GEInt      ModalResetKeyboard( void );
    GEInt      ModalSave( bCUnicodeString );
    GEInt      ModalStackAccept( GEInt, bCUnicodeString );
    GEInt      ModalStackAmount( GEInt, GEInt, GEInt &, bCUnicodeString );
    GEBool     Open( gEHudPage );
    GEBool     OpenAlchemy( void );
    GEBool     OpenAltar( void );
    GEBool     OpenAnvil( void );
    GEBool     OpenCooking( void );
    GEBool     OpenCoolWeapon( void );
    GEBool     OpenForge( void );
    GEBool     OpenFrying( void );
    GEBool     OpenGoldsmith( void );
    GEBool     OpenGrindStone( void );
    GEBool     OpenLoot( void );
    GEBool     OpenPickpocket( GEU32 );
    GEBool     OpenWriteScroll( void );
    void       PlayVideo( bCString const &, GEBool );
    void       PrintGameLog( bCUnicodeString const &, gELogMessageType, GEBool, GELPChar );
    void       PrintGameLogF( gELogMessageType, GELPCChar, ... );
    void       PrintItemLog( Entity, GEInt );
    GEBool     RestoreResolution( void );
    void       RestoreUserPageMode( void ) const;
    GEBool     SendAbort( gEHudPage );
    GEBool     SendGameMessage( GEInt, GEInt, GEInt, gEHudPage, GEBool );
    GEBool     SendGetSaveGameSelect( bCUnicodeString &, gEHudPage );
    GEBool     SendLockpickInfo( Entity, GEInt, gELockCombi );
    GEBool     SendLoot( Entity, GEInt, gEHudPage );
    GEBool     SendSaveGameChanged( gEHudPage );
    GEBool     SendSetSaveGameSelect( bCUnicodeString const &, gEHudPage );
    void       SetCrossHairSize( GEFloat );
    void       SetEnableLogMessages( GEBool );
    void       SetPageMode( gEPageMode const &, GEBool );
    void       SetPendingRefreshRate( GEInt );
    void       SetPendingResolution( GEInt );
    GEBool     Show( gEHudPage, GEBool );
    void       ShowConsole( GEBool );
    void       ShowCrossHair( GEBool );
    void       ShowPicture( bCString const & );
    GEBool     ShowPropertyEditor( Entity, GEBool );
    void       ShowSubtitle( bCUnicodeString const & );
    GEBool     StartTalk( Entity, bCString );
    void       StopTalk( void );
    void       ToggleEntityDebug( void );
private:
    GUI2( void );  // hide constructor
   ~GUI2( void );  // hide destructor
private:
    GUI2 & operator = ( GUI2 const & );  // hide copy assignment operator
};

GE_DLLIMPORT_EXTC GUI2 gui2;

#endif
