#ifndef ENGINEENUM_H_INCLUDED
#define ENGINEENUM_H_INCLUDED

enum eEAudioChannelFallOff
{
    eEAudioChannelFallOff_Logarithmic = 0x00000000,
    eEAudioChannelFallOff_Linear      = 0x00000001,
    eEAudioChannelFallOff_ForceDWORD  = GE_FORCE_DWORD
};

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

enum eEDecayState
{
    eEDecayState_None       = 0x00000000,
    eEDecayState_Pending    = 0x00000001,
    eEDecayState_Decayed    = 0x00000002,
    eEDecayState_ForceDWORD = GE_FORCE_DWORD
};

enum eEPropertySetType
{
    eEPropertySetType_Unknown,
    eEPropertySetType_Base,
    eEPropertySetType_MeshVisual,
    eEPropertySetType_DummyVisual,
    eEPropertySetType_Advanced,
    eEPropertySetType_Navigation,
    eEPropertySetType_DynamicCollisionCircle,
    eEPropertySetType_CollisionCircle,
    eEPropertySetType_NavZone,
    eEPropertySetType_NegZone,
    eEPropertySetType_NavPath,
    eEPropertySetType_PrefPath,
    eEPropertySetType_NavHelper,
    eEPropertySetType_RigidBody,
    eEPropertySetType_CollisionShape,
    eEPropertySetType_DynamicLight,
    eEPropertySetType_DirectionalLight,
    eEPropertySetType_PointLight,
    eEPropertySetType_SpotLight,
    eEPropertySetType_Hemisphere,
    eEPropertySetType_MovementBase,
    eEPropertySetType_CharacterMovement,
    eEPropertySetType_CharacterControl,
    eEPropertySetType_CharacterSensor,
    eEPropertySetType_CameraAI,
    eEPropertySetType_Editor,
    eEPropertySetType_AIHelper,
    eEPropertySetType_AIHelperFreePoint,
    eEPropertySetType_AIHelperSpawnPoint,
    eEPropertySetType_AIHelperPlayerStart,
    eEPropertySetType_NPC,
    eEPropertySetType_Inventory,
    eEPropertySetType_Clock,
    eEPropertySetType_Skydome,
    eEPropertySetType_EditorVisual,
    eEPropertySetType_Occluder,
    eEPropertySetType_ScriptRoutine,
    eEPropertySetType_SpeedTree,
    eEPropertySetType_SpeedTreeWind,
    eEPropertySetType_Item,
    eEPropertySetType_Interaction,
    eEPropertySetType_Damage,
    eEPropertySetType_QuestManager,
    eEPropertySetType_Quest,
    eEPropertySetType_InfoManager,
    eEPropertySetType_Info,
    eEPropertySetType_InfoScript,
    eEPropertySetType_InfoScriptLine,
    eEPropertySetType_Focus,
    eEPropertySetType_NavOffset,
    eEPropertySetType_Arena,
    eEPropertySetType_Area,
    eEPropertySetType_Vegetation,
    eEPropertySetType_VegetationBrush,
    eEPropertySetType_VegetationRubber,
    eEPropertySetType_Dialog,
    eEPropertySetType_Lock,
    eEPropertySetType_Door,
    eEPropertySetType_StaticLight,
    eEPropertySetType_StaticPointLight,
    eEPropertySetType_StaticSpotLight,
    eEPropertySetType_Illuminated,
    eEPropertySetType_Statistics,
    eEPropertySetType_PhysicScene,
    eEPropertySetType_Party,
    eEPropertySetType_Anchor,
    eEPropertySetType_Letter,
    eEPropertySetType_Book,
    eEPropertySetType_Map,
    eEPropertySetType_LinkContainer,
    eEPropertySetType_Projectile,
    eEPropertySetType_Sound,
    eEPropertySetType_Strip,
    eEPropertySetType_Particle,
    eEPropertySetType_AIZone,
    eEPropertySetType_AudioEmitter,
    eEPropertySetType_Effect,
    eEPropertySetType_LightStreaks,
    eEPropertySetType_WeatherZone,
    eEPropertySetType_Precipitation,
    eEPropertySetType_StateGraph,
    eEPropertySetType_Mover,
    eEPropertySetType_Animation,
    eEPropertySetType_Magic,
    eEPropertySetType_Tutorial,
    eEPropertySetType_CastInfo,
    eEPropertySetType_Skills,
    eEPropertySetType_ArmorSet,
    eEPropertySetType_SectorPersistence,
    eEPropertySetType_Flock,
    eEPropertySetType_Recipe,
    eEPropertySetType_WaterZone,
    eEPropertySetType_Decal,
    eEPropertySetType_GenericEntityListener,
    eEPropertySetType_Billboard,
    eEPropertySetType_InfoSystem,
    eEPropertySetType_CombatSystem,
    eEPropertySetType_AreaStringProperty,
    eEPropertySetType_Room,
    eEPropertySetType_Portal,
    eEPropertySetType_GameScript,
    eEPropertySetType_BodyPart,
    eEPropertySetType_ParticleSystem,
    eEPropertySetType_MapInfo,
    eEPropertySetType_AudioOccluder,
    eEPropertySetType_SpeedTreeBBMesh,
    eEPropertySetType_Count,
    eEPropertySetType_ForceDWORD = GE_FORCE_DWORD
};

GE_DLLIMPORT_EXTC GELPCChar const g_ppszPropertySetTypes[ eEPropertySetType_Count ];

enum eERadiosityLightmapType
{
    //FIXME: eERadiosityLightmapType constants.
    eERadiosityLightmapType_ForceDWORD = GE_FORCE_DWORD
};

enum eEShaderMaterialBlendMode
{
    eEShaderMaterialBlendMode_Normal        = 0x00000000,
    eEShaderMaterialBlendMode_Masked        = 0x00000001,
    eEShaderMaterialBlendMode_AlphaBlend    = 0x00000002,
    eEShaderMaterialBlendMode_Modulate      = 0x00000003,
    eEShaderMaterialBlendMode_AlphaModulate = 0x00000004,
    eEShaderMaterialBlendMode_Translucent   = 0x00000005,
    eEShaderMaterialBlendMode_Darken        = 0x00000006,
    eEShaderMaterialBlendMode_Brighten      = 0x00000007,
    eEShaderMaterialBlendMode_Invisible     = 0x00000008,
    eEShaderMaterialBlendMode_ForceDWORD    = GE_FORCE_DWORD
};

enum eEShaderMaterialLightmapCombi
{
    //FIXME: eEShaderMaterialLightmapCombi constants.
    eEShaderMaterialLightmapCombi_ForceDWORD = GE_FORCE_DWORD
};

enum eEShaderMaterialOverwriteIndicator
{
    //FIXME: eEShaderMaterialOverwriteIndicator constants.
    eEShaderMaterialOverwriteIndicator_ForceDWORD = GE_FORCE_DWORD
};

enum eEShaderMaterialSpecialPassOption
{
    //FIXME: eEShaderMaterialSpecialPassOption constants.
    eEShaderMaterialSpecialPassOption_ForceDWORD = GE_FORCE_DWORD
};

enum eEShaderMaterialSpecialPassType
{
    //FIXME: eEShaderMaterialSpecialPassType constants.
    eEShaderMaterialSpecialPassType_ForceDWORD = GE_FORCE_DWORD
};

enum eEShaderMaterialVersion
{
    eEShaderMaterialVersion_1_1        = 0x00000000,
    eEShaderMaterialVersion_1_4        = 0x00000001,
    eEShaderMaterialVersion_2_0        = 0x00000002,
    eEShaderMaterialVersion_3_0        = 0x00000003,
    eEShaderMaterialVersion_ForceDWORD = GE_FORCE_DWORD
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

enum eETransformSpace
{
    eETransformSpace_ForceDWORD = GE_FORCE_DWORD
};

#endif
