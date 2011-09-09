#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "FFC.h"

namespace EMotionFX
{
    class ActorInstance{};
    class Motion{};
    class MotionInstance{};
    class SkeletalSubMotion{};
}
class NxActor{};

#include "Engine/EngineEnum.h"

#include "Engine/ge_locadmin2.h"
#include "Engine/ge_locstring.h"

#include "Engine/ge_virtualfilesystem.h"

#include "Engine/ge_archivefile.h"
#include "Engine/ge_archivemanager.h"

#include "Engine/ge_processibleelement.h"

#include "Engine/ge_docobject.h"
#include "Engine/ge_docobjectmap.h"
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

class GE_DLLIMPORT eCDeferredGuiBitmap2{};
class GE_DLLIMPORT eCGuiBitmapProxy2
{
    eCDeferredGuiBitmap2 * m_pBitmap;
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

class GE_DLLIMPORT eCGuiWindow2{};
class GE_DLLIMPORT eCGuiFrame2{};

class eCStatisticView;
#include "Engine/ge_statistic.h"
#include "Engine/ge_statisticview.h"

#include "Engine/ge_enginecomponentbase.h"
#include "Engine/ge_moduleadmin.h"

#include "Engine/ge_resourceinputstream2.h"
#include "Engine/ge_resourceoutputstream2.h"
class GE_DLLIMPORT eCCollisionMeshResource2{};
class GE_DLLIMPORT eCImageResource2{};
class GE_DLLIMPORT eCMaterialResource2{};
class GE_DLLIMPORT eCMeshResource2{};
class GE_DLLIMPORT eCMotionActorResource2{};
class GE_DLLIMPORT eCMotionResource2{};
class GE_DLLIMPORT eCSoundResource2{};
class GE_DLLIMPORT eCSpeedTreeResource2{};
class eCResourceCache2;
#include "Engine/ge_resource2.h"
#include "Engine/ge_resourcecache2.h"
#include "Engine/ge_resourcemodule2.h"

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

#include "Engine/ge_scriptadminbase.h"
#include "Engine/ge_scriptfunctionmap.h"
#include "Engine/ge_scriptproxy.h"
#include "Engine/ge_scriptproxyscript.h"

#include "Engine/ge_splash.h"
class eCConsoleEdit2{};
class eCConsoleListCtrl2{};
class eCPropertyEditFrame2{};
#include "Engine/ge_console2.h"

#include "Engine/ge_configadmin.h"
#include "Engine/ge_debugoptions.h"

#include "Engine/ge_configfile.h"
#include "Engine/ge_application.h"
class GE_DLLIMPORT eCEntityDynamicContext{};

#include "Engine/ge_inputadmin.h"

class GE_DLLIMPORT eCBodyPart_PS{};

#include "Engine/ge_actorwrapper.h"
class eCAnimation_PS;
#include "Engine/ge_actorattachment.h"
#include "Engine/ge_animation_ps.h"

class eCMover_PS;
#include "Engine/ge_moveranimationbase.h"
#include "Engine/ge_moveranimationfile.h"
//TODO: Analyze bTInterpolator templates.
// eCMoverAnimationKFBase: eCMoverAnimationBase
// eCMoverAnimationBezier: eCMoverAnimationKFBase
// eCMoverAnimationHermit: eCMoverAnimationKFBase
// eCMoverAnimationLinear: eCMoverAnimationKFBase
#include "Engine/ge_moveranimationrotate.h"
#include "Engine/ge_moveranimationskeletal.h"
// eCMoverAnimationTCB: eCMoverAnimationKFBase
#include "Engine/ge_mover_ps.h"

class eCPrimitiveWeatherZoneBox{};
#include "Engine/ge_area_stringproperty_ps.h"

#endif
