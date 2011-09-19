#ifndef GE_ENGINECOMPONENTBASE_H_INCLUDED
#define GE_ENGINECOMPONENTBASE_H_INCLUDED

enum eEEngineMessage
{
    eEEngineMessage_WorldActivate,           // gCWorld *
    eEEngineMessage_WorldDeactivate,         // gCWorld *
    eEEngineMessage_AfterWorldDeactivate,    // gCWorld *
    eEEngineMessage_InsertSector,            // eSEngineMessage::eSWorldSector *
    eEEngineMessage_RemoveSector,            // eSEngineMessage::eSWorldSector *
    eEEngineMessage_AfterRemoveSector,       // eSEngineMessage::eSWorldSector *
    eEEngineMessage_AfterSectorActivate,     // gCWorld *
    eEEngineMessage_ProjectActivate,         //FIXME: Wild guess, no usage found.
    eEEngineMessage_ProjectDeactivate,       // gCProject *
    eEEngineMessage_AfterProjectDeactivate,  // gCProject *
    eEEngineMessage_Activate,                // eCProcessibleElement *
    eEEngineMessage_Deactivate,              // eCProcessibleElement *
    eEEngineMessage_AfterDeactivate,         // eCProcessibleElement *
    eEEngineMessage_Save,                    // eCProcessibleElement *
    eEEngineMessage_AfterSave,               // eCProcessibleElement *
    eEEngineMessage_SectorDeactivate,        // gCSector *
    eEEngineMessage_AfterSectorDeactivate,   // gCSector *
    eEEngineMessage_SectorActivate,          // gCSector *
    eEEngineMessage_Initialize,
    eEEngineMessage_PostInitialize,
    eEEngineMessage_AppInitialized,
    eEEngineMessage_PreShutdown,
    eEEngineMessage_Shutdown,
    eEEngineMessage_AppStateChanged,         // eSEngineMessage::eSAppStateChanged
    eEEngineMessage_Count,
    eEEngineMessage_ForceDWORD = GE_FORCE_DWORD
};

struct eSEngineMessage
{
    struct eSAppStateChanged {
        GEU16 m_enumNewAppState;  // eEAppState
        GEU16 m_enumOldAppState;  // eEAppState
    };
    struct eSWorldSector {
        eCProcessibleElement * m_pWorld;
        eCProcessibleElement * m_pSector;
    };

    eEEngineMessage m_enumType;
    union
    {
        eSAppStateChanged      m_AppStateChanged;
        GELPVoid               m_pData;
        eCProcessibleElement * m_pElement;
        eSWorldSector *        m_pWorldSector;
    };
};
GE_ASSERT_SIZEOF( eSEngineMessage, 0x0008 )

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
public:    virtual              ~eCEngineComponentBase( void );
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

