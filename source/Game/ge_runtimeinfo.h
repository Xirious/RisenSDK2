#ifndef GE_RUNTIMEINFO_H_INCLUDED
#define GE_RUNTIMEINFO_H_INCLUDED

class GE_DLLIMPORT gCRuntimeInfo
{
public: virtual ~gCRuntimeInfo( void );
protected:
    GEInt    m_iCurrentCommandIndex;
    GEBool   m_bExecuteFailed;
    GEBool   m_bPrepareExecuteFailed;
             GE_PADDING( 2 )
    gCInfo * m_pInfoPS;
    GEBool   m_bIsProcessingEnabled;
             GE_PADDING1( 3 )
protected:
    void   Destroy( void );
    GEBool Execute( gCInfoCommand *, GEBool );
    void   Invalidate( void );
    GEBool PrepareExecute( GEBool & );
    void   Reset( void );
public:
    GEInt                  AssureItems( eCEntity *, bCPropertyID, GEInt, gEStackType );
    void                   Create( void );
    void                   EnableProcessing( GEBool );
    GEInt                  GetCurrentCommandIndex( void ) const;
    eCEntity *             GetEntity( bCPropertyID const & );
    eCEntity *             GetEntity( bCString const & );
    eCEntity *             GetEntityByKeyword( bCString const & );
    bCPropertyID           GetEntityID( bCString const & );
    gCInfo *               GetInfoPS( void ) const;
    eCEntity *             GetOwnerEntity( void ) const;
    gCQuestManager *       GetQuestManager( void );
    gCQuestManager const * GetQuestManager( void ) const;
    GEBool                 Give( bCPropertyID const &, bCPropertyID const &, bCPropertyID const &, GEU32 const & );
    GEBool                 Give( eCEntity *, eCEntity *, GEInt, GEInt );
    GEBool                 IsChildInfo( void ) const;
    GEBool                 IsPermanent( void ) const;
    GEBool                 IsProcessingEnabled( void ) const;
    GEBool                 IsValid( bCString & ) const;
    GEBool                 OnCommandCompleted( GEBool );
    GEBool                 OnDelivery( void );
    void                   OnEndInfo( void );
    void                   Process( void );
    void                   SetInfoPS( gCInfo * );
public:
    gCRuntimeInfo & operator = ( gCRuntimeInfo const & );
public:
    gCRuntimeInfo( gCRuntimeInfo const & );
    gCRuntimeInfo( void );
};
GE_ASSERT_SIZEOF( gCRuntimeInfo, 0x0014 )

#endif
