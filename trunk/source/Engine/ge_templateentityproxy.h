#ifndef GE_TEMPLATEENTITYPROXY_H_INCLUDED
#define GE_TEMPLATEENTITYPROXY_H_INCLUDED

class GE_DLLIMPORT eCTemplateEntityProxy
{
private:
    eSEntityID * m_pEntityID;     // 0000
    // sizeof(eCTemplateEntityProxy) 0004

protected:
    GEBool   Compare( eCTemplateEntityProxy const & ) const;
    bEResult CopyFrom( eCTemplateEntityProxy const & );
    bEResult Create( void );
    void     Destroy( void );
    void     Invalidate( void );
public:
    bCString                 GetAddress( void ) const;
    eCTemplateEntity *       GetEntity( void );
    eCTemplateEntity const * GetEntity( void ) const;
    bCPropertyID const &     GetEntityID( void ) const;
    GEU16                    GetVersion( void ) const;
    GEBool                   IsEntityIDValid( void ) const;
    bEResult                 Read( bCIStream & );
    void                     SetEntity( bCPropertyID const & );
    void                     SetEntity( bCString const & );
    void                     SetEntity( eCTemplateEntity * );
    bEResult                 Write( bCOStream & ) const;
public:
                                  operator eCTemplateEntity *       ( void );
                                  operator eCTemplateEntity const * ( void ) const;
    eCTemplateEntity *            operator ->                       ( void );
    eCTemplateEntity const *      operator ->                       ( void ) const;
    GEBool                        operator ==                       ( eCTemplateEntityProxy const & ) const;
    GEBool                        operator !=                       ( eCTemplateEntityProxy const & ) const;
    bCIStream &                   operator <<                       ( bCIStream & );
    bCOStream &                   operator >>                       ( bCOStream & ) const;
    eCTemplateEntityProxy const & operator =                        ( eCTemplateEntityProxy const & );
public:
    eCTemplateEntityProxy( eCTemplateEntity * );
    eCTemplateEntityProxy( eCTemplateEntityProxy const & );
    eCTemplateEntityProxy( void );
   ~eCTemplateEntityProxy( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, eCTemplateEntityProxy & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, eCTemplateEntityProxy const & );
};

#endif
