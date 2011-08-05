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

#include <commctrl.h>
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df'\"" )

void ProtoTypeMain( void )
{
}

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
    INITCOMMONCONTROLSEX IccEx;
    IccEx.dwSize = sizeof(INITCOMMONCONTROLSEX);
    IccEx.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx( &IccEx );

    ProtoTypeMain();

    return 0;
}

