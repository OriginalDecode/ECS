#pragma once
#include "ComponentContainer.h"
#include "TypeID.h"
#include "EntityTypes.h"
#include <atomic>
#include "BaseComponent.h"

typedef std::vector<Entity> EntityArray;
class CBaseSystem;
class CEntityManager
{
public:
	CEntityManager();
	~CEntityManager();

	Entity CreateEntity();

	void Update(float dt);
	const EntityArray& GetEntities(CComponentFilter filter);

	template<typename T>
	void AddComponent(Entity e);

	template<typename T>
	T& GetComponent(Entity e);

	template <typename T>
	void AddSystem();

	bool HasComponent(Entity e, unsigned int component_id);

private:
	Entity m_NextEntity = 0;
	CComponentContainer* m_Components = nullptr;
	std::vector<CBaseSystem*> m_Systems;
};

template<typename T>
void CEntityManager::AddComponent(Entity e)
{
	T* component = new T();
	m_Components->AddComponent(e, component, CTypeID<SBaseComponent>::GetID<T>());
}

template<typename T>
T& CEntityManager::GetComponent(Entity e)
{
	return static_cast<T&>(m_Components->GetComponent(e, CTypeID<SBaseComponent>::GetID<T>()));
}

template <typename T>
void CEntityManager::AddSystem()
{
	m_Systems.push_back(new T(*this));
} 