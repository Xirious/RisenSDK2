#ifndef GE_SCRIPTPROXY_H_INCLUDED
#define GE_SCRIPTPROXY_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4265 )  // class has virtual functions, but destructor is not virtual

class GE_DLLIMPORT eCScriptProxy
{
protected: virtual eSScriptBase * QueryScript( bCString const & );  // [0000].0000
protected: virtual void           ReleaseScript( eSScriptBase * );  // [0000].0004
protected:
    eSScriptBase * m_pScript;
protected:
    GEBool   Compare( eCScriptProxy const & ) const;
    bEResult CopyFrom( eCScriptProxy const & );
    bEResult Create( void );
    void     Destroy( void );
    void     Invalidate( void );
public:
    void                 Clear( void );
    eSScriptBase *       GetScript( void );
    eSScriptBase const * GetScript( void ) const;
    bCString const &     GetScriptName( void ) const;
    GEU16                GetVersion( void ) const;
    GEBool               IsScriptValid( void ) const;
    GEBool               IsValid( void ) const;
    bEResult             Read( bCIStream & );
    void                 SetScript( bCString const & );
    void                 SetScript( eSScriptBase * );
    bEResult             Write( bCOStream & ) const;
public:
                          operator bCString const & ( void ) const;
    eCScriptProxy const & operator =                ( bCString const & );
    GEBool                operator ==               ( eCScriptProxy const & ) const;
    GEBool                operator !=               ( eCScriptProxy const & ) const;
    bCIStream &           operator <<               ( bCIStream & );
    bCOStream &           operator >>               ( bCOStream & ) const;
    eCScriptProxy const & operator =                ( eCScriptProxy const & );
public:
    eCScriptProxy( eCScriptProxy const & );
    eCScriptProxy( void );
   ~eCScriptProxy( void );
public:
    friend GE_DLLIMPORT bCIStream & GE_STDCALL operator >> ( bCIStream &, eCScriptProxy & );
    friend GE_DLLIMPORT bCOStream & GE_STDCALL operator << ( bCOStream &, eCScriptProxy const & );
};
GE_ASSERT_SIZEOF( eCScriptProxy, 0x0008 )

#pragma warning( pop )

#endif
