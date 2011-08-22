#ifndef GE_ANCHOR_PS_H_INCLUDED
#define GE_ANCHOR_PS_H_INCLUDED

enum gEAnchorType
{
    gEAnchorType_Local      = 0x00000000,
    gEAnchorType_Roam       = 0x00000001,
    gEAnchorType_Patrol     = 0x00000002,
    gEAnchorType_Event      = 0x00000003,
    gEAnchorType_ForceDWORD = GE_FORCE_DWORD
};

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTPropertyContainer<T>' needs to have dll-interface to be used by clients of class 'gCAnchor_PS'
                                   // class 'bTValArray<T>' needs to have dll-interface to be used by clients of class 'gCAnchor_PS'

class GE_DLLIMPORT gCAnchor_PS :
    public eCEntityPropertySet
{
public:    virtual bCPropertyObjectTypeBase *                 GetObjectType( void ) const;
public:    virtual GEU16                                      GetVersion( void ) const;
public:    virtual GEBool                                     OnRead( bCIStream & );
public:    virtual GEBool                                     OnWrite( bCOStream & );
public:    virtual bEResult                                   Create( void );
public:    virtual void                                       Destroy( void );
public:    virtual                                           ~gCAnchor_PS( void );
public:    virtual eEPropertySetType                          GetPropertySetType( void ) const;
public:    virtual GEBool                                     IsReferencedByTemplate( void ) const;
public:    virtual GEBool                                     IsVisual( void ) const;
protected: virtual GEBool                                     IsEntityListener( void ) const;
public:    virtual eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance( void ) const;
protected: virtual void                                       OnRenderDebug( void );
public:    virtual void                                       GetBoundary( bCBox &, GEBool );
protected: virtual GEBool                                     OnListenEntityEvent( eSEntityListenerEvent const & );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTPropertyContainer< gEAnchorType > m_enumAnchorType;
    GEU32                               m_u32MaxUsers;
    GEU32                               m_u32PatrolIndex;
    bTValArray< gCInteraction_PS * >    m_arrInteractPoints;
protected:
    void AddInteractPoint( gCInteraction_PS * );
    void Invalidate( void );
    void RemoveInteractPoint( gCInteraction_PS * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bTPropertyContainer< gEAnchorType > &       AccessAnchorType( void );
    GEU32 &                                     AccessMaxUsers( void );
    GEU32 &                                     AccessPatrolIndex( void );
    bTPropertyContainer< gEAnchorType > const & GetAnchorType( void ) const;
    bTValArray< gCInteraction_PS * > &          GetInteractPoints( void );
    bTValArray< gCInteraction_PS * > const &    GetInteractPoints( void ) const;
    GEU32 const &                               GetMaxUsers( void ) const;
    GEU32 const &                               GetPatrolIndex( void ) const;
    GEU32                                       GetUserCount( eCEntity * ) const;
    void                                        SetAnchorType( bTPropertyContainer< gEAnchorType > const & );
    void                                        SetMaxUsers( GEU32 const & );
    void                                        SetPatrolIndex( GEU32 const & );
public:
    gCAnchor_PS & operator = ( gCAnchor_PS const & );
public:
    gCAnchor_PS( gCAnchor_PS const & );
    gCAnchor_PS( void );
};
GE_ASSERT_SIZEOF( gCAnchor_PS, 0x002C )

#pragma warning( pop )

#endif
