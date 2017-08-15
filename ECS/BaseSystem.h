#pragma once
#include "ComponentFilter.h"
#include "EntityManager.h"

class CBaseSystem
{
public:
	CBaseSystem(CEntityManager& manager);
	CBaseSystem(CEntityManager& manager, const CComponentFilter& filter);
	virtual ~CBaseSystem() = 0;

	virtual void Update(float dt) = 0;
	const std::vector<Entity>& GetEntities();

	template<typename T>
	T& GetComponent(Entity anEntity);

private:
	void operator=(CBaseSystem&) = delete;

protected:
	CComponentFilter m_Filter;
	CEntityManager& m_Manager;
};

template<typename T>
T& CBaseSystem::GetComponent(Entity anEntity)
{
	return m_Manager.GetComponent<T>(anEntity);
}

