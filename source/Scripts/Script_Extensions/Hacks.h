#ifndef HACKS_H_INCLUDED
#define HACKS_H_INCLUDED

#include "Script.h"

class GE_DLLIMPORT eCMesh_PS : public eCEntityPropertySet
{
public:
    bCString GetMeshFileName( void ) const;
};

class GE_DLLIMPORT gCLayerBase : public eCProcessibleElement
{
    public:
        void Enable( GEBool );
};

enum gEEntityType
{
    gEEntityType_Game       = 0x00000000,
    gEEntityType_Temporary  = 0x00000001,
    gEEntityType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT gCDynamicLayer : public gCLayerBase
{
public:
    eCDynamicEntity * CreateDynamicEntity( void );
    bTPropertyContainer< gEEntityType > const & GetEntityType( void ) const;
};

class GE_DLLIMPORT gCSector : public eCProcessibleElement
{
public:
    GEInt                                     GetDynamicLayerIndex( bCString const & ) const;
    const bTRefPtrArray< gCDynamicLayer * > & GetEntityLayers( void ) const;
    gCDynamicLayer *                          InsertNewDynamicLayer( bCString const &, gEEntityType );
    void                                      Reload( void );
    eEResult                                  RemoveDynamicLayer( gCDynamicLayer * );
};

class GE_DLLIMPORT gCWorld : public eCProcessibleElement
{
public:
    static gCSector * GetSectorForEntity( const eCEntity * );
    static gCWorld *  GetCurrentWorld( void );
public:
    eCEntity *                     CreateChildEntityFromTemplate( eCEntity *, eCTemplateEntity * );
    GEBool                         DestroyDynamicEntity( eCDynamicEntity * );
    gCSector *                     GetSector( bCString const & );
    const gCSector *               GetSectorAt( GEInt ) const;
    GEInt                          GetSectorCount( void ) const;
    gCSector *                     InsertNewSector( bCString const &, bCString const & );
    eCProcessibleElement::eEResult RemoveSector( gCSector * );
};

class GE_DLLIMPORT eCSceneAdmin : public eCEngineComponentBase
{
    public:
        GEInt  GetNumEntitiesByName( const bCString & ) const;
        GEBool UnregisterNameInfo( eCDynamicEntity & );
};

#endif  // HACKS_H_INCLUDED