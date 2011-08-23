#ifndef GE_RESOURCEMODULE2_H_INCLUDED
#define GE_RESOURCEMODULE2_H_INCLUDED

class eIResourceLoadListener
{
public: virtual void OnResourceLoad( eCResource2 * ) = 0;
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'eCResourceModule2::CProcessor' needs to have dll-interface to be used by clients of class 'eCResourceModule2'
                                   // class 'bTPtrArray<T>' needs to have dll-interface to be used by clients of class 'eCResourceModule2'
                                   // class 'bTStringValMap<T>' needs to have dll-interface to be used by clients of class 'eCResourceModule2'

class GE_DLLIMPORT eCResourceModule2 :
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
        eCResourceModule2 * m_pResourceModule;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual                           ~eCResourceModule2( void );
public: virtual bEResult                   Initialize( void );
public: virtual bEResult                   PreShutdown( void );
public: virtual bEResult                   Shutdown( void );
public: virtual void                       ApplyConfiguration( void );
public: virtual bEResult                   ResetResources( GEBool );
public: virtual bEResult                   RestoreResources( GEBool );
public: virtual void                       Process( void );
public: virtual eCStatistic *              CreateStatistics( void ) const;
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    CProcessor                            m_Processor;
    bTPtrArray< eCResourceCache2 * >      m_arrCaches;
    bTStringValMap< eCResourceCache2 * >  m_mapCaches;
    GEBool                                m_bImmediateMode;
                                          GE_PADDING( 3 )
private:
    void          CreateCache( eSResourceCache const & );
    void          CreateCaches( void );
    void          DestroyCaches( void );
    void          DumpCaches( void );
    eCResource2 * GetResource( bCString const &, eCResourceCache2 * ) const;
    void          PopulateCaches( void );
    void          ProcessCaches( void );
    void          TestCaches( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static eCResourceModule2 &        GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    eCResource2 * CreateResource( eEResourceType ) const;
    void          DumpCaches( eCArchiveFile & );
    void          FlushCaches( void );
    bCString      FormatTotalNumQueuedBytes( void ) const;
    GEBool        GetImmediateMode( void ) const;
    eCResource2 * GetResource( bCString const & ) const;
    eCResource2 * GetResource( eEResourceType, bCString const & ) const;
    GEUInt        GetTotalNumQueuedBytes( void ) const;
    void          LoadResources( eEResourceType, eIResourceLoadListener * );
    void          SetImmediateMode( GEBool );
public:
    eCResourceModule2 & operator = ( eCResourceModule2 const & );
public:
    eCResourceModule2( eCResourceModule2 const & );
    eCResourceModule2( void );
};
GE_ASSERT_SIZEOF( eCResourceModule2, 0x0040 )

#pragma warning( pop )

#endif
