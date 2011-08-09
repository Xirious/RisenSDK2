#ifndef GE_PROTOTYPEAPP_H_INCLUDED
#define GE_PROTOTYPEAPP_H_INCLUDED

#include "Game.h"

//FIXME: Get prototype running...
#include "Engine/ge_application.h"
class gCSessionCheats{};
class gCSessionInfo{};
#include "Game/ge_session.h"
class gCDynamicLayer{};
class gCSector{};
class gCProject;
#include "Game/ge_world.h"
class gCWorkspace;
#include "Game/ge_project.h"
#include "Game/ge_database.h"
#include "Game/ge_workspace.h"
#include "Game/ge_gameapp.h"

class aCProtoTypeApp :
    public gCGameApp
{
public:    using gCGameApp::Create;
public:    virtual void     Destroy( void );
public:    virtual         ~aCProtoTypeApp( void );
public:    virtual GEBool   IsCompilerRunning( void ) const;
protected: virtual void     OnDestroyWorkspace( void );
protected: virtual void     CopyFrom( aCProtoTypeApp const & );
private:
    void *            m_Reserved0;
    void *            m_Reserved1;
    bCString          m_Reserved2;
    bCObjectRefBase * m_Reserved3;
    bCObjectBase *    m_Reserved4;
    bCString          m_strObserveMemory;
    GEBool            m_bIsCompilerRunning;
public:
    bEResult Create( HINSTANCE a_hInstance, bCString const & a_strConfig, bCString const & a_strCmdLine );
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
