#ifndef GE_WORKSPACE_H_INCLUDED
#define GE_WORKSPACE_H_INCLUDED

class GE_DLLIMPORT gCWorkspace :
    public eCEngineComponentBase
{
GE_DECLARE_PROPERTY_OBJECT( gCWorkspace, eCEngineComponentBase )
public:    virtual void                 Destroy( void );
public:    virtual                     ~gCWorkspace(void);
public:    virtual bEResult             PreShutdown( void );
protected: using eCEngineComponentBase::Create;
protected:
    gCProject *  m_pProject;
    gCDatabase * m_pDatabase;
    bCString     m_strReserved;
public:
    static gCWorkspace & GE_STDCALL GetInstance( void );
public:
    void               Activate( void );
    bEResult           Create( bCString const & a_strReserved );
    gCDatabase *       GetCurrentDatabase( void );
    gCProject *        GetCurrentProject( void );
    gCDatabase *       GetDatabase( bCString const & a_strReserved );
    gCDatabase const * GetDatabase( bCString const & a_strReserved ) const;
    gCProject *        GetProject( bCString const & a_strReserved );
    gCProject const *  GetProject( bCString const & a_strReserved ) const;
    bEResult           Import( bCString const & a_strReserved );
    gCProject *        ImportProject( bCString const & a_strFileBaseName );
    gCProject *        ImportProject( eCArchiveFile & a_File );
    gCDatabase *       InsertNewDatabase( bCString const & a_strReserved );
    gCProject *        InsertNewProject( bCString const & a_strFilePath, GEBool a_bIsPersistable );
    GEBool             IsDataAvailable( void ) const;
    void               RemoveAll( void );
protected:
    void Invalidate( void );
};
GE_ASSERT_SIZEOF( gCWorkspace, 0x001C );

#endif
