#ifndef GE_PROJECT_H_INCLUDED
#define GE_PROJECT_H_INCLUDED

#pragma warning( push )
#pragma warning( disable : 4251 )  // class 'bTRefPtrArray<T>' needs to have dll-interface to be used by clients of class 'gCProject'

class GE_DLLIMPORT gCProject :
    public eCProcessibleElement
{
public:    virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public:    virtual GEU16                      GetVersion( void ) const;
public:    virtual GEBool                     OnRead( bCIStream & );
public:    virtual GEBool                     OnWrite( bCOStream & );
public:    using        eCProcessibleElement::Create;
public:    virtual bEResult                   Create( void );
public:    virtual void                       Destroy( void );
public:    virtual bEResult                   PostInitializeProperties( void );
public:    virtual                           ~gCProject( void );
public:    virtual GEBool                     IsDataAvailable( void ) const;
public:    virtual bCString                   GetFileExt( void ) const;
public:    virtual bCString                   GetFileType( void ) const;
public:    virtual bCString                   GetDataFileExt( void ) const;
public:    virtual GEU16                      GetFileVersion( void ) const;
protected: virtual GEBool                     OnReleaseData( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    bTRefPtrArray< gCWorld * > m_arrWorlds;
    bCString                   m_strActiveWorld;
    gCWorkspace *              m_pWorkspace;
protected:
    void Invalidate( void );
    void SetWorkspace( gCWorkspace const * );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCProject *                GE_STDCALL GetCurrentProject( void );
    static void                       GE_STDCALL GetFileExt( bCString & );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    bCString &                         AccessActiveWorld( void );
    bTRefPtrArray< gCWorld * > &       AccessWorlds( void );
    eCProcessibleElement::eEResult     Create( gCWorkspace &, bCString const & );
    bCString const &                   GetActiveWorld( void ) const;
    gCWorkspace &                      GetWorkspace( void );
    gCWorkspace const &                GetWorkspace( void ) const;
    gCWorld *                          GetWorld( bCString const & );
    gCWorld const *                    GetWorld( bCString const & ) const;
    gCWorld *                          GetWorldByIndex( GEInt );
    gCWorld const *                    GetWorldByIndex( GEInt ) const;
    GEInt                              GetWorldIndex( bCString const & ) const;
    bTRefPtrArray< gCWorld * > const & GetWorlds( void ) const;
    gCWorld *                          ImportWorld( eCArchiveFile & );
    gCWorld *                          ImportWorld( bCString const & );
    gCWorld *                          InsertNewWorld( bCString const &, GEBool );
    eCProcessibleElement::eEResult     InsertWorld( gCWorld * );
    void                               RemoveAll( void );
    eCProcessibleElement::eEResult     RemoveWorld( gCWorld * );
    void                               SetActiveWorld( bCString const & );
    void                               SetWorlds( bTRefPtrArray< gCWorld * > const & );
public:
    gCProject & operator = ( gCProject const & );
    gCProject( gCProject const & );
    gCProject( void );
};
GE_ASSERT_SIZEOF( gCProject, 0x0028 )

#pragma warning( pop )

#endif
