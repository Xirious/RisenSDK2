#ifndef GE_ENTITYPROXY_H_INCLUDED
#define GE_ENTITYPROXY_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCEntityProxy
{
public:    virtual bCString   GetAddress( void ) const;           // [0000].0000
protected: virtual eCEntity * ResolveEntity( void );              // [0000].0004
protected: virtual void       Destroy( void );                    // [0000].0008
protected: virtual bEResult   CopyFrom( eCEntityProxy const & );  // [0000].000C
public:    virtual bEResult   Read( bCIStream & );                // [0000].0010
public:    virtual bEResult   Write( bCOStream & ) const;         // [0000].0014
private:
    eSEntityID * m_pEntityID;
protected:
    GEBool   Compare( eCEntityProxy const & ) const;
    bEResult Create( void );
    void     Invalidate( void );
public:
    eCDynamicEntity *        GetDynamicEntity( void );
    eCDynamicEntity const *  GetDynamicEntity( void ) const;
    eCEntity *               GetEntity( void );
    eCEntity const *         GetEntity( void ) const;
    bCPropertyID const &     GetEntityID( void ) const;
    eCGeometryEntity *       GetGeometryEntity( void );
    eCGeometryEntity const * GetGeometryEntity( void ) const;
    eCTemplateEntity *       GetTemplateEntity( void );
    eCTemplateEntity const * GetTemplateEntity( void ) const;
    GEU16                    GetVersion( void ) const;
    GEBool                   IsEntityIDValid( void ) const;
    void                     SetEntity( bCPropertyID const & );
    void                     SetEntity( bCString const & );
    void                     SetEntity( eCEntity * );
public:
                          operator eCEntity *       ( void );
                          operator eCEntity const * ( void ) const;
    eCEntity *            operator ->               ( void );
    eCEntity const *      operator ->               ( void ) const;
    GEBool                operator ==               ( eCEntityProxy const & ) const;
    GEBool                operator !=               ( eCEntityProxy const & ) const;
    bCIStream &           operator <<               ( bCIStream & );
    bCOStream &           operator >>               ( bCOStream & ) const;
    eCEntityProxy const & operator =                ( eCEntityProxy const & );
public:
    eCEntityProxy( eCEntity * );
    eCEntityProxy( eCEntityProxy const & );
    eCEntityProxy( void );
   ~eCEntityProxy( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, eCEntityProxy & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, eCEntityProxy const & );
};
GE_ASSERT_SIZEOF( eCEntityProxy, 0x0008 )

#pragma warning( pop )

#endif
