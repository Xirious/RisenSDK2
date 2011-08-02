#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "FFC.h"

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

#pragma warning( push )
#pragma warning( disable : 4505 )  // unreferenced local function has been removed

#include "Engine/EngineEnum.h"

#include "Engine/ge_locstring.h"

#include "Engine/ge_virtualfilesystem.h"

#include "Engine/ge_archivefile.h"
#include "Engine/ge_archivemanager.h"

#include "Engine/ge_processibleelement.h"

#include "Engine/ge_docobject.h"
#include "Engine/ge_docarchive.h"

class eCVideoPlayer{
protected:
    char __FIXME[ 0x0030 ];
};
#include "Engine/ge_gfxshared.h"
#include "Engine/ge_apitexture.h"
#include "Engine/ge_gfxobject.h"
#include "Engine/ge_gfximagedata.h"

#include "Engine/ge_animshared.h"

/*

//HACK: bTRefPtrArray is like bTPtrArray but uses Add/ReleaseReference of the elements.
#define bTRefPtrArray bTPtrArray
//HACK: Get Entity classes it compiling...

*/
template< typename T >
class bTRefPtrArray : public bTPtrArray< T >
{
};

struct eSGizmoPickInfo{};
struct eSRayIntersectionDesc{};
class GE_DLLIMPORT eCCollisionDesc{};
class GE_DLLIMPORT eCContactIterator{};
class GE_DLLIMPORT eCContextBase{};
class GE_DLLIMPORT eCGfxCamera{};
class GE_DLLIMPORT eCFrustumDatabase{
public:
    struct eSRenderTargetDesc{};
protected:
    char __FIXME[ 0x0B1C ];
};
class GE_DLLIMPORT eCIlluminated_PS{};
class GE_DLLIMPORT eCLightSet{};
class GE_DLLIMPORT eCRenderContext{};
class GE_DLLIMPORT eCShadowMapBase{};
class GE_DLLIMPORT eCPhysicObject{};
class GE_DLLIMPORT eCPortalRoom_PS;
class eCEntity;
class eCGeometryEntity;
#include "Engine/ge_camerabase.h"

#include "Engine/ge_node.h"
#include "Engine/ge_entityproxy.h"
#include "Engine/ge_entitystringproxy.h"
#include "Engine/ge_templateentityproxy.h"
#include "Engine/ge_entitypropertyset.h"
#include "Engine/ge_entity.h"
#include "Engine/ge_templateentity.h"
#include "Engine/ge_frustumelementitem.h"
#include "Engine/ge_geometryentity.h"
#include "Engine/ge_processible.h"
#include "Engine/ge_processor.h"
#include "Engine/ge_dynamicentity.h"

class GE_DLLIMPORT eCSpeedTreeResource2{};

#include "Engine/ge_collisionshape.h"
#include "Engine/ge_collisionshapebase_ps.h"
#include "Engine/ge_collisionshape_ps.h"

#include "Engine/ge_portalbsp.h"
#include "Engine/ge_portal.h"
#include "Engine/ge_portalcell_ps.h"
#include "Engine/ge_portalroom_ps.h"

#include "Engine/ge_messagehandler.h"
#include "Engine/ge_window.h"

#include "Engine/ge_guiresource2.h"

class GE_DLLIMPORT eCGuiWindow2{};
class GE_DLLIMPORT eCGuiFrame2{};
#include "Engine/ge_statistic.h"
#include "Engine/ge_statisticview.h"

#include "Engine/ge_enginecomponentbase.h"
#include "Engine/ge_moduleadmin.h"

#include "Engine/ge_scriptadminbase.h"
#include "Engine/ge_scriptfunctionmap.h"
#include "Engine/ge_scriptproxy.h"
#include "Engine/ge_scriptproxyscript.h"

#include "Engine/ge_splash.h"
class eCConsoleEdit2{};
class eCConsoleListCtrl2{};
class eCPropertyEditFrame2{};
#include "Engine/ge_console2.h"

#pragma warning( pop )

#endif
