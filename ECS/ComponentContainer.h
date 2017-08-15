#pragma once
#include "EntityTypes.h"

struct CComponentFilter;
struct SBaseComponent;

class CComponentContainer
{
public:
	CComponentContainer();
	~CComponentContainer();

	void AddEntity();
	void AddComponent(Entity e, SBaseComponent* component, unsigned int component_id);

	SBaseComponent& GetComponent(Entity anEntity, unsigned int component_id);
	bool HasComponent(Entity e, unsigned int component_id);
	const std::vector<Entity>& GetEntities(CComponentFilter filter);


private:
	std::vector<ComponentArray> m_Components;
	std::vector<EntityComponentArray> m_EntityComponents;
	std::vector<Entity> m_EntitiesToReturn;
};

