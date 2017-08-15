#include "RenderSystem.h"

#include "TranslationComponent.h"
#include "GraphicsComponent.h"

#include <iostream>


CRenderSystem::CRenderSystem(CEntityManager& manager)
	: CBaseSystem(manager, CreateFilter<Requires<STranslationComponent, SGraphicsComponent>>())
{
}

CRenderSystem::~CRenderSystem()
{
}

void CRenderSystem::Update(float dt)
{
	const auto& entities = GetEntities();
	

	for (Entity e : entities)
	{
		auto& t = m_Manager.GetComponent<STranslationComponent>(e);
		auto& g = m_Manager.GetComponent<SGraphicsComponent>(e);
		printf("Rendering entity %d at x%.3f y%.3f z%.3f with graphics key %d\n ", e, t.m_Orientation[12], t.m_Orientation[13], t.m_Orientation[14],g.m_HashKey);
	}


}
