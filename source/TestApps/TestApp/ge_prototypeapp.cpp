#include "ge_prototypeapp.h"

aCProtoTypeApp const & aCProtoTypeApp::operator = ( aCProtoTypeApp const & a_Source )
{
    this->CopyFrom( a_Source );
    return (*this);
}

void aCProtoTypeApp::CopyFrom( aCProtoTypeApp const & )
{
}

GEBool aCProtoTypeApp::LoadProjectFile( bCString const & a_strProject, bCString const & a_strWorld )
{
    gCProject * pProject = gCWorkspace::GetInstance().GetProject( a_strProject );
    if( pProject )
    {
        if( !pProject->IsActive() )
        {
            pProject->Load();
        }
        {
            gCWorld * pWorld = pProject->GetWorld( a_strWorld );
            if( !pWorld )
            {
                pWorld = pProject->InsertNewWorld( a_strWorld, GEFalse );
            }
            if( pWorld )
            {
                pProject->SetActiveWorld( pWorld->GetFileBaseName() );
            }
        }
    }
    else
    {
        pProject = gCWorkspace::GetInstance().GetCurrentProject();
        if( !pProject )
        {
            pProject = gCWorkspace::GetInstance().InsertNewProject( "Temp", GEFalse );
        }
    }
    if( pProject )
    {
        if( !pProject->IsActive() )
        {
            pProject->Load();
        }
        {
            gCWorld * pWorld = pProject->GetWorld( pProject->GetActiveWorld() );
            if( pWorld && !pWorld->IsActive() )
            {
                pWorld->Activate();
            }
        }
    }
    return GETrue;
}

void aCProtoTypeApp::Invalidate( void )
{
}

void aCProtoTypeApp::OnDestroyWorkspace( void )
{
    gCGameApp::OnDestroyWorkspace();
    gCGameApp::GetAccessToWorkspace().RemoveAll();
}

aCProtoTypeApp::aCProtoTypeApp( void )
{
    this->Invalidate();
    this->Create();
}

aCProtoTypeApp::aCProtoTypeApp( aCProtoTypeApp const & a_Source )
{
    this->Invalidate();
    this->Create();
    this->CopyFrom( a_Source );
}

aCProtoTypeApp::~aCProtoTypeApp( void )
{
    this->Invalidate();
}

void aCProtoTypeApp::Destroy( void )
{
    this->DestroyWorkspace();
    gCGameApp::Destroy();
    this->Invalidate();
}

bEResult aCProtoTypeApp::Create( HINSTANCE a_hInstance, bCString const & a_strConfig, bCString const & a_strCmdLine )
{
    return gCGameApp::Create( a_hInstance, a_strConfig, a_strCmdLine );
}

