#include "ComponentContainer.h"
#include "ComponentFilter.h"
#include "BaseComponent.h"

CComponentContainer::CComponentContainer()
{
	m_Components.reserve(MAX_COMPONENTS_COUNT);
	m_EntityComponents.reserve(500);
	m_EntitiesToReturn.reserve(500);

	for (size_t i = 0; i < MAX_COMPONENTS_COUNT; i++)
	{
		m_Components.push_back(ComponentArray());
		m_Components[i].reserve(500);
	}
}

CComponentContainer::~CComponentContainer()
{
	for (ComponentArray& arr : m_Components)
	{
		for (SBaseComponent* bc : arr)
		{
			delete bc;
			bc = nullptr;
		}
	}
}

void CComponentContainer::AddEntity()
{
	m_EntityComponents.push_back(EntityComponentArray());
	EntityComponentArray& components = m_EntityComponents[m_EntityComponents.size() - 1];
	for (size_t i = 0; i < MAX_COMPONENTS_COUNT; i++)
	{
		components[i] = -1;
	}
}

void CComponentContainer::AddComponent(Entity e, SBaseComponent* component, unsigned int component_id)
{
	m_Components[component_id].push_back(component);
	m_EntityComponents[e][component_id] = m_Components[component_id].size() - 1;
}

SBaseComponent& CComponentContainer::GetComponent(Entity e, unsigned int component_id)
{
	const int index = m_EntityComponents[e][component_id];
	return *m_Components[component_id][index];
}

bool CComponentContainer::HasComponent(Entity e, unsigned int component_id)
{
	if (m_EntityComponents.size() <= e)
		return false;
	return m_EntityComponents[e][component_id] != -1;
}

const std::vector<Entity>& CComponentContainer::GetEntities(CComponentFilter filter)
{
	m_EntitiesToReturn.clear();

	for (size_t i = 0; i < m_EntityComponents.size(); i++)
	{
		if (filter.Compare(m_EntityComponents[i]) == true)
		{
			m_EntitiesToReturn.push_back(i);
		}
	}
	return m_EntitiesToReturn;
}

