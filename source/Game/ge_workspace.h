#ifndef GE_WORKSPACE_H_INCLUDED
#define GE_WORKSPACE_H_INCLUDED

class GE_DLLIMPORT gCWorkspace :
    public eCEngineComponentBase
{
public: virtual bCPropertyObjectTypeBase * GetObjectType( void ) const;
public: using       eCEngineComponentBase::Create;
public: virtual void                       Destroy( void );
public: virtual                           ~gCWorkspace( void );
public: virtual bEResult                   PreShutdown( void );
private:
    static bCPropertyObjectTypeBase thisType;
protected:
    gCProject *  m_pCurrentProject;
    gCDatabase * m_pGetCurrentDatabase;
    bCString     m_FIXME;
protected:
    void Invalidate( void );
public:
    static bCObjectBase *             GE_STDCALL CreateObject( void );
    static gCWorkspace &              GE_STDCALL GetInstance( void );
    static bCPropertyObjectTypeBase & GE_STDCALL GetThisType( void );
    static void                       GE_STDCALL StaticConstructor( bCPropertyObjectTypeBase & );
public:
    void               Activate( void );
    bEResult           Create( bCString const & );
    gCDatabase *       GetCurrentDatabase( void );
    gCProject *        GetCurrentProject( void );
    gCDatabase *       GetDatabase( bCString const & );
    gCDatabase const * GetDatabase( bCString const & ) const;
    gCProject *        GetProject( bCString const & );
    gCProject const *  GetProject( bCString const & ) const;
    bEResult           Import( bCString const & );
    gCProject *        ImportProject( eCArchiveFile & );
    gCProject *        ImportProject( bCString const & );
    gCDatabase *       InsertNewDatabase( bCString const & );
    gCProject *        InsertNewProject( bCString const &, GEBool );
    GEBool             IsDataAvailable( void ) const;
    void               RemoveAll( void );
public:
    gCWorkspace & operator = ( gCWorkspace const & );
public:
    gCWorkspace( gCWorkspace const & );
    gCWorkspace( void );
};
GE_ASSERT_SIZEOF( gCWorkspace, 0x001C );

#endif
