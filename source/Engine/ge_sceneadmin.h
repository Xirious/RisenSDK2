#ifndef GE_SCENEADMIN_H_INCLUDED
#define GE_SCENEADMIN_H_INCLUDED

class GE_DLLIMPORT eCPrefetchAdmin;
class GE_DLLIMPORT eCEntityNameInfo;
class GE_DLLIMPORT eCTemplateEntity;

enum eEEntityType
{
	//FIXME: eEEntityType constants.
	eEEntityType_ForceDWORD = GE_FORCE_DWORD
};

class GE_DLLIMPORT eCSceneAdmin : eCEngineComponentBase
{
GE_DECLARE_PROPERTY_OBJECT(eCSceneAdmin, eCEngineComponentBase)
public: virtual GEU16 GetVersion() const;
public: virtual bEResult Create();
public: virtual void Destroy();
public: virtual ~eCSceneAdmin();
public: virtual bEResult Initialize();
public: virtual bEResult Shutdown();
public: virtual void ApplyConfiguration();
public: virtual eCStatistic * CreateStatistics() const;
protected: static GEInt S_CompareEntityNames(void const *, void const *);
public:
	GEBool                                                 AddDeletedTemplate(eCTemplateEntity *, GEBool);
	GEBool                                                 CheckIfEntityNameExists(bCString const &) const;
	void                                                   ClearRegisteredEntities();
	GEBool                                                 ClearTemplateEntities();
	eCEntityAdmin &                                        GetAccessToEntityAdmin();
	bCString                                               GetDeletedTemplateListFile() const;
	eCEntityDynamicContext *                               GetDynamicEntityContext(GEInt) const;
	GEInt                                                  GetDynamicEntityContextCount() const;
	GEBool                                                 GetEntitiesByName(bCString const &, bTPtrArray< eCEntity * > &);
	GEBool                                                 GetEntitiesByName(bCString const &, bTPtrArray< eCEntity * > &) const;
	GEBool                                                 GetEntitiesByPartName(bCString const &, bTPtrArray< eCEntity * > &, eEEntityType);
	eCNode *                                               GetEntity(bCPropertyID const &, eEEntityType);
	eCNode const *                                         GetEntity(bCPropertyID const &, eEEntityType) const;
	eCEntity *                                             GetEntityByName(bCString const &);
	eCEntity const *                                       GetEntityByName(bCString const &) const;
	eCEntity *                                             GetEntityByPartName(bCString const &, eEEntityType, GEInt);
	GEInt                                                  GetEntityCountByPartName(bCString const &, eEEntityType);
	GEInt                                                  GetNumEntitiesByName(bCString const &) const;
	GEU32                                                  GetNumberOfDynamicEntities() const;
	GEU32                                                  GetNumberOfStaticEntities() const;
	eCPrefetchAdmin &                                      GetPrefetchAdmin();
	void                                                   GetRootTemplateEntities(bTPtrArray< eCTemplateEntity * > &);
	void                                                   GetTemplateEntities(bTPtrArray< eCTemplateEntity * > &, GEBool, GEBool, GEBool, GEBool, GEBool);
	GEInt                                                  GetTemplateEntitiesByName(bCString const &, bTPtrArray< eCTemplateEntity * > &);
	eCTemplateEntity *                                     GetTemplateEntityByName(bCString const &, GEBool, GEBool, GEBool);
	GEBool                                                 GetUniqueEntityByName(bCString const &, eCEntity * &) const;
	bCBox const &                                          GetWorldBox() const;
	GEBool                                                 IsDeletedTemplate(bCPropertyID const &);
	GEBool                                                 LoadDeletedTemplateList();
	eCEntityNameInfo *                                     RegisterNameInfo(eCEntity const &, bCString const &);
	GEBool                                                 RemoveDeletedTemplate(eCTemplateEntity *);
	GEBool                                                 SaveDeletedTemplateList();
	bTValMap< bCPropertyID, eSEntityID >::bCConstIterator TemplateEntitiesBegin() const;
	bTValMap< bCPropertyID, eSEntityID >::bCConstIterator TemplateEntitiesEnd() const;
	GEBool                                                 UnregisterNameInfo(eCDynamicEntity &);
	GEBool                                                 UnregisterNameInfo(eCTemplateEntity &);
protected:
	GEBool       AddDeletedTemplate(bCPropertyID const &);
	void         Invalidate();
	GEBool       RegisterDynamicEntityContext(eCEntityDynamicContext &);
	eSEntityID * RegisterEntity(eCNode *, bCPropertyID const &);
	eSEntityID * RegisterEntityProxy(bCPropertyID const &);
	eSEntityID * RegisterEntityProxy(eCNode *);
	GEBool       RemoveDeletedTemplate(bCPropertyID const &);
	GEBool       UnregisterDynamicEntityContext(eCEntityDynamicContext &);
	GEBool       UnregisterEntity(eSEntityID * &);
	GEBool       UnregisterEntityProxy(eSEntityID * &);
protected: 
	char __FIXME[ 0x03b0 - sizeof(eCEngineComponentBase) ];
protected: 
	static bool eCSceneAdmin::ms_bInitialised

};
GE_ASSERT_SIZEOF(eCSceneAdmin, 0x03B0)

#endif
