#ifndef SCRIPT_H_INCLUDED
#define SCRIPT_H_INCLUDED

#include "Game.h"

#include "Script/gs_propertymacros.h"

class Entity;
#include "Script/gs_template.h"
#include "Script/gs_entity.h"
#include "Script/gs_achievement.h"
#include "Script/gs_effect.h"
#include "Script/gs_effectsystem.h"
#include "Script/gs_focus.h"
#include "Script/gs_gui2.h"
#include "Script/gs_infcom.h"
#include "Script/gs_infcomattack.h"
#include "Script/gs_infcomheal.h"
#include "Script/gs_infcominfowait.h"
#include "Script/gs_infcompickpocket.h"
#include "Script/gs_infcomrunaiscript.h"
#include "Script/gs_infcomsay.h"
#include "Script/gs_infcomsayconfirm.h"
#include "Script/gs_infcomsayholdingposition.h"
#include "Script/gs_infcomsaykeepitup.h"
#include "Script/gs_infcomsaysvm.h"
#include "Script/gs_infcomsaysound.h"
#include "Script/gs_infcomsetsectorstatus.h"
#include "Script/gs_infcomsleep.h"
#include "Script/gs_infcomthink.h"
#include "Script/gs_infcomuse.h"
#include "Script/gs_infosystem.h"
#include "Script/gs_input.h"
#include "Script/gs_music.h"
#include "Script/gs_psaizone.h"
#include "Script/gs_psanchor.h"
#include "Script/gs_psanimation.h"
#include "Script/gs_psarea.h"
#include "Script/gs_psarena.h"
#include "Script/gs_psbook.h"
#include "Script/gs_pscastinfo.h"
#include "Script/gs_pscharactermovement.h"
#include "Script/gs_psclock.h"
#include "Script/gs_pscollisionshape.h"
#include "Script/gs_pscombatsystem.h"
#include "Script/gs_psdamage.h"
#include "Script/gs_psdialog.h"
#include "Script/gs_psdoor.h"
#include "Script/gs_pseffect.h"
#include "Script/gs_psinteraction.h"
#include "Script/gs_psinventory.h"
#include "Script/gs_psitem.h"
#include "Script/gs_psletter.h"
#include "Script/gs_pslock.h"
#include "Script/gs_psmap.h"
#include "Script/gs_psmover.h"
// PSNavigation, gCNavigation_PS
#include "Script/gs_psnpc.h"
// PSParticle, eCParticle_PS
// PSParty, gCParty_PS
// PSProjectile, gCProjectile2_PS
// PSRecipe, gCRecipe_PS
// PSRigidBody, eCRigidBody_PS
#include "Script/gs_psroutine.h"
#include "Script/gs_psskills.h"
// PSStateGraph, gCStateGraph_PS
// PSStrip, eCStrip_PS
#include "Script/gs_questmanager.h"
#include "Script/gs_scriptactiontimer.h"
#include "Script/gs_scriptcommentmanager.h"
#include "Script/gs_scriptdestinationcollector.h"
#include "Script/gs_tutorial.h"
#include "Script/gs_world.h"

#endif
