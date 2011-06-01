#ifndef GE_TEMPLATEENTITY_H_INCLUDED
#define GE_TEMPLATEENTITY_H_INCLUDED

class GE_DLLIMPORT eCTemplateEntity :
    public eCEntity
{
public:    virtual void                   SetID( bCPropertyID const & );                      
public:    virtual GEBool                 IsHelperParent( void ) const;                       
public:    virtual void                   SetName( bCString const & );                        
protected: virtual bEResult               ReadHeader( bCIStream &, GEU16 &, GEBool );         
protected: virtual bEResult               ReadContent( bCIStream &, GEU16 );                  
protected: virtual bEResult               ReadSkipData( bCIStream & );                        
public:    virtual bEResult               ReadAll( void );                                    
public:    virtual GEU16                  GetVersion( void ) const;                           
protected: virtual GEBool                 OnRead( bCIStream & );                              
protected: virtual GEBool                 OnWrite( bCOStream & );                             
public:    virtual void                   Destroy( void );                                    
public:    virtual GEBool                 OnCopyFrom( bCObjectBase const & );                 
protected: virtual bCPropertyConverterPtr GetNativePropertyAt( GEInt ) const;                 
protected: virtual                       ~eCTemplateEntity( void );                           
public:    virtual eCTemplateEntity *     QueryTemplateEntity( void );                        
public:    virtual eSEntityID *           GetEntityID( void ) const;                          
protected: virtual void                   OnReadContent( void );                              
protected: virtual void                   OnAttachChild( eCNode * );                          
protected: virtual void                   OnDetachChild( eCNode * );                          
public:    virtual eCTemplateEntity *     DoClone( void ) const;                              
public:    virtual bCPropertyID const &   GetID( void ) const;                                
public:    virtual bCString const &       GetName( void ) const;  // inline local: static bCString strEmpty;
public:    virtual void                   CopyEntityPrivateData( eCEntity const &, GEBool );  
private:
    GEU8           m_IsHelperParent : 1;     // 0030
    GEU8           m_IsContentLoaded: 1;
    GEU8           m_IsGameRelevant : 1;
                   GE_PADDING( 3 )
    bCPropertyID * m_pRefTemplateID;         // 0034
    void *         m_pNameInfo;              // 0038 // eCEntityNameInfo *
    GEFloat        m_fRenderAlphaValue;      // 003C
    GEFloat        m_fViewRange;             // 0040
    GEU8           m_u8ScaleGridPercentage;  // 0044
                   GE_PADDING1( 3 )
    void *         __FIXME_0048;
    bCVector       m_vecTranslation;         // 004C
    bCQuaternion   m_qatRotation;            // 0058
    eSEntityID *   m_pEntityID;              // 0068
                   GE_PADDING2( 4 )
    // sizeof(eCTemplateEntity)              // 0070
private:
    bEResult ReadTemplateEntityDependency( bCIStream &, bTValArray< eCTemplateEntity * > & );
protected:
    void     DeleteInstances( eCEntity * );
    void     Invalidate( void );
    void     PatchInstances( eCEntity * );
    bEResult WriteHeader( bCOStream & );
public:
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCTemplateEntity * );
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCDynamicEntity *, GEBool );
    static eCTemplateEntity * GE_STDCALL CreateEntityCopy( eCEntity *, GEBool );
    static eCTemplateEntity * GE_STDCALL CreateNewEntity( void );
    static bCString const &   GE_STDCALL GetFileExt( void );
    static GEU32              GE_STDCALL GetMagicCode1( void );
    static GEU32              GE_STDCALL GetMagicCode2( void );
    static eCTemplateEntity * GE_STDCALL Load( bCString const &, GEBool );
public:
    bCBox                    CalculateLocalNode( void ) const;
    bCMatrix                 CalculateWorldMatrix( void ) const;
    void                     DeleteContent( void );
    void                     DeleteInstances( void );
    bCString const           GetFileName( void ) const;
    bCString const           GetFilePath( void ) const;
    GEBool                   GetIsGameRelevant( void ) const;
    eCTemplateEntity const * GetRefTemplate( void ) const;
    bCPropertyID const &     GetRefTemplateID( void ) const;
    GEFloat                  GetRenderAlphaValue( void ) const;
    GEU8                     GetScaleGridPercentage( void ) const;
    GEFloat                  GetViewRange( void ) const;
    GEBool                   IsContentLoaded( void ) const;
    GEBool                   IsMultiTemplate( void ) const;
    GEBool                   IsReadOnly( void ) const;
    GEBool                   IsReferencedTemplateEntity( void ) const;
    GEBool                   IsSingleTemplate( void ) const;
    void                     Kill( void );
    bCDateTime const &       Modified( void );
    bEResult                 PatchEntity( eCEntity *, GEBool, GEBool ) const;
    GEBool                   PatchInstances( void );
    bEResult                 Save( bCString const & );
    bEResult                 Save( void );
    void                     SetAsHelperParent( void );
    void                     SetIsGameRelevant( GEBool );
    void                     SetRefTemplate( eCTemplateEntity const & );
    void                     SetRenderAlphaValue( GEFloat );
    void                     SetScaleGridPercentage( GEU8 );
    void                     SetViewRange( GEFloat );
protected:
    eCTemplateEntity const & operator = ( eCTemplateEntity const & );
protected:
    eCTemplateEntity( eCTemplateEntity const & );
    eCTemplateEntity( void );
};

#endif