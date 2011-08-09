#ifndef HACKS_H_INCLUDED
#define HACKS_H_INCLUDED

#include "Script.h"

class GE_DLLIMPORT eCMesh_PS : public eCEntityPropertySet
{
public:
    bCString GetMeshFileName( void ) const;
};

class GE_DLLIMPORT eCSceneAdmin : public eCEngineComponentBase
{
    public:
        GEInt  GetNumEntitiesByName( const bCString & ) const;
        GEBool UnregisterNameInfo( eCDynamicEntity & );
};

#endif  // HACKS_H_INCLUDED