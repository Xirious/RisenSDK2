#ifndef SCRIPT_EXTENSIONS_M_HACKS_H_INCLUDED
#define SCRIPT_EXTENSIONS_M_HACKS_H_INCLUDED

#include "Script.h"

namespace eCGfxShared
{
    enum eEMasterCmpFunc{};
    enum eEMasterWrite{};
}

class GE_DLLIMPORT eCDecalAdmin :
    public eCEngineComponentBase
{
public:
    GEBool RenderDecals( eCFrustumDatabase * );
};

class GE_DLLIMPORT eCGfxMixerAdmin :
    public bCObjectRefBase
{
public:
    static eCGfxMixerAdmin * GE_STDCALL GetInstance( void );
public:
    bEResult DrawBox( bCBox const &, GEU32, bCMatrix const &, GEBool, GEBool, GEBool );
    bEResult DrawLine( bCVector const &, bCVector const &, GEU32, GEBool, GEBool ) const;
    bEResult DrawLineList( bTValArray< bCVector > const &, GEU32, GEBool, GEBool ) const;
	bEResult EndScene( void ) const;
    bEResult GetMasterDepthTesting( eCGfxShared::eEMasterCmpFunc & ) const;
    bEResult GetMasterDepthWrite( eCGfxShared::eEMasterWrite & ) const;
    bEResult SetMasterDepthTesting( eCGfxShared::eEMasterCmpFunc ) const;
    bEResult SetMasterDepthWrite( eCGfxShared::eEMasterWrite ) const;
};

class GE_DLLIMPORT eCMesh_PS :
    public eCEntityPropertySet
{
public:
    bCString GetMeshFileName( void ) const;
};

#pragma once

class GE_DLLIMPORT eCPhysicQueryReport
{
public:
    GEBool   m_bValid;
    char     __FIXME[ 0x68 - 0x01 ];
    bCVector m_vecVector;
};

class GE_DLLIMPORT eCPhysicsScene :
    public eCEngineComponentBase
{
public:
    static eCPhysicsScene & GE_STDCALL GetInstance( void );
public:
    eCPhysicQueryReport & GetQueryReport( void );
    GEBool                TraceRayNearestHit( bCVector const &, bCVector const &, eCGeometryEntity const *, GEU32, eCGeometryEntity const *, eEPropertySetType, eEShapeGroup );
};

class GE_DLLIMPORT eCSceneAdmin :
    public eCEngineComponentBase
{
public:
    eCEntityAdmin & GetAccessToEntityAdmin( void );
    GEInt           GetNumEntitiesByName( const bCString & ) const;
    void            GetTemplateEntities( bTPtrArray< eCTemplateEntity * > &, GEBool, GEBool, GEBool, GEBool, GEBool );
    GEBool          UnregisterNameInfo( eCDynamicEntity & );
};

class GE_DLLIMPORT gCCameraAdmin :
    public eCEngineComponentBase
{
public:
    GEInt  OnAction( gSAction const & );
    GEBool IsExternalCamera( void );
};

class CConfigAdminAccessor :
    public eCConfigAdmin
{
public:
    static GEBool GetLayerValueString( eECfgLayer a_enuLayer, bCString const & a_strKey, bCString & a_strDest, bCString const & a_strDefault ) { return GetInstance().GetValueString( eCConfigAdmin::s_strCfgLayer[ a_enuLayer ] + a_strKey, a_strDest, a_strDefault ); }
    static GEBool SetLayerValueString( eECfgLayer a_enuLayer, bCString const & a_strKey, bCString const & a_strValue ) { return GetInstance().SetValueString( eCConfigAdmin::s_strCfgLayer[ a_enuLayer ] + a_strKey, a_strValue ); }
private:
    static CConfigAdminAccessor & GetInstance( void ) { return *static_cast< CConfigAdminAccessor * >( static_cast< GELPVoid >( &eCConfigAdmin::GetInstance() ) ); }
};

#endif