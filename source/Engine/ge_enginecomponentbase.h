#ifndef GE_ENGINECOMPONENTBASE_H_INCLUDED
#define GE_ENGINECOMPONENTBASE_H_INCLUDED

enum eEEngineMessage
{
    eEEngineMessage_WorldActivate        = 0x00000000,
    eEEngineMessage_WorldDeactivate      = 0x00000001,
    eEEngineMessage_AfterWorldDeactivate = 0x00000002,
    //FIXME: eEEngineMessage constants.
    eEEngineMessage_Initialize           = 0x00000012,
    eEEngineMessage_PostInitialize       = 0x00000013,
    eEEngineMessage_OnAppInitialized     = 0x00000014,
    eEEngineMessage_PreShutdown          = 0x00000015,
    eEEngineMessage_Shutdown             = 0x00000016,
    eEEngineMessage_ForceDWORD           = GE_FORCE_DWORD
};

struct eSEngineMessage
{
    eEEngineMessage m_enumEngineMessage;
    void *          m_EngineMessageData;
};

class GE_DLLIMPORT eCEngineComponentBase :
    public bCObjectRefBase
{
public:    virtual bEResult      Initialize( void );
public:    virtual bEResult      PostInitialize( void );
public:    virtual bEResult      PreShutdown( void );
public:    virtual bEResult      Shutdown( void );
public:    virtual void          OnAppInitialized( void );
public:    virtual void          ApplyConfiguration( void );
protected: virtual bEResult      WorldActivate( void );
protected: virtual bEResult      WorldDeactivate( void );
protected: virtual bEResult      AfterWorldDeactivate( void );
public:    virtual void          EngineMessageProc( eSEngineMessage & );
public:    virtual bEResult      ResetResources( GEBool );
public:    virtual bEResult      RestoreResources( GEBool );
public:    virtual void          Process( void );
public:    virtual void          OnBeginRenderSolid( void );
public:    virtual void          OnEndRenderSolid( void );
public:    virtual void          OnBeginRenderAlpha( void );
public:    virtual void          OnEndRenderAlpha( void );
public:    virtual void          OnPostRender( void );
public:    virtual eCStatistic * CreateStatistics( void ) const;
protected: virtual bEResult      OnReadPreLoadData( bCIStream & );
protected: virtual bEResult      OnWritePreLoadData( bCOStream & );
protected: virtual bEResult      ReadSaveGame( bCIStream & );
protected: virtual bEResult      WriteSaveGame( bCOStream & );
GE_DECLARE_PROPERTY_OBJECT( eCEngineComponentBase, bCObjectRefBase )
public:    virtual GEU16         GetVersion( void ) const;
public:    virtual bEResult      Create( void );
public:    virtual void          Destroy( void );
protected:
    GEBool m_bEnabled;
    GEU8   __FIXME;
           GE_PADDING( 2 )
    GEInt  m_iModuleLevel;
public:
    void   Enable( GEBool );
    GEInt  GetModuleLevel( void ) const;
    GEBool IsEnabled( void ) const;
    void   OnProcess( void );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( eCEngineComponentBase, 0x0010 )

#endif

