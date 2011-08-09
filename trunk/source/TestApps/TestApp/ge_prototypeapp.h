#ifndef GE_PROTOTYPEAPP_H_INCLUDED
#define GE_PROTOTYPEAPP_H_INCLUDED

#include "Game.h"

class aCProtoTypeApp :
    public gCGameApp
{
public:    using     gCGameApp::Create;
public:    virtual void         Destroy( void );
public:    virtual             ~aCProtoTypeApp( void );
protected: virtual void         OnDestroyWorkspace( void );
public:    using eCApplication::CopyFrom;
protected: virtual void         CopyFrom( aCProtoTypeApp const & );
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

#endif
