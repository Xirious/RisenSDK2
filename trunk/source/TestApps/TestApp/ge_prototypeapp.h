#ifndef GE_PROTOTYPEAPP_H_INCLUDED
#define GE_PROTOTYPEAPP_H_INCLUDED

class aCProtoTypeApp :
    public gCGameApp
{
protected: virtual bEResult Create( void );
public:    virtual void     Destroy( void );
public:    virtual         ~aCProtoTypeApp( void );
public:    virtual GEBool   IsCompilerRunning( void ) const;
protected: virtual void     OnEngineReadyForBenchmark( void );
protected: virtual void     OnEngineCreated( void );
protected: virtual void     OnDestroyWorkspace( void );
public:    virtual void     OnProcess( void );
public:    virtual void     OnWorldActivate( void );
public:    virtual void     CopyFrom( aCProtoTypeApp const & );
private:
    void *            m_Reserved0;
    void *            m_Reserved1;
    bCString          m_Reserved2;
    bCObjectRefBase * m_Reserved3;
    bCObjectBase *    m_Reserved4;
    bCString          m_strObserveMemory;
    GEBool            m_bIsCompilerRunning;
public:
    bEResult Create( HINSTANCE a_hInstance, bCString const & a_strFIXME1, bCString const & a_strFIXME2 );
    void     Invalidate( void );
    GEBool   LoadProjectFile( bCString const & a_strProject, bCString const & a_strWorld );
public:
    aCProtoTypeApp const & operator = ( aCProtoTypeApp const & a_Source );
public:
    aCProtoTypeApp( aCProtoTypeApp const & a_Source );
    aCProtoTypeApp( void );
};
GE_ASSERT_SIZEOF( aCProtoTypeApp, 0x0BC4 );

#endif
