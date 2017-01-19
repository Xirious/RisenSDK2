#ifndef GE_HUDSYSTEM2_H_INCLUDED
#define GE_HUDSYSTEM2_H_INCLUDED

class GE_DLLIMPORT IFFGuiBitmap2;

class GE_DLLIMPORT gCHudDialog2;
class GE_DLLIMPORT gCHudPage2;

// Interface for handling messages
class eIGuiMessageHandler2
{
	virtual GEBool OnHandleMessage(GEUInt, GEUInt, long) = 0;
	virtual GEBool PreHandleMessage(GEUInt, GEUInt, long) = 0;
};


class GE_DLLIMPORT gCHudSystem2 : eIGuiMessageHandler2
{
public:
	virtual GEBool OnHandleMessage(GEUInt, GEUInt, long);
	virtual GEBool PreHandleMessage(GEUInt, GEUInt, long);
	virtual ~gCHudSystem2();
	GEBool         ClearGameLog();
	gCHudDialog2 * CloneDialog(bCString const &);
	eCGuiFrame2 *  CloneFrame(bCString const &);
	GEBool         Close(gEHudPage);
	GEBool         Create();
	void           Destroy();
	GEBool         DoModal(bCString, GEInt &, void *);
	gCHudPage2 *   FindPage(gEHudPage) const;
	gEHudMode      GetMode() const;
	gEPageMode     GetPageMode() const;
	void           HidePicture();
	GEBool         IsBrowsing() const;
	GEBool         IsBrowsingGame() const;
	GEBool         IsBrowsingMap() const;
	GEBool         IsBrowsingMenu() const;
	GEBool         IsEditing() const;
	GEBool         IsLoading() const;
	GEBool         IsVisible(gEHudPage) const;
	void           OnAppInitialized();
	void           OnInit();
	void           OnProcess();
	void           OnWorldActivate();
	GEBool         Open(gEHudPage);
	GEBool         PrintGameLog(bCUnicodeString const &, gELogMessageType, IFFGuiBitmap2 *, GEBool, GEChar *);
	GEBool         PrintItemLog(eCEntity *, GEInt);
	void           ReSize(GEInt, GEInt);
	void           RestoreUserPageMode();
	GEBool         SendGameMessage(GEInt, GEInt, GEInt, gEHudPage, GEBool);
	void           SetPageMode(gEPageMode const &, GEBool);
	GEBool         Show(gEHudPage, GEBool);
	void           ShowPicture(bCString const &);
	void           ShowSubtitle(bCUnicodeString const &);
	gCHudSystem2(gCHudSystem2 const &);
	gCHudSystem2();
	gCHudSystem2 & operator=(gCHudSystem2 const &);

private:
	void   DumpPageReport();
	void   HandlePageChange(gEHudPage, GEBool);
	GEBool LoadWindows();
	void   RegisterPopUps();
protected:
	char __FIXME[ 0x74 - sizeof(eIGuiMessageHandler2) ];

};
GE_ASSERT_SIZEOF(gCHudSystem2, 0x0074)

#endif