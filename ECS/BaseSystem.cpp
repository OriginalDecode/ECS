#include "BaseSystem.h"

CBaseSystem::CBaseSystem(CEntityManager& manager)
	: m_Manager(manager)
{
}

CBaseSystem::CBaseSystem(CEntityManager& manager, const CComponentFilter& filter)
	: m_Manager(manager)
	, m_Filter(filter)
{
}

CBaseSystem::~CBaseSystem() = default;

const std::vector<Entity>& CBaseSystem::GetEntities()
{
	return m_Manager.GetEntities(m_Filter);
}