#ifndef GE_HUDMODULE2_H_INCLUDED
#define GE_HUDMODULE2_H_INCLUDED

class GE_DLLIMPORT gCHudModule2 : eCEngineComponentBase
{
protected:
	class CProcessor :
		public eCProcessible
	{
	public: virtual GEU8  GetProcessingIndex(void) const;
	public: virtual GEU32 GetAppStateFlags(void) const;
	public: virtual void  OnProcess(void);
	public: virtual      ~CProcessor(void);
	protected:
		gCInfoModule * m_pInfoModule;
	};
	GE_ASSERT_SIZEOF(CProcessor, 0x0010)

GE_DECLARE_PROPERTY_OBJECT(gCHudModule2, eCEngineComponentBase)
//public: virtual bCPropertyObjectTypeBase * GetObjectType() const;
public: virtual ~gCHudModule2();
public: virtual bEResult Initialize();
public: virtual bEResult Shutdown();
public: virtual void OnAppInitialized();
public: virtual bEResult WorldActivate();
public: virtual void EngineMessageProc(eSEngineMessage &);
public: virtual void Process();
public: virtual void OnBeginRenderSolid();
public: virtual void OnEndRenderSolid();
public: virtual void OnBeginRenderAlpha();
public: virtual void OnEndRenderAlpha();
public: virtual void OnPostRender();
protected:
	CProcessor     m_Processor;
	gCHudSystem2 * m_pSystem;
public: static gCHudModule2 & GE_STDCALL GetInstance();
public: static gCHudSystem2 * GE_STDCALL GetSystem();
};
GE_ASSERT_SIZEOF( gCHudModule2, 0x0024 )


#endif
