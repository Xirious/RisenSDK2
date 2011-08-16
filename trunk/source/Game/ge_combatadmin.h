#ifndef GE_COMBATADMIN_H_INCLUDED
#define GE_COMBATADMIN_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTValMap<K,T>' needs to have dll-interface to be used by clients of class 'gCCombatAdmin'
                                   // class 'gCCombatAdmin::CProcessor' needs to have dll-interface to be used by clients of class 'gCCombatAdmin'

class GE_DLLIMPORT gCCombatAdmin :
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
        gCCombatAdmin * m_pCombatAdmin;
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: virtual bEResult                   Create( void );
public: virtual void                       Destroy( void );
public: virtual                           ~gCCombatAdmin( void );
public: virtual bEResult                   Initialize( void );
public: virtual bEResult                   PostInitialize( void );
public: virtual bEResult                   Shutdown( void );
public: virtual void                       Process( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    CProcessor                              m_Processor;
    bTValMap< bCString, gCCombatSpecies * > m_mapSpeciesFiles;
    eTDocObjectMap< gCCombatSpecies >       m_mapSpecieses;
protected:
    void Invalidate( void );
    void SetSpeciesFileDirty( bCString const & );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCCombatAdmin *            GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                                               AddSpecies( gCCombatSpecies *, bCString const & );
    eTDocObjectMap< gCCombatSpecies >::bCConstIterator GetIteratorBegin( void ) const;
    eTDocObjectMap< gCCombatSpecies >::bCConstIterator GetIteratorEnd( void ) const;
    gCCombatSpecies *                                  GetSpecies( bCString const & ) const;
    GEInt                                              GetSpeciesCount( void ) const;
    gCCombatSpecies *                                  LoadRawSpecies( bCString const &, GEBool );
    GEBool                                             LoadSpecieses( void );
    void                                               RemoveSpecies( gCCombatSpecies * );
    GEBool                                             RenameSpecies( bCString const &, bCString const & );
    GEBool                                             SaveRawSpecies( bCString const & );
    GEBool                                             SaveRawSpeciesAs( bCString const &, bCString const & );
public:
    gCCombatAdmin & operator = ( gCCombatAdmin const & );
public:
    gCCombatAdmin( gCCombatAdmin const & );
    gCCombatAdmin( void );
};
GE_ASSERT_SIZEOF( gCCombatAdmin, 0x0044 )

#pragma warning( pop )

#endif
