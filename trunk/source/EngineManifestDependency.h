
//
// Include this header (once) in your applications that use the Engine.dll
//

#define __RISEN_OPENMP_ASSEMBLY_VERSION "8.0.50727.762"

#if !defined(_OPENMP) || defined(_DEBUG)
    #pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='" __RISEN_OPENMP_ASSEMBLY_VERSION "' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#elif (_MSC_FULL_VER != 140050727) || defined(_USE_RTM_VERSION) || !defined(_MSC_BUILD) || (_MSC_BUILD != 762)
    #if !defined(__OPENMP_ASSEMBLY_VERSION)
        #include <crtassem.h>
        #define __OPENMP_ASSEMBLY_VERSION _CRT_ASSEMBLY_VERSION
    #endif
    #pragma message( "warning: Please verify that your OpenMP version (" __OPENMP_ASSEMBLY_VERSION ") matches Risen's Engine.dll (" __RISEN_OPENMP_ASSEMBLY_VERSION ")" )
#endif

