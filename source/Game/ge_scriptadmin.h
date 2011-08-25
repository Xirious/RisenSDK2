#ifndef GE_SCRIPTADMIN_H_INCLUDED
#define GE_SCRIPTADMIN_H_INCLUDED

struct gSScript :
    eSScriptBase
{
    GEInt operator () ( gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
};

struct gSScriptAICallback :
    eSScriptBase
{
    GEBool operator () ( gCScriptProcessingUnit * );
};

struct gSScriptAIFunction :
    eSScriptBase
{
    GEBool operator () ( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
};

struct gSScriptAIState :
    eSScriptBase
{
    GEBool operator () ( bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
};

struct gSScriptDLL
{
    GELPVoid                           m_hModule;
    bCString                           m_strFileName;
    bTPtrArray< gSScriptAIState * >    m_arrScriptAIStates;
    bTPtrArray< gSScriptAIFunction * > m_arrScriptAIFunctions;
    bTPtrArray< gSScriptAICallback * > m_arrScriptAICallbacks;
    bTPtrArray< gSScript * >           m_arrScripts;
};
GE_ASSERT_SIZEOF( gSScriptDLL, 0x0038 )

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'gCScriptAdmin::CProcessor' needs to have dll-interface to be used by clients of class 'gCScriptAdmin'

class GE_DLLIMPORT gCScriptAdmin :
    public eCScriptAdminBase
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
        gCScriptAdmin * m_pScriptAdmin;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;                                      
public:    virtual GEBool                     IsValid( void ) const;                                            
public:    virtual bEResult                   Create( void );                                                   
public:    virtual void                       Destroy( void );                                                  
public:    virtual                           ~gCScriptAdmin( void );                                            
public:    virtual bEResult                   Initialize( void );                                               
public:    virtual bEResult                   PostInitialize( void );                                           
public:    virtual bEResult                   Shutdown( void );                                                 
public:    virtual void                       Process( void );                                                  
protected: virtual GEInt                      CallScript( gSScript *, eCEntity *, eCEntity *, GEInt );          
protected: virtual gSScript *                 RegisterScript( bCString const & );                               
protected: virtual GEBool                     UnRegisterScript( gSScript * );                                   
public:    virtual GEU32 const                GetProfileLastTicksFirst( void ) const;                           
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    CProcessor                  m_Processor;
    gCScriptProcessingUnit      m_ScriptProcessingUnit;
    void *                      __FIXME;
    bTPtrArray< gSScriptDLL * > m_arrScriptDLLs;
    GEU32                       m_u32ProfileLastTicksFirst;
    GEU32                       m_u32ProfileTicks;
protected:
    GEInt                CallScript( bCString const &, eCEntity *, eCEntity *, GEInt );
    GEInt                CallScriptFromScript( bCString const &, GELPVoid, GELPVoid, GEInt );
    GEInt                CallScriptFromScript( gSScript *, GELPVoid, GELPVoid, GEInt );
    GEBool               LoadAllScriptDLLs( void );
    gSScriptAICallback * RegisterScriptAICallback( bCString const & );
    gSScriptAIFunction * RegisterScriptAIFunction( bCString const & );
    gSScriptAIState *    RegisterScriptAIState( bCString const & );
    GEInt                RunScript( bCString const &, gCScriptProcessingUnit * );
    GEInt                RunScript( gSScript *, gCScriptProcessingUnit * );
    GEBool               RunScriptCallback( bCString const &, gCScriptProcessingUnit * );
    GEBool               RunScriptCallback( gSScriptAICallback *, gCScriptProcessingUnit * );
    GEInt                RunScriptFromScript( bCString const &, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
    GEInt                RunScriptFromScript( gSScript *, gCScriptProcessingUnit *, GELPVoid, GELPVoid, GEInt );
    GEBool               RunScriptFunction( bCString const &, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptFunction( gSScriptAIFunction *, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptState( bCString const &, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               RunScriptState( gSScriptAIState *, bTObjStack< gScriptRunTimeSingleState > &, gCScriptProcessingUnit * );
    GEBool               UnRegisterScriptAICallback( gSScriptAICallback * );
    GEBool               UnRegisterScriptAIFunction( gSScriptAIFunction * );
    GEBool               UnRegisterScriptAIState( gSScriptAIState * );
    GEBool               UnloadAllScriptDLLs( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                       AddProfileTicks( GEU32 );
    void                       ClearDLLList( void );
    gSScript const *           GetScript( bCString const & ) const;
    gSScriptAICallback const * GetScriptAICallback( bCString const & ) const;
    gSScriptAIFunction const * GetScriptAIFunction( bCString const & ) const;
    gSScriptAIState const *    GetScriptAIState( bCString const & ) const;
    gSScriptDLL const *        GetScriptDLLAt( GEInt ) const;
    GEInt                      GetScriptDLLCount( void ) const;
    GEBool                     IsScriptDLLLoaded( bCString const & ) const;
    GEBool                     LoadScriptDLL( bCString const & );
    GEBool                     UnloadScriptDLL( bCString const & );
private:
    gCScriptAdmin & operator = ( gCScriptAdmin const & );  // not defined
    gCScriptAdmin( gCScriptAdmin const & );                // not defined
public:
    gCScriptAdmin( void );
};
GE_ASSERT_SIZEOF( gCScriptAdmin, 0x0168 )

#pragma warning( pop )

#endif
