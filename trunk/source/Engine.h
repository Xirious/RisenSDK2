#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "FileSystem2.h"
#include "GUI2.h"

/** /
#ifdef _OPENMP
#ifdef _OPENMP_NOFORCE_MANIFEST
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#else
#error Please verify that the OpenMP version matches Risen’s Engine.dll
#endif
#else
#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.VC80.OpenMP' version='8.0.50727.762' processorArchitecture='x86' publicKeyToken='1fc8b3b9a1e18e3b'\"" )
#endif
/**/

#include "Engine/ge_virtualfilesystem.h"

#include "Engine/ge_archivefile.h"
#include "Engine/ge_archivemanager.h"

#include "Engine/ge_docobject.h"
#include "Engine/ge_docarchive.h"

#endif
