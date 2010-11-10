#ifndef GE_NODE_H_INCLUDED
#define GE_NODE_H_INCLUDED

class eCEntity;          // forward
class eCGeometryEntity;  // forward
class eCDynamicEntity;   // forward
class eCTemplateEntity;  // forward

struct eSEntityID
{
    //FIXME: eSEntityID members.
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
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;          // [0000].0000
public:    virtual GEU16                      GetVersion( void ) const;             // [0000].0004
public:    virtual GEBool                     IsValid( void ) const;                // [0000].0008
public:    using                bCObjectBase::Deserialize;                          // [0000].000C
public:    using                bCObjectBase::Serialize;                            // [0000].0010
public:    using                bCObjectBase::Read;                                 // [0000].0014
public:    using                bCObjectBase::Write;                                // [0000].0018
public:    using                bCObjectBase::OnDeserialize;                        // [0000].001C
public:    using                bCObjectBase::OnSerialize;                          // [0000].0020
public:    virtual GEBool                     OnRead( bCIStream & );                // [0000].0024
public:    virtual GEBool                     OnWrite( bCOStream & );               // [0000].0028
public:    virtual bEResult                   Create( void );                       // [0000].002C
public:    virtual void                       Destroy( void );                      // [0000].0030
public:    using                bCObjectBase::CopyFrom;                             // [0000].0034
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );   // [0000].0038
public:    using                bCObjectBase::OnCopyPatchableOnly;                  // [0000].003C
public:    using             bCObjectRefBase::AddReference;                         // [0000].0040
public:    virtual GEU32                      ReleaseReference( void );             // [0000].0044
public:    using                bCObjectBase::GetReferenceCount;                    // [0000].0048
public:    using                bCObjectBase::BindPOType;                           // [0000].004C
public:    using                bCObjectBase::PostInitializeProperties;             // [0000].0050
public:    using                bCObjectBase::HandleDeprecatedProperty;             // [0000].0054
public:    using                bCObjectBase::NotifyPropertyValueChangedEnterEx;    // [0000].0058
public:    using                bCObjectBase::NotifyPropertyValueChangedExitEx;     // [0000].005C
public:    using                bCObjectBase::OnNotifyPropertyValueChangedEnterEx;  // [0000].0060
public:    using                bCObjectBase::OnNotifyPropertyValueChangedExitEx;   // [0000].0064
public:    using                bCObjectBase::GetNativePropertyCount;               // [0000].0068
public:    using                bCObjectBase::GetNativePropertyAt;                  // [0000].006C
protected: virtual                           ~eCNode( void );                       // [0000].0070
public:    virtual eCEntity *                 QueryEntity( void );                  // [0000].0074
public:    virtual eCGeometryEntity *         QueryGeometryEntity( void );          // [0000].0078
public:    virtual eCDynamicEntity *          QueryDynamicEntity( void );           // [0000].007C
public:    virtual eCTemplateEntity *         QueryTemplateEntity( void );          // [0000].0080
public:    virtual eSEntityID *               GetEntityID( void ) const;            // [0000].0084
protected: virtual void                       OnReadContent( void );                // [0000].0088
protected: virtual void                       OnParentChanged( eCNode * );          // [0000].008C
protected: virtual void                       OnAttachChild( eCNode * );            // [0000].0090
protected: virtual void                       OnDetachChild( eCNode * );            // [0000].0094
public:    virtual void                       UpdateParentBoundaries( void );       // [0000].0098
public:    virtual void                       UpdateChildDependencies( void );      // [0000].009C
protected: virtual eCNode *                   DoClone( void ) const;                // [0000].00A0
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
