#include "ge_prototypeapp.h"

void aCProtoTypeApp::Invalidate( void )
{
    g_FFInvalidateFileHandle( this->m_hEngineMessageLogFile );
    this->m_iEngineMessageIndentation = 0;
    g_FFInvalidateFileHandle( this->m_hMessageCallbackLogFile );
}

aCProtoTypeApp::aCProtoTypeApp( void )
{
    this->Invalidate();
    this->Create();
}

bEResult aCProtoTypeApp::Create( HINSTANCE a_hInstance, bCString const & a_strConfig, bCString const & a_strCmdLine )
{
    bCCommandLine CommandLine( a_strCmdLine );
    if( GETrue == CommandLine.GetOptions().IsValidKey( "enginelog" ) )
    {
        this->m_hEngineMessageLogFile = g_FFCreateFile(
            gCGameApp::GetApplicationFileName() + ".engine.log",
            EFFFileCreate_CreateAlways, EFFFileAccess_Write, EFFFileShare_Read, 0, 0 );
    }
    if( GETrue == CommandLine.GetOptions().IsValidKey( "messagelog" ) )
    {
        this->m_hMessageCallbackLogFile = g_FFCreateFile(
            gCGameApp::GetApplicationFileName() + ".message.log",
            EFFFileCreate_CreateAlways, EFFFileAccess_Write, EFFFileShare_Read, 0, 0 );
        bCMessageAdmin::GetInstance().RegisterCallback(
            aCProtoTypeApp::g_MessageCallback, bEMessageCallbackPriority_Normal,
            reinterpret_cast< GEU32 >( this ) );
    }
    return gCGameApp::Create( a_hInstance, a_strConfig, a_strCmdLine );
}

void aCProtoTypeApp::CopyFrom( aCProtoTypeApp const & )
{
}

aCProtoTypeApp::aCProtoTypeApp( aCProtoTypeApp const & a_Source )
{
    this->Invalidate();
    this->Create();
    this->CopyFrom( a_Source );
}

aCProtoTypeApp const & aCProtoTypeApp::operator = ( aCProtoTypeApp const & a_Source )
{
    this->CopyFrom( a_Source );
    return (*this);
}

void aCProtoTypeApp::Destroy( void )
{
    this->DestroyWorkspace();
    gCGameApp::Destroy();
    if( g_FFIsValidFileHandle( this->m_hEngineMessageLogFile ) )
        g_FFCloseFile( this->m_hEngineMessageLogFile );
    if( g_FFIsValidFileHandle( this->m_hMessageCallbackLogFile ) )
        g_FFCloseFile( this->m_hMessageCallbackLogFile );
    this->Invalidate();
}

void aCProtoTypeApp::OnDestroyWorkspace( void )
{
    gCGameApp::OnDestroyWorkspace();
    gCGameApp::GetAccessToWorkspace().RemoveAll();
}

bEResult aCProtoTypeApp::OnCreateWindow( eCWindow::eSCreate & a_WindowSetup )
{
    bEResult enumResult = gCGameApp::OnCreateWindow( a_WindowSetup );
    if( (bEResult_Ok == enumResult) &&
        (eCWindow::eEWindowMode_FullScreen == a_WindowSetup.m_enumWindowMode) &&
        (GETrue == bCCommandLine( this->GetCommandLineA() ).GetOptions().IsValidKey( "window" )) )
    {
        a_WindowSetup.m_enumWindowMode = eCWindow::eEWindowMode_Sizeable;
    }
    return enumResult;
};

aCProtoTypeApp::~aCProtoTypeApp( void )
{
    this->Invalidate();
}

GEBool aCProtoTypeApp::LoadProjectFile( bCString const & a_strProject, bCString const & a_strWorld )
{
    gCWorkspace & Workspace = gCWorkspace::GetInstance();
    gCProject * pProject = Workspace.GetProject( a_strProject );
    if( 0 == pProject )
    {
        pProject = Workspace.GetCurrentProject();
        if( 0 == pProject )
            pProject = Workspace.InsertNewProject( a_strProject, GEFalse );
    }
    if( pProject )
    {
        if( GEFalse == pProject->IsActive() )
            pProject->Load();
        {
            gCWorld * pWorld = pProject->GetWorld( a_strWorld );
            if( 0 == pWorld )
                pWorld = pProject->InsertNewWorld( a_strWorld, GEFalse );
            if( pWorld )
                pProject->SetActiveWorld( pWorld->GetFileBaseName() );
            //NOTE: [NicoDE] World will be activated by the game (avoid +75% startup time).
        }
    }
    return GETrue;
}

struct aSEngineMessageInfo {
    GELPCChar m_pcName;
    GEInt     m_PreIndentation;
    GEInt     m_PostIndentation;
} const g_arrEngineMessageInfos[ eEEngineMessage_Count ] =
{
    { "WorldActivate",       0,  0 },
    { "WorldDeactivate:",    0, +1 },
    { ":WorldDeactivate",   -1,  0 },
    { "InsertSector",        0,  0 },
    { "RemoveSector:",       0, +1 },
    { ":RemoveSector",      -1,  0 },
    { ":SectorActivate",    -1,  0 },
    { "ProjectActivate",     0,  0 },
    { "ProjectDeactivate:",  0, +1 },
    { ":ProjectDeactivate", -1,  0 },
    { "Activate",            0,  0 },
    { "Deactivate:",         0, +1 },
    { ":Deactivate",        -1,  0 },
    { "Save:",               0, +1 },
    { ":Save",              -1,  0 },
    { "SectorDeactivate:",   0, +1 },
    { ":SectorDeactivate",  -1,  0 },
    { "SectorActivate:",     0, +1 },
    { "Initialize",          0,  0 },
    { "PostInitialize",      0,  0 },
    { "AppInitialized",      0,  0 },
    { "PreShutdown",         0,  0 },
    { "Shutdown",            0,  0 },
    { "AppStateChanged",    +1, -1 }
};

GEBool IsKnownEngineMessage( eEEngineMessage a_enumType )
{
    return static_cast< GEU32 >( a_enumType ) < eEEngineMessage_Count;
}

bCString GetProcessibleElementString( eCProcessibleElement * a_Element )
{
    return !a_Element ? "<null>" :
        bCString::GetFormattedString(
            "(%s) %s",
            a_Element->GetClassName(),
            a_Element->GetFileName() );
}

void aCProtoTypeApp::SendEngineMessage( eSEngineMessage & a_EngineMessage )
{
    if( g_FFIsValidFileHandle( this->m_hEngineMessageLogFile ) )
    {
        if( IsKnownEngineMessage( a_EngineMessage.m_enumType ) )
        {
            this->m_iEngineMessageIndentation +=
                g_arrEngineMessageInfos[ a_EngineMessage.m_enumType ].m_PreIndentation;
            if( this->m_iEngineMessageIndentation < 0 )
                this->m_iEngineMessageIndentation = 0;
        }
        bCString strEngineMessage = bCString( ' ', this->m_iEngineMessageIndentation ) +
            bCString::GetFormattedString(
                "[%s] ",
                IsKnownEngineMessage( a_EngineMessage.m_enumType ) ?
                    g_arrEngineMessageInfos[ a_EngineMessage.m_enumType ].m_pcName :
                    bCString::GetFormattedString(
                        "0x%08lX",
                        a_EngineMessage.m_enumType ) );
        switch( a_EngineMessage.m_enumType )
        {
        case eEEngineMessage_WorldActivate:
        case eEEngineMessage_WorldDeactivate:
        case eEEngineMessage_AfterWorldDeactivate:
        case eEEngineMessage_ProjectActivate:
        case eEEngineMessage_ProjectDeactivate:
        case eEEngineMessage_AfterProjectDeactivate:
        case eEEngineMessage_SectorDeactivate:
        case eEEngineMessage_AfterSectorDeactivate:
        case eEEngineMessage_SectorActivate:
        case eEEngineMessage_AfterSectorActivate:
        case eEEngineMessage_Activate:
        case eEEngineMessage_Deactivate:
        case eEEngineMessage_AfterDeactivate:
        case eEEngineMessage_Save:
        case eEEngineMessage_AfterSave:
            strEngineMessage += !a_EngineMessage.m_pElement ? "<null>" :
                GetProcessibleElementString( a_EngineMessage.m_pElement );
            break;
        case eEEngineMessage_InsertSector:
        case eEEngineMessage_RemoveSector:
        case eEEngineMessage_AfterRemoveSector:
            strEngineMessage += !a_EngineMessage.m_pWorldSector ? "<null>" :
                bCString::GetFormattedString(
                    "{ %s, %s }",
                    GetProcessibleElementString( a_EngineMessage.m_pWorldSector->m_pWorld ),
                    GetProcessibleElementString( a_EngineMessage.m_pWorldSector->m_pSector ) );
            break;
        case eEEngineMessage_AppStateChanged:
            strEngineMessage += bCString::GetFormattedString(
                "0x%04lX -> 0x%04lX",
                a_EngineMessage.m_AppStateChanged.m_enumOldAppState,
                a_EngineMessage.m_AppStateChanged.m_enumNewAppState );
            break;
        case eEEngineMessage_Initialize:
        case eEEngineMessage_PostInitialize:
        case eEEngineMessage_AppInitialized:
        case eEEngineMessage_PreShutdown:
        case eEEngineMessage_Shutdown:
        default:
        case eEEngineMessage_Count:
        case eEEngineMessage_ForceDWORD:
            strEngineMessage += !a_EngineMessage.m_pData ? "<null>" :
                bCString::GetFormattedString(
                    "0x%08lX",
                    a_EngineMessage.m_pData );
            break;
        }
        if( IsKnownEngineMessage( a_EngineMessage.m_enumType ) )
        {
            this->m_iEngineMessageIndentation +=
                g_arrEngineMessageInfos[ a_EngineMessage.m_enumType ].m_PostIndentation;
            if( this->m_iEngineMessageIndentation < 0 )
                this->m_iEngineMessageIndentation = 0;
        }
        strEngineMessage += "\n";
        FFU32 u32NumberOfBytesWritten;
        g_FFWriteFile( this->m_hEngineMessageLogFile, strEngineMessage.GetText(),
            static_cast< FFU32 >( strEngineMessage.GetLength() ), &u32NumberOfBytesWritten );
    }
    gCGameApp::SendEngineMessage( a_EngineMessage );
}

GEBool GE_STDCALL aCProtoTypeApp::g_MessageCallback( bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GEU32 a_u32Parameter, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority )
{
    aCProtoTypeApp * pProtoTypeApp = reinterpret_cast< aCProtoTypeApp * >( a_u32Parameter );
    if( pProtoTypeApp )
        return pProtoTypeApp->OnMessageCallback( a_enumType, a_pcMessage, a_pcReserved, a_pcFile, a_iLine, a_iPriority );
    return GEFalse;
}

GEBool aCProtoTypeApp::OnMessageCallback( bEMessageTypes a_enumType, GELPCChar a_pcMessage, GELPCChar a_pcReserved, GELPCChar a_pcFile, GEInt a_iLine, GEInt a_iPriority )
{
    if( g_FFIsValidFileHandle( this->m_hMessageCallbackLogFile ) )
    {
        bCString strMessage = bCString::GetFormattedString( "{%d,%d} ", a_enumType, a_iPriority );
        if( a_pcReserved )
            strMessage += bCString::GetFormattedString( "[%s] ", a_pcReserved );
        strMessage += a_pcMessage;
        if( a_pcFile )
            strMessage += bCString::GetFormattedString( " (%s,%d)", a_pcFile, a_iLine );
        strMessage += "\n";
        FFU32 u32NumberOfBytesWritten;
        return g_FFWriteFile( this->m_hMessageCallbackLogFile, strMessage.GetText(),
            static_cast< FFU32 >( strMessage.GetLength() ), &u32NumberOfBytesWritten );
    }   
    return GEFalse;
}
