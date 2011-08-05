#include "TestApp.h"

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

void aCProtoTypeApp::OnWorldActivate( void )
{
    gCGameApp::OnWorldActivate();
}

GEBool aCProtoTypeApp::IsCompilerRunning( void ) const
{
    return this->m_bIsCompilerRunning;
}

void aCProtoTypeApp::Invalidate( void )
{
    this->m_Reserved0 = 0;
    this->m_Reserved1 = 0;
    this->m_Reserved2.Clear();
    this->m_Reserved3 = 0;
    this->m_Reserved4 = 0;
    this->m_bIsCompilerRunning = GEFalse;
}

bEResult aCProtoTypeApp::Create( void )
{
    return gCGameApp::Create();
}

void aCProtoTypeApp::OnProcess( void )
{
    gCGameApp::OnProcess();
}

void aCProtoTypeApp::OnEngineReadyForBenchmark( void )
{
    gCGameApp::OnEngineReadyForBenchmark();
}

void aCProtoTypeApp::OnEngineCreated( void )
{
    gCGameApp::OnEngineCreated();
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
    GE_RELEASE( this->m_Reserved3 );
    GE_DELETE< bCObjectBase >( this->m_Reserved4 );
    this->DestroyWorkspace();
    gCGameApp::Destroy();
    this->Invalidate();
}

bEResult aCProtoTypeApp::Create( HINSTANCE a_hInstance, bCString const & a_strFIXME1, bCString const & a_strFIXME2 )
{
    if( bEResult_Ok == gCGameApp::Create( a_hInstance, a_strFIXME1, a_strFIXME2 ) )
    {
        //FIXME: eCConfigAdmin::GetInstance().GetValue( eSDebugOptions::GetInstance()->ObserveMemory );
        this->m_strObserveMemory = "Audio";
    }
    return bEResult_Ok;
}

