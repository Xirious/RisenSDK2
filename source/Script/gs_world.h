#ifndef GS_WORLD_H_INCLUDED
#define GS_WORLD_H_INCLUDED

class GE_DLLIMPORT World
{
protected:
    void * m_Reserved;
public:
    void            AutoSave( bCString const & );
    void            CacheEntities( void );
    GEBool          DeleteSaveGame( bCUnicodeString const & );
    GEBool          EnableSectorFolder( bCString const &, GEBool );
    void            EndGame( void );
    void            ExitGame( void );
    bCString        FindNextSector( bCString const &, bCString const & );
    bCString        FindNextTemplate( bCString const &, bCString const &, eEPropertySetType ) const;
    bCString        GetCommandLineA( void );
    Entity          GetFocus( void ) const;
    Entity          GetInteract( void ) const;
    Entity          GetPlayer( void ) const;
    GEInt           GetSaveGameCount( void ) const;
    bCString        GetSaveGameDate( bCString const & ) const;
    bCString        GetSaveGameDateShort( bCString const & ) const;
    bCString        GetSaveGameFileName( GEInt ) const;
    bCUnicodeString GetSaveGameLocation( bCString const & ) const;
    bCUnicodeString GetSaveGameName( bCString const & ) const;
    bCUnicodeString GetSaveGamePlayTime( bCString const & ) const;
    bCString        GetSaveGameTime( bCString const & ) const;
    GEBool          GetSectorStatus( bCString const & );
    Entity          GetTrader( void ) const;
    GEBool          IsGameRunning( void ) const;
    GEBool          IsInTestMode( void ) const;
    GEBool          IsPaused( void ) const;
    GEBool          IsPrefetching( void );
    GEBool          IsSaveAllowed( void ) const;
    void            LoadGame( bCUnicodeString const & );
    void            NewGame( void );
    void            Pause( void );
    void            Prefetch( bCVector const & );
    void            Prefetch( void );
    void            QuickLoad( void );
    void            QuickSave( void );
    void            RefreshSaveGameImage( bCString const & );
    void            RefreshSaveGameList( void );
    void            Resume( void );
    void            SaveConfiguration( void );
    void            SaveGame( bCUnicodeString const & );
    GEBool          SaveGameExists( bCString const & ) const;
    void            SaveStatistics( void );
    GEBool          SetSectorStatus( bCString const &, GEBool );
    void            TogglePause( void );
    void            UpdateScreenShot( void );
public:
    World & operator = ( World const & );
public:
    World( void );
   ~World( void );
};

GE_DLLIMPORT_EXTC World world;

#endif
