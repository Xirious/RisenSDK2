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

enum eECollisionGroup
{
    eECollisionGroup_Static           = 0x00000001,
    eECollisionGroup_Dynamic          = 0x00000002,
    eECollisionGroup_Player           = 0x00000003,
    eECollisionGroup_NPC              = 0x00000004,
    eECollisionGroup_Item_Equipped    = 0x00000005,
    eECollisionGroup_Item_World       = 0x00000006,
    eECollisionGroup_Item_Attack      = 0x00000007,
    eECollisionGroup_Interactable     = 0x00000008,
    eECollisionGroup_Trigger          = 0x00000009,
    eECollisionGroup_Zone             = 0x0000000A,
    eECollisionGroup_Camera           = 0x0000000B,
    eECollisionGroup_Tree             = 0x0000000C,
    eECollisionGroup_DownCharacter    = 0x0000000D,
    eECollisionGroup_PlayerTrigger    = 0x0000000E,
    eECollisionGroup_ObjectTrigger    = 0x0000000F,
    eECollisionGroup_Ghost            = 0x00000010,
    eECollisionGroup_Mover            = 0x00000011,
    eECollisionGroup_RagDoll          = 0x00000012,
    eECollisionGroup_CharacterTrigger = 0x00000013,
    eECollisionGroup_ForceDWORD       = GE_FORCE_DWORD
};

enum eEShapeGroup
{
    eEShapeGroup_Static            = 0x00000001,
    eEShapeGroup_Dynamic           = 0x00000002,
    eEShapeGroup_Shield            = 0x00000003,
    eEShapeGroup_MeleeWeapon       = 0x00000004,
    eEShapeGroup_Projectile        = 0x00000005,
    eEShapeGroup_Movement          = 0x00000006,
    eEShapeGroup_WeaponTrigger     = 0x00000007,
    eEShapeGroup_ParadeSphere      = 0x00000008,
    eEShapeGroup_Tree_Trunk        = 0x00000009,
    eEShapeGroup_Tree_Branches     = 0x0000000A,
    eEShapeGroup_Camera            = 0x0000000B,
    eEShapeGroup_Movement_ZoneNPC  = 0x0000000C,
    eEShapeGroup_HeightRepulsor    = 0x0000000D,
    eEShapeGroup_Cloth             = 0x0000000E,
    eEShapeGroup_PhysicalBodyPart  = 0x0000000F,
    eEShapeGroup_KeyframedBodyPart = 0x00000010,
    eEShapeGroup_Camera_Obstacle   = 0x00000011,
    eEShapeGroup_Projectile_Level  = 0x00000012,
    eEShapeGroup_Trigger           = 0x00000013,
    eEShapeGroup_Door              = 0x00000014,
    eEShapeGroup_ForceDWORD        = GE_FORCE_DWORD
};

enum eEShapeMaterial
{
    eEShapeMaterial_None             = 0x00000000,
    eEShapeMaterial_Wood             = 0x00000001,
    eEShapeMaterial_Metal            = 0x00000002,
    eEShapeMaterial_Water            = 0x00000003,
    eEShapeMaterial_Stone            = 0x00000004,
    eEShapeMaterial_Earth            = 0x00000005,
    eEShapeMaterial_Ice              = 0x00000006,
    eEShapeMaterial_Leather          = 0x00000007,
    eEShapeMaterial_Clay             = 0x00000008,
    eEShapeMaterial_Glass            = 0x00000009,
    eEShapeMaterial_Flesh            = 0x0000000A,
    eEShapeMaterial_Snow             = 0x0000000B,
    eEShapeMaterial_Debris           = 0x0000000C,
    eEShapeMaterial_Foliage          = 0x0000000D,
    eEShapeMaterial_Magic            = 0x0000000E,
    eEShapeMaterial_Grass            = 0x0000000F,
    eEShapeMaterial_SpringAndDamper1 = 0x00000010,
    eEShapeMaterial_SpringAndDamper2 = 0x00000011,
    eEShapeMaterial_SpringAndDamper3 = 0x00000012,
    eEShapeMaterial_Damage           = 0x00000013,
    eEShapeMaterial_Sand             = 0x00000014,
    eEShapeMaterial_Movement         = 0x00000015,
    eEShapeMaterial_Axe              = 0x00000016,
    eEShapeMaterial_ForceDWORD       = GE_FORCE_DWORD
};

#include "Engine/ge_virtualfilesystem.h"

#include "Engine/ge_archivefile.h"
#include "Engine/ge_archivemanager.h"

#include "Engine/ge_docobject.h"
#include "Engine/ge_docarchive.h"

#include "Engine/ge_animshared.h"

#include "Engine/ge_node.h"

#endif
