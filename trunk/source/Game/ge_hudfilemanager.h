#ifndef GE_HUDFILEMANAGER_H_INCLUDED
#define GE_HUDFILEMANAGER_H_INCLUDED

//FIXME: move this to engine
enum eEAppState
{
	//FIXME: eEAppState constants.
	eEAppState_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCSaveGame
{
};

class gIWorldEventClient
{
public: virtual void OnWorldEvent(GEUInt, void *, void *) = 0;
};

class GE_DLLIMPORT gCHUDFileManager : gIWorldEventClient
{
private: virtual ~gCHUDFileManager();
public: virtual void OnWorldEvent(GEUInt, void *, void *);
public: static gCHUDFileManager & GE_STDCALL GetInstance();
public: static GEInt GE_STDCALL GetLoadingProgress();
public: enum gEEventID {
	//FIXME: gEEventID constants.
	gEEventID_ForceDWORD = GE_FORCE_DWORD
};
public:
	GEBool             DeleteSaveGame(bCUnicodeString const &);
	GEBool             GetSaveGame(bCString const &, gCSaveGame &) const;
	GEInt              GetSaveGameCount() const;
	bCString           GetSaveGameDate(bCString const &) const;
	bCString           GetSaveGameDateShort(bCString const &) const;
	bCUnicodeString    GetSaveGameDateW(bCString const &) const;
	bCString           GetSaveGameFileName(GEInt) const;
	GEBool             GetSaveGameFileName(bCUnicodeString const &, bCString &) const;
	bCUnicodeString    GetSaveGameLocation(bCString const &) const;
	bCUnicodeString    GetSaveGameName(bCString const &) const;
	bCUnicodeString    GetSaveGamePlayTime(bCString const &) const;
	bCString           GetSaveGameTime(bCString const &) const;
	void               OnAppStateChanged(eEAppState, eEAppState);
	void               PostAutoSave(bCString const &);
	void               PostLoad(bCUnicodeString const &);
	void               PostNewGame();
	void               PostPrefetch();
	void               PostQuickLoad();
	void               PostQuickSave();
	void               PostSave(bCUnicodeString const &);
	void               RefreshIndexToNameMap();
	void               RefreshSaveGameImage(bCString const &);
	void               RefreshSaveGameList();
	GEBool             SaveGameExists(bCString const &) const;
	void               Shutdown();
	void               UpdateScreenshot();
	gCHUDFileManager(gCHUDFileManager const &);
	gCHUDFileManager & operator=(gCHUDFileManager const &);

protected:
	void     FindLatestSaveGame();
	GEBool   GenerateSaveGameName(bCString &) const;
	bCString GetDefaultWorldName() const;
	GEBool   GetSaveGames(bTObjArray< bCString > &) const;

protected:
	char __FIXME[ 0x44 - sizeof(gIWorldEventClient) ];

private:
	void   BeginPrefetch();
	void   BeginProgress();
	void   ClearGameEvent();
	void   EndPrefetch();
	void   EndProgress();
	GEBool LoadGame(bCString const &);
	GEBool NewGame();
	void   OnProcessEvent();
	void   PostGameEvent(gCHUDFileManager::gEEventID, bCUnicodeString const &);
	void   Prefetch();
	gCHUDFileManager();

};

// TODO: This class was not tested!
GE_ASSERT_SIZEOF( gCHUDFileManager, 0x0044 )

#endif
