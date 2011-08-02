#ifndef GE_PORTALROOM_PS_H_INCLUDED
#define GE_PORTALROOM_PS_H_INCLUDED

class GE_DLLIMPORT eCPortalRoom_PS :
    public eCPortalCell_PS
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
protected: virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual GEBool                     OnCopyFrom( bCObjectBase const & );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~eCPortalRoom_PS( void );
public:    virtual eEPropertySetType          GetPropertySetType( void ) const;
public:    virtual void                       OnRenderDebug( void );
public:    virtual void                       GetBoundary( bCBox &, GEBool );
public:    virtual void                       OnPostRead( void );
protected: virtual void                       OnUpdatedWorldMatrix( bCMatrix const &, bCMatrix const & );
public:    virtual GEBool                     Intersects( bCFrustum & ) const;
public:    virtual void                       AddPortalTo( bCFrustum const &, eCPortalCell_PS * );
protected:
    bCString                         m_strReverbPreset;  // 001C
    bCString                         m_strMeshFileName;  // 0020
    bCBox                            m_boxBoundary;      // 0024
    eCPortalBSP *                    m_pPortalBSP;       // 003C
    eCPortalRoom_PS *                __FIXME_0040;
    bTValArray< eCGeometryEntity * > m_arrEntities;      // 0044
public:
    static bCObjectBase *             CreateObject( void );
    static bCPropertyObjectTypeBase & GetThisType( void );
    static void                       StaticConstructor( bCPropertyObjectTypeBase & );
protected:
    void AddEntity( eCGeometryEntity * );
    void CreateFromMesh( void );
    void Invalidate( void );
    void RemoveEntity( eCGeometryEntity * );
public:
    bCString &                               AccessReverbPreset( void );
    bTValArray< eCGeometryEntity * > const & GetEntities( void ) const;
    bCString                                 GetMeshFileName( void ) const;
    eCPortalBSP &                            GetPortalBSP( void );
    eCPortalBSP const &                      GetPortalBSP( void ) const;
    bCString const &                         GetReverbPreset( void ) const;
    void                                     SetMeshFileName( bCString const & );
    void                                     SetReverbPreset( bCString const & );
public:
    eCPortalRoom_PS & operator = ( eCPortalRoom_PS const & );
public:
    eCPortalRoom_PS( void );
    eCPortalRoom_PS( eCPortalRoom_PS const & );
};
GE_ASSERT_SIZEOF( eCPortalRoom_PS, 0x0050 )

#endif