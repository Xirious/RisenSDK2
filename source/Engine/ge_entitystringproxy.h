#ifndef GE_ENTITYSTRINGPROXY_H_INCLUDED
#define GE_ENTITYSTRINGPROXY_H_INCLUDED

class GE_DLLIMPORT eCEntityStringProxy
{
protected:
    eSEntityID * m_pEntityID;
    bCString     m_strEntityName;
protected:
    GEBool           Compare( eCEntityStringProxy const & ) const;
    bEResult         CopyFrom( eCEntityStringProxy const & );
    bEResult         Create( void );
    void             Destroy( void );
    void             Invalidate( void );
    eCEntity const * ResolveEntity( void );
public:
    bCString         GetAddress( void ) const;
    eCEntity *       GetEntity( void );
    eCEntity const * GetEntity( void ) const;
    bCString const & GetEntityName( void ) const;
    GEU16            GetVersion( void ) const;
    GEBool           IsEntityIDValid( void ) const;
    GEBool           IsEntityNameValid( void ) const;
    bEResult         Read( bCIStream & );
    void             SetEntity( bCPropertyID const & );
    void             SetEntity( bCString const & );
    void             SetEntity( eCEntity * );
    bEResult         Write( bCOStream & );
public:
                                operator eCEntity *       ( void );
                                operator eCEntity const * ( void ) const;
    eCEntity *                  operator ->               ( void );
    eCEntity const *            operator ->               ( void ) const;
    GEBool                      operator ==               ( eCEntityStringProxy const & ) const;
    GEBool                      operator !=               ( eCEntityStringProxy const & ) const;
    bCIStream &                 operator <<               ( bCIStream & );
    bCOStream &                 operator >>               ( bCOStream & );
    eCEntityStringProxy const & operator =                ( eCEntityStringProxy const & );
public:
    eCEntityStringProxy( bCString const & );
    eCEntityStringProxy( eCEntity * );
    eCEntityStringProxy( eCEntityStringProxy const & );
    eCEntityStringProxy( void );
   ~eCEntityStringProxy( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, eCEntityStringProxy & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, eCEntityStringProxy & );
};
GE_ASSERT_SIZEOF( eCEntityStringProxy, 0x0008 )

#endif
