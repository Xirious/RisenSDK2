#include "TestApp.h"

#ifdef _OPENMP
#ifdef _OPENMP_NOFORCE_MANIFEST
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#else
#error Please verify that the OpenMP version matches Risen’s Engine.dll
#endif
#else
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#endif

static int __stdcall ProtoTypeMain( HINSTANCE a_hInstance, bCString const & a_strCmdLine, bCCommandLine const & a_CommandLine )
{
    aCProtoTypeApp ProtoTypeApp;

    iCSceneCompiler    SceneCompiler;
    iCResourceCompiler ResourceCompiler;
    iCDemoCompiler     DemoCompiler;

    GEBool bSkipMain =
        a_CommandLine.GetOptions().IsValidKey( "skipmain" ) ||
        a_CommandLine.GetOptions().IsValidKey( "compileoptions" ) ||
        a_CommandLine.GetOptions().IsValidKey( "compilelibrary" ) ||
        a_CommandLine.GetOptions().IsValidKey( "compilematerials" ) ||
        a_CommandLine.GetOptions().IsValidKey( "compilenavigation" ) ||
        a_CommandLine.GetOptions().IsValidKey( "importanis" ) ||
        a_CommandLine.GetOptions().IsValidKey( "importimages" ) ||
        a_CommandLine.GetOptions().IsValidKey( "importsounds" ) ||
        a_CommandLine.GetOptions().IsValidKey( "builddemo" );
    if( bSkipMain )
    {
        bCMessageAdmin::GetInstance().EnableSilentLogMode();
    }
    else
    {
        eCApplication::CreateSplashScreen();
    }

    bCString strConfig( "Config" );
    if( GETrue == a_CommandLine.GetOptions().IsValidKey( "config" ) )
    {
        strConfig = a_CommandLine.GetOptions().GetAt( "config" );
    }

    bEResult enumResult = ProtoTypeApp.Create( a_hInstance, strConfig, a_strCmdLine );

    bCGCMem::GetInstance().GetTotalBytesAllocated();

    if( bEResult_Ok == enumResult )
    {
        //TODO: Write physical #G3:/save to HKEY_CURRENT_USER\Software\Deep Silver\Risen\SAVEGAME_DIR

        SceneCompiler.ParseCommandLine( a_CommandLine );
        ResourceCompiler.ParseCommandLine( a_CommandLine );
        DemoCompiler.ParseCommandLine( a_CommandLine );

        if( GEFalse == bSkipMain )
        {
            bCString strProject( "Projects" );
            bCString strWorld( "G3_Startup" );
            if( GETrue == a_CommandLine.GetOptions().IsValidKey( "projectfile" ) )
            {
                strProject = a_CommandLine.GetOptions().GetAt( "projectfile" );
            }
            /** /// Not present in the Risen - don’t ask me why.
            if( GETrue == a_CommandLine.GetOptions().IsValidKey( "worldfile" ) )
            {
                strWorld = a_CommandLine.GetOptions().GetAt( "worldfile" );
            }
            /**/
            ProtoTypeApp.LoadProjectFile( strProject, strWorld );
            
            gCSession::GetInstance().GotoStartPosition();

            ProtoTypeApp.SetVisible( GETrue );

            ProtoTypeApp.ConfineCursor();

            ProtoTypeApp.PlayIntros();
            
            g_GetModule< gCSession >()->StartGame();

            ProtoTypeApp.Run();
        }
        ClipCursor( 0 );
        ProtoTypeApp.Destroy();
        ClipCursor( 0 );
        return 0;
    }
    return -1;
}

LONG WINAPI aFUnhandledExceptionFilter( struct _EXCEPTION_POINTERS * )
{
    return EXCEPTION_EXECUTE_HANDLER;
};

#pragma warning( push )
#pragma warning( disable : 4509 )  // nonstandard extension used: uses SEH and has destructor

#include <commctrl.h>
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df'\"" )

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int )
{
    INITCOMMONCONTROLSEX IccEx;
    IccEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
    IccEx.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx( &IccEx );

    bCString strCmdLine( lpCmdLine );
    strCmdLine.ToLower();
    if( GETrue == strCmdLine.IsEmpty() )
    {
        strCmdLine = "-mnt=mountlist_packed.ini -projectfile=Projects -worldfile=World";
    }
    bCCommandLine CommandLine;
    CommandLine.Create( strCmdLine );
    if( CommandLine.GetOptions().IsValidKey( "disablecrashdumps" ) )
    {
        ProtoTypeMain( hInstance, strCmdLine, CommandLine );
    }
    else
    {
        SetUnhandledExceptionFilter( aFUnhandledExceptionFilter );
        __try
        {
            ProtoTypeMain( hInstance, strCmdLine, CommandLine );
        }
        __except( bCErrorAdmin::GetInstance().HandleCrash( GetExceptionCode(), GetExceptionInformation() ) )
        {
        }
    }
    return 0;
}

#pragma warning( pop )
