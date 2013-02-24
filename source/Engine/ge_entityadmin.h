#ifndef GE_ENTITYADMIN_H_INCLUDED
#define GE_ENTITYADMIN_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'eCEntityAdmin::CProcessor' needs to have dll-interface to be used by clients of class 'gCScriptAdmin'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCScriptAdmin'

class GE_DLLIMPORT eCEntityAdmin
{
public:
    struct eSEntityStatistics
    {
        GEU32 m_u32KilledEntityCount;
        char  __FIXME__0004[ 0x0010 - 0x0004 ];
        GEU64 __FIXME__0010;
    };
protected:
    class CProcessor :
        public eCProcessible
    {
    public: virtual GEU8  GetProcessingIndex( void ) const;  
    public: virtual GEU32 GetAppStateFlags( void ) const;    
    public: virtual void  OnProcess( void );                 
    public: virtual      ~CProcessor( void );                
    protected:
        eCEntityAdmin * m_pEntityAdmin;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:
    eCEntityAdmin( eCEntityAdmin const & );
    eCEntityAdmin( void );
   ~eCEntityAdmin( void );
public:
    eCEntityAdmin & operator = ( eCEntityAdmin const & );
public:
    void                       AddKilledEntity( eCEntity * );
    bEResult                   Create( void );
    void                       Destroy( void );
    void                       EnableProcessing( GEBool );
    eSEntityStatistics const & GetStatistics( void );
    GEBool                     IsProcessingEnabled( void ) const;
    void                       KillEntities( void );
    void                       NotifyDeleteEntities( eCEntity * );
    void                       OnProcess( void );
    void                       RemoveEarlyKilledEntity( eCEntity * );
    void                       SetKilledEntityCallback( GEBool ( GE_STDCALL * )( eCEntity * ), GEBool );
protected:
    void Invalidate( void );
protected:
    CProcessor                                          m_Processor;
    bTValArray< eCEntity >                              m_arrEntities;
    bTValArray< GEBool ( GE_STDCALL * )( eCEntity * ) > m_arrEntityCallbacks;
    eSEntityStatistics                                  m_Statistics;
    GEBool                                              m_bProcessingEnabled;
                                                        GE_PADDING( 7 )
};
GE_ASSERT_SIZEOF( eCEntityAdmin, 0x0048 );

#pragma warning( pop )

#endif