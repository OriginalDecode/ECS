#include "EntityManager.h"
#include "GraphicsComponent.h"
#include "TranslationComponent.h"
#include "RenderSystem.h"
void main()
{
	CEntityManager m_Manager;

	Entity e = m_Manager.CreateEntity();
	m_Manager.AddComponent<STranslationComponent>(e);
	m_Manager.AddComponent<SGraphicsComponent>(e);

	auto& t0 = m_Manager.GetComponent<STranslationComponent>(e);
	t0.m_Orientation[12] = 2.f;
	t0.m_Orientation[13] = 8.f;
	t0.m_Orientation[14] = 6.f;
	t0.m_Orientation[15] = 1.f;

	auto& g0 = m_Manager.GetComponent<SGraphicsComponent>(e);
	g0.m_HashKey = 004444400;

	e = m_Manager.CreateEntity();
	m_Manager.AddComponent<STranslationComponent>(e);
	m_Manager.AddComponent<SGraphicsComponent>(e);

	auto& t1 = m_Manager.GetComponent<STranslationComponent>(e);
	t1.m_Orientation[12] = 34.f;
	t1.m_Orientation[13] = 28.f;
	t1.m_Orientation[14] = 44.f;
	t1.m_Orientation[15] = 1.f;

	auto& g1 = m_Manager.GetComponent<SGraphicsComponent>(e);
	g1.m_HashKey = 99999999;


	m_Manager.AddSystem<CRenderSystem>();

	for (size_t i = 0; i < 250; i++)
	{
		m_Manager.Update(0.f);
	}

	std::getchar();
}