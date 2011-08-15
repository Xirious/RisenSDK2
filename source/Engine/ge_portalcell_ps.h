#ifndef GE_PORTALCELL_PS_H_INCLUDED
#define GE_PORTALCELL_PS_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTObjArray<T>' needs to have dll-interface to be used by clients of class 'eCPortalCell_PS'

class GE_DLLIMPORT eCPortalCell_PS :
    public eCEntityPropertySet
{
public:    virtual GEBool                     Intersects( bCFrustum & ) const;
public:    virtual void                       AddPortalTo( bCFrustum const &, eCPortalCell_PS * );
public:    virtual void                       RemovePortalsTo( eCPortalCell_PS * );
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
protected: virtual bEResult                   Create( void );
protected: virtual void                       Destroy( void );
public:    virtual                           ~eCPortalCell_PS( void );
public:    virtual void                       OnRenderDebug( void );
protected:
    bTObjArray< eCPortal > m_arrPortals;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void                           ClearPortals( void );
    bTObjArray< eCPortal > const & GetPortals( void ) const;
    GEBool                         HasPortalTo( eCPortalCell_PS * ) const;
public:
    eCPortalCell_PS & operator = ( eCPortalCell_PS const & );
public:
    eCPortalCell_PS( eCPortalCell_PS const & );
    eCPortalCell_PS( void );
};
GE_ASSERT_SIZEOF( eCPortalCell_PS, 0x001C )

#pragma warning( pop )

#endif