#ifndef GE_ENTITY_H_INCLUDED
#define GE_ENTITY_H_INCLUDED

struct eSEntityFlags
{
    GEU32 m_Locked            : 1;  // 00000001 0
    GEU32 m_RenderingEnabled  : 1;  // 00000002 1
    GEU32 m_Enabled           : 1;  // 00000004 2
    GEU32 m_Killed            : 1;  // 00000008 3
    GEU32 m_InProcessingRange : 1;  // 00000010 4
    GEU32 m_CachedIn          : 1;  // 00000020 5
    GEU32 m_EventsEnabled     : 1;  // 00000040 6
    GEU32 m_PickingEnabled    : 1;  // 00000080 7
    GEU32 m_CollisionEnabled  : 1;  // 00000100 8
    GEU32 __FIXME_9           : 1;  // 00000200 9
    GEU32 m_InsertType        : 4;  // 00003C00 10..13 // eCEntity::eEInsertType
    GEU32 __FIXME_14          : 1;  // 00004000 14
    GEU32 __FIXME_15          : 1;  // 00008000 15
    GEU32 __FIXME_16          : 1;  // 00010000 16
    GEU32 m_IsDynamic         : 1;  // 00020000 17
    GEU32 __FIXME_18          : 1;  // 00040000 18
    GEU32 m_IsSaveGameRelevant: 1;  // 00080000 19
    GEU32 m_IsTemporary       : 1;  // 00100000 20
    GEU32 m_IsFrozen          : 1;  // 00200000 21
    GEU32 m_IsBurned          : 1;  // 00400000 22
    GEU32 m_IsHighlighted     : 1;  // 00800000 23
    GEU32 __FIXME             : 8;  // FF000000 24..31
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTRefPtrArray<>' needs to have dll-interface to be used by clients of class 'eCEntity'

class GE_DLLIMPORT eCEntity :
    public eCNode
{
public:
    enum eEInsertType
    {
        eEInsertType_None,
        eEInsertType_Floor,
        eEInsertType_Ground,
        eEInsertType_Tree,
        eEInsertType_Wall,
        eEInsertType_Arrow,
        eEInsertType_Manual,
        eEInsertType_ForceDWORD = GE_FORCE_DWORD
    };

public:    virtual bCPropertyID const &     GetID( void ) const;                                                                      
public:    virtual void                     Enable( GEBool );                                                                         
public:    virtual void                     EnablePicking( GEBool, GEBool );                                                          
public:    virtual GEBool                   IsDummy( void ) const;                                                                    
public:    virtual void                     SetCreator( eCTemplateEntity * );                                                         
public:    virtual eCTemplateEntity const * GetCreator( void ) const;                                                                 
public:    virtual bCString const &         GetName( void ) const;                                                                    
public:    virtual GEBool                   AddPropertySet( eCEntityPropertySet * );                                                  
public:    virtual GEBool                   SetPropertySets( bTRefPtrArray< eCEntityPropertySet * > const & );                        
public:    virtual GEBool                   RemovePropertySet( bCString const & );                                                    
public:    virtual eCEntityPropertySet *    GetPropertySet( eEPropertySetType );                                                      
public:    virtual void                     Decay( void );                                                                            
public:    virtual GEBool                   IsAutoKillEnabled( void ) const;                                                          
protected: virtual void                     CopyEntityPrivateData( eCEntity const &, GEBool );                                        
protected: virtual GEBool                   OnPatchWithTemplate( eCTemplateEntity const &, GEBool, GEBool );                          
protected: virtual void                     OnUpdateBoundary( void );                                                                 
public:    virtual void                     Prefetch( bCVector const &, GEBool );                                                     
public:    virtual void                     OnCacheIn( void );                                                                        
public:    virtual void                     OnCacheOut( void );                                                                       
protected: virtual void                     EnterProcessingRange( void );                                                             
protected: virtual void                     ExitProcessingRange( void );                                                              
public:    virtual void                     CacheOut( void );                                                                         
public:    virtual void                     RenderGizmo( eCCameraBase *, GEInt );                                                     
public:    virtual void                     RenderAlphaGizmo( eCCameraBase *, GEInt );                                                
public:    virtual GEBool                   PickGizmo( eSRayIntersectionDesc &, eSGizmoPickInfo *, GEInt );                           
public:    virtual GEBool                   OnMoveGizmo( eSGizmoPickInfo const *, eCCameraBase *, bCPoint const &, GEFloat, GEInt );  
// eCNode
public:    virtual GEU16                    GetVersion( void ) const;                                                                 
public:    virtual GEBool                   OnRead( bCIStream & );                                                                    
public:    virtual GEBool                   OnWrite( bCOStream & );                                                                   
public:    virtual bEResult                 Create( void );                                                                           
public:    virtual void                     Destroy( void );                                                                          
public:    virtual GEBool                   OnCopyFrom( bCObjectBase const & );                                                       
public:    virtual GEInt                    GetNativePropertyCount( void ) const;                                                     
public:    virtual bCPropertyConverterPtr   GetNativePropertyAt( GEInt ) const;                                                       
protected: virtual                         ~eCEntity( void );                                                                         
public:    virtual eCEntity *               QueryEntity( void );                                                                      
protected: virtual void                     OnParentChanged( eCNode * );                                                              
protected: virtual void                     OnAttachChild( eCNode * );                                                                
protected: virtual void                     OnDetachChild( eCNode * );                                                                
protected:
    eSEntityFlags                          m_EntityFlags;
    eSPSIndexMap *                         m_pPSIndexMap;
    bTRefPtrArray< eCEntityPropertySet * > m_arrPropertySets;
    bCDateTime                             m_DataChangedTimeStamp;
public:
    static void * GE_STDCALL operator new( unsigned int, GELPCChar, GELPCChar, GELPCChar, GEInt );  // inline local: static char s_carrAllocBuffer[];
public:
    static void GE_STDCALL RemapEntityProxies( bTValMap< eCEntity *, eCEntity * > const &, GEBool, GEBool );
    static void GE_STDCALL RemapEntityProxiesRecursive( bCPropertyConverterPtr, bCPropertyConverterPtr, bTValMap< eCEntity *, eCEntity * > const &, GEBool, GEBool );
public:
    GEBool                      CreateFromTemplate( bCPropertyID const & );
    GEBool                      CreateFromTemplate( eCTemplateEntity const & );
    void                        EnableRendering( GEBool );
    bCDateTime const &          GetDataChangedTimeStamp( void ) const;
    eSEntityFlags &             GetEntityFlags( void );
    eSEntityFlags const &       GetEntityFlags( void ) const;
    eEInsertType                GetInsertType( void ) const;
    eCEntityPropertySet *       GetPropertySet( bCString const & );
    eCEntityPropertySet const * GetPropertySet( bCString const & ) const;
    eCEntityPropertySet const * GetPropertySet( eEPropertySetType ) const;
    eCEntityPropertySet *       GetPropertySetAt( GEInt );
    eCEntityPropertySet const * GetPropertySetAt( GEInt ) const;
    GEInt                       GetPropertySetCount( void ) const;
    GEInt                       GetPropertySetIndex( eCEntityPropertySet const * ) const;
    bCPropertyID const &        GetTemplateID( void ) const;
    GEBool                      HasPropertySet( bCString const & ) const;
    GEBool                      HasPropertySet( eEPropertySetType ) const;
    GEBool                      HasVisual( void ) const;
    GEBool                      IsPhysicRelevant( void ) const;
    GEBool                      IsSaveGameRelevant( void ) const;
    GEBool                      IsTriggerable( void ) const;
    GEBool                      IsValidPropertySetIndex( GEInt ) const;
    void                        Kill( void );
    void                        Lock( GEBool );
    GEBool                      PatchWithTemplate( bCPropertyID const &, GEBool );
    GEBool                      PatchWithTemplate( bCString const &, GEBool );
    GEBool                      PatchWithTemplate( eCTemplateEntity const &, GEBool );
    void                        PostRead( GEBool );
    void                        RemoveAllPropertySets( void );
    GEBool                      RemovePropertySet( eCEntityPropertySet * );
    GEBool                      RemovePropertySetAt( GEInt );
    void                        SetInsertType( eEInsertType );
    GEBool                      SetPropertySet( eCEntityPropertySet * );
    void                        SetSaveGameRelevant( GEBool );
    void                        SetTemporary( void );
    void                        UpdateAll( GEBool );
    void                        UpdateBoundary( void );
protected:
    static GEInt GE_CCALL ComparePropertySets( GELPCVoid, GELPCVoid );
protected:
    eCEntity( void );
    eCEntity( eCEntity const & );
protected:
    eCEntity const & operator = ( eCEntity const & );
protected:
    void Invalidate( void );
    void KillIntern( void );
    void SendListenerEvent( eSEntityListenerEvent const &, GEBool );
    void SortPropertySets( void );
};
GE_ASSERT_SIZEOF( eCEntity, 0x0030 )

#pragma warning( pop )

#endif
