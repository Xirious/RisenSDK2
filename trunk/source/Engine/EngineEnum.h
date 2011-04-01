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
    eEPropertySetType_Unknown                = 0x00000000,
    eEPropertySetType_Base                   = 0x00000001,
    eEPropertySetType_MeshVisual             = 0x00000002,
    eEPropertySetType_DummyVisual            = 0x00000003,
    eEPropertySetType_Advanced               = 0x00000004,
    eEPropertySetType_Navigation             = 0x00000005,
    eEPropertySetType_DynamicCollisionCircle = 0x00000006,
    eEPropertySetType_CollisionCircle        = 0x00000007,
    eEPropertySetType_NavZone                = 0x00000008,
    eEPropertySetType_NegZone                = 0x00000009,
    eEPropertySetType_NavPath                = 0x0000000A,
    eEPropertySetType_PrefPath               = 0x0000000B,
    eEPropertySetType_NavHelper              = 0x0000000C,
    eEPropertySetType_RigidBody              = 0x0000000D,
    eEPropertySetType_CollisionShape         = 0x0000000E,
    eEPropertySetType_DynamicLight           = 0x0000000F,
    eEPropertySetType_DirectionalLight       = 0x00000010,
    eEPropertySetType_PointLight             = 0x00000011,
    eEPropertySetType_SpotLight              = 0x00000012,
    eEPropertySetType_Hemisphere             = 0x00000013,
    eEPropertySetType_MovementBase           = 0x00000014,
    eEPropertySetType_CharacterMovement      = 0x00000015,
    eEPropertySetType_CharacterControl       = 0x00000016,
    eEPropertySetType_CharacterSensor        = 0x00000017,
    eEPropertySetType_CameraAI               = 0x00000018,
    eEPropertySetType_Editor                 = 0x00000019,
    eEPropertySetType_AIHelper               = 0x0000001A,
    eEPropertySetType_AIHelperFreePoint      = 0x0000001B,
    eEPropertySetType_AIHelperSpawnPoint     = 0x0000001C,
    eEPropertySetType_AIHelperPlayerStart    = 0x0000001D,
    eEPropertySetType_NPC                    = 0x0000001E,
    eEPropertySetType_Inventory              = 0x0000001F,
    eEPropertySetType_Clock                  = 0x00000020,
    eEPropertySetType_Skydome                = 0x00000021,
    eEPropertySetType_EditorVisual           = 0x00000022,
    eEPropertySetType_Occluder               = 0x00000023,
    eEPropertySetType_ScriptRoutine          = 0x00000024,
    eEPropertySetType_SpeedTree              = 0x00000025,
    eEPropertySetType_SpeedTreeWind          = 0x00000026,
    eEPropertySetType_Item                   = 0x00000027,
    eEPropertySetType_Interaction            = 0x00000028,
    eEPropertySetType_Damage                 = 0x00000029,
    eEPropertySetType_QuestManager           = 0x0000002A,
    eEPropertySetType_Quest                  = 0x0000002B,
    eEPropertySetType_InfoManager            = 0x0000002C,
    eEPropertySetType_Info                   = 0x0000002D,
    eEPropertySetType_InfoScript             = 0x0000002E,
    eEPropertySetType_InfoScriptLine         = 0x0000002F,
    eEPropertySetType_Focus                  = 0x00000030,
    eEPropertySetType_NavOffset              = 0x00000031,
    eEPropertySetType_Arena                  = 0x00000032,
    eEPropertySetType_Area                   = 0x00000033,
    eEPropertySetType_Vegetation             = 0x00000034,
    eEPropertySetType_VegetationBrush        = 0x00000035,
    eEPropertySetType_VegetationRubber       = 0x00000036,
    eEPropertySetType_Dialog                 = 0x00000037,
    eEPropertySetType_Lock                   = 0x00000038,
    eEPropertySetType_Door                   = 0x00000039,
    eEPropertySetType_StaticLight            = 0x0000003A,
    eEPropertySetType_StaticPointLight       = 0x0000003B,
    eEPropertySetType_StaticSpotLight        = 0x0000003C,
    eEPropertySetType_Illuminated            = 0x0000003D,
    eEPropertySetType_Statistics             = 0x0000003E,
    eEPropertySetType_PhysicScene            = 0x0000003F,
    eEPropertySetType_Party                  = 0x00000040,
    eEPropertySetType_Anchor                 = 0x00000041,
    eEPropertySetType_Letter                 = 0x00000042,
    eEPropertySetType_Book                   = 0x00000043,
    eEPropertySetType_Map                    = 0x00000044,
    eEPropertySetType_LinkContainer          = 0x00000045,
    eEPropertySetType_Projectile             = 0x00000046,
    eEPropertySetType_Sound                  = 0x00000047,
    eEPropertySetType_Strip                  = 0x00000048,
    eEPropertySetType_Particle               = 0x00000049,
    eEPropertySetType_AIZone                 = 0x0000004A,
    eEPropertySetType_AudioEmitter           = 0x0000004B,
    eEPropertySetType_Effect                 = 0x0000004C,
    eEPropertySetType_LightStreaks           = 0x0000004D,
    eEPropertySetType_WeatherZone            = 0x0000004E,
    eEPropertySetType_Precipitation          = 0x0000004F,
    eEPropertySetType_StateGraph             = 0x00000050,
    eEPropertySetType_Mover                  = 0x00000051,
    eEPropertySetType_Animation              = 0x00000052,
    eEPropertySetType_Magic                  = 0x00000053,
    eEPropertySetType_Tutorial               = 0x00000054,
    eEPropertySetType_CastInfo               = 0x00000055,
    eEPropertySetType_Skills                 = 0x00000056,
    eEPropertySetType_ArmorSet               = 0x00000057,
    eEPropertySetType_SectorPersistence      = 0x00000058,
    eEPropertySetType_Flock                  = 0x00000059,
    eEPropertySetType_Recipe                 = 0x0000005A,
    eEPropertySetType_WaterZone              = 0x0000005B,
    eEPropertySetType_Decal                  = 0x0000005C,
    eEPropertySetType_GenericEntityListener  = 0x0000005D,
    eEPropertySetType_Billboard              = 0x0000005E,
    eEPropertySetType_InfoSystem             = 0x0000005F,
    eEPropertySetType_CombatSystem           = 0x00000060,
    eEPropertySetType_AreaStringProperty     = 0x00000061,
    eEPropertySetType_Room                   = 0x00000062,
    eEPropertySetType_Portal                 = 0x00000063,
    eEPropertySetType_GameScript             = 0x00000064,
    eEPropertySetType_BodyPart               = 0x00000065,
    eEPropertySetType_ParticleSystem         = 0x00000066,
    eEPropertySetType_MapInfo                = 0x00000067,
    eEPropertySetType_AudioOccluder          = 0x00000068,
    eEPropertySetType_SpeedTreeBBMesh        = 0x00000069,
    eEPropertySetType_ForceDWORD             = GE_FORCE_DWORD
};

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

#endif
