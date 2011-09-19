#ifndef GE_INFOMODULE_H_INCLUDED
#define GE_INFOMODULE_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'gCInfoModule::CProcessor' needs to have dll-interface to be used by clients of class 'gCInfoModule'

class GE_DLLIMPORT gCInfoModule :
    public eCEngineComponentBase
{
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        gCInfoModule * m_pInfoModule;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )

GE_DECLARE_PROPERTY_OBJECT( gCInfoModule, eCEngineComponentBase )
public:    virtual              ~gCInfoModule( void );
public:    virtual bEResult      Initialize( void );
public:    virtual bEResult      PostInitialize( void );
public:    virtual bEResult      Shutdown( void );
public:    virtual bEResult      WorldActivate( void );
public:    virtual void          Process( void );
public:    virtual eCStatistic * CreateStatistics( void ) const;
protected: virtual bEResult      ReadSaveGame( bCIStream & );
protected: virtual bEResult      WriteSaveGame( bCOStream & );
protected:
    CProcessor     m_Processor;
    gCInfoSystem * m_pSystem;
public:
    static gCInfoModule & GE_STDCALL GetInstance( void );
public:
    gCInfoSystem * GetSystem( void ) const;
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCInfoModule, 0x0024 )

#pragma warning( pop )

#endif
