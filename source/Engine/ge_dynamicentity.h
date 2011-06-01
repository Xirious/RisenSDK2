#ifndef GE_DYNAMICENTITY_H_INCLUDED
#define GE_DYNAMICENTITY_H_INCLUDED

class GE_DLLIMPORT eCDynamicEntity :
    public eCGeometryEntity
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
        eCDynamicEntity * m_pEntity;       // 000C
    };
    GE_ASSERT_SIZEOF( CProcessor, 0x0010 )
public:    virtual void                     SetID( bCPropertyID const & );                                          
public:    virtual void                     OnTrigger( eCEntity *, eCEntity * );                                    
public:    virtual void                     OnUntrigger( eCEntity *, eCEntity * );                                  
public:    virtual void                     OnTouch( eCEntity *, eCContactIterator & );                             
public:    virtual void                     OnIntersect( eCEntity *, eCContactIterator & );                         
public:    virtual void                     OnUntouch( eCEntity *, eCContactIterator & );                           
public:    virtual void                     OnDamage( eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator & );  
protected: virtual void                     OnProcess( void );                                                      
public:    virtual void                     Render( GEI16 );                                                        
public:    virtual void                     SetLocalNodeBoundary( bCBox const & );                                  
public:    virtual void                     SetWorldNodeBoundary( bCBox const & );                                  
protected: virtual void                     OnUpdatedLocalMatrix( void );                                           
protected: virtual void                     DoSaveGameEntityPostRead( void );                                       
protected: virtual void                     UpdateChildBoundaries( void );                                          
public:    virtual GEU16                    GetVersion( void ) const;                                               
public:    virtual GEBool                   OnRead( bCIStream & );                                                  
public:    virtual GEBool                   OnWrite( bCOStream & );                                                 
public:    virtual bEResult                 Create( void );                                                         
public:    virtual void                     Destroy( void );                                                        
public:    virtual GEBool                   OnCopyFrom( bCObjectBase const & );                                     
public:    virtual bCPropertyConverterPtr   GetNativePropertyAt( GEInt ) const;                                     
protected: virtual                         ~eCDynamicEntity( void );                                                
public:    virtual eCDynamicEntity *        QueryDynamicEntity( void );                                             
public:    virtual eSEntityID *             GetEntityID( void ) const;                                              
//FIXME: OnAttach/OnDetachChild hidden in eCDynamicEntity
protected: virtual void                     UpdateParentBoundaries( void );                                         
protected: virtual void                     UpdateChildDependencies( void );                                        
protected: virtual eCDynamicEntity *        DoClone( void ) const;                                                  
public:    virtual bCPropertyID const &     GetID( void ) const;                                                    
public:    virtual GEBool                   IsDummy( void ) const;                                                  
public:    virtual void                     SetCreator( eCTemplateEntity * );                                       
public:    virtual eCTemplateEntity const * GetCreator( void ) const;                                               
public:    virtual bCString const &         GetName( void ) const;  // inline local: static bCString strEmpty;
public:    virtual void                     Decay( void );                                                          
public:    virtual GEBool                   IsAutoKillEnabled( void ) const;                                        
public:    virtual void                     CopyEntityPrivateData( eCEntity const &, GEBool );                      
protected: virtual void                     OnUpdateBoundary( void );                                               
protected: virtual void                     EnterProcessingRange( void );                                           
protected: virtual void                     ExitProcessingRange( void );                                            
public:    virtual void                     SetName( bCString const & );                                            
public:    virtual GEBool                   HasCreator( void ) const;                                               
protected: virtual void                     OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );             
protected: virtual void                     OnUpdatedWorldTreeBoundary( void );                                     
public:    virtual void                     SetLocalMatrix( bCMatrix const & );                                     
public:    virtual void                     SetWorldTreeBoundary( bCBox const & );                                  
public:    virtual bCMatrix const &         GetLocalMatrix( void ) const;                                           
public:    virtual bCBox const &            GetLocalNodeBoundary( void ) const;                                     
public:    virtual bCBox const &            GetWorldNodeBoundary( void ) const;                                     
public:    virtual bCSphere const &         GetWorldNodeSphere( void ) const;                                       
protected:
    CProcessor    m_Processor;                   // 00D0
    bCMatrix      m_matLocalMatrix;              // 00E0
    bCBox         m_boxWorldNodeBoundary;        // 0120
    bCSphere      m_sphWorldNodeSphere;          // 0138
    bCBox         m_boxLocalNodeBoundary;        // 0148
    void *        m_pNameInfo;                   // 0160 // eCEntityNameInfo *
    eSEntityID *  m_pEntityID;                   // 0164
    eCEntityProxy m_Creator;                     // 0168
    GEU16         m_bIsNativeSaveGameEntity: 1;  // 0170
    GEU16         __FIXME_0170_0002        : 1;
    GEU16         __FIXME_0170_0004        : 1;
    GEU16         m_u16VisualizedTransAxes : 4;
    GEU16         m_u16VisualizedRotAxes   : 6;
    GEU16         m_bIsInOnTrigger         : 1;
    GEU16         m_bIsInOnUntrigger       : 1;
                  GE_PADDING( 6 )
protected:
    void Invalidate( void );
public:
    bCPropertyID const & GetCreatorID( void ) const;
    GEU16                GetVisualizedRotAxes( void ) const;
    GEU16                GetVisualizedTransAxes( void ) const;
    GEBool               IsNativeSaveGameEntity( void ) const;
    bEResult             ReadSaveGame( bCIStream & );
    bEResult             SetMeshVisual( bCString const &, GEBool );
    void                 SetVisualizedRotAxes( GEU16 );
    void                 SetVisualizedTransAxes( GEU16 );
    bEResult             WriteSaveGame( bCOStream & );
protected:
    eCDynamicEntity const & operator = ( eCDynamicEntity const & );
protected:
    eCDynamicEntity( eCDynamicEntity const & );
    eCDynamicEntity( void );
};
GE_ASSERT_SIZEOF( eCDynamicEntity, 0x0178 )

#endif
