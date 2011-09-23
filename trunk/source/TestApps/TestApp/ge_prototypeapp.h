#ifndef GE_PROTOTYPEAPP_H_INCLUDED
#define GE_PROTOTYPEAPP_H_INCLUDED

#include "Game.h"

class aCProtoTypeApp :
    public gCGameApp
{
protected: virtual void         CopyFrom( aCProtoTypeApp const & );
// gCGameApp
public:    virtual void         Destroy( void );
public:    virtual             ~aCProtoTypeApp( void );
protected: virtual void         OnDestroyWorkspace( void );
protected: virtual bEResult     OnCreateWindow( eCWindow::eSCreate & );
public:    virtual void         SendEngineMessage( eSEngineMessage & );
protected: using eCApplication::CopyFrom;
protected: using     gCGameApp::Create;
protected:
    FFLPVoid          m_hEngineMessageLogFile;
    GEInt             m_iEngineMessageIndentation;
    FFLPVoid          m_hMessageCallbackLogFile;
public:
    aCProtoTypeApp( void );
    aCProtoTypeApp( aCProtoTypeApp const & a_Source );
public:
    aCProtoTypeApp const & operator = ( aCProtoTypeApp const & a_Source );
public:
    bEResult Create( HINSTANCE a_hInstance, bCString const & a_strConfig, bCString const & a_strCmdLine );
    void     Invalidate( void );
    GEBool   LoadProjectFile( bCString const & a_strProject, bCString const & a_strWorld );
protected:
    static GEBool GE_STDCALL g_MessageCallback( bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GEU32 a_u32Parameter, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority );
protected:
    GEBool OnMessageCallback( bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority );
};

#endif
