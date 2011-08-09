#ifndef GE_NODE_H_INCLUDED
#define GE_NODE_H_INCLUDED

class eCEntity;          // forward
class eCGeometryEntity;  // forward
class eCDynamicEntity;   // forward
class eCTemplateEntity;  // forward

struct eSEntityID
{
    eCEntity *     m_pEntity;        // 0000
    GEU16          m_u16RegCounter;  // 0004
    GEU8           __FIXME_0006;
                   GE_PADDING( 1 )
    bCPropertyID * m_pID;            // 0008
    //FIXME: sizeof(eSEntityID)
};

class GE_DLLIMPORT eCNode :
    public bCObjectRefBase
{
public:
    class eCIterator
    {
    public:
        eCNode * m_pNode;  // 0000
    };
public:    virtual eCEntity *                 QueryEntity( void );                  
public:    virtual eCGeometryEntity *         QueryGeometryEntity( void );          
public:    virtual eCDynamicEntity *          QueryDynamicEntity( void );           
public:    virtual eCTemplateEntity *         QueryTemplateEntity( void );          
public:    virtual eSEntityID *               GetEntityID( void ) const;            
protected: virtual void                       OnReadContent( void );                
protected: virtual void                       OnParentChanged( eCNode * );          
protected: virtual void                       OnAttachChild( eCNode * );            
protected: virtual void                       OnDetachChild( eCNode * );            
public:    virtual void                       UpdateParentBoundaries( void );       
public:    virtual void                       UpdateChildDependencies( void );      
protected: virtual eCNode *                   DoClone( void ) const;                
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          
public:    virtual GEU16                      GetVersion( void ) const;             
public:    virtual GEBool                     IsValid( void ) const;                
public:    virtual GEBool                     OnRead( bCIStream & );                
public:    virtual GEBool                     OnWrite( bCOStream & );               
public:    virtual bEResult                   Create( void );                       
public:    virtual void                       Destroy( void );                      
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );   
public:    virtual GEU32                      ReleaseReference( void );             
protected: virtual                           ~eCNode( void );                       
private:
    static bCPropertyObjectTypeBase thisType;
private:
    eCNode * m_pParent;         // 0008
    eCNode * m_pNextNeighbour;  // 000C
    eCNode * m_pFirstChild;     // 0010
protected:
    void Invalidate( void );
    void MoveToNode( eCNode * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static eCIterator                 GE_STDCALL EndIterator( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    GEBool         AttachChild( eCNode * );
    eCNode *       Clone( void ) const;
    eCNode *       CloneIntoWorld( void ) const;
    eCNode *       CloneSubgraph( void ) const;
    void           CollectChildrenRecursive( bTPtrArray< eCNode * > & ) const;
    GEBool         ContainsParent( eCNode const * ) const;
    GEBool         DetachChild( eCNode * );
    eCIterator     GetChildIterator( void ) const;
    eCNode *       GetFirstChild( void );
    eCNode const * GetFirstChild( void ) const;
    eCNode *       GetLastChild( void );
    eCNode const * GetLastChild( void ) const;
    GEInt          GetLevel( void ) const;
    eCNode *       GetNextNeighbour( void );
    eCNode const * GetNextNeighbour( void ) const;
    eCNode *       GetParent( void );
    eCNode const * GetParent( void ) const;
    eCNode const * GetRoot( void ) const;
    GEBool         HasMultiChildren( void ) const;
    GEBool         HasParent( void ) const;
    GEBool         HasSingleChild( void ) const;
    GEBool         IsRoot( void ) const;
    void           RemoveAllChildren( void );
    void           RemoveFromParent( void );
    void           SetParent( eCNode * );
public:
    eCNode const & operator = ( eCNode const & );
public:
    eCNode( eCNode const & );
    eCNode( void );
};

#endif
