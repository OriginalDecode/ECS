#include "EntityManager.h"
#include "BaseSystem.h"

CEntityManager::CEntityManager()
{
	m_Components = new CComponentContainer;
}

CEntityManager::~CEntityManager()
{
	delete m_Components;
	m_Components = nullptr;
}

Entity CEntityManager::CreateEntity()
{
	Entity newEntity = m_NextEntity++;
	m_Components->AddEntity();
	return newEntity;
}

void CEntityManager::Update(float dt)
{
	for (CBaseSystem* system : m_Systems)
	{
		system->Update(dt);
	}
}

const std::vector<Entity>& CEntityManager::GetEntities(CComponentFilter filter)
{
	return m_Components->GetEntities(filter);
}

bool CEntityManager::HasComponent(Entity e, unsigned int component_id)
{
	return m_Components->HasComponent(e, component_id);
}

